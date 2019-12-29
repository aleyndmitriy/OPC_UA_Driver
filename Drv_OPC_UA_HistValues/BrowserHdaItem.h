#pragma once
#include"HdaBrowserHandler.h"
#include"ISettingsDataSource.h"

namespace DrvOPCUAHistValues
{
	class BrowserHdaItem : public ODS::IBrowserItem
	{
	public:
		BrowserHdaItem(std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<SoftingServerInteractor> softingDataStore);
		BrowserHdaItem() = delete;
		void* GetInterface(int nIfcId) override;
		int Init(TCHAR* szCfgString) override;
		int Shut() override;
		int GetBrowseItemList(const ODS::ItemAddress* pAddress, ODS::BrowseItem** ppList, ULONG* pulCount) override;
		int DestroyBrowseItemList(ODS::BrowseItem* pList, ULONG ulCount) override;
		
	private:
		std::shared_ptr<ConnectionAttributes> m_pAttributes;
		std::shared_ptr<ISettingsDataSource> m_settingsDataStore;
		std::shared_ptr<BrowserHandler> m_pBrowserHandler;
		ODS::OdsString GetAddressOld(const ODS::ItemAddress& rAddress);
	};
}

