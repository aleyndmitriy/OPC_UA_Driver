#pragma once
#include<Application.h>
#include<ClientSession.h>
#include<memory>
#include<map>
#include"SoftingServerInteractorOutput.h"
#include"ConnectionAttributes.h"

class SoftingServerInteractor {
public:
	SoftingServerInteractor(SoftingServerInteractorOutput* output, const DrvOPCUAHistValues::ConnectionAttributes& attributes);
	SoftingServerInteractor() = delete;
	~SoftingServerInteractor();
	void GetServers();
	void ChooseCurrentServer();
	void ChooseCurrentEndPoint();
	bool OpenConnectionWithUUID(const std::string& connectionID);
	std::string OpenConnection();
	void SetServerConfiguration(const DrvOPCUAHistValues::ConnectionAttributes& attributes);
private:
	DrvOPCUAHistValues::ConnectionAttributes m_serverAttributes;
	SoftingServerInteractorOutput* m_pOutput;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
	EnumStatusCode m_enumResult;
	SoftingOPCToolbox5::EndpointDescription m_selectedEndPointDescription;
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr> m_sessionsList;
	void initApplicationDescription();
	DrvOPCUAHistValues::SoftingServerEndPointDescription mapEndPointDescription(const SoftingOPCToolbox5::EndpointDescription& desc) const;
	bool admitToAttributes(const SoftingOPCToolbox5::EndpointDescription& desc, const DrvOPCUAHistValues::ConnectionAttributes& attributes) const;
};
