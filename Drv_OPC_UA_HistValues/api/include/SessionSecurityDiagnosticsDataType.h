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

#ifndef SESSIONSECURITYDIAGNOSTICSDATATYPE_H
#define SESSIONSECURITYDIAGNOSTICSDATATYPE_H

#include "ISessionSecurityDiagnosticsDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SessionSecurityDiagnosticsDataType contains security-related diagnostic information
	* about client sessions. */
	class TBC_EXPORT SessionSecurityDiagnosticsDataType
		: public ISessionSecurityDiagnosticsDataType
	{
	public:
		/*! Default constructor */
		SessionSecurityDiagnosticsDataType();
		/*! Constructs a copy of the given instance */
		SessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType*);
		/*! @overload */
		SessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType&);
		/*! @overload */
		SessionSecurityDiagnosticsDataType(const SessionSecurityDiagnosticsDataType&);

		/*! Destructor */
		virtual ~SessionSecurityDiagnosticsDataType();

		/*! Assigns the contents of @p cp to this instance */
		SessionSecurityDiagnosticsDataType& operator=(const ISessionSecurityDiagnosticsDataType*);
		/*! @overload */
		SessionSecurityDiagnosticsDataType& operator=(const ISessionSecurityDiagnosticsDataType&);
		/*! @overload */
		SessionSecurityDiagnosticsDataType& operator=(const SessionSecurityDiagnosticsDataType&);

		/* see ISessionSecurityDiagnosticsDataType::set */
		virtual EnumStatusCode set(const ISessionSecurityDiagnosticsDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISessionSecurityDiagnosticsDataType& pSrc);

		/* see ISessionSecurityDiagnosticsDataType::compare */
		virtual int compare(const ISessionSecurityDiagnosticsDataType*) const;
		/*! @overload */
		virtual int compare(const ISessionSecurityDiagnosticsDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISessionSecurityDiagnosticsDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISessionSecurityDiagnosticsDataType& other) const;

		/* see ISessionSecurityDiagnosticsDataType::getSessionId */
		virtual const INodeId* getSessionId() const;
		/* see ISessionSecurityDiagnosticsDataType::setSessionId */
		virtual EnumStatusCode setSessionId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setSessionId(const NodeId& value);

		/* see ISessionSecurityDiagnosticsDataType::getClientUserIdOfSession */
		virtual tstring getClientUserIdOfSession() const;
		/* see ISessionSecurityDiagnosticsDataType::setClientUserIdOfSession */
		virtual void setClientUserIdOfSession(const tstring& value);

		/* see ISessionSecurityDiagnosticsDataType::getClientUserIdHistory */
		virtual std::vector<tstring> getClientUserIdHistory() const;
		/* see ISessionSecurityDiagnosticsDataType::setClientUserIdHistory */
		virtual EnumStatusCode setClientUserIdHistory(const std::vector<tstring>& values);

		/* see ISessionSecurityDiagnosticsDataType::getAuthenticationMechanism */
		virtual tstring getAuthenticationMechanism() const;
		/* see ISessionSecurityDiagnosticsDataType::setAuthenticationMechanism */
		virtual void setAuthenticationMechanism(const tstring& value);

		/* see ISessionSecurityDiagnosticsDataType::getEncoding */
		virtual tstring getEncoding() const;
		/* see ISessionSecurityDiagnosticsDataType::setEncoding */
		virtual void setEncoding(const tstring& value);

		/* see ISessionSecurityDiagnosticsDataType::getTransportProtocol */
		virtual tstring getTransportProtocol() const;
		/* see ISessionSecurityDiagnosticsDataType::setTransportProtocol */
		virtual void setTransportProtocol(const tstring& value);

		/* see ISessionSecurityDiagnosticsDataType::getSecurityMode */
		virtual EnumMessageSecurityMode getSecurityMode() const;
		/* see ISessionSecurityDiagnosticsDataType::setSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& value);

		/* see ISessionSecurityDiagnosticsDataType::getSecurityPolicyUri */
		virtual tstring getSecurityPolicyUri() const;
		/* see ISessionSecurityDiagnosticsDataType::setSecurityPolicyUri */
		virtual void setSecurityPolicyUri(const tstring& value);

		/* see ISessionSecurityDiagnosticsDataType::getClientCertificate */
		virtual ByteString getClientCertificate() const;
		/* see ISessionSecurityDiagnosticsDataType::setClientCertificate */
		virtual EnumStatusCode setClientCertificate(const ByteString& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_sessionId;
		InnerByteString m_clientCertificate;

		SessionSecurityDiagnosticsDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SESSIONSECURITYDIAGNOSTICSDATATYPE_H
