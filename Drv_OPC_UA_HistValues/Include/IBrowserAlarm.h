/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for RT and HDA Alarm browser class
*/

#pragma once

#include "IDsBrowser.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class PropertyInfo;

/**
	This class represents Alarm browser. The object that implements
	this interface has to be supported in Drv_XYZ_RtAlarm.dll and in Drv_XYZ_HdaAlarm.dll
	drivers for DA and HDA alarms 
*/
class IBrowserAlarm : public IDsBrowser
{
public:

	virtual int GetExternalFilterList(TCHAR*** ppszFilterList, ULONG* pulCount) = 0;
	/**<
		@brief Retrieve list of external filters
				 DestroyFilterList() has to be called after

		@param[out] ppszFilterList Pointer to list of pointers to external filter names,
		            list will be allocated inside

		@param[out] pulCount Pointer to variable to be filled with number of names in the list

		@return Error code
	*/

	virtual int GetFilterList(TCHAR*** ppszFilterList, ULONG* pulCount) = 0;
	/**<
		@brief Retrieve list of custom filters
				 DestroyFilterList() has to be called after

		@param[out] ppszFilterList Pointer to list of pointers to custom filter names,
		                           list will be allocated inside

		@param[out] pulCount Pointer to variable to be filled with number of names in the list

		@return Error code
	*/

	virtual int DestroyFilterList(TCHAR** ppFilterList, ULONG ulCount) = 0;
	/**<
		@brief Free allocated list of filters

		@param[in] ppFilterList List of filters

		@param[in] ulCount Number of filters

		@return Error code
	*/

	virtual int GetAlarmPropertyInfoList(PropertyInfo** ppPropertyInfoList, ULONG* pulCount) = 0;
	/**<
		@brief Retrieve list of alarm properties that can be retrieved from IServerDaAlarm
				 DestroyAlarmPropertyInfoList() has to be called after

		@param[out] ppPropertyInfoList Pointer to array of PropertyInfo, array will be allocated inside

		@param[out] pulCount Pointer to variable to be filled with number of elements in the list

		@return Error code
	*/

	virtual int DestroyAlarmPropertyInfoList(PropertyInfo* pPropertyInfoList, ULONG ulCount) = 0;
	/**<
		@brief Free list of alarm properties allocated inside

		@param[in] pPropertyInfoList List of names retrieved from GetAlarmPropertyInfoList()

		@param[in] ulCount Number retrieved from GetAlarmPropertyInfoList()

		@return Error code
	*/
};

}

/**
	@}
*/

#pragma pack()