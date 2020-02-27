/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file  TimeUtils.h
	@brief TimeUtils class interface - time conversions toolbox
*/

#pragma once

#include <windows.h>

#include "OdsCoreLib.h"
#include "OdsString.h"

namespace ODS
{

namespace TimeUtils
{

ODS_CORE_LIB_EXP void InitSystemTime(SYSTEMTIME* pSysTime);

ODS_CORE_LIB_EXP int ConvertSystemTimeToDateMsec(const SYSTEMTIME& rSysTime, double* pDateMsec, int nMilliResolution = 0);

ODS_CORE_LIB_EXP int ConvertDateMsecToSystemTime(double dDateMsec, SYSTEMTIME* pSysTime);

/**
   @brief Add milliseconds to systemtime. It can be negative number for substruction
   @note System time has to be provided as UTC
*/
ODS_CORE_LIB_EXP int SystemTimeAdd(const SYSTEMTIME& rSysTime, SYSTEMTIME* pChanged, LONG64 l64Milli);


/**
   @brief Convert local time to utc time
*/
ODS_CORE_LIB_EXP int SysTimeLocalToUtc(const SYSTEMTIME& rLocal, SYSTEMTIME* pUtc);

/**
   @brief Convert utc time to local time
*/
ODS_CORE_LIB_EXP int SysTimeUtcToLocal(const SYSTEMTIME& rUtc, SYSTEMTIME* pLocal);

/**
   @brief Compare two SYSTEMTIME structures
   @return 0 if equal, less then 0 if first is less, greater then 0 if first is greater
*/
ODS_CORE_LIB_EXP int SysTimeCompare(const SYSTEMTIME& rFirst, const SYSTEMTIME& rSecond);

/**
   @brief Convert system time which is local time to number of millieseconds since 1970 UTC
   @param [in] rSysTime System time to convert
   @param [out] pul64Millisec Milliseconds since 1970-01-01 00:00:00 UTC
   @param [in] nDstOn 1 - DST is in effect, 0 - DST is not active, -1 - DST is not defined
   @return error code
*/
ODS_CORE_LIB_EXP int SysTimeLocalToUlong64(const SYSTEMTIME& rSysTime, ULONG64* pul64Millisec, int nDstOn = -1);

/**
   @brief Convert system time which is UTC time to number of millieseconds since 1970 UTC
   @return error code
*/
ODS_CORE_LIB_EXP int SysTimeUtcToUlong64(const SYSTEMTIME& rSysTime, ULONG64* pul64Millisec);

/**
	@brief Convert ULONG64 with milliseconds to system time UTC
	@param [in] ul64Millisec Milliseconds since 1970-01-01 00:00:00 UTC
	@param [out] pSysTime SystemTime structure to be filled
	@param [out] pnDstOn This parameter is ignored and not used because the time is UTC
	@return error code
*/
ODS_CORE_LIB_EXP int Ulong64ToSysTimeUtc(ULONG64 ul64Millisec, SYSTEMTIME* pSysTime, int* pnDstOn = nullptr);

/**
   @brief Convert ULONG64 with milliseconds to system time Local
   @param [in] ul64Millisec Milliseconds since 1970-01-01 00:00:00 UTC
   @param [out] pSysTime SystemTime structure to be filled
   @param [out] pnDstOn 1 - DST is in effect, 0 - DST is not active, -1 - DST is not defined
   @return error code
*/
ODS_CORE_LIB_EXP int Ulong64ToSysTimeLocal(ULONG64 ul64Millisec, SYSTEMTIME* pSysTime, int* pnDstOn = nullptr);

/**
   @brief Retrieve ISO time string
*/
ODS_CORE_LIB_EXP OdsString CreateIsoTimeStringFromSysTime(const SYSTEMTIME& rSysTime, bool bWithMillisec = false);

/**
   @brief Retrieve system time from ISO time string
*/
ODS_CORE_LIB_EXP int GetSysTimeFromIsoTimeString(LPCTSTR szTimeString, SYSTEMTIME* pSysTime);

ODS_CORE_LIB_EXP int SysTimeDiff(const SYSTEMTIME& rFirst, const SYSTEMTIME& rSecond, LONG64* pl64Milli);


}} // namespace