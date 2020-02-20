#pragma once
#include "SoftingServerInteractor.h"
#include "SoftingApplicationOutput.h"

namespace DrvOPCUAHistValues
{
	class SoftingApplication
	{
	public:
		SoftingApplication();
		~SoftingApplication();
		void AddDelegate(std::shared_ptr<SoftingApplicationOutput> delegate);
		void SetSertificate(const SecurityCertificateAccess& certificateInfo);
		bool StartApplication();
		
	private:
		SoftingOPCToolbox5::ApplicationPtr m_pApp;
		SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
		EnumStatusCode m_enumResult;
		SecurityCertificateAccess m_CertificateInfo;
		std::vector<std::weak_ptr<SoftingApplicationOutput> > m_pOutputList;
		void resetApplication();
		bool stopApplication();
		void initApplicationDescription();
		void sendErrorMessageToDelegates(std::string&& message);
	};
}