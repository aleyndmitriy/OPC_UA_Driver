/*
	Copyright (c) 2003-2010 Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file PropertyInfo class interface
*/

#pragma once

#include <windows.h>
#include <tchar.h>
#include "OdsCoreLib.h"

namespace ODS
{

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	PropertyInfoHelper class to simplify work
*/
class ODS_CORE_LIB_EXP PropertyInfo
{
	struct PropertyInfoBody;

public:

	PropertyInfo();
	~PropertyInfo();

	PropertyInfo(const PropertyInfo& rOther);
	PropertyInfo& operator = (const PropertyInfo& rOther);

	/**
		 @brief Retrieve Id of the property

		 @return Property Id
	*/
	ULONG GetId() const;

	/**
		@brief Retrieve name of the property, buffer will be allocated inside
				 Call DestroyString() after usage of this method

		@param[out] pszName Pointer to buffer to be filled on output

		@return Error code
	*/
	int GetName(TCHAR** pszName) const;

	/**
		@brief Destroy string allocated inside

		@param[in] szValue Pointer to buffer

		@return Error code
	*/
	int DestroyString(TCHAR* szValue) const;

	/**
		@brief Retrieve value type of the property

		@param[out] pVarType In case value type is PROP_VALUE_TYPE_VAR, this variable
		                     will be filled with variant type
		@return Value type, see Property.h, can be PROP_VALUE_TYPE_EMPTY,
		        PROP_VALUE_TYPE_STR, PROP_VALUE_TYPE_VAR
	*/
	ULONG GetValueType(VARTYPE* pVarType) const;

	/**
		@brief Retrieve boolean value for specific flag

		@param[in] ulFlagId ID of the flag to get value for

		@return Value for flag, true or false
	*/
	bool GetFlag(ULONG ulFlagId) const;

	/**
		@brief Set property ID in property info

		@param[in] ulId ID of the property

		@return VOID
 	*/
	void SetId(ULONG ulId);

	/**
		@brief Set name of the property into property info

		@param[in] szName Pointer to null terminated buffer

		@return VOID
	*/
	void SetName(const TCHAR* szName);

	/**
		@brief Set value type

		@param[in] ulValueType Value type
		@param[in] varType Variant type in case of value type is PROP_VALUE_TYPE_VAR

		@return VOID
	*/
	void SetValueType(ULONG ulValueType, VARTYPE varType);

	/**
		@brief Set boolean value for specific flag

		@param[in] ulFlagId ID of the flag to set value for
		@param[in] bValue Value to be set, true or false

		@return VOID
	*/
	void SetFlag(ULONG ulFlagId, bool bValue);

private:
	
	PropertyInfoBody* m_pBody;
};

}