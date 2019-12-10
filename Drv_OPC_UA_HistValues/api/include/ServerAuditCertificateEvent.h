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

#ifndef SERVERAUDITCERTIFICATEEVENT_H
#define SERVERAUDITCERTIFICATEEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditEvent.h"
#include "ByteString.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class of all certificate-related audit events.
		*
		* Derived events of this class are generated if certificate validation fails.
		* This event type must not be directly generated, only specialized classes shall be reported.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li Certificate:	The certificate that encountered a validation issue. */
		class TBC_EXPORT AuditCertificateEvent
			: public AuditEvent
		{
		protected:
			/*! This constructor is used for derived classes.
			*
			* This constructor shall be called for specialized events with the concrete event type.
			*
			* A newly instantiated event has the following properties (beside the default properties of base class) already set:
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			AuditCertificateEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateEvent();

			/*! Returns the Certificate property.
			*
			* @see setCertificate() */
			ByteString getCertificate() const;
			/*! Sets the Certificate property of the audit event.
			*
			* The Certificate property contains the certificate which causes the event.
			*
			* @param certificate The certificate which causes the event */
			EnumStatusCode setCertificate(const IByteString* certificate);

		private:
			/*! Forbid use default constructor */
			AuditCertificateEvent();
			/*! Forbid use assignment operator */
			AuditCertificateEvent& operator=(const AuditCertificateEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateEvent(const AuditCertificateEvent&);
		};
		typedef ObjectPointer<AuditCertificateEvent> AuditCertificateEventPtr;
		typedef ObjectPointer<const AuditCertificateEvent> AuditCertificateEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEEVENT_H
