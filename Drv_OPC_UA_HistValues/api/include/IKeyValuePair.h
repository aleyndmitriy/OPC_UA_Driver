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

#ifndef IKEYVALUEPAIR_H
#define IKEYVALUEPAIR_H

#include "KeyValuePairStruct.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The interface for the KeyValuePair data type.
	*
	* A KeyValuePair is used to specify a value for a specific key.
	* The key is defined as a QualifiedName and the value is a Value, i.e. a variant. */
	class TBC_EXPORT IKeyValuePair
	{
	public:
		/*! Destructor */
		virtual ~IKeyValuePair(){};

		/*! Sets the key member for the KeyValuePair */
		virtual EnumStatusCode setKey(const IQualifiedName* key) = 0;
		/*! @overload */
		virtual EnumStatusCode setKey(const QualifiedName& key) = 0;
		/*! Gets the key member of the KeyValuePair */
		virtual const IQualifiedName* getKey() const = 0;

		/*! Sets the value member for the KeyValuePair */
		virtual EnumStatusCode setValue(const IValue* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setValue(const Value& value) = 0;
		/*! Gets the value member of the KeyValuePair */
		virtual const IValue* getValue() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IKeyValuePair* other) const = 0;
		/*! @overload */
		virtual int compare(const IKeyValuePair& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IKeyValuePair& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IKeyValuePair& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IKeyValuePair* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IKeyValuePair& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IKeyValuePair
} // end namespace

#endif
