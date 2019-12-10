/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief AddressComponent interface
*/

#pragma once

#include "OdsCoreLib.h"
#include <tchar.h>

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
	AddressComponentHelper class to simplify work
*/

class ODS_CORE_LIB_EXP AddressComponent
{
	struct AddressComponentBody;

public:

	AddressComponent();
	~AddressComponent();
	AddressComponent(const AddressComponent& rOther);
	AddressComponent& operator = (const AddressComponent& rOther); 

	/**
		@brief Return name of the component, value will be allocated inside
		       call DestroyString() after

		@param[out] pszValue Pointer to pointer to be filled with value

		@return Error code
	*/
	int GetName(TCHAR** pszValue) const;

	/**
		@brief Return value of the component, value will be allocated inside

		@param[out] pszValue Pointer to pointer to be filled with value

		@return Error code
	*/
	int GetValue(TCHAR** pszValue) const;

	/**
		@brief Destroy allocated value

		@param[in] szValue Pointer to value retrieved from Get methods
	*/
	int DestroyString(TCHAR* szValue) const;

	/**
		@brief Set name for the component. It will clear the previous value

		@param[in] szValue Pointer to value to be set

		@return VOID
	*/
	void SetName(const TCHAR* szValue);

	/**
		@brief Set value for the component. It will clear the previous value

		@param[in] szValue Pointer to value to be set

		@return VOID
	*/
	void SetValue(const TCHAR* szValue);

private:

	AddressComponentBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()