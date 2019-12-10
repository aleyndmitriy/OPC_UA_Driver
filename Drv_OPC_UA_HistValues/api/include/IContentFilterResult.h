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

#ifndef ICONTENTFILTERRESULT_H
#define ICONTENTFILTERRESULT_H
#if TB5_FILTER

#include "ContentFilterResultStruct.h"
#include "ContentFilterElementResult.h"
#include "IContentFilterElementResult.h"

namespace SoftingOPCToolbox5
{
	/*! The ContentFilter data type is used by event subscriptions and the query services
	* (see Client::Session::queryFirst() and Client::Session::queryNext()) to return any errors
	* associated with the event resp. node filter.
	*
	* @see IContentFilter */
	class TBC_EXPORT IContentFilterResult
	{
	public:
		/*! Destructor */
		virtual ~IContentFilterResult(){};

		/*! Returns a list of results for individual elements in the filter.
		*
		* The size and order of the list matches the size and order of the elements in
		* the ContentFilter parameter. */
		virtual std::vector<ContentFilterElementResult> getElementResults() const = 0;
		/*! Adds a result for an individual element in the filter. */
		virtual EnumStatusCode addElementResult(const IContentFilterElementResult* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IContentFilterResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilterResult* other) const = 0;
		/*! @overload */
		virtual int compare(const IContentFilterResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IContentFilterResult
} // end namespace

#endif
#endif	// ICONTENTFILTERRESULT_H
