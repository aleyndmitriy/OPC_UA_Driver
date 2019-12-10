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

#ifndef IEVENTFILTER_H
#define IEVENTFILTER_H
#if TB5_ALARMS

#include "EventFilterStruct.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"
#include "InnerContentFilter.h"
#include "ContentFilter.h"

namespace SoftingOPCToolbox5
{
	/*! The EventFilter data type is used by event MonitoredItems (see Client::MonitoredItem::setEventFilter()) to
	* specify the content of reported events (select clauses) and criteria for an event to be reported (where clause). */
	class TBC_EXPORT IEventFilter
	{
	public:
		/*! Destructor */
		virtual ~IEventFilter(){};

		/*! The methods getSelectClauseCount() and getSelectClause() are provided for efficient access to data.
		* The semantics of these methods are documented in getSelectClauses(). */
		virtual OTUInt32 getSelectClauseCount() const = 0;
		/*! The methods getSelectClauseCount() and getSelectClause() are provided for efficient access to data.
		* The semantics of these methods are documented in getSelectClauses(). */
		virtual const ISimpleAttributeOperand* getSelectClause(OTUInt32 index) const = 0;
		/*! Returns a list of select clauses. A select clause determines which value to return
		* with each event. */
		virtual std::vector<SimpleAttributeOperand> getSelectClauses() const = 0;
		/*! Adds a select clause to the list of select clauses. A select clause determines which value to return
		* with each event. */
		virtual EnumStatusCode addSelectClause(const ISimpleAttributeOperand* pValue) = 0;
		/*! @overload */
		virtual EnumStatusCode addSelectClause(const SimpleAttributeOperand& value) = 0;

		/*! Returns the where clause that limits notifications to those events that match
		* the criteria defined by the returned ContentFilter. */
		virtual const IContentFilter* getWhereClause() const = 0;
		/*! @overload */
		virtual IContentFilter* getWhereClause() = 0;
		/*! Sets the where clause that limits notifications to those events that match
		* the criteria defined by the provided ContentFilter.
		*
		* @note Please note that the AttributeOperand may not be used in an EventFilter. */
		virtual void setWhereClause(const IContentFilter* value) = 0;
		/*! @overload */
		virtual void setWhereClause(const ContentFilter& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEventFilter* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEventFilter& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEventFilter* other) const = 0;
		/*! @overload */
		virtual int compare(const IEventFilter& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFilter& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFilter& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEventFilter
} // end namespace
#endif
#endif	// IEVENTFILTER_H
