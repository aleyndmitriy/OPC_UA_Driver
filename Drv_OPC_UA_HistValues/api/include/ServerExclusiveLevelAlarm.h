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

#ifndef SERVEREXCLUSIVELEVELALARM_H
#define SERVEREXCLUSIVELEVELALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerExclusiveLimitAlarm.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A level alarm is commonly used to report when a limit is exceeded. It typically relates to an
		* instrument (e.g. a temperature meter). The level alarm becomes active when the observed value is
		* above a high limit or below a low limit.
		*
		* The ExclusiveLevelAlarm is a special level alarm utilized with multiple mutually exclusive limits. */
		class TBC_EXPORT ExclusiveLevelAlarm
			: public ExclusiveLimitAlarm
		{
		public:
			/*! Constructs a new ExclusiveLevelAlarm instance */
			static ObjectPointer<ExclusiveLevelAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ExclusiveLevelAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ExclusiveLevelAlarm();
			/*! For internal use only */
			ExclusiveLevelAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ExclusiveLevelAlarm();

		private:
			/*! Forbid use assignment operator */
			ExclusiveLevelAlarm& operator=(const ExclusiveLevelAlarm&);
			/*! Forbid use of copy constructor */
			ExclusiveLevelAlarm(const ExclusiveLevelAlarm&);
		};
		typedef ObjectPointer<ExclusiveLevelAlarm> ExclusiveLevelAlarmPtr;
		typedef ObjectPointer<const ExclusiveLevelAlarm> ExclusiveLevelAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVEREXCLUSIVELEVELALARM_H
