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

#ifndef SERVERTRANSITION_H
#define SERVERTRANSITION_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! The Transition class represents a transition of a state machine in the address space of a server.
		*
		* @see FiniteStateMachine */
		class TBC_EXPORT Transition
			: public Object
		{
		public:
			/*! Constructs a new Transition instance */
			static ObjectPointer<Transition> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Transition(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			Transition();
			/*! For internal use only */
			Transition(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Transition();

			/*! Returns the 'TransitionNumber' property that uniquely identifies the transition within a state machine.
			*
			* @note	Please note that both the BrowseName of the Transition and the value of this property must be unique
			*		within a state machine.
			*
			* @see getTransitionNumber() setTransitionNumber() */
			ObjectPointer<Server::Variable> getTransitionNumberVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getTransitionNumberVar() const;

			/*! Returns a number that uniquely identifies the transition within a state machine.
			*
			* @see setTransitionNumber() */
			OTUInt32 getTransitionNumber() const;
			/*! Sets the number that uniquely identifies the transition within a state machine.
			*
			* @note	Please note that both the BrowseName of the Transition and the transition number must be unique
			*		within a state machine. */
			virtual EnumStatusCode setTransitionNumber(OTUInt32 transitionNumber);

		private:
			/*! Forbid use assignment operator */
			Transition& operator=(const Transition&);
			/*! Forbid use of copy constructor */
			Transition(const Transition&);

		};
		typedef ObjectPointer<Transition> TransitionPtr;
		typedef ObjectPointer<const Transition> TransitionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTRANSITION_H
