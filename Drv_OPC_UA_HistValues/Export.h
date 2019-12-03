#pragma once
#include<IPluginHost.h>

extern "C" __declspec(dllexport) int InitPlugin(void* pParam, ODS::IPluginHost * pPluginHost);