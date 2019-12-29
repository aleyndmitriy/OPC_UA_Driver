#pragma once
#include <IDsConfigurator.h>
#include <Interface\IAbstractUIFacrory.h>
#include <functional>
#include"ISettingsDataSource.h"
#include"SoftingServerInteractor.h"

namespace DrvOPCUAHistValues
{
	class CDsConfigurator : public ODS::IDsConfigurator
	{
	private:
		std::function<ODS::UI::IAbstractUIFacrory * (void)>  m_uiFactoryGetter;
		std::shared_ptr<ISettingsDataSource> m_settingsDataStore;
		std::shared_ptr<SoftingServerInteractor> m_pSoftingInteractor;
		HWND m_hParentWindow;
	public:

		CDsConfigurator(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter, std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<SoftingServerInteractor> softingInteractor);
		~CDsConfigurator() = default;

		void* GetInterface(int nIfcId) override;

		int Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString) override;

		int DestroyString(TCHAR* szCfgString) override;

		void SetOwnerWnd(void* pOwnerWnd) override;
	};
}
