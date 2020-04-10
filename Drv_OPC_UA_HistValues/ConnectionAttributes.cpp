#include"pch.h"
#include"ConnectionAttributes.h"

int DrvOPCUAHistValues::GetIntFromSecurityMode(ConfigurationSecurityMode mode)
{
	switch (mode) {
	case ConfigurationSecurityMode::INVALID:
		return 0;
		break;
	case ConfigurationSecurityMode::NONE:
		return 1;
		break;
	case ConfigurationSecurityMode::SIGN:
		return 2;
		break;
	case  ConfigurationSecurityMode::SIGN_AND_ENCRYPT:
		return 3;
		break;
	default:
		return 0;
		break;
	}
}

std::string DrvOPCUAHistValues::GetStringFromSecurityMode(ConfigurationSecurityMode mode)
{
	switch (mode) {
	case ConfigurationSecurityMode::NONE:
		return std::string("None");
		break;
	case ConfigurationSecurityMode::SIGN:
		return std::string("Sign");
		break;
	case  ConfigurationSecurityMode::SIGN_AND_ENCRYPT:
		return std::string("Sign and Encrypt");
		break;
	default:
		return std::string("Invalid");
	}
}

DrvOPCUAHistValues::ConfigurationSecurityMode DrvOPCUAHistValues::GetModeFromString(const std::string& mode)
{
	if (mode == std::string("None")) {
		return ConfigurationSecurityMode::NONE;
	}
	else if (mode == std::string("Sign")) {
		return ConfigurationSecurityMode::SIGN;
	}
	else if (mode == std::string("Sign and Encrypt")) {
		return ConfigurationSecurityMode::SIGN_AND_ENCRYPT;
	}
	else {
		return ConfigurationSecurityMode::INVALID;
	}
}

DrvOPCUAHistValues::ConfigurationSecurityMode DrvOPCUAHistValues::GetModeFromInt(int mode)
{
	switch (mode) {
	case 3:
		return ConfigurationSecurityMode::SIGN_AND_ENCRYPT;
		break;
	case 2:
		return ConfigurationSecurityMode::SIGN;
		break;
	case 1:
		return ConfigurationSecurityMode::NONE;
		break;
	default:
		return ConfigurationSecurityMode::INVALID;
		break;
	}
}

int DrvOPCUAHistValues::GetIntFromSecurityType(ConfigurationSecurityType type)
{
	switch (type) {
	case ConfigurationSecurityType::USER_NAME:
		return 1;
	case ConfigurationSecurityType::CERTIFICATE:
		return 2;
	case  ConfigurationSecurityType::ISSUED_TOKEN:
		return 3;
	default:
		return 0;
	}
}

std::string DrvOPCUAHistValues::GetStringFromSecurityType(ConfigurationSecurityType type)
{
	switch (type) {
	case ConfigurationSecurityType::USER_NAME:
		return std::string("User Name");
		break;
	case ConfigurationSecurityType::CERTIFICATE:
		return std::string("Certificate");
		break;
	case  ConfigurationSecurityType::ISSUED_TOKEN:
		return std::string("Issued Token");
		break;
	default:
		return std::string("Anonymous");
		break;
	}
}

DrvOPCUAHistValues::ConfigurationSecurityType DrvOPCUAHistValues::GetTypeFromInt(int type)
{
	switch (type) {
	case 3:
		return ConfigurationSecurityType::ISSUED_TOKEN;
		break;
	case 2:
		return ConfigurationSecurityType::CERTIFICATE;
		break;
	case 1:
		return ConfigurationSecurityType::USER_NAME;
		break;
	default:
		return ConfigurationSecurityType::ANONYMOUS;
		break;
	}
}


DrvOPCUAHistValues::ServerConfiguration::ServerConfiguration(const std::string& computer, const std::string& server, unsigned int number):
	computerName(computer),serverName(server),port(number)
{

}

DrvOPCUAHistValues::ServerConfiguration::ServerConfiguration(const std::string& computer, unsigned int number):
	ServerConfiguration(computer, std::string(), number)
{

}

DrvOPCUAHistValues::ServerConfiguration::ServerConfiguration(const std::string& computer):
	ServerConfiguration(computer,  0)
{

}

DrvOPCUAHistValues::ServerConfiguration::ServerConfiguration():
	ServerConfiguration(std::string())
{

}

DrvOPCUAHistValues::ServerConfiguration::~ServerConfiguration()
{
	computerName.clear();
	serverName.clear();
	port = 0;
}

bool DrvOPCUAHistValues::operator==(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.computerName == rhs.computerName && lhs.serverName == rhs.serverName && lhs.port == rhs.port;
}

bool DrvOPCUAHistValues::operator!=(const ServerConfiguration& lhs, const ServerConfiguration& rhs)
{
	return lhs.computerName != rhs.computerName || lhs.serverName != rhs.serverName || lhs.port != rhs.port;
}


DrvOPCUAHistValues::ServerSecurityModeConfiguration::ServerSecurityModeConfiguration(const std::string& config, const std::string& policy, ConfigurationSecurityMode mode):
	serverSecurityName(config), serverSecurityPolicy(policy), securityMode(mode)
{

}

DrvOPCUAHistValues::ServerSecurityModeConfiguration::ServerSecurityModeConfiguration():
	ServerSecurityModeConfiguration(std::string(),std::string(), ConfigurationSecurityMode::INVALID)
{

}

DrvOPCUAHistValues::ServerSecurityModeConfiguration::~ServerSecurityModeConfiguration()
{
	serverSecurityName.clear();
	serverSecurityPolicy.clear();
	securityMode = ConfigurationSecurityMode::INVALID;
}

bool DrvOPCUAHistValues::operator==(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs)
{
	return lhs.serverSecurityName == rhs.serverSecurityName && lhs.securityMode == rhs.securityMode && rhs.serverSecurityPolicy == lhs.serverSecurityPolicy;
}

bool DrvOPCUAHistValues::operator!=(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs)
{
	return lhs.serverSecurityName != rhs.serverSecurityName || lhs.securityMode != rhs.securityMode || rhs.serverSecurityPolicy == lhs.serverSecurityPolicy;
}

bool DrvOPCUAHistValues::operator<(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs)
{
	if (lhs.serverSecurityName < rhs.serverSecurityName) {
		return true;
	}
	else {
		if (lhs.serverSecurityName == rhs.serverSecurityName) {
			if (lhs.securityMode < rhs.securityMode) {
				return true;
			}
			else {
				if (lhs.securityMode == rhs.securityMode) {
					return lhs.serverSecurityPolicy < rhs.serverSecurityPolicy;
				}
				return false;
			}
		}
		return false;
	}
}


DrvOPCUAHistValues::SecurityUserNameAccess::SecurityUserNameAccess(const std::string& login, const std::string& password):
	m_login(login),m_password(password)
{

}

DrvOPCUAHistValues::SecurityUserNameAccess::SecurityUserNameAccess():SecurityUserNameAccess(std::string(),std::string())
{

}

DrvOPCUAHistValues::SecurityUserNameAccess::~SecurityUserNameAccess()
{

}


bool DrvOPCUAHistValues::operator==(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs)
{
	return lhs.m_login == rhs.m_login && lhs.m_password == rhs.m_password;
}

bool DrvOPCUAHistValues::operator!=(const SecurityUserNameAccess& lhs, const SecurityUserNameAccess& rhs)
{
	return lhs.m_login != rhs.m_login || lhs.m_password != rhs.m_password;
}

DrvOPCUAHistValues::SecurityCertificateAccess::SecurityCertificateAccess(std::string password, std::string certificate, std::string privateKey, std::string pkiTrustedPath) :
	m_password(password),m_certificate(certificate), m_privateKey(privateKey),m_pkiTrustedPath(pkiTrustedPath)
{

}

DrvOPCUAHistValues::SecurityCertificateAccess::SecurityCertificateAccess():SecurityCertificateAccess(std::string(), std::string(), std::string(), std::string())
{

}

DrvOPCUAHistValues::SecurityCertificateAccess::~SecurityCertificateAccess()
{

}


DrvOPCUAHistValues::SecurityUserTokenPolicy::SecurityUserTokenPolicy(const std::string& policyId, const std::string& securityPolicyUri, int type) :
	m_policyId(policyId), m_securityPolicyUri(securityPolicyUri), m_securityType(GetTypeFromInt(type))
{

}

DrvOPCUAHistValues::SecurityUserTokenPolicy::SecurityUserTokenPolicy(const std::string& policyId, const std::string& securityPolicyUri, ConfigurationSecurityType type) :
	m_policyId(policyId), m_securityPolicyUri(securityPolicyUri), m_securityType(type)
{

}

DrvOPCUAHistValues::SecurityUserTokenPolicy::SecurityUserTokenPolicy(): SecurityUserTokenPolicy(std::string(),std::string(), ConfigurationSecurityType::ANONYMOUS)
{

}

DrvOPCUAHistValues::SecurityUserTokenPolicy::~SecurityUserTokenPolicy()
{

}

bool DrvOPCUAHistValues::operator==(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs)
{
	return lhs.m_policyId == rhs.m_policyId && lhs.m_securityType == rhs.m_securityType && lhs.m_securityPolicyUri == rhs.m_securityPolicyUri;
}

bool DrvOPCUAHistValues::operator!=(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs)
{
	return lhs.m_policyId != rhs.m_policyId || lhs.m_securityType != rhs.m_securityType || lhs.m_securityPolicyUri != rhs.m_securityPolicyUri;
}

bool DrvOPCUAHistValues::operator<(const DrvOPCUAHistValues::SecurityUserTokenPolicy& lhs, const DrvOPCUAHistValues::SecurityUserTokenPolicy& rhs)
{
	if (lhs.m_policyId < rhs.m_policyId) {
		return true;
	}
	else {
		if (lhs.m_policyId == rhs.m_policyId) {
			if (lhs.m_securityType < rhs.m_securityType) {
				return true;
			}
			else {
				if (lhs.m_securityType == rhs.m_securityType) {
					return lhs.m_securityPolicyUri == rhs.m_securityPolicyUri;
				}
				return false;
			}
		}
		return false;
	}
}

bool DrvOPCUAHistValues::operator==(const SecurityCertificateAccess& lhs, const SecurityCertificateAccess& rhs)
{
	return lhs.m_password == rhs.m_password && lhs.m_certificate == rhs.m_certificate &&
		lhs.m_privateKey == rhs.m_privateKey && lhs.m_pkiTrustedPath == rhs.m_pkiTrustedPath;
}

bool DrvOPCUAHistValues::operator!=(const SecurityCertificateAccess& lhs, const SecurityCertificateAccess& rhs)
{
	return lhs.m_password != rhs.m_password || lhs.m_certificate != rhs.m_certificate ||
		lhs.m_privateKey != rhs.m_privateKey || lhs.m_pkiTrustedPath != rhs.m_pkiTrustedPath;
}


DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration(const SecurityUserNameAccess& user, const SecurityCertificateAccess& certificate, const SecurityUserTokenPolicy& policy):
	m_userLogin(user), m_certificate(certificate), m_policy(policy)
{

}


DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration() :
	SecurityAccessConfiguration(SecurityUserNameAccess(), SecurityCertificateAccess(), SecurityUserTokenPolicy())
{
	
}

DrvOPCUAHistValues::SecurityAccessConfiguration::~SecurityAccessConfiguration()
{
	
}

bool DrvOPCUAHistValues::operator==(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.m_userLogin == rhs.m_userLogin && lhs.m_certificate == rhs.m_certificate && lhs.m_policy == rhs.m_policy;
}

bool DrvOPCUAHistValues::operator!=(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.m_userLogin != rhs.m_userLogin || lhs.m_certificate != rhs.m_certificate || lhs.m_policy != rhs.m_policy;
}

DrvOPCUAHistValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server, const ServerSecurityModeConfiguration& mode, const SecurityAccessConfiguration& accessType):
	configuration(server), configurationMode(mode), configurationAccess(accessType)
{

}

DrvOPCUAHistValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server, const ServerSecurityModeConfiguration& mode) :
	ConnectionAttributes(server, mode, SecurityAccessConfiguration())
{

}

DrvOPCUAHistValues::ConnectionAttributes::ConnectionAttributes(const ServerConfiguration& server) :
	ConnectionAttributes(server, ServerSecurityModeConfiguration())
{

}

DrvOPCUAHistValues::ConnectionAttributes::ConnectionAttributes() :
	ConnectionAttributes(ServerConfiguration())
{

}

DrvOPCUAHistValues::ConnectionAttributes::~ConnectionAttributes() 
{

}

bool DrvOPCUAHistValues::operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration == rhs.configuration && lhs.configurationMode == rhs.configurationMode && lhs.configurationAccess == rhs.configurationAccess;
}

bool DrvOPCUAHistValues::operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return lhs.configuration != rhs.configuration || lhs.configurationMode != rhs.configurationMode || lhs.configurationAccess != rhs.configurationAccess;
}