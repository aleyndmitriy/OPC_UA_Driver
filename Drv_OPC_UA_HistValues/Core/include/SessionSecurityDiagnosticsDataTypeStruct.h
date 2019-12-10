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

#ifndef _SessionSecurityDiagnosticsDataTypeStruct_H_
#define _SessionSecurityDiagnosticsDataTypeStruct_H_

#include "NodeIdStruct.h"
#include "Enums.h"
#include "ByteStringStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(SessionSecurityDiagnosticsDataTypeStruct::clear, cleanup)
//lint -sem(SessionSecurityDiagnosticsDataTypeStruct::init, initializer)
typedef struct TBCORE_IF SessionSecurityDiagnosticsDataTypeStruct
{
	/*! @brief Server-assigned identifier of the session. */
	NodeIdStruct sessionId;

	/*! @brief Name of authenticated user when creating the session. */
	OTChar* pClientUserIdOfSession;

	/*! Array containing the name of the authenticated user
	 * currently active (either from creating the session or from
	 * calling the ActivateSession Service) and the history of those
	 * names. Each time the active user changes, an entry shall be
	 * made at the end of the array. The active user is always at
	 * the end of the array. Servers may restrict the size of this
	 * array, but shall support at least a size of 2. */
	OTChar** ppClientUserIdHistory;
	OTUInt32 ppClientUserIdHistory_count;

	/*! @brief Type of authentication (user name and password, X.509,
	 * Kerberos). */
	OTChar* pAuthenticationMechanism;

	/*! @brief Which encoding is used on the wire, e.g. XML or UA Binary. */
	OTChar* pEncoding;

	/*! @brief Which transport protocol is used, e.g. TCP or HTTP. */
	OTChar* pTransportProtocol;

	/*! @brief The message security mode used for the session. */
	EnumMessageSecurityMode securityMode;

	/*! @brief The name of the security policy used for the session. */
	OTChar* pSecurityPolicyUri;

	/*! @brief The application instance certificate provided by the client in
	 * the CreateSession request. */
	ByteStringStruct clientCertificate;


	SessionSecurityDiagnosticsDataTypeStruct();
	SessionSecurityDiagnosticsDataTypeStruct(const SessionSecurityDiagnosticsDataTypeStruct&);

	EnumStatusCode set(const SessionSecurityDiagnosticsDataTypeStruct&);
	EnumStatusCode get(SessionSecurityDiagnosticsDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SessionSecurityDiagnosticsDataType&);
	EnumStatusCode get(OpcUa_SessionSecurityDiagnosticsDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const SessionSecurityDiagnosticsDataTypeStruct& operator=(const SessionSecurityDiagnosticsDataTypeStruct& cp);
	bool operator==(const SessionSecurityDiagnosticsDataTypeStruct& toCompare) const;
	bool operator!=(const SessionSecurityDiagnosticsDataTypeStruct& toCompare) const;
	bool operator<(const SessionSecurityDiagnosticsDataTypeStruct& toCompare) const;
	bool operator>(const SessionSecurityDiagnosticsDataTypeStruct& toCompare) const;

	int compare(const SessionSecurityDiagnosticsDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~SessionSecurityDiagnosticsDataTypeStruct(void);
} SessionSecurityDiagnosticsDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
