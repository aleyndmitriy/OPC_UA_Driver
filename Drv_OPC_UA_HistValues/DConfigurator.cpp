#include"pch.h"
#include <sstream>
#include "DConfigurator.h"
#include "OdsErr.h"
#include "OdsString.h"
#include"ConnectionAttributes.h"
#include"XMLSettingsDataSource.h"
#include "ClientSettingsDialog.h"
#include"Constants.h"

CDsConfigurator::CDsConfigurator(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter) :m_uiFactoryGetter(uiFactoryGetter), m_hParentWindow(nullptr)
{

}

void* CDsConfigurator::GetInterface(int nIfcId)
{
	return NULL;
}

int CDsConfigurator::Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString)
{
	int iRes = ODS::ERR::FILE;
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes = std::make_shared<DrvOPCUAHistValues::ConnectionAttributes>();
	DrvOPCUAHistValues::XMLSettingsDataSource settingSource;
	if (szCfgInString != NULL)
	{
		size_t len = _tcslen(szCfgInString);
		if (len > 0) {
			settingSource.LoadAttributesString(szCfgInString, len, *attributes);
		}
	}
	HINSTANCE hOld = AfxGetResourceHandle();
	HMODULE hModule = GetModuleHandle(OPC_UA_LIBRARY_NAME);
	AfxSetResourceHandle(hModule);
	CWnd* parent = CWnd::FromHandle(m_hParentWindow);
	CClientSettingsDialog dlg(m_uiFactoryGetter, attributes, parent);
	int response = dlg.DoModal();
	if (response == IDOK) {
		std::ostringstream outStream;
		settingSource.Save(*attributes, outStream);
		std::string outString = outStream.str();
		char* outStr = new char[outString.length() + 1];
		_tcscpy_s(outStr, outString.length() + 1, outString.c_str());
		*pszCfgOutString = outStr;
		iRes = ODS::ERR::OK;
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

int CDsConfigurator::DestroyString(TCHAR* szCfgString)
{
	delete[] szCfgString;

	return ODS::ERR::OK;
}

void CDsConfigurator::SetOwnerWnd(void* pOwnerWnd)
{
	m_hParentWindow = reinterpret_cast<HWND>(pOwnerWnd);
}