#pragma once
#include<IBrowserItem.h>
#include<BrowseItem.h>
#include<OdsString.h>
#include<vector>
#include"ConnectionAttributes.h"

struct STagItem
{
	std::vector<ODS::OdsString> m_vAddress;
	ODS::OdsString m_szDescription;
	int m_nType;

	STagItem()
	{
		m_nType = ODS::BrowseItem::TYPE_ITEM;
	}
};

class BrowserHdaItem : public ODS::IBrowserItem
{
public:
	BrowserHdaItem();
	void* GetInterface(int nIfcId) override;
	int Init(TCHAR* szCfgString) override;
	int Shut() override;
	int GetBrowseItemList(const ODS::ItemAddress* pAddress, ODS::BrowseItem** ppList, ULONG* pulCount) override;
	int DestroyBrowseItemList(ODS::BrowseItem* pList, ULONG ulCount) override;
private:
	DrvOPCUAHistValues::ConnectionAttributes m_attributes;
	std::vector<STagItem> m_TagList;
	int GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList);
	ODS::OdsString GetAddressOld(const ODS::ItemAddress& rAddress);
};