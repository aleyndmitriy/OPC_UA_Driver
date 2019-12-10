/*	Copyright (c) 2010 Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief Structures for alarm interface classes.
*/

#pragma once

#include "OdsCoreLib.h"
#include <windows.h>

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class Property;

class ODS_CORE_LIB_EXP Alarm
{
	struct AlarmBody;

public:

	Alarm();
   ~Alarm();
	Alarm(const Alarm& rOther);
	Alarm& operator = (const Alarm& rOther);

	int GetPropertyList(Property** ppList, int* pnCount) const;
	/**<
		@brief Retrieve list of properties for alarm, list is allocated inside

		@param[out] ppList Pointer to be filled with allocated array of properties
		@param[out] pnCount Pointer to be filled with number of elements

		@return Error code
	*/

	int DestroyPropertyList(Property* pList, int nCount) const;
	/**<
		@brief Destroy allocated list

		@param[in] pList Allocated list from GetPropertyList()
		@param[in] nCount Number of elements

		@return Error code
	*/

	int SetPropertyList(const Property* pList, int nCount);
	/**<
		@brief Set property list for alarm

		@param[in] pList Pointer to property array
		@param[in] nCount Number of elements

		@return Error code
	*/

	const ODS::Property* GetPropertyById(ULONG ulPropId) const;

private:
	AlarmBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()