/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file  BrowseItem.h
	@brief BrowseItem interface
*/

#pragma once

#include <tchar.h>

#include "OdsCoreLib.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class ItemAddress;

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	Helper class to simplify work
*/
class ODS_CORE_LIB_EXP BrowseItem
{
	struct BrowseItemBody;

public:

	static const int TYPE_ITEM        = 1;
	static const int TYPE_BRANCH      = 2;
	static const int TYPE_BRANCH_ITEM = 3;

	BrowseItem();
	~BrowseItem();
	BrowseItem(const BrowseItem& rOther);
	BrowseItem& operator = (const BrowseItem& rOther);

	
	int GetHierarchyType() const;
	/**<
		@brief Retrieve hierarchy type of browse item

		@return type (TYPE_ITEM, TYPE_BRANCH, etc)
	*/

	
	int GetAddress(ItemAddress* pAddress) const;
	/**<
		@brief Retrieve item address

		@param[out] pAddress Pointer to be filled on output

		@return Error code
	*/

	int GetName(TCHAR** pszValue) const;

	
	int GetDescription(TCHAR** pszValue) const;
	/**<
		@brief Retrieve description, value will be allocated inside
		       Call DestroyString() method after usage of this method

		@param[out] pszValue Pointer to pointer to be filled with value

		@return Error code
	*/

	
	int DestroyString(TCHAR* szValue) const;
	/**<
		@brief Destroy allocated string

		@param[in] szValue Pointer to allocated string

		@return Error code
	*/

	
	int GetValueType() const;
	/**<
		@brief Retrieve value type of the item, see ItemValue

		@return type
	*/

	
	void SetHierarchyType(int nType);
	/**<
		@brief Set hierarchy type

		@param[in] nType Value to be set

		@return void
	*/

	
	void SetAddress(const ItemAddress* pAddress);
	/**<
		@brief Set address

		@param[in] pAddress Value to be set

		@return void
	*/

	void SetAddress(const ItemAddress& rAddress);
	/**<
		@brief Set address

		@param[in] rAddress Address to be set

		@return void
	*/

	void SetName(const TCHAR* szValue);

	
	void SetDescription(const TCHAR* szValue);
	/**<
		@brief Set description

		@param[in] szValue Value to be set

		@return void
	*/

	
	void SetValueType(int nType);
	/**<
		@brief Set value type, see ItemValue

		@param[in] nType Value to be set

		@return void
	*/

private:

	BrowseItemBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()