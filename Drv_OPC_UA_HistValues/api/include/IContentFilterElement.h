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

#ifndef ICONTENTFILTERELEMENT_H
#define ICONTENTFILTERELEMENT_H
#if TB5_FILTER

#include "ContentFilterElementStruct.h"
#include "InnerFilterOperand.h"
#include "FilterOperand.h"

namespace SoftingOPCToolbox5
{
	/*! The ContentFilterElement data type specifies a filter element of a ContentFilter.
	*
	* A filter element defines
	* @li a filter operator (e.g. 'And', 'Or', 'Like', 'OfType', ...)
	* @li one or more operands for the operator
	*
	* @see IContentFilter EnumFilterOperator ILiteralOperand IElementOperand IAttributeOperand ISimpleAttributeOperand */
	class TBC_EXPORT IContentFilterElement
	{
	public:
		/*! Destructor */
		virtual ~IContentFilterElement(){};

		/*! Returns the filter operator that is to be evaluated. */
		virtual EnumFilterOperator getFilterOperator() const = 0;
		/*! Sets the filter operator that is to be evaluated. */
		virtual void setFilterOperator(EnumFilterOperator value) = 0;

		/*! The methods getFilterOperandCount() and getFilterOperand() are provided for efficient access to data.
		* The semantics of these methods are documented in getFilterOperands(). */
		virtual OTUInt32 getFilterOperandCount() const = 0;
		/*! The methods getFilterOperandCount() and getFilterOperand() are provided for efficient access to data.
		* The semantics of these methods are documented in getFilterOperands(). */
		virtual const IFilterOperand* getFilterOperand(OTUInt32 index) const = 0;
		/*! Returns the operands used be the specified filter operator (see getFilterOperator()).
		*
		* @see addFilterOperand() */
		virtual std::vector<FilterOperand> getFilterOperands() const = 0;
		/*! Adds an operand used by the specified filter operator (see setFilterOperator()).
		* The number and use of the operands depends on the operator (see EnumFilterOperator). */
		virtual EnumStatusCode addFilterOperand(const IFilterOperand* pValue) = 0;
		/*! @overload */
		virtual EnumStatusCode addFilterOperand(const FilterOperand& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IContentFilterElement* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterElement& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilterElement* other) const = 0;
		/*! @overload */
		virtual int compare(const IContentFilterElement& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterElement& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterElement& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IContentFilterElement
} // end namespace
#endif
#endif	// ICONTENTFILTERELEMENT_H
