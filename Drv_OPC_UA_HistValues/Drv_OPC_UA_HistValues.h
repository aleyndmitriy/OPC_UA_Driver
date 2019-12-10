// Drv_OPC_UA_HistValues.h: основной файл заголовка для библиотеки DLL Drv_OPC_UA_HistValues
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CDrvOPCUAHistValuesApp
// Реализацию этого класса см. в файле Drv_OPC_UA_HistValues.cpp
//

class CDrvOPCUAHistValuesApp : public CWinApp
{
public:
	CDrvOPCUAHistValuesApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
