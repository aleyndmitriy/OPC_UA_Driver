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

#ifndef IFILTEROPERAND_H
#define IFILTEROPERAND_H
#if TB5_FILTER

#include "FilterOperandStruct.h"
#include "InnerLiteralOperand.h"
#include "LiteralOperand.h"
#include "InnerElementOperand.h"
#include "ElementOperand.h"
#include "InnerAttributeOperand.h"
#include "AttributeOperand.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"

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
	class TBC_EXPORT IFilterOperand
	{
	public:
		/*! Destructor */
		virtual ~IFilterOperand(){};

		/*! Returns the actual type of the filter operand. */
		virtual EnumFilterOperand getType() const = 0;

		/*! Returns the LiteralOperand. If this operand is not a LiteralOperand,
		* this method returns a bad status code.
		*
		* @see setLiteralOperand() */
		virtual EnumStatusCode getLiteralOperand(LiteralOperand& operand) const = 0;
		/*! Assigns a LiteralOperand to this FilterOperand instance. */
		virtual EnumStatusCode setLiteralOperand(const ILiteralOperand* operand) = 0;
		/*! @overload */
		virtual EnumStatusCode setLiteralOperand(const LiteralOperand& operand) = 0;

		/*! Returns the ElementOperand. If this operand is not an ElementOperand,
		* this method returns a bad status code.
		*
		* @see setElementOperand() */
		virtual EnumStatusCode getElementOperand(ElementOperand& operand) const = 0;
		/*! Assigns an ElementOperand to this FilterOperand instance. */
		virtual EnumStatusCode setElementOperand(const IElementOperand* operand) = 0;
		/*! @overload */
		virtual EnumStatusCode setElementOperand(const ElementOperand& operand) = 0;

		/*! Returns the AttributeOperand. If this operand is not an AttributeOperand,
		* this method returns a bad status code.
		*
		* @see setAttributeOperand() */
		virtual EnumStatusCode getAttributeOperand(AttributeOperand& operand) const = 0;
		/*! Assigns an AttributeOperand to this FilterOperand instance. */
		virtual EnumStatusCode setAttributeOperand(const IAttributeOperand* operand) = 0;
		/*! @overload */
		virtual EnumStatusCode setAttributeOperand(const AttributeOperand& operand) = 0;

		/*! Returns the SimpleAttributeOperand. If this operand is not a SimpleAttributeOperand,
		* this method returns a bad status code.
		*
		* @see setSimpleAttributeOperand() */
		virtual EnumStatusCode getSimpleAttributeOperand(SimpleAttributeOperand& operand) const = 0;
		/*! Assigns a SimpleAttributeOperand to this FilterOperand instance. */
		virtual EnumStatusCode setSimpleAttributeOperand(const ISimpleAttributeOperand* operand) = 0;
		/*! @overload */
		virtual EnumStatusCode setSimpleAttributeOperand(const SimpleAttributeOperand& operand) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IFilterOperand* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IFilterOperand& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IFilterOperand* other) const = 0;
		/*! @overload */
		virtual int compare(const IFilterOperand& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFilterOperand& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFilterOperand& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IFilterOperand
} // end namespace
#endif
#endif	// IFILTEROPERAND_H
