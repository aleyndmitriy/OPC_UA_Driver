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

#ifndef SERVERFINITETRANSITIONVARIABLE_H
#define SERVERFINITETRANSITIONVARIABLE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerTransitionVariable.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! The FiniteTransitionVariable is a subtype of TransitionVariable and is used to store a
		* transition that occurred within a FiniteStateMachine as a human readable name. */
		class TBC_EXPORT FiniteTransitionVariable
			: public TransitionVariable
		{
		public:
			/*! Constructs a new FiniteTransitionVariable instance */
			static ObjectPointer<FiniteTransitionVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			FiniteTransitionVariable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			FiniteTransitionVariable();
			/*! For internal use only */
			FiniteTransitionVariable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~FiniteTransitionVariable();

			/*! Returns the 'Id' property that uniquely identifies the transition within a state machine.
			*
			* @see getId() setId() */
			ObjectPointer<Server::Variable> getIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getIdVar() const;

			/*! Returns the NodeId of the current Transition object. This NodeId uniquely identifies
			* the last transition within the FiniteStateMachine. */
			NodeId getId() const;

#ifdef SOOS_POSIX
		private: // suppress the diab warnings...
			virtual EnumStatusCode setId(const IValue* id) { return TransitionVariable::setId(id); }
			virtual EnumStatusCode setId(const IValue& id) { return TransitionVariable::setId(id); }
#endif
		private:
			/*! Forbid use assignment operator */
			FiniteTransitionVariable& operator=(const FiniteTransitionVariable&);
			/*! Forbid use of copy constructor */
			FiniteTransitionVariable(const FiniteTransitionVariable&);
		};
		typedef ObjectPointer<FiniteTransitionVariable> FiniteTransitionVariablePtr;
		typedef ObjectPointer<const FiniteTransitionVariable> FiniteTransitionVariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERFINITETRANSITIONVARIABLE_H
