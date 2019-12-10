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

#ifndef ISERVERDIAGNOSTICSSUMMARYDATATYPE_H
#define ISERVERDIAGNOSTICSSUMMARYDATATYPE_H

#include "ServerDiagnosticsSummaryDataTypeStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The ServerDiagnosticsSummaryDataType contains diagnostic summary information for an OPC UA server. */
	class TBC_EXPORT IServerDiagnosticsSummaryDataType
	{
	public:
		/*! Destructor */
		virtual ~IServerDiagnosticsSummaryDataType(){};

		/*! Returns the number of server-created views in the server. */
		virtual OTUInt32 getServerViewCount() const = 0;
		/*! Sets the number of server-created views in the server. */
		virtual void setServerViewCount(const OTUInt32& value) = 0;

		/*! Returns the number of client sessions currently established in the server. */
		virtual OTUInt32 getCurrentSessionCount() const = 0;
		/*! Sets the number of client sessions currently established in the server. */
		virtual void setCurrentSessionCount(const OTUInt32& value) = 0;

		/*! Returns the cumulative number of client sessions that have been established in the
		* server since the server was started (or restarted). This includes the
		* current session count (see getCurrentSessionCount()). */
		virtual OTUInt32 getCumulatedSessionCount() const = 0;
		/*! Sets the cumulative number of client sessions that have been established in the
		* server since the server was started (or restarted). This includes the
		* current session count (see getCurrentSessionCount()). */
		virtual void setCumulatedSessionCount(const OTUInt32& value) = 0;

		/*! Returns the number of client session establishment requests that were rejected due
		* to security constraints since the server was started (or restarted). */
		virtual OTUInt32 getSecurityRejectedSessionCount() const = 0;
		/*! Sets the number of client session establishment requests that were rejected due
		* to security constraints since the server was started (or restarted). */
		virtual void setSecurityRejectedSessionCount(const OTUInt32& value) = 0;

		/*! Returns the number of client session establishment requests that were rejected
		* since the server was started (or restarted). This number includes the
		* security-rejected session count (see getSecurityRejectedSessionCount()). */
		virtual OTUInt32 getRejectedSessionCount() const = 0;
		/*! Sets the number of client session establishment requests that were rejected
		* since the server was started (or restarted). This number includes the
		* security-rejected session count (see getSecurityRejectedSessionCount()). */
		virtual void setRejectedSessionCount(const OTUInt32& value) = 0;

		/*! Returns the number of client sessions that were closed due to timeout since the
		* server was started (or restarted). */
		virtual OTUInt32 getSessionTimeoutCount() const = 0;
		/*! Sets the number of client sessions that were closed due to timeout since the
		* server was started (or restarted). */
		virtual void setSessionTimeoutCount(const OTUInt32& value) = 0;

		/*! Returns the number of client sessions that were closed due to errors since the
		* server was started (or restarted). */
		virtual OTUInt32 getSessionAbortCount() const = 0;
		/*! Sets the number of client sessions that were closed due to errors since the
		* server was started (or restarted). */
		virtual void setSessionAbortCount(const OTUInt32& value) = 0;

		/*! Returns the number of subscriptions currently established in the server. */
		virtual OTUInt32 getCurrentSubscriptionCount() const = 0;
		/*! Sets the number of subscriptions currently established in the server. */
		virtual void setCurrentSubscriptionCount(const OTUInt32& value) = 0;

		/*! Returns the cumulative number of subscriptions that have been established in the
		* server since the server was started (or restarted). This includes the
		* current subscription count (see getCurrentSubscriptionCount()). */
		virtual OTUInt32 getCumulatedSubscriptionCount() const = 0;
		/*! Sets the cumulative number of subscriptions that have been established in the
		* server since the server was started (or restarted). This includes the
		* current subscription count (see getCurrentSubscriptionCount()). */
		virtual void setCumulatedSubscriptionCount(const OTUInt32& value) = 0;

		/*! Returns the number of publishing intervals currently supported in the server. */
		virtual OTUInt32 getPublishingIntervalCount() const = 0;
		/*! Sets the number of publishing intervals currently supported in the server. */
		virtual void setPublishingIntervalCount(const OTUInt32& value) = 0;

		/*! Returns the number of requests that were rejected due to security constraints since
		* the server was started (or restarted). The requests include all OPC UA Services
		* that the server supports. */
		virtual OTUInt32 getSecurityRejectedRequestsCount() const = 0;
		/*! Sets the number of requests that were rejected due to security constraints since
		* the server was started (or restarted). The requests include all OPC UA Services
		* that the server supports. */
		virtual void setSecurityRejectedRequestsCount(const OTUInt32& value) = 0;

		/*! Returns the number of requests that were rejected since the server was started (or
		* restarted). The requests include all OPC UA Services that the server supports.
		* This number includes the security-rejected requests count (see getSecurityRejectedRequestsCount()). */
		virtual OTUInt32 getRejectedRequestsCount() const = 0;
		/*! Sets the number of requests that were rejected since the server was started (or
		* restarted). The requests include all OPC UA Services that the server supports.
		* This number includes the security-rejected requests count (see getSecurityRejectedRequestsCount()). */
		virtual void setRejectedRequestsCount(const OTUInt32& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IServerDiagnosticsSummaryDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IServerDiagnosticsSummaryDataType& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IServerDiagnosticsSummaryDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IServerDiagnosticsSummaryDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IServerDiagnosticsSummaryDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IServerDiagnosticsSummaryDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IServerDiagnosticsSummaryDataType
} // end namespace

#endif	// ISERVERDIAGNOSTICSSUMMARYDATATYPE_H
