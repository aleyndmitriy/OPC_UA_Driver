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

#ifndef SERVERAUDITCONDITIONENABLEEVENT_H
#define SERVERAUDITCONDITIONENABLEEVENT_H
#if TB5_ALARMS
#include "ServerAuditUpdateMethodEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a condition is enabled or disabled.
		*
		* There are no additionally properties in that event. */
		class TBC_EXPORT AuditConditionEnableEvent
			: public AuditUpdateMethodEvent
		{
		public:
			/*! Constructs a new AuditConditionEnableEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditConditionEnableEvent> create();

		protected:
			/*! Default constructor */
			AuditConditionEnableEvent();
			/*! @overload */
			AuditConditionEnableEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditConditionEnableEvent();

			/*! Sets the properties SourceName and Message of the audit event.
			*
			* @param enable		True if the condition is enabled, false if condition is disabled.
			* @param byMethod	True if enable state change is triggered by a method, false if triggered by server internally. */
			EnumStatusCode setEnabledTexts(bool enable, bool byMethod);

		private:
			/*! Forbid use assignment operator */
			AuditConditionEnableEvent& operator=(const AuditConditionEnableEvent&);
			/*! Forbid use of copy constructor */
			AuditConditionEnableEvent(const AuditConditionEnableEvent&);
		};
		typedef ObjectPointer<AuditConditionEnableEvent> AuditConditionEnableEventPtr;
		typedef ObjectPointer<const AuditConditionEnableEvent> AuditConditionEnableEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCONDITIONENABLEEVENT_H
