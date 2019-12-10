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

#ifndef ISUBSCRIPTIONDIAGNOSTICSDATATYPE_H
#define ISUBSCRIPTIONDIAGNOSTICSDATATYPE_H

#include "SubscriptionDiagnosticsDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The SubscriptionDiagnosticsDataType contains diagnostic information about subscriptions. */
	class TBC_EXPORT ISubscriptionDiagnosticsDataType
	{
	public:
		/*! Destructor */
		virtual ~ISubscriptionDiagnosticsDataType(){};

		/*! Returns the server-assigned identifier of the session the subscription belongs to. */
		virtual const INodeId* getSessionId() const = 0;
		/*! Sets the server-assigned identifier of the session the subscription belongs to. */
		virtual EnumStatusCode setSessionId(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value) = 0;

		/*! Returns the server-assigned identifier of the subscription. */
		virtual OTUInt32 getSubscriptionId() const = 0;
		/*! Sets the server-assigned identifier of the subscription. */
		virtual void setSubscriptionId(const OTUInt32& value) = 0;

		/*! Returns the priority the client assigned to the subscription. */
		virtual OTUInt8 getPriority() const = 0;
		/*! Sets the priority the client assigned to the subscription. */
		virtual void setPriority(const OTUInt8& value) = 0;

		/*! Returns the publishing interval of the subscription in milliseconds. */
		virtual double getPublishingInterval() const = 0;
		/*! Sets the publishing interval of the subscription in milliseconds. */
		virtual void setPublishingInterval(const double& value) = 0;

		/*! Returns the maximum keep-alive count of the subscription. */
		virtual OTUInt32 getMaxKeepAliveCount() const = 0;
		/*! Sets the maximum keep-alive count of the subscription. */
		virtual void setMaxKeepAliveCount(const OTUInt32& value) = 0;

		/*! Returns the maximum lifetime count of the subscription. */
		virtual OTUInt32 getMaxLifetimeCount() const = 0;
		/*! Sets the maximum lifetime count of the subscription. */
		virtual void setMaxLifetimeCount(const OTUInt32& value) = 0;

		/*! Returns the maximum number of notifications per publish response. */
		virtual OTUInt32 getMaxNotificationsPerPublish() const = 0;
		/*! Sets the maximum number of notifications per publish response. */
		virtual void setMaxNotificationsPerPublish(const OTUInt32& value) = 0;

		/*! Returns whether publishing is enabled for the subscription. */
		virtual bool getPublishingEnabled() const = 0;
		/*! Sets whether publishing is enabled for the subscription. */
		virtual void setPublishingEnabled(const bool& value) = 0;

		/*! Returns the number of ModifySubscription requests received for the subscription. */
		virtual OTUInt32 getModifyCount() const = 0;
		/*! Sets the number of ModifySubscription requests received for the subscription. */
		virtual void setModifyCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has been enabled. */
		virtual OTUInt32 getEnableCount() const = 0;
		/*! Sets the number of times the subscription has been enabled. */
		virtual void setEnableCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has been disabled. */
		virtual OTUInt32 getDisableCount() const = 0;
		/*! Sets the number of times the subscription has been disabled. */
		virtual void setDisableCount(const OTUInt32& value) = 0;

		/*! Returns the number of Republish Service requests that have been received and
		* processed for the subscription. */
		virtual OTUInt32 getRepublishRequestCount() const = 0;
		/*! Sets the number of Republish Service requests that have been received and
		* processed for the subscription. */
		virtual void setRepublishRequestCount(const OTUInt32& value) = 0;

		/*! Returns the total number of messages that have been requested to be republished for
		* the subscription. */
		virtual OTUInt32 getRepublishMessageRequestCount() const = 0;
		/*! Sets the total number of messages that have been requested to be republished for
		* the subscription. */
		virtual void setRepublishMessageRequestCount(const OTUInt32& value) = 0;

		/*! Returns the number of messages that have been successfully republished for the
		* subscription. */
		virtual OTUInt32 getRepublishMessageCount() const = 0;
		/*! Sets the number of messages that have been successfully republished for the
		* subscription. */
		virtual void setRepublishMessageCount(const OTUInt32& value) = 0;

		/*! Returns the total number of TransferSubscriptions Service requests that have been
		* received for the subscription. */
		virtual OTUInt32 getTransferRequestCount() const = 0;
		/*! Sets the total number of TransferSubscriptions Service requests that have been
		* received for the subscription. */
		virtual void setTransferRequestCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has been transferred to an alternate client. */
		virtual OTUInt32 getTransferredToAltClientCount() const = 0;
		/*! Sets the number of times the subscription has been transferred to an alternate client. */
		virtual void setTransferredToAltClientCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has been transferred to an alternate
		* session for the same client. */
		virtual OTUInt32 getTransferredToSameClientCount() const = 0;
		/*! Sets the number of times the subscription has been transferred to an alternate
		* session for the same client. */
		virtual void setTransferredToSameClientCount(const OTUInt32& value) = 0;

		/*! Returns the number of Publish Service requests that have been received and
		* processed for the subscription. */
		virtual OTUInt32 getPublishRequestCount() const = 0;
		/*! Sets the number of Publish Service requests that have been received and
		* processed for the subscription. */
		virtual void setPublishRequestCount(const OTUInt32& value) = 0;

		/*! Returns the number of data change Notifications sent by the subscription. */
		virtual OTUInt32 getDataChangeNotificationsCount() const = 0;
		/*! Sets the number of data change Notifications sent by the subscription. */
		virtual void setDataChangeNotificationsCount(const OTUInt32& value) = 0;

		/*! Returns the number of Event Notifications sent by the subscription. */
		virtual OTUInt32 getEventNotificationsCount() const = 0;
		/*! Sets the number of Event Notifications sent by the subscription. */
		virtual void setEventNotificationsCount(const OTUInt32& value) = 0;

		/*! Returns the total number of Notifications sent by the subscription. */
		virtual OTUInt32 getNotificationsCount() const = 0;
		/*! Sets the total number of Notifications sent by the subscription. */
		virtual void setNotificationsCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has entered the LATE State, i.e. the
		* number of times the publish timer expires and there are unsent notifications. */
		virtual OTUInt32 getLatePublishRequestCount() const = 0;
		/*! Sets the number of times the subscription has entered the LATE State, i.e. the
		* number of times the publish timer expires and there are unsent notifications. */
		virtual void setLatePublishRequestCount(const OTUInt32& value) = 0;

		/*! Returns the number of times the subscription has entered the KEEPALIVE State. */
		virtual OTUInt32 getCurrentKeepAliveCount() const = 0;
		/*! Sets the number of times the subscription has entered the KEEPALIVE State. */
		virtual void setCurrentKeepAliveCount(const OTUInt32& value) = 0;

		/*! Returns the current lifetime count of the subscription. */
		virtual OTUInt32 getCurrentLifetimeCount() const = 0;
		/*! Sets the current lifetime count of the subscription. */
		virtual void setCurrentLifetimeCount(const OTUInt32& value) = 0;

		/*! Returns the number of unacknowledged messages saved in the republish queue. */
		virtual OTUInt32 getUnacknowledgedMessageCount() const = 0;
		/*! Sets the number of unacknowledged messages saved in the republish queue. */
		virtual void setUnacknowledgedMessageCount(const OTUInt32& value) = 0;

		/*! Returns the number of messages that were discarded before they were
		* acknowledged. */
		virtual OTUInt32 getDiscardedMessageCount() const = 0;
		/*! Sets the number of messages that were discarded before they were
		* acknowledged. */
		virtual void setDiscardedMessageCount(const OTUInt32& value) = 0;

		/*! Returns the total number of monitored items of the subscription, including the disabled
		* monitored items. */
		virtual OTUInt32 getMonitoredItemCount() const = 0;
		/*! Sets the total number of monitored items of the subscription, including the disabled
		* monitored items. */
		virtual void setMonitoredItemCount(const OTUInt32& value) = 0;

		/*! Returns the number of disabled monitored items of the subscription. */
		virtual OTUInt32 getDisabledMonitoredItemCount() const = 0;
		/*! Sets the number of disabled monitored items of the subscription. */
		virtual void setDisabledMonitoredItemCount(const OTUInt32& value) = 0;

		/*! Returns the number of times a monitored item dropped notifications because of a
		* queue overflow. */
		virtual OTUInt32 getMonitoringQueueOverflowCount() const = 0;
		/*! Sets the number of times a monitored item dropped notifications because of a
		* queue overflow. */
		virtual void setMonitoringQueueOverflowCount(const OTUInt32& value) = 0;

		/*! Returns the sequence number for the next notification message. */
		virtual OTUInt32 getNextSequenceNumber() const = 0;
		/*! Sets the sequence number for the next notification message. */
		virtual void setNextSequenceNumber(const OTUInt32& value) = 0;

		/*! Returns the number of times a monitored item in the subscription has generated an
		* Event of type EventQueueOverflowEventType. */
		virtual OTUInt32 getEventQueueOverFlowCount() const = 0;
		/*! Sets the number of times a monitored item in the subscription has generated an
		* Event of type EventQueueOverflowEventType. */
		virtual void setEventQueueOverFlowCount(const OTUInt32& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const ISubscriptionDiagnosticsDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISubscriptionDiagnosticsDataType& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISubscriptionDiagnosticsDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const ISubscriptionDiagnosticsDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISubscriptionDiagnosticsDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISubscriptionDiagnosticsDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISubscriptionDiagnosticsDataType
} // end namespace

#endif	// ISUBSCRIPTIONDIAGNOSTICSDATATYPE_H
