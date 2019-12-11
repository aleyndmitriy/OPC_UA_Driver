#pragma once
#include <ISourceHdaItem.h>
#include<IPluginHost.h>
#include "DConfigurator.h"
#include "BrowserHdaItem.h"
#include "ServerHdaItem.h"

class CDSource : public ODS::ISourceHdaItem
{
public:
	CDSource();
	~CDSource();
	CDSource(const CDSource& src) = delete;
	CDSource& operator=(const CDSource& src) = delete;
	CDSource(CDSource&& src) = delete;
	CDSource& operator=(CDSource&& src) = delete;
	void* GetInterface(int nIfcId) override;
	ODS::IDsConfigurator* GetConfigurator() override;
	ODS::IServerHda* GetServer() override;
	ODS::IBrowserItem* GetBrowser() override;
	int Attach(const ODS::IPluginHost* pHost) override;
	int Detach() override;
	ODS::IPropertySet* GetPropertySet() override;
private:
	CDsConfigurator m_Configurator;
	BrowserHdaItem m_Browser;
	ServerHdaItem m_Server;
	ODS::IPluginHost* m_pHost;
};