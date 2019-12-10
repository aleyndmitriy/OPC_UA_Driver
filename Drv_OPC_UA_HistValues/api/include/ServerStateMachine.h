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

#ifndef SERVERSTATEMACHINE_H
#define SERVERSTATEMACHINE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerObject.h"
#include "ServerState.h"
#include "ServerTransition.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class StateVariable;
		class TransitionVariable;
		class State;
	}

	namespace Server
	{
		/*! The StateMachine class is the base class for all state machines that are
		* exposed in the address space of a server.
		*
		* @see FiniteStateMachine */
		class TBC_EXPORT StateMachine
			: public Object
		{
		public:
			/*! Constructs a new StateMachine instance */
			static ObjectPointer<StateMachine> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			StateMachine(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			StateMachine();
			/*! For internal use only */
			StateMachine(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~StateMachine();

			/*! Deactivates the state machine. This method resets the values of the CurrentState
			* and the LastTransition and assigns the values a bad quality (Bad_StateNotActive). */
			virtual EnumStatusCode deactivate();
			/*! Returns whether the state machine is active. */
			bool isActive() const;
			/*! Activates the state machine and sets the CurrentState property. Please
			* note that this method does not touch the LastTransitionTime property.
			*
			* This method returns a bad status code if the state machine is already active. */
			virtual EnumStatusCode activate();

			/*! Returns the "CurrentState" property that holds the current state
			* of the state machine.
			*
			* Please use StateVariable::setId() to change the current state. */
			ObjectPointer<Server::StateVariable> getCurrentStateVar();
			/*! @overload */
			ObjectPointer<const Server::StateVariable> getCurrentStateVar() const;

			/*! Returns the localized text that describes the current state.
			*
			* @note	Please use StateVariable::getId() to retrieve the current
			*		state (see StateMachine::getId()). */
			LocalizedText getCurrentState() const;
			/*! Sets the localized text that describes the current state. */
			virtual EnumStatusCode setCurrentState(const ILocalizedText* currentState);
			/*! @overload */
			virtual EnumStatusCode setCurrentState(const ILocalizedText& currentState);

			/*! Returns the "LastTransition" property that stores the last transition
			* that occurred in the state machine. */
			ObjectPointer<Server::TransitionVariable> getLastTransitionVar();
			/*! @overload */
			ObjectPointer<const Server::TransitionVariable> getLastTransitionVar() const;

			/*! Returns the localized text that describes the last transition that
			* occurred in the state machine.
			*
			* @note	Please use TransitionVariable::getId() to retrieve a unique
			*		identifier for the last transition. */
			LocalizedText getLastTransition() const;
			/*! Sets the localized text that describes the last transition that
			* occurred in the state machine. */
			virtual EnumStatusCode setLastTransition(const ILocalizedText* lastTransition);
			/*! @overload */
			virtual EnumStatusCode setLastTransition(const ILocalizedText& lastTransition);

			/*! Returns the state of the state machine.
			*
			* @param browseName the browse name of the state object
			*
			* @note The returned state is usually the object defined at the state machine type.
			* Do not remove states from the type definition! */
			Server::StatePtr getState(const QualifiedName& browseName);

			/*! Returns the transition of the state machine.
			*
			* @param browseName the browse name of the transition object
			*
			* @note The returned transition is usually the object defined at the state machine type.
			* Do not remove transition from the type definition! */
			Server::TransitionPtr getTransition(const QualifiedName& browseName);

		private:
			/*! Forbid use assignment operator */
			StateMachine& operator=(const StateMachine&);
			/*! Forbid use of copy constructor */
			StateMachine(const StateMachine&);
		};
		typedef ObjectPointer<StateMachine> StateMachinePtr;
		typedef ObjectPointer<const StateMachine> StateMachineConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERSTATEMACHINE_H
