#include"pch.h"
#include"XMLSettingsDataSource.h"
#include<pugixml.hpp>

bool DrvOPCUAHistValues::XMLSettingsDataSource::Save(const ConnectionAttributes& attributes, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Settings");
	pugi::xml_node serverNode = rootNode.append_child("ServerConfiguration");
	serverNode.append_attribute("Computer").set_value(attributes.configuration.computerName.c_str());
	serverNode.append_attribute("Server").set_value(attributes.configuration.serverName.c_str());
	serverNode.append_attribute("Port").set_value(attributes.configuration.port);
	pugi::xml_node securityModeNode = rootNode.append_child("SecurityModeConfiguration");
	securityModeNode.append_attribute("Configuration").set_value(attributes.configurationMode.serverSecurityName.c_str());
	securityModeNode.append_attribute("SecurityMode").set_value(GetIntFromSecurityMode(attributes.configurationMode.securityMode));
	pugi::xml_node connectionNode = rootNode.append_child("SecurityAccessConfiguration");
	connectionNode.append_attribute("User").set_value(attributes.configurationAccess.login.c_str());
	std::string encryptPass = attributes.configurationAccess.password;
	connectionNode.append_attribute("Password").set_value(encryptPass.c_str());
	std::string encryptCertificate = attributes.configurationAccess.certificate;
	connectionNode.append_attribute("Certificate").set_value(encryptCertificate.c_str());
	std::string encryptKey = attributes.configurationAccess.privateKey;
	connectionNode.append_attribute("PrivateKey").set_value(encryptKey.c_str());
	connectionNode.append_attribute("SecurityType").set_value(GetIntFromSecurityType(attributes.configurationAccess.securityType));
	doc.save(stream);
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::Load(ConnectionAttributes& attributes, std::istream& stream)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load(stream);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node serverNode = rootNode.child("ServerConfiguration");
	std::string computerName = std::string(serverNode.attribute("Computer").as_string());
	std::string serverName = std::string(serverNode.attribute("Server").as_string());
	unsigned int port = serverNode.attribute("Port").as_uint();
	ServerConfiguration serverConfiguration(computerName, serverName, port);

	pugi::xml_node securityModeNode = rootNode.child("SecurityModeConfiguration");
	std::string serverSecurityName = std::string(securityModeNode.attribute("Configuration").as_string());
	int intMode = securityModeNode.attribute("SecurityMode").as_int();
	ServerSecurityModeConfiguration modeConfiguration(serverSecurityName, GetModeFromInt(intMode));

	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("User").as_string());
	std::string pass = std::string(connectionNode.attribute("Password").as_string());
	std::string certificate = std::string(connectionNode.attribute("Certificate").as_string());
	std::string privateKey = std::string(connectionNode.attribute("PrivateKey").as_string());
	int type = connectionNode.attribute("SecurityType").as_int();
	SecurityAccessConfiguration configurationAccess(loginName, pass, certificate, privateKey, GetTypeFromInt(type));
	
	attributes.configuration = serverConfiguration;
	attributes.configurationMode = modeConfiguration;
	attributes.configurationAccess = configurationAccess;

	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::LoadAttributesString(const char* source, size_t length, ConnectionAttributes& attributes)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_buffer(source, length);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node serverNode = rootNode.child("ServerConfiguration");
	std::string computerName = std::string(serverNode.attribute("Computer").as_string());
	std::string serverName = std::string(serverNode.attribute("Server").as_string());
	unsigned int port = serverNode.attribute("Port").as_uint();
	ServerConfiguration serverConfiguration(computerName, serverName, port);

	pugi::xml_node securityModeNode = rootNode.child("SecurityModeConfiguration");
	std::string serverSecurityName = std::string(securityModeNode.attribute("Configuration").as_string());
	int intMode = securityModeNode.attribute("SecurityMode").as_int();
	ServerSecurityModeConfiguration modeConfiguration(serverSecurityName, GetModeFromInt(intMode));

	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("User").as_string());
	std::string pass = std::string(connectionNode.attribute("Password").as_string());
	std::string certificate = std::string(connectionNode.attribute("Certificate").as_string());
	std::string privateKey = std::string(connectionNode.attribute("PrivateKey").as_string());
	int type = connectionNode.attribute("SecurityType").as_int();
	SecurityAccessConfiguration configurationAccess(loginName, pass, certificate, privateKey, GetTypeFromInt(type));

	attributes.configuration = serverConfiguration;
	attributes.configurationMode = modeConfiguration;
	attributes.configurationAccess = configurationAccess;
	return true;
}

