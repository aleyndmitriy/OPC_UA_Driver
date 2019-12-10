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

#ifndef ISESSIONDIAGNOSTICSDATATYPE_H
#define ISESSIONDIAGNOSTICSDATATYPE_H

#include "SessionDiagnosticsDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"
#include "ApplicationDescription.h"
#include "IApplicationDescription.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "ServiceCounterDataType.h"
#include "IServiceCounterDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The SessionDiagnosticsDataType contains diagnostic information about client sessions. */
	class TBC_EXPORT ISessionDiagnosticsDataType
	{
	public:
		/*! Destructor */
		virtual ~ISessionDiagnosticsDataType(){};

		/*! Returns the server-assigned identifier of the session. */
		virtual const INodeId* getSessionId() const = 0;
		/*! Sets the server-assigned identifier of the session. */
		virtual EnumStatusCode setSessionId(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value) = 0;

		/*! Returns the name of the session provided in the CreateSession request. */
		virtual tstring getSessionName() const = 0;
		/*! Sets the name of the session provided in the CreateSession request. */
		virtual void setSessionName(const tstring& value) = 0;

		/*! Returns the application description provided by the client in the CreateSession request. */
		virtual const IApplicationDescription* getClientDescription() const = 0;
		/*! Sets the application description provided by the client in the CreateSession request. */
		virtual EnumStatusCode setClientDescription(const IApplicationDescription* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setClientDescription(const ApplicationDescription& value) = 0;

		/*! Returns the ServerUri parameter in the CreateSession request. */
		virtual tstring getServerUri() const = 0;
		/*! Sets the ServerUri parameter in the CreateSession request. */
		virtual void setServerUri(const tstring& value) = 0;

		/*! Returns the EndpointUrl passed by the client to the CreateSession request. */
		virtual tstring getEndpointUrl() const = 0;
		/*! Sets the EndpointUrl passed by the client to the CreateSession request. */
		virtual void setEndpointUrl(const tstring& value) = 0;

		/*! Returns an array of preferred locales specified by the client in the ActivateSession request. */
		virtual std::vector<tstring> getLocaleIds() const = 0;
		/*! Sets the array of preferred locales specified by the client in the ActivateSession request. */
		virtual EnumStatusCode setLocaleIds(const std::vector<tstring>& values) = 0;

		/*! Returns the requested session timeout specified by the client in the CreateSession request. */
		virtual double getActualSessionTimeout() const = 0;
		/*! Sets the requested session timeout specified by the client in the CreateSession request. */
		virtual void setActualSessionTimeout(const double& value) = 0;

		/*! Returns the maximum size for the response message sent to the client. */
		virtual OTUInt32 getMaxResponseMessageSize() const = 0;
		/*! Sets the maximum size for the response message sent to the client. */
		virtual void setMaxResponseMessageSize(const OTUInt32& value) = 0;

		/*! Returns the server timestamp when the client has opened the session. */
		virtual const IDateTime* getClientConnectionTime() const = 0;
		/*! Sets the server timestamp when the client has opened the session. */
		virtual EnumStatusCode setClientConnectionTime(const IDateTime* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setClientConnectionTime(const DateTime& value) = 0;

		/*! Returns the server timestamp of the last request of the client in the context
		* of the session. */
		virtual const IDateTime* getClientLastContactTime() const = 0;
		/*! Sets the server timestamp of the last request of the client in the context
		* of the session. */
		virtual EnumStatusCode setClientLastContactTime(const IDateTime* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setClientLastContactTime(const DateTime& value) = 0;

		/*! Returns the number of subscriptions currently used by the session. */
		virtual OTUInt32 getCurrentSubscriptionsCount() const = 0;
		/*! Sets the number of subscriptions currently used by the session. */
		virtual void setCurrentSubscriptionsCount(const OTUInt32& value) = 0;

		/*! Returns the number of MonitoredItems currently used by the session. */
		virtual OTUInt32 getCurrentMonitoredItemsCount() const = 0;
		/*! Sets the number of MonitoredItems currently used by the session. */
		virtual void setCurrentMonitoredItemsCount(const OTUInt32& value) = 0;

		/*! Returns the number of publish requests currently in the queue for the session. */
		virtual OTUInt32 getCurrentPublishRequestsInQueue() const = 0;
		/*! Sets the number of publish requests currently in the queue for the session. */
		virtual void setCurrentPublishRequestsInQueue(const OTUInt32& value) = 0;

		/*! Returns the counter of all services, identifying the number of received requests
		* of any services on the session. */
		virtual const IServiceCounterDataType* getTotalRequestCount() const = 0;
		/*! Sets the counter of all services, identifying the number of received requests
		* of any services on the session. */
		virtual EnumStatusCode setTotalRequestCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setTotalRequestCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of all services, identifying the number of service requests
		* that were rejected due to authorization failure. */
		virtual OTUInt32 getUnauthorizedRequestCount() const = 0;
		/*! Sets the counter of all services, identifying the number of service requests
		* that were rejected due to authorization failure. */
		virtual void setUnauthorizedRequestCount(const OTUInt32& value) = 0;

		/*! Returns the counter of the Read service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getReadCount() const = 0;
		/*! Sets the counter of the Read service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setReadCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setReadCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the HistoryRead service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getHistoryReadCount() const = 0;
		/*! Returns the counter of the HistoryRead service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setHistoryReadCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setHistoryReadCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the Write service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getWriteCount() const = 0;
		/*! Returns the counter of the Write service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setWriteCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setWriteCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the HistoryUpdate service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getHistoryUpdateCount() const = 0;
		/*! Sets the counter of the HistoryUpdate service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setHistoryUpdateCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setHistoryUpdateCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the Call service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getCallCount() const = 0;
		/*! Sets the counter of the Call service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setCallCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCallCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the CreateMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getCreateMonitoredItemsCount() const = 0;
		/*! Sets the counter of the CreateMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setCreateMonitoredItemsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCreateMonitoredItemsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the ModifyMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getModifyMonitoredItemsCount() const = 0;
		/*! Sets the counter of the ModifyMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setModifyMonitoredItemsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setModifyMonitoredItemsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the SetMonitoringMode service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getSetMonitoringModeCount() const = 0;
		/*! Sets the counter of the SetMonitoringMode service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setSetMonitoringModeCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSetMonitoringModeCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the SetTriggering service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getSetTriggeringCount() const = 0;
		/*! Sets the counter of the SetTriggering service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setSetTriggeringCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSetTriggeringCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the DeleteMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getDeleteMonitoredItemsCount() const = 0;
		/*! Sets the counter of the DeleteMonitoredItems service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setDeleteMonitoredItemsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setDeleteMonitoredItemsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the CreateSubscription service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getCreateSubscriptionCount() const = 0;
		/*! Sets the counter of the CreateSubscription service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setCreateSubscriptionCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCreateSubscriptionCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the ModifySubscription service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getModifySubscriptionCount() const = 0;
		/*! Sets the counter of the ModifySubscription service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setModifySubscriptionCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setModifySubscriptionCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the SetPublishingMode service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getSetPublishingModeCount() const = 0;
		/*! Sets the counter of the SetPublishingMode service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setSetPublishingModeCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSetPublishingModeCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the Publish service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getPublishCount() const = 0;
		/*! Sets the counter of the Publish service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setPublishCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setPublishCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the Republish service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getRepublishCount() const = 0;
		/*! Sets the counter of the Republish service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setRepublishCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setRepublishCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the TransferSubscriptions service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getTransferSubscriptionsCount() const = 0;
		/*! Sets the counter of the TransferSubscriptions service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setTransferSubscriptionsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransferSubscriptionsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the DeleteSubscriptions service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getDeleteSubscriptionsCount() const = 0;
		/*! Sets the counter of the DeleteSubscriptions service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setDeleteSubscriptionsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setDeleteSubscriptionsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the AddNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getAddNodesCount() const = 0;
		/*! Sets the counter of the AddNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setAddNodesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAddNodesCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the AddReferences service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getAddReferencesCount() const = 0;
		/*! Sets the counter of the AddReferences service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setAddReferencesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAddReferencesCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the DeleteNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getDeleteNodesCount() const = 0;
		/*! Sets the counter of the DeleteNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setDeleteNodesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setDeleteNodesCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the DeleteReferences service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getDeleteReferencesCount() const = 0;
		/*! Sets the counter of the DeleteReferences service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setDeleteReferencesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setDeleteReferencesCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the Browse service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getBrowseCount() const = 0;
		/*! Sets the counter of the Browse service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setBrowseCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setBrowseCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the BrowseNext service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getBrowseNextCount() const = 0;
		/*! Sets the counter of the BrowseNext service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setBrowseNextCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setBrowseNextCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the TranslateBrowsePathsToNodeIds service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getTranslateBrowsePathsToNodeIdsCount() const = 0;
		/*! Sets the counter of the TranslateBrowsePathsToNodeIds service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setTranslateBrowsePathsToNodeIdsCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setTranslateBrowsePathsToNodeIdsCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the QueryFirst service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getQueryFirstCount() const = 0;
		/*! Sets the counter of the QueryFirst service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setQueryFirstCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setQueryFirstCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the QueryNext service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getQueryNextCount() const = 0;
		/*! Sets the counter of the QueryNext service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setQueryNextCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setQueryNextCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the RegisterNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getRegisterNodesCount() const = 0;
		/*! Sets the counter of the RegisterNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setRegisterNodesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setRegisterNodesCount(const ServiceCounterDataType& value) = 0;

		/*! Returns the counter of the UnregisterNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual const IServiceCounterDataType* getUnregisterNodesCount() const = 0;
		/*! Sets the counter of the UnregisterNodes service, identifying the number of received
		* requests of this service on the session. */
		virtual EnumStatusCode setUnregisterNodesCount(const IServiceCounterDataType* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setUnregisterNodesCount(const ServiceCounterDataType& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISessionDiagnosticsDataType*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISessionDiagnosticsDataType&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISessionDiagnosticsDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const ISessionDiagnosticsDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISessionDiagnosticsDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISessionDiagnosticsDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISessionDiagnosticsDataType
} // end namespace

#endif	// ISESSIONDIAGNOSTICSDATATYPE_H
