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

#ifndef SERVERNONEXCLUSIVELIMITALARM_H
#define SERVERNONEXCLUSIVELIMITALARM_H
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
		class TwoStateVariable;
	}

	namespace Server
	{
		/*! The NonExclusiveLimitAlarm is used to specify the common behavior for alarm types with multiple non-exclusive
		* limits.
		*
		* @see NonExclusiveLevelAlarm NonExclusiveDeviationAlarm NonExclusiveRateOfChangeAlarm */
		class TBC_EXPORT NonExclusiveLimitAlarm
			: public LimitAlarm
		{
		public:
			/*! Constructs a new NonExclusiveLimitAlarm instance */
			static ObjectPointer<NonExclusiveLimitAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			NonExclusiveLimitAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			NonExclusiveLimitAlarm();
			/*! For internal use only */
			NonExclusiveLimitAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~NonExclusiveLimitAlarm();

			/*! Returns the 'HighHighState' variable. The value of this
			* variable indicates whether the HighHigh limit has been exceeded or not.
			*
			* Please use TwoStateVariable::setCurrentState() to change the current state. */
			ObjectPointer<Server::TwoStateVariable> getHighHighStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getHighHighStateVar() const;

			/*! Returns the localized text that describes the current HighHigh state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		HighHigh state (see NonExclusiveLimitAlarm::getHighHighStateVar()).
			*		The localized texts that describe the 'true' and 'false' HighHigh state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getHighHighState() const;

			/*! Returns the 'HighState' variable. The value of this
			* variable indicates whether the High limit has been exceeded or not.
			*
			* Please use TwoStateVariable::setCurrentState() to change the current state. */
			ObjectPointer<Server::TwoStateVariable> getHighStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getHighStateVar() const;

			/*! Returns the localized text that describes the current High state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		High state (see NonExclusiveLimitAlarm::getHighStateVar()).
			*		The localized texts that describe the 'true' and 'false' High state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getHighState() const;

			/*! Returns the 'LowState' variable. The value of this
			* variable indicates whether the Low limit has been exceeded or not.
			*
			* Please use TwoStateVariable::setCurrentState() to change the current state. */
			ObjectPointer<Server::TwoStateVariable> getLowStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getLowStateVar() const;

			/*! Returns the localized text that describes the current Low state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		Low state (see NonExclusiveLimitAlarm::getLowStateVar()).
			*		The localized texts that describe the 'true' and 'false' Low state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getLowState() const;

			/*! Returns the 'LowLowState' variable. The value of this
			* variable indicates whether the LowLow limit has been exceeded or not.
			*
			* Please use TwoStateVariable::setCurrentState() to change the current state. */
			ObjectPointer<Server::TwoStateVariable> getLowLowStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getLowLowStateVar() const;

			/*! Returns the localized text that describes the current LowLow state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		LowLow state (see NonExclusiveLimitAlarm::getLowLowStateVar()).
			*		The localized texts that describe the 'true' and 'false' LowLow state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getLowLowState() const;

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
			NonExclusiveLimitAlarm& operator=(const NonExclusiveLimitAlarm&);
			/*! Forbid use of copy constructor */
			NonExclusiveLimitAlarm(const NonExclusiveLimitAlarm&);
		};
		typedef ObjectPointer<NonExclusiveLimitAlarm> NonExclusiveLimitAlarmPtr;
		typedef ObjectPointer<const NonExclusiveLimitAlarm> NonExclusiveLimitAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERNONEXCLUSIVELIMITALARM_H
