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

#ifndef IHISTORYEVENTFIELDLIST_H
#define IHISTORYEVENTFIELDLIST_H
#if TB5_HISTORY

#include "HistoryEventFieldListStruct.h"
#include "Value.h"
#include "IValue.h"

namespace SoftingOPCToolbox5
{
	/*! The HistoryEventFieldList data type contains a list of historical events being delivered to a
	* client as result of a HistoryRead service call (see Client::Session::historyReadEvent()). The size
	* and order of the elements in this list is determined by the select clauses in the EventFilter
	* (see ReadEventDetails::setFilter()). */
	class TBC_EXPORT IHistoryEventFieldList
	{
	public:
		/*! Destructor */
		virtual ~IHistoryEventFieldList(){};

		/*! Returns a list of event fields belonging to a historical event. The order of the
		* event fields in this list matches the order specified by select clause in ReadEventDetails::setFilter(). */
		virtual std::vector<Value> getEventFields() const = 0;
		/*! Adds an event field to the list of event fields.
		*
		* @see getEventFields() */
		virtual EnumStatusCode addEventField(const IValue* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IHistoryEventFieldList* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IHistoryEventFieldList& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IHistoryEventFieldList* other) const = 0;
		/*! @overload */
		virtual int compare(const IHistoryEventFieldList& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IHistoryEventFieldList& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IHistoryEventFieldList& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IHistoryEventFieldList
} // end namespace

#endif
#endif	// IHISTORYEVENTFIELDLIST_H
