#pragma once
#include"Statement.h"
#include"SQLServerConnection.h"

namespace DrvOPCUAHistValues {

	struct DataBinding {
		SQLSMALLINT dataType;
		std::unique_ptr<char[]> ptrDataValue;
		SQLLEN iBufferLength;
		SQLLEN iStrLenOrIndex;
		std::string colName;
	};

	class SQLServerStatement final : public Statement {
	public:
		SQLServerStatement() = delete;
		SQLServerStatement(const SQLServerStatement& src) = delete;
		SQLServerStatement& operator=(const SQLServerStatement& src) = delete;
		SQLServerStatement(SQLServerStatement&& src) noexcept;
		SQLServerStatement& operator=(SQLServerStatement&& src) noexcept;
		explicit SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, const std::vector<std::string>& parameters);
		explicit SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, std::vector<std::string>&& parameters);
		explicit SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query, std::initializer_list<std::string> parameters);
		explicit SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query, std::vector<std::string>&& parameters);
		explicit SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query, std::initializer_list<std::string> parameters);
		explicit SQLServerStatement(const std::shared_ptr<SQLServerConnection>& connection, const std::string& query);
		explicit SQLServerStatement(std::shared_ptr<SQLServerConnection>&& connection, std::string&& query);
		~SQLServerStatement();
		void* GetInterface([[maybe_unused]] int nIfcId) override;
		std::vector<Record> Execute() override;
	private:

		SQLHSTMT    m_sqlStmt;
		void freeStatement();
		void allocateStatement();
		void HandleDiagnosticRecord();
		std::string DataToString(char* data, SQLSMALLINT type);
	};
}