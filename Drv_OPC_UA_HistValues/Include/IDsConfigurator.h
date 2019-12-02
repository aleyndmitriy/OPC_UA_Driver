/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for Data Source Configurator
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


/**
	This interface represents Configurator for Data Source
*/
class IDsConfigurator : public IExtensible
{
public:

	virtual int Configure(const TCHAR* szCfgInString, TCHAR** pszCfgOutString) = 0;
	/**<
		@brief Open configuration UI. Configuration string that retrieved
		       from this UI will be used for initialization of Data Source Server
		@note DestroyString() has to be called after

		@param[in] szCfgInString Pointer to null terminated configuration string
		                         saved from previous configuration, or NULL

	   @param[out] pszCfgOutString Pointer to pointer to be filled with allocated 
		                            inside configuration null terminated string.
										    This string is a result of configuration made
										    with help of configuration UI.

		@return Error code, if PLUGIN_REINIT_REQUIRED is returned the framework must
		        call Shut() and Init() with new configuration string.
	*/

	virtual int DestroyString(TCHAR* szCfgString) = 0;
	/**<
		@brief Free allocated configuration string returned from Configure method

		@param[in] szCfgString Pointer that was received from Configure() method

		@return Error code
	*/

	virtual void SetOwnerWnd(void* pOwnerWnd){};
};

}

/**
	@}
*/

#pragma pack()