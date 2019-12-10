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

#ifndef CONTENTFILTERRESULT_H
#define CONTENTFILTERRESULT_H
#if TB5_FILTER

#include "IContentFilterResult.h"
#include "ContentFilterElementResult.h"
#include "IContentFilterElementResult.h"
#include "InnerContentFilterElementResult.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ContentFilter data type is used by event subscriptions and the query services
	* (see Client::Session::queryFirst() and Client::Session::queryNext()) to return any errors
	* associated with the event resp. node filter.
	*
	* @see IContentFilter */
	class TBC_EXPORT ContentFilterResult
		: public IContentFilterResult
	{
	public:
		/*! Default constructor */
		ContentFilterResult();
		/*! Constructs a copy of the given instance */
		ContentFilterResult(const IContentFilterResult*);
		/*! @overload */
		ContentFilterResult(const IContentFilterResult&);
		/*! @overload */
		ContentFilterResult(const ContentFilterResult&);

		/*! Destructor */
		virtual ~ContentFilterResult();

		/*! Assigns the contents of @p cp to this instance */
		ContentFilterResult& operator=(const IContentFilterResult* cp);
		/*! @overload */
		ContentFilterResult& operator=(const IContentFilterResult& cp);
		/*! @overload */
		ContentFilterResult& operator=(const ContentFilterResult& cp);

		/* see IContentFilterResult::set */
		virtual EnumStatusCode set(const IContentFilterResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterResult& pSrc);

		/* see IContentFilterResult::compare */
		virtual int compare(const IContentFilterResult*) const;
		/*! @overload */
		virtual int compare(const IContentFilterResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterResult& other) const;

		/* see IContentFilterResult::getElementResults */
		virtual std::vector<ContentFilterElementResult> getElementResults() const;
		/* see IContentFilterResult::addElementResult */
		virtual EnumStatusCode addElementResult(const IContentFilterElementResult* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerContentFilterElementResult> m_pElementResults)

		ContentFilterResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// CONTENTFILTERRESULT_H
