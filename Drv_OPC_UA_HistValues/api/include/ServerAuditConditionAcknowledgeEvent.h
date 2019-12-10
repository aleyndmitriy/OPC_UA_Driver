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

#ifndef SERVERAUDITCONDITIONACKNOWLEDGEEVENT_H
#define SERVERAUDITCONDITIONACKNOWLEDGEEVENT_H
#if TB5_ALARMS
#include "ServerAuditUpdateMethodEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a condition is acknowledged.
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li EventId:	This property shall contain the id of the event for which the comment was added.
		* @li Comment:	Contains the actual comment that was added. */
		class TBC_EXPORT AuditConditionAcknowledgeEvent
			: public AuditUpdateMethodEvent
		{
		public:
			/*! Constructs a new AuditConditionAcknowledgeEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Method/ConditionAcknowledge"
			* @li Message:			"Condition acknowledged" / "en".
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditConditionAcknowledgeEvent> create();

		protected:
			/*! Default constructor */
			AuditConditionAcknowledgeEvent();
			/*! @overload */
			AuditConditionAcknowledgeEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditConditionAcknowledgeEvent();

		private:
			/*! Forbid use assignment operator */
			AuditConditionAcknowledgeEvent& operator=(const AuditConditionAcknowledgeEvent&);
			/*! Forbid use of copy constructor */
			AuditConditionAcknowledgeEvent(const AuditConditionAcknowledgeEvent&);
		};
		typedef ObjectPointer<AuditConditionAcknowledgeEvent> AuditConditionAcknowledgeEventPtr;
		typedef ObjectPointer<const AuditConditionAcknowledgeEvent> AuditConditionAcknowledgeEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCONDITIONACKNOWLEDGEEVENT_H
