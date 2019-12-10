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

#ifndef SERVERTWOSTATEVARIABLE_H
#define SERVERTWOSTATEVARIABLE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerStateVariable.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! The TwoStateVariable defines a two-state state machine with the states 'true' and 'false'.
		*
		* The TwoStateVariable has the following properties:
		* @li Id:									Holds the current state of the state machine
		* @li TransitionTime:						Specifies the time when the current state was entered
		* @li EffectiveTransitionTime (optional):	Specifies the time when the current state or one of its sub-states was entered
		* @li TrueState:							Contains the localized string that is copied to the value attribute of the
		*											TwoStateVariable when the 'true' state is entered.
		* @li FalseState:							Contains the localized string that is copied to the value attribute of the
		*											TwoStateVariable when the 'false' state is entered. */
		class TBC_EXPORT TwoStateVariable
			: public StateVariable
		{
		public:
			/*! Constructs a new TwoStateVariable instance */
			static ObjectPointer<TwoStateVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TwoStateVariable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			TwoStateVariable();
			/*! For internal use only */
			TwoStateVariable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~TwoStateVariable();

			/*! Returns the current state ('true' or 'false') of the state machine. */
			bool getCurrentState() const;
			/*! Updates the current state of the state machine.
			*
			* This method updates the 'Id' property and copies the localized string
			* from either the 'TrueState' or the 'FalseState' property to the value attribute of the variable. */
			EnumStatusCode setCurrentState(bool newState);

			/*! Activates the state machine. */
			EnumStatusCode activate();
			/*! Returns whether the state machine is active. */
			bool isActive() const;
			/*! Deactivates the state machine. When the state machine is deactivated,
			* the variable's value will be assigned a bad quality (EnumStatusCode_BadStateNotActive). */
			EnumStatusCode deactivate();

			/*! Returns the property that contains the current state of the state machine.
			*
			* @note Please use setCurrentState() to update the current state. */
			ObjectPointer<Server::Variable> getIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getIdVar() const;

			/*! Returns the current state of the state machine.
			*
			* @note This function is identical to TwoStateVariable::getCurrentState().
			*
			* @see setId() */
			bool getId() const;
			/*! Updates the current state of the state machine.
			*
			* @note	This method does only update the 'Id' property of the variable.
			*		Please use setCurrentState() to update the current state. */
			virtual EnumStatusCode setId(bool id);

			/*! Returns the property that specifies the time when the current state was entered.
			*
			* @see setTransitionTime() getTransitionTime() */
			ObjectPointer<Server::Variable> getTransitionTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getTransitionTimeVar() const;

			/*! Returns the time when the current state was entered.
			*
			* @see setTransitionTime() */
			DateTime getTransitionTime() const;
			/*! Sets the time when the current state was entered.
			*
			* @see setEffectiveTransitionTime() */
			virtual EnumStatusCode setTransitionTime(const IDateTime* transitionTime);
			/*! @overload */
			virtual EnumStatusCode setTransitionTime(const IDateTime& transitionTime);

			/*! Returns the property that specifies the time when the current state or one of its sub-states was entered.
			*
			* @see getEffectiveTransitionTime() setEffectiveTransitionTime() */
			ObjectPointer<Server::Variable> getEffectiveTransitionTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getEffectiveTransitionTimeVar() const;

			/*! Returns the time when the current state or one of its sub-states was entered.
			*
			* @see setEffectiveTransitionTime() */
			DateTime getEffectiveTransitionTime() const;
			/*! Sets the time when the current state or one of its sub-states was entered.
			*
			* @see setTransitionTime() */
			virtual EnumStatusCode setEffectiveTransitionTime(const IDateTime* effectiveTransitionTime);
			/*! @overload */
			virtual EnumStatusCode setEffectiveTransitionTime(const IDateTime& effectiveTransitionTime);

			/*! Returns the property that contains the localized string which will be set when the current state
			* is set to 'true'. This variable can be used to get or set the LocalizedText for the 'true' state.
			*
			* @see getTrueState() setTrueState() */
			ObjectPointer<Server::Variable> getTrueStateVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getTrueStateVar() const;

			/*! Returns the localized string which will be set when the current state is set to 'true'.
			*
			* @see setTrueState() */
			LocalizedText getTrueState() const;
			/*! Sets the localized string which will be set when the current state is set to 'true'. */
			virtual EnumStatusCode setTrueState(const ILocalizedText* trueState);
			/*! @overload */
			virtual EnumStatusCode setTrueState(const ILocalizedText& trueState);

			/*! Returns the property that contains the localized string which will be set when the current state
			* is set to 'false'. This variable can be used to get or set the LocalizedText for the 'false' state.
			*
			* @see getFalseState() setFalseState() */
			ObjectPointer<Server::Variable> getFalseStateVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getFalseStateVar() const;

			/*! Returns the localized string which will be set when the current state is set to 'false'.
			*
			* @see setFalseState() */
			LocalizedText getFalseState() const;
			/*! Sets the localized string which will be set when the current state is set to 'false'. */
			virtual EnumStatusCode setFalseState(const ILocalizedText* falseState);
			/*! @overload */
			virtual EnumStatusCode setFalseState(const ILocalizedText& falseState);

#ifdef SOOS_POSIX
		private: // suppress the diab warnings...
			virtual EnumStatusCode setId(const IValue* id) { return StateVariable::setId(id); }
			virtual EnumStatusCode setId(const IValue& id) { return StateVariable::setId(id); }
#endif
		private:
			/*! Forbid use assignment operator */
			TwoStateVariable& operator=(const TwoStateVariable&);
			/*! Forbid use of copy constructor */
			TwoStateVariable(const TwoStateVariable&);
		};
		typedef ObjectPointer<TwoStateVariable> TwoStateVariablePtr;
		typedef ObjectPointer<const TwoStateVariable> TwoStateVariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTWOSTATEVARIABLE_H
