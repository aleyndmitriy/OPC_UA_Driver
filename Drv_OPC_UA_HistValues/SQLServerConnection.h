#pragma once
#include"Connection.h"
#include"SQLServerEnvironment.h"
#include"ConnectionAttributes.h"
#include<vector>

namespace DrvOPCUAHistValues {

	class SQLServerConnection final : public Connection {
	public:
		SQLServerConnection() = delete;
		SQLServerConnection(SQLServerConnection&& rsc) = delete;
		SQLServerConnection& operator=(SQLServerConnection&& rhs) = delete;
		explicit SQLServerConnection(const std::shared_ptr<SQLServerEnvironment>& environment, const ConnectionAttributes& attributes);
		explicit SQLServerConnection(const std::shared_ptr<SQLServerEnvironment>& environment);
		explicit SQLServerConnection(std::shared_ptr<SQLServerEnvironment>&& environment, ConnectionAttributes&& attributes);
		explicit SQLServerConnection(std::shared_ptr<SQLServerEnvironment>&& environment);
		SQLServerConnection(const SQLServerConnection& src) = delete;
		SQLServerConnection& operator=(const SQLServerConnection& rhs) = delete;
		~SQLServerConnection() override;
		void* GetInterface([[maybe_unused]] int nIfcId) override;
		bool ConnectToServerInstances(std::string driverName) override;
		bool ConnectToDatabaseInstances(std::string serverName, std::string login, std::string password, AuthenticationType authType) override;
		bool ConnectToDatabase(std::string databaseName) override;
		std::vector<std::string> GetServerList() const override;
		std::vector<std::string> GetDatabaseList() const override;
		bool IsValidConnection() const override;
		ConnectionStatus GetConnectionStatus() const override;
		static std::shared_ptr<SQLServerConnection> CreateConnectionToDatabase(const std::shared_ptr<SQLServerEnvironment>& environment, const ConnectionAttributes& attributes);
	private:
		SQLHDBC m_sqlDBC;
		void freeConnection();
		void allocateConnection();
		std::string HandleDiagnosticRecord();
		std::vector<std::string> serverList;
		std::vector<std::string> databaseList;
	};
}