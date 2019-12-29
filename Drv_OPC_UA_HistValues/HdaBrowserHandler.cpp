#include"pch.h"
#include"HdaBrowserHandler.h"
#include"Constants.h"
#include"Log.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>

DrvOPCUAHistValues::HdaBrowserHandler::HdaBrowserHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore) : m_pAttributes(nullptr), m_pSoftingInteractor(softingDataStore), m_ConnectionId()
{

}

DrvOPCUAHistValues::HdaBrowserHandler::~HdaBrowserHandler()
{

}

int DrvOPCUAHistValues::HdaBrowserHandler::Init(std::shared_ptr<ConnectionAttributes> attributes)
{
	m_pAttributes = attributes;
	m_pSoftingInteractor->SetAttributes(attributes);
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::HdaBrowserHandler::GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList)
{
	m_pSoftingInteractor->SetOutput(shared_from_this());
	pTagList->clear();
	m_pSoftingInteractor->OpenConnection();
	if (m_ConnectionId.empty()) {
		return ODS::ERR::DB_CONNECTION_FAILED;
	}
	std::vector<std::pair<std::string, bool> > tagsName;
	std::queue<std::string> pathQueue;
	for (std::vector<ODS::OdsString>::const_iterator iter = rEntry.cbegin(); iter != rEntry.cend(); ++iter) {
		std::string name(iter->GetString());
		pathQueue.push(name);
	}
	m_pSoftingInteractor->GetTags(tagsName, pathQueue, m_ConnectionId);

	for (std::vector<std::pair<std::string, bool> >::const_iterator itr = tagsName.cbegin(); itr != tagsName.cend(); ++itr) {
		ODS::OdsString szAddress(itr->first.c_str());
		STagItem sItem;
		sItem.m_vAddress.assign(rEntry.cbegin(), rEntry.cend());
		sItem.m_vAddress.push_back(szAddress);
		if (itr->second == false) {
			sItem.m_nType = ODS::BrowseItem::TYPE_BRANCH;
		}
		pTagList->push_back(sItem);
	}
	m_pSoftingInteractor->CloseConnectionWithUUID(m_ConnectionId);

	return ODS::ERR::OK;
}


void DrvOPCUAHistValues::HdaBrowserHandler::SendMessageError(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::HdaBrowserHandler::SendWarning(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::HdaBrowserHandler::SendMessageInfo(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::HdaBrowserHandler::GetServers(std::vector<std::string>&& servers)
{

}

void DrvOPCUAHistValues::HdaBrowserHandler::GetEndPoints(std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>&& servers)
{

}

void DrvOPCUAHistValues::HdaBrowserHandler::GetNewConnectionGuide(std::string&& uuid)
{
	m_ConnectionId = uuid;
}

void DrvOPCUAHistValues::HdaBrowserHandler::CloseConnectionWithGuide(std::string&& uuid)
{
	m_ConnectionId.clear();
}