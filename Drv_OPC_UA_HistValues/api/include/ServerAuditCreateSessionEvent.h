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

#ifndef SERVERAUDITCREATESESSIONEVENT_H
#define SERVERAUDITCREATESESSIONEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditSessionEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a client creates a session.
		*
		* The SourceNode property for events of this type should be assigned to the Server object.
		* The ClientUserId property for audit events is not available for this call thus this parameter shall be set to the "System/CreateSession".
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li SecureChannelId:				Shall uniquely identify the SecureChannel.
		* @li ClientCertificate:			The clientCertificate parameter of the CreateSession Service call.
		* @li ClientCertificateThumbprint:	A thumb print of the ClientCertificate.
		* @li RevisedSessionTimeout:		The returned revisedSessionTimeout parameter of the CreateSession Service call. */
		class TBC_EXPORT AuditCreateSessionEvent
			: public AuditSessionEvent
		{
		public:
			/*! Constructs a new AuditCreateSessionEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Session/CreateSession"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/CreateSession"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCreateSessionEvent> create();

		protected:
			/*! Constructs a new audit event for the given audit event type
			*
			* This constructor shall be used from derived classes with the concrete event type. */
			AuditCreateSessionEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCreateSessionEvent();

			/*! Returns the SecureChannelId that uniquely identifies the secure channel.
			*
			* @see setSecureChannelId() */
			tstring getSecureChannelId() const;
			/*! Sets the SecureChannelId that uniquely identifies the secure channel.
			*
			* @param secureChannelId The ID of the secure channel */
			EnumStatusCode setSecureChannelId(const tstring& secureChannelId);

			/*! Returns the client certificate provided with the CreateSession service invocation.
			*
			* @see setClientCertificate() */
			ByteString getClientCertificate() const;
			/*! Sets the client certificate provided with the CreateSession service invocation.
			*
			* @param clientCertificate The certificate of the client creating a session */
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

			/*! Returns the revised session timeout provided with the CreateSession response.
			*
			* @see setRevisedSessionTimeout() */
			OTDouble getRevisedSessionTimeout() const;
			/*! Sets the revised session timeout provided with the CreateSession response.
			*
			* @param revisedSessionTimeout The revised timeout of the created session */
			EnumStatusCode setRevisedSessionTimeout(const OTDouble& revisedSessionTimeout);

		private:
			/*! Forbid use default constructor */
			AuditCreateSessionEvent();
			/*! Forbid use assignment operator */
			AuditCreateSessionEvent& operator=(const AuditCreateSessionEvent&);
			/*! Forbid use of copy constructor */
			AuditCreateSessionEvent(const AuditCreateSessionEvent&);
		};
		typedef ObjectPointer<AuditCreateSessionEvent> AuditCreateSessionEventPtr;
		typedef ObjectPointer<const AuditCreateSessionEvent> AuditCreateSessionEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCREATESESSIONEVENT_H
