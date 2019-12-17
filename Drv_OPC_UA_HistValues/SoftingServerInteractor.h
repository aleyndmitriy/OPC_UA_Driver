#pragma once
#include<Application.h>
#include<memory>
#include"SoftingServerInteractorOutput.h"

class SoftingServerInteractor {
public:
	SoftingServerInteractor(SoftingServerInteractorOutput* output, const std::string& compName);
	explicit SoftingServerInteractor(const std::string& compName);
	SoftingServerInteractor() = delete;
	~SoftingServerInteractor();
	void GetServers();
	void ChooseCurrentServer(int index);
	bool OpenConnectionWithUUID(const std::string& connectionID);
	std::string OpenConnection();
private:
	std::string m_strCompServName;
	SoftingServerInteractorOutput* m_pOutput;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
	EnumStatusCode m_enumResult;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> m_serversList;
	std::vector<SoftingOPCToolbox5::EndpointDescription> m_selectedUrlEndpointDescriptions;
	void InitApplicationDescription();
	bool findServersDescription();
};