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

#ifndef ISESSIONSECURITYDIAGNOSTICSDATATYPE_H
#define ISESSIONSECURITYDIAGNOSTICSDATATYPE_H

#include "SessionSecurityDiagnosticsDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"
#include "ByteString.h"

namespace SoftingOPCToolbox5
{
	/*! The SessionSecurityDiagnosticsDataType contains security-related diagnostic information
	* about client sessions. */
	class TBC_EXPORT ISessionSecurityDiagnosticsDataType
	{
	public:
		/*! Destructor */
		virtual ~ISessionSecurityDiagnosticsDataType(){};

		/*! Returns the server-assigned identifier of the session. */
		virtual const INodeId* getSessionId() const = 0;
		/*! Sets the server-assigned identifier of the session. */
		virtual EnumStatusCode setSessionId(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value) = 0;

		/*! Returns the name of the authenticated user associated with the session. */
		virtual tstring getClientUserIdOfSession() const = 0;
		/*! Sets the name of the authenticated user associated with the session. */
		virtual void setClientUserIdOfSession(const tstring& value) = 0;

		/*! Returns a vector containing the name of the authenticated user currently active
		* and the history of those names.
		*
		* @see setClientUserIdHistory() */
		virtual std::vector<tstring> getClientUserIdHistory() const = 0;
		/*! Sets a vector containing the name of the authenticated user currently active
		* and the history of those names.
		*
		* Each time the active user changes, an entry shall be made at the end of the list.
		* The active user is always at the end of the list. Servers may restrict the size of this
		* array, but shall support at least a size of 2. */
		virtual EnumStatusCode setClientUserIdHistory(const std::vector<tstring>& values) = 0;

		/*! Returns the type of user authentication (user name and password, X.509,
		* Kerberos). */
		virtual tstring getAuthenticationMechanism() const = 0;
		/*! Sets the type of user authentication (user name and password, X.509,
		* Kerberos). */
		virtual void setAuthenticationMechanism(const tstring& value) = 0;

		/*! Returns which encoding is used on the wire, e.g. XML or UA Binary. */
		virtual tstring getEncoding() const = 0;
		/*! Sets which encoding is used on the wire, e.g. XML or UA Binary. */
		virtual void setEncoding(const tstring& value) = 0;

		/*! Returns which transport protocol is used, e.g. TCP or HTTP. */
		virtual tstring getTransportProtocol() const = 0;
		/*! Sets which transport protocol is used, e.g. TCP or HTTP. */
		virtual void setTransportProtocol(const tstring& value) = 0;

		/*! Returns the message security mode used for the session. */
		virtual EnumMessageSecurityMode getSecurityMode() const = 0;
		/*! Sets the message security mode used for the session. */
		virtual void setSecurityMode(const EnumMessageSecurityMode& value) = 0;

		/*! Returns the URI of the security policy used for the session. */
		virtual tstring getSecurityPolicyUri() const = 0;
		/*! Sets the URI of the security policy used for the session. */
		virtual void setSecurityPolicyUri(const tstring& value) = 0;

		/*! Returns the application instance certificate provided by the client in
		* the CreateSession request. */
		virtual ByteString getClientCertificate() const = 0;
		/*! Sets the application instance certificate provided by the client in
		* the CreateSession request. */
		virtual EnumStatusCode setClientCertificate(const ByteString& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISessionSecurityDiagnosticsDataType*) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISessionSecurityDiagnosticsDataType&) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISessionSecurityDiagnosticsDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const ISessionSecurityDiagnosticsDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISessionSecurityDiagnosticsDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISessionSecurityDiagnosticsDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISessionSecurityDiagnosticsDataType
} // end namespace

#endif	// ISESSIONSECURITYDIAGNOSTICSDATATYPE_H
