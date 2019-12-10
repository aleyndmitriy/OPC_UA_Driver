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

#ifndef SIMPLEATTRIBUTEOPERAND_H
#define SIMPLEATTRIBUTEOPERAND_H
#if TB5_FILTER
#include "ISimpleAttributeOperand.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

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
	class TBC_EXPORT SimpleAttributeOperand
		: public ISimpleAttributeOperand
	{
	public:
		/*! Default constructor */
		SimpleAttributeOperand();
		/*! Constructs a copy of the given instance */
		SimpleAttributeOperand(const ISimpleAttributeOperand*);
		/*! @overload */
		SimpleAttributeOperand(const ISimpleAttributeOperand&);
		/*! @overload */
		SimpleAttributeOperand(const SimpleAttributeOperand&);

		/*! Destructor */
		virtual ~SimpleAttributeOperand();

		/*! Assigns the contents of @p cp to this instance */
		SimpleAttributeOperand& operator=(const ISimpleAttributeOperand* cp);
		/*! @overload */
		SimpleAttributeOperand& operator=(const ISimpleAttributeOperand& cp);
		/*! @overload */
		SimpleAttributeOperand& operator=(const SimpleAttributeOperand& cp);

		/* see ISimpleAttributeOperand::set */
		virtual EnumStatusCode set(const ISimpleAttributeOperand* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISimpleAttributeOperand& pSrc);

		/* see ISimpleAttributeOperand::compare */
		virtual int compare(const ISimpleAttributeOperand*) const;
		/*! @overload */
		virtual int compare(const ISimpleAttributeOperand&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISimpleAttributeOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISimpleAttributeOperand& other) const;

		/* see ISimpleAttributeOperand::getTypeDefinitionId */
		virtual const INodeId* getTypeDefinitionId() const;
		/*! @overload */
		virtual INodeId* getTypeDefinitionId();
		/* see ISimpleAttributeOperand::setTypeDefinitionId */
		virtual void setTypeDefinitionId(const INodeId* value);
		/*! @overload */
		virtual void setTypeDefinitionId(const NodeId& value);

		/* see ISimpleAttributeOperand::getBrowsePathCount */
		virtual OTUInt32 getBrowsePathCount() const;
		/* see ISimpleAttributeOperand::getBrowsePath */
		virtual const IQualifiedName* getBrowsePath(OTUInt32 index) const;
		/*! @overload */
		virtual std::vector<QualifiedName> getBrowsePath() const;
		/* see ISimpleAttributeOperand::addBrowsePath */
		virtual EnumStatusCode addBrowsePath(const IQualifiedName* pValue);
		/*! @overload */
		virtual EnumStatusCode addBrowsePath(const QualifiedName& value);

		/* see ISimpleAttributeOperand::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;
		/* see ISimpleAttributeOperand::setAttributeId */
		virtual void setAttributeId(EnumAttributeId value);

		/* see ISimpleAttributeOperand::getIndexRange */
		virtual const INumericRange* getIndexRange() const;
		/* see ISimpleAttributeOperand::setIndexRange */
		virtual void setIndexRange(const INumericRange* value);
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_TypeDefinitionId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerQualifiedName> m_BrowsePath)
		SimpleAttributeOperandStruct m_content;
		InnerNumericRange m_IndexRange;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// SIMPLEATTRIBUTEOPERAND_H
