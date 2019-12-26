#pragma once
#include<IServerHda.h>
#include"ConnectionAttributes.h"
#include"HdaCommandHandler.h"

namespace DrvOPCUAHistValues
{
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
		std::shared_ptr<ConnectionAttributes> m_pAttributes;
		HdaCommandHandler m_commandHandler;
	};
}
