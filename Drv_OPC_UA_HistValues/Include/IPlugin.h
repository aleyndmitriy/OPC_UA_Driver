/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief Interfaces for plugin classes.
	Author: 
	Version: 4.0
	Date: 2010.09
*/

#pragma once

#include "OdsIID.h"
#include "IExtensible.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk SDK
	@{
*/

namespace ODS
{

class IPropertySet;
class IPluginHost;

class IPluginObj : public IExtensible
{
public:
	virtual ~IPluginObj(){};

	/**
		@brief Attach plugin to the framework. This is the first
		       operation which is called on plugin object after creation

		@param[in] pHost Pointer to plugin host

		@return Error code
	*/
	virtual int Attach(const IPluginHost* pHost) = 0;

	/**
		@brief Detach plugin from framework. This is the last operation
		       on the plugin. It's called before destroying

		@return Error code
	*/
	virtual int Detach() = 0;

	/**
		@brief Retrieve property set of the plugin

		@return NULL or valid pointer to IPropertySet interface
	*/
	virtual IPropertySet* GetPropertySet() = 0;
};

}

/**
	@brief This is a prototype of the function that must be implemented in 
	       a DLL that provides plugin objects. Loader will look for this entry point name.
			 In this function plugin dll must register all objects that plugin can provide
			 to upper layer. This registration is performed with help of method of IPluginHost
			 interface

	@param[in] pParam Pointer to some parameters that will be passed back on registration
	@param[in] pPluginHost Pointer to plugin host that will be used for registration

	@return Error code

*/
//extern "C" __declspec(dllexport) int InitPlugin(void* pParam, IPluginHost* pPluginHost);

/**
	@brief This is a prototype of the function that must be implemented in a DLL
	       that provides plugin objects. Loader will look for this entry point name.
			 In this function plugin dll must clean up all resources allocated inside

	@return Error code

*/
//extern "C" __declspec(dllexport) int ShutPlugin();

/**
	@}
*/

#pragma pack()