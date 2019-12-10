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

#ifndef SERVERSUBSCRIPTION_H
#define SERVERSUBSCRIPTION_H
#include "Base.h"
#include "Enums.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Session;
		class MonitoredItem;
		typedef ObjectPointer<MonitoredItem> MonitoredItemPtr;
		typedef ObjectPointer<const MonitoredItem> MonitoredItemConstPtr;
		class CreateMonitoredItemRequest;
		typedef ObjectPointer<CreateMonitoredItemRequest> CreateMonitoredItemRequestPtr;
		typedef ObjectPointer<const CreateMonitoredItemRequest> CreateMonitoredItemRequestConstPtr;
		class ModifyMonitoredItemRequest;
		typedef ObjectPointer<ModifyMonitoredItemRequest> ModifyMonitoredItemRequestPtr;
		typedef ObjectPointer<const ModifyMonitoredItemRequest> ModifyMonitoredItemRequestConstPtr;
		class DeleteMonitoredItemRequest;
		typedef ObjectPointer<DeleteMonitoredItemRequest> DeleteMonitoredItemRequestPtr;
		typedef ObjectPointer<const DeleteMonitoredItemRequest> DeleteMonitoredItemRequestConstPtr;
		class DeleteSubscriptionRequest;
		typedef ObjectPointer<DeleteSubscriptionRequest> DeleteSubscriptionRequestPtr;
		typedef ObjectPointer<const DeleteSubscriptionRequest> DeleteSubscriptionRequestConstPtr;
	}

	namespace Server
	{
		/*! The Subscription class represents a subscription that has been created by
		* an OPC UA client to monitor data changes and/or events. */
		class TBC_EXPORT Subscription
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Subscription(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			Subscription(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Subscription();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Subscription
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the session to which this subscription is bound. */
			ObjectPointer<Server::Session> getSession();
			/*! @overload */
			ObjectPointer<const Server::Session> getSession() const;

			/*! Returns the monitored items that have been created for this subscription. */
			std::vector<Server::MonitoredItemPtr> getMonitoredItems();
			/*! @overload */
			std::vector<Server::MonitoredItemConstPtr> getMonitoredItems() const;

			/*! Returns the publishing interval (in milliseconds) of this subscription. */
			double getPublishingInterval() const;
			/*! Sets the (revised) publishing interval (in milliseconds) of this subscription.
			* The publishing interval defines the cycle time in which the server sends notifications
			* (data changes, events or status changes) periodically to the client.
			*
			* @param publishingInterval		The publishing interval (in milliseconds). The value 0 is invalid.
			*
			* @note	This method may be called only inside the onCreate() or onModify() callback method
			*		in order to revise the value requested by the client. */
			EnumStatusCode setPublishingInterval(double publishingInterval);

			/*! Returns the maximum lifetime count of the subscription.
			*
			* @see setLifetimeCount() */
			OTUInt32 getLifetimeCount() const;
			/*! Sets the (revised) maximum lifetime count of the subscription. The lifetime count should be
			* equal or greater than 3 times the (revised) maximum keep-alive count.
			*
			* The server uses a life time counter to keep track of client activity for the subscription. The life time
			* counter of a subscription is incremented by one whenever the publishing interval expires and it is reset
			* to zero on every subscription-related client activity (e.g. when the server receives a publish request). When the
			* life time counter reaches the threshold provided by this method the server deletes the subscription.
			*
			* In order to ensure regular client activity in case the subscription has no notifications to publish,
			* the server publishes keep-alive messages when a given number of publishing intervals have elapsed without
			* notifications being available at the server (see setMaxKeepAliveCount()). Therefore, the life time count
			* depends on the maximum keep-alive count of the subscription. The life time count should always be
			* set to at least three times the maximum keep-alive count.
			*
			* @param lifetimeCount		The maximum lifetime count. This parameter should be at least three times the
			*							maximum keep-alive count.
			*
			* @note	This method may be called only inside the onCreate() or onModify() callback method
			*		in order to revise the value requested by the client. */
			EnumStatusCode setLifetimeCount(OTUInt32 lifetimeCount);

			/*! Returns the maximum keep alive count of this subscription.
			*
			* @see setMaxKeepAliveCount() */
			OTUInt32 getMaxKeepAliveCount() const;
			/*! Sets the (revised) maximum of the subscription's keep-alive counter. Whenever the keep-alive counter
			* reaches the provided maximum, the server publishes a keep-alive notification message for
			* this subscription.
			*
			* The server uses a keep-alive counter to inform the client that the subscription is still alive
			* and to provoke activity from the client in order to prevent the subscription from being deleted
			* (see setLifetimeCount()). The keep-alive counter is incremented by one whenever the publishing interval
			* expires and is reset to zero when the server publishes any notification message (including the keep-alive
			* message) for the subscription.
			*
			* @param maxKeepAliveCount	The maximum keep-alive count
			*
			* @note	This method may be called only inside the onCreate() or onModify() callback method
			*		in order to revise the value requested by the client. */
			EnumStatusCode setMaxKeepAliveCount(OTUInt32 maxKeepAliveCount);

			/*! Returns the maximum number of notifications that the server shall return with each publish response. */
			OTUInt32 getMaxNotificationsPerPublish() const;

			/*! Returns whether the client has enabled publishing of notification messages. */
			bool getPublishingEnabled() const;

			/*! Returns the priority of the subscription. */
			unsigned char getPriority() const;

			/*! Returns the identifier of the subscription. This identifier has been assigned by the SDK core. */
			OTUInt32 getId() const;

#define CTT_1_2_336_276
#ifdef CTT_1_2_336_276
			/*! Enables the validation of monitored item client handles.
			*
			* Usually the client handles of all monitored items within a subscription shall be unique since this is the
			* identifier within publish responses.
			* The SDK can validate this in various service calls and reject duplicates.
			*
			* In some situations (e.g. the response of a createMonitoredItems service does not return in time) the client can try to
			* create monitored items more than once and at server side the previously created monitored items would keep alive.
			* If this validation is enabled the SDK will remove the already existing monitored items with identical clientHandle.
			*
			* By default the validation is enabled. */
			EnumStatusCode enableClientHandleValidation(bool enableValidation) const;
#endif


			/////////////////////////////////////////////////////////////////////////
			// Callbacks
			/////////////////////////////////////////////////////////////////////////

			/*! Callback that is called when the client creates the subscription.
			* That allows the server implementation to verify and optionally revise the parameters
			* of the subscription that is being created.
			*
			* Note: A subscription may have a longer lifetime than a session.
			* Due to this fact the callbacks for creation and deletion are implemented at the Subscription class.
			* During creation of a subscription a valid session is obligatory. */
			virtual EnumStatusCode onCreate();

			/*! Callback that is called when the client changes parameters of the subscription.
			* That allows the server implementation to verify and optionally revise the parameters
			* of the subscription that is being created.
			*
			* The client may change the following parameters of the subscription:
			* @li PublishingInterval
			* @li LifetimeCount
			* @li MaxKeepAliveCount
			* @li MaxNotificationsPerPublish (cannot be revised)
			* @li Priority (cannot be revised) */
			virtual EnumStatusCode onModify();

			/*! Callback that is called when a subscription is deleted.
			*
			* The response to the client is sent after the request is completed (i.e. complete method is called).
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* Processing and completion of the request can be executed within a separate thread if blocking calls are necessary.
			*
			* Note: A subscription may have a longer lifetime than a session.
			* Due to this fact the callbacks for creation and deletion are implemented at the subscription class.
			* Subscription::getSession() may return NULL when called during handleDelete().
			* All related MonitoredItems are already deleted before this callback is called.
			*
			* @see handleDeleteMonitoredItems() */
			virtual EnumStatusCode handleDelete(DeleteSubscriptionRequestPtr deleteSubscriptionRequest);

			/*! Callback that is called when one or more monitored items are created.
			*
			* The server implementation is able to verify and optionally revise the parameters of the monitored items that are being created
			* or deny creation.
			* The response to the client is sent after all requests are completed (i.e. complete method is called).
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* Processing and completion of the requests can be executed within a separate thread if blocking calls are necessary. */
			virtual EnumStatusCode handleCreateMonitoredItems(const std::vector<Server::CreateMonitoredItemRequestPtr>& requests);

			/*! Callback that is called when parameters of one or more monitored items are modified.
			*
			* The server implementation is able to verify and optionally revise the parameters or deny
			* the requests of the monitored items that are being modified.
			* The response to the client is sent after all requests are completed (i.e. complete method is called).
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* Processing and completion of the requests can be executed within a separate thread if blocking calls are necessary. */
			virtual void handleModifyMonitoredItems(const std::vector<Server::ModifyMonitoredItemRequestPtr>& requests);

			/*! Callback that is called when the one or more monitored items are deleted.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* Processing and completion of the requests can be executes within a separate thread if blocking calls are necessary.
			*
			* @note If an application processes these requests asynchronously, the monitored items are still
			* available in the subscription until all requests are completed.
			* In this case it can happen that the onDelete callback is invoked with monitored items in it. */
			virtual void handleDeleteMonitoredItems(const std::vector<Server::DeleteMonitoredItemRequestPtr>& requests);

			/*! @brief Callback that is called whenever initial values need to be provided for monitored items.
			*
			* When a client creates monitored items or changes their monitoring mode from 'Disabled' to 'Reporting' or 'Sampling',
			* the server application needs to provide initial values for the monitored attribute of a node. Depending on
			* the data source for the monitored attribute, the server application may decide to either use the cached attribute
			* value or to update the cache by calling into an underlying system (e.g. by means of I/O).
			*
			* @param monitoredItems The monitored items that need an initial value
			*
			* @return	A vector with the same size as @p monitoredItems.
			*			@li EnumInitialValueProvider_CurrentAttributeValue:	Use the current attribute value of the monitored node (default)
			*			@li EnumInitialValueProvider_UnderlyingSystem:		Use a value retrieved from an underlying system, i.e. wait for
			*																the initial value to be provided by setAttribute()
			* @note This callback is called only for the first reporting monitored item on a node. For a further monitored item which changes
			* to reporting this callback won't be invoked and the current value is enqueued for reporting! */
			virtual std::vector<EnumInitialValueProvider> onProvideInitialValues(const std::vector<Server::MonitoredItem*>& monitoredItems);

		private:
			/*! For internal use only */
			void initMembers();

			/*! Subscriptions are always created by the SDK core. */
			Subscription();
			/*! Forbid use assignment operator */
			Subscription& operator=(const Subscription&);
			/*! Forbid use of copy constructor */
			Subscription(const Subscription&);
		};
		typedef ObjectPointer<Subscription> SubscriptionPtr;
		typedef ObjectPointer<const Subscription> SubscriptionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERSUBSCRIPTION_H
