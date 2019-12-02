/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file Property class interface
*/

#pragma once

#include <oaidl.h>
#include <tchar.h>
#include "OdsCoreLib.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	PropertyHelper class to simplify work
*/
class ODS_CORE_LIB_EXP Property
{
	struct PropertyBody;

public:

	static const ULONG PROP_VALUE_TYPE_EMPTY    = 0;
	static const ULONG PROP_VALUE_TYPE_STR      = 1;
	static const ULONG PROP_VALUE_TYPE_VAR      = 2;

	static const ULONG PROP_FLAG_ACCESS_READ_ONLY  = 0;

	Property();
	~Property();
	Property(const Property& rOther);
	Property& operator = (const Property& rOther);

	
	ULONG GetId() const;
	/**<
		@brief Retrive ID of the property

		@return Id of the property
	*/

	int GetName(TCHAR** pszName) const;
	/**<
		@brief Retrieve name of the property, buffer will be allocated inside
		       Call DestroyString() after using this method

		@param[out] pszName Pointer to pointer that will be filled by allocated buffer

		@return Error code
	*/
	
	int DestroyString(TCHAR* szString) const;
	/**<
		@brief Destroy string allocated inside

		@param[in] szString Pointer to allocated buffer

		@return Error code
	*/
	
	ULONG GetValueType(VARTYPE* pVarType) const;
	/**<
		@brief Retrieve value type of the property

		@param[out] pVarType In case value type is PROP_VALUE_TYPE_VAR, this variable
		                     will be filled with variant type

		@return Property value type
	*/
	
	int GetStrValue(TCHAR** pszValue) const;
	/**<
		@brief Retrieve string value of the property, buffer will be allocated inside
		       Call DestroyString() after usage of this method

		@param[out] pszValue Pointer to pointer to be filled by buffer allocated inside

		@return Error code
	*/
	
	void GetVarValue(VARIANT* pValue) const;
	/**<
		@brief Return variant value of the property

		@param[out] pValue Pointer to variant to be filled with value

		@return VOID
	*/
	
	bool GetFlag(ULONG ulFlagId) const;
	/**<
		@brief Retrieve boolean value for specific flag

		@param[in] ulFlagId ID of the flag to get value for

		@return Value for flag, true or false
	*/

	
	void SetId(ULONG ulId);
	/**<
		@brief Set property ID

		@param[in] ulId ID of the property

		@return VOID
 	*/
	
	void SetName(const TCHAR* szName);
	/**<
		@brief Set name of the property

		@param[in] szName Pointer to null terminated buffer
	*/

	
	void SetStrValue(const TCHAR* szValue);
	/**<
		@brief Set string value for the property. It will clear the previous value
		       set the string and change the value type to string

		@param[in] szValue Pointer to null terminated buffer

		@return VOID
	*/
	
	void SetVarValue(const VARIANT* pValue);
	/**<
		@brief Set variant value for the property. It will clear the previous value
		       set the variant and change the value type to variant

		@param[in] pValue Pointer to value to be set

		@return VOID
	*/
	
	void SetFlag(ULONG ulFlagId, bool bValue);
	/**<
		@brief Set boolean value for specific flag

		@param[in] ulFlagId ID of the flag to set value for
		@param[in] bValue Value to be set, true or false

		@return VOID
	*/

private:

	PropertyBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()