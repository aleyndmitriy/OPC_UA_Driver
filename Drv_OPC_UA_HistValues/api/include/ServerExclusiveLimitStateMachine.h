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

#ifndef SERVEREXCLUSIVELIMITSTATEMACHINE_H
#define SERVEREXCLUSIVELIMITSTATEMACHINE_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerFiniteStateMachine.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class State;
		class Transition;
	}

	namespace Server
	{
		/*! The ExclusiveLimitStateMachine class defines the state machine used by alarms that
		* handle multiple mutually exclusive limits.
		*
		* @see Server::ExclusiveLimitAlarm */
		class TBC_EXPORT ExclusiveLimitStateMachine
			: public FiniteStateMachine
		{
		public:
			/*! Constructs a new ExclusiveLimitStateMachine instance */
			static ObjectPointer<ExclusiveLimitStateMachine> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ExclusiveLimitStateMachine(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ExclusiveLimitStateMachine();
			/*! For internal use only */
			ExclusiveLimitStateMachine(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ExclusiveLimitStateMachine();

			/*! Returns the "HighHigh" State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getHighHigh();
			/*! @overload */
			ObjectPointer<const Server::State> getHighHigh() const;

			/*! Returns the "High" State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getHigh();
			/*! @overload */
			ObjectPointer<const Server::State> getHigh() const;

			/*! Returns the "Low" State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getLow();
			/*! @overload */
			ObjectPointer<const Server::State> getLow() const;

			/*! Returns the "LowLow" State node.
			*
			* @note The returned state is the state object defined at the state machine type.
			* Do not remove states from the type definition! */
			ObjectPointer<Server::State> getLowLow();
			/*! @overload */
			ObjectPointer<const Server::State> getLowLow() const;

			/*! Returns the "LowLowToLow" Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getLowLowToLow();
			/*! @overload */
			ObjectPointer<const Server::Transition> getLowLowToLow() const;

			/*! Returns the "LowToLowLow" Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getLowToLowLow();
			/*! @overload */
			ObjectPointer<const Server::Transition> getLowToLowLow() const;

			/*! Returns the "HighHighToHigh" Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getHighHighToHigh();
			/*! @overload */
			ObjectPointer<const Server::Transition> getHighHighToHigh() const;

			/*! Returns the "HighToHighHigh" Transition node.
			*
			* @note The returned transition is the transition object defined at the state machine type.
			* Do not remove transitions from the type definition! */
			ObjectPointer<Server::Transition> getHighToHighHigh();
			/*! @overload */
			ObjectPointer<const Server::Transition> getHighToHighHigh() const;

		private:
			/*! Forbid use assignment operator */
			ExclusiveLimitStateMachine& operator=(const ExclusiveLimitStateMachine&);
			/*! Forbid use of copy constructor */
			ExclusiveLimitStateMachine(const ExclusiveLimitStateMachine&);
		};
		typedef ObjectPointer<ExclusiveLimitStateMachine> ExclusiveLimitStateMachinePtr;
		typedef ObjectPointer<const ExclusiveLimitStateMachine> ExclusiveLimitStateMachineConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVEREXCLUSIVELIMITSTATEMACHINE_H
