#include"pch.h"
#include "ConnectionAttributes.h"

DrvOPCUAHistValues::ConnectionAttributes::ConnectionAttributes() :driver(), serverName(), databaseName(), loginName(), password(), isServerAuthentication(false), isAlarmReport(false)
{

}

DrvOPCUAHistValues::ConnectionAttributes::~ConnectionAttributes()
{

}

bool DrvOPCUAHistValues::operator==(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return (lhs.driver == rhs.driver && lhs.serverName == rhs.serverName && lhs.loginName == rhs.loginName &&
		lhs.password == rhs.password && lhs.databaseName == rhs.databaseName && lhs.isServerAuthentication == rhs.isServerAuthentication);
}

bool DrvOPCUAHistValues::operator!=(const ConnectionAttributes& lhs, const ConnectionAttributes& rhs)
{
	return (lhs.driver != rhs.driver || lhs.serverName != rhs.serverName || lhs.loginName != rhs.loginName ||
		lhs.password != rhs.password || lhs.databaseName != rhs.databaseName || lhs.isServerAuthentication != rhs.isServerAuthentication);
}