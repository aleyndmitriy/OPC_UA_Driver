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

#ifndef SERVERAUDITCONDITIONSHELVINGEVENT_H
#define SERVERAUDITCONDITIONSHELVINGEVENT_H
#if TB5_ALARMS
#include "ServerAuditUpdateMethodEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if a condition is shelved or unshelved.
		*
		* Beside properties of the base class additionally the following optional property can be set:
		* @li ShelvingTime:	This property shall contain duration for which the Alarm is to be shelved. */
		class TBC_EXPORT AuditConditionShelvingEvent
			: public AuditUpdateMethodEvent
		{
		public:
			/*! Constructs a new AuditConditionShelvingEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Method/ConditionShelving"
			* @li Message:			"Condition shelving state changed" / "en".
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditConditionShelvingEvent> create();

		protected:
			/*! Default constructor */
			AuditConditionShelvingEvent();
			/*! @overload */
			AuditConditionShelvingEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditConditionShelvingEvent();

			/*! Returns the duration (in milliseconds) for which an alarm is to be shelved. */
			double getShelvingTime() const;
			/*! Sets the ShelvingTime property of the audit event.
			*
			* The shelving time property is an optional property for this event type.
			* In case of a TimeShelve operation the property shall contain the duration
			* for which the alarm is to be shelved. For other changes in the shelving state
			* this property can be omitted.

			* @param shelvingTime The duration (in milliseconds) for which the alarm is to be shelved */
			EnumStatusCode setShelvingTime(double shelvingTime);

		private:
			/*! Forbid use assignment operator */
			AuditConditionShelvingEvent& operator=(const AuditConditionShelvingEvent&);
			/*! Forbid use of copy constructor */
			AuditConditionShelvingEvent(const AuditConditionShelvingEvent&);
		};
		typedef ObjectPointer<AuditConditionShelvingEvent> AuditConditionShelvingEventPtr;
		typedef ObjectPointer<const AuditConditionShelvingEvent> AuditConditionShelvingEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCONDITIONSHELVINGEVENT_H
