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

#ifndef IDATACHANGEFILTER_H
#define IDATACHANGEFILTER_H

#include "DataChangeFilterStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The DataChangeFilter data type is used by data change subscriptions (see Client::MonitoredItem::setFilter())
	* to specify the conditions under which a data change notification should be reported and, optionally, a
	* range or band for value changes where no data change notification is generated. This range is called "deadband". */
	class TBC_EXPORT IDataChangeFilter
	{
	public:
		/*! Destructor */
		virtual ~IDataChangeFilter(){};

		/*! Returns the conditions under which a data change notification should be reported.
		*
		* @see setTrigger() */
		virtual EnumDataChangeTrigger getTrigger() const = 0;
		/*! Sets the conditions under which a data change notification should be reported.
		*
		* The following triggering options are supported:
		* @li	Report data change notifications only if the status code associated with the
		*		value changes (see EnumDataChangeTrigger_Status)
		* @li	Report data change notifications if either the status code or the value changes
		*		(see EnumDataChangeTrigger_StatusValue)
		* @li	Report data change notifications if either the status code, the value
		*		or the timestamp changes (see EnumDataChangeTrigger_StatusValueTimestamp) */
		virtual void setTrigger(EnumDataChangeTrigger value) = 0;

		/*! Returns the type of the deadband to apply. */
		virtual EnumDeadbandType getDeadbandType() const = 0;
		/*! Sets the type of the deadband to apply.
		*
		* The following types of deadbands are supported:
		* @li	Apply no deadband (see EnumDeadbandType_None)
		* @li	Apply an absolute deadband (see EnumDeadbandType_Absolute)
		* @li	Apply a percent deadband (see EnumDeadbandType_Percent) */
		virtual void setDeadbandType(EnumDeadbandType value) = 0;

		/*! Returns the value of the deadband.
		*
		* @see setDeadbandValue() */
		virtual double getDeadbandValue() const = 0;
		/*! Sets the value of the deadband.
		*
		* The deadband is applied only if
		* @li the trigger includes value changes and
		* @li the DeadbandType is set appropriately.
		*
		* @see EnumDeadbandType */
		virtual void setDeadbandValue(double value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataChangeFilter* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataChangeFilter& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDataChangeFilter* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataChangeFilter& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataChangeFilter& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataChangeFilter& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataChangeFilter
} // end namespace
#endif	// IDATACHANGEFILTER_H
