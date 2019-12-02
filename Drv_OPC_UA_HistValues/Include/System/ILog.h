/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for Logging subsystem
*/

#pragma once

#include <windows.h>
#include <tchar.h>

#include "IExtensible.h"

namespace ODS
{

namespace System
{

/**
	This is an interface for Logging subsystem
*/
class ILog : public IExtensible
{
public:

	struct Level
	{
		static const int LOG_NORMAL = 2; // level on which the message will be shown
		static const int LOG_DEBUG  = 3;
	};

	struct MsgType
	{
		static const int INFO = 0; // type of the message , it will be prefixed with "Info"
		static const int WARN = 1; // type of the message , it will be prefixed with "Warning"
		static const int ERR  = 2; // type of the message , it will be prefixed with "Error"
	};

	
	virtual void Write(int nLevel, int msgType, const TCHAR* szFormat, ...) = 0;
	/**<
		@brief Write message with specified level and message type, most flexible way
	*/

	// These methods are used with predefined message type and level, to simplify usage

	virtual void WriteInfo(const TCHAR* szFormat, ...) = 0;
	/**<
		@brief write message INFO on NORMAL level
	*/

	
	virtual void WriteInfoDebug(const TCHAR* szFormat, ...) = 0;
	/**
		@brief write message INFO on DEBUG level
	*/

	
	virtual void WriteError(const TCHAR* szFormat, ...) = 0;
	/**<
		@brief write message ERROR on NORMAL level
	*/

	
	virtual void WriteErrorDebug(const TCHAR* szFormat, ...) = 0;
	/**<
		@brief write message ERROR on DEBUG level
	*/

	
	virtual void WriteWarning(const TCHAR* szFormat, ...) = 0;
	/**<
		@brief write message WARNING on NORMAL level
	*/

	
	virtual void WriteWarningDebug(const TCHAR* szFormat, ...) = 0;
	/**<
		@brief write message WARNING on DEBUG level
	*/
};

/**
Example:

	ODS::System::IAppEnv* pAppEnv = ODS::System::GetAppEnv();
	if(pAppEnv)
	{
		ODS::System::ILog* pLog = pAppEnv->GetInterface(IID_LOG);
		if(pLog)
		{
			// save pointer somewhere for future usage
		}
	}

	// usage in some place

	pLog->WriteInfo(_T("MyClass, Operation failed, rc = %d"), rc);


*/

}} // namespace