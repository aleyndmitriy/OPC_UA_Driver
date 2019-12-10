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

#ifndef SERVERSHELVEDSTATEMACHINE_H
#define SERVERSHELVEDSTATEMACHINE_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerFiniteStateMachine.h"
#include "ServerAlarmCondition.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
		class State;
		class Transition;
		class ShelvedStateMachineTimedShelve;
		class ShelvedStateMachineOneShotShelve;
		class ShelvedStateMachineUnshelve;
	}

	namespace Server
	{
		/*! The ShelvedStateMachine class defines a state machine that represents an advanced alarm filtering model.
		* This StateMachine defines three states: Unshelved, TimedShelved and OneShotShelved. */
		class TBC_EXPORT ShelvedStateMachine
			: public FiniteStateMachine
		{
		public:
			/*! Constructs a new ShelvedStateMachine instance */
			static ObjectPointer<ShelvedStateMachine> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ShelvedStateMachine(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ShelvedStateMachine();
			/*! For internal use only */
			ShelvedStateMachine(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ShelvedStateMachine();

			/*! Shelves the alarm using one-shot shelving. The one-shot shelving clears automatically when an alarm returns
			* to an inactive state. */
			EnumStatusCode shelve();

			/*! Shelves the alarm using timed shelving. In timed shelving, a user specifies that an alarm is to be shelved
			* for a fixed period of time.
			*
			* @param duration	The time (in milliseconds) that indicates how long the alarm is to be shelved */
			EnumStatusCode timeShelve(double duration);

			/*! Unshelves a shelved alarm. */
			EnumStatusCode unshelve();

			/*! Returns the alarm to which the shelving state machine belongs. */
			ObjectPointer<Server::AlarmCondition> getAlarmCondition();
			/*! @overload */
			ObjectPointer<const Server::AlarmCondition> getAlarmCondition() const;

			/*! Returns the 'UnshelveTime' property. */
			ObjectPointer<Server::Variable> getUnshelveTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getUnshelveTimeVar() const;

			/*! Returns the remaining time in milliseconds until the alarm is automatically being unshelved. */
			double getUnshelveTime() const;
			/*! Sets the remaining time in milliseconds until the alarm is automatically being unshelved.
			*
			* @li	For one-shot shelving, the unshelve time should be initialized with the value of the
			*		'MaxTimeShelved' property
			* @li	For timed shelving, the time should be initialized with the provided period of time */
			virtual EnumStatusCode setUnshelveTime(double unshelveTime);

			/*! Returns the 'Unshelved' State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getUnshelved();
			/*! @overload */
			ObjectPointer<const Server::State> getUnshelved() const;

			/*! Returns the 'TimedShelved' State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getTimedShelved();
			/*! @overload */
			ObjectPointer<const Server::State> getTimedShelved() const;

			/*! Returns the 'OneShotShelved' State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getOneShotShelved();
			/*! @overload */
			ObjectPointer<const Server::State> getOneShotShelved() const;

			/*! Returns the 'UnshelvedToTimedShelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getUnshelvedToTimedShelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getUnshelvedToTimedShelved() const;

			/*! Returns the 'TimedShelvedToUnshelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getTimedShelvedToUnshelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getTimedShelvedToUnshelved() const;

			/*! Returns the 'UnshelvedToOneShotShelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getUnshelvedToOneShotShelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getUnshelvedToOneShotShelved() const;

			/*! Returns the 'OneShotShelvedToUnshelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getOneShotShelvedToUnshelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getOneShotShelvedToUnshelved() const;

			/*! Returns the 'OneShotShelvedToTimedShelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getOneShotShelvedToTimedShelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getOneShotShelvedToTimedShelved() const;

			/*! Returns the 'TimedShelvedToOneShotShelved' Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getTimedShelvedToOneShotShelved();
			/*! @overload */
			ObjectPointer<const Server::Transition> getTimedShelvedToOneShotShelved() const;

			/*! Returns the 'OneShotShelve' Method node.
			*
			* @note The returned node is the method node defined at the state machine type.
			* Do not remove methods from the type definition! */
			ObjectPointer<Server::ShelvedStateMachineOneShotShelve> getOneShotShelve();
			/*! @overload */
			ObjectPointer<const Server::ShelvedStateMachineOneShotShelve> getOneShotShelve() const;

			/*! Returns the 'TimedShelve' Method node.
			*
			* @note The returned node is the method node defined at the state machine type.
			* Do not remove methods from the type definition! */
			ObjectPointer<Server::ShelvedStateMachineTimedShelve> getTimedShelve();
			/*! @overload */
			ObjectPointer<const Server::ShelvedStateMachineTimedShelve> getTimedShelve() const;

			/*! Returns the 'Unshelve' Method node.
			*
			* @note The returned node is the method node defined at the state machine type.
			* Do not remove methods from the type definition! */
			ObjectPointer<Server::ShelvedStateMachineUnshelve> getUnshelve();
			/*! @overload */
			ObjectPointer<const Server::ShelvedStateMachineUnshelve> getUnshelve() const;

		private:
			/*! Forbid use assignment operator */
			ShelvedStateMachine& operator=(const ShelvedStateMachine&);
			/*! Forbid use of copy constructor */
			ShelvedStateMachine(const ShelvedStateMachine&);
		};
		typedef ObjectPointer<ShelvedStateMachine> ShelvedStateMachinePtr;
		typedef ObjectPointer<const ShelvedStateMachine> ShelvedStateMachineConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERSHELVEDSTATEMACHINE_H
