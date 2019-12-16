#pragma once
#include<string>

class SoftingServerInteractorOutput {
public:
	virtual void SendMessageError(std::string&& message) = 0;
	virtual ~SoftingServerInteractorOutput() {};
};