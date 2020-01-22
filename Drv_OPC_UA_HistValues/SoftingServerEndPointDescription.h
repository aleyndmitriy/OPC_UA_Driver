#pragma once
#include"ConnectionAttributes.h"

namespace DrvOPCUAHistValues
{
	struct SoftingServerEndPointDescription {
		SoftingServerEndPointDescription(const std::string& policyId, int type);
		SoftingServerEndPointDescription(const std::string& policyId, ConfigurationSecurityType type);
		SoftingServerEndPointDescription() = default;
		SoftingServerEndPointDescription(const SoftingServerEndPointDescription& src) = default;
		SoftingServerEndPointDescription& operator=(const SoftingServerEndPointDescription& src) = default;
		SoftingServerEndPointDescription(SoftingServerEndPointDescription&& src) = default;
		SoftingServerEndPointDescription& operator=(SoftingServerEndPointDescription&& src) = default;
		~SoftingServerEndPointDescription();
		std::string m_policyId;
		ConfigurationSecurityType m_securityType;
	};
}

bool IsEndPointDescEqual(const DrvOPCUAHistValues::SoftingServerEndPointDescription& lhs, const DrvOPCUAHistValues::SoftingServerEndPointDescription& rhs);
bool IsEndPointDescLess(const DrvOPCUAHistValues::SoftingServerEndPointDescription& lhs, const DrvOPCUAHistValues::SoftingServerEndPointDescription& rhs);