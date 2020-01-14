#include"pch.h"
#include"SoftingServerEndPointDescription.h"

DrvOPCUAHistValues::SoftingServerEndPointDescription::SoftingServerEndPointDescription(const std::string& endPoinUrl, int mode, int type):
	m_endPointDesc(endPoinUrl, GetModeFromInt(mode)), m_securityType(GetTypeFromInt(type))
{

}

DrvOPCUAHistValues::SoftingServerEndPointDescription::SoftingServerEndPointDescription(const std::string& endPoinUrl, ConfigurationSecurityMode mode, ConfigurationSecurityType type):
	m_endPointDesc(endPoinUrl,mode),m_securityType(type)
{

}

DrvOPCUAHistValues::SoftingServerEndPointDescription::~SoftingServerEndPointDescription()
{

}

bool IsEndPointDescEqual(const DrvOPCUAHistValues::SoftingServerEndPointDescription& lhs, const DrvOPCUAHistValues::SoftingServerEndPointDescription& rhs)
{
	return lhs.m_endPointDesc == rhs.m_endPointDesc && lhs.m_securityType == rhs.m_securityType;
}


bool IsEndPointDescLess(const DrvOPCUAHistValues::SoftingServerEndPointDescription& lhs, const DrvOPCUAHistValues::SoftingServerEndPointDescription& rhs)
{
	if (lhs.m_endPointDesc < rhs.m_endPointDesc) {
		return true;
	}
	else {
		if (lhs.m_securityType < rhs.m_securityType) {
			return true;
		}
		return false;
	}
}
