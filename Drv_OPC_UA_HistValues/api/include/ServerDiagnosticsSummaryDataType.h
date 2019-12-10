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

#ifndef SERVERDIAGNOSTICSSUMMARYDATATYPE_H
#define SERVERDIAGNOSTICSSUMMARYDATATYPE_H

#include "IServerDiagnosticsSummaryDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ServerDiagnosticsSummaryDataType contains diagnostic summary information for an OPC UA Server. */
	class TBC_EXPORT ServerDiagnosticsSummaryDataType
		: public IServerDiagnosticsSummaryDataType
	{
	public:
		/*! Default constructor */
		ServerDiagnosticsSummaryDataType();
		/*! Constructs a copy of the given instance */
		ServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType*);
		/*! @overload */
		ServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType&);
		/*! @overload */
		ServerDiagnosticsSummaryDataType(const ServerDiagnosticsSummaryDataType&);

		/*! Destructor */
		virtual ~ServerDiagnosticsSummaryDataType();

		/*! Assigns the contents of @p cp to this instance */
		ServerDiagnosticsSummaryDataType& operator=(const IServerDiagnosticsSummaryDataType*);
		/*! @overload */
		ServerDiagnosticsSummaryDataType& operator=(const IServerDiagnosticsSummaryDataType&);
		/*! @overload */
		ServerDiagnosticsSummaryDataType& operator=(const ServerDiagnosticsSummaryDataType&);

		/* see IServerDiagnosticsSummaryDataType::set */
		virtual EnumStatusCode set(const IServerDiagnosticsSummaryDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IServerDiagnosticsSummaryDataType& pSrc);

		/* see IServerDiagnosticsSummaryDataType::compare */
		virtual int compare(const IServerDiagnosticsSummaryDataType*) const;
		/*! @overload */
		virtual int compare(const IServerDiagnosticsSummaryDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IServerDiagnosticsSummaryDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IServerDiagnosticsSummaryDataType& other) const;

		/* see IServerDiagnosticsSummaryDataType::getServerViewCount */
		virtual OTUInt32 getServerViewCount() const;
		/* see IServerDiagnosticsSummaryDataType::setServerViewCount */
		virtual void setServerViewCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getCurrentSessionCount */
		virtual OTUInt32 getCurrentSessionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setCurrentSessionCount */
		virtual void setCurrentSessionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getCumulatedSessionCount */
		virtual OTUInt32 getCumulatedSessionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setCumulatedSessionCount */
		virtual void setCumulatedSessionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getSecurityRejectedSessionCount */
		virtual OTUInt32 getSecurityRejectedSessionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setSecurityRejectedSessionCount */
		virtual void setSecurityRejectedSessionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getRejectedSessionCount */
		virtual OTUInt32 getRejectedSessionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setRejectedSessionCount */
		virtual void setRejectedSessionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getSessionTimeoutCount */
		virtual OTUInt32 getSessionTimeoutCount() const;
		/* see IServerDiagnosticsSummaryDataType::setSessionTimeoutCount */
		virtual void setSessionTimeoutCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getSessionAbortCount */
		virtual OTUInt32 getSessionAbortCount() const;
		/* see IServerDiagnosticsSummaryDataType::setSessionAbortCount */
		virtual void setSessionAbortCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getCurrentSubscriptionCount */
		virtual OTUInt32 getCurrentSubscriptionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setCurrentSubscriptionCount */
		virtual void setCurrentSubscriptionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getCumulatedSubscriptionCount */
		virtual OTUInt32 getCumulatedSubscriptionCount() const;
		/* see IServerDiagnosticsSummaryDataType::setCumulatedSubscriptionCount */
		virtual void setCumulatedSubscriptionCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getPublishingIntervalCount */
		virtual OTUInt32 getPublishingIntervalCount() const;
		/* see IServerDiagnosticsSummaryDataType::setPublishingIntervalCount */
		virtual void setPublishingIntervalCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getSecurityRejectedRequestsCount */
		virtual OTUInt32 getSecurityRejectedRequestsCount() const;
		/* see IServerDiagnosticsSummaryDataType::setSecurityRejectedRequestsCount */
		virtual void setSecurityRejectedRequestsCount(const OTUInt32& value);

		/* see IServerDiagnosticsSummaryDataType::getRejectedRequestsCount */
		virtual OTUInt32 getRejectedRequestsCount() const;
		/* see IServerDiagnosticsSummaryDataType::setRejectedRequestsCount */
		virtual void setRejectedRequestsCount(const OTUInt32& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		ServerDiagnosticsSummaryDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SERVERDIAGNOSTICSSUMMARYDATATYPE_H
