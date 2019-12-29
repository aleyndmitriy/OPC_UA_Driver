#include "pch.h"
#include"Constants.h"
#include"BrowserHdaItem.h"
#include <OdsErr.h>
#include <AddressComponent.h>
#include <Address.h>
#include"XMLSettingsDataSource.h"
#include"Log.h"

DrvOPCUAHistValues::BrowserHdaItem::BrowserHdaItem(std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<SoftingServerInteractor> softingDataStore):
	m_pAttributes(nullptr), m_settingsDataStore(settingsDataStore), m_pBrowserHandler(std::make_shared<HdaBrowserHandler>(softingDataStore))
{
	
}

void* DrvOPCUAHistValues::BrowserHdaItem::GetInterface(int nIfcId)
{
	return this;
}

int DrvOPCUAHistValues::BrowserHdaItem::Init(TCHAR* szCfgString)
{
	if (szCfgString != NULL)
	{
		size_t len = _tcslen(szCfgString);
		if (len > 0) {
			m_pAttributes = std::make_shared<ConnectionAttributes>();
			m_settingsDataStore->LoadAttributesString(szCfgString, len, *m_pAttributes);
			m_pBrowserHandler->Init(m_pAttributes);
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

		iRes = m_pBrowserHandler->GetTagList(entry, &tagList);
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

