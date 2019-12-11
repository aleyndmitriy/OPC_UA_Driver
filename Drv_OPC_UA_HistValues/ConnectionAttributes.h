#pragma once
#include<string>

namespace DrvOPCUAHistValues
{
	enum class ConfigurationSecurityMode {
		INVALID = 0,
		NONE = 1,
		SIGN = 2,
		SIGN_AND_ENCRYPT = 3
	};
	
	int GetIntFromSecurityMode(ConfigurationSecurityMode mode);
	ConfigurationSecurityMode GetModeFromInt(int mode);


	enum class ConfigurationSecurityType {
		ANONYMOUS = 0,
		USER_NAME = 1,
		CERTIFICATE = 2,
		ISSUED_TOKEN = 3
	};

	int GetIntFromSecurityType(ConfigurationSecurityType type);
	ConfigurationSecurityType GetTypeFromInt(int type);


	struct ServerConfiguration {
		std::string computerName;
		std::string serverName;
		unsigned int port;
		ServerConfiguration(const std::string& computer, const std::string& server, unsigned int number);
		ServerConfiguration(const std::string& computer, unsigned int number);
		ServerConfiguration(const std::string& computer);
		ServerConfiguration();
		~ServerConfiguration();
		ServerConfiguration(const ServerConfiguration& src) = default;
		ServerConfiguration& operator=(const ServerConfiguration& rhs) = default;
		ServerConfiguration(ServerConfiguration&& src) = default;
		ServerConfiguration& operator=(ServerConfiguration&& rhs) = default;
	};
	bool operator==(const ServerConfiguration& lhs, const ServerConfiguration& rhs);
	bool operator!=(const ServerConfiguration& lhs, const ServerConfiguration& rhs);

	struct ServerSecurityModeConfiguration {
		std::string serverSecurityName;
		ConfigurationSecurityMode securityMode;
		ServerSecurityModeConfiguration(const std::string& config, ConfigurationSecurityMode mode);
		ServerSecurityModeConfiguration(const std::string& config);
		ServerSecurityModeConfiguration();
		~ServerSecurityModeConfiguration();
		ServerSecurityModeConfiguration(const ServerSecurityModeConfiguration& src) = default;
		ServerSecurityModeConfiguration& operator=(const ServerSecurityModeConfiguration& rhs) = default;
		ServerSecurityModeConfiguration(ServerSecurityModeConfiguration&& src) = default;
		ServerSecurityModeConfiguration& operator=(ServerSecurityModeConfiguration&& rhs) = default;
	};

	bool operator==(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs);
	bool operator!=(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs);

	struct SecurityAccessConfiguration {
		std::string login;
		std::string password;
		std::string certificate;
		std::string privateKey;
		ConfigurationSecurityType securityType;
		SecurityAccessConfiguration(const std::string& loginString, const std::string& passString, const::std::string& certificateString, const::std::string& keyString, ConfigurationSecurityType type);
		SecurityAccessConfiguration(const std::string& loginString, const std::string& passString);
		SecurityAccessConfiguration(const::std::string& key, ConfigurationSecurityType type);
		SecurityAccessConfiguration();
		~SecurityAccessConfiguration();
		SecurityAccessConfiguration(const SecurityAccessConfiguration& src) = default;
		SecurityAccessConfiguration& operator=(const SecurityAccessConfiguration& rhs) = default;
		SecurityAccessConfiguration(SecurityAccessConfiguration&& src) = default;
		SecurityAccessConfiguration& operator=(SecurityAccessConfiguration&& rhs) = default;
	};

	bool operator==(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs);
	bool operator!=(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs);

	struct ConnectionAttributes {
		ServerConfiguration configuration;
		ServerSecurityModeConfiguration configurationMode;
		SecurityAccessConfiguration configurationAccess;
		ConnectionAttributes(const ServerConfiguration& server, const ServerSecurityModeConfiguration& mode, const SecurityAccessConfiguration& accessType);
		ConnectionAttributes(const ServerConfiguration& server, const ServerSecurityModeConfiguration& mode);
		ConnectionAttributes(const ServerConfiguration& server);
		ConnectionAttributes();
		~ConnectionAttributes();
		ConnectionAttributes(const ConnectionAttributes& src) = default;
		ConnectionAttributes& operator=(const ConnectionAttributes& rhs) = default;
		ConnectionAttributes(ConnectionAttributes&& src) = default;
		ConnectionAttributes& operator=(ConnectionAttributes&& rhs) = default;
	};

	bool operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs);
	bool operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs);
}