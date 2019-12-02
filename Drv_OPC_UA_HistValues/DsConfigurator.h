#pragma once
#include <IDsConfigurator.h>
#include <Interface\IAbstractUIFacrory.h>
#include <functional>
#include "SettingsDataSource.h"

namespace DrvOPCUAHistValues
{
	class UISettingsConfigurator final : public ODS::IDsConfigurator {
	public:

		UISettingsConfigurator() = delete;
		UISettingsConfigurator(const std::shared_ptr<ISettingsDataSource>& settingsDataSource, std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter);
		~UISettingsConfigurator();
		UISettingsConfigurator(const UISettingsConfigurator& src) = delete;
		UISettingsConfigurator(UISettingsConfigurator&& src) = delete;
		UISettingsConfigurator& operator=(const UISettingsConfigurator& rhs) = delete;
		UISettingsConfigurator& operator=(UISettingsConfigurator&& rhs) = delete;
		int Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString) override;
		int DestroyString(TCHAR* szCfgString) override;
		void* GetInterface(int nIfcId) override;
		void SetOwnerWnd(void* pOwnerWnd) override;
	private:
		std::shared_ptr<ISettingsDataSource> m_settingsDataSource;
		std::function<ODS::UI::IAbstractUIFacrory * (void)> m_uiFactoryGetter;
		HWND m_hParentWindow;
	};
}
