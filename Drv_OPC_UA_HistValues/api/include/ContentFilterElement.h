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

#ifndef CONTENTFILTERELEMENT_H
#define CONTENTFILTERELEMENT_H
#if TB5_FILTER
#include "IContentFilterElement.h"
#include "InnerFilterOperand.h"
#include "FilterOperand.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ContentFilterElement data type specifies a filter element of a ContentFilter.
	*
	* A filter element defines
	* @li a filter operator (e.g. 'And', 'Or', 'Like', 'OfType', ...)
	* @li one or more operands for the operator
	*
	* @see IContentFilter EnumFilterOperator ILiteralOperand IElementOperand IAttributeOperand ISimpleAttributeOperand */
	class TBC_EXPORT ContentFilterElement
		: public IContentFilterElement
	{
	public:
		/*! Default constructor */
		ContentFilterElement();
		/*! Constructs a copy of the given instance */
		ContentFilterElement(const IContentFilterElement*);
		/*! @overload */
		ContentFilterElement(const IContentFilterElement&);
		/*! @overload */
		ContentFilterElement(const ContentFilterElement&);

		/*! Destructor */
		virtual ~ContentFilterElement();

		/*! Assigns the contents of @p cp to this instance */
		ContentFilterElement& operator=(const IContentFilterElement* cp);
		/*! @overload */
		ContentFilterElement& operator=(const IContentFilterElement& cp);
		/*! @overload */
		ContentFilterElement& operator=(const ContentFilterElement& cp);

		/* see IContentFilterElement::set */
		virtual EnumStatusCode set(const IContentFilterElement* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterElement& pSrc);

		/* see IContentFilterElement::compare */
		virtual int compare(const IContentFilterElement*) const;
		/*! @overload */
		virtual int compare(const IContentFilterElement&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterElement& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterElement& other) const;

		/* see IContentFilterElement::getFilterOperator */
		virtual EnumFilterOperator getFilterOperator() const;
		/* see IContentFilterElement::setFilterOperator */
		virtual void setFilterOperator(EnumFilterOperator value);

		/* see IContentFilterElement::getFilterOperandCount */
		virtual OTUInt32 getFilterOperandCount() const;
		/* see IContentFilterElement::getFilterOperand */
		virtual const IFilterOperand* getFilterOperand(OTUInt32 index) const;
		/* see IContentFilterElement::getFilterOperands */
		virtual std::vector<FilterOperand> getFilterOperands() const;
		/* see IContentFilterElement::addFilterOperand */
		virtual EnumStatusCode addFilterOperand(const IFilterOperand* pValue);
		/*! @overload */
		virtual EnumStatusCode addFilterOperand(const FilterOperand& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerFilterOperand> m_FilterOperands)
		ContentFilterElementStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// CONTENTFILTERELEMENT_H
