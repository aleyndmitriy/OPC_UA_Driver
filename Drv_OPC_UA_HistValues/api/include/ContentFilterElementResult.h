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

#ifndef CONTENTFILTERELEMENTRESULT_H
#define CONTENTFILTERELEMENTRESULT_H
#if TB5_FILTER

#include "IContentFilterElementResult.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ContentFilterElementResult data type contains the result of an individual filter element.
	*
	* @see IContentFilterResult IContentFilterElement */
	class TBC_EXPORT ContentFilterElementResult
		: public IContentFilterElementResult
	{
	public:
		/*! Default constructor */
		ContentFilterElementResult();
		/*! Constructs a copy of the given instance */
		ContentFilterElementResult(const IContentFilterElementResult*);
		/*! @overload */
		ContentFilterElementResult(const IContentFilterElementResult&);
		/*! @overload */
		ContentFilterElementResult(const ContentFilterElementResult&);

		/*! Destructor */
		virtual ~ContentFilterElementResult();

		/*! Assigns the contents of @p cp to this instance */
		ContentFilterElementResult& operator=(const IContentFilterElementResult*);
		/*! @overload */
		ContentFilterElementResult& operator=(const IContentFilterElementResult&);
		/*! @overload */
		ContentFilterElementResult& operator=(const ContentFilterElementResult&);

		/* see IContentFilterElementResult::set */
		virtual EnumStatusCode set(const IContentFilterElementResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterElementResult& pSrc);

		/* see IContentFilterElementResult::compare */
		virtual int compare(const IContentFilterElementResult*) const;
		/*! @overload */
		virtual int compare(const IContentFilterElementResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterElementResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterElementResult& other) const;

		/* see IContentFilterElementResult::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;
		/* see IContentFilterElementResult::setStatusCode */
		virtual void setStatusCode(const EnumStatusCode& value);

		/* see IContentFilterElementResult::getOperandStatusCodes */
		virtual std::vector<EnumStatusCode> getOperandStatusCodes() const;
		/* see IContentFilterElementResult::setOperandStatusCodes */
		virtual EnumStatusCode setOperandStatusCodes(const std::vector<EnumStatusCode>& values);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		ContentFilterElementResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// CONTENTFILTERELEMENTRESULT_H
