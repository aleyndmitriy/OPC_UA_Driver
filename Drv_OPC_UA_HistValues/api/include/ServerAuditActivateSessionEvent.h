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

#ifndef SERVERAUDITACTIVATESESSIONEVENT_H
#define SERVERAUDITACTIVATESESSIONEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditSessionEvent.h"
#include "UserIdentityToken.h"
#include "SignedSoftwareCertificate.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a client activates a session.
		*
		* The SourceName property for events of this type should be "Session/ActivateSession".
		* The SourceNode property for events of this type should be assigned to the server object.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li	ClientSoftwareCertificates:	The clientSoftwareCertificates parameter of the ActivateSession Service call.
		* @li	UserIdentityToken:			Reflects the userIdentityToken parameter of the ActivateSession Service call.
		*									For Username/Password tokens the password should NOT be included. */
		class TBC_EXPORT AuditActivateSessionEvent
			: public AuditSessionEvent
		{
		public:
			/*! Constructs a new AuditActivateSessionEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Session/ActivateSession"
			* @li SourceNode:		The server object
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditActivateSessionEvent> create();

		protected:
			/*! Default constructor */
			AuditActivateSessionEvent();
			/*! @overload */
			AuditActivateSessionEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditActivateSessionEvent();

			/*! Returns the ClientSoftwareCertificates property.
			*
			* @see setClientSoftwareCertificates() */
			std::vector<SignedSoftwareCertificate> getClientSoftwareCertificates() const;
			/*! Sets the ClientSoftwareCertificates property of the audit event.
			*
			* ClientSoftwareCertificates are the SoftwareCertificates which have been issued to the Client application.
			*
			* @param certificates The certificates */
			EnumStatusCode setClientSoftwareCertificates(const std::vector<const ISignedSoftwareCertificate*> certificates);

			/*! Returns the UserIdentityToken property.
			*
			* @see setUserIdentityToken() */
			UserIdentityToken getUserIdentityToken() const;
			/*! Sets the UserIdentityToken property of the audit event.
			*
			* UserIdentityToken is the identity token of the user initiating the session activation.
			* For Username/Password tokens the password should NOT be included.
			*
			* @param userIdentityToken The user identity token of th client session */
			EnumStatusCode setUserIdentityToken(const IUserIdentityToken* userIdentityToken);

		private:
			/*! Forbid use assignment operator */
			AuditActivateSessionEvent& operator=(const AuditActivateSessionEvent&);
			/*! Forbid use of copy constructor */
			AuditActivateSessionEvent(const AuditActivateSessionEvent&);
		};
		typedef ObjectPointer<AuditActivateSessionEvent> AuditActivateSessionEventPtr;
		typedef ObjectPointer<const AuditActivateSessionEvent> AuditActivateSessionEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITACTIVATESESSIONEVENT_H
