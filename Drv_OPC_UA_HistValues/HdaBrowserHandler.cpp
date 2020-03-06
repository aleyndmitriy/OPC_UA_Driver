#include"pch.h"
#include"HdaBrowserHandler.h"
#include"Constants.h"
#include"Log.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>
#include<algorithm>
#include"Utils.h"

DrvOPCUAHistValues::BrowserHandler::BrowserHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore) : m_pAttributes(nullptr), m_pSoftingInteractor(softingDataStore), m_ConnectionId()
{

}

DrvOPCUAHistValues::BrowserHandler::~BrowserHandler()
{
	if (!m_ConnectionId.empty()) {
		std::string connectionId(m_ConnectionId);
		m_pSoftingInteractor->CloseConnectionWithUUID(connectionId);
		Log::GetInstance()->WriteInfo(_T("Close connection with session id %s !"), (LPCTSTR)connectionId.c_str());
	}
}

int DrvOPCUAHistValues::BrowserHandler::Init(std::shared_ptr<ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes)
{
	m_pAttributes = attributes;
	m_pDataAttributes = dataAttributes;
	m_pSoftingInteractor->SetAttributes(attributes);
	m_pSoftingInteractor->SetDataAttributes(dataAttributes);
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::BrowserHandler::GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList)
{
	m_pSoftingInteractor->SetOutput(shared_from_this());
	pTagList->clear();
	if (m_ConnectionId.empty()) {
		m_pSoftingInteractor->OpenConnection();
		if (m_ConnectionId.empty()) {
			Log::GetInstance()->WriteInfo(_T("Can't open connection!"));
			return ODS::ERR::DB_CONNECTION_FAILED;
		}
		Log::GetInstance()->WriteInfo(_T("Open connection with session id %s !"), (LPCTSTR)m_ConnectionId.c_str());
	}
	std::set<TagInfo> tagsName;
	std::vector<std::string> vec;
	std::vector<std::string> splitVec;
	if (rEntry.size() == 1) {
		std::string name(rEntry.at(0).GetString());
		splitVec = split(name, std::string("/"));
		std::transform(splitVec.cbegin(), splitVec.cend(), std::back_inserter(vec), [](const std::string& path) {
			return path;
			});
	}
	else {
		std::transform(rEntry.cbegin(), rEntry.cend(), std::back_inserter(vec), [](const ODS::OdsString& path) {
			std::string name(path.GetString());
			return name;
			});
	}
	
	m_pSoftingInteractor->GetTags(tagsName, vec, m_ConnectionId);
	for (std::set<TagInfo>::const_iterator itr = tagsName.cbegin(); itr != tagsName.cend(); ++itr) {
		ODS::OdsString szAddress(itr->m_strName.c_str());
		STagItem sItem;
		if (rEntry.size() == 1) {
			std::transform(splitVec.cbegin(), splitVec.cend(), std::back_inserter(sItem.m_vAddress), [](const std::string& path) {
			return ODS::OdsString(path.c_str()); });
		}
		else {
			sItem.m_vAddress.assign(rEntry.cbegin(), rEntry.cend());
		}
		
		sItem.m_vAddress.push_back(szAddress);
		sItem.m_szDescription = ODS::OdsString(itr->m_strDescription.c_str());
		sItem.m_nType = itr->m_iType;
		pTagList->push_back(sItem);
	}
	return ODS::ERR::OK;
}


void DrvOPCUAHistValues::BrowserHandler::SendMessageError(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHandler::SendWarning(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHandler::SendMessageInfo(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHandler::GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetAggregates(std::vector<std::pair<std::string, int> >&& aggregates)
{

}


void DrvOPCUAHistValues::BrowserHandler::SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetNewConnectionGuide(std::string&& uuid)
{
	m_ConnectionId = uuid;
}

void DrvOPCUAHistValues::BrowserHandler::CloseConnectionWithGuide(std::string&& uuid)
{
	m_ConnectionId.clear();
}

DrvOPCUAHistValues::STagItem DrvOPCUAHistValues::mapFromHierarchicalTagInfo(const HierarchicalTagInfo& tag)
{
	STagItem item;
	item.m_szDescription = ODS::OdsString(tag.m_strDescription.c_str());
	item.m_nType = tag.m_iType;
	std::transform(tag.m_strAddress.cbegin(), tag.m_strAddress.cend(), std::back_inserter(item.m_vAddress), [](const std::string& addr) {
		ODS::OdsString odsAddr(addr.c_str());
		return odsAddr; });
	return item;
}