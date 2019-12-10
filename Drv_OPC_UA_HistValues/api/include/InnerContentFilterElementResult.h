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

#ifndef INNERCONTENTFILTERELEMENTRESULT_H
#define INNERCONTENTFILTERELEMENTRESULT_H
#if TB5_FILTER

#include "IContentFilterElementResult.h"

namespace SoftingOPCToolbox5
{
	/*! Stores an evaluation result for a ContentFilterElement */
	class TBC_EXPORT InnerContentFilterElementResult
		: public IContentFilterElementResult
	{
	public:
		/*! Destructor */
		virtual ~InnerContentFilterElementResult();

		/*! The status code for a single element. */
		virtual EnumStatusCode getStatusCode() const;
		virtual void setStatusCode(const EnumStatusCode& value);

		/*! @brief A list of status codes for the operands in an element.
		*
		* The size and order of the list matches the size and order of the
		* operands in the ContentFilterElement.
		* This list is empty if no operand errors occurred. */
		virtual std::vector<EnumStatusCode> getOperandStatusCodes() const;
		virtual EnumStatusCode setOperandStatusCodes(const std::vector<EnumStatusCode>& values);

		// init from otb handle
		void initInner(ContentFilterElementResultStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilterElementResult* other) const;
		/*! @overload */
		virtual int compare(const IContentFilterElementResult& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterElementResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterElementResult& other) const;

		/* see IContentFilterElementResult::set */
		EnumStatusCode set(const IContentFilterElementResult* pSrc);
		/*! @overload */
		EnumStatusCode set(const IContentFilterElementResult& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		ContentFilterElementResultStruct* m_pContent;
	};
} // end namespace

#endif
#endif	// INNERCONTENTFILTERELEMENTRESULT_H
