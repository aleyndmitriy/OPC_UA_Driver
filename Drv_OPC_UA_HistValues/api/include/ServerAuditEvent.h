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

#ifndef SERVERAUDITEVENT_H
#define SERVERAUDITEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerBaseEventNotification.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class of all audit events.
		*
		* This base class exposes the common properties of all specialized audit events.
		* It is an abstract class and events of this type are not meant to be reported to the client.
		*
		* The exposed properties can be set via its access methods.
		* Beside the properties of the base class additionally the following mandatory properties shall be set:
		* @li ActionTimeStamp:		Identifies the time the user initiated the action.
		* @li Status:				Identifies whether the requested action could be performed.
		* @li ServerId:				Uniquely identifies the Server generating the Event.
		* @li ClientAuditEntryId:	Contains the human-readable AuditEntryId.
		* @li ClientUserId:			Identifies the user of the client requesting an action. */
		class TBC_EXPORT AuditEvent
			: public BaseEventNotification
		{
		protected:
			/*! Constructs a new audit event for the given audit event type.
			*
			* This constructor shall be called from derived classes with the concrete event type.
			*
			* The newly created object has already the following properties initially set:
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			AuditEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditEvent();

			/*! Returns the time (in UTC) the user initiated the action that resulted in the AuditEvent being generated.
			*
			* @see setActionTimeStamp() */
			DateTime getActionTimeStamp() const;
			/*! Returns the time the user initiated the action that resulted in the AuditEvent being generated.
			* It differs from the Time property of the BaseEvent because this is the time the server generated the
			* AuditEvent documenting the action.
			*
			* The ActionTimeStamp contains a UTC time.
			*
			* @param actionTimeStamp The UTC time of the action */
			EnumStatusCode setActionTimeStamp(const IDateTime* actionTimeStamp);

			/*! Returns whether the requested action could be performed ('true') or not ('false').
			*
			* @see setStatus() */
			bool getStatus() const;
			/*! Sets whether the requested action could be performed ('true') or not ('false').
			*
			* @param status The status of the action */
			EnumStatusCode setStatus(bool status);

			/*! Returns the ID of the server generating the event.
			*
			* @see setServerId() */
			tstring getServerId() const;
			/*! Sets the ID of the server generating the event.
			*
			* The server ID identifies the server uniquely even in a server-controlled transparent
			* redundancy scenario where several servers may use the same URI.
			*
			* @param serverId  The ID of the server */
			EnumStatusCode setServerId(const tstring serverId);

			/*! Returns the human-readable AuditEntryId provided by the client.
			*
			* @see setClientAuditEntryId() */
			tstring getClientAuditEntryId() const;
			/*! Sets the human-readable AuditEntryId provided by the client.
			* The AuditEntryId typically contains who initiated the action and from where it was initiated.
			*
			* @param clientAuditEntryId The audit entry ID */
			EnumStatusCode setClientAuditEntryId(const tstring clientAuditEntryId);

			/*! Returns the user of the client that requested the action.
			*
			* @see setClientUserId() */
			tstring getClientUserId() const;
			/*! Sets the user of the client that requested the action.
			*
			* The ClientUserId can be obtained from the UserIdentityToken passed in the ActivateSession call.
			* This token can contain the information in multiple formats depending on the type of User Identity
			* that is passed to the service. If the UserIdentityToken that was passed was defined as a UserName,
			* then the structure contains an explicit string that is the user. If the passed UserIdentityToken was
			* defined as X509v3, then the CertificateData byte string contains an element that is the user string
			* which can be extracted from the subject key in this structure. If the passed UserIdentityToken was
			* defined as WSS, then the user string can be extracted from the WS-Security XML token.
			* If an AnonymousIdentityToken was used, the value is null.
			*
			* @param clientUserId The user ID who initiated the action */
			EnumStatusCode setClientUserId(const tstring clientUserId);

		private:
			/*! Forbid use default constructor */
			AuditEvent();
			/*! Forbid use assignment operator */
			AuditEvent& operator=(const AuditEvent&);
			/*! Forbid use of copy constructor */
			AuditEvent(const AuditEvent&);
		};
		typedef ObjectPointer<AuditEvent> AuditEventPtr;
		typedef ObjectPointer<const AuditEvent> AuditEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITEVENT_H
