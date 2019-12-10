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

#ifndef CONTENTFILTER_H
#define CONTENTFILTER_H
#if TB5_FILTER
#include "IContentFilter.h"
#include "InnerContentFilterElement.h"
#include "ContentFilterElement.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

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
	class TBC_EXPORT ContentFilter
		: public IContentFilter
	{
	public:
		/*! Default constructor */
		ContentFilter();
		/*! Constructs a copy of the given instance */
		ContentFilter(const IContentFilter*);
		/*! @overload */
		ContentFilter(const IContentFilter&);
		/*! @overload */
		ContentFilter(const ContentFilter&);

		/*! Destructor */
		virtual ~ContentFilter();

		/*! Assigns the contents of @p cp to this instance */
		ContentFilter& operator=(const IContentFilter*);
		/*! @overload */
		ContentFilter& operator=(const IContentFilter&);
		/*! @overload */
		ContentFilter& operator=(const ContentFilter&);

		/* see IContentFilter::compare */
		virtual int compare(const IContentFilter*) const;
		/*! @overload */
		virtual int compare(const IContentFilter&) const;

		/* see IContentFilter::set */
		virtual EnumStatusCode set(const IContentFilter* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilter& pSrc);

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilter& other) const;

		/* see IContentFilter::getElementCount */
		virtual OTUInt32 getElementCount() const;
		/* see IContentFilter::getElement */
		virtual const IContentFilterElement* getElement(OTUInt32 index) const;
		/* see IContentFilter::getElements */
		virtual std::vector<ContentFilterElement> getElements() const;
		/* see IContentFilter::addElement */
		virtual EnumStatusCode addElement(const IContentFilterElement* value);
		/*! @overload */
		virtual EnumStatusCode addElement(const ContentFilterElement& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerContentFilterElement> m_Elements)
		ContentFilterStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// CONTENTFILTER_H
