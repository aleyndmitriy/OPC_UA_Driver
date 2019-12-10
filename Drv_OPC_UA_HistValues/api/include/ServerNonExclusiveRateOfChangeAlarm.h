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

#ifndef SERVERNONEXCLUSIVERATEOFCHANGEALARM_H
#define SERVERNONEXCLUSIVERATEOFCHANGEALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerNonExclusiveLimitAlarm.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A rate of change alarm is commonly used to report an unusual change or lack of change in a
		* measured value related to the speed at which the value has changed. The rate of change alarm
		* becomes active when the rate at which the value changes exceeds or drops below a defined limit.
		*
		* The NonExclusiveRateOfChangeAlarm is a special level alarm utilized with one or more non-exclusive
		* states.
		*
		* If for example both the High and HighHigh states need to be maintained as active at the same time this
		* alarm type should be used */
		class TBC_EXPORT NonExclusiveRateOfChangeAlarm
			: public NonExclusiveLimitAlarm
		{
		public:
			/*! Constructs a new NonExclusiveRateOfChangeAlarm instance */
			static ObjectPointer<NonExclusiveRateOfChangeAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			NonExclusiveRateOfChangeAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			NonExclusiveRateOfChangeAlarm();
			/*! For internal use only */
			NonExclusiveRateOfChangeAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~NonExclusiveRateOfChangeAlarm();

		private:
			/*! Forbid use assignment operator */
			NonExclusiveRateOfChangeAlarm& operator=(const NonExclusiveRateOfChangeAlarm&);
			/*! Forbid use of copy constructor */
			NonExclusiveRateOfChangeAlarm(const NonExclusiveRateOfChangeAlarm&);
		};
		typedef ObjectPointer<NonExclusiveRateOfChangeAlarm> NonExclusiveRateOfChangeAlarmPtr;
		typedef ObjectPointer<const NonExclusiveRateOfChangeAlarm> NonExclusiveRateOfChangeAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERNONEXCLUSIVERATEOFCHANGEALARM_H
