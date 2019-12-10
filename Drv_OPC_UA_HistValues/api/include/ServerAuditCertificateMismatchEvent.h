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

#ifndef SERVERAUDITCERTIFICATEMISMATCHEVENT_H
#define SERVERAUDITCERTIFICATEMISMATCHEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCertificateEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event type is generated if a certificate set of uses does not match the requested
		* use for the certificate (i.e. application instance certificate, software certificate or CA).
		*
		* This class does not define additional properties. */
		class TBC_EXPORT AuditCertificateMismatchEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateMismatchEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Certificate mismatch" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateMismatchEvent> create();

		protected:
			/*! Default constructor */
			AuditCertificateMismatchEvent();
			/*! @overload */
			AuditCertificateMismatchEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateMismatchEvent();

		private:
			/*! Forbid use assignment operator */
			AuditCertificateMismatchEvent& operator=(const AuditCertificateMismatchEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateMismatchEvent(const AuditCertificateMismatchEvent&);
		};
		typedef ObjectPointer<AuditCertificateMismatchEvent> AuditCertificateMismatchEventPtr;
		typedef ObjectPointer<const AuditCertificateMismatchEvent> AuditCertificateMismatchEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEMISMATCHEVENT_H
