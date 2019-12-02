#pragma once
#include"Record.h"
#include"ConnectionAttributes.h"
#include"Statement.h"

namespace DrvOPCUAHistValues {
	
	class IDatabaseEngine
	{
	public:
		virtual bool OpenConnection() = 0;
		virtual bool OpenConnection(const ConnectionAttributes& attributes) = 0;
		virtual bool OpenConnectionIfNeeded(const ConnectionAttributes& attributes) = 0;
		virtual bool loadServerInstances(std::string driverName) = 0;
		virtual bool loadDatabaseInstances(std::string serverName, AuthenticationType type, std::string user, std::string password) = 0;
		virtual bool ChooseDatabase(std::string databaseName) = 0;
		virtual bool CreateDirectConnectionToDatabase(const ConnectionAttributes& attributes) = 0;
		virtual void CloseConnection() = 0;
		virtual bool IsValidConnection() const = 0;
		virtual ConnectionAttributes GetConnectionAttributes() const = 0;
		virtual ConnectionStatus GetConnectionStatus() const = 0;
		virtual std::vector<std::string> GetServersList() const = 0;
		virtual std::vector<std::string> GetDatabasesList() const = 0;
		virtual std::vector<Record> ExecuteStatement(const std::string& query, const std::vector<std::string>& parameters) = 0;
		virtual ~IDatabaseEngine() {};
	};
}