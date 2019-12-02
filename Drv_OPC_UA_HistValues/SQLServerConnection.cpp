#include"pch.h"
#include"SQLServerConnection.h"
#include"Log.h"
#include"Constants.h"
#include"Utils.h"

DrvOPCUAHistValues::SQLServerConnection::SQLServerConnection(const std::shared_ptr<SQLServerEnvironment>& environment, const ConnectionAttributes& attributes) :Connection(environment, attributes), m_sqlDBC(SQL_NULL_HDBC)
{
	allocateConnection();
}

DrvOPCUAHistValues::SQLServerConnection::SQLServerConnection(const std::shared_ptr<SQLServerEnvironment>& environment) : Connection(environment), m_sqlDBC(SQL_NULL_HDBC)
{
	allocateConnection();
}

DrvOPCUAHistValues::SQLServerConnection::SQLServerConnection(std::shared_ptr<SQLServerEnvironment>&& environment, ConnectionAttributes&& attributes) : Connection(std::move(environment), std::move(attributes)), m_sqlDBC(SQL_NULL_HDBC)
{
	allocateConnection();
}

DrvOPCUAHistValues::SQLServerConnection::SQLServerConnection(std::shared_ptr<SQLServerEnvironment>&& environment) : Connection(std::move(environment)), m_sqlDBC(SQL_NULL_HDBC)
{
	allocateConnection();
}

DrvOPCUAHistValues::SQLServerConnection::~SQLServerConnection() {
	if (m_sqlDBC)
	{
		freeConnection();
	}
}

void* DrvOPCUAHistValues::SQLServerConnection::GetInterface([[maybe_unused]] int nIfcId) {
	return m_sqlDBC;
}

void DrvOPCUAHistValues::SQLServerConnection::freeConnection() {
	__try {
		SQLSMALLINT res = SQLDisconnect(m_sqlDBC);
		__try {
			res = SQLFreeHandle(SQL_HANDLE_DBC, m_sqlDBC);
			m_sqlDBC = SQL_NULL_HDBC;
		}
		__except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
			Log::GetInstance()->WriteInfo(_T("exeption during free connection!"));
		}
	}
	__except ((GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION || GetExceptionCode() == EXCEPTION_BREAKPOINT) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
		Log::GetInstance()->WriteInfo(_T("exeption during free connection in debug"));
	}
	if (m_sqlDBC)
	{
		SQLSMALLINT res = SQLFreeHandle(SQL_HANDLE_DBC, m_sqlDBC);
	}
	m_sqlDBC = SQL_NULL_HDBC;
	m_ptrEnvironment.reset();
	databaseList.clear();
	serverList.clear();
	m_connectionAttributes.driver.clear();
	m_connectionAttributes.serverName.clear();
	m_connectionAttributes.loginName.clear();
	m_connectionAttributes.password.clear();
	m_connectionAttributes.databaseName.clear();
	m_connectionAttributes.isServerAuthentication = false;
}

void DrvOPCUAHistValues::SQLServerConnection::allocateConnection() {
	m_sqlDBC = SQL_NULL_HDBC;
	SQLSMALLINT res = SQLAllocHandle(SQL_HANDLE_DBC, m_ptrEnvironment->GetInterface(0), &m_sqlDBC);
	if (res == SQL_ERROR)
	{
		HandleDiagnosticRecord();
		freeConnection();
		return;
	}
	bool isConnect = false;
	if (m_connectionAttributes.driver.empty()) {
		return;
	}
	isConnect = ConnectToServerInstances(m_connectionAttributes.driver);
	if (serverList.empty() || !isConnect) {
		return;
	}
	if (m_connectionAttributes.serverName.empty()) {
		return;
	}
	AuthenticationType authtype = AuthenticationType::Server;
	if (m_connectionAttributes.isServerAuthentication) {
		authtype = AuthenticationType::Server;
	}
	else {
		authtype = AuthenticationType::System;
	}
	isConnect = ConnectToDatabaseInstances(m_connectionAttributes.serverName, m_connectionAttributes.loginName, m_connectionAttributes.password, authtype);
	if (databaseList.empty() || !isConnect) {
		return;
	}
	if (m_connectionAttributes.databaseName.empty()) {
		return;
	}
	ConnectToDatabase(m_connectionAttributes.databaseName);
}

bool DrvOPCUAHistValues::SQLServerConnection::ConnectToServerInstances(std::string driverName) {

	TCHAR wchDriverName[MAX_DRIVERNAME_LENGTH];
	TCHAR wStrOut[STR_LENGTH];
	SQLSMALLINT shBrowseResultLen = 0;
	std::string strDriver = std::string("DRIVER={") + driverName + std::string("};");
	StringCchCopy(wchDriverName, strDriver.length() + 1, strDriver.c_str());
	SQLSMALLINT res = SQLBrowseConnect(m_sqlDBC, reinterpret_cast<SQLCHAR*>(wchDriverName), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(wStrOut), STR_LENGTH, &shBrowseResultLen);
	if (SQL_SUCCEEDED(res) || res == SQL_NEED_DATA) {
		std::string strRes = std::string(wStrOut);
		size_t firstPos = strRes.find_first_of("{", 0);
		size_t lastPos = strRes.find_first_of("}", 0);
		if (firstPos != std::string::npos && lastPos != std::string::npos) {
			std::string serversString = strRes.substr(firstPos + 1, lastPos - firstPos - 1);
			std::vector<std::string> servers = split(serversString, std::string(","));
			if (servers.empty()) {
				freeConnection();
				return false;
			}
			else {
				serverList.assign(servers.begin(), servers.end());
				return true;
			}
		}
		else {
			freeConnection();
			return false;
		}
	}
	else {
		HandleDiagnosticRecord();
		freeConnection();
		return false;
	}
}

bool DrvOPCUAHistValues::SQLServerConnection::ConnectToDatabaseInstances(std::string serverName, std::string login, std::string password, AuthenticationType authType)
{
	TCHAR whUserInfo[SQL_MAX_MESSAGE_LENGTH];
	std::unique_ptr<TCHAR[]> wStrOut(new TCHAR[STR_LENGTH]);
	SQLSMALLINT shBrowseResultLen = 0;
	std::string strServerData = std::string("SERVER=") + serverName;
	if (authType == AuthenticationType::Server) {
		strServerData = strServerData + std::string(";UID=") + login + std::string(";PWD=") + password;
	}
	else {
		strServerData = strServerData + std::string(";Trusted_Connection=yes");
	}
	StringCchCopy(whUserInfo, strServerData.length() + 1, strServerData.c_str());
	SQLSMALLINT res = SQLBrowseConnect(m_sqlDBC, reinterpret_cast<SQLCHAR*>(whUserInfo), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(wStrOut.get()), STR_LENGTH, &shBrowseResultLen);
	if ((SQL_SUCCEEDED(res) || res == SQL_NEED_DATA) && shBrowseResultLen > STR_LENGTH) {
		wStrOut.reset(new TCHAR[shBrowseResultLen + 1]);
		res = SQLBrowseConnect(m_sqlDBC, reinterpret_cast<SQLCHAR*>(whUserInfo), SQL_NTS,
			reinterpret_cast<SQLCHAR*>(wStrOut.get()), shBrowseResultLen, &shBrowseResultLen);
	}
	if (SQL_SUCCEEDED(res) || res == SQL_NEED_DATA) {
		std::string result = HandleDiagnosticRecord();
		if (result.empty() == false) {
			freeConnection();
			return false;
		}
		std::string strRes(wStrOut.get());
		size_t firstPos = strRes.find_first_of("{", 0);
		size_t lastPos = strRes.find_first_of("}", 0);
		if (firstPos != std::string::npos && lastPos != std::string::npos) {
			std::string databaseString = strRes.substr(firstPos + 1, lastPos - firstPos - 1);
			std::vector<std::string> databases = split(databaseString, std::string(","));
			if (databases.empty()) {
				freeConnection();
				return true;
			}
			else {
				databaseList.assign(databases.begin(), databases.end());
				m_connectionAttributes.serverName = serverName;
				if (authType == AuthenticationType::Server) {
					m_connectionAttributes.isServerAuthentication = true;
				}
				else {
					m_connectionAttributes.isServerAuthentication = false;
				}
				return true;
			}
		}
		else {
			freeConnection();
			return false;
		}
	}
	else {
		HandleDiagnosticRecord();
		freeConnection();
		return false;
	}
}

bool DrvOPCUAHistValues::SQLServerConnection::ConnectToDatabase(std::string databaseName)
{
	TCHAR wchDataBaseName[MAX_DATABASENAME_LENGTH];
	TCHAR wStrOut[STR_LENGTH];
	SQLSMALLINT shBrowseResultLen = 0;
	std::string strDatabase = std::string("DATABASE=") + databaseName + std::string(";");
	StringCchCopy(wchDataBaseName, strDatabase.length() + 1, strDatabase.c_str());
	SQLSMALLINT res = SQLBrowseConnect(m_sqlDBC, reinterpret_cast<SQLCHAR*>(wchDataBaseName), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(wStrOut), STR_LENGTH, &shBrowseResultLen);
	if (!SQL_SUCCEEDED(res)) {
		HandleDiagnosticRecord();
		freeConnection();
		return false;
	}
	m_connectionAttributes.databaseName = databaseName;
	return true;
}

std::vector<std::string> DrvOPCUAHistValues::SQLServerConnection::GetServerList() const
{
	return serverList;
}

std::vector<std::string> DrvOPCUAHistValues::SQLServerConnection::GetDatabaseList() const
{
	return databaseList;
}

bool DrvOPCUAHistValues::SQLServerConnection::IsValidConnection() const
{
	return (m_sqlDBC != SQL_NULL_HDBC);
}

DrvOPCUAHistValues::ConnectionStatus DrvOPCUAHistValues::SQLServerConnection::GetConnectionStatus() const
{
	if (!IsValidConnection()) {
		return ConnectionStatus::NoConnect;
	}

	if (!m_connectionAttributes.databaseName.empty()) {
		return ConnectionStatus::ConnectToDatabase;
	}
	else if (!m_connectionAttributes.serverName.empty()) {
		return ConnectionStatus::ConnectToServer;
	}
	else if (!m_connectionAttributes.driver.empty()) {
		return ConnectionStatus::ConnectToDriver;
	}
	else {
		return ConnectionStatus::NoConnect;
	}
}

std::string DrvOPCUAHistValues::SQLServerConnection::HandleDiagnosticRecord()
{
	SQLSMALLINT iRec = 0;
	SQLINTEGER  iError;
	TCHAR       wszMessage[SQL_MAX_MESSAGE_LENGTH];
	ZeroMemory(wszMessage, SQL_MAX_MESSAGE_LENGTH);
	TCHAR       wszState[SQL_SQLSTATE_SIZE + 1];
	ZeroMemory(wszState, SQL_SQLSTATE_SIZE + 1);
	while (SQLGetDiagRec(SQL_HANDLE_DBC, m_sqlDBC, ++iRec, reinterpret_cast<SQLCHAR*>(wszState), &iError, reinterpret_cast<SQLCHAR*>(wszMessage),
		(SQLSMALLINT)(sizeof(wszMessage) / sizeof(TCHAR)), (SQLSMALLINT*)NULL) == SQL_SUCCESS)
	{
		if (_tcsncmp(wszState, "01004", 5))
		{
			fprintf(stderr, "[%5.5s] %s (%d)\n", wszState, wszMessage, iError);
		}
		Log::GetInstance()->WriteInfo(_T("State: %s - Message : %s ."), (LPCTSTR)wszState, (LPCTSTR)wszMessage);
		if (!_tcsnccmp(wszState, TEXT("08001"), SQL_MAX_MESSAGE_LENGTH)) {

			return std::string("08001");
		}
	}
	return std::string(wszState);
}

std::shared_ptr<DrvOPCUAHistValues::SQLServerConnection> DrvOPCUAHistValues::SQLServerConnection::CreateConnectionToDatabase(const std::shared_ptr<SQLServerEnvironment>& environment, const ConnectionAttributes& attributes) {
	if (attributes.driver.empty() || attributes.serverName.empty() || attributes.databaseName.empty()) {
		return nullptr;
	}
	std::shared_ptr<SQLServerConnection> connection = std::make_shared<SQLServerConnection>(environment);
	if (connection->m_sqlDBC == SQL_NULL_HDBC) {
		return nullptr;
	}
	TCHAR whServerInfo[SQL_MAX_MESSAGE_LENGTH];
	TCHAR wStrOut[STR_LENGTH];
	SQLSMALLINT shBrowseResultLen = 0;
	std::string strServerData = std::string("DRIVER=") + attributes.driver + std::string(";SERVER=") + attributes.serverName;

	if (attributes.isServerAuthentication) {
		strServerData = strServerData + std::string(";UID=") + attributes.loginName + std::string(";PWD=") + attributes.password;
	}
	else {
		strServerData = strServerData + std::string(";Trusted_Connection=yes");
	}
	strServerData = strServerData + std::string(";DATABASE=") + attributes.databaseName + std::string(";");
	StringCchCopy(whServerInfo, strServerData.length() + 1, strServerData.c_str());
	SQLSMALLINT res = SQLDriverConnect(connection->m_sqlDBC, NULL, reinterpret_cast<SQLCHAR*>(whServerInfo), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(wStrOut), STR_LENGTH, &shBrowseResultLen, SQL_DRIVER_NOPROMPT);
	if (!SQL_SUCCEEDED(res)) {
		connection->HandleDiagnosticRecord();
		connection.reset();
		return nullptr;
	}
	connection->HandleDiagnosticRecord();
	connection->m_connectionAttributes = attributes;
	return connection;
}