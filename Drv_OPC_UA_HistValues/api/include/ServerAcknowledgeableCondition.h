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

#ifndef SERVERACKNOWLEDGEABLECONDITION_H
#define SERVERACKNOWLEDGEABLECONDITION_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerCondition.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class TwoStateVariable;
		class AcknowledgeableConditionAcknowledge;
		class AcknowledgeableConditionConfirm;
	}

	namespace Server
	{
		/*! @brief	AcknowledgeableCondition expose states to indicate whether a Condition has to be
		*			acknowledged or confirmed.
		*
		* The enabled state is extended by adding the AckedState and (optionally) the ConfirmedState.
		*
		* Acknowledgment of the transition may come from the client or may be due to some logic
		* internal to the server. For example, acknowledgment of a related Condition may result in this
		* Condition becoming acknowledged, or the Condition may be set up to automatically acknowledge
		* itself when the acknowledgeable situation disappears.
		*
		* If acknowledgement or confirmation comes from client, the appropriate method is called by client.
		* Handling on this acknowledgement and confirmation can be implemented in AcknowledgeableConditionAcknowledge
		* and AcknowledgeableConditionConfirm. */
		class TBC_EXPORT AcknowledgeableCondition
			: public Condition
		{
		public:
			/*! Constructs a new AcknowledgeableCondition instance */
			static ObjectPointer<AcknowledgeableCondition> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AcknowledgeableCondition(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			AcknowledgeableCondition();
			/*! For internal use only */
			AcknowledgeableCondition(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~AcknowledgeableCondition();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class AcknowledgeableCondition
			/////////////////////////////////////////////////////////////////////////

			/*! Callback that is called after a client has acknowledged the Condition.
			* The default implementation reports the (modified) Condition state to subscribed clients. */
			virtual void onAcknowledge();

			/*! Callback that is called after a client has confirmed the Condition.
			* The default implementation reports the (modified) Condition state to subscribed clients. */
			virtual void onConfirm();

			/*! Creates a new branch (copy) of this condition. The branch is made available after construction
			* by calling Condition::addBranch().
			*
			* The caller must provide a valid pointer to an "empty" branch (instance of a condition (sub-)type).
			* Override this method to add custom components (Objects, Variables, Methods) to your branch instance.
			* Default implementations populate the branch with all components of a condition (sub-)type
			* except for state machines. */
			virtual EnumStatusCode createBranch(Server::Condition* branchToConstruct);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class AcknowledgeableCondition
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the Variable that contains the acknowledgement state of the Condition. */
			ObjectPointer<Server::TwoStateVariable> getAckedStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getAckedStateVar() const;

			/*! Returns the localized text that describes the current acknowledgement state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		acknowledgement state (see AcknowledgeableCondition::getAckedStateVar()).
			*		The localized texts that describe the 'true' and 'false' acknowledgement state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getAckedState() const;

			/*! Returns the Variable that contains the confirmation state of the Condition. */
			ObjectPointer<Server::TwoStateVariable> getConfirmedStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getConfirmedStateVar() const;

			/*! Returns the localized text that describes the current confirmation state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		confirmation state (see AcknowledgeableCondition::getConfirmedStateVar()).
			*		The localized texts that describe the 'true' and 'false' confirmation state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getConfirmedState() const;

			/*! Returns the "Acknowledge" method of this Condition that may be used by clients
			* to acknowledge the condition state. */
			ObjectPointer<Server::AcknowledgeableConditionAcknowledge> getAcknowledge();
			/*! @overload */
			ObjectPointer<const Server::AcknowledgeableConditionAcknowledge> getAcknowledge() const;

			/*! Returns the "Confirm" method of this Condition that may be used by clients
			* to confirm the condition state. */
			ObjectPointer<Server::AcknowledgeableConditionConfirm> getConfirm();
			/*! @overload */
			ObjectPointer<const Server::AcknowledgeableConditionConfirm> getConfirm() const;

		private:
			/*! Forbid use assignment operator */
			AcknowledgeableCondition& operator=(const AcknowledgeableCondition&);
			/*! Forbid use of copy constructor */
			AcknowledgeableCondition(const AcknowledgeableCondition&);
		};
		typedef ObjectPointer<AcknowledgeableCondition> AcknowledgeableConditionPtr;
		typedef ObjectPointer<const AcknowledgeableCondition> AcknowledgeableConditionConstPtr;
	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERACKNOWLEDGEABLECONDITION_H
