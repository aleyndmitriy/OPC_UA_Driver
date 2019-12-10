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

#ifndef SESSIONDIAGNOSTICSDATATYPE_H
#define SESSIONDIAGNOSTICSDATATYPE_H

#include "ISessionDiagnosticsDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "ApplicationDescription.h"
#include "IApplicationDescription.h"
#include "InnerApplicationDescription.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "InnerDateTime.h"
#include "ServiceCounterDataType.h"
#include "IServiceCounterDataType.h"
#include "InnerServiceCounterDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SessionDiagnosticsDataType contains diagnostic information about client sessions. */
	class TBC_EXPORT SessionDiagnosticsDataType
		: public ISessionDiagnosticsDataType
	{
	public:
		/*! Default constructor */
		SessionDiagnosticsDataType();
		/*! Constructs a copy of the given instance */
		SessionDiagnosticsDataType(const ISessionDiagnosticsDataType*);
		/*! @overload */
		SessionDiagnosticsDataType(const ISessionDiagnosticsDataType&);
		/*! @overload */
		SessionDiagnosticsDataType(const SessionDiagnosticsDataType&);

		/*! Destructor */
		virtual ~SessionDiagnosticsDataType();

		/*! Assigns the contents of @p cp to this instance */
		SessionDiagnosticsDataType& operator=(const ISessionDiagnosticsDataType*);
		/*! @overload */
		SessionDiagnosticsDataType& operator=(const ISessionDiagnosticsDataType&);
		/*! @overload */
		SessionDiagnosticsDataType& operator=(const SessionDiagnosticsDataType&);

		/* see ISessionDiagnosticsDataType::set */
		virtual EnumStatusCode set(const ISessionDiagnosticsDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISessionDiagnosticsDataType& pSrc);

		/* see ISessionDiagnosticsDataType::compare */
		virtual int compare(const ISessionDiagnosticsDataType*) const;
		/*! @overload */
		virtual int compare(const ISessionDiagnosticsDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISessionDiagnosticsDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISessionDiagnosticsDataType& other) const;

		/* see ISessionDiagnosticsDataType::getSessionId */
		virtual const INodeId* getSessionId() const;
		/* see ISessionDiagnosticsDataType::setSessionId */
		virtual EnumStatusCode setSessionId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value);

		/* see ISessionDiagnosticsDataType::getSessionName */
		virtual tstring getSessionName() const;
		/* see ISessionDiagnosticsDataType::setSessionName */
		virtual void setSessionName(const tstring& value);

		/* see ISessionDiagnosticsDataType::getClientDescription */
		virtual const IApplicationDescription* getClientDescription() const;
		/* see ISessionDiagnosticsDataType::setClientDescription */
		virtual EnumStatusCode setClientDescription(const IApplicationDescription* value);
		/*! @overload */
		virtual EnumStatusCode setClientDescription(const ApplicationDescription& value);

		/* see ISessionDiagnosticsDataType::getServerUri */
		virtual tstring getServerUri() const;
		/* see ISessionDiagnosticsDataType::setServerUri */
		virtual void setServerUri(const tstring& value);

		/* see ISessionDiagnosticsDataType::getEndpointUrl */
		virtual tstring getEndpointUrl() const;
		/* see ISessionDiagnosticsDataType::setEndpointUrl */
		virtual void setEndpointUrl(const tstring& value);

		/* see ISessionDiagnosticsDataType::getLocaleIds */
		virtual std::vector<tstring> getLocaleIds() const;
		/* see ISessionDiagnosticsDataType::setLocaleIds */
		virtual EnumStatusCode setLocaleIds(const std::vector<tstring>& values);

		/* see ISessionDiagnosticsDataType::getActualSessionTimeout */
		virtual double getActualSessionTimeout() const;
		/* see ISessionDiagnosticsDataType::setActualSessionTimeout */
		virtual void setActualSessionTimeout(const double& value);

		/* see ISessionDiagnosticsDataType::getMaxResponseMessageSize */
		virtual OTUInt32 getMaxResponseMessageSize() const;
		/* see ISessionDiagnosticsDataType::setMaxResponseMessageSize */
		virtual void setMaxResponseMessageSize(const OTUInt32& value);

		/* see ISessionDiagnosticsDataType::getClientConnectionTime */
		virtual const IDateTime* getClientConnectionTime() const;
		/* see ISessionDiagnosticsDataType::setClientConnectionTime */
		virtual EnumStatusCode setClientConnectionTime(const IDateTime* value);
		/*! @overload */
		virtual EnumStatusCode setClientConnectionTime(const DateTime& value);

		/* see ISessionDiagnosticsDataType::getClientLastContactTime */
		virtual const IDateTime* getClientLastContactTime() const;
		/* see ISessionDiagnosticsDataType::setClientLastContactTime */
		virtual EnumStatusCode setClientLastContactTime(const IDateTime* value);
		/*! @overload */
		virtual EnumStatusCode setClientLastContactTime(const DateTime& value);

		/* see ISessionDiagnosticsDataType::getCurrentSubscriptionsCount */
		virtual OTUInt32 getCurrentSubscriptionsCount() const;
		/* see ISessionDiagnosticsDataType::setCurrentSubscriptionsCount */
		virtual void setCurrentSubscriptionsCount(const OTUInt32& value);

		/* see ISessionDiagnosticsDataType::getCurrentMonitoredItemsCount */
		virtual OTUInt32 getCurrentMonitoredItemsCount() const;
		/* see ISessionDiagnosticsDataType::setCurrentMonitoredItemsCount */
		virtual void setCurrentMonitoredItemsCount(const OTUInt32& value);

		/* see ISessionDiagnosticsDataType::getCurrentPublishRequestsInQueue */
		virtual OTUInt32 getCurrentPublishRequestsInQueue() const;
		/* see ISessionDiagnosticsDataType::setCurrentPublishRequestsInQueue */
		virtual void setCurrentPublishRequestsInQueue(const OTUInt32& value);

		/* see ISessionDiagnosticsDataType::getTotalRequestCount */
		virtual const IServiceCounterDataType* getTotalRequestCount() const;
		/* see ISessionDiagnosticsDataType::setTotalRequestCount */
		virtual EnumStatusCode setTotalRequestCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTotalRequestCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getUnauthorizedRequestCount */
		virtual OTUInt32 getUnauthorizedRequestCount() const;
		/* see ISessionDiagnosticsDataType::setUnauthorizedRequestCount */
		virtual void setUnauthorizedRequestCount(const OTUInt32& value);

		/* see ISessionDiagnosticsDataType::getReadCount */
		virtual const IServiceCounterDataType* getReadCount() const;
		/* see ISessionDiagnosticsDataType::setReadCount */
		virtual EnumStatusCode setReadCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setReadCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getHistoryReadCount */
		virtual const IServiceCounterDataType* getHistoryReadCount() const;
		/* see ISessionDiagnosticsDataType::setHistoryReadCount */
		virtual EnumStatusCode setHistoryReadCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setHistoryReadCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getWriteCount */
		virtual const IServiceCounterDataType* getWriteCount() const;
		/* see ISessionDiagnosticsDataType::setWriteCount */
		virtual EnumStatusCode setWriteCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setWriteCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getHistoryUpdateCount */
		virtual const IServiceCounterDataType* getHistoryUpdateCount() const;
		/* see ISessionDiagnosticsDataType::setHistoryUpdateCount */
		virtual EnumStatusCode setHistoryUpdateCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setHistoryUpdateCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getCallCount */
		virtual const IServiceCounterDataType* getCallCount() const;
		/* see ISessionDiagnosticsDataType::setCallCount */
		virtual EnumStatusCode setCallCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setCallCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getCreateMonitoredItemsCount */
		virtual const IServiceCounterDataType* getCreateMonitoredItemsCount() const;
		/* see ISessionDiagnosticsDataType::setCreateMonitoredItemsCount */
		virtual EnumStatusCode setCreateMonitoredItemsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setCreateMonitoredItemsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getModifyMonitoredItemsCount */
		virtual const IServiceCounterDataType* getModifyMonitoredItemsCount() const;
		/* see ISessionDiagnosticsDataType::setModifyMonitoredItemsCount */
		virtual EnumStatusCode setModifyMonitoredItemsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setModifyMonitoredItemsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getSetMonitoringModeCount */
		virtual const IServiceCounterDataType* getSetMonitoringModeCount() const;
		/* see ISessionDiagnosticsDataType::setSetMonitoringModeCount */
		virtual EnumStatusCode setSetMonitoringModeCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setSetMonitoringModeCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getSetTriggeringCount */
		virtual const IServiceCounterDataType* getSetTriggeringCount() const;
		/* see ISessionDiagnosticsDataType::setSetTriggeringCount */
		virtual EnumStatusCode setSetTriggeringCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setSetTriggeringCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getDeleteMonitoredItemsCount */
		virtual const IServiceCounterDataType* getDeleteMonitoredItemsCount() const;
		/* see ISessionDiagnosticsDataType::setDeleteMonitoredItemsCount */
		virtual EnumStatusCode setDeleteMonitoredItemsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDeleteMonitoredItemsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getCreateSubscriptionCount */
		virtual const IServiceCounterDataType* getCreateSubscriptionCount() const;
		/* see ISessionDiagnosticsDataType::setCreateSubscriptionCount */
		virtual EnumStatusCode setCreateSubscriptionCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setCreateSubscriptionCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getModifySubscriptionCount */
		virtual const IServiceCounterDataType* getModifySubscriptionCount() const;
		/* see ISessionDiagnosticsDataType::setModifySubscriptionCount */
		virtual EnumStatusCode setModifySubscriptionCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setModifySubscriptionCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getSetPublishingModeCount */
		virtual const IServiceCounterDataType* getSetPublishingModeCount() const;
		/* see ISessionDiagnosticsDataType::setSetPublishingModeCount */
		virtual EnumStatusCode setSetPublishingModeCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setSetPublishingModeCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getPublishCount */
		virtual const IServiceCounterDataType* getPublishCount() const;
		/* see ISessionDiagnosticsDataType::setPublishCount */
		virtual EnumStatusCode setPublishCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setPublishCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getRepublishCount */
		virtual const IServiceCounterDataType* getRepublishCount() const;
		/* see ISessionDiagnosticsDataType::setRepublishCount */
		virtual EnumStatusCode setRepublishCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setRepublishCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getTransferSubscriptionsCount */
		virtual const IServiceCounterDataType* getTransferSubscriptionsCount() const;
		/* see ISessionDiagnosticsDataType::setTransferSubscriptionsCount */
		virtual EnumStatusCode setTransferSubscriptionsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransferSubscriptionsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getDeleteSubscriptionsCount */
		virtual const IServiceCounterDataType* getDeleteSubscriptionsCount() const;
		/* see ISessionDiagnosticsDataType::setDeleteSubscriptionsCount */
		virtual EnumStatusCode setDeleteSubscriptionsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDeleteSubscriptionsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getAddNodesCount */
		virtual const IServiceCounterDataType* getAddNodesCount() const;
		/* see ISessionDiagnosticsDataType::setAddNodesCount */
		virtual EnumStatusCode setAddNodesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setAddNodesCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getAddReferencesCount */
		virtual const IServiceCounterDataType* getAddReferencesCount() const;
		/* see ISessionDiagnosticsDataType::setAddReferencesCount */
		virtual EnumStatusCode setAddReferencesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setAddReferencesCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getDeleteNodesCount */
		virtual const IServiceCounterDataType* getDeleteNodesCount() const;
		/* see ISessionDiagnosticsDataType::setDeleteNodesCount */
		virtual EnumStatusCode setDeleteNodesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDeleteNodesCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getDeleteReferencesCount */
		virtual const IServiceCounterDataType* getDeleteReferencesCount() const;
		/* see ISessionDiagnosticsDataType::setDeleteReferencesCount */
		virtual EnumStatusCode setDeleteReferencesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDeleteReferencesCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getBrowseCount */
		virtual const IServiceCounterDataType* getBrowseCount() const;
		/* see ISessionDiagnosticsDataType::setBrowseCount */
		virtual EnumStatusCode setBrowseCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setBrowseCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getBrowseNextCount */
		virtual const IServiceCounterDataType* getBrowseNextCount() const;
		/* see ISessionDiagnosticsDataType::setBrowseNextCount */
		virtual EnumStatusCode setBrowseNextCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setBrowseNextCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getTranslateBrowsePathsToNodeIdsCount */
		virtual const IServiceCounterDataType* getTranslateBrowsePathsToNodeIdsCount() const;
		/* see ISessionDiagnosticsDataType::setTranslateBrowsePathsToNodeIdsCount */
		virtual EnumStatusCode setTranslateBrowsePathsToNodeIdsCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTranslateBrowsePathsToNodeIdsCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getQueryFirstCount */
		virtual const IServiceCounterDataType* getQueryFirstCount() const;
		/* see ISessionDiagnosticsDataType::setQueryFirstCount */
		virtual EnumStatusCode setQueryFirstCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setQueryFirstCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getQueryNextCount */
		virtual const IServiceCounterDataType* getQueryNextCount() const;
		/* see ISessionDiagnosticsDataType::setQueryNextCount */
		virtual EnumStatusCode setQueryNextCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setQueryNextCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getRegisterNodesCount */
		virtual const IServiceCounterDataType* getRegisterNodesCount() const;
		/* see ISessionDiagnosticsDataType::setRegisterNodesCount */
		virtual EnumStatusCode setRegisterNodesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setRegisterNodesCount(const ServiceCounterDataType& value);

		/* see ISessionDiagnosticsDataType::getUnregisterNodesCount */
		virtual const IServiceCounterDataType* getUnregisterNodesCount() const;
		/* see ISessionDiagnosticsDataType::setUnregisterNodesCount */
		virtual EnumStatusCode setUnregisterNodesCount(const IServiceCounterDataType* value);
		/*! @overload */
		virtual EnumStatusCode setUnregisterNodesCount(const ServiceCounterDataType& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_sessionId;
		InnerApplicationDescription m_clientDescription;
		InnerDateTime m_clientConnectionTime;
		InnerDateTime m_clientLastContactTime;
		InnerServiceCounterDataType m_totalRequestCount;
		InnerServiceCounterDataType m_readCount;
		InnerServiceCounterDataType m_historyReadCount;
		InnerServiceCounterDataType m_writeCount;
		InnerServiceCounterDataType m_historyUpdateCount;
		InnerServiceCounterDataType m_callCount;
		InnerServiceCounterDataType m_createMonitoredItemsCount;
		InnerServiceCounterDataType m_modifyMonitoredItemsCount;
		InnerServiceCounterDataType m_setMonitoringModeCount;
		InnerServiceCounterDataType m_setTriggeringCount;
		InnerServiceCounterDataType m_deleteMonitoredItemsCount;
		InnerServiceCounterDataType m_createSubscriptionCount;
		InnerServiceCounterDataType m_modifySubscriptionCount;
		InnerServiceCounterDataType m_setPublishingModeCount;
		InnerServiceCounterDataType m_publishCount;
		InnerServiceCounterDataType m_republishCount;
		InnerServiceCounterDataType m_transferSubscriptionsCount;
		InnerServiceCounterDataType m_deleteSubscriptionsCount;
		InnerServiceCounterDataType m_addNodesCount;
		InnerServiceCounterDataType m_addReferencesCount;
		InnerServiceCounterDataType m_deleteNodesCount;
		InnerServiceCounterDataType m_deleteReferencesCount;
		InnerServiceCounterDataType m_browseCount;
		InnerServiceCounterDataType m_browseNextCount;
		InnerServiceCounterDataType m_translateBrowsePathsToNodeIdsCount;
		InnerServiceCounterDataType m_queryFirstCount;
		InnerServiceCounterDataType m_queryNextCount;
		InnerServiceCounterDataType m_registerNodesCount;
		InnerServiceCounterDataType m_unregisterNodesCount;

		SessionDiagnosticsDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SESSIONDIAGNOSTICSDATATYPE_H
