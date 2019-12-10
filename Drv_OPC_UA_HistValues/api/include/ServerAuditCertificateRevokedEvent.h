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

#ifndef SERVERAUDITCERTIFICATEREVOKEDEVENT_H
#define SERVERAUDITCERTIFICATEREVOKEDEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCertificateEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event is generated if the certificate is revoked.
		*
		* This happens if the given certificate is in the revocation list of the signing certificate authority.
		*
		* This class does not define additional properties. */
		class TBC_EXPORT AuditCertificateRevokedEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateRevokedEvent instance.
			*
			* A newly instantiated event has the following properties (beside the default properties of base class) already set:
			* @li Message:			"Certificate is revoked" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateRevokedEvent> create();

		protected:
			/*! Default constructor */
			AuditCertificateRevokedEvent();
			/*! @overload */
			AuditCertificateRevokedEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateRevokedEvent();

		private:
			/*! Forbid use assignment operator */
			AuditCertificateRevokedEvent& operator=(const AuditCertificateRevokedEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateRevokedEvent(const AuditCertificateRevokedEvent&);
		};
		typedef ObjectPointer<AuditCertificateRevokedEvent> AuditCertificateRevokedEventPtr;
		typedef ObjectPointer<const AuditCertificateRevokedEvent> AuditCertificateRevokedEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEREVOKEDEVENT_H
