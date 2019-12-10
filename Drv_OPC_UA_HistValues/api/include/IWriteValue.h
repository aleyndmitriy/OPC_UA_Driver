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

#ifndef IWRITEVALUE_H
#define IWRITEVALUE_H

#include "WriteValueStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! The WriteValue data type is used by the Write service (see Client::Session::write())
	* to specify a node and its attribute to write. */
	class TBC_EXPORT IWriteValue
	{
	public:
		/*! Destructor */
		virtual ~IWriteValue(){};

		/*! Returns the NodeId of the node whose attribute is to be written. */
		virtual const INodeId* getNodeId() const = 0;
		/*! @overload */
		virtual INodeId* getNodeId() = 0;
		/*! Sets the NodeId of the node whose attribute is to be written. */
		virtual void setNodeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setNodeId(const NodeId& value) = 0;

		/*! Returns the identifier of the attribute that is to be written. */
		virtual EnumAttributeId getAttributeId() const = 0;
		/*! Sets the identifier of the attribute that is to be written. */
		virtual void setAttributeId(EnumAttributeId value) = 0;

		/*! Returns the index range that defines which subset of the attribute value is written. */
		virtual const INumericRange* getIndexRange() const = 0;
		/*! Sets the index range that defines which subset of the attribute value is written.
		* This parameter applies only to attribute values of type 'array'.
		* If this parameter is omitted, all elements of the array are included in the range. */
		virtual void setIndexRange(const INumericRange* value) = 0;
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value) = 0;

		/*! Returns the value that is to be written on the attribute of the specified node. */
		virtual const IDataValue* getDataValue() const = 0;
		/*! @overload */
		virtual IDataValue* getDataValue() = 0;
		/*! Sets the value that is to be written on the attribute of the specified node.
		* If the SourceTimestamp or ServerTimestamp of the provided @p value is defined,
		* then a server uses this value. */
		virtual void setDataValue(const IDataValue* value) = 0;
		/*! @overload */
		virtual void setDataValue(const DataValue& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IWriteValue* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IWriteValue& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IWriteValue* other) const = 0;
		/*! @overload */
		virtual int compare(const IWriteValue& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriteValue& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriteValue& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IWriteValue
} // end namespace
#endif	// IWRITEVALUE_H
