#include"pch.h"
#include"SoftingServerInteractor.h"
#include"Utils.h"
#include"Constants.h"
#include<algorithm>
#include<functional>

SoftingServerInteractor::SoftingServerInteractor(SoftingServerInteractorOutput* output, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes):
m_pOutput(output), m_pServerAttributes(attributes), m_pApp(), m_AppDesc(), m_enumResult(), m_selectedEndPointDescription(), m_sessionsList()
{
	m_enumResult = SoftingOPCToolbox5::loadToolbox(NULL);
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("Failed to load the SDK: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
		return;
	}
	m_pApp = SoftingOPCToolbox5::Application::instance();
	initApplicationDescription();	// this function is user defined
	// initialize the application (also initializes the underlying stack to get access to its functions)
	m_enumResult = m_pApp->initialize(&m_AppDesc);
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("Failed to initialize the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
	}
	if (StatusCode::isGood(m_enumResult))
	{
		m_enumResult = m_pApp->start();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("Failed to start the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			if (m_pOutput) {
				m_pOutput->SendMessageError(std::move(message));
			}
		}
	}
}

SoftingServerInteractor::~SoftingServerInteractor()
{
	if (StatusCode::isGood(m_enumResult))
	{
		m_enumResult = m_pApp->stop();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("An error occurred while stopping the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			if (m_pOutput) {
				m_pOutput->SendMessageError(std::move(message));
			}
		}

		m_enumResult = m_pApp->uninitialize();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("An error occurred while uninitializing the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			if (m_pOutput) {
				m_pOutput->SendMessageError(std::move(message));
			}
		}
		m_AppDesc.clear();

		m_pApp.reset();
	}
	m_enumResult = SoftingOPCToolbox5::unloadToolbox();
	
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("An error occurred while unloading the SDK: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
	}
}

void SoftingServerInteractor::initApplicationDescription()
{
	std::string hostName;
	if (getComputerName(hostName) == false)
	{
		// use the default host name
		hostName = std::string("localhost");
	}
	std::string folder = std::string("/ODS/Dream Report/System/");
	m_AppDesc.setApplicationType(EnumApplicationType_Client);
	m_AppDesc.setApplicationName(SoftingOPCToolbox5::LocalizedText(_T("DreamReport OpcUa Histotical Items Client"), _T("en")));
	m_AppDesc.setApplicationUri(_T("urn:") + hostName + folder + std::string(OPC_UA_LIBRARY_NAME));	// The ApplicationUri should match with the URI in the application certificate
	m_AppDesc.setProductUri(_T("urn:") + folder + std::string(OPC_UA_LIBRARY_NAME));
}

std::string SoftingServerInteractor::OpenConnection()
{
	GUID guid;
	if (CoCreateGuid(&guid) != S_OK) {
		return std::string();
	}
	WCHAR strGuide[MAX_UUID_LENGTH];
	int res = StringFromGUID2(guid, strGuide, MAX_UUID_LENGTH);
	std::string key = std::string(Wstr2Str(std::wstring(strGuide)));
	if (OpenConnectionWithUUID(key)) {
		return key;
	}
	else {
		return std::string();
	}
}

bool SoftingServerInteractor::OpenConnectionWithUUID(const std::string& connectionID)
{
	if (connectionID.empty()) {
		return false;
	}
	else {
		return true;
	}
}

void SoftingServerInteractor::GetServers()
{
	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (m_pOutput) {
			std::string message("Computer name is empty!");
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}

	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<std::string> serverURIs;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> serversList;

	std::string discoveryServerUrl = std::string("opc.tcp://") + m_pServerAttributes->configuration.computerName;
	if (m_pServerAttributes->configuration.port > 0) {
		discoveryServerUrl = discoveryServerUrl + std::string(":") + std::to_string(m_pServerAttributes->configuration.port) + std::string("/");
	}
	result = m_pApp->findServers(discoveryServerUrl, serverURIs, serversList);
	if (StatusCode::isBad(result) || serversList.empty())
	{
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
		return;
	}
	
	std::vector<std::string> vec;
	std::transform(serversList.cbegin(), serversList.cend(), std::back_inserter(vec), [](const SoftingOPCToolbox5::ApplicationDescription& desc) {
		std::string name(desc.getApplicationUri());
		name.erase(0, 4);
		::Sleep(1000);
		return name; });

	if (m_pOutput) {
		m_pOutput->GetServers(std::move(vec));
	}
}

void SoftingServerInteractor::ChooseCurrentServer() {

	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (m_pOutput) {
			std::string message("Computer name is empty!");
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	if (m_pServerAttributes->configuration.serverName.empty()) {
		std::string message("Select sever!");
		if (m_pOutput) {
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<std::string> serverURIs;
	serverURIs.push_back(std::string("opc.tcp://") + m_pServerAttributes->configuration.serverName);
	std::string discoveryServerUrl = std::string("opc.tcp://") + m_pServerAttributes->configuration.computerName;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> serversList;

	if (m_pServerAttributes->configuration.port > 0) {
		discoveryServerUrl = discoveryServerUrl + std::string(":") + std::to_string(m_pServerAttributes->configuration.port) + std::string("/");
	}
	
	result = m_pApp->findServers(discoveryServerUrl, serverURIs, serversList);
	if (StatusCode::isBad(result) || serversList.empty())
	{
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
		return;
	}
	std::vector<tstring> discoveryUrls;
	discoveryUrls = serversList.at(0).getDiscoveryUrls();
	if (discoveryUrls.empty())
	{
		if (m_pOutput) {
			std::string message("Invalid endpoint URL!");
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	for (std::vector<std::string>::const_iterator itr = discoveryUrls.cbegin(); itr != discoveryUrls.cend(); itr++) {
		if (itr->length() > 0) {
			std::vector<tstring> transportProfileList;
			std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription> endpointDescriptionsString;
			std::vector<SoftingOPCToolbox5::EndpointDescription> selectedUrlEndpointDescriptions;
			result = EnumStatusCode_Good;
			result = m_pApp->getEndpointsFromServer(*itr, transportProfileList, selectedUrlEndpointDescriptions);
			if (StatusCode::isBad(result))
			{
				if (m_pOutput) {
					std::string message = std::string("Failed to get endpoint descriptions: ") + std::string(getEnumStatusCodeString(m_enumResult));
					m_pOutput->SendWarning(std::move(message));
				}
			}
			std::transform(selectedUrlEndpointDescriptions.cbegin(), selectedUrlEndpointDescriptions.cend(), std::back_inserter(endpointDescriptionsString),mapEndPointDescription);
			if (m_pOutput) {
				m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
			}
			break;
		}
	}
}

void SoftingServerInteractor::ChooseCurrentEndPoint()
{
	m_selectedEndPointDescription.clear();
	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (m_pOutput) {
			std::string message("Computer name is empty!");
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	if (m_pServerAttributes->configuration.serverName.empty()) {
		std::string message("Select sever!");
		if (m_pOutput) {
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<std::string> serverURIs;
	serverURIs.push_back(m_pServerAttributes->configuration.serverName);
	std::vector<SoftingOPCToolbox5::ApplicationDescription> serverList;
	std::string discoveryServerUrl = std::string("opc.tcp://") + m_pServerAttributes->configuration.computerName;
	if (m_pServerAttributes->configuration.port > 0) {
		discoveryServerUrl = discoveryServerUrl + std::string(":") + std::to_string(m_pServerAttributes->configuration.port) + std::string("/");
	}
	result = m_pApp->findServers(discoveryServerUrl, serverURIs, serverList);
	if (StatusCode::isBad(result) || serverList.empty())
	{
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
		return;
	}
	std::vector<tstring> discoveryUrls;
	discoveryUrls = serverList.at(0).getDiscoveryUrls();
	if (discoveryUrls.empty())
	{
		if (m_pOutput) {
			std::string message("Invalid endpoint URL!");
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	for (std::vector<std::string>::const_iterator itr = discoveryUrls.cbegin(); itr != discoveryUrls.cend(); itr++) {
		if (itr->length() > 0) {
			std::vector<tstring> transportProfileList;
			std::vector<SoftingOPCToolbox5::EndpointDescription> selectedUrlEndpointDescriptions;
			result = EnumStatusCode_Good;
			result = m_pApp->getEndpointsFromServer(*itr, transportProfileList, selectedUrlEndpointDescriptions);
			if (StatusCode::isBad(result))
			{
				if (m_pOutput) {
					std::string message = std::string("Failed to get endpoint descriptions: ") + std::string(getEnumStatusCodeString(m_enumResult));
					m_pOutput->SendWarning(std::move(message));
				}
			}
			std::vector<SoftingOPCToolbox5::EndpointDescription>::const_iterator itrFound =
				std::find_if(selectedUrlEndpointDescriptions.cbegin(), selectedUrlEndpointDescriptions.cend(), std::bind(admitToAttributes, std::placeholders::_1, *m_pServerAttributes));
			if (itrFound == selectedUrlEndpointDescriptions.cend()) {
				if (m_pOutput) {
					std::string message = std::string("Failed to get endpoint with given attributes: ");
					m_pOutput->SendWarning(std::move(message));
				}
				return;
			}
			m_selectedEndPointDescription = *itrFound;
			break;
		}
	}
}


DrvOPCUAHistValues::SoftingServerEndPointDescription mapEndPointDescription(const SoftingOPCToolbox5::EndpointDescription& desc)
{
	std::string name(desc.getEndpointUrl());
	int mode = desc.getMessageSecurityMode();
	std::string certificate = desc.getServerCertificate().toString();
	unsigned int tokenCount = desc.getUserIdentityTokenCount();
	std::string token;
	int type = 0;
	if (tokenCount > 0) {
		const SoftingOPCToolbox5::IUserTokenPolicy* pPolicy = desc.getUserIdentityToken(0);
		EnumUserTokenType identityToken = pPolicy->getTokenType();
		type = identityToken;
		//token = pPolicy->getPolicyId();
		Sleep(1000);
	}
	
	DrvOPCUAHistValues::SoftingServerEndPointDescription endPointDesc(name, mode, certificate, token, type);
	return endPointDesc;
}

bool admitToAttributes(const SoftingOPCToolbox5::EndpointDescription& desc, const DrvOPCUAHistValues::ConnectionAttributes& attributes)
{
	size_t fdSofting = std::string::npos;
	std::string name(desc.getEndpointUrl());
	fdSofting = name.find(attributes.configurationMode.serverSecurityName);
	if (fdSofting == tstring::npos)
	{
		return false;
	}
	fdSofting = std::string::npos;
	std::string certificate = desc.getServerCertificate().toString();
	fdSofting = certificate.find(attributes.configurationAccess.certificate);
	if (fdSofting == tstring::npos)
	{
		return false;
	}
	int type = 0;
	unsigned int tokenCount = desc.getUserIdentityTokenCount();
	if (tokenCount == 0) {
		return false;
	}
	const SoftingOPCToolbox5::IUserTokenPolicy* pPolicy = desc.getUserIdentityToken(0);
	EnumUserTokenType identityToken = pPolicy->getTokenType();
	type = identityToken;
	if (type != DrvOPCUAHistValues::GetIntFromSecurityMode(attributes.configurationMode.securityMode)) {
		return false;
	}
	return true;
}