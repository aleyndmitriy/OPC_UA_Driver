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

#ifndef IATTRIBUTEOPERAND_H
#define IATTRIBUTEOPERAND_H
#if TB5_FILTER

#include "AttributeOperandStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerRelativePath.h"
#include "RelativePath.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! The AttributeOperand data type is used as operand in event and query filters to specify an attribute
	* of an Object or Variable node using a node in the type system and relative path constructed from
	* reference types and browse names.
	*
	* @see IContentFilter ISimpleAttributeOperand */
	class TBC_EXPORT IAttributeOperand
	{
	public:
		/*! Destructor */
		virtual ~IAttributeOperand(){};

		/*! Returns the NodeId of a node from the type system. */
		virtual const INodeId* getNodeId() const = 0;
		/*! @overload */
		virtual INodeId* getNodeId() = 0;
		/*! Sets the NodeId of a node from the type system. */
		virtual void setNodeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setNodeId(const NodeId& value) = 0;

		/*! Returns the (optional) alias that this operand defines. */
		virtual tstring getAlias() const = 0;
		/*! Sets an alias for this operand. An alias is a symbolic name that can be used to alias
		* this operand and use it in other location in the filter structure.
		* Note that this parameter is optional. */
		virtual void setAlias(const tstring& value) = 0;

		/*! Returns the browse path relative to the node identified by the NodeId. */
		virtual const IRelativePath* getBrowsePath() const = 0;
		/*! @overload */
		virtual IRelativePath* getBrowsePath() = 0;
		/*! Sets the browse path relative to the node identified by the NodeId. */
		virtual void setBrowsePath(const IRelativePath* value) = 0;
		/*! @overload */
		virtual void setBrowsePath(const RelativePath& value) = 0;

		/*! Returns the identifier of the attribute that is selected by the operand. */
		virtual EnumAttributeId getAttributeId() const = 0;
		/*! Sets the identifier of the attribute that shall be selected by the operand. */
		virtual void setAttributeId(EnumAttributeId value) = 0;

		/*! Returns the index range that is applied to the selected attribute.
		* @see setIndexRange() */
		virtual const INumericRange* getIndexRange() const = 0;
		/*! Sets the index range that is applied to the selected attribute.
		*
		* This parameter is used to identify a single element of an array or a single range
		* of indexes for an array.
		*
		* @note		This parameter is not used if the specified Attribute is not an array. However, if
		*			the specified Attribute is an array and this parameter is not used, then all
		*			elements are to be included in the range. The parameter is null if not used. */
		virtual void setIndexRange(const INumericRange* value) = 0;
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IAttributeOperand* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IAttributeOperand& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAttributeOperand* other) const = 0;
		/*! @overload */
		virtual int compare(const IAttributeOperand& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAttributeOperand& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAttributeOperand& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IAttributeOperand
} // end namespace
#endif
#endif	// IATTRIBUTEOPERAND_H
