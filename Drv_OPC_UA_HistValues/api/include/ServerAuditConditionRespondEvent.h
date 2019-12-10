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

#ifndef SERVERAUDITCONDITIONRESPONDEVENT_H
#define SERVERAUDITCONDITIONRESPONDEVENT_H
#if TB5_ALARMS
#include "ServerAuditUpdateMethodEvent.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event shall be generated if the respond method of a dialog condition is called.
		*
		* Beside mandatory properties of the base class additionally the following mandatory property shall be set:
		* @li SelectedResponse:	This property shall contain the response that was selected. */
		class TBC_EXPORT AuditConditionRespondEvent
			: public AuditUpdateMethodEvent
		{
		public:
			/*! Constructs a new AuditConditionRespondEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Method/ConditionRespond"
			* @li Message:			"Condition response received" / "en".
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditConditionRespondEvent> create();

		protected:
			/*! Default constructor */
			AuditConditionRespondEvent();
			/*! @overload */
			AuditConditionRespondEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditConditionRespondEvent();

			/*! Returns the response that was selected in the dialog. */
			OTInt32 getSelectedResponse() const;
			/*! Sets the response that was selected in the dialog. */
			EnumStatusCode setSelectedResponse(OTInt32 response);

		private:
			/*! Forbid use assignment operator */
			AuditConditionRespondEvent& operator=(const AuditConditionRespondEvent&);
			/*! Forbid use of copy constructor */
			AuditConditionRespondEvent(const AuditConditionRespondEvent&);
		};
		typedef ObjectPointer<AuditConditionRespondEvent> AuditConditionRespondEventPtr;
		typedef ObjectPointer<const AuditConditionRespondEvent> AuditConditionRespondEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITCONDITIONRESPONDEVENT_H
