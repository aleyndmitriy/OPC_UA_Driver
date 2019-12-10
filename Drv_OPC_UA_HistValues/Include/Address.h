/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief ItemAddress interface
*/

#pragma once

#include <windows.h>
#include <tchar.h>

#include "OdsCoreLib.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class AddressComponent;

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	Helper class to simplify work
*/

class ODS_CORE_LIB_EXP ItemAddress
{
	struct ItemAddressBody;

public:

	static const TCHAR SEPARATOR = _T('/');

	ItemAddress();
	~ItemAddress();
	ItemAddress(const ItemAddress& rOther);
	ItemAddress& operator = (const ItemAddress& rOther);


	
	int GetAddress(AddressComponent** ppAddress, int* pnCount, int* pnIndex) const;
	/**<
		@brief Retrieve address, address is an array of ItemAddressComponent
		       it will be allocated inside

		@param[out] ppAddress Pointer to pointer to be filled with allocated array
		@param[out] pnCount Pointer to variable to be filled with number of components
		@param[out] pnIndex Pointer where to store index of item in case of array

		@return Error code
	*/

	
	int DestroyAddress(AddressComponent* pAddress, int nCount) const;
	/**<
		@brief Destroy allocated array address

		@param[in] pAddress Pointer to value retrieved from GetAddress()
		@param[in] nCount Number of components retrieved from GetAddress()

		@return Error code
	*/

	
	void SetAddress(const AddressComponent* pAddress, int nCount, int nIndex);
	/**<
		@brief Set address

		@param[in] pAddress Pointer to array to be set
		@param[in] nCount Number of components in array
		@param[in] nIndex Index of item in case of array

		@return VOID
	*/

	void SetPlainAddress(const TCHAR* szPlainAddress);
	/**<
		@brief Set plain address which is a null terminated string with separator
		       with escape sequence ( / in the name is // )

		@param[in] szPlainAddress Plain address

		@return void
	*/

	int GetPlainAddress(TCHAR** pszPlainAddress);
	/**<
		@brief Retrieve Plain Address which is a null terminated string with separator
		       with escape sequence ( / in the name is // )

	   @param[out] pszPlainAddress Allocated inside null terminated string

		@return Error code
	*/

	int DestroyString(TCHAR* szPlainAddress) ;
	/**<
		@brief Destroy allocated inside null terminated string

		@param[in] szPlainAddress String to destroy

		@return Error code
	*/

	bool IsEqual(const ItemAddress& rOther);
	/**<
		@brief Return true if addresses are equal

		@param[in] rOther Reference to object to check with

		@return true if objects are equal
	*/

	bool IsEqualNoCase(const ItemAddress& rOther);
	/**<
		@brief Return true if addresses are equal, use no case compare

		@param[in] rOther Reference to object to check with

		@return true if objects are equal
	*/

private:

	ItemAddressBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()