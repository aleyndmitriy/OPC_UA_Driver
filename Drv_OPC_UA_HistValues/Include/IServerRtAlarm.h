/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for RT Alarm server class
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

class AlarmFilter;
class ICallbackClientRtAlarm;

/**
	This interface represents RT Alarm server. The object with this interface
	has to be supported in Drv_XYZ_RtAlarm.dll which is a driver for RT alarms
*/
class IServerRtAlarm : public IDsServer
{
public:

	virtual int RegisterCallback(ICallbackClientRtAlarm* pCallback) = 0;
	/**<
		@brief Register callback that will be called

		@param[in] pCallback Pointer to callback
		
		@return Error code
	*/

	virtual int Subscribe(ULONG ulSubscriptionId, VOID* pParam, AlarmFilter** ppFilterList, int nCount) = 0;
	/**<
		@brief Subscribe for alarm messages
		
		@param[in] ulSubscriptionId Id for subscription
		@param[in] pParam Parameter to be passed to callback
		@param[in] pFilterList List of pointers to alarm filters for subscription
		@param[in] nCount Number of filters in the list
		
		@return Error code
	*/

	virtual int Unsubscribe(ULONG ulSubscriptionId) = 0;

};

}

/**
	@}
*/

#pragma pack()