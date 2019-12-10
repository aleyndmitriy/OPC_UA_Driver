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

#ifndef CLIENTSUBSCRIPTION_H
#define CLIENTSUBSCRIPTION_H
#if TB5_CLIENT
#include "Base.h"
#include "Enums.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "InnerEventFieldList.h"
#include "EventFieldList.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Client
	{
		class Session;
		class MonitoredItem;
		typedef ObjectPointer<MonitoredItem> MonitoredItemPtr;
	}

	namespace Client
	{
		/*! The Subscription class is used to publish data changes and/or events that occur in a server.
		*
		* A subscription aggregates one or more monitored items that collect data changes and/or events in a server.
		* The publishing interval of the subscription defines the rate at which those data changes and/or events
		* are published to the client (see setPublishingInterval()). Client applications must derive from this class
		* and override the onDataChange() and/or onEventsReceived() methods to process received data changes and/or events.
		*
		* A configured subscription is created on the server only after it has been
		* added to a session and connected (see Session::addSubscription() and connect()).
		*
		* @see MonitoredItem */
		class TBC_EXPORT Subscription
			: public Base
		{
		public:
			/*! Constructs a new Subscription instance */
			static ObjectPointer<Subscription> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Subscription(TBHandle otbHandle);

		public:
			/*! Default constructor */
			Subscription();
			/*! Destructor */
			virtual ~Subscription();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Subscription
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the ID that the server assigned to this Subscription. This parameter is only valid after
			* the Subscription has been connected. */
			OTUInt32 getId() const;

			/*! The client session to which this Subscription is bound. */
			ObjectPointer<Client::Session> getSession();
			/*! @overload */
			ObjectPointer<const Client::Session> getSession() const;

			/*! Returns the publishing interval (in milliseconds) that has been provided by the client.
			* This is not necessarily the interval that the server actually uses. The actually used
			* interval can be retrieved by getRevisedPublishingInterval().
			*
			* @see setPublishingInterval() getRevisedPublishingInterval() */
			double getPublishingInterval() const;
			/*! Defines the publishing interval in milliseconds. The publishing interval defines the cycle time
			* in which the server sends notifications (data changes, events or status changes) periodically to the client.
			*
			* @param publishingInterval The publishing interval in milliseconds
			*
			* @note The default value is the 1000.0.
			* @note Please use update() to apply changes to this parameter if the Subscription is already connected. */
			EnumStatusCode setPublishingInterval(double publishingInterval);

			/*! Holds the revised publishing interval that has been returned by the server. This value is set automatically
			* during the connect operation. */
			double getRevisedPublishingInterval() const;

			/*! Returns the threshold for the Subscription's life time counter.
			*
			* @see setLifeTimeCount() */
			OTUInt32 getLifeTimeCount() const;
			/*! Sets the threshold for the Subscription's life timer counter. Whenever the life time counter
			* reaches the provided threshold, the server deletes the Subscription.
			*
			* The server uses a life time counter to keep track of client activity for the Subscription. The life time
			* counter of a Subscription is incremented by one whenever the publishing interval expires and it is reset
			* to zero on every Subscription-related client activity (e.g. when the server receives a publish request). When the
			* life time counter reaches the threshold provided by this method the server deletes the Subscription.
			*
			* In order to ensure regular client activity in case the Subscription has no notifications to publish,
			* the server publishes keep-alive messages when a given number of publishing intervals have elapsed without
			* notifications being available at the server (see setMaxKeepAliveCount()). Therefore, the life time count
			* depends on the maximum keep-alive count of the Subscription. The life time count should always be
			* set to at least three times the maximum keep-alive count.
			*
			* @param lifeTimeCount	When the publishing interval of the Subscription has elapsed this number of times,
			*						the Subscription will be deleted from the server. This value should be not less than
			*						three times the maximum keep-alive count. Please note that the server may revise
			*						the provided value.
			*
			* @see setMaxKeepAliveCount() getRevisedLifeTimeCount()
			*
			* @note The default value is the value 60.
			* @note Please use update() to apply changes to this parameter if the Subscription is already connected. */
			EnumStatusCode setLifeTimeCount(OTUInt32 lifeTimeCount);

			/*! Returns the revised life time count that has been assigned by the
			* server. This value is set automatically during the connect operation.
			*
			* @see setLifeTimeCount() */
			OTUInt32 getRevisedLifeTimeCount() const;

			/*! The number of consecutive empty publish cycles after that the Server has to send a keep alive message.
			*
			* The server is allowed to adapt this value to its capabilities (see setMaxKeepAliveCount()). */
			OTUInt32 getMaxKeepAliveCount() const;
			/*! Sets the threshold for the Subscription's keep-alive counter. Whenever the keep-alive counter
			* reaches the provided threshold, the server publishes a keep-alive notification message for
			* this Subscription.
			*
			* The server uses a keep-alive counter to inform the client that the Subscription is still alive
			* and to provoke activity from the client in order to prevent the Subscription from being deleted
			* (see setLifeTimeCount()). The keep-alive counter is incremented by one whenever the publishing interval
			* expires and is reset to zero when the server publishes any notification message (including the keep-alive
			* message) for the Subscription.
			*
			* @param maxKeepAliveCount	The maximum value of the keep alive counter. When the counter reaches this threshold,
			*							the server publishes a keep-alive notification message for this Subscription
			*							and resets the counter. Please note that the server may revise
			*							the provided value.
			*
			* @see setLifeTimeCount() getRevisedMaxKeepAliveCount()
			*
			* @note The default value is the value 10.
			* @note Please use update() to apply changes to this parameter if the Subscription is already connected. */
			EnumStatusCode setMaxKeepAliveCount(OTUInt32 maxKeepAliveCount);

			/*! Returns the revised keep alive count that has been assigned by the server. This value is set automatically
			* during the connect operation.
			*
			* @see setMaxKeepAliveCount() */
			OTUInt32 getRevisedMaxKeepAliveCount() const;

			/*! Returns the maximum number of notifications that a server sends in one publish response.
			* A value of 0 means that there is no limit.
			*
			* @see setMaxNotificationsPerPublish() */
			OTUInt32 getMaxNotificationsPerPublish() const;
			/*! Sets the maximum number of notifications that a client wishes to receive per publish response.
			*
			* Every queued data change or event of every MonitoredItem of this subscription is a notification.
			* If a server reaches this number, then it splits the notifications into several PublishResponses and sends the
			* several PublishResponses in a row.
			* The callbacks onDataChange() or onEventsReceived() are triggered for every received PublishResponse that contains the related notification type.
			* If the client does not want to impose restrictions on the message size of the publish response,
			* this parameter should be set to 0.
			*
			* @note Default value is 0.
			* @note Please use update() to apply changes to this parameter if the Subscription is already connected. */
			EnumStatusCode setMaxNotificationsPerPublish(OTUInt32 maxNotificationsPerPublish);

			/*! Returns whether publishing of notification messages is enabled for this Subscription
			*
			* @see setPublishingEnabled() */
			bool getPublishingEnabled() const;
			/*! Defines whether publishing of notification messages (i.e. data changes or events)
			* is enabled or not for this Subscription.
			*
			* @note Same as disablePublishing() or enablePublishing()
			*
			* @note		Publishing is enabled by default. */
			EnumStatusCode setPublishingEnabled(bool publishingEnabled);

			/*! Returns whether republishing of lost notifications is enabled.
			*
			* @see setRePublishingEnabled */
			bool getRePublishingEnabled() const;
			/*! Enables or disables republishing in case of lost notifications.
			*
			* RePublishing is a UA specific way to force the server to re-send lost notifications of a subscription.
			* If republishing is enabled lost notifications are again requested from server (if available).
			* By default republishing is enabled for a subscription.

			* It is recommended to enable republishing for subscriptions which need to receive every single notification (e.g.
			* subscriptions receiving events, ...). For subscriptions which simply are interested in newest data values republishing is not necessary.
			*
			* In case of lost notifications (either republishing disabled or server cannot provide lost notifications) the error EnumStatusCode_BadSequenceNumberInvalid
			* is reported via the error callback. */
			EnumStatusCode setRePublishingEnabled(bool rePublishingEnabled);

			/*! Returns the priority which is assigned to this Subscription.
			*
			* @see setPriority() */
			unsigned char getPriority() const;
			/*! The relative priority of the Subscription. If several Subscriptions are ready to publish
			* notification messages (Data changes, event notifications), the server uses the priority to
			* decide which Subscription is allowed to publish first. In this case, the Subscription with higher
			* priority will be allowed to publish its notification messages first.
			*
			* Use priority value "0" if the Subscription does not require special priority settings (recommended!).
			*
			* @note The default value is 0.
			* @note Please use update() to apply changes to this parameter if the Subscription is already connected. */
			EnumStatusCode setPriority(unsigned char priority);


			//////////////////////////////////////////////////////////////////////////
			// Methods of class Subscription
			//////////////////////////////////////////////////////////////////////////

			/*! Connects the Subscription to the Server.
			* If MonitoredItems are configured to report data changes the reporting will start after a successful connect.
			*
			* @param deep If true, not only the Subscription but also the added MonitoredItems will be connected.
			*
			* @see disconnect() */
			EnumStatusCode connect(bool deep);

			/*! Disconnects the Subscription from the server. All contained MonitoredItems are also disconnected. */
			EnumStatusCode disconnect();

			/*! Returns true, if the Subscription is connected (i.e. registered at the server), false otherwise. */
			bool isConnected() const;

			/*! Adds a MonitoredItem to the Subscription. Changes will only take effect in the server
			* after connecting the added MonitoredItem via connect(true) or by calling MonitoredItem::connect()
			* on the added item.
			*
			* @param monitoredItem The MonitoredItem to add
			*
			* @see connect() addMonitoredItems()
			*
			* @note Preferred sequence is adding monitored items to a subscription after the subscription is already added to a session.
			*       Otherwise (if the subscription will never be added to a session) deletion of a subscription requires that the monitored
			*       items are explicitly removed via removeAllMonitoredItems().
			*       Otherwise a memory leak will be produced because subscription and monitored items stay alive by a linkage between them.
			*       If a subscription is added to a session, the SDK takes care of breaking this linkage. */
			EnumStatusCode addMonitoredItem(Client::MonitoredItemPtr monitoredItem);

			/*! Adds an array of MonitoredItems to the Subscription. Changes will only take effect in the server
			* after connecting the added MonitoredItems via connectMonitoredItems().
			*
			* @param items The MonitoredItems to add to the Subscription
			*
			* @see connect()
			*
			* @note Preferred sequence is adding monitored items to a subscription after the subscription is already added to a session.
			*       Otherwise (if the subscription will never be added to a session) deletion of a subscription requires that the monitored
			*       items are explicitly removed via removeAllMonitoredItems().
			*       Otherwise a memory leak will be produced because subscription and monitored items stay alive by a linkage between them.
			*       If a subscription is added to a session, the SDK takes care of breaking this linkage. */
			EnumStatusCode addMonitoredItems(const std::vector<Client::MonitoredItemPtr>& items);

			/*! Connects several MonitoredItems, that belong to this Subscription.
			* @param items The MonitoredItems to connect
			* @param pConnectResults optional array of operational results for each connect, can be NULL */
			EnumStatusCode connectMonitoredItems(std::vector<Client::MonitoredItemPtr>& items, std::vector<EnumStatusCode> *pConnectResults);

			/*! Returns the MonitoredItems that belong to this subscription. */
			std::vector<Client::MonitoredItemPtr> getMonitoredItems();

			/*! Removes the given MonitoredItem from the Subscription. The given @p monitoredItem will
			* be removed from the Subscription on the server immediately.
			*
			* @param monitoredItem The MonitoredItem to remove from the Subscription */
			EnumStatusCode removeMonitoredItem(Client::MonitoredItemPtr monitoredItem);

			/*! Removes the given MonitoredItems from the Subscription. The given @p items will
			* be removed from the Subscription on the server immediately.
			*
			* @param items The MonitoredItem to remove from the Subscription */
			EnumStatusCode removeMonitoredItems(const std::vector<Client::MonitoredItemPtr>& items);

			/*! Removes all MonitoredItems from the Subscription. The items will be removed from
			* the Subscription on the server immediately. */
			EnumStatusCode removeAllMonitoredItems();

			/*! Applies local changes to the given list of MonitoredItems in the server. The following
			* MonitoredItem parameters are updated in the server:
			* @li SamplingInterval
			* @li Filter
			* @li QueueSize
			* @li DiscardOldest
			*
			* The Subscription must be connected when this method is called.
			*
			* @param items The list of MonitoredItems that contain local modifications */
			EnumStatusCode updateMonitoredItems(const std::vector<Client::MonitoredItemPtr>& items);

			/*! Convenience methods to apply local changes to MonitoredItems that have been changed
			* since the last update in the server.
			*
			* @see updateMonitoredItems() */
			EnumStatusCode updateChangedMonitoredItems();

			/*! Sets the monitoring mode of all the MonitoredItems contained in this Subscription.
			* Changes are applied immediately in the server.
			*
			* @param eMonitoringMode The monitoring mode to apply to all items
			*
			* @see setMonitoredItemsMonitoringMode() */
			EnumStatusCode setAllMonitoredItemsMonitoringMode(EnumMonitoringMode eMonitoringMode);

			/*! Sets the monitoring mode of the given MonitoredItems contained in this Subscription.
			* Changes are applied immediately in the server.
			*
			* @param monitoredItems The list of MonitoredItems for which you want to change the monitoring mode
			* @param eMonitoringMode The monitoring mode to apply to the given items
			*
			* @see setAllMonitoredItemsMonitoringMode() */
			EnumStatusCode setMonitoredItemsMonitoringMode(const std::vector<Client::MonitoredItemPtr>& monitoredItems, EnumMonitoringMode eMonitoringMode);

			/*! Enable publishing of notification messages for this Subscription.
			*
			* @note same as  setPublishingEnabled(true) */
			EnumStatusCode enablePublishing();

			/*! Disables publishing of notification messages for this Subscription.
			*
			* @note same as  setPublishingEnabled(false) */
			EnumStatusCode disablePublishing();

			/*! Applies local changes to the following Subscription parameters in the server:
			* @li PublishingInterval
			* @li LifeTimeCount
			* @li MaxKeepAliveCount
			* @li MaxNotificationsPerPublish,
			* @li Priority
			*
			* The Subscription must be connected when this method is called, otherwise an error
			* code will be returned. If successful, the RevisedLifetimeCount, RevisedMaxKeepAliveCount,
			* and RevisedPublishingInterval will be updated with the values received in the server response.
			*
			* @see setPublishingInterval() setLifeTimeCount() setMaxKeepAliveCount() setMaxNotificationsPerPublish() setPriority() */
			EnumStatusCode update();

			/*! Refreshes the current state of all monitored conditions
			*
			* The Subscription must be connected when this method is called, otherwise an error code will be returned.
			* If successful, the subscription will receive notifications for all event monitored items.
			* For each event monitored item in the subscription the following sequence of notifications shall be received:
			*
			* @li An event of type RefreshStartEventType
			* @li The current status of all retained conditions notifying the monitored item
			* @li An event of type RefreshEndEventType
			*
			* The notification of events can start before the method returns.
			*
			* @return	EnumStatusCode_Good if refresh was successful.
			*			EnumStatusCode_BadInvalidState if session is not connected
			*			EnumStatusCode_BadSubscriptionIdInvalid if subscription is unknown in server
			*			EnumStatusCode_BadRefreshInProgress if another refresh of this subscription is already in progress
			*
			* @see onEventsReceived(), MonitoredItem() */
			EnumStatusCode conditionRefresh();

			/////////////////////////////////////////////////////////////////////////
			// Callbacks
			/////////////////////////////////////////////////////////////////////////

			/*! Callback for data changes. This function must be overridden in a derived class to obtain data
			* change events.
			*
			* @param items	The MonitoredItems that have received data changes. This vector may contain a NULL pointer if
			*				the client receives a notification for a MonitoredItem has has been already removed.
			* @param values	The received data changes. The number of elements in this vector matches the number of
			*				notified @p items. */
			virtual void onDataChange(const std::vector<Client::MonitoredItem*>& items, const std::vector<DataValue>& values);

			/*! Callback for reported events. This function must be overridden in a derived class to obtain
			* event reports
			*
			* The reported events are filtered by the monitored items where clause of the filter.
			* The received event fields match the specified select clause of the filter.
			*
			* In case of a queue overflow of a monitored item in the server, an event of type RefreshRequiredEventType is reported.
			* It indicates that due to queue overflow some events are missing. An application can perform a conditionRefresh to update
			* the current states of the monitored conditions.
			* The reporting of this event type ignores any filtering.
			*
			* @param items	The MonitoredItems that have received events. This vector may contain a NULL pointer if
			*				the client receives a notification for a MonitoredItem has has been already removed.
			* @param values	The received events. The number of elements in this vector matches the number of
			*				notified @p items.
			* @note	The EventFields in @p values can be null if the selected value is not accessible, e.g. if not all
			*		events have a selected property
			*
			* @see conditionRefresh() */
			virtual void onEventsReceived(const std::vector<Client::MonitoredItem*>& items, const std::vector<EventFieldList>& values);

			/*! Error callback. This must be overridden in a derived class in order to receive error notifications.
			*
			* Typical contexts in which this callback can be called are errors in following situations:
			* @li creating the Subscription on the server (connect)
			* @li deleting the Subscription
			* @li setting the publishing mode
			* @li modifying the Subscription
			* @li processing notification message or publish response from server
			* @li notification messages from server were missing
			*
			* @param status The error condition */
			virtual void onError(EnumStatusCode status);

			/*! Connection status change callback. This callback will be called whenever the connection status of the Subscription
			* changes.
			*
			* @param status		If true, the Subscription is connected and data changes or events may arrive at MonitoredItems. If false,
			*					the Subscription is disconnected and no data changes or events may arrive at MonitoredItems. */
			virtual void onStatusChange(bool status);

		private:
			/*! For internal use only */
			void initMembers();

			/*! Forbid use assignment operator */
			Subscription& operator=(const Subscription&);
			/*! Forbid use of copy constructor */
			Subscription(const Subscription&);
		};
		typedef ObjectPointer<Subscription> SubscriptionPtr;
		typedef ObjectPointer<const Subscription> SubscriptionConstPtr;

	} // end Client namespace
} // toolbox namespace end
#endif
#endif	// CLIENTSESSION_H
