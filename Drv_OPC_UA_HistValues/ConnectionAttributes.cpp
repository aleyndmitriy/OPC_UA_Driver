#include"pch.h"
#include"ConnectionAttributes.h"

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


DrvOPCUAHistValues::ServerSecurityModeConfiguration::ServerSecurityModeConfiguration(const std::string& config, ConfigurationSecurityMode mode):
	serverSecurityName(config),securityMode(mode)
{

}

DrvOPCUAHistValues::ServerSecurityModeConfiguration::ServerSecurityModeConfiguration(const std::string& config):
	ServerSecurityModeConfiguration(config, ConfigurationSecurityMode::INVALID)
{

}

DrvOPCUAHistValues::ServerSecurityModeConfiguration::ServerSecurityModeConfiguration():
	ServerSecurityModeConfiguration(std::string())
{

}

DrvOPCUAHistValues::ServerSecurityModeConfiguration::~ServerSecurityModeConfiguration()
{
	serverSecurityName.clear();
	securityMode = ConfigurationSecurityMode::INVALID;
}

bool DrvOPCUAHistValues::operator==(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs)
{
	return lhs.serverSecurityName == rhs.serverSecurityName && lhs.securityMode == rhs.securityMode;
}

bool DrvOPCUAHistValues::operator!=(const ServerSecurityModeConfiguration& lhs, const ServerSecurityModeConfiguration& rhs)
{
	return lhs.serverSecurityName != rhs.serverSecurityName || lhs.securityMode != rhs.securityMode;
}

DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration(const std::string& loginString, const std::string& passString, const::std::string& certificateString, const::std::string& keyString, ConfigurationSecurityType type):
	login(loginString),password(passString),certificate(certificateString),privateKey(keyString), securityType(type)
{

}

DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration(const std::string& loginString, const std::string& passString):
	SecurityAccessConfiguration(loginString,passString,std::string(),std::string(),ConfigurationSecurityType::USER_NAME)
{

}

DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration(const::std::string& key, ConfigurationSecurityType type):
	SecurityAccessConfiguration(std::string(), std::string(), std::string(), std::string(), type)
{
	if (type == ConfigurationSecurityType::CERTIFICATE) {
		certificate = key;
	}
	else if (type == ConfigurationSecurityType::ISSUED_TOKEN) {
		privateKey = key;
	}
}

DrvOPCUAHistValues::SecurityAccessConfiguration::SecurityAccessConfiguration() :
	SecurityAccessConfiguration(std::string(), std::string(), std::string(), std::string(), ConfigurationSecurityType::ANONYMOUS)
{
	
}

DrvOPCUAHistValues::SecurityAccessConfiguration::~SecurityAccessConfiguration()
{
	login.clear();
	password.clear();
	certificate.clear();
	privateKey.clear();
	securityType = ConfigurationSecurityType::ANONYMOUS;
}

bool DrvOPCUAHistValues::operator==(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.login == rhs.login && lhs.password == rhs.password && lhs.certificate == rhs.certificate &&
		lhs.privateKey == rhs.privateKey && lhs.securityType == rhs.securityType;
}

bool DrvOPCUAHistValues::operator!=(const SecurityAccessConfiguration& lhs, const SecurityAccessConfiguration& rhs)
{
	return lhs.login != rhs.login || lhs.password != rhs.password || lhs.certificate != rhs.certificate ||
		lhs.privateKey != rhs.privateKey || lhs.securityType != rhs.securityType;
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