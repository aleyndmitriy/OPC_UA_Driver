#include "pch.h"
#include "DSource.h"
#include "PluginObjectFactory.h"
#include"Log.h"
#include "XMLSettingsDataSource.h"

DrvOPCUAHistValues::CDSource::CDSource() : m_Configurator(std::make_shared<XMLSettingsDataSource>(), [this]()->ODS::UI::IAbstractUIFacrory* {
	if (m_pHost)
		return (ODS::UI::IAbstractUIFacrory*) (m_pHost->GetInterface(ODS::IPluginHost::IID_UI_FACTORY));
	return 	nullptr;
}), m_pHost(nullptr)
{

}

DrvOPCUAHistValues::CDSource::~CDSource()
{
	m_pHost = nullptr;
}

void* DrvOPCUAHistValues::CDSource::GetInterface(int nIfcID)
{
	return this;
}

ODS::IDsConfigurator* DrvOPCUAHistValues::CDSource::GetConfigurator()
{
	return &m_Configurator;
}

ODS::IServerHda* DrvOPCUAHistValues::CDSource::GetServer()
{
	return nullptr;
}

ODS::IBrowserItem* DrvOPCUAHistValues::CDSource::GetBrowser()
{
	return nullptr;
}


int DrvOPCUAHistValues::CDSource::Attach(const ODS::IPluginHost* pHost)
{
	if (!pHost)
		return ODS::ERR::BAD_PARAM;

	m_pHost = const_cast<ODS::IPluginHost*>(pHost);
	ODS::System::ILog* pILog =
		static_cast<ODS::System::ILog*>(m_pHost->GetInterface(ODS::IPluginHost::IID_LOG));

	DrvOPCUAHistValues::Log::GetInstance()->Init(pILog);
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::CDSource::Detach()
{
	m_pHost = 0;
	return ODS::ERR::OK;
}

ODS::IPropertySet* DrvOPCUAHistValues::CDSource::GetPropertySet()
{
	ODS::RegisterInfo* pInfo = PluginObjectFactory::GetInstance().GetRegisterInfo();
	return pInfo->m_pPropertySet;
}
