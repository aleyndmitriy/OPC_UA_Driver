#pragma once
#include "PropertySet.h"
#include <IPluginHost.h>

namespace DrvOPCUAHistValues
{
	class PluginObjectFactory;

	class CRegisterInfo
	{
	public:
		friend class PluginObjectFactory;
		CRegisterInfo();
		CRegisterInfo(int minorVersion, int majorVersion, const TCHAR* key, void* param, ODS::IPluginObjectFactory* factory);
		CRegisterInfo(const CRegisterInfo& src) = delete;
		CRegisterInfo(CRegisterInfo&& src) = delete;
		CRegisterInfo& operator=(const CRegisterInfo& src) = delete;
		CRegisterInfo& operator=(CRegisterInfo&& src) = delete;
		~CRegisterInfo();
	private:
		ODS::RegisterInfo m_RegInfo;
	};
}