#include "pch.h"
#include"Constants.h"
#include"BrowserHdaItem.h"
#include <OdsErr.h>
#include <AddressComponent.h>
#include <Address.h>
#include"XMLSettingsDataSource.h"
#include"Log.h"

DrvOPCUAHistValues::BrowserHdaItem::BrowserHdaItem() :m_pAttributes(nullptr), m_pSoftingInteractor(nullptr), m_TagList(), m_ConnectionId()
{
	
}

void* DrvOPCUAHistValues::BrowserHdaItem::GetInterface(int nIfcId)
{
	return this;
}

int DrvOPCUAHistValues::BrowserHdaItem::Init(TCHAR* szCfgString)
{
	DrvOPCUAHistValues::XMLSettingsDataSource settingSource;

	if (szCfgString != NULL)
	{
		size_t len = _tcslen(szCfgString);
		if (len > 0) {
			m_pAttributes = std::make_shared<ConnectionAttributes>();
			m_pSoftingInteractor = std::make_unique<SoftingServerInteractor>(this, m_pAttributes);
			settingSource.LoadAttributesString(szCfgString, len, *m_pAttributes);
		}
	}

	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::BrowserHdaItem::Shut()
{
	return ODS::ERR::OK;
}

ODS::OdsString DrvOPCUAHistValues::BrowserHdaItem::GetAddressOld(const ODS::ItemAddress& rAddress)
{
	ODS::AddressComponent* addrComp = nullptr;
	int nCount = 0;
	int nIndex = 0;
	rAddress.GetAddress(&addrComp, &nCount, &nIndex);
	if (addrComp != nullptr) {
		for (int ind = 0; ind < nCount; ++ind) {
			TCHAR* name = nullptr;
			addrComp[ind].GetValue(&name);
			if (name != nullptr) {
				ODS::OdsString strName = ODS::OdsString(name);
				addrComp[ind].DestroyString(name);
				if (strName == _T("address_old")) {
					TCHAR* address = nullptr;
					if (address != nullptr) {
						ODS::OdsString strAddress = ODS::OdsString(address);
						addrComp[ind].DestroyString(address);
						rAddress.DestroyAddress(addrComp, nCount);
						return strAddress;
					}
				}
			}
		}
		rAddress.DestroyAddress(addrComp, nCount);
	}
	return _T("");
}


int DrvOPCUAHistValues::BrowserHdaItem::GetBrowseItemList(const ODS::ItemAddress* pAddress, ODS::BrowseItem** ppList, ULONG* pulCount)
{
	int iRes = ODS::ERR::OK;

	if (ppList && pulCount)
	{
		std::vector<STagItem> tagList;

		int nCount = 0;
		ODS::AddressComponent* pAddrComponent = NULL;
		std::vector<ODS::OdsString> entry;

		if (pAddress)
		{
			TCHAR* szName = NULL;
			TCHAR* szValue = NULL;
			int nIndex = 0;

			ODS::ItemAddress addr;

			ODS::ItemAddress* pAddr = (ODS::ItemAddress*)pAddress;

			ODS::OdsString addressOld = GetAddressOld(*pAddress);
			if (!addressOld.IsEmpty())
			{
				addr.SetPlainAddress((LPCTSTR)addressOld);
				pAddr = &addr;
			}

			pAddr->GetAddress(&pAddrComponent, &nCount, &nIndex);

			for (int ind = 0; ind < nCount; ind++)
			{
				pAddrComponent[ind].GetName(&szName);
				pAddrComponent[ind].GetValue(&szValue);

				if (szValue && szValue[0])
					entry.push_back(szValue);

				pAddrComponent[ind].DestroyString(szName);
				pAddrComponent[ind].DestroyString(szValue);
			}
			pAddr->DestroyAddress(pAddrComponent, nCount);
		}

		iRes = GetTagList(entry, &tagList);
		if (iRes != ODS::ERR::OK)
			return iRes;

		*pulCount = tagList.size();

		if (*pulCount)
		{
			*ppList = new ODS::BrowseItem[*pulCount];
			if (*ppList)
			{
				for (UINT ind = 0; ind < tagList.size(); ind++)
				{
					ODS::BrowseItem* pItem = *ppList + ind;

					ODS::ItemAddress addr;
					UINT uiComponentCount = tagList[ind].m_vAddress.size();
					ODS::AddressComponent* pAddrComponent = new ODS::AddressComponent[uiComponentCount];

					if (pAddrComponent)
					{
						for (UINT i = 0; i < uiComponentCount; i++)
						{
							pAddrComponent[i].SetName((LPCTSTR)tagList[ind].m_vAddress[i]);

							pAddrComponent[i].SetValue((LPCTSTR)tagList[ind].m_vAddress[i]);
						}

						addr.SetAddress(pAddrComponent, uiComponentCount, 0);

						delete[] pAddrComponent;
					}

					pItem->SetName((LPCTSTR)tagList[ind].m_vAddress[tagList[ind].m_vAddress.size() - 1]);
					pItem->SetAddress(addr);
					pItem->SetDescription((LPCTSTR)tagList[ind].m_szDescription);

					pItem->SetHierarchyType(tagList[ind].m_nType);
				}
			}
		}
	}
	else
	{
		iRes = ODS::ERR::BAD_PARAM;
	}

	return iRes;
}

int DrvOPCUAHistValues::BrowserHdaItem::DestroyBrowseItemList(ODS::BrowseItem* pList, ULONG ulCount)
{
	if (pList)
	{
		delete[] pList;
	}
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::BrowserHdaItem::GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList)
{
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
		sItem.m_vAddress.assign(rEntry.cbegin(),rEntry.cend());
		sItem.m_vAddress.push_back(szAddress);
		if (itr->second == false) {
			sItem.m_nType = ODS::BrowseItem::TYPE_BRANCH;
		}
		pTagList->push_back(sItem);
	}
	m_pSoftingInteractor->CloseConnectionWithUUID(m_ConnectionId);
	
	return ODS::ERR::OK;
}


void DrvOPCUAHistValues::BrowserHdaItem::SendMessageError(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHdaItem::SendWarning(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHdaItem::SendMessageInfo(std::string&& message)
{
	Log::GetInstance()->WriteInfo(_T(message.c_str()));
}

void DrvOPCUAHistValues::BrowserHdaItem::GetServers(std::vector<std::string>&& servers)
{

}

void DrvOPCUAHistValues::BrowserHdaItem::GetEndPoints(std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>&& servers)
{

}

void DrvOPCUAHistValues::BrowserHdaItem::GetNewConnectionGuide(std::string&& uuid)
{
	m_ConnectionId = uuid;
}