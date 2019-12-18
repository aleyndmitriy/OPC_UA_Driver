#pragma once
#include<Application.h>
#include<ClientSession.h>
#include<memory>
#include<map>
#include"SoftingServerInteractorOutput.h"
#include"ConnectionAttributes.h"

class SoftingServerInteractor {
public:
	SoftingServerInteractor(SoftingServerInteractorOutput* output, const std::string& compName, unsigned int port);
	SoftingServerInteractor(SoftingServerInteractorOutput* output, const std::string& compName);
	explicit SoftingServerInteractor(const std::string& compName);
	SoftingServerInteractor() = delete;
	~SoftingServerInteractor();
	void GetServers();
	void ChooseCurrentServer(int index);
	bool OpenConnectionWithUUID(const std::string& connectionID);
	std::string OpenConnection();
	bool SetServerConfiguration(const DrvOPCUAHistValues::ConnectionAttributes& attributes);
private:
	std::string m_strCompServName;
	unsigned int m_uServerPort;
	SoftingServerInteractorOutput* m_pOutput;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
	EnumStatusCode m_enumResult;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> m_serversList;
	std::vector<SoftingOPCToolbox5::EndpointDescription> m_selectedUrlEndpointDescriptions;
	std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr > m_sessionsList;
	void InitApplicationDescription();
	bool findServersDescription();
	DrvOPCUAHistValues::SoftingServerEndPointDescription mapEndPointDescription(const SoftingOPCToolbox5::EndpointDescription& desc) const;
	bool admitToAttributes(const SoftingOPCToolbox5::EndpointDescription& desc, const DrvOPCUAHistValues::ConnectionAttributes& attributes) const;
};
