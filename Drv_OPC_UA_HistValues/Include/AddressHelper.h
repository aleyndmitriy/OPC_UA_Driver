/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Address Helper class interface
*/

#pragma once

#include <vector>
#include "OdsCoreLib.h"
#include "OdsString.h"


#pragma pack(8)

namespace ODS
{

class ItemAddress;
class AddressComponent;

/**
	This class can be used to simplify work with Address class.
	Use this class if you build your module with ODS build settings
*/
class ODS_CORE_LIB_EXP AddressHelper
{
public:

	AddressHelper(ItemAddress* pAddress);
	AddressHelper(const ItemAddress* pAddress);
	~AddressHelper();

	int GetAddress(std::vector<AddressComponent>* pAddress, int* pnIndex) const;
	/**<
	@brief Retrieve address, address is a list of ItemAddressComponent

	@param[out] pAddress Pointer to list to fill
	@param[out] pnIndex Pointer where to store index of item in case of array, can be NULL

	@return Error code
	*/

	int GetAddressAsList(std::vector<std::pair<ODS::OdsString, ODS::OdsString>>* pList, int* pnIndex) const;

	void SetAddress(const std::vector<AddressComponent>* pAddress, int nIndex);
	/**<
	@brief Set address

	@param[in] pAddress Pointer to list to set
	@param[in] nIndex Index of item in case of array

	@return VOID
	*/

	void SetAddress(const std::vector<AddressComponent>& rAddress, int nIndex);

	void SetPlainAddress(const OdsString* pPlainAddress);
	/**<
	@brief Set plain address which is a string with separator
	with escape sequence ( / in the name is // )

	@param[in] pPlainAddress Plain address

	@return void
	*/

	void SetPlainAddress(const OdsString& rPlainAddress);

	static void SetPlainAddress(const OdsString& rPlainAddress, ODS::ItemAddress* pAddress);

	OdsString GetPlainAddress();
	/**<
	@brief Retrieve Plain Address which is a string with separator
	with escape sequence ( / in the name is // )

	@return Plain address
	*/

	static ODS::OdsString GetPlainAddress(const ODS::ItemAddress& rAddress);

	BOOL GetPlainAddressWithName(ODS::OdsString* pItemName, ODS::OdsString* pItemAddress);

	AddressHelper& AddAddressComponent(const AddressComponent& rAddrComp);
	/**<
	@brief Add address component to address
	@param[in] rAddrComp Address component to add
	@return Error code
	*/

	AddressHelper& AddAddressComponent(const OdsString& rValue, const OdsString& rName = OdsString(_T("")));
	/**<
	@brief Add address component to address
	@param[in] rValue Value of component
	@param[in] rName Name of component
	@return Error code
	*/

	void ClearAddress();

	int FindAddressComponent(const OdsString& rName, AddressComponent* pAddrComp);

	int FindAddressComponent(int nIndex, AddressComponent* pAddrComp);

	int RemoveAddressComponent(const ODS::OdsString& rNameComponent);

	static ODS::OdsString DoEscape(const ODS::OdsString& rStr);

	static void SplitPlainAddress(const ODS::OdsString& rAddress,
		std::vector<std::pair<ODS::OdsString, ODS::OdsString>>* pList);

private:

	AddressHelper(const AddressHelper& rOther);
	AddressHelper& operator = (const AddressHelper& rOther);

	ItemAddress* m_pAddress;
};

}

#pragma pack()