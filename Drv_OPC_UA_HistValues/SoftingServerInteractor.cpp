#include"pch.h"
#include"SoftingServerInteractor.h"
#include"Utils.h"
#include"Constants.h"
#include<algorithm>
#include<functional>
#include <UserIdentityToken.h>
#include <Statics.h>
SoftingServerInteractor::SoftingServerInteractor(SoftingServerInteractorOutput* output, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes):
m_pOutput(output), m_pServerAttributes(attributes), m_pApp(), m_AppDesc(), m_enumResult(), m_selectedEndPointDescription(nullptr), m_sessionsList()
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
		m_AppDesc.clear();
		if (m_selectedEndPointDescription) {
			m_selectedEndPointDescription->clear();
		}
		
		m_enumResult = m_pApp->uninitialize();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("An error occurred while uninitializing the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			if (m_pOutput) {
				m_pOutput->SendMessageError(std::move(message));
			}
		}
		
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

void SoftingServerInteractor::OpenConnection()
{
	GUID guid;
	if (CoCreateGuid(&guid) != S_OK) {
		if (m_pOutput) {
			std::string message("Can not create Guide!");
			m_pOutput->SendMessageError(std::move(message));
			m_pOutput->GetNewConnectionGuide(std::string());
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
	if (connectionID.empty()) {
		return;
	}
	if (!m_selectedEndPointDescription) {
		if (m_pOutput) {
			std::string message("Server is not configured!");
			m_pOutput->SendMessageError(std::move(message));
			m_pOutput->GetNewConnectionGuide(std::string());
		}
		ChooseCurrentEndPoint();
	}
	EnumStatusCode result = EnumStatusCode_Good;
	std::string endpointUrl = m_selectedEndPointDescription->getEndpointUrl();
	if (endpointUrl.length() <= 0)
	{
		if (m_pOutput) {
			std::string message("Invalid endpoint URL!");
			m_pOutput->SendMessageError(std::move(message));
			m_pOutput->GetNewConnectionGuide(std::string());
		}
	}
	SoftingOPCToolbox5::Client::SessionPtr session = SoftingOPCToolbox5::Client::Session::create();

	result = session->setUrl(endpointUrl);
	if (StatusCode::isBad(result))
	{
		if (m_pOutput) {
			std::string message = std::string("Set URL to the session failed: ") + std::string(getEnumStatusCodeString(result));
			m_pOutput->SendMessageError(std::move(message));
			m_pOutput->GetNewConnectionGuide(std::string());
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
		session->setUserSecurityPolicy(m_selectedEndPointDescription->getUserIdentityToken(0)->getSecurityPolicyUri());
		session->setUserIdentityToken(&userIdentityToken);
		result = m_pApp->addSession(session);
		if (StatusCode::isBad(result))
		{
			if (m_pOutput) {
				std::string message = std::string("Adding session failed: ") + std::string(getEnumStatusCodeString(result));
				m_pOutput->SendMessageError(std::move(message));
				m_pOutput->GetNewConnectionGuide(std::string());
			}
			return;
		}
		if (StatusCode::isGood(result))
		{
			result = session->connect(false);
			if (StatusCode::isBad(result))
			{
				if (m_pOutput) {
					std::string message = std::string("Connecting to the server failed: ") + std::string(getEnumStatusCodeString(result));
					m_pOutput->SendMessageError(std::move(message));
					m_pOutput->GetNewConnectionGuide(std::string());
				}
				return;
			}
			if (StatusCode::isGood(result))
			{
				std::pair<std::string, SoftingOPCToolbox5::Client::SessionPtr> pair =
					std::make_pair<std::string, SoftingOPCToolbox5::Client::SessionPtr>(std::string(connectionID), SoftingOPCToolbox5::Client::SessionPtr(session));
				m_sessionsList.insert(pair);
				if (m_pOutput) {
					m_pOutput->GetNewConnectionGuide(std::string(connectionID));
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
			if (m_pOutput) {
				std::string message = std::string("Can not disconnect session: ") + std::string(getEnumStatusCodeString(result));
				m_pOutput->SendMessageError(std::move(message));
				m_pOutput->GetNewConnectionGuide(std::string());
			}
		}
		m_pApp->removeSession(iter->second);
		if (StatusCode::isBad(result))
		{
			if (m_pOutput) {
				std::string message = std::string("Can not remove session: ") + std::string(getEnumStatusCodeString(result));
				m_pOutput->SendMessageError(std::move(message));
				m_pOutput->GetNewConnectionGuide(std::string());
			}
		}
		iter->second.reset();
		m_sessionsList.erase(iter);
	}
}

void SoftingServerInteractor::GetServers()
{
	std::vector<std::string> vec;
	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (m_pOutput) {
			std::string message("Computer name is empty!");
			m_pOutput->SendWarning(std::move(message));
			m_pOutput->GetServers(std::move(vec));
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
			m_pOutput->GetServers(std::move(vec));
		}
		return;
	}
	
	std::transform(serversList.cbegin(), serversList.cend(), std::back_inserter(vec), [](const SoftingOPCToolbox5::ApplicationDescription& desc) {
		std::string name(desc.getApplicationUri());
		::Sleep(1000);
		return name; });

	if (m_pOutput) {
		m_pOutput->GetServers(std::move(vec));
	}
}

void SoftingServerInteractor::ChooseCurrentServer() {

	std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription> endpointDescriptionsString;
	if (m_pServerAttributes->configuration.computerName.empty()) {
		if (m_pOutput) {
			std::string message("Computer name is empty!");
			m_pOutput->SendWarning(std::move(message));
			m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
		}
		return;
	}
	if (m_pServerAttributes->configuration.serverName.empty()) {
		std::string message("Select sever!");
		if (m_pOutput) {
			m_pOutput->SendWarning(std::move(message));
			m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
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
		std::string message = std::string("Finding registered severs failed: ") + std::string(getEnumStatusCodeString(m_enumResult));
		if (m_pOutput) {
			m_pOutput->SendMessageError(std::move(message));
			m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
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
			m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
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
					m_pOutput->GetEndPoints(std::move(endpointDescriptionsString));
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
	if(m_selectedEndPointDescription) {
		m_selectedEndPointDescription->clear();
	}
	m_selectedEndPointDescription.reset();
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
			m_selectedEndPointDescription = std::make_unique<SoftingOPCToolbox5::EndpointDescription>(SoftingOPCToolbox5::EndpointDescription(*itrFound));
			break;
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
	}
}

void SoftingServerInteractor::BrowseSession(const std::string& connectionID)
{
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		if (iter->second.isNull() || iter->second->isConnected() == false)
		{
			if (m_pOutput) {
				std::string message("The session is not connected... connect it before calling this function!");
				m_pOutput->SendWarning(std::move(message));
			}
			return;
		}
		if (getNodeInfo(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder), iter->second) != EnumNodeClass_Variable) {
			nodeWalk(SoftingOPCToolbox5::NodeId(EnumNumericNodeId_RootFolder), iter->second);
		}
	}
	else {
		if (m_pOutput) {
			std::string message("There is no any sessions with such ID!");
			m_pOutput->SendWarning(std::move(message));
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
		if (m_pOutput) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			m_pOutput->SendMessageInfo(std::move(message));
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
		if (m_pOutput) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			m_pOutput->SendMessageInfo(std::move(message));
		}
		for (size_t i = 0; i < refDescriptions.size(); i++)
		{
			nodeClass = refDescriptions[i].getNodeClass();
			Sleep(1000);
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
	bd.setNodeId(originNodeId);
	bd.setReferenceTypeId(SoftingOPCToolbox5::Statics::ReferenceTypeId_HierarchicalReferences);
	bd.setIncludeSubtypes(true);
	bd.setBrowseDirection(EnumBrowseDirection_Forward);
	bd.setNodeClassMask(EnumNodeClass_Node);
	resultMask = EnumResultMask_ReferenceType | EnumResultMask_DisplayName | EnumResultMask_TypeDefinition | EnumResultMask_NodeClass;
	bd.setResultMask(resultMask);

	result = session->browseNode(&vd, &bd, refDescriptions);
	if (StatusCode::isGood(result)) 
	{
		if (m_pOutput) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			m_pOutput->SendMessageInfo(std::move(message));
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
			if (m_pOutput) {
				std::string message = std::string("Can not find node with name ") + path;
				m_pOutput->SendMessageInfo(std::move(message));
			}
			return false;
		}
	}
	return false;
}

void SoftingServerInteractor::GetTags(std::vector<std::pair<std::string, bool> >& tags, std::queue<std::string>& receivedTags, const std::string& connectionID)
{
	tags.clear();
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr>::iterator iter = m_sessionsList.find(connectionID);
	if (iter != m_sessionsList.end()) {
		if (iter->second.isNull() || iter->second->isConnected() == false)
		{
			if (m_pOutput) {
				std::string message("The session is not connected... connect it before calling this function!");
				m_pOutput->SendWarning(std::move(message));
			}
			return;
		}
		SoftingOPCToolbox5::NodeId devicesNode;
		devicesNode.setNull();
		getTags(devicesNode, tags, receivedTags, iter->second);
	}
	else {
		if (m_pOutput) {
			std::string message("There is no any sessions with such ID!");
			m_pOutput->SendWarning(std::move(message));
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
		if (m_pOutput) {
			std::string message = std::string("Number of references: ") + std::to_string(refDescriptions.size());
			m_pOutput->SendMessageInfo(std::move(message));
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
	std::string certificate = desc.getServerCertificate().toString();
	unsigned int tokenCount = desc.getUserIdentityTokenCount();
	std::string token;
	int type = 0;
	if (tokenCount > 0) {
		const SoftingOPCToolbox5::IUserTokenPolicy* pPolicy = desc.getUserIdentityToken(0);
		EnumUserTokenType identityToken = pPolicy->getTokenType();
		type = identityToken;
		//token = pPolicy->getPolicyId();
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