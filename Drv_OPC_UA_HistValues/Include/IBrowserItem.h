/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file IBrowserItem.h
	@brief Interfaces for Item browser class
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

class BrowseItem;
class ItemAddress;

static const TCHAR COMPONENT_NAME_OLD[] = _T("name_old");

static const TCHAR COMPONENT_ADDRESS_OLD[] = _T("address_old");

/**
	This interface represents Item browser for HDA Items and RT Items.
	The object that implements	this interface has to be supported in
	Drv_XYZ_HdaItem.dll which is a driver for HDA items and in
	Drv_XYZ_RtItem.dll which is a driver for RT Items
*/
class IBrowserItem : public IDsBrowser
{
public:

   static const int IID_ITEM_MANAGER = 100; // this interface can be retrieved from Browser with help of GetInterface method
                                            // if Browser does not support this interface GetInterface method will return 0

	virtual int GetBrowseItemList(const ItemAddress* pAddress, BrowseItem** ppList, ULONG* pulCount) = 0;
	/**<
		@brief Retrieve list of browse items

		@param[in] pAddress Pointer to address of the item, NULL for root level

		@param[out] ppList Pointer to pointer will be filled with array allocated inside

		@param[out] pulCount Pointer to the variable to be filled with number of browse items in the list

		@return Error code
	*/

	virtual int DestroyBrowseItemList(BrowseItem* pList, ULONG ulCount) = 0;
	/**<
		@brief Destroy allocated list of browse items

		@param[in] pList Pointer retrieved from GetBrowseItemList()

		@param[in] ulCount Number of the browse items in the list, retrieved from GetBrowseItemList()
	*/
};

}

/**
	@}
*/

#pragma pack()