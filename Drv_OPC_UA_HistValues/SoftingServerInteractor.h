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
	std::vector<std::string> GetServers();
	bool OpenConnectionWithUUID(const std::string& connectionID);
	std::string OpenConnection();
private:
	std::string m_strCompServName;
	SoftingServerInteractorOutput* m_pOutput;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
	EnumStatusCode m_enumResult;
	std::vector<SoftingOPCToolbox5::ApplicationDescription> m_serversList;
	void InitApplicationDescription();
	bool findServersDescription();
};