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

#ifndef SERVEREXCLUSIVELIMITALARM_H
#define SERVEREXCLUSIVELIMITALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerLimitAlarm.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class ExclusiveLimitStateMachine;
	}

	namespace Server
	{
		/*! The ExclusiveLimitAlarm is used to specify the common behavior for alarm types with multiple mutually
		* exclusive limits.
		*
		* @see ExclusiveLevelAlarm ExclusiveDeviationAlarm ExclusiveRateOfChangeAlarm */
		class TBC_EXPORT ExclusiveLimitAlarm
			: public LimitAlarm
		{
		public:
			/*! Constructs a new ExclusiveLimitAlarm instance */
			static ObjectPointer<ExclusiveLimitAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ExclusiveLimitAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ExclusiveLimitAlarm();
			/*! For internal use only */
			ExclusiveLimitAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ExclusiveLimitAlarm();

			/*! Returns the 'LimitState' component of the alarm.
			* The 'LimitState' represents the actual limit that is violated in an ExclusiveLimitAlarm. */
			ObjectPointer<Server::ExclusiveLimitStateMachine> getLimitState();
			/*! @overload */
			ObjectPointer<const Server::ExclusiveLimitStateMachine> getLimitState() const;

			/*! Callback method that is called whenever the input variable changes its value.
			*
			* Please note that the input variable needs to have a 'HasCondition' reference
			* that points to this alarm in order to trigger this callback method.
			*
			* An application should override this method to match its own requirements.
			* The method needs to be overridden, for example, if
			* @li the input variable has a data type different from double or float,
			* @li alarms are generated in an underlying system or
			* @li alarms use condition branches
			*
			* @param var	The variable which has changed
			* @param value	The new value of that variable
			*
			* @see Condition::onVariableChanged() */
			virtual void onVariableChanged(Server::Variable* var, const IDataValue* value);

			/*! Creates a new branch (copy) of this condition. The branch is made available after construction
			* by calling Condition::addBranch().
			*
			* The caller must provide a valid pointer to an "empty" branch (instance of a condition (sub-)type).
			* Override this method to add custom components (Objects, Variables, Methods) to your branch instance.
			* Default implementations populate the branch with all components of a condition (sub-)type
			* except for state machines. */
			virtual EnumStatusCode createBranch(Server::Condition* branchToConstruct);

		private:
			/*! Forbid use assignment operator */
			ExclusiveLimitAlarm& operator=(const ExclusiveLimitAlarm&);
			/*! Forbid use of copy constructor */
			ExclusiveLimitAlarm(const ExclusiveLimitAlarm&);
		};
		typedef ObjectPointer<ExclusiveLimitAlarm> ExclusiveLimitAlarmPtr;
		typedef ObjectPointer<const ExclusiveLimitAlarm> ExclusiveLimitAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVEREXCLUSIVELIMITALARM_H
