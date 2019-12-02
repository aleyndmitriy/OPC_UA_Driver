/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interface for real time Alarm data source. This is the object type that can be created from
	Drv_XYZ_RtAlarm.dll
*/

#pragma once


#include "IDataSource.h"
#include "IBrowserAlarm.h"
#include "IServerRtAlarm.h"
#include "IDsConfiguratorAlarm.h"

#pragma pack(8)

/**
   @addtogroup ods_sdk
   @{
*/

namespace ODS
{

class IServerRtAlarm;
class IBrowserAlarm;
class IDsConfiguratorAlarm;

/**
	This interface represents DA alarm data source. Objects of this type are
	registered from Drv_XYZ_RtAlarm.dll
*/
class ISourceRtAlarm : public IDataSource
{
public:

	/** flag of the browser filter configuration ability UI*/
	static const int PROPERTY_ID_HAS_FILTER_CFG_UI = 11;

	/** flag of external filter supporting*/
	static const int PROPERTY_ID_EXTERNAL_FILTER_SUPPORT = 12;

	/** flag of custom filter supporting*/
	static const int PROPERTY_ID_CUSTOM_FILTER_SUPPORT = 13;


	virtual IDsConfiguratorAlarm* GetConfigurator() = 0;
	/**<
		@brief Retrieve interface to configurator

		@return Pointer to interface
	*/

	virtual IServerRtAlarm* GetServer() = 0;
	/**<
		@brief Retrieve interface to server for data exchange operations

		@return Pointer to interface
	*/

	virtual IBrowserAlarm* GetBrowser() = 0;
	/**<
		@brief Retrieve interface to browser to browse what is inside a data source

		@return Pointer to interface
	*/
};

}

/**
	@}
*/

#pragma pack()