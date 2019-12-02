/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief IPropertySet interface
*/

#pragma once

#pragma pack(8)

/**
   @addtogroup ods_sdk
   @{
*/

namespace ODS
{

class Property;
class PropertyInfo;

/**
   Interface that is used to get/set properties
	This interface can cross DLL boundaries with modules
	that can be developed by third party. Plain Old Data
	types are used for this reason
*/
class IPropertySet
{
public:

	virtual ~IPropertySet(){}

	virtual void GetPropertyInfoList(PropertyInfo** ppPropInfoList, ULONG* pulCount) const = 0;
   /**<
		@brief Retrieve list of all property info structures

		@param[out] ppPropInfoList Array of property info. Array is allocated inside
		@param[out] pulCount Pointer to variable to be filled with count

		@return VOID
	*/
	
	virtual void DestroyPropertyInfoList(PropertyInfo* pPropInfoList, ULONG ulCount) const = 0;
   /**<
		@brief Clean the list of property info objects that was allocated inside
		       Must be called by client after calling of GetPropertyInfoList

		@param[in] pPropList Pointer to array that was returned from GetPropertyList()

		@return VOID
	*/

	virtual void GetPropertyList(Property** ppPropList, ULONG* pulCount) const = 0;
   /**<
		@brief Retrieve list of all properties

		@param[out] ppPropList Array of properties. The array is allocated inside
		@param[out] pulCount Pointer to variable to be filled with count

		@return VOID
	*/

	virtual void DestroyPropertyList(Property* pPropList, ULONG ulCount) const = 0;
   /**<
		@brief Destroy the list of properties that was allocated inside
		       Must be called by client after calling of GetPropertyList

		@param[in] pPropList Pointer to array that was returned from GetPropertyList()

		@return VOID
	*/

	virtual INT GetProperty(ULONG ulPropId, Property* pProperty) const = 0;
   /**<
		@brief Retrieve property by id
		@param[in] ulPropId Property Id
		@param[out] ppProperty Pointer to property to be filled

		@return Error code
	*/

	virtual INT GetProperty(const TCHAR* pPropName, Property* pProperty) const = 0;
   /**<
		@brief Retrieve property by name

		@param[in] pPropName Property name to retrieve
		@param[out] Pointer to property to be filled

		@return Error code
	*/

	virtual INT SetProperty(const Property* pProperty) = 0;
   /**<
		@brief Set property data by ID

		@param[in] pProperty Property with data to put in. Id must be filled with correct id
		           of the property where to set data. Search will be done by this Id

		@return Error code
	*/
};

}

/** @} */


#pragma pack()