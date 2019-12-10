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

#ifndef IQUERYDATADESCRIPTION_H
#define IQUERYDATADESCRIPTION_H

#include "QueryDataDescriptionStruct.h"
#include "RelativePath.h"
#include "IRelativePath.h"
#include "NumericRange.h"
#include "INumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! The QueryDataDescription data type is used by the QueryFirst service (see Client::Session::queryFirst())
	* to specify an attribute or a reference from the originating type definition node along a given RelativePath
	* for which to return data. */
	class TBC_EXPORT IQueryDataDescription
	{
	public:
		/*! Destructor */
		virtual ~IQueryDataDescription(){};

		/*! Returns the browse path relative to the originating node that identifies
		* the node which contains the data that is being requested, where the originating
		* node is an instance node of the type defined by the type definition node. */
		virtual const IRelativePath* getRelativePath() const = 0;
		/*! Sets the browse path relative to the originating node that identifies
		* the node which contains the data that is being requested, where the originating
		* node is an instance node of the type defined by the type definition node.
		* The instance nodes are further limited by the filter provided as part of the
		* QueryFirst service call.
		*
		* This RelativePath could end on a reference, in which case the
		* ReferenceDescription of the reference would be returned as its value. */
		virtual EnumStatusCode setRelativePath(const IRelativePath* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setRelativePath(const RelativePath& value) = 0;

		/*! Returns the identifier of the attribute. If the RelativePath ended in a reference
		* then this parameter is 0 and ignored by the server. */
		virtual EnumAttributeId getAttributeId() const = 0;
		/*! Sets the identifier of the attribute. If the RelativePath ended in a reference
		* then this parameter is 0 and ignored by the server. */
		virtual void setAttributeId(const EnumAttributeId& value) = 0;

		/*! Returns the index range that is applied to attribute values
		* returned as result of the QueryFirst or QueryNext service call.
		*
		* @see setIndexRange() */
		virtual const INumericRange* getIndexRange() const = 0;
		/*! Sets the index range that is applied to attribute values
		* returned as result of the QueryFirst or QueryNext service call.
		*
		* This parameter is used to identify a single element of a structure or an
		* array, or a single range of indexes for arrays. If a range of elements
		* are specified, the values are returned as a composite.
		*
		* This parameter is must not be defined if the specified attribute is not an array or a
		* structure. However, if the specified attribute is an array or a structure,
		* and this parameter is not defined, then all elements are to be included in the range. */
		virtual EnumStatusCode setIndexRange(const INumericRange* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setIndexRange(const NumericRange& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IQueryDataDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IQueryDataDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IQueryDataDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IQueryDataDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQueryDataDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQueryDataDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IQueryDataDescription
} // end namespace

#endif	// IQUERYDATADESCRIPTION_H
