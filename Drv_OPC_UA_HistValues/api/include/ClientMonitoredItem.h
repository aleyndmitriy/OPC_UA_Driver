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

#ifndef CLIENTMONITOREDITEM_H
#define CLIENTMONITOREDITEM_H
#if TB5_CLIENT
#include "Base.h"
#include "Enums.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataChangeFilter.h"
#include "DataChangeFilter.h"
#include "InnerEventFilter.h"
#include "EventFilter.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Client
	{
		class Subscription;
		class MonitoredItem;
		typedef ObjectPointer<MonitoredItem> MonitoredItemPtr;
	}

	namespace Client
	{
		/*! The MonitoredItem class is used to monitor data changes or events in a server.
		*
		* For monitoring data changes, the monitored item needs to be configured with the NodeId
		* of the monitored node and the attribute of the node that is to be monitored
		* (see setNodeId() and setAttributeId()). Usually, this will be the value attribute
		* of a variable. The sampling interval determines the rate that the server
		* uses to update the monitored attribute (setSamplingInterval()).
		*
		* For monitoring events, the monitored item needs to be configured with the NodeId of
		* an object that emits events and the special attribute 'EnumAttributeId_EventNotifier'
		* (see setNodeId() and setAttributeId()). An event filter specifies both the fields
		* of an event that the client is interested in and the criteria for an event to
		* be reported to the client (see setEventFilter()).
		*
		* A configured monitored item is created on the server only after it has been
		* added to a subscription and connected (see Subscription::addMonitoredItem() and connect()).
		*
		* @see Subscription */
		class TBC_EXPORT MonitoredItem
			: public Base
		{
		public:
			/*! Constructs a new MonitoredItem instance */
			static ObjectPointer<MonitoredItem> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			MonitoredItem(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			MonitoredItem();
			/*! For internal use only */
			MonitoredItem(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~MonitoredItem();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class MonitoredItem
			/////////////////////////////////////////////////////////////////////////

			/*! Connects the configured MonitoredItem to the server. When this call succeeds, the MonitoredItem
			* is registered at the server and collects data changes or events. Data changes and events
			* are reported via Client::Subscription::onDataChange() resp. Client::Subscription::onEventsReceived().
			*
			* @see disconnect() */
			EnumStatusCode connect();

			/*! Disconnects the MonitoredItem from the server. When this call succeeds, the MonitoredItem
			* has been deleted on the server.
			*
			* @see connect() */
			EnumStatusCode disconnect();

			/*! Returns true if the monitored item is connected to the server.
			* @see connect() disconnect() */
			bool isConnected() const;

			/*! @brief Adds a list of item that shall be reported when this monitored item triggers.
			*
			* OPC UA allows setting up MonitoredItems that report their data changes or events only
			* if they are triggered by some other MonitoredItem. The triggering mechanism is a useful
			* feature that allows clients to reduce the data volume on the wire by configuring some MonitoredItems
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
			* @param itemsToReport	A list of MonitoredItems that shall report their notifications when this
			*						MonitoredItem triggers.
			*
			* @note	Please note that both the reporting MonitoredItems and the triggering MonitoredItem need
			*		to be added to a subscription before the triggering linkage can be established.
			*       The triggered monitored items must not be connected after the triggering monitored item (connecting in the same call works).
			*
			* @see removeItemsToReport() */
			EnumStatusCode addItemsToReport(const std::vector<Client::MonitoredItemPtr>& itemsToReport);

			/*! Removes a list of items to be reported when this MonitoredItem triggers.
			*
			* @param itemsToReport	A list of MonitoredItems that shall no longer report their notifications when this
			*						MonitoredItem triggers.
			*
			* @see addItemsToReport() */
			EnumStatusCode removeItemsToReport(const std::vector<Client::MonitoredItemPtr>& itemsToReport);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class MonitoredItem
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the subscription this MonitoredItem belongs to. */
			ObjectPointer<Client::Subscription> getSubscription();
			/*! @overload */
			ObjectPointer<const Client::Subscription> getSubscription() const;

			/*! Returns the identifier of this MonitoredItem that has been assigned by the server.
			*
			* @note	Since the identifier is assigned by the server, this method shall only
			*		be called when the MonitoredItem is connected (i.e. isConnected() == true) */
			OTUInt32 getId() const;

			/*! Returns the NodeId of the node that is being monitored.
			* @see setNodeId() */
			const INodeId* getNodeId() const;
			/*! Sets the NodeId of the node that is to be monitored.
			*
			* @note The NodeId cannot be modified after the MonitoredItem has been connected.
			*
			* @see setAttributeId() */
			EnumStatusCode setNodeId(const INodeId* nodeId);
			/*! @overload */
			EnumStatusCode setNodeId(const INodeId& nodeId);

			/*! Returns the attribute of the node that is to be monitored.
			* @see setAttributeId() */
			EnumAttributeId getAttributeId() const;
			/*! Sets the attribute of the node that is to be monitored.
			*
			* In case of monitoring events, the attribute id must be the 'EventNotifier' attribute.
			* Default attribute id is EnumAttributeId_Value.
			*
			* @note The monitored attribute cannot be modified after the MonitoredItem has been connected. */
			EnumStatusCode setAttributeId(EnumAttributeId attributeId);

			/*! Returns the index range that the server applies to DataValues that contain variants of type 'array' or 'matrix'.
			* @see setIndexRange() */
			const INumericRange* getIndexRange() const;
			/*! Sets the index range that the server applies to DataValues that contain variants of type 'array' or 'matrix'.
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
			* @note The index range cannot be modified after the MonitoredItem has been connected.
			* @note The second argument of the range specification for a dimension must be greater than the first one.
			* The following values are, for example, invalid: "1:1", "2:1" */
			EnumStatusCode setIndexRange(const INumericRange* pIndexRange);
			/*! @overload */
			EnumStatusCode setIndexRange(const NumericRange& indexRange);

			/*! Returns the monitoring mode of the MonitoredItem.
			* @see setMonitoringMode() */
			EnumMonitoringMode getMonitoringMode() const;
			/*! Sets the monitoring mode of the MonitoredItem. The monitoring mode determines whether the MonitoredItem
			* collects notification messages (i.e. data change notifications or event notifications) and, if so, whether
			* the Subscription publishes the collected notifications or not.
			*
			* The monitoring mode is usually set before the MonitoredItem is being connected.
			* Changing the monitoring mode of a connected MonitoredItem will immediately change its state in the server.
			*
			* @param monitoringMode		The monitoring mode of the MonitoredItem.
			*
			* @note	Default value is EnumMonitoringMode_Reporting
			*
			* @note	To modify the monitoring mode of multiple items, please use the methods
			* Client::Subscription::setMonitoredItemsMonitoringMode() or Client::Subscription::setAllMonitoredItemsMonitoringMode(). */
			EnumStatusCode setMonitoringMode(EnumMonitoringMode monitoringMode);

			/*! Returns the sampling interval (in milliseconds) of the MonitoredItem. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the MonitoredItem
			* has been connected.
			*
			* @see setSamplingInterval() */
			double getSamplingInterval() const;
			/*! Sets the sampling interval of the MonitoredItem. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the MonitoredItem
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
			* @note	Please use Client::Subscription::updateChangedMonitoredItems() to apply changes to the sampling interval
			*		when the MonitoredItem is already connected (isConnected() == true). */
			EnumStatusCode setSamplingInterval(double samplingInterval);

			/*! Returns the revised sampling interval. The server may revise this value to a more
			* appropriate value which can be retrieved by getRevisedSamplingInterval() after the MonitoredItem
			* has been connected.
			*
			* @note This method is only available when isConnected() == true. */
			double getRevisedSamplingInterval() const;

			/*! Returns the maximum number of data change or event notifications that a MonitoredItem may
			* hold in its queue. Notifications are dequeued by the Subscription every publishing interval.
			*
			* @see setQueueSize() */
			OTUInt32 getQueueSize() const;
			/*! Sets the maximum number of data change or event notifications that a MonitoredItem may
			* hold in its queue. Notifications are dequeued by the Subscription every publishing interval.
			*
			* The queue of notification messages allows clients to collect more than one data value change or event for
			* the same node with one publish call.
			*
			* If the server wants to enqueue a notification message and the queue has reached the maximum number of elements,
			* then depending on the DiscardOldest parameter (see setDiscardOldest()) either the oldest or the latest notification
			* is discarded.
			*
			* @param queueSize	The maximum number of data change or event notification messages that the MonitoredItem
			*					shall keep in its queue before the queue is emptied by the Subscription during publishing.
			*					If the value 0 is provided, the server will use the default queue size.
			*
			* @note The default value is the value 0 which means that the server will use the default queue size.
			* @note	Please use Client::Subscription::updateChangedMonitoredItems() to apply changes to the queue size
			*		when the MonitoredItem is already connected (isConnected() == true). */
			EnumStatusCode setQueueSize(OTUInt32 queueSize);

			/*! Returns the revised maximum number of data change or event notifications that a MonitoredItem may
			* hold in its queue. The server may revise the queue size to a more appropriate value which can be retrieved by
			* this method after the MonitoredItem has been connected.
			*
			* @see setQueueSize()
			* @note This method is only available when isConnected() == true. */
			OTUInt32 getRevisedQueueSize() const;

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
			* @param discardOldest	If true, the oldest notification message in the queue is discarded. (Default)
			*						If false, the new notification message to enqueue is discarded.
			*
			* @note	Please use Client::Subscription::updateChangedMonitoredItems() to apply changes to the queue policy
			*		when the MonitoredItem is already connected (isConnected() == true).
			*
			* @see setQueueSize() */
			EnumStatusCode setDiscardOldest(bool discardOldest);

			/*! Returns the data change filter that decides whether a data change is to be enqueued (and reported) or not.
			* @see setFilter() */
			const IDataChangeFilter* getFilter() const;
			/*! Sets the data change filter that decides whether a data change is to be enqueued (and reported) or not.
			* The data change filter defines
			* @li	which DataValue attributes (value, quality/status, timestamp) must have
			*		changed for the data change to be enqueued.
			* @li	an optional deadband for analog values.
			*
			* @param filter		The data change filter
			*
			* @note	Please use Client::Subscription::updateChangedMonitoredItems() to apply changes to the data change filter
			*		when the MonitoredItem is already connected (isConnected() == true).
			* @note The data change filter must only be specified for data change- (and not event-) monitored items. */
			EnumStatusCode setFilter(const IDataChangeFilter* filter);
			/*! @overload */
			EnumStatusCode setFilter(const IDataChangeFilter& filter);

			/*! Returns the event filter that is applied to events that are enqueued in the notification message queue.
			* setEventFilter() */
			const IEventFilter* getEventFilter() const;
			/*! Sets the event filter that is applied to events that are enqueued in the notification message queue.
			* Setting an event filter denotes this MonitoredItem as event monitored item.
			*
			* The event filter defines
			* @li which data (event fields) of an event is to be returned
			* @li a SQL-like "where"-clause that determines which events to report
			*
			* @param eventFilter	The filter that contains the 'select'- and 'where'-clause for events
			*						which are enqueued in this MonitoredItem's notification message queue
			*
			* @note	Please use Client::Subscription::updateChangedMonitoredItems() to apply changes to the event filter
			*		when the MonitoredItem is already connected (isConnected() == true).
			* @note The data change filter must only be specified for data change- (and not event-) monitored items. */
			EnumStatusCode setEventFilter(const IEventFilter* eventFilter);
			/*! @overload */
			EnumStatusCode setEventFilter(const IEventFilter& eventFilter);


			//////////////////////////////////////////////////////////////////////////
			// Callbacks
			//////////////////////////////////////////////////////////////////////////

			/*! This method is called whenever an error concerning this MonitoredItem occurs.
			* Applications should override this method to catch errors that occur due to this monitored item.
			*
			* Typical contexts in which this callback is called are errors in following situations:
			* @li connecting the monitored item on the server node
			* @li deleting a monitored item from the server
			* @li updating the server with the monitored items modifications
			* @li setting the monitoring mode for monitored items
			* @li setting triggered monitored items (for the items to be added or removed)
			*
			* @param errorCode		The status code of the error that occurred */
			virtual void onError(EnumStatusCode errorCode);

			/*! This method is called whenever the connection state of the MonitoredItem changes.
			*
			* @param isConnected	If true, the MonitoredItem is connected to the server */
			virtual void onStatusChange(bool isConnected);


		private:
			/*! For internal use only */
			void initMembers();

			/*! Forbid use assignment operator */
			MonitoredItem& operator=(const MonitoredItem&);
			/*! Forbid use of copy constructor */
			MonitoredItem(const MonitoredItem&);

			InnerNodeId m_NodeId;
			InnerDataChangeFilter m_Filter;
			InnerEventFilter m_EventFilter;
			InnerNumericRange m_IndexRange;
		};
		typedef ObjectPointer<MonitoredItem> MonitoredItemPtr;
		typedef ObjectPointer<const MonitoredItem> MonitoredItemConstPtr;

	} // end Client namespace
} // toolbox namespace end
#endif

#endif	// CLIENTMONITOREDITEM_H
