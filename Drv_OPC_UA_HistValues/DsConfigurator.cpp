#include"pch.h"
#include"DsConfigurator.h"
#include "OdsErr.h"
#include "Constants.h"
#include <sstream>
#include"SettingsDialog.h"

DrvOPCUAHistValues::UISettingsConfigurator::UISettingsConfigurator(const std::shared_ptr<ISettingsDataSource>& settingsDataSource, std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter) :m_settingsDataSource(settingsDataSource), m_uiFactoryGetter(uiFactoryGetter), m_hParentWindow(nullptr)
{

}

DrvOPCUAHistValues::UISettingsConfigurator::~UISettingsConfigurator()
{
	m_settingsDataSource.reset();
}

int DrvOPCUAHistValues::UISettingsConfigurator::DestroyString(TCHAR* szCfgString)
{
	if (szCfgString)
		delete[] szCfgString;

	return ODS::ERR::OK;
}

void* DrvOPCUAHistValues::UISettingsConfigurator::GetInterface(int nIfcId)
{
	return NULL;
}

void DrvOPCUAHistValues::UISettingsConfigurator::SetOwnerWnd(void* pOwnerWnd) {
	m_hParentWindow = (HWND)(pOwnerWnd);
}

int DrvOPCUAHistValues::UISettingsConfigurator::Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString)
{
	int iRes = ODS::ERR::FILE;
	std::shared_ptr<ConnectionAttributes> attributes = std::make_shared<ConnectionAttributes>();
	std::shared_ptr<std::map<std::string, std::vector<StatementCondition> > > filters = std::make_shared<std::map<std::string, std::vector<StatementCondition> > >();
	if (szCfgInString != NULL)
	{
		size_t len = _tcslen(szCfgInString);
		if (m_settingsDataSource) {
			m_settingsDataSource->LoadSettingsString(szCfgInString, len, *attributes, *filters);
		}
	}
	HINSTANCE hOld = AfxGetResourceHandle();
	HMODULE hModule = GetModuleHandle(OPC_UA_LIBRARY_NAME);
	AfxSetResourceHandle(hModule);
	CWnd* parent = CWnd::FromHandle(m_hParentWindow);
	SettingsDialog dlg(m_uiFactoryGetter, attributes, filters, parent);
	int response = dlg.DoModal();
	if (response == IDOK) {
		std::ostringstream outStream;
		if (m_settingsDataSource) {
			m_settingsDataSource->SaveSettingsString(*attributes, *filters, outStream);
			std::string outString = outStream.str();
			char* outStr = new char[outString.length() + 1];
			_tcscpy_s(outStr, outString.length() + 1, outString.c_str());
			*pszCfgOutString = outStr;
			iRes = ODS::ERR::OK;
		}
	}
	else {
		if (szCfgInString != NULL)
		{
			size_t len = _tcslen(szCfgInString);
			char* outStr = new char[len + 1];
			_tcscpy_s(outStr, len + 1, szCfgInString);
			*pszCfgOutString = outStr;
			iRes = ODS::ERR::OK;
		}
	}
	return iRes;
}