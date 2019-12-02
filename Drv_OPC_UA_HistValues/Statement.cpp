#include"pch.h"
#include"Statement.h"

DrvOPCUAHistValues::Statement::Statement(const std::shared_ptr<Connection>& connection, const std::string& query, std::initializer_list<std::string> list) :m_ptrConnection(connection), strQuery(query), binders(list) {

}

DrvOPCUAHistValues::Statement::Statement(const std::shared_ptr<Connection>& connection, const std::string& query) : Statement(connection, query, std::initializer_list<std::string>{}) {

}

DrvOPCUAHistValues::Statement::Statement(std::shared_ptr<Connection>&& connection, std::string&& query, std::initializer_list<std::string> list) : m_ptrConnection(std::move(connection)), strQuery(std::move(query)), binders(list) {

}

DrvOPCUAHistValues::Statement::Statement(std::shared_ptr<Connection>&& connection, std::string&& query) : Statement(std::move(connection), std::move(query), std::initializer_list<std::string>{}) {

}


DrvOPCUAHistValues::Statement::Statement(const std::shared_ptr<Connection>& connection, const std::string& query, const std::vector<std::string>& parameters) : m_ptrConnection(connection), strQuery(query), binders(parameters)
{

}

DrvOPCUAHistValues::Statement::Statement(const std::shared_ptr<Connection>& connection, const std::string& query, std::vector<std::string>&& parameters) : m_ptrConnection(connection), strQuery(query), binders(std::move(parameters))
{

}

DrvOPCUAHistValues::Statement::Statement(std::shared_ptr<Connection>&& connection, std::string&& query, std::vector<std::string>&& parameters) : m_ptrConnection(std::move(connection)), strQuery(std::move(query)), binders(std::move(parameters))
{

}

DrvOPCUAHistValues::Statement::~Statement() {
	m_ptrConnection.reset();
	strQuery.clear();
	binders.clear();
}

DrvOPCUAHistValues::Statement::Statement(Statement&& src) noexcept {
	m_ptrConnection = src.m_ptrConnection;
	src.m_ptrConnection.reset();
	strQuery = std::move(src.strQuery);
	binders = std::move(src.binders);
}

DrvOPCUAHistValues::Statement& DrvOPCUAHistValues::Statement::operator=(Statement&& rhs) noexcept
{
	if (this == &rhs) {
		return *this;
	}
	else {
		m_ptrConnection = rhs.m_ptrConnection;
		rhs.m_ptrConnection.reset();
		strQuery = std::move(rhs.strQuery);
		binders = std::move(rhs.binders);
		return *this;
	}
}

std::string DrvOPCUAHistValues::Statement::getQueryString() const {
	return strQuery;
}
