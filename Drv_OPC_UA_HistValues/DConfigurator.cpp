#include"pch.h"
#include <sstream>
#include "DConfigurator.h"
#include "OdsErr.h"
#include "OdsString.h"
#include"ConnectionAttributes.h"
#include"XMLSettingsDataSource.h"
#include "ClientSettingsDialogWrapper.h"
#include"Constants.h"

DrvOPCUAHistValues::CDsConfigurator::CDsConfigurator(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactoryGetter, std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<SoftingServerInteractor> softingInteractor) :m_uiFactoryGetter(uiFactoryGetter), m_settingsDataStore(settingsDataStore), m_pSoftingInteractor(softingInteractor),m_hParentWindow(nullptr)
{

}

void* DrvOPCUAHistValues::CDsConfigurator::GetInterface(int nIfcId)
{
	return NULL;
}

int DrvOPCUAHistValues::CDsConfigurator::Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString)
{
	int iRes = ODS::ERR::FILE;
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes = std::make_shared<DrvOPCUAHistValues::ConnectionAttributes>();
	
	if (szCfgInString != NULL)
	{
		size_t len = _tcslen(szCfgInString);
		if (len > 0) {
			m_settingsDataStore->LoadAttributesString(szCfgInString, len, *attributes);
		}
	}
	HINSTANCE hOld = AfxGetResourceHandle();
	HMODULE hModule = GetModuleHandle(OPC_UA_LIBRARY_NAME);
	AfxSetResourceHandle(hModule);
	std::shared_ptr<ClientSettingsDialogWrapper> dlg = std::make_shared<ClientSettingsDialogWrapper>(m_uiFactoryGetter, m_pSoftingInteractor, attributes, m_hParentWindow);
	int response = dlg->DoModal();
	if (response == IDOK) {
		std::ostringstream outStream;
		m_settingsDataStore->Save(*attributes, outStream);
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

int DrvOPCUAHistValues::CDsConfigurator::DestroyString(TCHAR* szCfgString)
{
	delete[] szCfgString;

	return ODS::ERR::OK;
}

void DrvOPCUAHistValues::CDsConfigurator::SetOwnerWnd(void* pOwnerWnd)
{
	m_hParentWindow = reinterpret_cast<HWND>(pOwnerWnd);
}