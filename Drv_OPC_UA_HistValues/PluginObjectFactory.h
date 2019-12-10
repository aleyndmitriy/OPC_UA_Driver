#pragma once
#include<IPluginObjectFactory.h>
#include<OdsErr.h>
#include<memory>
#include"RegisterInfo.h"

namespace DrvOPCUAHistValues
{
	class PluginObjectFactory : public ODS::IPluginObjectFactory
	{
	public:
		PluginObjectFactory(const PluginObjectFactory& src) = delete;
		PluginObjectFactory& operator = (const PluginObjectFactory& rhs) = delete;
		PluginObjectFactory(PluginObjectFactory&& src) = delete;
		PluginObjectFactory& operator = (PluginObjectFactory&& rhs) = delete;
		~PluginObjectFactory() = default;
		static PluginObjectFactory& GetInstance();
		void* GetInterface(int nIfcId) override;
		int CreateObject(const TCHAR* szObjKey, void* pObjCreationParam, ODS::IPluginObj** ppPluginObj) override;
		int DestroyObject(ODS::IPluginObj* pPluginObj) override;
		void CreateRegisterInfo();
		ODS::RegisterInfo* GetRegisterInfo();
	private:
		PluginObjectFactory() = default;
		std::unique_ptr<CRegisterInfo> regInfoDSList;
	};
}