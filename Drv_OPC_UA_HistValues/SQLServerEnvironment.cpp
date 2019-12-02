#include"pch.h"
#include"SQLServerEnvironment.h"

DrvOPCUAHistValues::SQLServerEnvironment::SQLServerEnvironment() :m_sqlEnvironment(SQL_NULL_HENV) {
	SQLSMALLINT res = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &m_sqlEnvironment);

	res = SQLSetEnvAttr(m_sqlEnvironment, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	res = SQLSetEnvAttr(m_sqlEnvironment, SQL_ATTR_CONNECTION_POOLING, (SQLPOINTER)SQL_CP_OFF, 0);
}

DrvOPCUAHistValues::SQLServerEnvironment::~SQLServerEnvironment() {
	SQLSMALLINT res = SQLFreeHandle(SQL_HANDLE_ENV, m_sqlEnvironment);
	m_sqlEnvironment = SQL_NULL_HENV;
}

void* DrvOPCUAHistValues::SQLServerEnvironment::GetInterface([[maybe_unused]] int nIfcId) {
	return m_sqlEnvironment;
}