/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Address Component Helper interface
*/

#pragma once

#include "OdsCoreLib.h"
#include "OdsString.h"

#pragma pack(8)

namespace ODS
{

class AddressComponent;

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	AddressComponentHelper class to simplify work
*/

class ODS_CORE_LIB_EXP AddressComponentHelper
{

public:

	AddressComponentHelper(AddressComponent* pComponent);
	~AddressComponentHelper();

	void AttachComponent(AddressComponent* pComponent);
	
	OdsString GetName() const;
	/**<
		@brief Return name of the component

		@return Name
	*/

	OdsString GetValue() const;
	/**<
		@brief Return value of the component

		@return Value
	*/

	void SetName(const OdsString* pName);
	/**<
		@brief Set name for the component. It will clear the previous value

		@param[in] pName Pointer to name to be set

		@return VOID
	*/

	
	void SetValue(const OdsString* pValue);
	/**<
		@brief Set value for the component. It will clear the previous value

		@param[in] pValue Pointer to value to be set

		@return VOID
	*/

private:

	AddressComponentHelper(const AddressComponentHelper& rOther);
	AddressComponentHelper& operator = (const AddressComponentHelper& rOther); 

	AddressComponent* m_pComponent;
};

}

/**
	@}
*/

#pragma pack()