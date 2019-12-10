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

#ifndef SERVERAUDITCERTIFICATEINVALIDEVENT_H
#define SERVERAUDITCERTIFICATEINVALIDEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCertificateEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event is generated if the data in the certificate do not match the given data.
		*
		* It is generated if the HostName in the URL used to connect to the Server is not the same as one of the HostNames
		* specified in the Certificate or if Application and Software Certificates contain an application or
		* product URI that does not match the URI specified in the ApplicationDescription provided with the
		* Certificate.
		*
		* This class does not define any additional properties. */
		class TBC_EXPORT AuditCertificateInvalidEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateInvalidEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Invalid certificate" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateInvalidEvent> create();

		protected:
			/*! Default constructor */
			AuditCertificateInvalidEvent();
			/*! @overload */
			AuditCertificateInvalidEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateInvalidEvent();

		private:
			/*! Forbid use assignment operator */
			AuditCertificateInvalidEvent& operator=(const AuditCertificateInvalidEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateInvalidEvent(const AuditCertificateInvalidEvent&);
		};
		typedef ObjectPointer<AuditCertificateInvalidEvent> AuditCertificateInvalidEventPtr;
		typedef ObjectPointer<const AuditCertificateInvalidEvent> AuditCertificateInvalidEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEINVALIDEVENT_H
