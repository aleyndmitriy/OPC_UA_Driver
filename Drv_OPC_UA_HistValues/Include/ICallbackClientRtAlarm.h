/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for Callback of client of RT alarms
*/


#pragma once

#include "IExtensible.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class Alarm;

class ICallbackClientRtAlarm : public IExtensible
{
public:

	virtual int FireAlarm(ULONG ulSubscriptionId, VOID* pParam, Alarm* pAlarm) = 0;
   /**<
      @brief This function is called by RT Alarm server when alarm event occurred

      @param[in] ulSubscriptionId The id of subscription
		@param[in] pParam Parameter that was passed during subscription
      @param[in] pAlarm Pointer to alarm that occurred

      @return Error code
   */
};

}

/**
	@}
*/

#pragma pack()