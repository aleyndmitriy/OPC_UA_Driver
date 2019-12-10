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

#ifndef SERVERAUDITCERTIFICATEDATAMISMATCHEVENT_H
#define SERVERAUDITCERTIFICATEDATAMISMATCHEVENT_H
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
		* It is generated if the host name in the URL used to connect to the server is not the same as one of the host names
		* specified in the certificate or if the Application and Software Certificates contain an application or
		* product URI that does not match the URI specified in the ApplicationDescription provided with the
		* Certificate.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li	InvalidHostname:	The string that represents the host name passed in as part of the URL that is
		*							found to be invalid. If the host name was not invalid this property must no be set.
		* @li	InvalidUri:			The URI that was passed in and found to not match what is contained in the certificate.
		*							If the URI was not invalid this property must no be set. */
		class TBC_EXPORT AuditCertificateDataMismatchEvent
			: public AuditCertificateEvent
		{
		public:
			/*! Constructs a new AuditCertificateDataMismatchEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Message:			"Invalid certificate data" / "en"
			* @li SourceName:		"Security/Certificate"
			* @li SourceNode:		The server object
			* @li ClientUserId:		"System/OpenSecureChannel"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCertificateDataMismatchEvent> create();

		protected:
			/*! Default constructor */
			AuditCertificateDataMismatchEvent();
			/*! @overload */
			AuditCertificateDataMismatchEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCertificateDataMismatchEvent();

			/*! Returns the InvalidHostname property.
			*
			* @see setInvalidHostname() */
			tstring getInvalidHostname() const;
			/*! Sets the InvalidHostname property of the audit event.
			*
			* @param invalidHostname The host name passed in as part of the URL that is found to be invalid. */
			EnumStatusCode setInvalidHostname(const tstring& invalidHostname);

			/*! Returns the InvalidUri property.
			*
			* @see setInvalidUri() */
			tstring getInvalidUri() const;
			/*! Sets the InvalidUri property of the audit event.
			* InvalidUri identifies the application or product URI contained in the ApplicationDescription
			* that does not match the URI provided with the certificate.
			*
			* @param invalidUri The URI that was passed with the ApplicationDescription */
			EnumStatusCode setInvalidUri(const tstring& invalidUri);

		private:
			/*! Forbid use assignment operator */
			AuditCertificateDataMismatchEvent& operator=(const AuditCertificateDataMismatchEvent&);
			/*! Forbid use of copy constructor */
			AuditCertificateDataMismatchEvent(const AuditCertificateDataMismatchEvent&);
		};
		typedef ObjectPointer<AuditCertificateDataMismatchEvent> AuditCertificateDataMismatchEventPtr;
		typedef ObjectPointer<const AuditCertificateDataMismatchEvent> AuditCertificateDataMismatchEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCERTIFICATEDATAMISMATCHEVENT_H
