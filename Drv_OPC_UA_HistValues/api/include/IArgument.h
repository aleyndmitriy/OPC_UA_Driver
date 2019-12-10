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

#ifndef IARGUMENT_H
#define IARGUMENT_H

#include "ArgumentStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The Argument data type describes an input or output parameter of an OPC UA Method. */
	class TBC_EXPORT IArgument
	{
	public:
		/*! Destructor */
		virtual ~IArgument(){};

		/*! Returns the NodeId of the argument's data type. */
		virtual const INodeId* getDataType() const = 0;
		/*! @overload */
		virtual INodeId* getDataType() = 0;
		/*! Sets the NodeId of the argument's data type. */
		virtual void setDataType(const INodeId* value) = 0;
		/*! @overload */
		virtual void setDataType(const NodeId& value) = 0;

		/*! Returns the name of the argument */
		virtual tstring getName() const = 0;
		/*! Sets the name of the argument */
		virtual void setName(const tstring& value) = 0;

		/*! Returns the value rank of the argument. The value rank indicates whether the
		* data type is an array and how many dimensions the array has.
		* @see setValueRank() */
		virtual OTInt32 getValueRank() const = 0;
		/*! Sets the value rank of the argument. The value rank indicates whether the
		* data type is an array and how many dimensions the array has.
		*
		* If the rank is
		* @li >= 1 it defines the array dimensions of the value,
		* @li -1 means scalar (not an array),
		* @li 0 means 1 or more dimensions
		* @li -2 means scalar or an array with any number of dimensions.
		* @li -3 means the value can be a scalar or a one dimensional array.
		*
		* @note If the array dimensions don't match to the new value rank, then the array dimensions are
		*       automatically updated to matching dimensions without length limitation. @see setArrayDimensions */
		virtual void setValueRank(OTInt32 value) = 0;

		/*! Returns the length of each dimension for an array data type.
		* @see setArrayDimensions() setValueRank() */
		virtual std::vector<OTUInt32> getArrayDimensions() const = 0;
		/*! @brief Sets the length of each dimension for an array data type.
		*
		* It is intended to describe the capability of the data type, not the current size.
		* The number of elements shall be equal to the value of the value rank and shall be null if valueRank <= 0.
		* A value of 0 for an individual dimension indicates that the dimension has a variable length.
		*
		* @note If the value rank does not match to the new array dimensions, then the value rank is automatically updated
		*       to the exact dimension. @see setValueRank */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>&) = 0;

		/*! Returns a localized description of the argument. */
		virtual const ILocalizedText* getDescription() const = 0;
		/*! @overload */
		virtual ILocalizedText* getDescription() = 0;
		/*! Sets a localized description of the argument. */
		virtual void setDescription(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual void setDescription(const LocalizedText& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IArgument* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IArgument& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IArgument* other) const = 0;
		/*! @overload */
		virtual int compare(const IArgument& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IArgument& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IArgument& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IArgument
} // end namespace
#endif	// IARGUMENT_H
