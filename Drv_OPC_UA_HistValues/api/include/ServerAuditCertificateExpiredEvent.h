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

#ifndef SERVERAUDITCERTIFICATEEXPIREDEVENT_H
#define SERVERAUDITCERTIFICATEEXPIREDEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCertificateEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event is generated if the certificate is expired.
		*
		* The certificate may be have a starting validity date in the future or an ending validity date in the past.
		*
		* This class does not define additional properties. */
		class TBC_EXPORT AuditCertificateExpiredEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateExpiredEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Certificate is expired" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateExpiredEvent> create();

		protected:
			/*! Default constructor */
			AuditCertificateExpiredEvent();
			/*! @overload */
			AuditCertificateExpiredEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateExpiredEvent();

		private:
			/*! Forbid use assignment operator */
			AuditCertificateExpiredEvent& operator=(const AuditCertificateExpiredEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateExpiredEvent(const AuditCertificateExpiredEvent&);
		};
		typedef ObjectPointer<AuditCertificateExpiredEvent> AuditCertificateExpiredEventPtr;
		typedef ObjectPointer<const AuditCertificateExpiredEvent> AuditCertificateExpiredEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEEXPIREDEVENT_H
