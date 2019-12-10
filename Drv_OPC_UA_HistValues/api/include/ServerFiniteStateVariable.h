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

#ifndef SERVERFINITESTATEVARIABLE_H
#define SERVERFINITESTATEVARIABLE_H
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
		/*! The FiniteStateVariable is a subtype of StateVariable and is used to store the current state of
		* a FiniteStateMachine as a human readable name. */
		class TBC_EXPORT FiniteStateVariable
			: public StateVariable
		{
		public:
			/*! Constructs a new FiniteStateVariable instance */
			static ObjectPointer<FiniteStateVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			FiniteStateVariable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			FiniteStateVariable();
			/*! For internal use only */
			FiniteStateVariable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~FiniteStateVariable();

			/*! Returns the 'Id' property that uniquely identifies the state within a state machine.
			*
			* @see getId() setId() */
			ObjectPointer<Server::Variable> getIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getIdVar() const;

			/*! Returns the NodeId of the current State object. This NodeId uniquely identifies
			* the current state within the FiniteStateMachine. */
			NodeId getId() const;
			/*! @deprecated Do not call this method, use FiniteStateMachine::changeState() instead. */
			DEPRECATED(virtual EnumStatusCode setId(const INodeId* id));
			/*! @overload */
			DEPRECATED(virtual EnumStatusCode setId(const INodeId& id));

#ifdef SOOS_POSIX
		private: // suppress the diab warnings...
			virtual EnumStatusCode setId(const IValue* id) { return StateVariable::setId(id); }
			virtual EnumStatusCode setId(const IValue& id) { return StateVariable::setId(id); }
#endif
		private:
			/*! Forbid use assignment operator */
			FiniteStateVariable& operator=(const FiniteStateVariable&);
			/*! Forbid use of copy constructor */
			FiniteStateVariable(const FiniteStateVariable&);
		};
		typedef ObjectPointer<FiniteStateVariable> FiniteStateVariablePtr;
		typedef ObjectPointer<const FiniteStateVariable> FiniteStateVariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERFINITESTATEVARIABLE_H
