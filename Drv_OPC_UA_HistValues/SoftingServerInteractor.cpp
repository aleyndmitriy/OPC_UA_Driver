#include"pch.h"
#include"SoftingServerInteractor.h"
#include"Utils.h"
#include"Constants.h"
#include<algorithm>

SoftingServerInteractor::SoftingServerInteractor(SoftingServerInteractorOutput* output, const std::string& compName):
	m_strCompServName(compName), m_pOutput(output), m_pApp(), m_AppDesc(), m_enumResult(), m_serversList(), m_selectedUrlEndpointDescriptions()
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
	InitApplicationDescription();	// this function is user defined
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

SoftingServerInteractor::SoftingServerInteractor(const std::string& compName): SoftingServerInteractor(nullptr, compName)
{

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
		for (std::vector<SoftingOPCToolbox5::ApplicationDescription>::iterator itr = m_serversList.begin(); itr != m_serversList.end(); itr++) {
			itr->clear();
		}
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

void SoftingServerInteractor::InitApplicationDescription()
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

bool SoftingServerInteractor::findServersDescription()
{
	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<std::string> serverURIs;
	m_serversList.clear();
	std::string compName = m_strCompServName;
	if (m_strCompServName.empty()) {
		return false;
	}
	std::string discoveryServerUrl = std::string("opc.tcp://") + m_strCompServName; //+ std::string(":51510/");
	result = m_pApp->findServers(discoveryServerUrl, serverURIs, m_serversList);
	if (StatusCode::isBad(result))
	{
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
		}
		return false;
	}
	return true;
}

void SoftingServerInteractor::GetServers()
{
	std::vector<std::string> vec;
	if (m_serversList.empty()) {
		if (findServersDescription() == false) {
			return ;
		}
	}
	std::transform(m_serversList.cbegin(), m_serversList.cend(), std::back_inserter(vec), [](const SoftingOPCToolbox5::ApplicationDescription& desc) {
		std::string name(desc.getApplicationUri());
		::Sleep(1000);
		return name; });

	if (m_pOutput) {
		m_pOutput->GetServers(std::move(vec));
	}
}

void SoftingServerInteractor::ChooseCurrentServer(int index) {
	if (index < 0) {
		std::string message("Select sever!");
		if (m_pOutput) {
			m_pOutput->SendWarning(std::move(message));
		}
		return;
	}
	std::vector<tstring> discoveryUrls;
	discoveryUrls = m_serversList[index].getDiscoveryUrls();
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
			std::vector<tstring> endpointDescriptionsString;
			EnumStatusCode result = EnumStatusCode_Good;
			result = m_pApp->getEndpointsFromServer(*itr, transportProfileList, m_selectedUrlEndpointDescriptions);
			if (StatusCode::isBad(result))
			{
				if (m_pOutput) {
					std::string message = std::string("Failed to get endpoint descriptions: ") + std::string(getEnumStatusCodeString(m_enumResult));
					m_pOutput->SendWarning(std::move(message));
				}
			}
			std::transform(m_selectedUrlEndpointDescriptions.cbegin(), m_selectedUrlEndpointDescriptions.cend(), std::back_inserter(endpointDescriptionsString), [](const SoftingOPCToolbox5::EndpointDescription& desc) {
				std::string name(desc.getEndpointUrl());
				std::string policy = desc.getSecurityPolicy();
				EnumMessageSecurityMode mode = desc.getMessageSecurityMode();
				std::string modeStr = std::to_string(mode);
				std::string endDesc = name + std::string("-") + policy + std::string("-") + modeStr;
				Sleep(1000);
				return endDesc; });
			if (m_pOutput) {
				m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
			}
			break;
		}
	}
}
