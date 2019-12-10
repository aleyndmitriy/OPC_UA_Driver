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

#ifndef _ServerDiagnosticsSummaryDataTypeStruct_H_
#define _ServerDiagnosticsSummaryDataTypeStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif


//lint -sem(ServerDiagnosticsSummaryDataTypeStruct::clear, cleanup)
//lint -sem(ServerDiagnosticsSummaryDataTypeStruct::init, initializer)
typedef struct TBCORE_IF ServerDiagnosticsSummaryDataTypeStruct
{
	/*!
	 * @brief The number of server-created views in the server.
	 */
	OTUInt32 serverViewCount;

	/*!
	 * @brief The number of client sessions currently established in the server.
	 */
	OTUInt32 currentSessionCount;

	/*!
	 * @brief The cumulative number of client sessions that have been established in the
	 * server since the server was started (or restarted). This includes the
	 * @p currentSessionCount.
	 */
	OTUInt32 cumulatedSessionCount;

	/*!
	 * @brief The number of client session establishment requests that were rejected due
	 * to security constraints since the server was started (or restarted).
	 */
	OTUInt32 securityRejectedSessionCount;

	/*!
	 * @brief The number of client session establishment requests that were rejected
	 * since the server was started (or restarted). This number includes the
	 * @p securityRejectedSessionCount.
	 */
	OTUInt32 rejectedSessionCount;

	/*!
	 * @brief The number of client sessions that were closed due to timeout since the
	 * server was started (or restarted).
	 */
	OTUInt32 sessionTimeoutCount;

	/*!
	 * @brief The number of client sessions that were closed due to errors since the
	 * server was started (or restarted).
	 */
	OTUInt32 sessionAbortCount;

	/*!
	 * @brief The number of subscriptions currently established in the server.
	 */
	OTUInt32 currentSubscriptionCount;

	/*!
	 * @brief The cumulative number of subscriptions that have been established in the
	 * server since the server was started (or restarted). This includes the
	 * @p currentSubscriptionCount.
	 */
	OTUInt32 cumulatedSubscriptionCount;

	/*!
	 * @brief The number of publishing intervals currently supported in the server.
	 */
	OTUInt32 publishingIntervalCount;

	/*!
	 * @brief The number of requests that were rejected due to security constraints since
	 * the server was started (or restarted). The requests include all OPC UA Services
	 * that the server supports.
	 */
	OTUInt32 securityRejectedRequestsCount;

	/*!
	 * @brief The number of requests that were rejected since the server was started (or
	 * restarted). The requests include all OPC UA Services that the server supports.
	 * This number includes the @p securityRejectedRequestsCount.
	 */
	OTUInt32 rejectedRequestsCount;


	ServerDiagnosticsSummaryDataTypeStruct();
	ServerDiagnosticsSummaryDataTypeStruct(const ServerDiagnosticsSummaryDataTypeStruct&);

	EnumStatusCode set(const ServerDiagnosticsSummaryDataTypeStruct&);
	EnumStatusCode get(ServerDiagnosticsSummaryDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ServerDiagnosticsSummaryDataType&);
	EnumStatusCode get(OpcUa_ServerDiagnosticsSummaryDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const ServerDiagnosticsSummaryDataTypeStruct& operator=(const ServerDiagnosticsSummaryDataTypeStruct& cp);
	bool operator==(const ServerDiagnosticsSummaryDataTypeStruct& toCompare) const;
	bool operator!=(const ServerDiagnosticsSummaryDataTypeStruct& toCompare) const;
	bool operator<(const ServerDiagnosticsSummaryDataTypeStruct& toCompare) const;
	bool operator>(const ServerDiagnosticsSummaryDataTypeStruct& toCompare) const;

	int compare(const ServerDiagnosticsSummaryDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ServerDiagnosticsSummaryDataTypeStruct(void);
} ServerDiagnosticsSummaryDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
