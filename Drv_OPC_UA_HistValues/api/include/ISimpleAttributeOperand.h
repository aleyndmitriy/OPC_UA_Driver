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

#ifndef ISIMPLEATTRIBUTEOPERAND_H
#define ISIMPLEATTRIBUTEOPERAND_H
#if TB5_ALARMS

#include "SimpleAttributeOperandStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	/*! The SimpleAttributeOperand data type is used as operand in event and query filters to specify an attribute
	* of an Object or Variable node using a node in the type system and relative path constructed from
	* browse names.
	*
	* The SimpleAttributeOperand is a simplified form of the AttributeOperand and all of the rules that apply to
	* the AttributeOperand also apply to the SimpleAttributeOperand. The AttributeOperand can be replaced by a
	* SimpleAttributeOperand whenever all ReferenceTypes in the RelativePath are subtypes of HierarchicalReferences
	* and the targets are Object or Variable nodes and an alias (see IAttributeOperand::getAlias()) is not required.
	*
	* @see IContentFilter IAttributeOperand */
	class TBC_EXPORT ISimpleAttributeOperand
	{
	public:
		/*! Destructor */
		virtual ~ISimpleAttributeOperand(){};

		/*! Returns the NodeId of a type definition node. This parameter restricts the operand to
		* instances of the type definition node or one of its subtypes. */
		virtual const INodeId* getTypeDefinitionId() const = 0;
		/*! @overload */
		virtual INodeId* getTypeDefinitionId() = 0;
		/*! Sets the NodeId of a type definition node. This parameter restricts the operand to
		* instances of the type definition node or one of its subtypes. */
		virtual void setTypeDefinitionId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setTypeDefinitionId(const NodeId& value) = 0;

		/*! The methods getBrowsePathCount() and getBrowsePath() are provided for efficient access to data.
		* The semantics of these methods are documented in getBrowsePath(). */
		virtual OTUInt32 getBrowsePathCount() const = 0;
		/*! The methods getBrowsePathCount() and getBrowsePath() are provided for efficient access to data.
		* The semantics of these methods are documented in getBrowsePath(). */
		virtual const IQualifiedName* getBrowsePath(OTUInt32 index) const = 0;
		/*! Returns a relative path to a node.
		*
		* @see addBrowsePath() */
		virtual std::vector<QualifiedName> getBrowsePath() const = 0;
		/*! Adds an browse name to the list of browse names that make up
		* a relative path to a node.
		*
		* The list of browse names is equivalent to a RelativePath that specifies forward
		* references which are subtypes of the HierarchicalReferences reference type.
		* If this list is empty the node is the instance of the type definition. */
		virtual EnumStatusCode addBrowsePath(const IQualifiedName* pValue) = 0;
		/*! @overload */
		virtual EnumStatusCode addBrowsePath(const QualifiedName& value) = 0;

		/*! Returns the attribute of the node that is to be selected. */
		virtual EnumAttributeId getAttributeId() const = 0;
		/*! Sets the attribute of the node that is to be selected. */
		virtual void setAttributeId(EnumAttributeId value) = 0;

		/*! Returns the index range that is applied to the attribute value
		* if the attribute value is an array.
		*
		* @see setIndexRange() */
		virtual const INumericRange* getIndexRange() const = 0;
		/*! Sets the index range that is applied to the attribute value if the
		* attribute value is an array.
		*
		* This parameter is used to identify a single element of an array, or a single
		* range of indexes for an array. The first element is identified by index 0 (zero).
		* This parameter is ignored if the selected node is not a Variable or the value of a
		* Variable is not an array.
		*
		* All values in the array are used if this parameter is not specified. */
		virtual void setIndexRange(const INumericRange* value) = 0;
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISimpleAttributeOperand*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISimpleAttributeOperand&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISimpleAttributeOperand* other) const = 0;
		/*! @overload */
		virtual int compare(const ISimpleAttributeOperand& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISimpleAttributeOperand& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISimpleAttributeOperand& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISimpleAttributeOperand
} // end namespace
#endif
#endif	// ISIMPLEATTRIBUTEOPERAND_H
