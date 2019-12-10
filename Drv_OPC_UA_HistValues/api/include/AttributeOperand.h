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

#ifndef ATTRIBUTEOPERAND_H
#define ATTRIBUTEOPERAND_H
#if TB5_FILTER

#include "IAttributeOperand.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerRelativePath.h"
#include "RelativePath.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The AttributeOperand data type is used as operand in query filters to specify an attribute
	* of an Object or Variable node using a node in the type system and relative path constructed from
	* reference types and browse names.
	*
	* @see IContentFilter ISimpleAttributeOperand */
	class TBC_EXPORT AttributeOperand
		: public IAttributeOperand
	{
	public:
		/*! Default constructor */
		AttributeOperand();
		/*! Constructs a copy of the given instance */
		AttributeOperand(const IAttributeOperand*);
		/*! @overload */
		AttributeOperand(const IAttributeOperand&);
		/*! @overload */
		AttributeOperand(const AttributeOperand&);

		/*! Destructor */
		virtual ~AttributeOperand();

		/*! Assigns the contents of @p cp to this instance */
		AttributeOperand& operator=(const IAttributeOperand*);
		/*! @overload */
		AttributeOperand& operator=(const IAttributeOperand&);
		/*! @overload */
		AttributeOperand& operator=(const AttributeOperand&);

		/* see IAttributeOperand::set */
		virtual EnumStatusCode set(const IAttributeOperand* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IAttributeOperand& pSrc);

		/* see IAttributeOperand::compare */
		virtual int compare(const IAttributeOperand*) const;
		/*! @overload */
		virtual int compare(const IAttributeOperand&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAttributeOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAttributeOperand& other) const;

		/* see IAttributeOperand::getNodeId */
		virtual const INodeId* getNodeId() const;
		/*! @overload */
		virtual INodeId* getNodeId();
		/* see IAttributeOperand::setNodeId */
		virtual void setNodeId(const INodeId* value);
		/*! @overload */
		virtual void setNodeId(const NodeId& value);

		/* see IAttributeOperand::getAlias */
		virtual tstring getAlias() const;
		/* see IAttributeOperand::setAlias */
		virtual void setAlias(const tstring& value);

		/* see IAttributeOperand::getBrowsePath */
		virtual const IRelativePath* getBrowsePath() const;
		/*! @overload */
		virtual IRelativePath* getBrowsePath();
		/* see IAttributeOperand::setBrowsePath */
		virtual void setBrowsePath(const IRelativePath* value);
		/*! @overload */
		virtual void setBrowsePath(const RelativePath& value);

		/* see IAttributeOperand::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;
		/* see IAttributeOperand::setAttributeId */
		virtual void setAttributeId(EnumAttributeId value);

		/* see IAttributeOperand::getIndexRange */
		virtual const INumericRange* getIndexRange() const;
		/* see IAttributeOperand::setIndexRange */
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

		InnerNodeId m_NodeId;
		InnerRelativePath m_BrowsePath;
		InnerNumericRange m_IndexRange;

		AttributeOperandStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// ATTRIBUTEOPERAND_H
