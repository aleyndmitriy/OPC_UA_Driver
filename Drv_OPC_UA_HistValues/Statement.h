#pragma once
#include"Connection.h"
#include"Record.h"
#include<vector>

namespace DrvOPCUAHistValues {

	class Statement : public ODS::IExtensible {
	public:
		Statement() = delete;
		Statement(const Statement& src) = delete;
		Statement& operator=(const Statement& src) = delete;
		Statement(const std::shared_ptr<Connection>& connection, const std::string& query, const std::vector<std::string>& parameters);
		Statement(const std::shared_ptr<Connection>& connection, const std::string& query, std::vector<std::string>&& parameters);
		Statement(std::shared_ptr<Connection>&& connection, std::string&& query, std::vector<std::string>&& parameters);
		Statement(const std::shared_ptr<Connection>& connection, const std::string& query);
		Statement(std::shared_ptr<Connection>&& connection, std::string&& query);
		Statement(const std::shared_ptr<Connection>& connection, const std::string& query, std::initializer_list<std::string> list);
		Statement(std::shared_ptr<Connection>&& connection, std::string&& query, std::initializer_list<std::string> list);
		Statement(Statement&& src) noexcept;
		Statement& operator=(Statement&& src) noexcept;
		virtual ~Statement();
		std::string getQueryString() const;
		virtual std::vector<Record> Execute() = 0;
	protected:
		std::shared_ptr<Connection> m_ptrConnection;
		std::string strQuery;
		std::vector<std::string> binders;
	};
}