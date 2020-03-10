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
	std::string GetStringFromSecurityMode(ConfigurationSecurityMode mode);
	ConfigurationSecurityMode GetModeFromInt(int mode);
	ConfigurationSecurityMode GetModeFromString(const std::string& mode);

	enum class ConfigurationSecurityType {
		ANONYMOUS = 0,
		USER_NAME = 1,
		CERTIFICATE = 2,
		ISSUED_TOKEN = 3
	};

	int GetIntFromSecurityType(ConfigurationSecurityType type);
	std::string GetStringFromSecurityType(ConfigurationSecurityType type);
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
		std::string serverSecurityPolicy;
		ConfigurationSecurityMode securityMode;
		ServerSecurityModeConfiguration(const std::string& config, const std::string& policy, ConfigurationSecurityMode mode);
		ServerSecurityModeConfiguration();
		~ServerSecurityModeConfiguration();
		ServerSecurityModeConfiguration(const ServerSecurityModeConfiguration& src) = default;
		ServerSecurityModeConfiguration& operator=(const ServerSecurityModeConfiguration& rhs) = default;
		ServerSecurityModeConfiguration(ServerSecurityModeConfiguration&& src) = default;
		ServerSecurityModeConfiguration& operator=(ServerSecurityModeConfiguration&& rhs) = default;
	};

	bool operator==(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs);
	bool operator!=(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs);
	bool operator<(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs);

	struct SecurityUserNameAccess {
		std::string m_login;
		std::string m_password;
		SecurityUserNameAccess(const std::string& login, const std::string& password);
		SecurityUserNameAccess(const SecurityUserNameAccess& src) = default;
		SecurityUserNameAccess& operator=(const SecurityUserNameAccess& src) = default;
		SecurityUserNameAccess(SecurityUserNameAccess&& src) = default;
		SecurityUserNameAccess& operator=(SecurityUserNameAccess&& src) = default;
		SecurityUserNameAccess();
		~SecurityUserNameAccess();
	};
	bool operator==(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs);
	bool operator!=(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs);

	struct SecurityCertificateAccess {
		std::string m_password;
		std::string m_certificate;
		std::string m_privateKey;
		std::string m_pkiTrustedPath;
		SecurityCertificateAccess(std::string password, std::string certificate, std::string privateKey, std::string pkiTrustedPath);
		SecurityCertificateAccess(const SecurityCertificateAccess& src) = default;
		SecurityCertificateAccess& operator=(const SecurityCertificateAccess& src) = default;
		SecurityCertificateAccess(SecurityCertificateAccess&& src) = default;
		SecurityCertificateAccess& operator=(SecurityCertificateAccess&& src) = default;
		SecurityCertificateAccess();
		~SecurityCertificateAccess();
	};
	bool operator==(const SecurityCertificateAccess& lhs, const SecurityCertificateAccess& rhs);
	bool operator!=(const SecurityCertificateAccess& lhs, const SecurityCertificateAccess& rhs);

	struct SecurityUserTokenPolicy {
		SecurityUserTokenPolicy(const std::string& policyId, const std::string& securityPolicyUri, int type);
		SecurityUserTokenPolicy(const std::string& policyId, const std::string& securityPolicyUri, ConfigurationSecurityType type);
		SecurityUserTokenPolicy() = default;
		SecurityUserTokenPolicy(const SecurityUserTokenPolicy& src) = default;
		SecurityUserTokenPolicy& operator=(const SecurityUserTokenPolicy& src) = default;
		SecurityUserTokenPolicy(SecurityUserTokenPolicy&& src) = default;
		SecurityUserTokenPolicy& operator=(SecurityUserTokenPolicy&& src) = default;
		~SecurityUserTokenPolicy();
		std::string m_policyId;
		std::string m_securityPolicyUri;
		ConfigurationSecurityType m_securityType;
	};

	bool operator==(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs);
	bool operator!=(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs);
	bool operator<(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs);


	struct SecurityAccessConfiguration {
		SecurityUserNameAccess m_userLogin;
		SecurityCertificateAccess m_certificate;
		SecurityUserTokenPolicy m_policy;
		SecurityAccessConfiguration(const SecurityUserNameAccess& user, const SecurityCertificateAccess& certificate, const SecurityUserTokenPolicy& policy);
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

	struct DataTypeAttributes {
		int m_iProcessed;
		std::pair<std::string, int> m_pAggregateType;
		double m_dProcessingInterval;
		std::vector<std::string> m_vDataQuantities;
	};
}