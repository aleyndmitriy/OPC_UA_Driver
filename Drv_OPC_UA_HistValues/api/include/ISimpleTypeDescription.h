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

#ifndef ISIMPLETYPEDESCRIPTION_H
#define ISIMPLETYPEDESCRIPTION_H

#include "SimpleTypeDescriptionStruct.h"
#include "NodeId.h"
#include "INodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The SimpleTypeDescription data type provides the information for DataTypes derived from built-in DataTypes. */
	class TBC_EXPORT ISimpleTypeDescription
	{
	public:
		/*! Destructor */
		virtual ~ISimpleTypeDescription(){};
		/*! Gets the BaseDataType member of the class */
		virtual const INodeId* getBaseDataType() const = 0;
		/*! Sets the BaseDataType member in the class */
		virtual EnumStatusCode setBaseDataType(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& value) = 0;

		/*! Gets the BuiltInType member of the class */
		virtual OTUInt8 getBuiltInType() const = 0;
		/*! Sets the BuiltInType member in the class */
		virtual void setBuiltInType(const OTUInt8& value) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const ISimpleTypeDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const ISimpleTypeDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISimpleTypeDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISimpleTypeDescription& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISimpleTypeDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISimpleTypeDescription& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISimpleTypeDescription
} // end namespace

#endif
