#pragma once
#include<string>
#include<vector>
#include"ConnectionAttributes.h"

class SoftingServerInteractorOutput {
public:
	virtual void SendMessageError(std::string&& message) = 0;
	virtual void SendWarning(std::string&& message) = 0;
	virtual void SendMessageInfo(std::string&& message) = 0;
	virtual void GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl) = 0;
	virtual void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName) = 0;
	virtual void ChooseSecurityConfiguration() = 0;
	virtual void GetEndPoints(std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>&& servers) = 0;
	virtual void GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds) = 0;
	virtual void GetAggregates(std::vector<std::pair<std::string, int> >&& aggregates) = 0;
	virtual void GetNewConnectionGuide(std::string&& uuid) = 0;
	virtual void CloseConnectionWithGuide(std::string&& uuid) = 0;
	virtual ~SoftingServerInteractorOutput() {};
};