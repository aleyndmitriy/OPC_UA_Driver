#include "pch.h"
#include "DSource.h"
#include "PluginObjectFactory.h"
#include"Log.h"

DrvOPCUAHistValues::CDSource::CDSource(std::shared_ptr<ISettingsDataSource> settingsDataStore, std::shared_ptr<SoftingServerInteractor> softingDataStore) : m_Configurator([this]()->ODS::UI::IAbstractUIFacrory* {
	if (m_pHost)
		return (ODS::UI::IAbstractUIFacrory*) (m_pHost->GetInterface(ODS::IPluginHost::IID_UI_FACTORY));
	return 	nullptr;
	}, settingsDataStore, softingDataStore), m_Browser(settingsDataStore, softingDataStore), m_Server(settingsDataStore, softingDataStore), m_pHost(nullptr)
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
	return &m_Server;
}

ODS::IBrowserItem* DrvOPCUAHistValues::CDSource::GetBrowser()
{
	return &m_Browser;
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
	ODS::RegisterInfo* pInfo = DrvOPCUAHistValues::PluginObjectFactory::GetInstance().GetRegisterInfo();
	return pInfo->m_pPropertySet;
}