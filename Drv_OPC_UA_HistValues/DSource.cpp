#include "pch.h"
#include "DSource.h"
#include "PluginObjectFactory.h"
#include"Log.h"

CDSource::CDSource() : m_Configurator([this]()->ODS::UI::IAbstractUIFacrory* {
	if (m_pHost)
		return (ODS::UI::IAbstractUIFacrory*) (m_pHost->GetInterface(ODS::IPluginHost::IID_UI_FACTORY));
	return 	nullptr;
	}), m_Browser(), m_Server(), m_pHost(nullptr)
{

}

CDSource::~CDSource()
{
	m_pHost = nullptr;
}

void* CDSource::GetInterface(int nIfcID)
{
	return this;
}

ODS::IDsConfigurator* CDSource::GetConfigurator()
{
	return &m_Configurator;
}

ODS::IServerHda* CDSource::GetServer()
{
	return &m_Server;
}

ODS::IBrowserItem* CDSource::GetBrowser()
{
	return &m_Browser;
}

int CDSource::Attach(const ODS::IPluginHost* pHost)
{
	if (!pHost)
		return ODS::ERR::BAD_PARAM;

	m_pHost = const_cast<ODS::IPluginHost*>(pHost);
	ODS::System::ILog* pILog =
		static_cast<ODS::System::ILog*>(m_pHost->GetInterface(ODS::IPluginHost::IID_LOG));
	DrvOPCUAHistValues::Log::GetInstance()->Init(pILog);
	return ODS::ERR::OK;
}

int CDSource::Detach()
{
	m_pHost = 0;
	return ODS::ERR::OK;
}

ODS::IPropertySet* CDSource::GetPropertySet()
{
	ODS::RegisterInfo* pInfo = DrvOPCUAHistValues::PluginObjectFactory::GetInstance().GetRegisterInfo();
	return pInfo->m_pPropertySet;
}