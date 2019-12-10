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

#ifndef SUBSCRIPTIONDIAGNOSTICSDATATYPE_H
#define SUBSCRIPTIONDIAGNOSTICSDATATYPE_H

#include "ISubscriptionDiagnosticsDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SubscriptionDiagnosticsDataType contains diagnostic information about subscriptions. */
	class TBC_EXPORT SubscriptionDiagnosticsDataType
		: public ISubscriptionDiagnosticsDataType
	{
	public:
		/*! Default constructor */
		SubscriptionDiagnosticsDataType();
		/*! Constructs a copy of the given instance */
		SubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType*);
		/*! @overload */
		SubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType&);
		/*! @overload */
		SubscriptionDiagnosticsDataType(const SubscriptionDiagnosticsDataType&);

		/*! Destructor */
		virtual ~SubscriptionDiagnosticsDataType();

		/*! Assigns the contents of @p cp to this instance */
		SubscriptionDiagnosticsDataType& operator=(const ISubscriptionDiagnosticsDataType* cp);
		/*! @overload */
		SubscriptionDiagnosticsDataType& operator=(const ISubscriptionDiagnosticsDataType& cp);
		/*! @overload */
		SubscriptionDiagnosticsDataType& operator=(const SubscriptionDiagnosticsDataType& cp);

		/* see ISubscriptionDiagnosticsDataType::set */
		virtual EnumStatusCode set(const ISubscriptionDiagnosticsDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISubscriptionDiagnosticsDataType& pSrc);

		/* see ISubscriptionDiagnosticsDataType::compare */
		virtual int compare(const ISubscriptionDiagnosticsDataType*) const;
		/*! @overload */
		virtual int compare(const ISubscriptionDiagnosticsDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISubscriptionDiagnosticsDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISubscriptionDiagnosticsDataType& other) const;

		/* see ISubscriptionDiagnosticsDataType::getSessionId */
		virtual const INodeId* getSessionId() const;
		/* see ISubscriptionDiagnosticsDataType::setSessionId */
		virtual EnumStatusCode setSessionId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value);

		/* see ISubscriptionDiagnosticsDataType::getSubscriptionId */
		virtual OTUInt32 getSubscriptionId() const;
		/* see ISubscriptionDiagnosticsDataType::setSubscriptionId */
		virtual void setSubscriptionId(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getPriority */
		virtual OTUInt8 getPriority() const;
		/* see ISubscriptionDiagnosticsDataType::setPriority */
		virtual void setPriority(const OTUInt8& value);

		/* see ISubscriptionDiagnosticsDataType::getPublishingInterval */
		virtual double getPublishingInterval() const;
		/* see ISubscriptionDiagnosticsDataType::setPublishingInterval */
		virtual void setPublishingInterval(const double& value);

		/* see ISubscriptionDiagnosticsDataType::getMaxKeepAliveCount */
		virtual OTUInt32 getMaxKeepAliveCount() const;
		/* see ISubscriptionDiagnosticsDataType::setMaxKeepAliveCount */
		virtual void setMaxKeepAliveCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getMaxLifetimeCount */
		virtual OTUInt32 getMaxLifetimeCount() const;
		/* see ISubscriptionDiagnosticsDataType::setMaxLifetimeCount */
		virtual void setMaxLifetimeCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getMaxNotificationsPerPublish */
		virtual OTUInt32 getMaxNotificationsPerPublish() const;
		/* see ISubscriptionDiagnosticsDataType::setMaxNotificationsPerPublish */
		virtual void setMaxNotificationsPerPublish(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getPublishingEnabled */
		virtual bool getPublishingEnabled() const;
		/* see ISubscriptionDiagnosticsDataType::setPublishingEnabled */
		virtual void setPublishingEnabled(const bool& value);

		/* see ISubscriptionDiagnosticsDataType::getModifyCount */
		virtual OTUInt32 getModifyCount() const;
		/* see ISubscriptionDiagnosticsDataType::setModifyCount */
		virtual void setModifyCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getEnableCount */
		virtual OTUInt32 getEnableCount() const;
		/* see ISubscriptionDiagnosticsDataType::setEnableCount */
		virtual void setEnableCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getDisableCount */
		virtual OTUInt32 getDisableCount() const;
		/* see ISubscriptionDiagnosticsDataType::setDisableCount */
		virtual void setDisableCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getRepublishRequestCount */
		virtual OTUInt32 getRepublishRequestCount() const;
		/* see ISubscriptionDiagnosticsDataType::setRepublishRequestCount */
		virtual void setRepublishRequestCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getRepublishMessageRequestCount */
		virtual OTUInt32 getRepublishMessageRequestCount() const;
		/* see ISubscriptionDiagnosticsDataType::setRepublishMessageRequestCount */
		virtual void setRepublishMessageRequestCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getRepublishMessageCount */
		virtual OTUInt32 getRepublishMessageCount() const;
		/* see ISubscriptionDiagnosticsDataType::setRepublishMessageCount */
		virtual void setRepublishMessageCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getTransferRequestCount */
		virtual OTUInt32 getTransferRequestCount() const;
		/* see ISubscriptionDiagnosticsDataType::setTransferRequestCount */
		virtual void setTransferRequestCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getTransferredToAltClientCount */
		virtual OTUInt32 getTransferredToAltClientCount() const;
		/* see ISubscriptionDiagnosticsDataType::setTransferredToAltClientCount */
		virtual void setTransferredToAltClientCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getTransferredToSameClientCount */
		virtual OTUInt32 getTransferredToSameClientCount() const;
		/* see ISubscriptionDiagnosticsDataType::setTransferredToSameClientCount */
		virtual void setTransferredToSameClientCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getPublishRequestCount */
		virtual OTUInt32 getPublishRequestCount() const;
		/* see ISubscriptionDiagnosticsDataType::setPublishRequestCount */
		virtual void setPublishRequestCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getDataChangeNotificationsCount */
		virtual OTUInt32 getDataChangeNotificationsCount() const;
		/* see ISubscriptionDiagnosticsDataType::setDataChangeNotificationsCount */
		virtual void setDataChangeNotificationsCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getEventNotificationsCount */
		virtual OTUInt32 getEventNotificationsCount() const;
		/* see ISubscriptionDiagnosticsDataType::setEventNotificationsCount */
		virtual void setEventNotificationsCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getNotificationsCount */
		virtual OTUInt32 getNotificationsCount() const;
		/* see ISubscriptionDiagnosticsDataType::setNotificationsCount */
		virtual void setNotificationsCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getLatePublishRequestCount */
		virtual OTUInt32 getLatePublishRequestCount() const;
		/* see ISubscriptionDiagnosticsDataType::setLatePublishRequestCount */
		virtual void setLatePublishRequestCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getCurrentKeepAliveCount */
		virtual OTUInt32 getCurrentKeepAliveCount() const;
		/* see ISubscriptionDiagnosticsDataType::setCurrentKeepAliveCount */
		virtual void setCurrentKeepAliveCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getCurrentLifetimeCount */
		virtual OTUInt32 getCurrentLifetimeCount() const;
		/* see ISubscriptionDiagnosticsDataType::setCurrentLifetimeCount */
		virtual void setCurrentLifetimeCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getUnacknowledgedMessageCount */
		virtual OTUInt32 getUnacknowledgedMessageCount() const;
		/* see ISubscriptionDiagnosticsDataType::setUnacknowledgedMessageCount */
		virtual void setUnacknowledgedMessageCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getDiscardedMessageCount */
		virtual OTUInt32 getDiscardedMessageCount() const;
		/* see ISubscriptionDiagnosticsDataType::setDiscardedMessageCount */
		virtual void setDiscardedMessageCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getMonitoredItemCount */
		virtual OTUInt32 getMonitoredItemCount() const;
		/* see ISubscriptionDiagnosticsDataType::setMonitoredItemCount */
		virtual void setMonitoredItemCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getDisabledMonitoredItemCount */
		virtual OTUInt32 getDisabledMonitoredItemCount() const;
		/* see ISubscriptionDiagnosticsDataType::setDisabledMonitoredItemCount */
		virtual void setDisabledMonitoredItemCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getMonitoringQueueOverflowCount */
		virtual OTUInt32 getMonitoringQueueOverflowCount() const;
		/* see ISubscriptionDiagnosticsDataType::setMonitoringQueueOverflowCount */
		virtual void setMonitoringQueueOverflowCount(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getNextSequenceNumber */
		virtual OTUInt32 getNextSequenceNumber() const;
		/* see ISubscriptionDiagnosticsDataType::setNextSequenceNumber */
		virtual void setNextSequenceNumber(const OTUInt32& value);

		/* see ISubscriptionDiagnosticsDataType::getEventQueueOverFlowCount */
		virtual OTUInt32 getEventQueueOverFlowCount() const;
		/* see ISubscriptionDiagnosticsDataType::setEventQueueOverFlowCount */
		virtual void setEventQueueOverFlowCount(const OTUInt32& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_sessionId;

		SubscriptionDiagnosticsDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SUBSCRIPTIONDIAGNOSTICSDATATYPE_H
