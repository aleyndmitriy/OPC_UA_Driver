/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interface data source
*/

#pragma once


#include "IPlugin.h"
#include "tchar.h"

#pragma pack(8)

/**
   @addtogroup ods_sdk
   @{
*/

namespace ODS
{

class IDsServer;
class IDsBrowser;
class IDsConfigurator;

/**
	This interface represents data source
*/
class IDataSource : public IPluginObj
{
public:

	/** vendor name, will be seen in UI */
	static const int PROPERTY_ID_VENDOR = 0;

	/** data source name, will be seen in UI */
	static const int PROPERTY_ID_DATA_SOURCE = 1;

	/** data source client name, will be seen in UI */
	static const int PROPERTY_ID_CLIENT_NAME = 2;

	/** description of client, will be seen in UI */
	static const int PROPERTY_ID_DESCRIPTION = 3;

	/** flag of the browser UI configuration ability*/
	static const int PROPERTY_ID_HAS_CONFIGURATION_UI = 4;

	/** flag for special driver with query language */
	static const int PROPERTY_ID_SUPPORT_QUERY = 5;

	virtual IDsConfigurator* GetConfigurator() = 0;
	/**<
		@brief Retrieve configuration interface of the data source

		@return Pointer to interface
	*/

	virtual IDsServer* GetServer() = 0;
	/**<
		@brief Retrieve interface to server for data exchange operations

		@return Pointer to interface
	*/

	
	virtual IDsBrowser* GetBrowser() = 0;
	/**<
		@brief Retrieve interface to browser to browse what is inside a data source

		@return Pointer to interface
	*/

	/**
	@brief Set logical name of the driver instance

	@param[in] szObjName Pointer to the driver name string
	*/
	virtual void SetLogicalName(const TCHAR* szObjName) {};
};

}

/**
	@}
*/

#pragma pack()