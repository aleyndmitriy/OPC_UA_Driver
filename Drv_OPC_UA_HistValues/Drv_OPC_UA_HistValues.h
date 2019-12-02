// Drv_OPC_UA_HistValues.h : main header file for the Drv_OPC_UA_HistValues DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDrvOPCUAHistValuesApp
// See Drv_OPC_UA_HistValues.cpp for the implementation of this class
//

class CDrvOPCUAHistValuesApp : public CWinApp
{
public:
	CDrvOPCUAHistValuesApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
