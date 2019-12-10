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

#ifndef OT_EXPORTS_H
#define OT_EXPORTS_H

#include "OSCompat.h"

///////////////////////////////////////////////////////////////////////////////
// Win 32 definitions
///////////////////////////////////////////////////////////////////////////////
#ifdef SOOS_WINDOWS
	#ifndef _WIN32_WCE
		#define TBC_OS_WINDOWS
	#endif
	#define OTAPI_CALL __stdcall

	#ifndef TBC_EXPORT
		#define TBC_EXPORT __declspec(dllimport)
	#endif

	#ifndef TBCORE_IF
		#ifdef OT_COMPILATION
			#define TBCORE_IF __declspec(dllexport)
		#else
			#define TBCORE_IF __declspec(dllimport)
		#endif
	#endif
#endif

///////////////////////////////////////////////////////////////////////////////
// Linux definitions
///////////////////////////////////////////////////////////////////////////////
#ifdef SOOS_POSIX
	#define OTAPI_CALL

	#ifndef TBC_EXPORT
		#define TBC_EXPORT
	#endif

	#ifndef TBCORE_IF
		#define TBCORE_IF
	#endif

	#ifndef SODEVENV_CYGWIN
		#define _stdcall
		#define __cdecl
	#endif
#endif

// Prevent symbols from being exported when building a static library
#ifdef BUILD_LIB
	#ifdef TBCORE_IF
		#undef TBCORE_IF
		#define TBCORE_IF
	#endif

	#ifdef TBC_EXPORT
		#undef TBC_EXPORT
		#define TBC_EXPORT
	#endif
#endif

#endif
