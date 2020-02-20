#pragma once
#include "SoftingServerInteractor.h"

namespace DrvOPCUAHistValues
{
	class SoftingApplication
	{
	public:
		SoftingApplication();
		~SoftingApplication();
	private:
		SoftingOPCToolbox5::ApplicationPtr m_pApp;
		SoftingOPCToolbox5::ApplicationDescription m_AppDesc;
		
	};
}