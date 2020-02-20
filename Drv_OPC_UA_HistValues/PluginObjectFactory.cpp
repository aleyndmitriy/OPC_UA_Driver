#include "pch.h"
#include "PluginObjectFactory.h"
#include <OdsErr.h>
#include "DSource.h"
#include"Constants.h"

DrvOPCUAHistValues::PluginObjectFactory& DrvOPCUAHistValues::PluginObjectFactory::GetInstance()
{
	static PluginObjectFactory f;
	return f;
}

void* DrvOPCUAHistValues::PluginObjectFactory::GetInterface(int nIfcId)
{
	return this;
}

int DrvOPCUAHistValues::PluginObjectFactory::CreateObject(const TCHAR* szObjKey, void* pObjCreationParam, ODS::IPluginObj** ppPluginObj)
{
	*ppPluginObj = 0;
	if (_tcscmp(szObjKey, OPC_UA_HIST_VALUES)) {
		return ODS::ERR::BAD_PARAM;
	}
	*ppPluginObj = new CDSource(DataAccessAssembly::Instance().GetSettingDataSource(), std::make_shared<SoftingServerInteractor>());
	if (*ppPluginObj)
		return ODS::ERR::OK;
	else
		return ODS::ERR::MEMORY_ALLOCATION_ERR;
}

int DrvOPCUAHistValues::PluginObjectFactory::DestroyObject(ODS::IPluginObj* pPluginObj)
{
	delete pPluginObj;

	return ODS::ERR::OK;
}

void DrvOPCUAHistValues::PluginObjectFactory::CreateRegisterInfo()
{
	regInfoDSList = std::make_unique<CRegisterInfo>(VERSION_MINOR, VERSION_MAJOR, OPC_UA_HIST_VALUES, nullptr, this);
}

ODS::RegisterInfo* DrvOPCUAHistValues::PluginObjectFactory::GetRegisterInfo()
{
	if (regInfoDSList) {
		return &(regInfoDSList->m_RegInfo);
	}
	else {
		return nullptr;
	}

}