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

#ifndef IELEMENTOPERAND_H
#define IELEMENTOPERAND_H
#if TB5_ALARMS

#include "ElementOperandStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The ElementOperand data type is used in the context of event or node filters (in queries)
	* to link sub-elements within a ContentFilter.
	*
	* The link is in the form of an integer that is used to index into the array of elements
	* contained in the ContentFilter. An index is considered valid if its value is greater than
	* the element index it is part of and it does not reference a non-existent element. Clients
	* shall construct filters in this way to avoid circular and invalid references. */
	class TBC_EXPORT IElementOperand
	{
	public:
		/*! Destructor */
		virtual ~IElementOperand(){};

		/*! Returns the index into the vector of ContentFilterElements. */
		virtual OTUInt32 getIndex() const = 0;
		/*! Sets the index into the vector of ContentFilterElements.
		* Please note that it is not allowed to define circular references
		* between elements. */
		virtual void setIndex(OTUInt32 value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IElementOperand* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IElementOperand& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IElementOperand* other) const = 0;
		/*! @overload */
		virtual int compare(const IElementOperand& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IElementOperand& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IElementOperand& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IElementOperand
} // end namespace
#endif
#endif	// IELEMENTOPERAND_H
