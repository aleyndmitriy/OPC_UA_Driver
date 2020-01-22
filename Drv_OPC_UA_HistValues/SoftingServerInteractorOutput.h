#pragma once
#include<string>
#include<vector>
#include"SoftingServerEndPointDescription.h"
class SoftingServerInteractorOutput {
public:
	virtual void SendMessageError(std::string&& message) = 0;
	virtual void SendWarning(std::string&& message) = 0;
	virtual void SendMessageInfo(std::string&& message) = 0;
	virtual void GetServers(std::vector<std::string>&& servers) = 0;
	virtual void GetEndPoints(std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>&& servers) = 0;
	virtual void GetPolicyIds(std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>&& policyIds) = 0;
	virtual void GetNewConnectionGuide(std::string&& uuid) = 0;
	virtual void CloseConnectionWithGuide(std::string&& uuid) = 0;
	virtual ~SoftingServerInteractorOutput() {};
};