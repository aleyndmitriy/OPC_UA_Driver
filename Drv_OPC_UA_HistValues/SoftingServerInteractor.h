#pragma once
#include<Application.h>
#include<ClientSession.h>
#include<memory>
#include<map>
#include"SoftingServerInteractorOutput.h"
#include"ConnectionAttributes.h"

class SoftingServerInteractor {
public:
	SoftingServerInteractor(SoftingServerInteractorOutput* output, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes);
	SoftingServerInteractor() = delete;
	SoftingServerInteractor(const SoftingServerInteractor& src) = delete;
	SoftingServerInteractor& operator=(const SoftingServerInteractor& src) = delete;
	SoftingServerInteractor(SoftingServerInteractor&& src) = delete;
	SoftingServerInteractor& operator=(SoftingServerInteractor&& src) = delete;
	~SoftingServerInteractor();
	void GetServers();
	void ChooseCurrentServer();
	void ChooseCurrentEndPoint();
	void OpenConnectionWithUUID(const std::string& connectionID);
	void CloseConnectionWithUUID(const std::string& connectionID);
	void OpenConnection();
	void TestConnection();
private:
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> m_pServerAttributes;
	SoftingServerInteractorOutput* m_pOutput;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
	EnumStatusCode m_enumResult;
	std::unique_ptr<SoftingOPCToolbox5::EndpointDescription> m_selectedEndPointDescription;
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr> m_sessionsList;
	void initApplicationDescription();
};

bool admitToAttributes(const SoftingOPCToolbox5::EndpointDescription& desc, const DrvOPCUAHistValues::ConnectionAttributes& attributes);
DrvOPCUAHistValues::SoftingServerEndPointDescription mapEndPointDescription(const SoftingOPCToolbox5::EndpointDescription& desc);