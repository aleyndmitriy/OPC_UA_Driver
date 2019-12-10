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

#ifndef SERVERAUDITOPENSECURECHANNELEVENT_H
#define SERVERAUDITOPENSECURECHANNELEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a client opens a new secure channel.
		*
		* The SourceNode property for events of this type should be assigned to the server object.
		* The SourceName property for events of this type should be "SecureChannel/OpenSecureChannel".
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li Status:						Identifies whether the requested action could be performed.
		* @li SecureChannelId:				Shall uniquely identify the SecureChannel.
		* @li ClientCertificate:			The clientCertificate parameter of the CreateSession Service call.
		* @li ClientCertificateThumbprint:	A thumb print of the ClientCertificate.
		* @li RequestType:					The requestType parameter of the OpenSecureChannel Service call.
		* @li SecurityPolicyUri:			The securityPolicyUri parameter of the OpenSecureChannel Service call.
		* @li SecurityMode:					The securityMode parameter of the OpenSecureChannel Service call.
		* @li RequestedLifetime:			The requestedLifetime parameter of the OpenSecureChannel Service call. */
		class TBC_EXPORT AuditOpenSecureChannelEvent
			: public AuditEvent
		{
		public:
			/*! Constructs a new AuditOpenSecureChannelEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"SecureChannel/OpenSecureChannel"
			* @li SourceNode:		The server object.
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditOpenSecureChannelEvent> create();

		protected:
			/*! Default constructor */
			AuditOpenSecureChannelEvent();
					/*! @overload */
			AuditOpenSecureChannelEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditOpenSecureChannelEvent();

			/*! Returns the SecureChannelId that uniquely identifies the secure channel.
			*
			* @see setSecureChannelId() */
			tstring getSecureChannelId() const;
			/*! Sets the SecureChannelId that uniquely identifies the secure channel.
			*
			* @param secureChannelId The ID of the secure channel */
			EnumStatusCode setSecureChannelId(const tstring& secureChannelId);

			/*! Returns the client certificate provided with the OpenSecureChannel service invocation.
			*
			* @see setClientCertificate() */
			ByteString getClientCertificate() const;
			/*! Sets the client certificate provided with the OpenSecureChannel service invocation.
			*
			* @param clientCertificate The certificate of the client that opened the secure channel */
			EnumStatusCode setClientCertificate(const IByteString* clientCertificate);

			/*! Returns the SHA1 thumbprint of the client certificate. The thumbprint
			* is formatted as hexadecimal string.
			*
			* @see setClientCertificateThumbprint() */
			tstring getClientCertificateThumbprint() const;
			/*! Sets the SHA1 thumbprint of the client certificate. The thumbprint
			* is formatted as hexadecimal string.
			*
			* @param clientCertificateThumbprint The thumb print of the client certificate */
			EnumStatusCode setClientCertificateThumbprint(const tstring& clientCertificateThumbprint);

			/*! Returns the requestType parameter of the OpenSecureChannel service service call.
			*
			* @see setRequestType() */
			OTInt32 getRequestType() const;
			/*! Sets the RequestType parameter that has been provided with the OpenSecureChannel service call.
			*
			* A value of 0 means open a new secure channel.
			* A value of 1 means that the channel is renewed.
			*
			* @param requestType The type of the request */
			EnumStatusCode setRequestType(const OTInt32& requestType);

			/*! Returns the SecurityPolicyUri parameter of the OpenSecureChannel service call.
			*
			* @see setSecurityPolicyUri() */
			tstring getSecurityPolicyUri() const;
			/*! Sets the SecurityPolicyUri parameter that has been provided with the OpenSecureChannel service call.
			*
			* @param securityPolicyUri The security policy of the request */
			EnumStatusCode setSecurityPolicyUri(const tstring& securityPolicyUri);

			/*! Returns the SecurityMode parameter of the OpenSecureChannel service call.
			*
			* @see setSecurityMode() */
			EnumMessageSecurityMode getSecurityMode() const;
			/*! Sets the SecurityMode parameter that has been provided with the OpenSecureChannel service call.
			*
			* @param securityMode The security policy of the open request */
			EnumStatusCode setSecurityMode(const EnumMessageSecurityMode& securityMode);

			/*! Returns the RequestedLifetime parameter of the OpenSecureChannel service call.
			*
			* @see setRequestedLifetime() */
			OTDouble getRequestedLifetime() const;
			/*! Sets the RequestedLifetime parameter that has been provided with the OpenSecureChannel service call.
			*
			* @param requestedLifetime The requested life time of the secure channel */
			EnumStatusCode setRequestedLifetime(const OTDouble& requestedLifetime);

		private:
			/*! Forbid use assignment operator */
			AuditOpenSecureChannelEvent& operator=(const AuditOpenSecureChannelEvent&);
			/*! Forbid use of copy constructor */
			AuditOpenSecureChannelEvent(const AuditOpenSecureChannelEvent&);
		};
		typedef ObjectPointer<AuditOpenSecureChannelEvent> AuditOpenSecureChannelEventPtr;
		typedef ObjectPointer<const AuditOpenSecureChannelEvent> AuditOpenSecureChannelEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITOPENSECURECHANNELEVENT_H
