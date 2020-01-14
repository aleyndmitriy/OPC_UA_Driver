#include"pch.h"
#include"SoftingServerInteractor.h"
#include"Utils.h"
#include"Constants.h"
#include<algorithm>
#include<functional>
#include <UserIdentityToken.h>
#include <Statics.h>
#include"Log.h"

SoftingServerInteractor::SoftingServerInteractor():
 m_pServerAttributes(), m_pOutput(), m_pApp(), m_AppDesc(), m_enumResult(), m_selectedEndPointDescription(nullptr), m_sessionsList()
{
	m_enumResult = SoftingOPCToolbox5::loadToolbox(NULL);
	if (StatusCode::isBad(m_enumResult))
	{
		DrvOPCUAHistValues::Log::GetInstance()->WriteError(_T("Failed to load the SDK: %s"), std::string(getEnumStatusCodeString(m_enumResult)).c_str());
	}
}

SoftingServerInteractor::~SoftingServerInteractor()
{
	if (stopApplication()) {
		m_enumResult = SoftingOPCToolbox5::unloadToolbox();
		if (StatusCode::isBad(m_enumResult))
		{
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message = std::string("An error occurred while unloading the SDK:") + std::string(getEnumStatusCodeString(m_enumResult));
				output->SendMessageError(std::move(message));
			}
		}
	}
}

void SoftingServerInteractor::SetAttributes(std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes)
{
	m_pServerAttributes = attributes;
}

void SoftingServerInteractor::SetOutput(std::shared_ptr<SoftingServerInteractorOutput> output)
{
	m_pOutput.reset();
	m_pOutput = output;
}

void SoftingServerInteractor::initApplicationDescription()
{
	std::string folder = std::string("/ODS/Dream Report/System/");
	m_AppDesc.setApplicationType(EnumApplicationType_Client);
	m_AppDesc.setApplicationName(SoftingOPCToolbox5::LocalizedText(_T("DreamReport OpcUa Histotical Items Client"), _T("en")));
	m_AppDesc.setApplicationUri(_T("urn:") + m_pServerAttributes->configuration.computerName + folder + std::string(OPC_UA_LIBRARY_NAME));	// The ApplicationUri should match with the URI in the application certificate
	m_AppDesc.setProductUri(_T("urn:") + folder + std::string(OPC_UA_LIBRARY_NAME));
}

bool SoftingServerInteractor::startApplication()
{
	if (m_pApp.isNotNull()) {
		return true;
	}
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (output) {
			std::string message("Computer name is empty!");
			output->SendWarning(std::move(message));
		}
		return false;
	}
	m_pApp = SoftingOPCToolbox5::Application::instance();
	SoftingOPCToolbox5::PkiStoreConfiguration storeConfiguration;
	storeConfiguration.setCertificateTrustListLocation(_T("C:/ODS/Dream Report/System/certificates/PKI/trusted"));
	m_enumResult = m_pApp->setPkiStoreConfiguration(&storeConfiguration);
	if (StatusCode::isBad(m_enumResult))
	{
		if (output) {
			std::string message = std::string("Failed to set the PKI store configuration: ") + std::string(getEnumStatusCodeString(m_enumResult));
			output->SendMessageError(std::move(message));
		}
		m_pApp.reset();
		return false;
	}
	initApplicationDescription();
	m_enumResult = m_pApp->initialize(&m_AppDesc);
	if (StatusCode::isBad(m_enumResult))
	{
		if (output) {
			std::string message = std::string("Failed to initialize the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			output->SendMessageError(std::move(message));
		}
		m_pApp.reset();
		return false;
	}
	if (StatusCode::isGood(m_enumResult))
	{
		if (m_pServerAttributes->configurationAccess.certificate.empty() == false && m_pServerAttributes->configurationAccess.privateKey.empty() == false &&
			m_pServerAttributes->configurationAccess.password.empty() == false) {
			m_enumResult = m_pApp->setInstanceCertificate(m_pServerAttributes->configurationAccess.certificate.c_str(),
				m_pServerAttributes->configurationAccess.privateKey.c_str(), m_pServerAttributes->configurationAccess.password.c_str());
			if (StatusCode::isBad(m_enumResult))
			{
				if (output) {
					std::string message = std::string("Failed to load the application certificate: ") + std::string(getEnumStatusCodeString(m_enumResult));
					output->SendMessageError(std::move(message));
				}
				m_pApp.reset();
				return false;
			}
		}
		m_enumResult = m_pApp->start();
		if (StatusCode::isBad(m_enumResult))
		{
			if (output) {
				std::string message = std::string("Failed to start the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
				output->SendMessageError(std::move(message));
			}
			m_pApp.reset();
			return false;
		}
	}
	return true;
}

bool SoftingServerInteractor::stopApplication()
{
	if (m_pApp.isNull()) {
		return true;
	}
	if (StatusCode::isGood(m_enumResult))
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		m_enumResult = m_pApp->stop();
		if (StatusCode::isBad(m_enumResult))
		{
			if (output) {
				std::string message = std::string("An error occurred while stopping the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
				output->SendMessageError(std::move(message));
			}
			m_pApp.reset();
			return false;
		}
		m_AppDesc.clear();
		if (m_selectedEndPointDescription) {
			m_selectedEndPointDescription->clear();
		}

		m_enumResult = m_pApp->uninitialize();
		if (StatusCode::isBad(m_enumResult))
		{
			if (output) {
				std::string message = std::string("An error occurred while uninitializing the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
				output->SendMessageError(std::move(message));
			}
			m_pApp.reset();
			return false;
		}
		m_pApp.reset();
	}
	return true;
}

void SoftingServerInteractor::OpenConnection()
{
	//CPPTestServer.exe /endpointurl opc.tcp://SSBMWS015:4880
	GUID guid;
	if (CoCreateGuid(&guid) != S_OK) {
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message("Can not create Guide!");
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
		return;
	}
	WCHAR strGuide[MAX_UUID_LENGTH];
	int res = StringFromGUID2(guid, strGuide, MAX_UUID_LENGTH);
	std::string key = std::string(Wstr2Str(std::wstring(strGuide)));
	OpenConnectionWithUUID(key);
}

void SoftingServerInteractor::OpenConnectionWithUUID(const std::string& connectionID)
{
	if (connectionID.empty() || startApplication() == false) {
		return;
	}
	if (!m_selectedEndPointDescription) {
		ChooseCurrentEndPoint();
	}
	if (!m_selectedEndPointDescription) {
		return;
	}
	EnumStatusCode result = EnumStatusCode_Good;
	std::string endpointUrl = m_selectedEndPointDescription->getEndpointUrl();
	if (endpointUrl.length() <= 0)
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message("Invalid endpoint URL!");
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
	}
	SoftingOPCToolbox5::Client::SessionPtr session = SoftingOPCToolbox5::Client::Session::create();

	result = session->setUrl(endpointUrl);
	if (StatusCode::isBad(result))
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message = std::string("Set URL to the session failed: ") + std::string(getEnumStatusCodeString(result));
			output->SendMessageError(std::move(message));
			output->GetNewConnectionGuide(std::string());
		}
		return;
	}
	if (StatusCode::isGood(result))
	{
		session->setServerCertificate(m_selectedEndPointDescription->getServerCertificate());
		EnumMessageSecurityMode mode = m_selectedEndPointDescription->getMessageSecurityMode();
		std::string policy = m_selectedEndPointDescription->getSecurityPolicy();
		session->setSecurityConfiguration(mode,policy);
		// and the first (only one) user identity token
		SoftingOPCToolbox5::UserIdentityToken userIdentityToken;
		userIdentityToken.setAnonymousIdentityToken(m_selectedEndPointDescription->getUserIdentityToken(0)->getPolicyId());
		//session->setUserSecurityPolicy(m_selectedEndPointDescription->getUserIdentityToken(0)->getSecurityPolicyUri());
		session->setUserIdentityToken(&userIdentityToken);
		result = m_pApp->addSession(session);
		if (StatusCode::isBad(result))
		{
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message = std::string("Adding session failed: ") + std::string(getEnumStatusCodeString(result));
				output->SendMessageError(std::move(message));
				output->GetNewConnectionGuide(std::string());
			}
			return;
		}
		if (StatusCode::isGood(result))
		{
			result = session->connect(false);
			if (StatusCode::isBad(result))
			{
				std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
				if (output) {
					std::string message = std::string("Connecting to the server failed: ") + std::string(getEnumStatusCodeString(result));
					output->SendMessageError(std::move(message));
					output->GetNewConnectionGuide(std::string());
				}
				return;
			}
			if (StatusCode::isGood(result))
			{
				std::pair<std::string, SoftingOPCToolbox5::Client::SessionPtr> pair =
					std::make_pair<std::string, SoftingOPCToolbox5::Client::SessionPtr>(std::string(connectionID), SoftingOPCToolbox5::Client::SessionPtr(session));
				m_sessionsList.insert(pair);
				std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
				if (output) {
					output->GetNewConnectionGuide(std::string(connectionID));
				}
			}
		}
	}
}

void SoftingServerInteractor::CloseConnectionWithUUID(const std::string& connectionID)
{
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		EnumStatusCode result = EnumStatusCode_Good;
		result = iter->second->disconnect();
		if (StatusCode::isBad(result))
		{
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message = std::string("Can not disconnect session: ") + std::string(getEnumStatusCodeString(result));
				output->SendMessageError(std::move(message));
				output->GetNewConnectionGuide(std::string());
			}
		}
		m_pApp->removeSession(iter->second);
		if (StatusCode::isBad(result))
		{
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message = std::string("Can not remove session: ") + std::string(getEnumStatusCodeString(result));
				output->SendMessageError(std::move(message));
				output->GetNewConnectionGuide(std::string());
			}
		}
		iter->second.reset();
		m_sessionsList.erase(iter);
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			output->CloseConnectionWithGuide(std::string(connectionID));
		}
	}
}

void SoftingServerInteractor::GetServers()
{
	if (startApplication() == false) {
		return;
	}
	std::vector<std::string> vec;
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
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(result));
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			output->SendMessageError(std::move(message));
			output->GetServers(std::move(vec));
		}
		return;
	}
	
	std::transform(serversList.cbegin(), serversList.cend(), std::back_inserter(vec), [](const SoftingOPCToolbox5::ApplicationDescription& desc) {
		std::string name(desc.getApplicationUri());
		return name; });
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	if (output) {
		output->GetServers(std::move(vec));
	}
}

void SoftingServerInteractor::ChooseCurrentServer()
{
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription> endpointDescriptionsString;
	if (m_pServerAttributes->configuration.serverName.empty()) {
		std::string message("Select sever!");
		if (output) {
			output->SendWarning(std::move(message));
			output->GetEndPoints(std::move(endpointDescriptionsString));
		}
		return;
	}
	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<std::string> serverURIs;
	serverURIs.push_back(m_pServerAttributes->configuration.serverName);
	std::string discoveryServerUrl = std::string("opc.tcp://") + m_pServerAttributes->configuration.computerName;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> serversList;

	if (m_pServerAttributes->configuration.port > 0) {
		discoveryServerUrl = discoveryServerUrl + std::string(":") + std::to_string(m_pServerAttributes->configuration.port) + std::string("/");
	}
	
	result = m_pApp->findServers(discoveryServerUrl, serverURIs, serversList);
	if (StatusCode::isBad(result) || serversList.empty())
	{
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(result));
		if (output) {
			output->SendMessageError(std::move(message));
			output->GetEndPoints(std::move(endpointDescriptionsString));
		}
		return;
	}
	std::vector<tstring> discoveryUrls;
	discoveryUrls = serversList.at(0).getDiscoveryUrls();
	if (discoveryUrls.empty())
	{
		if (output) {
			std::string message("Invalid endpoint URL!");
			output->SendWarning(std::move(message));
			output->GetEndPoints(std::move(endpointDescriptionsString));
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
				continue;
			}
			std::transform(selectedUrlEndpointDescriptions.cbegin(), selectedUrlEndpointDescriptions.cend(), std::back_inserter(endpointDescriptionsString),mapEndPointDescription);
		}
	}
	if (output) {
		if (endpointDescriptionsString.empty()) {
			std::string message = std::string("Failed to get endpoint descriptions: ") + std::string(getEnumStatusCodeString(result));
			output->SendWarning(std::move(message));
		}
		std::sort(endpointDescriptionsString.begin(), endpointDescriptionsString.end(), IsEndPointDescLess);
		std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>::iterator last = std::unique(endpointDescriptionsString.begin(), endpointDescriptionsString.end(), IsEndPointDescEqual);
		endpointDescriptionsString.erase(last, endpointDescriptionsString.end());
		output->GetEndPoints(std::move(endpointDescriptionsString));
	}
}

void SoftingServerInteractor::ChooseCurrentEndPoint()
{
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	if(m_selectedEndPointDescription) {
		m_selectedEndPointDescription->clear();
	}
	m_selectedEndPointDescription.reset();
	if (m_pServerAttributes->configuration.serverName.empty()) {
		std::string message("Select sever!");
		if (output) {
			output->SendWarning(std::move(message));
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
		if (output) {
			output->SendMessageError(std::move(message));
		}
		return;
	}
	std::vector<tstring> discoveryUrls;
	discoveryUrls = serverList.at(0).getDiscoveryUrls();
	if (discoveryUrls.empty())
	{
		if (output) {
			std::string message("Invalid endpoint URL!");
			output->SendWarning(std::move(message));
		}
		return;
	}
	std::vector<SoftingOPCToolbox5::EndpointDescription> selectedUrlEndpointDescriptions;
	for (std::vector<std::string>::const_iterator itr = discoveryUrls.cbegin(); itr != discoveryUrls.cend(); itr++) {
		if (itr->length() > 0) {
			std::vector<tstring> transportProfileList;
			result = EnumStatusCode_Good;
			result = m_pApp->getEndpointsFromServer(*itr, transportProfileList, selectedUrlEndpointDescriptions);
			if (StatusCode::isBad(result))
			{
				selectedUrlEndpointDescriptions.clear();
				continue;
			}
			std::vector<SoftingOPCToolbox5::EndpointDescription>::const_iterator itrFound =
				std::find_if(selectedUrlEndpointDescriptions.cbegin(), selectedUrlEndpointDescriptions.cend(), std::bind(admitToAttributes, std::placeholders::_1, *m_pServerAttributes));
			if (itrFound != selectedUrlEndpointDescriptions.cend()) {
				m_selectedEndPointDescription = std::make_unique<SoftingOPCToolbox5::EndpointDescription>(SoftingOPCToolbox5::EndpointDescription(*itrFound));
				break;
			}
			else {
				selectedUrlEndpointDescriptions.clear();
				continue;
			}
		}
	}
	if (output) {
		if (selectedUrlEndpointDescriptions.empty()) {
			std::string message = std::string("Failed to get endpoint with given attributes");
			output->SendWarning(std::move(message));
		}
	}
}

void SoftingServerInteractor::TestConnection()
{
	OpenConnection();
	if (!m_sessionsList.empty()) {
		std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::const_iterator iter = m_sessionsList.cbegin();
		//BrowseSession(iter->first);
		CloseConnectionWithUUID(iter->first);
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			output->CloseConnectionWithGuide(std::string(iter->first));
		}
	}
}

void SoftingServerInteractor::BrowseSession(const std::string& connectionID)
{
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		if (iter->second.isNull() || iter->second->isConnected() == false)
		{
			if (output) {
				std::string message("The session is not connected... connect it before calling this function!");
				output->SendWarning(std::move(message));
			}
			return;
		}
		if (getNodeInfo(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder), iter->second) != EnumNodeClass_Variable) {
			nodeWalk(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder), iter->second);
		}
	}
	else {
		if (output) {
			std::string message("There is no any sessions with such ID!");
			output->SendWarning(std::move(message));
		}
	}
}

void SoftingServerInteractor::nodeWalk(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session)
{
	EnumStatusCode result = EnumStatusCode_Good;
	SoftingOPCToolbox5::BrowseDescription bd;	
	SoftingOPCToolbox5::ViewDescription vd;
	std::vector<SoftingOPCToolbox5::ReferenceDescription> refDescriptions;	// result array for function call.
	EnumResultMask resultMask = 0;
	SoftingOPCToolbox5::NodeId devicesNode;
	bd.setNodeId(nodeId);
	bd.setReferenceTypeId(SoftingOPCToolbox5::Statics::ReferenceTypeId_HierarchicalReferences);
	bd.setIncludeSubtypes(true);
	bd.setBrowseDirection(EnumBrowseDirection_Forward);
	bd.setNodeClassMask(EnumNodeClass_Node);
	resultMask = EnumResultMask_ReferenceType | EnumResultMask_DisplayName | EnumResultMask_TypeDefinition | EnumResultMask_NodeClass;
	bd.setResultMask(resultMask);

	result = session->browseNode(&vd, &bd, refDescriptions);
	if (StatusCode::isGood(result)) // the call itself succeeded
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			output->SendMessageInfo(std::move(message));
		}
		for (size_t i = 0; i < refDescriptions.size(); i++)
		{
			std::string name = refDescriptions[i].getDisplayName()->getText();
			EnumNodeClass nodeClass = refDescriptions[i].getNodeClass();
			devicesNode = refDescriptions[i].getNodeId();
			if (nodeClass == EnumNodeClass_Variable || nodeClass == EnumNodeClass_VariableType) {
				readNode(devicesNode, session);
			}
			else {
				nodeWalk(devicesNode, session);
			}
		}
	}
}

void SoftingServerInteractor::readNode(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session)
{
	EnumStatusCode result = EnumStatusCode_Good;
	std::vector<SoftingOPCToolbox5::ReadValueId> readIds;
	SoftingOPCToolbox5::ReadValueId rvid;
	rvid.setNodeId(nodeId);
	rvid.setAttributeId(EnumAttributeId_Value);
	readIds.push_back(rvid);
	std::vector<SoftingOPCToolbox5::DataValue> readResults;
	result = session->read(EnumTimestampsToReturn_Both, readIds, 0, readResults);
	if (StatusCode::isGood(result)) 
	{
		for (std::vector<SoftingOPCToolbox5::DataValue>::const_iterator itr = readResults.cbegin(); itr != readResults.cend(); ++itr) {
			if (StatusCode::isGood(itr->getStatusCode())) {
				EnumDataTypeId type = itr->getValue()->getDataType();
				std::string val = std::string(itr->getValue()->toString());
			}
		}
	}
	else {
		result = session->read(EnumTimestampsToReturn_Both, readIds, 200, readResults);
		if (StatusCode::isGood(result))
		{
			for (std::vector<SoftingOPCToolbox5::DataValue>::const_iterator itr = readResults.cbegin(); itr != readResults.cend(); ++itr) {
				if (StatusCode::isGood(itr->getStatusCode())) {
					EnumDataTypeId type = itr->getValue()->getDataType();
					std::string val = std::string(itr->getValue()->toString());
				}
			}
		}
	}
}

EnumNodeClass SoftingServerInteractor::getNodeInfo(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session)
{
	EnumStatusCode result = EnumStatusCode_Good;
	EnumNodeClass nodeClass = EnumNodeClass_Node;
	SoftingOPCToolbox5::BrowseDescription bd;	
	SoftingOPCToolbox5::ViewDescription vd;	
	std::vector<SoftingOPCToolbox5::ReferenceDescription> refDescriptions;
	EnumResultMask resultMask = 0;
	bd.setNodeId(nodeId);
	bd.setReferenceTypeId(SoftingOPCToolbox5::Statics::ReferenceTypeId_NonHierarchicalReferences);
	bd.setIncludeSubtypes(true);
	bd.setBrowseDirection(EnumBrowseDirection_Forward);
	bd.setNodeClassMask(EnumNodeClass_Node);
	resultMask = EnumResultMask_ReferenceType | EnumResultMask_DisplayName | EnumResultMask_TypeDefinition | EnumResultMask_NodeClass;
	bd.setResultMask(resultMask);
	result = session->browseNode(&vd, &bd, refDescriptions);
	if (StatusCode::isGood(result))
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			output->SendMessageInfo(std::move(message));
		}
		for (size_t i = 0; i < refDescriptions.size(); i++)
		{
			nodeClass = refDescriptions[i].getNodeClass();
		}
	}
	return nodeClass;
}

bool SoftingServerInteractor::findNode(SoftingOPCToolbox5::NodeId& nodeId, const std::vector<std::string>& fullPath, SoftingOPCToolbox5::Client::SessionPtr session)
{
	nodeId.clear();
	SoftingOPCToolbox5::NodeId originNodeId = SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder);
	for (std::vector<std::string>::const_iterator iter = fullPath.cbegin(); iter != fullPath.cend(); ++iter) {
		if (findNode(originNodeId, nodeId, *iter, session)){
			originNodeId.clear();
			originNodeId = nodeId;
		}
		else {
			return false;
		}
	}
	return true;
}


bool SoftingServerInteractor::findNode(const SoftingOPCToolbox5::NodeId& originNodeId, SoftingOPCToolbox5::NodeId& finalNodeId, const std::string& path, SoftingOPCToolbox5::Client::SessionPtr session)
{
	finalNodeId.clear();
	EnumStatusCode result = EnumStatusCode_Good;
	SoftingOPCToolbox5::BrowseDescription bd;
	SoftingOPCToolbox5::ViewDescription vd;
	std::vector<SoftingOPCToolbox5::ReferenceDescription> refDescriptions;	// result array for function call.
	EnumResultMask resultMask = 0;
	if (originNodeId.isNull()) {
		bd.setNodeId(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder));
	}
	else {
		bd.setNodeId(originNodeId);
	}
	//bd.setNodeId(originNodeId);
	bd.setReferenceTypeId(SoftingOPCToolbox5::Statics::ReferenceTypeId_HierarchicalReferences);
	bd.setIncludeSubtypes(true);
	bd.setBrowseDirection(EnumBrowseDirection_Forward);
	bd.setNodeClassMask(EnumNodeClass_Node);
	resultMask = EnumResultMask_ReferenceType | EnumResultMask_DisplayName | EnumResultMask_TypeDefinition | EnumResultMask_NodeClass;
	bd.setResultMask(resultMask);

	result = session->browseNode(&vd, &bd, refDescriptions);
	if (StatusCode::isGood(result)) 
	{
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			output->SendMessageInfo(std::move(message));
		}

		std::vector<SoftingOPCToolbox5::ReferenceDescription>::const_iterator findIterator =
			std::find_if(refDescriptions.cbegin(), refDescriptions.cend(), [&](const SoftingOPCToolbox5::ReferenceDescription& desc) {
			std::string name(desc.getDisplayName()->getText());
			return name == path; });
		if (findIterator != refDescriptions.cend()) {
			finalNodeId = findIterator->getNodeId();
			return true;
		}
		else {
			finalNodeId.clear();
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message = std::string("Can not find node with name ") + path;
				output->SendMessageInfo(std::move(message));
			}
			return false;
		}
	}
	return false;
}

void SoftingServerInteractor::getHistoricalValues(const std::vector<SoftingOPCToolbox5::NodeId>& nodesToRead, const SoftingOPCToolbox5::DateTime& startTime, const SoftingOPCToolbox5::DateTime& endTime,
	std::vector< std::vector<SoftingOPCToolbox5::DataValue> >& historicalValuesOfNodes, SoftingOPCToolbox5::Client::SessionPtr session)
{
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	
	std::vector<SoftingOPCToolbox5::NumericRange> indexRanges(nodesToRead.size(), SoftingOPCToolbox5::NumericRange());
	std::vector<SoftingOPCToolbox5::HistoryReadValueId> historyReadValueIds;
	std::transform(nodesToRead.cbegin(), nodesToRead.cend(), std::back_inserter(historyReadValueIds), [](const SoftingOPCToolbox5::NodeId& nodeId) {
		SoftingOPCToolbox5::HistoryReadValueId historyReadValueId;
		historyReadValueId.setNodeId(&nodeId);
		return historyReadValueId; });
	SoftingOPCToolbox5::ReadRawDetails readRawDetails;
	readRawDetails.setStartTime(&startTime);
	readRawDetails.setEndTime(&endTime);
	readRawDetails.setMaxNumberOfValuesPerNode(0);
	readRawDetails.setReturnBounds(true);
	std::vector<SoftingOPCToolbox5::HistoryReadDataResult> historyReadResults;
	EnumStatusCode result = EnumStatusCode_Bad;
	result = session->historyReadRaw(EnumTimestampsToReturn_Both, false, historyReadValueIds, &readRawDetails, historyReadResults);
	historicalValuesOfNodes.clear();
	if (StatusCode::isSUCCEEDED(result))
	{
		for (std::vector<SoftingOPCToolbox5::HistoryReadDataResult>::const_iterator itr = historyReadResults.cbegin(); itr != historyReadResults.cend(); ++itr) {
			EnumStatusCode operationResult = itr->getStatusCode();
			if (StatusCode::isBad(operationResult)) {
				if (output) {
					std::string message = std::string("Operation of the HistoryRead service call returned an unexpected status code ") + std::string(getEnumStatusCodeString(operationResult));
					output->SendMessageInfo(std::move(message));
				}
				return;
			}
			std::vector<SoftingOPCToolbox5::DataValue> values;
			OTUInt32 sizeOfData = itr->getNumberOfValues();
			for (OTUInt32 valueIndex = 0; valueIndex < sizeOfData; valueIndex++)
			{
				values.push_back(itr->getValue(valueIndex));
			}
			historicalValuesOfNodes.push_back(values);
		}
	}
	else {
		if (output) {
			std::string message = std::string("Can not find any values for nodes ");
			output->SendMessageInfo(std::move(message));
		}
	}
}

void SoftingServerInteractor::GetRecords(std::map<std::string, std::vector<DrvOPCUAHistValues::Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
	const std::map<std::string, std::vector<std::string> >& fullPaths, const std::string& connectionID)
{
	tagsData.clear();
	std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		if (iter->second.isNull() || iter->second->isConnected() == false)
		{
			if (output) {
				std::string message("The session is not connected... connect it before calling this function!");
				output->SendWarning(std::move(message));
			}
			return;
		}
		std::vector<SoftingOPCToolbox5::NodeId> nodesToRead;
		for (std::map<std::string, std::vector<std::string> >::const_iterator pathIterator = fullPaths.cbegin(); pathIterator != fullPaths.cend(); pathIterator++) {
			SoftingOPCToolbox5::NodeId foundedNode;
			if (findNode(foundedNode, pathIterator->second, iter->second)) {
				nodesToRead.push_back(foundedNode);
				foundedNode.clear();
			}
			else {
				if (output) {
					std::string message = std::string("There is no node for tag with name: ") + pathIterator->first;
					output->SendMessageError(std::move(message));
				}
				return;
			}
		}
		if (!nodesToRead.empty()) {
			FILETIME start;
			if (!SystemTimeToFileTime(&startTime, &start)) {
				if (output) {
					std::string message("Can not get start time!");
					output->SendWarning(std::move(message));
				}
				return;
			}
			SoftingOPCToolbox5::DateTime startTime;
			startTime.set(start);

			FILETIME end;
			if (!SystemTimeToFileTime(&endTime, &end)) {
				if (output) {
					std::string message("Can not get end time!");
					output->SendWarning(std::move(message));
				}
				return;
			}
			SoftingOPCToolbox5::DateTime endTime;
			endTime.set(end);
			std::vector< std::vector<SoftingOPCToolbox5::DataValue> > historicalValuesOfNodes;
			getHistoricalValues(nodesToRead,startTime,endTime, historicalValuesOfNodes,iter->second);
			if (historicalValuesOfNodes.empty()) {
				if (output) {
					std::string message("There is no any data for all tags!");
					output->SendWarning(std::move(message));
				}
				return;
			}
			if (fullPaths.size() != historicalValuesOfNodes.size()) {
				if (output) {
					std::string message("The number of nodes is not equal to number of historical values!");
					output->SendWarning(std::move(message));
				}
				return;
			}
			std::map<std::string, std::vector<std::string> >::const_iterator pathIterator = fullPaths.cbegin();
			for (std::vector< std::vector<SoftingOPCToolbox5::DataValue> >::const_iterator historyResultsIterator = historicalValuesOfNodes.cbegin(); historyResultsIterator != historicalValuesOfNodes.cend();
				++historyResultsIterator) {
				std::pair<std::string, std::vector<DrvOPCUAHistValues::Record> > pair = std::make_pair<std::string, std::vector<DrvOPCUAHistValues::Record> >(std::string(pathIterator->first), std::vector<DrvOPCUAHistValues::Record>{});
				std::transform(historyResultsIterator->cbegin(), historyResultsIterator->cend(), std::back_inserter(pair.second), mapRecordFromDataValue);
				++pathIterator;
				tagsData.insert(pair);
			}
		}
	}
	else {
		if (output) {
			std::string message("There is no any sessions with such ID!");
			output->SendWarning(std::move(message));
		}
	}
}

void SoftingServerInteractor::GetTags(std::vector<std::pair<std::string, bool> >& tags, std::queue<std::string>& receivedTags, const std::string& connectionID)
{
	tags.clear();
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		if (iter->second.isNull() || iter->second->isConnected() == false)
		{
			std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
			if (output) {
				std::string message("The session is not connected... connect it before calling this function!");
				output->SendWarning(std::move(message));
			}
			return;
		}
		SoftingOPCToolbox5::NodeId devicesNode;
		devicesNode.setNull();
		getTags(devicesNode, tags, receivedTags, iter->second);
	}
	else {
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message("There is no any sessions with such ID!");
			output->SendWarning(std::move(message));
		}
	}
}

void SoftingServerInteractor::getTags(SoftingOPCToolbox5::NodeId& nodeId, std::vector<std::pair<std::string, bool> >& tags, std::queue<std::string>& receivedTags, SoftingOPCToolbox5::Client::SessionPtr session)
{
	bool isFounded = false;
	EnumStatusCode result = EnumStatusCode_Good;
	SoftingOPCToolbox5::BrowseDescription bd;
	SoftingOPCToolbox5::ViewDescription vd;
	SoftingOPCToolbox5::NodeId devicesNode;
	std::vector<SoftingOPCToolbox5::ReferenceDescription> refDescriptions;
	EnumResultMask resultMask = 0;
	if (nodeId.isNull()) {
		bd.setNodeId(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder));
	}
	else {
		bd.setNodeId(nodeId);
	}
	bd.setReferenceTypeId(SoftingOPCToolbox5::Statics::ReferenceTypeId_HierarchicalReferences);
	bd.setIncludeSubtypes(true);
	bd.setBrowseDirection(EnumBrowseDirection_Forward);
	bd.setNodeClassMask(EnumNodeClass_Node);
	resultMask = EnumResultMask_ReferenceType | EnumResultMask_DisplayName | EnumResultMask_TypeDefinition | EnumResultMask_NodeClass;
	bd.setResultMask(resultMask);
	result = session->browseNode(&vd, &bd, refDescriptions);
	if (StatusCode::isGood(result)) {
		std::shared_ptr<SoftingServerInteractorOutput> output = m_pOutput.lock();
		if (output) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			output->SendMessageInfo(std::move(message));
		}
		std::string findingName;
		if (receivedTags.empty() == false) {
			findingName = receivedTags.front();
			receivedTags.pop();
		}
		if (findingName.empty()) {
			for (size_t i = 0; i < refDescriptions.size(); i++)
			{
				std::string name = refDescriptions[i].getDisplayName()->getText();
				EnumNodeClass nodeClass = refDescriptions[i].getNodeClass();
				std::pair<std::string, bool> pair;
				if (nodeClass == EnumNodeClass_Variable || nodeClass == EnumNodeClass_VariableType) {
					pair = std::make_pair<std::string, bool>(std::string(name), true);
				}
				else {
					pair = std::make_pair<std::string, bool>(std::string(name), false);
				}
				std::vector<std::pair<std::string, bool> >::const_iterator findIterator =
					std::find_if(tags.cbegin(), tags.cend(), [&](const std::pair<std::string, bool>& existingPair) {
					return (existingPair.first == pair.first) && (existingPair.second == pair.second); });
				if (findIterator == tags.cend()) {
					tags.push_back(pair);
				}
			}
		}
		else {
			std::vector<SoftingOPCToolbox5::ReferenceDescription>::const_iterator findIterator = 
				std::find_if(refDescriptions.cbegin(), refDescriptions.cend(), [&](const SoftingOPCToolbox5::ReferenceDescription& desc) {
				std::string name(desc.getDisplayName()->getText());
				return name == findingName; });
			if (findIterator != refDescriptions.cend()) {
				devicesNode = findIterator->getNodeId();
				getTags(devicesNode, tags, receivedTags, session);
			}
		}
	}
}

DrvOPCUAHistValues::SoftingServerEndPointDescription mapEndPointDescription(const SoftingOPCToolbox5::EndpointDescription& desc)
{
	std::string name(desc.getEndpointUrl());
	int mode = desc.getMessageSecurityMode();
	//std::string certificate = desc.getServerCertificate().toString();
	unsigned int tokenCount = desc.getUserIdentityTokenCount();
	std::string token;
	int type = 0;
	if (tokenCount > 0) {
		const SoftingOPCToolbox5::IUserTokenPolicy* pPolicy = desc.getUserIdentityToken(0);
		EnumUserTokenType identityToken = pPolicy->getTokenType();
		type = identityToken;
		//token = pPolicy->getPolicyId();
	}
	
	DrvOPCUAHistValues::SoftingServerEndPointDescription endPointDesc(name, mode, type);
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
	int mode = -1;
	EnumMessageSecurityMode descMode = desc.getMessageSecurityMode();
	switch (descMode)
	{
	case EnumMessageSecurityMode::EnumMessageSecurityMode_SignAndEncrypt:
		mode = 3;
		break;
	case EnumMessageSecurityMode::EnumMessageSecurityMode_Sign:
		mode = 2;
		break;
	case EnumMessageSecurityMode::EnumMessageSecurityMode_None:
		mode = 1;
		break;
	default:
		mode = -1;
		break;
	}
	if (mode < 0) {
		return false;
	}
	if (mode != DrvOPCUAHistValues::GetIntFromSecurityMode(attributes.configurationMode.securityMode)) {
		return false;
	}
	int type = 0;
	unsigned int tokenCount = desc.getUserIdentityTokenCount();
	if (tokenCount == 0) {
		return false;
	}
	const SoftingOPCToolbox5::IUserTokenPolicy* pPolicy = desc.getUserIdentityToken(0);
	EnumUserTokenType identityToken = pPolicy->getTokenType();
	switch (identityToken) {
	case EnumUserTokenType_Anonymous:
		type = 0;
		break;
	case EnumUserTokenType_UserName:
		type = 1;
		break;
	case EnumUserTokenType_Certificate:
		type = 2;
		break;
	case EnumUserTokenType_IssuedToken:
		type = 3;
		break;
	default:
		type = -1;
		break;
	}
	if (type != DrvOPCUAHistValues::GetIntFromSecurityType(attributes.configurationAccess.securityType)) {
		return false;
	}
	
	return true;
}

DrvOPCUAHistValues::Record mapRecordFromDataValue(const SoftingOPCToolbox5::DataValue& dataValue)
{
	DrvOPCUAHistValues::Record record;
	EnumDataTypeId type = dataValue.getValue()->getDataType();
	SYSTEMTIME serverDataTime = { 0 };
	serverDataTime.wYear = dataValue.getServerTimestamp()->yearGMT();
	serverDataTime.wMonth = dataValue.getServerTimestamp()->monthGMT();
	serverDataTime.wDay = dataValue.getServerTimestamp()->dayGMT();
	serverDataTime.wHour = dataValue.getServerTimestamp()->hourGMT();
	serverDataTime.wMinute = dataValue.getServerTimestamp()->minuteGMT();
	serverDataTime.wSecond = dataValue.getServerTimestamp()->secondGMT();
	serverDataTime.wMilliseconds = dataValue.getServerTimestamp()->milliSecondGMT();
	char* strPtr = reinterpret_cast<char*>(&serverDataTime);
	record.insert(OPC_UA_SERVER_TIMESTAMP, EnumNumericNodeId_DateTime, std::string(strPtr,sizeof(SYSTEMTIME)));
	/*SYSTEMTIME clientDataTime = { 0 };
	clientDataTime.wYear = dataValue.getSourceTimestamp()->yearGMT();
	clientDataTime.wMonth = dataValue.getSourceTimestamp()->monthGMT();
	clientDataTime.wDay = dataValue.getSourceTimestamp()->dayGMT();
	clientDataTime.wHour = dataValue.getSourceTimestamp()->hourGMT();
	clientDataTime.wMinute = dataValue.getSourceTimestamp()->minuteGMT();
	clientDataTime.wSecond = dataValue.getSourceTimestamp()->secondGMT();
	clientDataTime.wMilliseconds = dataValue.getSourceTimestamp()->milliSecondGMT();
	strPtr = reinterpret_cast<char*>(&clientDataTime);
	record.insert(OPC_UA_CLIENT_TIMESTAMP, EnumNumericNodeId_DateTime, std::string(strPtr, sizeof(SYSTEMTIME)));*/
	std::string valueStr;
	switch (type) {
	case EnumNumericNodeId_Null:
		valueStr.clear();
		break;
	case EnumNumericNodeId_Boolean:
	{
		OTBoolean boolVal = dataValue.getValue()->getBoolean();
		if (boolVal) {
			valueStr = std::to_string(1);
		}
		else {
			valueStr = std::to_string(0);
		}
	}
		break;
	case EnumNumericNodeId_SByte:
	{
		char intVal = dataValue.getValue()->getInt8();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_Int16:
	{
		short intVal = dataValue.getValue()->getInt16();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_Int32:
	{
		valueStr = dataValue.getValue()->toString();
		int intVal = dataValue.getValue()->getInt32();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_Int64:
	{
		long long longVal = dataValue.getValue()->getInt64();
		valueStr = std::to_string(longVal);
	}
	break;
	case EnumNumericNodeId_Byte:
	{
		unsigned char intVal = dataValue.getValue()->getUInt8();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_UInt16:
	{
		unsigned short intVal = dataValue.getValue()->getUInt16();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_UInt32:
	{
		valueStr = dataValue.getValue()->toString();
		unsigned int intVal = dataValue.getValue()->getUInt32();
		valueStr = std::to_string(intVal);
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		unsigned long long longVal = dataValue.getValue()->getUInt64();
		valueStr = std::to_string(longVal);
	}
	break;
	case EnumNumericNodeId_Double:
	{
		double doubleVale = dataValue.getValue()->getDouble();
		valueStr = std::to_string(doubleVale);
	}
	break;
	case EnumNumericNodeId_Float:
	{
		float floatVale = dataValue.getValue()->getFloat();
		valueStr = std::to_string(floatVale);
	}
	break;
	default:
		valueStr = dataValue.getValue()->toString();
		break;
	}
	record.insert(OPC_UA_VALUE, type, valueStr);

	return record;
}