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

#ifndef _SubscriptionDiagnosticsDataTypeStruct_H_
#define _SubscriptionDiagnosticsDataTypeStruct_H_

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(SubscriptionDiagnosticsDataTypeStruct::clear, cleanup)
//lint -sem(SubscriptionDiagnosticsDataTypeStruct::init, initializer)
typedef struct TBCORE_IF SubscriptionDiagnosticsDataTypeStruct
{
	/*! @brief Server-assigned identifier of the session the subscription belongs to. */
	NodeIdStruct sessionId;

	/*! @brief Server-assigned identifier of the subscription. */
	OTUInt32 subscriptionId;

	/*! @brief The priority the client assigned to the subscription. */
	double publishingInterval;

	/*! @brief The publishing interval of the subscription in milliseconds. */
	OTUInt8 priority;

	/*! @brief The maximum keep-alive count of the subscription. */
	OTUInt32 maxKeepAliveCount;

	/*! @brief The maximum lifetime count of the subscription. */
	OTUInt32 maxLifetimeCount;

	/*! @brief The maximum number of notifications per publish response. */
	OTUInt32 maxNotificationsPerPublish;

	/*! @brief Whether publishing is enabled for the subscription. */
	bool publishingEnabled;

	/*! @brief The number of ModifySubscription requests received for the subscription. */
	OTUInt32 modifyCount;

	/*! @brief The number of times the subscription has been enabled. */
	OTUInt32 enableCount;

	/*! @brief The number of times the subscription has been disabled.
	 */
	OTUInt32 disableCount;

	/*! @brief The number of Republish Service requests that have been received and
	 * processed for the subscription. */
	OTUInt32 republishRequestCount;

	/*! @brief The total number of messages that have been requested to be republished for
	 * the subscription */
	OTUInt32 republishMessageRequestCount;

	/*! @brief The number of messages that have been successfully republished for the
	 * subscription. */
	OTUInt32 republishMessageCount;

	/*! @brief The total number of TransferSubscriptions Service requests that have been
	 * received for the subscription. */
	OTUInt32 transferRequestCount;

	/*! @brief The number of times the subscription has been transferred to an alternate
	 * client. */
	OTUInt32 transferredToAltClientCount;

	/*! @brief The number of times the subscription has been transferred to an alternate
	 * session for the same client. */
	OTUInt32 transferredToSameClientCount;

	/*! @brief The number of Publish Service requests that have been received and
	 * processed for the subscription. */
	OTUInt32 publishRequestCount;

	/*! @brief The number of data change Notifications sent by the subscription. */
	OTUInt32 dataChangeNotificationsCount;

	/*! @brief The number of Event Notifications sent by the subscription. */
	OTUInt32 eventNotificationsCount;

	/*! @brief The total number of Notifications sent by the subscription. */
	OTUInt32 notificationsCount;

	/*! @brief The number of times the subscription has entered the LATE State, i.e. the
	 * number of times the publish timer expires and there are unsent notifications. */
	OTUInt32 latePublishRequestCount;

	/*! @brief The number of times the subscription has entered the KEEPALIVE State. */
	OTUInt32 currentKeepAliveCount;

	/*! @brief The current lifetime count of the subscription. */
	OTUInt32 currentLifetimeCount;

	/*! @brief The number of unacknowledged messages saved in the republish queue. */
	OTUInt32 unacknowledgedMessageCount;

	/*! @brief The number of messages that were discarded before they were
	 * acknowledged. */
	OTUInt32 discardedMessageCount;

	/*! @brief The total number of monitored items of the subscription, including the disabled
	 * monitored items. */
	OTUInt32 monitoredItemCount;

	/*! @brief The number of disabled monitored items of the subscription. */
	OTUInt32 disabledMonitoredItemCount;

	/*! @brief The number of times a monitored item dropped notifications because of a
	 * queue overflow. */
	OTUInt32 monitoringQueueOverflowCount;

	/*! @brief Sequence number for the next notification message. */
	OTUInt32 nextSequenceNumber;

	/*! @brief The number of times a monitored item in the subscription has generated an
	 * Event of type EventQueueOverflowEventType. */
	OTUInt32 eventQueueOverFlowCount;


	SubscriptionDiagnosticsDataTypeStruct();
	SubscriptionDiagnosticsDataTypeStruct(const SubscriptionDiagnosticsDataTypeStruct&);

	EnumStatusCode set(const SubscriptionDiagnosticsDataTypeStruct&);
	EnumStatusCode get(SubscriptionDiagnosticsDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SubscriptionDiagnosticsDataType&);
	EnumStatusCode get(OpcUa_SubscriptionDiagnosticsDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const SubscriptionDiagnosticsDataTypeStruct& operator=(const SubscriptionDiagnosticsDataTypeStruct& cp);
	bool operator==(const SubscriptionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator!=(const SubscriptionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator<(const SubscriptionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator>(const SubscriptionDiagnosticsDataTypeStruct& toCompare) const;

	int compare(const SubscriptionDiagnosticsDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~SubscriptionDiagnosticsDataTypeStruct(void);
} SubscriptionDiagnosticsDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
