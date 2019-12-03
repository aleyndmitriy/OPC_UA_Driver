#include"pch.h"
#include"Export.h"
#include"PluginObjectFactory.h"

int InitPlugin(void* pParam, ODS::IPluginHost* pPluginHost)
{
	if (pParam == nullptr || pPluginHost == nullptr) {
		return ODS::ERR::INIT_ERR;
	}
	DrvOPCUAHistValues::PluginObjectFactory::GetInstance().CreateRegisterInfo();
	pPluginHost->RegisterObject(pParam, DrvOPCUAHistValues::PluginObjectFactory::GetInstance().GetRegisterInfo());
	return ODS::ERR::OK;
}