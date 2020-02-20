#pragma once
#include<string>

class SoftingApplicationOutput
{
public:
	virtual void SendMessageError(std::string&& message) = 0;
	virtual void SendWarning(std::string&& message) = 0;
	virtual void SendMessageInfo(std::string&& message) = 0;
	virtual ~SoftingApplicationOutput() {};
};