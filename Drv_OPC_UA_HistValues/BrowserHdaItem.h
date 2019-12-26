#pragma once
#include<IBrowserItem.h>
#include<BrowseItem.h>
#include<OdsString.h>
#include<vector>
#include"ConnectionAttributes.h"
#include"SoftingServerInteractorOutput.h"
#include"SoftingServerInteractor.h"

namespace DrvOPCUAHistValues
{
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

	class BrowserHdaItem : public ODS::IBrowserItem, public SoftingServerInteractorOutput
	{
	public:
		BrowserHdaItem();
		void* GetInterface(int nIfcId) override;
		int Init(TCHAR* szCfgString) override;
		int Shut() override;
		int GetBrowseItemList(const ODS::ItemAddress* pAddress, ODS::BrowseItem** ppList, ULONG* pulCount) override;
		int DestroyBrowseItemList(ODS::BrowseItem* pList, ULONG ulCount) override;
		void SendMessageError(std::string&& message) override;
		void SendWarning(std::string&& message) override;
		void SendMessageInfo(std::string&& message) override;
		void GetServers(std::vector<std::string>&& servers) override;
		void GetEndPoints(std::vector<SoftingServerEndPointDescription>&& servers) override;
		void GetNewConnectionGuide(std::string&& uuid) override;
	private:
		std::shared_ptr<ConnectionAttributes> m_pAttributes;
		std::unique_ptr<SoftingServerInteractor> m_pSoftingInteractor;
		std::vector<STagItem> m_TagList;
		std::string m_ConnectionId;
		int GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList);
		ODS::OdsString GetAddressOld(const ODS::ItemAddress& rAddress);
	};
}

