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

#ifndef IREADVALUEID_H
#define IREADVALUEID_H

#include "ReadValueIdStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "INumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! The ReadValueId data type is used by the Read service (see Client::Session::read())
	* to specify the items to read. */
	class TBC_EXPORT IReadValueId
	{
	public:
		/*! Destructor */
		virtual ~IReadValueId(){};

		/*! Returns the NodeId of the node that is to be read. */
		virtual const INodeId* getNodeId() const = 0;
		/*! @overload */
		virtual INodeId* getNodeId() = 0;
		/*! Sets the NodeId of the node that is to be read. */
		virtual void setNodeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setNodeId(const NodeId& value) = 0;

		/*! Returns the attribute of the node that is to be read. */
		virtual EnumAttributeId getAttributeId() const = 0;
		/*! Sets the attribute of the node that is to be read. */
		virtual void setAttributeId(EnumAttributeId value) = 0;

		/*! Returns the index range that is applied to the read
		* value if the value is an array.
		*
		* @see setIndexRange() */
		virtual const INumericRange* getIndexRange() const = 0;
		/*! Sets the index range that is applied to the read value if the value is an array.
		*
		* This parameter is used to identify a single element of an array, or a single range
		* of indexes for arrays. If a range of elements is specified, the values are returned
		* as a composite. The first element is identified by index 0 (zero).
		*
		* This parameter is not defined if the specified attribute is not an array. However, if
		* the specified attribute is an array, and this parameter is not defined, then all elements
		* are to be included in the range. */
		virtual void setIndexRange(const INumericRange* value) = 0;
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IReadValueId*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IReadValueId&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IReadValueId* other) const = 0;
		/*! @overload */
		virtual int compare(const IReadValueId& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReadValueId& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReadValueId& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IReadValueId
} // end namespace
#endif	// IREADVALUEID_H
