#pragma once
#include<string>
#include<vector>
class SoftingServerInteractorOutput {
public:
	virtual void SendMessageError(std::string&& message) = 0;
	virtual void SendWarning(std::string&& message) = 0;
	virtual void GetServers(std::vector<std::string>&& servers) = 0;
	virtual void GetEndPoints(std::vector<std::string>&& servers) = 0;
	virtual ~SoftingServerInteractorOutput() {};
};