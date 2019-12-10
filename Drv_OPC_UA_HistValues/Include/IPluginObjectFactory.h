/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	IPluginObjectFactory class interface that has to be implemented in 
	a dll which implements plugin objects
*/

#pragma once

#include <windows.h>
#include <tchar.h>

#include "IExtensible.h"


namespace ODS
{

class IPluginObj;

/**
	This factory will be used to create plugin objects from 
	loaded dlls. There are 4 types of data sources:
	DA Item, DA Alarm, HDA Item, HDA Alarm. Dll for each data
	source will have such factory. Factory will be used to create
	plugin objects.
*/
class IPluginObjectFactory : public IExtensible
{
public:
	
	virtual int CreateObject(const TCHAR* szObjKey, void* pObjCreationParam, IPluginObj** ppPluginObj) = 0;
	/**<
		@brief Factory method that creates plugin object by specific id.
		       Id is provided during plugin registration.

		@param[in] szObjKey Object key to be created, key was provided during plugin object registration
		@param[in] pObjCreationParam Parameter that was provided during plugin object registration
		@param[out] ppPluginObj Pointer to pointer to be filled on output

		@return Error code
	*/

	
	virtual int DestroyObject(IPluginObj* pPluginObj) = 0;
	/**<
		@brief Destroy plugin object that was created

		@param[in] pPluginObj Pointer to created plugin

		@return Error code
	*/
};

}