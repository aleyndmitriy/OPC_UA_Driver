/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2019                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             dataFEED OPC UA C++ Server & Client SDK           *
*                                                                            *
* VERSION                  5.61.0                                            *
*                                                                            *
* DATE                     05.11.2019                                        *
*                                                                            *
*****************************************************************************/

#ifndef IENUMVALUETYPE_H
#define IENUMVALUETYPE_H

#include "EnumValueTypeStruct.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The EnumValueType data type is used to store a human-readable representation of an
	* enumeration in an address space. */
	class IEnumValueType
	{
	public:
#ifdef SOOS_POSIX
		/*! Destructor */
		virtual ~IEnumValueType(){};
#endif
		/*! Sets the Value member in the class
		*
		* @param value		The Integer representation of an Enumeration. */
		virtual void setValue(const OTInt64& value) = 0;
		/*! Returns the integer representation of an enumeration. */
		virtual OTInt64 getValue() const = 0;

		/*! Sets the DisplayName member in the class
		*
		* @param displayName	A human-readable representation of the Value of the Enumeration. */
		virtual EnumStatusCode setDisplayName(const ILocalizedText* displayName) = 0;
		/*! @overload */
		virtual EnumStatusCode setDisplayName(const LocalizedText& displayName) = 0;
		/*! Returns a human-readable representation of the value of the enumeration. */
		virtual const ILocalizedText* getDisplayName() const = 0;

		/*! Sets the Description member in the class
		*
		* @param description	A localized description of the enumeration value.
		*						This field can contain an empty string if no description is available. */
		virtual EnumStatusCode setDescription(const ILocalizedText* description) = 0;
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description) = 0;
		/*! Returns a localized description of the enumeration value. This field can contain an
		* empty string if no description is available. */
		virtual const ILocalizedText* getDescription() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IEnumValueType* other) const = 0;
		/*! @overload */
		virtual int compare(const IEnumValueType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEnumValueType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEnumValueType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEnumValueType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEnumValueType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEnumValueType
} // end namespace

#endif	// IENUMVALUETYPE_H
