#include "pch.h"
#include"RegisterInfo.h"
#include "Constants.h"
#include<IDataSource.h>

DrvOPCUAHistValues::CRegisterInfo::CRegisterInfo() :CRegisterInfo(VERSION_MINOR, VERSION_MAJOR, nullptr, nullptr, nullptr)
{

}

DrvOPCUAHistValues::CRegisterInfo::CRegisterInfo(int minorVersion, int majorVersion, const TCHAR* key, void* param, ODS::IPluginObjectFactory* factory)
{
	m_RegInfo.m_Version.m_nMinor = minorVersion;
	m_RegInfo.m_Version.m_nMajor = majorVersion;
	if (key != nullptr) {
		_tcscpy_s(m_RegInfo.m_szObjKey, MAX_PATH, key);
	}
	else {
		memset(m_RegInfo.m_szObjKey, '\0', MAX_PATH);
	}
	m_RegInfo.m_pObjCreationParam = param;
	m_RegInfo.m_pFactory = factory;
	CPropertySet* propSet = new CPropertySet();
	propSet->AddProperty(ODS::IDataSource::PROPERTY_ID_VENDOR, TEXT("PROPERTY_ID_VENDOR"), OPC_VENDOR);
	propSet->AddProperty(ODS::IDataSource::PROPERTY_ID_DATA_SOURCE, TEXT("PROPERTY_ID_DATA_SOURCE"), OPC_UA_HDA_ITEM_DRIVER);
	propSet->AddProperty(ODS::IDataSource::PROPERTY_ID_CLIENT_NAME, TEXT("PROPERTY_ID_CLIENT_NAME"), OPC_UA_CLIENT_NAME);
	propSet->AddProperty(ODS::IDataSource::PROPERTY_ID_DESCRIPTION, TEXT("PROPERTY_ID_DESCRIPTION"), OPC_UA_ITEM_DESC);
	VARIANT vVal;
	::VariantInit(&vVal);
	vVal.boolVal = VARIANT_TRUE;
	vVal.vt = VT_BOOL;
	propSet->AddProperty(ODS::IDataSource::PROPERTY_ID_HAS_CONFIGURATION_UI, _T("PROPERTY_ID_HAS_CONFIGURATION_UI"),
		&vVal);
	::VariantClear(&vVal);
	m_RegInfo.m_pPropertySet = propSet;
}

DrvOPCUAHistValues::CRegisterInfo::~CRegisterInfo()
{
	m_RegInfo.m_Version.m_nMajor = VERSION_MAJOR;
	m_RegInfo.m_Version.m_nMinor = VERSION_MINOR;
	memset(m_RegInfo.m_szObjKey, '\0', MAX_PATH);
	m_RegInfo.m_pObjCreationParam = nullptr;
	m_RegInfo.m_pFactory = nullptr;
	delete m_RegInfo.m_pPropertySet;
	m_RegInfo.m_pPropertySet = nullptr;
}
