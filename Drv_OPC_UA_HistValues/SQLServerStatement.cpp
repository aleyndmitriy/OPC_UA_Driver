#include"pch.h"
#include"SQLServerStatement.h"
#include"Utils.h"
#include"Constants.h"
#include"Log.h"

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, const std::vector<std::string>& parameters) : Statement(connection, query, parameters), m_sqlStmt(SQL_NULL_HSTMT)
{
	allocateStatement();
}


DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, std::vector<std::string>&& parameters) : Statement(connection, query, std::move(parameters)), m_sqlStmt(SQL_NULL_HSTMT)
{
	allocateStatement();
}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(SQLServerStatement&& src) noexcept : Statement(std::move(src)), m_sqlStmt(src.m_sqlStmt) {
	src.m_sqlStmt = SQL_NULL_HSTMT;
}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query, std::vector<std::string>&& parameters) : Statement(std::move(connection), std::move(query), std::move(parameters)), m_sqlStmt(SQL_NULL_HSTMT)
{
	allocateStatement();
}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query, std::initializer_list<std::string> parameters) : SQLServerStatement(std::move(connection), std::move(query), std::vector<std::string>(parameters))
{

}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, std::initializer_list<std::string> parameters) : SQLServerStatement(connection, query, std::vector<std::string>(parameters))
{

}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query) : SQLServerStatement(connection, query, std::vector<std::string>())
{

}

DrvOPCUAHistValues::SQLServerStatement::SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query) : SQLServerStatement(std::move(connection), std::move(query), std::vector<std::string>())
{

}

DrvOPCUAHistValues::SQLServerStatement& DrvOPCUAHistValues::SQLServerStatement::operator=(SQLServerStatement&& rhs) noexcept {
	if (this == &rhs)
	{
		return *this;
	}
	else {
		m_sqlStmt = rhs.m_sqlStmt;
		rhs.m_sqlStmt = SQL_NULL_HSTMT;
		this->Statement::operator=(std::move(rhs));
		return *this;
	}
}

DrvOPCUAHistValues::SQLServerStatement::~SQLServerStatement() {
	freeStatement();
}

void* DrvOPCUAHistValues::SQLServerStatement::GetInterface([[maybe_unused]] int nIfcId) {
	return m_sqlStmt;
}

void DrvOPCUAHistValues::SQLServerStatement::freeStatement() {
	SQLSMALLINT res = SQL_SUCCESS;
	if (m_sqlStmt)
	{
		res = SQLFreeHandle(SQL_HANDLE_STMT, m_sqlStmt);
		m_sqlStmt = SQL_NULL_HSTMT;
		m_ptrConnection.reset();
		strQuery.clear();

	}
}

void DrvOPCUAHistValues::SQLServerStatement::HandleDiagnosticRecord()
{
	SQLSMALLINT iRec = 0;
	SQLINTEGER  iError;
	TCHAR       wszMessage[SQL_MAX_MESSAGE_LENGTH];
	TCHAR       wszState[SQL_SQLSTATE_SIZE + 1];
	while (SQLGetDiagRec(SQL_HANDLE_STMT, m_sqlStmt, ++iRec, reinterpret_cast<SQLCHAR*>(wszState), &iError, reinterpret_cast<SQLCHAR*>(wszMessage),
		(SQLSMALLINT)(sizeof(wszMessage) / sizeof(TCHAR)), (SQLSMALLINT*)NULL) == SQL_SUCCESS)
	{
		if (_tcsncmp(wszState, "01004", 5))
		{
			fprintf(stderr, "[%5.5s] %s (%d)\n", wszState, wszMessage, iError);
		}
		Log::GetInstance()->WriteInfo(_T("State: %s - Message : %s ."), (LPCTSTR)wszState, (LPCTSTR)wszMessage);
	}
}

void DrvOPCUAHistValues::SQLServerStatement::allocateStatement()
{
	SQLSMALLINT res = SQLAllocHandle(SQL_HANDLE_STMT, m_ptrConnection->GetInterface(0), &m_sqlStmt);
	if (res == SQL_ERROR)
	{
		HandleDiagnosticRecord();
		freeStatement();
		return;
	}

	for (std::vector<std::string>::const_iterator constItr = binders.cbegin(); constItr != binders.cend(); constItr++) {
		strQuery = FindAndReplace(strQuery, std::string("?"), *constItr);
	}

	res = SQLPrepare(m_sqlStmt, (SQLCHAR*)(strQuery.c_str()), SQL_NTS);
	if (!SQL_SUCCEEDED(res)) {
		HandleDiagnosticRecord();
		freeStatement();
		return;
	}
}

std::vector<DrvOPCUAHistValues::Record> DrvOPCUAHistValues::SQLServerStatement::Execute()
{
	std::vector<Record> recordSet = std::vector<Record>();
	SQLSMALLINT res = SQLExecute(m_sqlStmt);
	if (!SQL_SUCCEEDED(res)) {
		HandleDiagnosticRecord();
		freeStatement();
		return recordSet;
	}
	SQLSMALLINT shNumberOfColumns = 0;
	res = SQLNumResultCols(m_sqlStmt, &shNumberOfColumns);
	if (!SQL_SUCCEEDED(res)) {
		HandleDiagnosticRecord();
		freeStatement();
		return recordSet;
	}
	std::unique_ptr<DataBinding[]> bindingArray(new DataBinding[shNumberOfColumns]);
	for (SQLSMALLINT colIndex = 0; colIndex < shNumberOfColumns; colIndex++) {
		SQLSMALLINT     coltype = 0;
		SQLSMALLINT     colnamelen = 0;
		SQLULEN     collen[MAX_COLUMNS];
		SQLCHAR         colname[STR_LENGTH];
		SQLLEN      displaysize = 0;
		SQLSMALLINT     scale = 0;
		res = SQLDescribeCol(m_sqlStmt, colIndex + 1, colname, STR_LENGTH, &colnamelen, &coltype, collen + colIndex, &scale, NULL);
		if (!SQL_SUCCEEDED(res)) {
			HandleDiagnosticRecord();
			freeStatement();
			return recordSet;
		}
		if (coltype > SQL_GUID&& coltype < SQL_BIT) {
			coltype = SQL_CHAR;
		}
		if (coltype == SQL_FLOAT) {
			coltype = SQL_C_FLOAT;
		}
		if (coltype == SQL_BIGINT) {
			coltype = SQL_C_UBIGINT;
		}
		colname[colnamelen] = '\0';
		res = SQLColAttribute(m_sqlStmt, colIndex + 1, SQL_DESC_DISPLAY_SIZE, NULL, 0, NULL, &displaysize);
		if (!SQL_SUCCEEDED(res)) {
			HandleDiagnosticRecord();
			freeStatement();
			return recordSet;
		}
		std::string wideStr = std::string((TCHAR*)colname);
		bindingArray[colIndex].colName = wideStr;
		bindingArray[colIndex].dataType = coltype;
		bindingArray[colIndex].iBufferLength = max(displaysize, *(collen + colIndex));
		bindingArray[colIndex].ptrDataValue = std::unique_ptr<char[]>(new char[bindingArray[colIndex].iBufferLength]);
		bindingArray[colIndex].ptrDataValue[bindingArray[colIndex].iBufferLength - 1] = '\0';
		res = SQLBindCol(m_sqlStmt, colIndex + 1, coltype, bindingArray[colIndex].ptrDataValue.get(), bindingArray[colIndex].iBufferLength, &(bindingArray[colIndex].iStrLenOrIndex));
		if (!SQL_SUCCEEDED(res)) {
			HandleDiagnosticRecord();
			freeStatement();
			return recordSet;
		}
	}

	while ((res = SQLFetch(m_sqlStmt)) == SQL_SUCCESS)
	{
		Record record;
		for (SQLSMALLINT colIndex = 0; colIndex < shNumberOfColumns; colIndex++) {
			std::string dataString;
			if (bindingArray[colIndex].iStrLenOrIndex != SQL_NO_DATA && bindingArray[colIndex].iStrLenOrIndex != SQL_NULL_DATA) {
				dataString = DataToString(bindingArray[colIndex].ptrDataValue.get(), bindingArray[colIndex].dataType);
			}
			record.insert(bindingArray[colIndex].colName, bindingArray[colIndex].dataType, dataString);
		}
		recordSet.push_back(record);
	}
	return recordSet;
}

std::string DrvOPCUAHistValues::SQLServerStatement::DataToString(char* data, SQLSMALLINT type) {

	std::string str;
	int* ptrInt = nullptr;
	int iData = 0;
	unsigned char* ptrCh = nullptr;
	unsigned char ch;
	long long* ptrLong = nullptr;
	long long lData = 0;
	float* ptrFloat = nullptr;
	float fData = 0.0;
	SQLGUID* guid = nullptr;
	WCHAR strGuide[MAX_UUID_LENGTH];
	TIMESTAMP_STRUCT* ptrTime = nullptr;
	TIME_STRUCT* ptrHour = nullptr;
	DATE_STRUCT* ptrDay = nullptr;
	int res = 0;
	switch (type)
	{
	case SQL_C_LONG:
	case SQL_C_SHORT:
	case SQL_C_TINYINT:
		ptrInt = reinterpret_cast<int*>(data);
		iData = *ptrInt;
		return std::to_string(iData);
		break;
	case SQL_C_BIT:
		ptrCh = reinterpret_cast<unsigned char*>(data);
		ch = *ptrCh;
		if (ch > 0) {
			return std::to_string((int)1);
		}
		else {
			return std::to_string((int)0);
		}
		break;
	case SQL_C_UBIGINT:
	case SQL_C_INTERVAL_SECOND:
		ptrLong = reinterpret_cast<long long*>(data);
		lData = *ptrLong;
		return std::to_string(lData);
		break;
	case SQL_C_CHAR:
	case SQL_C_BINARY:
		return std::string(data);
		break;
	case SQL_C_GUID:
		guid = reinterpret_cast<SQLGUID*>(data);
		strGuide[MAX_UUID_LENGTH - 1] = L'\0';
		res = StringFromGUID2(*guid, strGuide, MAX_UUID_LENGTH);
		return std::string(Wstr2Str(std::wstring(strGuide)));
		break;
	case SQL_C_TYPE_TIMESTAMP:
		ptrTime = reinterpret_cast<TIMESTAMP_STRUCT*>(data);
		str = std::string(data, sizeof(TIMESTAMP_STRUCT));
		/*str = std::to_string(ptrTime->year) + std::string("-") + std::to_string(ptrTime->month) + std::string("-") +
			std::to_string(ptrTime->day) + std::string(" ") + std::to_string(ptrTime->hour) + std::string(":") + std::to_string(ptrTime->minute) +
			std::string(":") + std::to_string(ptrTime->second) + std::string(".") + std::to_string(ptrTime->fraction);*/
		return str;
		break;
	case SQL_C_TYPE_TIME:
		ptrHour = reinterpret_cast<TIME_STRUCT*>(data);
		str = std::string(data, sizeof(TIME_STRUCT));
		/*str =  std::to_string(ptrHour->hour) + std::string(":") + std::to_string(ptrHour->minute) +
			std::string(":") + std::to_string(ptrHour->second);*/
		return str;
		break;
	case SQL_C_TYPE_DATE:
		ptrDay = reinterpret_cast<DATE_STRUCT*>(data);
		str = std::string(data, sizeof(DATE_STRUCT));
		/*str = std::to_string(ptrDay->year) + std::string("-") + std::to_string(ptrDay->month) + std::string("-") +
			std::to_string(ptrDay->day);*/
		return str;
		break;
	case SQL_C_FLOAT:
	case SQL_FLOAT:
		ptrFloat = reinterpret_cast<float*>(data);
		fData = *ptrFloat;
		return std::to_string(fData);
		break;
	default:
		return str;
		break;
	}
}