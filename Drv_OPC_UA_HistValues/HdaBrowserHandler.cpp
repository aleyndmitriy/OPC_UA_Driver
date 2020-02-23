#include"pch.h"
#include"HdaBrowserHandler.h"
#include"Constants.h"
#include"Log.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>
#include"Utils.h"

DrvOPCUAHistValues::BrowserHandler::BrowserHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore) : m_pAttributes(nullptr), m_pSoftingInteractor(softingDataStore), m_ConnectionId()
{

}

DrvOPCUAHistValues::BrowserHandler::~BrowserHandler()
{
	if (!m_ConnectionId.empty()) {
		m_pSoftingInteractor->CloseConnectionWithUUID(m_ConnectionId);
	}
}

int DrvOPCUAHistValues::BrowserHandler::Init(std::shared_ptr<ConnectionAttributes> attributes)
{
	m_pAttributes = attributes;
	m_pSoftingInteractor->SetAttributes(attributes);
	
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::BrowserHandler::GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList)
{
	m_pSoftingInteractor->SetOutput(shared_from_this());
	pTagList->clear();
	if (m_ConnectionId.empty()) {
		m_pSoftingInteractor->OpenConnection();
	}
	if (m_ConnectionId.empty()) {
		return ODS::ERR::DB_CONNECTION_FAILED;
	}
	std::vector<TagInfo> tagsName;
	std::queue<std::string> pathQueue;
	std::vector<std::string> vec;
	if (rEntry.size() == 1) {
		std::string name(rEntry.at(0).GetString());
		vec = split(name, std::string("/"));
		for (std::vector<std::string>::const_iterator iterSplit = vec.cbegin(); iterSplit != vec.cend(); ++iterSplit)
		{
			pathQueue.push(*iterSplit);
		}
	}
	else {
		for (std::vector<ODS::OdsString>::const_iterator iter = rEntry.cbegin(); iter != rEntry.cend(); ++iter) {
			std::string name(iter->GetString());
			pathQueue.push(name);
		}
	}
	
	m_pSoftingInteractor->GetTags(tagsName, pathQueue, m_ConnectionId);
	for (std::vector<TagInfo>::const_iterator itr = tagsName.cbegin(); itr != tagsName.cend(); ++itr) {
		ODS::OdsString szAddress(itr->m_strName.c_str());
		STagItem sItem;
		if (rEntry.size() == 1) {
			std::transform(vec.cbegin(), vec.cend(), std::back_inserter(sItem.m_vAddress), [](const std::string& path) {
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

void DrvOPCUAHistValues::BrowserHandler::GetServers(std::vector<std::string>&& servers)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers)
{

}

void DrvOPCUAHistValues::BrowserHandler::GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds)
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