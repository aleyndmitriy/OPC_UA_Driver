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

#ifndef FILTEROPERAND_H
#define FILTEROPERAND_H
#if TB5_FILTER

#include "IFilterOperand.h"
#include "InnerLiteralOperand.h"
#include "LiteralOperand.h"
#include "InnerElementOperand.h"
#include "ElementOperand.h"
#include "InnerAttributeOperand.h"
#include "AttributeOperand.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The FilterOperand data type is used to specify a filter operand in a where clause of an
	* event or node filter.
	*
	* The FilterOperand can hold one of the following operand types:
	* @li ILiteralOperand
	* @li IElementOperand
	* @li IAttributeOperand (not allowed for event filters)
	* @li ISimpleAttributeOperand
	*
	* @see IContentFilter IContentFilterElement */
	class TBC_EXPORT FilterOperand
		: public IFilterOperand
	{
	public:
		/*! Default constructor */
		FilterOperand();
		/*! Constructs a copy of the given instance */
		FilterOperand(const IFilterOperand*);
		/*! @overload */
		FilterOperand(const IFilterOperand&);
		/*! @overload */
		FilterOperand(const FilterOperand&);

		/*! Destructor */
		virtual ~FilterOperand();

		/*! Assigns the contents of @p cp to this instance */
		FilterOperand& operator=(const IFilterOperand*);
		/*! @overload */
		FilterOperand& operator=(const IFilterOperand&);
		/*! @overload */
		FilterOperand& operator=(const FilterOperand&);

		/* see IFilterOperand::set */
		virtual EnumStatusCode set(const IFilterOperand* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IFilterOperand& pSrc);

		/* see IFilterOperand::compare */
		virtual int compare(const IFilterOperand*) const;
		/*! @overload */
		virtual int compare(const IFilterOperand&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFilterOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFilterOperand& other) const;

		/*! Returns the actual type of the filter operand. */
		virtual EnumFilterOperand getType() const;

		/* see IFilterOperand::getLiteralOperand */
		virtual EnumStatusCode getLiteralOperand(LiteralOperand& operand) const;
		/* see IFilterOperand::setLiteralOperand */
		virtual EnumStatusCode setLiteralOperand(const ILiteralOperand* operand);
		/* see IFilterOperand::setLiteralOperand */
		virtual EnumStatusCode setLiteralOperand(const LiteralOperand& operand);

		/* see IFilterOperand::getElementOperand */
		virtual EnumStatusCode getElementOperand(ElementOperand& operand) const;
		/* see IFilterOperand::setElementOperand */
		virtual EnumStatusCode setElementOperand(const IElementOperand* operand);
		/* see IFilterOperand::setElementOperand */
		virtual EnumStatusCode setElementOperand(const ElementOperand& operand);

		/* see IFilterOperand::getAttributeOperand */
		virtual EnumStatusCode getAttributeOperand(AttributeOperand& operand) const;
		/* see IFilterOperand::setAttributeOperand */
		virtual EnumStatusCode setAttributeOperand(const IAttributeOperand* operand);
		/* see IFilterOperand::setAttributeOperand */
		virtual EnumStatusCode setAttributeOperand(const AttributeOperand& operand);

		/* see IFilterOperand::getSimpleAttributeOperand */
		virtual EnumStatusCode getSimpleAttributeOperand(SimpleAttributeOperand& operand) const;
		/* see IFilterOperand::setSimpleAttributeOperand */
		virtual EnumStatusCode setSimpleAttributeOperand(const ISimpleAttributeOperand* operand);
		/* see IFilterOperand::setSimpleAttributeOperand */
		virtual EnumStatusCode setSimpleAttributeOperand(const SimpleAttributeOperand& operand);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		FilterOperandStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// FILTEROPERAND_H
