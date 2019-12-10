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

#ifndef SERVERSTATE_H
#define SERVERSTATE_H
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
		/*! The State class represents the state of a state machine in the address space of a server.
		*
		* @see FiniteStateMachine */
		class TBC_EXPORT State
			: public Object
		{
		public:
			/*! Constructs a new State instance */
			static ObjectPointer<State> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			State(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			State();
			/*! For internal use only */
			State(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~State();

			/*! Returns the 'StateNumber' property that uniquely identifies the state within a state machine.
			*
			* @note	Please note that both the BrowseName of the State and the value of this property must be unique
			*		within a state machine.
			*
			* @see getStateNumber() setStateNumber() */
			ObjectPointer<Server::Variable> getStateNumberVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getStateNumberVar() const;

			/*! Returns a number that uniquely identifies the state within a state machine. */
			OTUInt32 getStateNumber() const;
			/*! Sets the number that uniquely identifies the state within a state machine.
			*
			* @note	Please note that both the BrowseName of the State and the state number must be unique
			*		within a state machine. */
			virtual EnumStatusCode setStateNumber(OTUInt32 stateNumber);

		private:
			/*! Forbid use assignment operator */
			State& operator=(const State&);
			/*! Forbid use of copy constructor */
			State(const State&);
		};
		typedef ObjectPointer<State> StatePtr;
		typedef ObjectPointer<const State> StateConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERSTATE_H
