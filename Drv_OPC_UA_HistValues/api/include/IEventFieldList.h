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

#ifndef IEVENTFIELDLIST_H
#define IEVENTFIELDLIST_H
#if TB5_FILTER

#include "EventFieldListStruct.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The EventFieldList data type contains a list of events being delivered to a
	* client (see Client::Subscription::onEventsReceived()). The size and order of the elements
	* in this list is determined by the select clauses in the EventFilter. */
	class TBC_EXPORT IEventFieldList
	{
	public:
		/*! Destructor */
		virtual ~IEventFieldList(){};

		/*! The methods getEventFieldCount() and getEventField() are provided for efficient access to data.
		* The semantics of these methods are documented in getEventFields(). */
		virtual OTUInt32 getEventFieldCount() const = 0;
		/*! The methods getEventFieldCount() and getEventField() are provided for efficient access to data.
		* The semantics of these methods are documented in getEventFields(). */
		virtual const IValue* getEventField(OTUInt32 index) const = 0;
		/*! Returns the list of selected event fields. The size and order of the elements
		* in this list is determined by the select clauses in the EventFilter. */
		virtual std::vector<Value> getEventFields() const = 0;
		/*! Adds an event field to the list of event fields to return. The size and order of the elements
		* in the event field list is determined by the select clauses in the EventFilter. */
		virtual EnumStatusCode addEventField(const IValue* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEventFieldList* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEventFieldList& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEventFieldList* other) const = 0;
		/*! @overload */
		virtual int compare(const IEventFieldList& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFieldList& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFieldList& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEventFieldList
} // end namespace
#endif
#endif	// IEVENTFIELDLIST_H
