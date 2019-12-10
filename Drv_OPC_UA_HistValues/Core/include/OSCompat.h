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

#ifndef _OSCOMPAT_H_
#define _OSCOMPAT_H_

///////////////////////////////////////////////////////////////////////////////
// Determine the operating system
///////////////////////////////////////////////////////////////////////////////
#if defined _WIN32 || defined _WIN32_WCE
	#define SOOS_WINDOWS

	#ifdef _WIN32_WCE
	#define SOOS_WINDOWS_CE
	#endif
#else
	#define SOOS_POSIX

	#ifdef __linux__
	#define SODEVENV_LINUX
	#endif

	#ifdef __VXWORKS__
	#define SODEVENV_VXWORKS
	#endif

	#ifdef __CYGWIN__
	#define SODEVENV_CYGWIN
	#endif
#endif


// restricts the SDK to server data access only functionality
#ifndef TB5_EMBEDDED_SERVER
#define TB5_EMBEDDED_SERVER 0
#endif

// compiles the SDK without PKI functionality
#ifndef TB5_NO_PKI
#define TB5_NO_PKI 0
#endif

// defines what functionality shall be available
// client functionality
#if TB5_EMBEDDED_SERVER
#define TB5_CLIENT 0
#else
#define TB5_CLIENT 1
#endif

// query services
#if TB5_EMBEDDED_SERVER
#define TB5_QUERY 0
#else
#define TB5_QUERY 1
#endif

// history services
#if TB5_EMBEDDED_SERVER
#define TB5_HISTORY 0
#else
#define TB5_HISTORY 1
#endif

// alarms and conditions
#if TB5_EMBEDDED_SERVER
#define TB5_ALARMS 0
#else
#define TB5_ALARMS 1
#endif

// filters are used in queries and events
#if TB5_ALARMS || TB5_QUERY
#ifdef TB5_FILTER
#undef TB5_FILTER
#endif
#define TB5_FILTER 1
#else
#define TB5_FILTER 0
#endif

///////////////////////////////////////////////////////////////////////////////
// Windows-specific definitions
///////////////////////////////////////////////////////////////////////////////
#ifdef SOOS_WINDOWS
	// do not use global max() provided by windows.h
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

	#include <windows.h>
	#ifdef _WIN32_WCE
		#include <WinSock2.h>
	#endif
	#include <tchar.h>
	#ifndef _WIN32_WCE
		#include <io.h>
	#endif

	#ifdef _DEBUG
		#ifdef _WIN32_WCE
			#ifndef _ASSERTION
				#define _ASSERTION(expr, message) { if (!(expr)) _tprintf(_T("Assertion failed at %s(%u): %s\n"), _T(__FILE__), __LINE__, message); } (void)0
				#define _REPORT_ASSERTION(message) { _tprintf(_T("Assertion failed at %s(%u): %s\n"), _T(__FILE__), __LINE__, message); } (void)0
			#endif
		#else
			#include <crtdbg.h>
			#ifdef _UNICODE
				#if _MSC_VER >= 1400
					#define _ASSERTION(expr, message)																					\
							{																											\
								if (!(expr) && (1 == _CrtDbgReportW(_CRT_ASSERT, _T(__FILE__), __LINE__, NULL, _T("%s"), message)))		\
									_CrtDbgBreak();																						\
							} (void)0
					#define _REPORT_ASSERTION(message)																			\
							{																									\
								if (1 == _CrtDbgReportW(_CRT_ASSERT, _T(__FILE__), __LINE__, NULL, _T("%s"), message))			\
									_CrtDbgBreak();																				\
							} (void)0
				#else
					#define _ASSERTION(expr, message) (void)0
					#define _REPORT_ASSERTION(message) (void)0
				#endif
			#else // non unicode version
				#define _ASSERTION(expr, message)\
						{																										\
							if (!(expr) && (1 == _CrtDbgReport(_CRT_ASSERT, _T(__FILE__), __LINE__, NULL, _T("%s"), message)))	\
								_CrtDbgBreak();																					\
						} (void)0
				#define _REPORT_ASSERTION(message)																			\
						{																									\
							if (1 == _CrtDbgReport(_CRT_ASSERT, _T(__FILE__), __LINE__, NULL, _T("%s"), message))			\
								_CrtDbgBreak();																				\
						} (void)0
			#endif // _UNICODE
		#endif // _WIN32_WCE
	#else // _DEBUG
		#define _ASSERTION(expr, message) (void)0
		#define _REPORT_ASSERTION(message) (void)0
	#endif // _DEBUG

	#ifdef _WIN32_WCE
		#define FILE_OR_DIRECTORY_EXISTS(path)    (GetFileAttributes(path) != INVALID_FILE_ATTRIBUTES)
	#else
		#define FILE_OR_DIRECTORY_EXISTS(path)    (_taccess(path, 0) == 0)
	#endif

	#ifndef strtoll
		#define strtoll     _strtoi64
	#endif
	#ifndef strtoull
		#define strtoull    _strtoui64
	#endif

	#define DIR_SEPARATOR _T('\\')
	#define SLEEP(__milliseconds) Sleep(__milliseconds)
#endif // SOOS_WINDOWS

///////////////////////////////////////////////////////////////////////////////
// POSIX-specific definitions
///////////////////////////////////////////////////////////////////////////////
#ifdef SOOS_POSIX
	// The most common include on Linux
	#include <errno.h>
	#include <ctype.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <pthread.h>
	#include <time.h>
	#ifdef SODEVENV_VXWORKS
		#include <selectLib.h>
	#else
		#include <sys/time.h>
		#include <sys/times.h>
	#endif
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <string.h>
	#include <stdio.h> // Required by _ASSERTION macro
	#ifndef _DEBUG
		#ifndef _ASSERTION
			#define _ASSERTION(x,y) (void)0
			#define _REPORT_ASSERTION(message) (void)0
		#endif
	#else
		#ifndef _ASSERTION
			#define _ASSERTION(expr, message) { if (!(expr)) printf("Assertion failed at %s(%u): %s\n", __FILE__, __LINE__, message); } (void)0
			#define _REPORT_ASSERTION(message) { printf("Assertion failed at %s(%u): %s\n", __FILE__, __LINE__, message); } (void)0
		#endif
	#endif

	#define IN
	#define OUT
	#define OPTIONAL

	#define _T(text)    text
	#define _tcscpy     strcpy
	#define _tcscat     strcat
	#define _tcsdup     strdup
	#define _tcsstr     strstr
	#define _tcschr     strchr
	#define _tcsrchr    strrchr
	#define _tcscmp     strcmp
	#define FILE_OR_DIRECTORY_EXISTS(path)    (access(path, 0) == 0)
	#define _tfopen     fopen
	#define _tstat		stat
	#define _tstat		stat

	#ifdef SODEVENV_VXWORKS
		inline int _tcsicmp(const char *p1, const char *p2)
		{
			int result;
			while ((result = toupper((unsigned char)*p1) - toupper((unsigned char)*p2)) == 0 && *p1 && *p2)
				p1++, p2++;
			return (result);
		}
		inline int _tcsnicmp(const char *p1, const char *p2, size_t len)
		{
			int result;
			for(size_t i=0; i < len; i++)
			{
				result = toupper((unsigned char)p1[i]) - toupper((unsigned char)p2[i]);
				if((result != 0) && p1[i] && p2[i])
				{
					break;
				}
			}
			return (result);
		}
		#define stricmp _tcsicmp
		#define strnicmp _tcsnicmp
	#else
		#define _tcsicmp    strcasecmp
		#define _tcsnicmp   strncasecmp
		#define stricmp     strcasecmp
	#endif

	#define _tcslen     strlen
	#define _tcspbrk    strpbrk
	#define _tcsncpy    strncpy
	#define _tcstoul    strtoul
	#define _tcstol     strtol
	#define _tcstod     strtod
	#define _tcsncmp    strncmp
	#define _tcstoi64   strtoll
	#define _tcstoui64  strtoull
	#define _tcstok     strtok

	#define _tcsdec(_cpc1, _cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
	#define _tcsinc(_pc)  ((_pc)+1)

	#define _tmain      main

	#define _tprintf    printf
	#define _ftprintf   fprintf
	#define _stprintf   sprintf
	#define _sntprintf  snprintf
	#define _vstprintf  vsprintf
	#define _vsntprintf vsnprintf
	#define _tscanf     scanf
	#define _ftscanf    fscanf
	#define _stscanf    sscanf
	#define _fgetts     fgets

	#define _ttoi       atoi
	#define _ttol       atol
	#define _ttof       atof

	#define lstrlen     strlen
	#define lstrcpy     strcpy
	#define lstrcat     strcat

	/* ctype-functions */

	#define _istalnum   isalnum
	#define _istalpha   isalpha
	#define _istdigit   isdigit
	#define _istgraph   isgraph
	#define _istlower   islower
	#define _istprint   isprint
	#define _istpunct   ispunct
	#define _istspace   isspace
	#define _istupper   isupper

	#define _totupper   toupper
	#define _totlower   tolower

	#define __max(a,b)  (((a) > (b)) ? (a) : (b))
	#define __min(a,b)  (((a) < (b)) ? (a) : (b))

	#define INFINITE            0xFFFFFFFFul

	/*! @brief SLEEP macro. Redirects the call to system sleep.
	* @param __milliseconds The number of milliseconds to sleep. */
	#define SLEEP(__milliseconds)													\
			{																		\
				timespec sleeping_time;												\
				sleeping_time.tv_sec = (__milliseconds);							\
				sleeping_time.tv_nsec = (sleeping_time.tv_sec % 1000) * 1000000;	\
				sleeping_time.tv_sec /= 1000;										\
				nanosleep(&sleeping_time, NULL);									\
			}

	#define DIR_SEPARATOR _T('/')
#endif /* SOOS_POSIX */

//////////////////////////////////////////////////////////////////////////
// Common required header files and definitions
//////////////////////////////////////////////////////////////////////////
#include "Platforms.h" // interlockedIncrement/Decrement
#define _UNUSED(parameter) (void)(parameter)

//////////////////////////////////////////////////////////////////////////
// Platform-independent types
//////////////////////////////////////////////////////////////////////////
#include <string>
#include <sstream>

typedef unsigned char			OTUInt8;
typedef signed char				OTInt8;
typedef unsigned short			OTUInt16;
typedef short					OTInt16;
typedef bool					OTBoolean;
typedef unsigned int			OTUInt32;
typedef int						OTInt32;
typedef unsigned long long		OTUInt64;
typedef long long				OTInt64;
typedef double					OTDouble;
typedef float					OTFloat;
#ifdef SOOS_WINDOWS
typedef TCHAR					OTChar;
#else
typedef char					OTChar;
#endif
#if defined SOOS_WINDOWS && defined _UNICODE
	typedef std::wstring			tstring;
	typedef std::wstringstream		tstringstream;
	#define tcin std::wcin
#else
	typedef std::string				tstring;
	typedef std::stringstream		tstringstream;
	#define tcin std::cin
#endif

#endif // _OSCOMPAT_H_
