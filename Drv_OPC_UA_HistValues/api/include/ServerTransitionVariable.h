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

#ifndef SERVERTRANSITIONVARIABLE_H
#define SERVERTRANSITIONVARIABLE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerVariable.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! The TransitionVariable is the base class for variables that store a transition that
		* occurred within a state machine as a human readable name.
		*
		* @see StateMachine */
		class TBC_EXPORT TransitionVariable
			: public Variable
		{
		public:
			/*! Constructs a new TransitionVariable instance */
			static ObjectPointer<TransitionVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TransitionVariable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			TransitionVariable();
			/*! For internal use only */
			TransitionVariable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~TransitionVariable();

			/*! Resets the components of this variable.
			*
			* This method resets
			* @li the Id property to a NULL value
			* @li the Name property to an empty string
			* @li the Number property to 0
			* @li the TransitionTime property to 1601-01-01 12:00AM */
			EnumStatusCode reset();

			/*! Returns the 'Id' property that uniquely identifies the transition within a state machine.
			*
			* @see getId() setId() */
			ObjectPointer<Server::Variable> getIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getIdVar() const;

			/*! Returns a Value that uniquely identifies the transition within a state machine. */
			Value getId() const;
			/*! Sets the Value that uniquely identifies the transition within a state machine. */
			virtual EnumStatusCode setId(const IValue* id);
			/*! @overload */
			virtual EnumStatusCode setId(const IValue& id);

			/*! Returns the 'Name' property that uniquely identifies the transition within a state machine.
			*
			* @see getName() setName() */
			ObjectPointer<Server::Variable> getNameVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getNameVar() const;

			/*! Returns a QualifiedName that uniquely identifies the transition within a state machine. */
			QualifiedName getName() const;
			/*! Sets the QualifiedName that uniquely identifies the transition within a state machine. */
			virtual EnumStatusCode setName(const IQualifiedName* name);
			/*! @overload */
			virtual EnumStatusCode setName(const IQualifiedName& name);

			/*! Returns the 'Number' property that uniquely identifies the transition within a state machine.
			*
			* @see getNumber() setNumber() */
			ObjectPointer<Server::Variable> getNumberVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getNumberVar() const;

			/*! Returns a number that uniquely identifies the transition within a state machine. */
			OTUInt32 getNumber() const;
			/*! Sets the number that uniquely identifies the transition within a state machine. */
			virtual EnumStatusCode setNumber(OTUInt32 number);

			/*! Returns the 'TransitionTime' property that specifies when the transition occurred.
			*
			* @see getTransitionTime() setTransitionTime() */
			ObjectPointer<Server::Variable> getTransitionTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getTransitionTimeVar() const;

			/*! Returns the time when the transition occurred. */
			DateTime getTransitionTime() const;
			/*! Sets the time when the transition occurred. */
			virtual EnumStatusCode setTransitionTime(const IDateTime* transitionTime);
			/*! @overload */
			virtual EnumStatusCode setTransitionTime(const IDateTime& transitionTime);

		private:
			/*! Forbid use assignment operator */
			TransitionVariable& operator=(const TransitionVariable&);
			/*! Forbid use of copy constructor */
			TransitionVariable(const TransitionVariable&);
		};
		typedef ObjectPointer<TransitionVariable> TransitionVariablePtr;
		typedef ObjectPointer<const TransitionVariable> TransitionVariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTRANSITIONVARIABLE_H
