/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for Alarm Data Source Configurator
*/

#pragma once

#include "IDsConfigurator.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{


/**
	This interface represents Configurator for Data Source
*/
class IDsConfiguratorAlarm : public IDsConfigurator
{
public:

	virtual int ConfigureFilters(TCHAR* szCfgInString, TCHAR** pszCfgOutString) = 0;
	/**<
		@brief Open filter configuration UI. With help of this UI it will be possible
		       to configure custom filters in the DA or HDA Alarm server, that can be used in studio

		@note DestroyString() must be called after cfg string is copied

		@param[in] szCfgInString Pointer to null terminated configuration string
		                         saved from previous configuration, or NULL

	   @param[out] pszCfgOutString Pointer to pointer to be filled with allocated 
		                            inside configuration null terminated string.
										    This string is a result of configuration made
										    with help of configuration UI. After this call
											 DestroyCfgString() has to be called to destroy string

		@return Error code, if PLUGIN_REINIT_REQUIRED is returned the framework must
		        call Shut() and Init() with new configuration string.
	*/
};

}

/**
	@}
*/

#pragma pack()