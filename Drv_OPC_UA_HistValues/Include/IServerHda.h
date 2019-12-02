/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for HDA server class
*/


#pragma once

#include "IDsServer.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class HdaCommand;
class HdaCommandResult;

/**
	This interface represents HDA server for Item and Alarm history. The object with this interface
	has to be supported in Drv_XYZ_HdaAlarm.dll which is a driver for HDA alarms
	and in the Drv_XYZ_HdaItem.dll which is a driver for HDA items
*/
class IServerHda : public IDsServer
{
public:

	virtual int IsHdaFunctionSupported(int nFuncType) = 0;
	/**<
		@brief Retrieve info if specific function is supported in the server

		@param[in] nFuncType Type of the command to check

		@return 0 if function is not supported
	*/

	virtual int Execute(HdaCommand* pCommand, HdaCommandResult** ppResult) = 0;
	/**<
		@brief Start execution of provided command and retrieve result

		@param[in] pCommand Pointer to command object

		@param[out] ppResult Pointer to result to be filled on output

		@return Error code
	*/

	virtual int DestroyResult(HdaCommandResult* pResult) = 0;
	/**<
		@brief Free all allocated resources

		@param[in] pResult Pointer to received result

		@return Error code
	*/
};

}

/**
	@}
*/

#pragma pack()