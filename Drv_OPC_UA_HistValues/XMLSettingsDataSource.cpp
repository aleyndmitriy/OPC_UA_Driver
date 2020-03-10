#include"pch.h"
#include"XMLSettingsDataSource.h"
#include<pugixml.hpp>

bool DrvOPCUAHistValues::XMLSettingsDataSource::Save(const ConnectionAttributes& connectionAttributes, const DataTypeAttributes& dataAttributes, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Settings");
	pugi::xml_node serverNode = rootNode.append_child("ServerConfiguration");
	serverNode.append_attribute("Computer").set_value(connectionAttributes.configuration.computerName.c_str());
	serverNode.append_attribute("Server").set_value(connectionAttributes.configuration.serverName.c_str());
	serverNode.append_attribute("Port").set_value(connectionAttributes.configuration.port);
	pugi::xml_node securityModeNode = rootNode.append_child("SecurityModeConfiguration");
	securityModeNode.append_attribute("Configuration").set_value(connectionAttributes.configurationMode.serverSecurityName.c_str());
	securityModeNode.append_attribute("SecurityMode").set_value(GetIntFromSecurityMode(connectionAttributes.configurationMode.securityMode));
	securityModeNode.append_attribute("SecurityPolicy").set_value(connectionAttributes.configurationMode.serverSecurityPolicy.c_str());
	pugi::xml_node connectionNode = rootNode.append_child("SecurityAccessConfiguration");
	connectionNode.append_attribute("UserName").set_value(connectionAttributes.configurationAccess.m_userLogin.m_login.c_str());
	std::string encryptUserPass = connectionAttributes.configurationAccess.m_userLogin.m_password;
	connectionNode.append_attribute("UserPassword").set_value(encryptUserPass.c_str());
	connectionNode.append_attribute("Certificate").set_value(connectionAttributes.configurationAccess.m_certificate.m_certificate.c_str());
	std::string encryptCertificatePass = connectionAttributes.configurationAccess.m_certificate.m_password;
	connectionNode.append_attribute("CertificatePassword").set_value(encryptCertificatePass.c_str());
	connectionNode.append_attribute("PrivateKey").set_value(connectionAttributes.configurationAccess.m_certificate.m_privateKey.c_str());
	connectionNode.append_attribute("PkiTrustedStore").set_value(connectionAttributes.configurationAccess.m_certificate.m_pkiTrustedPath.c_str());
	connectionNode.append_attribute("PolicyId").set_value(connectionAttributes.configurationAccess.m_policy.m_policyId.c_str());
	connectionNode.append_attribute("PolicyUri").set_value(connectionAttributes.configurationAccess.m_policy.m_securityPolicyUri.c_str());
	connectionNode.append_attribute("SecurityType").set_value(GetIntFromSecurityType(connectionAttributes.configurationAccess.m_policy.m_securityType));

	rootNode = doc.append_child("DataType");
	pugi::xml_node processedNode = rootNode.append_child("ReadType");
	processedNode.append_attribute("Processed").set_value(dataAttributes.m_iProcessed);
	processedNode.append_attribute("Aggregate").set_value(dataAttributes.m_pAggregateType.first.c_str());
	processedNode.append_attribute("Identifier").set_value(dataAttributes.m_pAggregateType.second);
	processedNode.append_attribute("Interval").set_value(dataAttributes.m_dProcessingInterval);
	pugi::xml_node qualitiesNode = rootNode.append_child("DataQualities");
	for (std::vector<std::string>::const_iterator itr = dataAttributes.m_vDataQuantities.cbegin(); itr != dataAttributes.m_vDataQuantities.cend(); ++itr) {
		pugi::xml_node qualityNode = qualitiesNode.append_child("Quality");
		qualityNode.append_attribute("Value").set_value(itr->c_str());
	}
	doc.save(stream);
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::Load(ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes, std::istream& stream)
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
	std::string serverSecurityPolicy = std::string(securityModeNode.attribute("SecurityPolicy").as_string());
	ServerSecurityModeConfiguration modeConfiguration(serverSecurityName, serverSecurityPolicy, GetModeFromInt(intMode));
	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("UserName").as_string());
	std::string loginPass = std::string(connectionNode.attribute("UserPassword").as_string());
	SecurityUserNameAccess userAccess(loginName, loginPass);

	std::string certificate = std::string(connectionNode.attribute("Certificate").as_string());
	std::string certificatePassword = std::string(connectionNode.attribute("CertificatePassword").as_string());
	std::string privateKey = std::string(connectionNode.attribute("PrivateKey").as_string());
	std::string pkiKey = std::string(connectionNode.attribute("PkiTrustedStore").as_string());
	SecurityCertificateAccess certificateAccess(certificatePassword,certificate,privateKey,pkiKey);

	std::string policyId = std::string(connectionNode.attribute("PolicyId").as_string());
	std::string policyUri = std::string(connectionNode.attribute("PolicyUri").as_string());
	int type = connectionNode.attribute("SecurityType").as_int();
	SecurityUserTokenPolicy policy(policyId, policyUri, type);
	SecurityAccessConfiguration configurationAccess(userAccess, certificateAccess, policy);
	
	connectionAttributes.configuration = serverConfiguration;
	connectionAttributes.configurationMode = modeConfiguration;
	connectionAttributes.configurationAccess = configurationAccess;

	rootNode = doc.child("DataType");
	pugi::xml_node processedNode = rootNode.child("ReadType");
	int processed = processedNode.attribute("Processed").as_int();
	std::string processedType = std::string(processedNode.attribute("Aggregate").as_string());
	int indexAggregateType = processedNode.attribute("Identifier").as_int();
	double interval = processedNode.attribute("Interval").as_double();
	pugi::xml_node qualitiesNode = rootNode.child("DataQualities");
	std::vector<std::string> qualities;
	for (pugi::xml_node qualityNode = qualitiesNode.child("Quality"); qualityNode; qualityNode = qualityNode.next_sibling("Quality"))
	{
		std::string quality = std::string(qualityNode.attribute("Value").as_string());
		qualities.push_back(quality);
	}
	dataAttributes.m_vDataQuantities.clear();
	dataAttributes.m_iProcessed = processed;
	dataAttributes.m_pAggregateType = std::make_pair<std::string, int>(std::move(processedType), std::move(indexAggregateType));
	dataAttributes.m_dProcessingInterval = interval;
	if (!qualities.empty()) {
		dataAttributes.m_vDataQuantities.assign(qualities.cbegin(), qualities.cend());
	}
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::LoadAttributesString(const char* source, size_t length, ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes)
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
	std::string serverSecurityPolicy = std::string(securityModeNode.attribute("SecurityPolicy").as_string());
	ServerSecurityModeConfiguration modeConfiguration(serverSecurityName, serverSecurityPolicy, GetModeFromInt(intMode));

	pugi::xml_node connectionNode = rootNode.child("SecurityAccessConfiguration");
	std::string loginName = std::string(connectionNode.attribute("UserName").as_string());
	std::string loginPass = std::string(connectionNode.attribute("UserPassword").as_string());
	SecurityUserNameAccess userAccess(loginName, loginPass);

	std::string certificate = std::string(connectionNode.attribute("Certificate").as_string());
	std::string certificatePassword = std::string(connectionNode.attribute("CertificatePassword").as_string());
	std::string privateKey = std::string(connectionNode.attribute("PrivateKey").as_string());
	std::string pkiKey = std::string(connectionNode.attribute("PkiTrustedStore").as_string());
	SecurityCertificateAccess certificateAccess(certificatePassword, certificate, privateKey, pkiKey);

	std::string policyId = std::string(connectionNode.attribute("PolicyId").as_string());
	std::string policyUri = std::string(connectionNode.attribute("PolicyUri").as_string());
	int type = connectionNode.attribute("SecurityType").as_int();
	SecurityUserTokenPolicy policy(policyId, policyUri, type);
	SecurityAccessConfiguration configurationAccess(userAccess, certificateAccess, policy);

	connectionAttributes.configuration = serverConfiguration;
	connectionAttributes.configurationMode = modeConfiguration;
	connectionAttributes.configurationAccess = configurationAccess;

	rootNode = doc.child("DataType");
	pugi::xml_node processedNode = rootNode.child("ReadType");
	int processed = processedNode.attribute("Processed").as_int();
	std::string processedType = std::string(processedNode.attribute("Aggregate").as_string());
	int indexAggregateType = processedNode.attribute("Identifier").as_int();
	double interval = processedNode.attribute("Interval").as_double();
	pugi::xml_node qualitiesNode = rootNode.child("DataQualities");
	std::vector<std::string> qualities;
	for (pugi::xml_node qualityNode = qualitiesNode.child("Quality"); qualityNode; qualityNode = qualityNode.next_sibling("Quality"))
	{
		std::string  quality = std::string(qualityNode.attribute("Value").as_string());
		qualities.push_back(quality);
	}
	dataAttributes.m_vDataQuantities.clear();
	dataAttributes.m_iProcessed = processed;
	dataAttributes.m_pAggregateType = std::make_pair<std::string, int>(std::move(processedType),std::move(indexAggregateType));
	dataAttributes.m_dProcessingInterval = interval;
	if (!qualities.empty()) {
		dataAttributes.m_vDataQuantities.assign(qualities.cbegin(), qualities.cend());
	}
	return true;
}

