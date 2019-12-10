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

#ifndef ICONTENTFILTERELEMENTRESULT_H
#define ICONTENTFILTERELEMENTRESULT_H
#if TB5_FILTER

#include "ContentFilterElementResultStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The ContentFilterElementResult data type contains the result of an individual filter element.
	*
	* @see IContentFilterResult IContentFilterElement */
	class TBC_EXPORT IContentFilterElementResult
	{
	public:
		/*! Destructor */
		virtual ~IContentFilterElementResult(){};

		/*! Returns the status code for a single element. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Sets the status code for a single element. */
		virtual void setStatusCode(const EnumStatusCode& value) = 0;

		/*! Returns a list of status codes for the operands in a filter element.
		*
		* The size and order of the list matches the size and order of the
		* operands in the ContentFilterElement. This list is empty if no operand errors occurred. */
		virtual std::vector<EnumStatusCode> getOperandStatusCodes() const = 0;
		/*! Sets a list of status codes for the operands in a filter element.
		*
		* @see getOperandStatusCodes() */
		virtual EnumStatusCode setOperandStatusCodes(const std::vector<EnumStatusCode>& values) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IContentFilterElementResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IContentFilterElementResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IContentFilterElementResult* other) const = 0;
		/*! @overload */
		virtual int compare(const IContentFilterElementResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IContentFilterElementResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IContentFilterElementResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IContentFilterElementResult
} // end namespace

#endif
#endif	// ICONTENTFILTERELEMENTRESULT_H
