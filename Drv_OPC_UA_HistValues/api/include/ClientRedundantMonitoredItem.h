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

#ifndef CLIENTREDUNDANTMONITOREDITEM_H
#define CLIENTREDUNDANTMONITOREDITEM_H

#if TB5_CLIENT
#include "Base.h"
#include "NodeId.h"
#include "NumericRange.h"
#include "DataChangeFilter.h"
#include "EventFilter.h"
#include "Constants.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Client
	{
		class RedundantSubscription;
		class RedundantMonitoredItem;
		typedef ObjectPointer<RedundantMonitoredItem> RedundantMonitoredItemPtr;
	}

	namespace Client
	{
		/*! The RedundantMonitoredItem class is used to monitor data changes or events in a server.
		*
		* This class is similar to the MonitoredItem class but is used within a redundant session and a redundant subscription.
		*
		* @see MonitoredItem, RedundantSession, RedundantSubscription */
		class TBC_EXPORT RedundantMonitoredItem : public Base
		{
		public:
			/*! Constructs a new RedundantMonitoredItem instance */
			static ObjectPointer<RedundantMonitoredItem> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			RedundantMonitoredItem(TBHandle otbHandle);

			/*! Destructor */
			virtual ~RedundantMonitoredItem();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class RedundantMonitoredItem
			/////////////////////////////////////////////////////////////////////////

			/*! Connects the configured RedundantMonitoredItem to the server. When this call succeeds, the RedundantMonitoredItem
			* is registered at the server and collects data changes or events. Data changes and events
			* are reported via Client::Subscription::onDataChange() resp. Client::Subscription::onEventsReceived().
			*
			* @see disconnect() */
			EnumStatusCode connect();

			/*! Disconnects the RedundantMonitoredItem from the server. When this call succeeds, the RedundantMonitoredItem
			* has been deleted on the server.
			*
			* @see connect() */
			EnumStatusCode disconnect();

			/*! Returns whether the monitored item is connected to the server or not.
			* @see connect() disconnect() */
			EnumStatusCode isConnected(bool& isConnected, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			/*! @brief Adds a list of item that shall be reported when this monitored item triggers.
			*
			* OPC UA allows setting up monitored items that report their data changes or events only
			* if they are triggered by some other monitored item. The triggering mechanism is a useful
			* feature that allows clients to reduce the data volume on the wire by configuring some monitored items
			* to sample frequently but only report when some other event happens.
			*
			* The monitoring mode of the items to report (i.e. triggered items) is set to sampling-only so that it
			* will sample and queue notifications without reporting them.
			*
			* The following triggering modes are defined:
			* @li	If the monitoring mode of the triggering item is SAMPLING, then it is not reported when the
			*		triggering item triggers the items to report.
			* @li	If the monitoring mode of the triggering item is REPORTING, then it is reported when the triggering
			*		item triggers the items to report.
			* @li	If the monitoring mode of the triggering item is DISABLED, then the triggering item does not trigger
			*		the items to report.
			* @li	If the monitoring mode of the item to report is SAMPLING, then it is reported when the triggering item
			*		triggers the items to report.
			* @li	If the monitoring mode of the item to report is REPORTING, this effectively causes the triggering item
			*		to be ignored. All notifications of the items to report are sent after the publishing interval expires.
			* @li	If the monitoring mode of the item to report is DISABLED, then there will be no sampling of the item to
			*		report and therefore no notifications to report.
			*
			* @param itemsToReport	A list of monitored items that shall report their notifications when this
			*						monitored item triggers.
			*
			* @note	Please note that both the reporting monitored items and the triggering monitored item need
			*		to be connected to the server (i.e. isConnected() must return true).
			*
			* @see removeItemsToReport() */
			EnumStatusCode addItemsToReport(const std::vector<Client::RedundantMonitoredItemPtr>& itemsToReport);

			/*! Removes a list of items to be reported when this monitored item triggers.
			*
			* @param itemsToReport	A list of monitored items that shall no longer report their notifications when this
			*						monitored item triggers.
			*
			* @see addItemsToReport() */
			EnumStatusCode removeItemsToReport(const std::vector<Client::RedundantMonitoredItemPtr>& itemsToReport);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class RedundantMonitoredItem
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the index of the server which is currently the primary server.
			*
			* @note	When there is currently no primary server, the value OTRedundantServerIndex_Invalid is
			*		returned. Make sure to not use this special index to specify a single server or to use it as an
			*		index of a returned array. */
			OTUInt32 getPrimaryServerIndex() const;

			/*! Returns the subscription this RedundantMonitoredItem belongs to. */
			ObjectPointer<Client::RedundantSubscription> getSubscription();
			/*! @overload */
			ObjectPointer<const Client::RedundantSubscription> getSubscription() const;

			/*! Returns the server-assigned identifier for the monitored item at the given server.
			*
			* @note	Since the identifier is assigned by the server, this method returns only valid
			*		results of the monitored item while it is connected to the server. */
			EnumStatusCode getId(OTUInt32& id, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			/*! Returns the NodeId of the node that is being monitored.
			* @see setNodeId() */
			NodeId getNodeId() const;
			/*! Sets the NodeId of the node that is to be monitored.
			*
			* @note The NodeId cannot be modified after the monitored item has been connected.
			*
			* @see setAttributeId() */
			EnumStatusCode setNodeId(const INodeId* nodeId);
			/*! @overload */
			EnumStatusCode setNodeId(const INodeId& nodeId);

			/*! Returns the attribute of the node that is to be monitored.
			* @see setAttributeId() */
			EnumAttributeId getAttributeId() const;
			/*! Sets the attribute of the node that is to be monitored.
			* In case of monitoring events, the attribute id must be the 'EventNotifier' attribute.
			*
			* @note The monitored attribute cannot be modified after the RedundantMonitoredItem has been connected.
			*
			* @see setNodeId() */
			EnumStatusCode setAttributeId(EnumAttributeId attributeId);

			/*! Returns the index range that the server applies to DataValues that contain variants of type 'array'.
			* @see setIndexRange() */
			NumericRange getIndexRange() const;
			/*! Sets the index range that the server applies to DataValues that contain variants of type 'array'.
			* The index range allows clients to request only a certain range of an array.
			*
			* Examples:
			* @li "1" - would select the second array element only
			* @li "1:2" - would select the second and third elements in an array
			* @li "1:2,0:1" - would select an range of a matrix.
			* @li "1,2" - would select the element at position [1,2] in the matrix
			*
			* @param pIndexRange	The index range to apply to arrays
			*
			* @note The index range cannot be modified after the RedundantMonitoredItem has been connected.
			* @note The second argument of the range specification for a dimension must be greater than the first one.
			* The following values are, for example, invalid: "1:1", "2:1" */
			EnumStatusCode setIndexRange(const INumericRange* pIndexRange);
			/*! @overload */
			EnumStatusCode setIndexRange(const NumericRange& indexRange);

			/*! Returns the monitoring mode of the monitored item at the primary server.
			* @see setMonitoringMode() */
			EnumMonitoringMode getMonitoringMode() const;
			/*! Sets the monitoring mode of the monitored item at the primary server. The monitoring mode determines whether the monitored item
			* collects notification messages (i.e. data change notifications or event notifications) and, if so, whether
			* the Subscription publishes the collected notifications or not.
			*
			* The monitoring mode is usually set before the monitored item is being connected.
			* Changing the monitoring mode of a connected monitored item will immediately change its state in the server.
			*
			* @param monitoringMode		The monitoring mode of the monitored item.
			*
			* @note	Default value is EnumMonitoringMode_Disabled, i.e. notification messages are neither collected nor reported
			*		to the client. Use EnumMonitoringMode_Reporting to enable reporting of notification messages.
			*
			* @note	To modify the monitoring mode of multiple items, please use the methods
			* Client::RedundantSubscription::setMonitoredItemsMonitoringMode() or Client::RedundantSubscription::setAllMonitoredItemsMonitoringMode(). */
			EnumStatusCode setMonitoringMode(EnumMonitoringMode monitoringMode);

			/*! Returns the sampling interval (in milliseconds) of the monitored item. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the monitored item
			* has been connected.
			*
			* @see setSamplingInterval() */
			double getSamplingInterval() const;
			/*! Sets the sampling interval of the monitored item. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the monitored item
			* has been connected.
			*
			* The value 0 indicates that the server should use the fastest practical rate.
			* The value -1 indicates that the publishing interval of the subscription shall be
			* used for the sampling interval.
			*
			* In case of an event monitored item this value must be 0.
			*
			* @param samplingInterval	The sampling interval in milliseconds
			*
			* @note The default value is 0.
			* @note	Please use Client::RedundantSubscription::updateChangedMonitoredItems() to apply changes to the sampling interval
			*		when the monitored item is already connected (isConnected() == true). */
			EnumStatusCode setSamplingInterval(double samplingInterval);

			/*! Returns the revised sampling interval. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the monitored item
			* has been connected.
			*
			* @note This method is only available when isConnected() == true. */
			EnumStatusCode getRevisedSamplingInterval(OTDouble& revisedSamplingInterval, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			/*! Returns the maximum number of data change or event notifications that a monitored item may
			* hold in its queue. Notifications are dequeued by the Subscription every publishing interval.
			*
			* @see setQueueSize() */
			OTUInt32 getQueueSize() const;
			/*! Sets the maximum number of data change or event notifications that a monitored item may
			* hold in its queue. Notifications are dequeued by the Subscription every publishing interval.
			*
			* The queue of notification messages allows clients to collect more than one data value change or event for
			* the same node with one publish call.
			*
			* If the server wants to enqueue a notification message and the queue has reached the maximum number of elements,
			* then depending on the DiscardOldest parameter (see setDiscardOldest()) either the oldest or the latest notification
			* is discarded.
			*
			* @param queueSize	The maximum number of data change or event notification messages that the monitored item
			*					shall keep in its queue before the queue is emptied by the Subscription during publishing.
			*					If the value 0 is provided, the server will use the default queue size.
			*
			* @note The default value is the value 0 which means that the server will use the default queue size.
			* @note	Please use Client::RedundantSubscription::updateChangedMonitoredItems() to apply changes to the queue size
			*		when the monitored item is already connected (isConnected() == true). */
			EnumStatusCode setQueueSize(OTUInt32 queueSize);

			/*! Returns the revised maximum number of data change or event notifications that a monitored item may
			* hold in its queue. The server may revise the queue size to a more appropriate value which can be retrieved by
			* this method after the monitored item has been connected.
			*
			* @see setQueueSize()
			* @note This method is only available when isConnected() == true. */
			EnumStatusCode getRevisedQueueSize(OTUInt32& revisedQueueSize, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			/*! Returns whether the oldest or the latest notification message is discarded when the queue
			* of notification messages is full and a new notification is to be enqueued.
			*
			* Returns true, if the oldest notification message is discarded.
			* Returns false, if the latest notification message (i.e. the new notification to enqueue)
			* is discarded.
			*
			* @see setDiscardOldest() */
			bool getDiscardOldest() const;
			/*! Sets whether the oldest or the latest notification message is discarded when the queue
			* of notification messages is full and a new notification is to be enqueued.
			*
			* @param discardOldest	If true, the oldest notification message in the queue is discarded.
			*						If false, the new notification message to enqueue is discarded.
			*
			* @note	Please use Client::RedundantSubscription::updateChangedMonitoredItems() to apply changes to the queue policy
			*		when the monitored item is already connected.
			*
			* @see setQueueSize() */
			EnumStatusCode setDiscardOldest(bool discardOldest);

			/*! Returns the data change filter that decides whether a data change is to be enqueued (and reported) or not.
			* @see setFilter() */
			EnumStatusCode getFilter(DataChangeFilter& filter) const;
			/*! Sets the data change filter that decides whether a data change is to be enqueued (and reported) or not.
			* The data change filter defines
			* @li	which DataValue attributes (value, quality/status, timestamp) must have
			*		changed for the data change to be enqueued.
			* @li	an optional deadband for analog values.
			*
			* @param filter		The data change filter
			*
			* @note	Please use Client::RedundantSubscriptionSubscription::updateChangedMonitoredItems() to apply changes to the data change filter
			*		when the monitored item is already connected.
			* @note The data change filter must only be specified for data change- (and not event-) monitored items. */
			EnumStatusCode setFilter(const IDataChangeFilter* filter);
			/*! @overload */
			EnumStatusCode setFilter(const IDataChangeFilter& filter);

			/*! Returns the event filter that is applied to events that are enqueued in the notification message queue.
			* setEventFilter() */
			EnumStatusCode getEventFilter(EventFilter& filter) const;
			/*! Sets the event filter that is applied to events that are enqueued in the notification message queue.
			* Setting an event filter denotes this monitored item as event monitored item.
			*
			* The event filter defines
			* @li which data (event fields) of an event is to be returned
			* @li a SQL-like "where"-clause that determines which events to report
			*
			* @param eventFilter	The filter that contains the 'select'- and 'where'-clause for events
			*						which are enqueued in this monitored item's notification message queue
			*
			* @note	Please use Client::RedundantSubscription::updateChangedMonitoredItems() to apply changes to the event filter
			*		when the monitored item is already connected.
			* @note The data change filter must only be specified for event- (and not data change-) monitored items. */
			EnumStatusCode setEventFilter(const IEventFilter* eventFilter);
			/*! @overload */
			EnumStatusCode setEventFilter(const IEventFilter& eventFilter);

			//////////////////////////////////////////////////////////////////////////
			// Callbacks
			//////////////////////////////////////////////////////////////////////////

			/*! This method is called whenever an error concerning this monitored item occurs.
			* Applications should override this method to catch errors that occur due to this monitored item.
			*
			* Typical contexts in which this callback is called are errors in following situations:
			* @li connecting the monitored item on the server node
			* @li deleting a monitored item from the server
			* @li updating the server with the monitored items modifications
			* @li setting the monitoring mode for monitored items
			* @li setting triggered monitored items (for the items to be added or removed)
			*
			* @param errorCode				The status code of the error that occurred
			* @param redundantServerIndex	The index of the affected server (see Client::RedundantSession::setServerInformation()). */
			virtual void onError(EnumStatusCode errorCode, OTUInt32 redundantServerIndex);

			/*! This method is called whenever the connection state of the monitored item changes.
			*
			* @param isConnected	If true, the monitored item is connected to the server with given index.
			* @param redundantServerIndex	The index of the affected server (see Client::RedundantSession::setServerInformation()). */
			virtual void onStatusChange(bool isConnected, OTUInt32 redundantServerIndex);

		protected:
			/*! Please use RedundantMonitoredItem::create() to construct an instance of this type. */
			RedundantMonitoredItem();

			/*! For internal use only */
			RedundantMonitoredItem(bool suppressCoreInstanceCreate);

			/*! For internal use only */
			void initMembers();
		};
		typedef ObjectPointer<RedundantMonitoredItem> RedundantMonitoredItemPtr;
	} // end Client namespace
} // toolbox namespace end
#endif

#endif	// CLIENTREDUNDANTMONITOREDITEM_H
