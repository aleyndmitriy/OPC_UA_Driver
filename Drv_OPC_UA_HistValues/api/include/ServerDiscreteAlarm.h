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

#ifndef SERVERDISCRETEALARM_H
#define SERVERDISCRETEALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerAlarmCondition.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The DiscreteAlarm type is an alarm type used to classify alarm conditions where the input
		* for the alarm may take on only a certain number of possible values (e.g. true/false, running/stopped/terminating).
		*
		* @see OffNormalAlarm TripAlarm */
		class TBC_EXPORT DiscreteAlarm
			: public AlarmCondition
		{
		public:
			/*! Constructs a new DiscreteAlarm instance */
			static ObjectPointer<DiscreteAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DiscreteAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			DiscreteAlarm();
			/*! For internal use only */
			DiscreteAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~DiscreteAlarm();

			/*! Forbid use assignment operator */
			DiscreteAlarm& operator=(const DiscreteAlarm&);
			/*! Forbid use of copy constructor */
			DiscreteAlarm(const DiscreteAlarm&);
		};
		typedef ObjectPointer<DiscreteAlarm> DiscreteAlarmPtr;
		typedef ObjectPointer<const DiscreteAlarm> DiscreteAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERDISCRETEALARM_H
