#include"pch.h"
#include"SoftingServerEndPointDescription.h"

DrvOPCUAHistValues::SoftingServerEndPointDescription::SoftingServerEndPointDescription(const std::string& endPoinUrl, int mode, const std::string& certificate, const std::string& privateKey, int type):
	m_endPointDesc(endPoinUrl, GetModeFromInt(mode)), m_endPointPolicy(std::string(),std::string(),certificate,privateKey, GetTypeFromInt(type))
{

}

DrvOPCUAHistValues::SoftingServerEndPointDescription::SoftingServerEndPointDescription(const ServerSecurityModeConfiguration& config, const SecurityAccessConfiguration& policy):
	m_endPointDesc(config), m_endPointPolicy(policy)
{

}

DrvOPCUAHistValues::SoftingServerEndPointDescription::~SoftingServerEndPointDescription()
{

}