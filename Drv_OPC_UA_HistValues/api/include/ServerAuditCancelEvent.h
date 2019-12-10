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

#ifndef SERVERAUDITCANCELEVENT_H
#define SERVERAUDITCANCELEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditSessionEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a client cancels requests.
		*
		* The SourceName property for events of this type should be "Session/Cancel".
		* The SourceNode property for events of this type should be assigned to the server object.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li RequestHandle:	The requestHandle parameter of the Cancel Service call. */
		class TBC_EXPORT AuditCancelEvent
			: public AuditSessionEvent
		{
		public:
			/*! Constructs a new AuditCancelEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Session/Cancel"
			* @li SourceNode:		The server object
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditCancelEvent> create();

		protected:
			/*! Default constructor */
			AuditCancelEvent();
			/*! @overload */
			AuditCancelEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditCancelEvent();

			/*! Returns the RequestHandle property.
			*
			* @see setRequestHandle() */
			OTUInt32 getRequestHandle() const;
			/*! Sets the RequestHandle property of the audit event.
			*
			* RequestHandle is the transaction ID of the cancelled transactions.
			* @see Client::Session::cancelTransaction()
			*
			* @param requestHandle The ID of the transactions */
			EnumStatusCode setRequestHandle(const OTUInt32 requestHandle);

		private:
			/*! Forbid use assignment operator */
			AuditCancelEvent& operator=(const AuditCancelEvent&);
			/*! Forbid use of copy constructor */
			AuditCancelEvent(const AuditCancelEvent&);
		};
		typedef ObjectPointer<AuditCancelEvent> AuditCancelEventPtr;
		typedef ObjectPointer<const AuditCancelEvent> AuditCancelEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCANCELEVENT_H
