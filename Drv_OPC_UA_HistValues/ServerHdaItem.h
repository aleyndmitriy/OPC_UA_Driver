#pragma once
#include<IServerHda.h>
#include"ConnectionAttributes.h"

class ServerHdaItem : public ODS::IServerHda
{
public:
	ServerHdaItem() = default;
	void* GetInterface(int nIfcId) override;
	int Init(TCHAR* szCfgString) override;
	int Shut() override;
	int IsHdaFunctionSupported(int nFuncType) override;
	int Execute(ODS::HdaCommand* pCommand, ODS::HdaCommandResult** ppResult) override;
	int DestroyResult(ODS::HdaCommandResult* pResult) override;
private:
	DrvOPCUAHistValues::ConnectionAttributes m_attributes;
	//HdaCommandHandler m_commandHandler;
};