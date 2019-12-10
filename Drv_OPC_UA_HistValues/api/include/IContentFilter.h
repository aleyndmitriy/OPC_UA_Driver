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

#ifndef ICONTENTFILTER_H
#define ICONTENTFILTER_H
#if TB5_FILTER

#include "ContentFilterStruct.h"
#include "InnerContentFilterElement.h"
#include "ContentFilterElement.h"

namespace SoftingOPCToolbox5
{
	/*! The ContentFilter data type is used by event subscriptions (see IEventFilter) and the query services
	* (see Client::Session::queryFirst() and Client::Session::queryNext()) to specify filter criteria
	* for events resp. nodes.
	*
	* A filter consists of one or more filter elements that contain both a filter operator ('And', 'Or', 'Like', 'OfType', ...)
	* and filter operands.
	*
	* A filter is evaluated by evaluating the first entry in the element list starting with the first operand
	* in the operand list. The operands of an element may contain references to sub-elements (see ElementOperand)
	* resulting in the evaluation continuing to the referenced elements in the element array. If an element cannot
	* be traced back to the starting element it is ignored.
	*
	* @see EnumFilterOperator ILiteralOperand IElementOperand IAttributeOperand ISimpleAttributeOperand */
	class TBC_EXPORT IContentFilter
	{
	public:
		/*! Destructor */
		virtual ~IContentFilter(){};

		/*! The methods getElementCount() and getElement() are provided for efficient access to data.
		* The semantics of these methods are documented in getElements(). */
		virtual OTUInt32 getElementCount() const = 0;
		/*! The methods getElementCount() and getElement() are provided for efficient access to data.
		* The semantics of these methods are documented in getElements(). */
		virtual const IContentFilterElement* getElement(OTUInt32 index) const = 0;
		/*! Returns the list of filter elements (containing operators and their operands) that are
		* specified for this filter. The filter is evaluated by starting with the first entry
		* in this vector. */
		virtual std::vector<ContentFilterElement> getElements() const = 0;
		/*! Adds a filter element (containing a filter operator and its operands) to
		* the list of filter elements.
		*
		* @see getElements() */
		virtual EnumStatusCode addElement(const IContentFilterElement* value) = 0;
		/*! @overload */
		virtual EnumStatusCode addElement(const ContentFilterElement& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IContentFilter* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilter& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilter* other) const = 0;
		/*! @overload */
		virtual int compare(const IContentFilter& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilter& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilter& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IContentFilter
} // end namespace
#endif
#endif	// ICONTENTFILTER_H
