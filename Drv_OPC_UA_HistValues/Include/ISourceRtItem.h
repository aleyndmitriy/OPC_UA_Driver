/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interface for real time Item data source. This is the object type that can be created from
	Drv_XYZ_RtItem.dll
*/

#pragma once

#include "IDataSource.h"


#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class IServerRtItem;
class IBrowserItem;

/**
*/
class ISourceRtItem : public IDataSource
{
public:

	virtual IDsConfigurator* GetConfigurator() = 0;
	/**<
		@brief Retrieve interface to configurator

		@return Pointer to interface
	*/

	virtual IServerRtItem* GetServer() = 0;
	/**<
		@brief Retrieve interface to server for data exchange operations

		@return Pointer to interface
	*/

	
	virtual IBrowserItem* GetBrowser() = 0;
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