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

#ifndef INNERCONTENTFILTER_H
#define INNERCONTENTFILTER_H
#if TB5_FILTER

#include "IContentFilter.h"
#include "InnerContentFilterElement.h"
#include "ContentFilterElement.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerContentFilter
	class TBC_EXPORT InnerContentFilter
		: public IContentFilter
	{
	public:
		/*! Destructor */
		virtual ~InnerContentFilter();

		virtual OTUInt32 getElementCount() const;
		virtual const IContentFilterElement* getElement(OTUInt32 index) const;
		virtual std::vector<ContentFilterElement> getElements() const;
		virtual EnumStatusCode addElement(const IContentFilterElement* pValue);
		virtual EnumStatusCode addElement(const ContentFilterElement& value);


		// init from otb handle
		void initInner(ContentFilterStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilter* other) const;
		/*! @overload */
		virtual int compare(const IContentFilter& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilter& other) const;

		// set from interface
		EnumStatusCode set(const IContentFilter* pSrc);
		EnumStatusCode set(const IContentFilter& pSrc);

	private:
		// the handle to the related core object
		ContentFilterStruct* m_pContentFilter_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerContentFilterElement> m_Elements)
	};
}
#endif
#endif	// INNERCONTENTFILTER_H
