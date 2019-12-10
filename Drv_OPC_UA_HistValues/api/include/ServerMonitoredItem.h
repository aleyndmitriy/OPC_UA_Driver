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

#ifndef SERVERMONITOREDITEM_H
#define SERVERMONITOREDITEM_H
#include "Base.h"
#include "Enums.h"
#include "InnerDataChangeFilter.h"
#include "InnerNumericRange.h"
#include "InnerEventFilter.h"
#include "IDataValue.h"
#include "InnerNodeId.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class IEventFieldList;

	namespace Server
	{
		class BaseNode;
		class Subscription;
		class BaseEvent;
		typedef ObjectPointer<BaseEvent> BaseEventPtr;
		class BaseEventNotification;
		typedef ObjectPointer<BaseEventNotification> BaseEventNotificationPtr;
	}

	namespace Server
	{
		/*! The MonitoredItem class represents a monitored item that has been created by
		* an OPC UA client to monitor data changes or events. */
		class TBC_EXPORT MonitoredItem
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			MonitoredItem(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			MonitoredItem(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~MonitoredItem();

			/*! Returns the subscription to which this monitored item belongs. */
			ObjectPointer<Server::Subscription> getSubscription();
			/*! @overload */
			ObjectPointer<const Server::Subscription> getSubscription() const;

			/*! Returns the id of this monitored item. This identifier has been assigned by the SDK core. */
			OTUInt32 getId() const;

			/*! Returns whether the item is monitoring data changes. */
			bool isDataItem() const;

			/*! Returns whether the item is monitoring events. */
			bool isEventItem() const;

			/*! Returns the NodeId of the node that is being monitored. */
			const INodeId* getNodeId() const;

			/*! Returns the node that is being monitored. */
			ObjectPointer<Server::BaseNode> getNode();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNode() const;

			/*! Returns the attribute of the node that is monitored by this item. */
			EnumAttributeId getAttributeId() const;

			/*! Returns the index range that the server applies to array values.
			* The index range is provided for informational purposes only. The SDK
			* applies the index range automatically.
			*
			* @note	If the client did not provide an index range, this method
			*		returns NULL. */
			const INumericRange* getIndexRange() const;

			/*! Returns the timestamps that the server shall return for data changes. */
			EnumTimestampsToReturn getTimestampsToReturn() const;

			/*! Returns the monitoring mode of the monitored item. */
			EnumMonitoringMode getMonitoringMode() const;

			/*! Returns the sampling interval (in milliseconds) of the monitored item. */
			double getSamplingInterval() const;
			/*! Sets the (revised) sampling interval (in milliseconds) of the monitored item.
			*
			* @note	This method may only be called inside the Subscription::onCreateMonitoredItems() or
			*		Subscription::onModifyMonitoredItems() callback method in order to revise the value requested by the client. */
			EnumStatusCode setSamplingInterval(double revisedSamplingInterval);

			/*! Returns whether the oldest or the latest notification message is discarded when the queue of notification messages is full and a new notification is to be enqueued.
			Returns true, if the oldest notification message is discarded. Returns false, if the latest notification message (i.e. the new notification to enqueue) is discarded. */
			bool getDiscardOldest() const;

#if TB5_ALARMS
			/*! Reports an event notification only for this MonitoredItem.
			* This method is meant for advanced purposes where it's known which MonitoredItems need to be invoked.
			*
			* @param eventToReport			The event node or event notification (for simple events), which is used to retrieve the correct
			*								event fields, which are requested in the select clause of the client's event filter
			* @param evaluateWhereClause	Specifies whether the where clause of the client's event filter shall be evaluated
			*								or whether it shall be reported anyway. Per default, the evaluation is enabled.
			*								Disabling the evaluation should only be done when the where clause is known to match.
			*
			* @note Only this MonitoredItem is noticed, the event propagation along the references in the address space is not executed!
			*		This can lead to servers reacting not according to OPC UA specification (all events shall be reported at the server node).
			*
			* @note	To report an event to all MonitoredItems of the affected nodes, it is proposed to call BaseEventNotification::report()
			*		for simple events or BaseEvent::report() for events which are stored in the address space.
			*		This methods of reporting automatically follows the references for event propagation.
			*
			* @see BaseEvent::report(), BaseEventNotification::report() */
			EnumStatusCode reportEvent(const BaseEventPtr eventToReport, bool evaluateWhereClause = true);
			/*! @overload */
			EnumStatusCode reportEvent(const BaseEventNotificationPtr eventToReport, bool evaluateWhereClause = true);
			/*! @overload
            *
			* Set the event information by the exact event fields.
			* The select clause and where clause of the client's event filter have to be evaluated by the application.
			*
			* @param eventFields			The information to return which is specified in the select clause
			*								of the client's event filter
			*
			* @note If the application reports eventFields not matching the select clause a client can react unexpectedly and even crash. */
			EnumStatusCode reportEvent(const IEventFieldList& eventFields);
#endif

			/*! Adds a data value to the enqueued data changes, which will be reported after the next publishing interval.
			* This method is meant for advanced purposes where it's known which MonitoredItems need to be invoked.
			*
			* Queuing values may be rejected by a dead band filter, a disabled monitoring mode, by an invalid state
			* of the monitored item or by inserting DataValues where the server timestamp is older than the last monitored value.
			*
			* @param valueToReport		The DataValue to store
			* @param evaluateFilters	Specifies whether the filters shall be evaluated or whether to enforce to enqueue the value anyway.
			* @returns
			* @li EnumStatusCode_Good :					Reported data is stored to be reported.
			*											This does not guarantee that this value is ever published; it still can be overwritten by a value
			*											with a newer timestamp in the same sampling interval or even removed if a newer value in the same
			*											sampling interval is within the deadband of the latest published value.
			* @li EnumStatusCode_GoodDataIgnored :		Reported data is ignored (e.g. due to deadband)
			* @li EnumStatusCode_BadInvalidState :		Monitored item is disabled or an event monitored item
			* @li EnumStatusCode_BadUserAccessDenied :	The client created the monitored item has no read access right
			* @li EnumStatusCode_BadDataLost :			A previously reported data value had a newer server timestamp (also possible if updated the cache value of the corresponding node)
			*
			*
			* @note	Disabling the evaluation of the filters shall only be done when the filters are known to match.
			*		Make sure that the used data type is allowed for the monitored attribute.
			*		Only one value can be stored per sampling interval, setting it several times will overwrite the last recent value
			*		of this interval.
			*		The time of the inserted value and the sampling intervals are calculated by the server timestamp of the inserted values,
			*		this allows to enqueue values of different sampling intervals.
			*		The values can only be enqueued in an ascending server timestamp order, older values than the last enqueued value will
			*		be rejected.
			* @see IDataValue::setServerTimestamp() */
			EnumStatusCode reportDataChange(const IDataValue& valueToReport, bool evaluateFilters = true);

			/*! Returns the size of the queue which holds data change or event notifications. */
			OTUInt32 getQueueSize() const;
			/*! Sets the (revised) size of the queue which holds data change or event notifications.
			*
			* @note	This method may only be called inside the Subscription::onCreateMonitoredItems() or
			*		Subscription::onModifyMonitoredItems() callback method in order to revise the value requested by the client. */
			EnumStatusCode setQueueSize(OTUInt32 revisedQueueSize);

			/*! Returns the data change filter that was provided by a client. The data
			* change filter is provided for informational purposes only. The SDK applies
			* the provided data change filter automatically whenever the monitored item
			* receives an updated data value.
			*
			* @note	The DataChangeFilter is only valid when this is a data change monitored item (see isDataItem()),
			*		otherwise this method returns NULL */
			const IDataChangeFilter* getFilter() const;

#if TB5_ALARMS
			/*! Returns the event filter that was provided by a client. The event
			* filter is provided for informational purposes only. The SDK applies
			* the provided event filter automatically whenever the server reports
			* an event.
			*
			* @note	The EventFilter is only valid when this is an event monitored item (see isEventItem()),
			*		otherwise this method returns NULL */
			const IEventFilter* getEventFilter() const;
#endif

			/*! Returns a list of monitored items that are triggered by this monitored item.
			* The list of triggered items is provided for informational purposes only.
			* Triggering links are evaluated by the SDK automatically. */
			std::vector<ObjectPointer<Server::MonitoredItem> > getTriggeredMonitoredItems();
			/*! @overload */
			std::vector<ObjectPointer<const Server::MonitoredItem> > getTriggeredMonitoredItems() const;

			/*! Callback that is called when the client adds or removes triggering links for this
			* monitored item. This callback is for informational purposes only. Triggering links are
			* evaluated by the SDK automatically. */
			virtual void onSetTriggering(const std::vector<Server::MonitoredItem*>& addedLinks,
				const std::vector<Server::MonitoredItem*>& removedLinks);

			/*! For internal use only */
			void initMembers();
		private:

			/*! Default constructor
			*
			* The default constructor is private - a server application is not allowed to create such an object.
			* MonitoredItem objects are created in SDK core only when a client creates them via service. */
			MonitoredItem();

			/*! Forbid use assignment operator */
			MonitoredItem& operator=(const MonitoredItem&);
			/*! Forbid use of copy constructor */
			MonitoredItem(const MonitoredItem&);

			InnerNodeId m_NodeId;
			InnerDataChangeFilter m_Filter;
#if TB5_ALARMS
			InnerEventFilter m_EventFilter;
#endif
			InnerNumericRange m_IndexRange;
		};
		typedef ObjectPointer<MonitoredItem> MonitoredItemPtr;
		typedef ObjectPointer<const MonitoredItem> MonitoredItemConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERMONITOREDITEM_H
