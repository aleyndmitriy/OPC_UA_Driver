/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2019                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             dataFEED OPC UA C++ Server & Client SDK           *
*                                                                            *
* VERSION                  5.61.0                                            *
*                                                                            *
* DATE                     05.11.2019                                        *
*                                                                            *
*****************************************************************************/

#ifndef _OT_MEMORY_H_
#define _OT_MEMORY_H_

#include "OTExports.h"
#include "OSCompat.h"

#ifdef __cplusplus
extern "C"
{
#endif

	typedef void* (OTAPI_CALL *OT_Memory_Alloc_Func)(size_t);
	typedef void* (OTAPI_CALL *OT_Memory_ReAlloc_Func)(void*, size_t);
	typedef void (OTAPI_CALL *OT_Memory_Free_Func)(void*);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTInitializeMemorySystem(OT_Memory_Alloc_Func pAlloc, OT_Memory_ReAlloc_Func pRealloc, OT_Memory_Free_Func pFree);
	TBCORE_IF void OTAPI_CALL OTUninitializeMemorySystem();
	TBCORE_IF void OTAPI_CALL OTFreeMemory(void *pMemory);
	TBCORE_IF void* OTAPI_CALL OTAllocateMemory(size_t size);
	TBCORE_IF void* OTAPI_CALL OTAllocateMemoryInitialized(size_t size);
	TBCORE_IF void* OTAPI_CALL OTReallocateMemory(void* pMemory, size_t size);

#ifdef SOOS_WINDOWS
		TBCORE_IF void* OTAPI_CALL OTAllocateMemory_dbg(size_t size,
			int nBlockUse,
			const char * szFileName,
			int nLine);

#if defined _DEBUG && !defined _WIN32_WCE
		#define OTAllocateMemory(__size) OTAllocateMemory_dbg(__size, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
