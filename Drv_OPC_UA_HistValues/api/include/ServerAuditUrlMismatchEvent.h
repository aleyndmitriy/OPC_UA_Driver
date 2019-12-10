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

#ifndef SERVERAUDITURLMISMATCHEVENT_H
#define SERVERAUDITURLMISMATCHEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditCreateSessionEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if the EndpointUrl used in the CreateSession service call does not
		* match the server's hostname.
		*
		* The SourceNode property for events of this type should be assigned to the server object.
		* The ClientUserId property for audit events is not available for this call thus this parameter shall be set to the "System/CreateSession".
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li EndpointUrl:	The endpointUrl parameter of the CreateSession service call */
		class TBC_EXPORT AuditUrlMismatchEvent
			: public AuditCreateSessionEvent
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
			static ObjectPointer<AuditUrlMismatchEvent> create();

		protected:
			/*! Default constructor */
			AuditUrlMismatchEvent();
			/*! @overload */
			AuditUrlMismatchEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditUrlMismatchEvent();

			/*! Returns the EndpointUrl parameter of the CreateSession service call.
			*
			* @see setEndpointUrl() */
			tstring getEndpointUrl() const;
			/*! Sets the EndpointUrl parameter that has been provided with the CreateSession service call.
			*
			* @param endpointUrl The endpoint URL used in the CreateSession service call */
			EnumStatusCode setEndpointUrl(const tstring& endpointUrl);

		private:
			/*! Forbid use assignment operator */
			AuditUrlMismatchEvent& operator=(const AuditUrlMismatchEvent&);
			/*! Forbid use of copy constructor */
			AuditUrlMismatchEvent(const AuditUrlMismatchEvent&);
		};
		typedef ObjectPointer<AuditUrlMismatchEvent> AuditUrlMismatchEventPtr;
		typedef ObjectPointer<const AuditUrlMismatchEvent> AuditUrlMismatchEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITURLMISMATCHEVENT_H
