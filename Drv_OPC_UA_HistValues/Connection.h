#pragma once
#pragma once
#include<memory>
#include"ConnectionAttributes.h"
#include"IEnvironment.h"
#include<vector>

namespace DrvOPCUAHistValues {

	enum class ConnectionStatus
	{
		NoConnect = 0,
		ConnectToDriver = 1,
		ConnectToServer = 2,
		ConnectToDatabase = 3
	};
	enum class AuthenticationType
	{
		System = 1,
		Server = 2
	};

	class Connection : public ODS::IExtensible {
	public:
		Connection() = delete;
		Connection(const std::shared_ptr<IEnvironment>& environment, const ConnectionAttributes& attributes);
		Connection(const std::shared_ptr<IEnvironment>& environment, ConnectionAttributes&& attributes);
		Connection(const std::shared_ptr<IEnvironment>& environment);
		Connection(std::shared_ptr<IEnvironment>&& environment, ConnectionAttributes&& attributes);
		Connection(std::shared_ptr<IEnvironment>&& environment);
		Connection(const Connection& src) = delete;
		Connection& operator=(const Connection& rhs) = delete;
		Connection(Connection&& src) = delete;
		Connection& operator=(Connection&& rhs) = delete;
		virtual ~Connection() override;
		ConnectionAttributes GetConnectionAttributes() const;
		virtual bool ConnectToServerInstances(std::string driverName) = 0;
		virtual bool ConnectToDatabaseInstances(std::string serverName, std::string login, std::string password, AuthenticationType authType) = 0;
		virtual bool ConnectToDatabase(std::string databaseName) = 0;
		virtual std::vector<std::string> GetServerList() const = 0;
		virtual std::vector<std::string> GetDatabaseList() const = 0;
		virtual bool IsValidConnection() const = 0;
		virtual ConnectionStatus GetConnectionStatus() const = 0;
	protected:
		std::shared_ptr<IEnvironment> m_ptrEnvironment;
		ConnectionAttributes m_connectionAttributes;
	};
}