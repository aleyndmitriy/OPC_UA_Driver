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

#ifndef SERVERALARMCONDITION_H
#define SERVERALARMCONDITION_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerAcknowledgeableCondition.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class TwoStateVariable;
		class Variable;
		class ShelvedStateMachine;
	}

	namespace Server
	{
		/*! The AlarmCondition is an abstract type that extends the AcknowledgeableCondition by
		* introducing an ActiveState, SuppressedState and ShelvingState.
		*
		* SuppressedState (TwoStateVariable), ShelvingState (ShelvedStateMachine) and MaxTimeShelved (Variable) are optional components / properties.
		* Nevertheless these optional components / properties are initially created using the init() method of this or derived classes.
		* If the server application does not want these components, it can remove them after calling init(). */
		class TBC_EXPORT AlarmCondition
			: public AcknowledgeableCondition
		{
		public:
			/*! Constructs a new AlarmCondition instance */
			static ObjectPointer<AlarmCondition> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AlarmCondition(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			AlarmCondition();
			/*! For internal use only */
			AlarmCondition(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~AlarmCondition();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class AlarmCondition
			/////////////////////////////////////////////////////////////////////////

			/*! Callback that will be called in case that the alarm is enabled.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onEnable();

			/*! Callback that will be called in case that the alarm is disabled.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onDisable();

			/*! Callback that will be called in case that the alarm changes to an active state.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onActivate();

			/*! Callback that will be called in case that the alarm changes to the inactive state.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onDeactivate();

			/*! Callback that will be called in case that the alarm is acknowledged.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onAcknowledge();

			/*! Callback that will be called in case that the alarm is confirmed.
			*
			* An application can override this callback in order to get this notification.
			* However in this default implementation there is code which handles states of
			* acknowledgement, confirmation, retained flag and shelving state machine.
			* Additionally notification reporting to client is triggered here.
			*
			* In case of overwritten callback either the default implementation shall be called or appropriate parts
			* needs to be implemented in overwritten method. */
			virtual void onConfirm();

			/*! Sets the suppressed state of the alarm.
			*
			* SuppressState is used internally by a server to automatically suppress alarms due to system
			* specific reasons. For example a system may be configured to suppress alarms that are
			* associated with machinery that is being shutdown, such as a low level alarm for a tank
			* that is currently not in use. In this case some of the alarms can be suppressed to avoid flooding
			* of UA clients.
			*
			* @note This method does also update the "SuppressedOrShelved" flag of the alarm. */
			EnumStatusCode suppress(bool suppressed);

			/*! Reports the current state of the alarm to clients subscribed for notifications.
			*
			* The notification will be sent regardless of the suppressed or shelved state.
			* If a notification shall not be sent due to the SuppressedOrShelved flag use
			* AlarmCondition::getSuppressedOrShelved() before calling this method.
			*
			* The notification will be sent on the source node (see BaseEvent::setSourceNode()) of the alarm.
			* If the source node property is not specified, the source node is set to the node that points with
			* a "HasCondition" reference to the alarm. If the event type is not yet specified, the call sets the
			* event type to the node ID of the correct type node. */
			virtual EnumStatusCode report(const INodeId* reportingNode);

			/*! Creates a new branch (copy) of this condition. The branch is made available after construction
			* by calling Condition::addBranch().
			*
			* The caller must provide a valid pointer to an "empty" branch (instance of a condition (sub-)type).
			* Override this method to add custom components (Objects, Variables, Methods) to your branch instance.
			* Default implementations populate the branch with all components of a condition (sub-)type
			* except for state machines. */
			virtual EnumStatusCode createBranch(Server::Condition* branchToConstruct);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class AlarmCondition
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the variable holding the "Active" state of the alarm.
			*
			* When active (i.e. TwoStateVariable::getCurrentState() returns true), it indicates that the
			* situation the alarm is representing currently exists. When an alarm instance is in the inactive
			* state (i.e. TwoStateVariable::getCurrentState() returns false) it is representing a situation
			* that has returned to a normal state.
			*
			* The transitions of the active state are triggered by server specific actions.
			* The handling of the active state depends on specialized alarms like Server::ExclusiveLimitAlarm
			* or Server::OffNormalAlarm. */
			ObjectPointer<Server::TwoStateVariable> getActiveStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getActiveStateVar() const;

			/*! Returns the localized text that describes the current active state.
			* @note Please use TwoStateVariable::getCurrentState() to retrieve the current
			*       active state (see AlarmCondition::getActiveStateVar()).
			*       The localized texts that describe the 'true' and 'false' active state
			*       can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getActiveState() const;

			/*! Returns whether the alarm is currently suppressed or shelved.
			*
			* The SuppressedState and the ShelvingState together result in the SuppressedOrShelved status
			* of the alarm. When an alarm is either suppressed (by the UA server) or shelved (by a UA client),
			* the SuppressedOrShelved property is set true. This allows client to filter suppressed or shelved
			* alarms. */
			bool getSuppressedOrShelved() const;

			/*! Returns the variable holding the "SuppressedOrShelved" property.
			*
			* Please note that writing directly to the suppressed or shelved states of the alarm will not update SuppressedOrShelved
			* attribute. Instead please use the helper functions which are provided to update the states of the alarms
			* as these will also update the SuppressedOrShelved flag. */
			ObjectPointer<Server::Variable> getSuppressedOrShelvedVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getSuppressedOrShelvedVar() const;

			/*! Returns the variable holding the "Suppressed" state.
			* In order to modify the suppressed state, please use AlarmCondition::suppress().
			*
			* @see suppress() */
			ObjectPointer<Server::TwoStateVariable> getSuppressedStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getSuppressedStateVar() const;

			/*! Returns the localized text that describes the current suppression state.
			* @note Please use AlarmCondition::suppress() to change the current suppression state.
			*       The localized texts that describe the 'true' and 'false' suppression state
			*       can be retrieved by getSuppressedStateVar()->getTrueState() and getSuppressedStateVar()->getFalseState(). */
			LocalizedText getSuppressedState() const;

			/*! Returns the variable holding the "MaxTimeShelved" property.
			*
			* Consider using AlarmCondition::getMaxTimeShelved() to retrieve the actual
			* value of the MaxTimeShelved variable.
			*
			* @see AlarmCondition::getMaxTimeShelved() */
			ObjectPointer<Server::Variable> getMaxTimeShelvedVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getMaxTimeShelvedVar() const;

			/*! Returns the maximum time (in milliseconds) the alarm may be shelved by a client.
			*
			* @see setMaxTimeShelved() */
			double getMaxTimeShelved() const;
			/*! Sets the maximum time (in milliseconds) the alarm may be shelved by a client.
			*
			* OPC UA servers may use this property to prevent permanent shelving of an alarm.
			* Shelved alarms are automatically unshelved when this time expires. */
			virtual EnumStatusCode setMaxTimeShelved(double maxTimeShelved);

			/*! Returns the shelving state machine object.
			*
			* The shelving state machine is an optional component of an alarm.
			* Using this state machine a client can prevent the server from further notification of status changes.
			*
			* See Server::ShelvedStateMachine for exact definition of the shelving state machine. */
			ObjectPointer<Server::ShelvedStateMachine> getShelvingState();
			/*! @overload */
			ObjectPointer<const Server::ShelvedStateMachine> getShelvingState() const;

			/*! Returns the "InputNode" property that contains the NodeId of the InputNode.
			*
			* @see setInputNode() */
			ObjectPointer<Server::Variable> getInputNodeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getInputNodeVar() const;

			/*! Returns the NodeId of the InputNode that is used as primary input in the
			* calculation of the alarm state.
			*
			* @see setInputNode() */
			NodeId getInputNode() const;
			/*! Sets the NodeId of the InputNode.
			*
			* The InputNode property provides the NodeId of the variable the value of which is used as
			* primary input in the calculation of the alarm state. If this variable is not in the AddressSpace, a
			* "null" NodeId shall be provided.
			*
			* @note		The InputNode must match the source node of the alarm and must point to the alarm
			*			with a "HasCondition" reference. */
			virtual EnumStatusCode setInputNode(const INodeId* inputNode);
			/*! @overload */
			virtual EnumStatusCode setInputNode(const INodeId& inputNode);

		private:
			/*! Forbid use assignment operator */
			AlarmCondition& operator=(const AlarmCondition&);
			/*! Forbid use of copy constructor */
			AlarmCondition(const AlarmCondition&);
		};
		typedef ObjectPointer<AlarmCondition> AlarmConditionPtr;
		typedef ObjectPointer<const AlarmCondition> AlarmConditionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERALARMCONDITION_H
