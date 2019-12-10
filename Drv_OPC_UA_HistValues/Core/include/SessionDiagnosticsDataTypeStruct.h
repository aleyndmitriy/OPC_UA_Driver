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

#ifndef _SessionDiagnosticsDataTypeStruct_H_
#define _SessionDiagnosticsDataTypeStruct_H_

#include "NodeIdStruct.h"
#include "ApplicationDescriptionStruct.h"
#include "DateTimeStruct.h"
#include "ServiceCounterDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(SessionDiagnosticsDataTypeStruct::clear, cleanup)
//lint -sem(SessionDiagnosticsDataTypeStruct::init, initializer)
typedef struct TBCORE_IF SessionDiagnosticsDataTypeStruct
{
	/*!
	 * @brief Server-assigned identifier of the session.
	 */
	NodeIdStruct sessionId;

	/*!
	 * @brief The name of the session provided in the CreateSession request.
	 */
	OTChar* pSessionName;

	/*!
	 * @brief The description provided by the client in the CreateSession request.
	 */
	ApplicationDescriptionStruct clientDescription;

	/*!
	 * @brief The serverUri request in the CreateSession request.
	 */
	OTChar* pServerUri;

	/*!
	 * @brief The endpointUrl passed by the client to the CreateSession request.
	 */
	OTChar* pEndpointUrl;

	/*!
	 * @brief Array of LocaleIds specified by the client in the open session call.
	 */
	OTChar** ppLocaleIds;
	unsigned ppLocaleIds_count;

	/*!
	 * @brief The requested session timeout specified by the client in the open
	 * session call.
	 */
	double actualSessionTimeout;

	/*!
	 * @brief The maximum size for the response message sent to the client.
	 */
	OTUInt32 maxResponseMessageSize;

	/*!
	 * @brief The server timestamp when the client opens the session.
	 */
	DateTimeStruct clientConnectionTime;

	/*!
	 * @brief The server timestamp of the last request of the client in the context
	 * of the session
	 */
	DateTimeStruct clientLastContactTime;

	/*!
	 * @brief The number of subscriptions currently used by the session.
	 */
	OTUInt32 currentSubscriptionsCount;

	/*!
	 * @brief The number of MonitoredItems currently used by the session.
	 */
	OTUInt32 currentMonitoredItemsCount;

	/*!
	 * @brief The number of publish requests currently in the queue for the
	 * session.
	 */
	OTUInt32 currentPublishRequestsInQueue;

	/*!
	 * @brief Counter of allServices, identifying the number of received requests
	 * of any Services on the session.
	 */
	ServiceCounterDataTypeStruct totalRequestCount;

	/*!
	 * @brief Counter of all Services, identifying the number of Service requests
	 * that were rejected due to authorization failure.
	 */
	OTUInt32 unauthorizedRequestCount;

	/*!
	 * @brief Counter of the Read Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct readCount;

	/*!
	 * @brief Counter of the HistoryRead Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct historyReadCount;

	/*!
	 * @brief Counter of the Write Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct writeCount;

	/*!
	 * @brief Counter of the HistoryUpdate Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct historyUpdateCount;

	/*!
	 * @brief Counter of the Call Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct callCount;

	/*!
	 * @brief Counter of the CreateMonitoredItems Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct createMonitoredItemsCount;

	/*!
	 * @brief Counter of the ModifyMonitoredItems Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct modifyMonitoredItemsCount;

	/*!
	 * @brief Counter of the SetMonitoringMode Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct setMonitoringModeCount;

	/*!
	 * @brief Counter of the SetTriggering Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct setTriggeringCount;

	/*!
	 * @brief Counter of the DeleteMonitoredItems Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct deleteMonitoredItemsCount;

	/*!
	 * @brief Counter of the CreateSubscription Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct createSubscriptionCount;

	/*!
	 * @brief Counter of the ModifySubscription Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct modifySubscriptionCount;

	/*!
	 * @brief Counter of the SetPublishingMode Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct setPublishingModeCount;

	/*!
	 * @brief Counter of the Publish Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct publishCount;

	/*!
	 * @brief Counter of the Republish Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct republishCount;

	/*!
	 * @brief Counter of the TransferSubscriptions Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct transferSubscriptionsCount;

	/*!
	 * @brief Counter of the DeleteSubscriptions Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct deleteSubscriptionsCount;

	/*!
	 * @brief Counter of the AddNodes Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct addNodesCount;

	/*!
	 * @brief Counter of the AddReferences Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct addReferencesCount;

	/*!
	 * @brief Counter of the DeleteNodes Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct deleteNodesCount;

	/*!
	 * @brief Counter of the DeleteReferences Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct deleteReferencesCount;

	/*!
	 * @brief Counter of the Browse Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct browseCount;

	/*!
	 * @brief Counter of the BrowseNext Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct browseNextCount;

	/*!
	 * @brief Counter of the TranslateBrowsePathsToNodeIds Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct translateBrowsePathsToNodeIdsCount;

	/*!
	 * @brief Counter of the QueryFirst Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct queryFirstCount;

	/*!
	 * @brief Counter of the QueryNext Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct queryNextCount;

	/*!
	 * @brief Counter of the RegisterNodes Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct registerNodesCount;

	/*!
	 * @brief Counter of the UnregisterNodes Service, identifying the number of received
	 * requests of this Service on the session.
	 */
	ServiceCounterDataTypeStruct unregisterNodesCount;


	SessionDiagnosticsDataTypeStruct();
	SessionDiagnosticsDataTypeStruct(const SessionDiagnosticsDataTypeStruct&);

	EnumStatusCode set(const SessionDiagnosticsDataTypeStruct&);
	EnumStatusCode get(SessionDiagnosticsDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SessionDiagnosticsDataType&);
	EnumStatusCode get(OpcUa_SessionDiagnosticsDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const SessionDiagnosticsDataTypeStruct& operator=(const SessionDiagnosticsDataTypeStruct& cp);
	bool operator==(const SessionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator!=(const SessionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator<(const SessionDiagnosticsDataTypeStruct& toCompare) const;
	bool operator>(const SessionDiagnosticsDataTypeStruct& toCompare) const;

	int compare(const SessionDiagnosticsDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~SessionDiagnosticsDataTypeStruct(void);
} SessionDiagnosticsDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
