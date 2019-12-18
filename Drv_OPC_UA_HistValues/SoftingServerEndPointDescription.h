#pragma once
#include"ConnectionAttributes.h"

namespace DrvOPCUAHistValues
{
	struct SoftingServerEndPointDescription {
		SoftingServerEndPointDescription(const std::string& endPoinUrl, int mode, const std::string& certificate, const std::string& privateKey, int type);
		SoftingServerEndPointDescription() = default;
		SoftingServerEndPointDescription(const SoftingServerEndPointDescription& src) = default;
		SoftingServerEndPointDescription& operator=(const SoftingServerEndPointDescription& src) = default;
		SoftingServerEndPointDescription(SoftingServerEndPointDescription&& src) = default;
		SoftingServerEndPointDescription& operator=(SoftingServerEndPointDescription&& src) = default;
		~SoftingServerEndPointDescription();
		ServerSecurityModeConfiguration m_endPointDesc;
		SecurityAccessConfiguration m_endPointPolicy;
	};
}
