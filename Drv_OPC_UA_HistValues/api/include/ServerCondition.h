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

#ifndef SERVERCONDITION_H
#define SERVERCONDITION_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "ServerBaseEvent.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class TwoStateVariable;
		class Variable;
		class ConditionVariable;
		class ConditionEnable;
		class ConditionDisable;
		class ConditionRefresh;
		class ConditionAddComment;
		typedef ObjectPointer<BaseNode> BaseNodePtr;
		class Condition;
		typedef ObjectPointer<Condition> ConditionPtr;
	}

	namespace Server
	{
		/*! Base class for all Alarm and Condition instances. */
		class TBC_EXPORT Condition
			: public BaseEvent
		{
		public:
			/*! Constructs a new Condition instance */
			static ObjectPointer<Condition> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Condition(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			Condition();
			/*! For internal use only */
			Condition(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Condition();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class Condition
			/////////////////////////////////////////////////////////////////////////

			/*! Callback method that shall be executed when the condition is enabled by the 'Enable' method. */
			virtual void onEnable();

			/*! Callback method that shall be executed when the condition is disabled by the 'Disable' method. */
			virtual void onDisable();

			/*! Enables the condition by setting the state of the EnabledState to true.
			*
			* @note This will automatically update all the sub-states of the EnabledState component. */
			EnumStatusCode enable();

			/*! Disables the condition by setting the state of the EnabledState to false.
			*
			* @note This will automatically update all the sub-states of the EnabledState component. */
			EnumStatusCode disable();

			/*! Creates a new branch (copy) of this condition. The branch is made available after construction
			* by calling Condition::addBranch().
			*
			* The caller must provide a valid pointer to an "empty" branch (instance of a condition (sub-)type).
			* Override this method to add custom components (Objects, Variables, Methods) to your branch instance.
			* Default implementations populate the branch with all components of a condition (sub-)type
			* except for state machines. */
			virtual EnumStatusCode createBranch(Server::Condition* branchToConstruct);

			/*! Adds a branch to this condition. This will create and assign a new BranchId to the
			* provided branch which uniquely identifies the branch within this condition.
			*
			* @param conditionBranch	The condition branch to add
			* @param branchId			The BranchId of the added branch
			*
			* @see createBranch() */
			EnumStatusCode addBranch(Server::ConditionPtr conditionBranch, NodeId& branchId);
			/*! @overload
			*
			* @param conditionBranch	The condition branch to add
			* @param reportAddedBranch	Denotes whether the added branch is reported to clients.
			* @param branchId			The BranchId of the added branch */
			EnumStatusCode addBranch(Server::ConditionPtr conditionBranch, bool reportAddedBranch, NodeId& branchId);

			/*! Returns an existing condition branch identified by the given branch id.
			*
			* @param branchId				The identifier of the branch to return
			* @param[out] conditionBranch	The condition branch */
			EnumStatusCode getBranch(const INodeId* branchId, ObjectPointer<Server::Condition>& conditionBranch);
			/*! @overload */
			EnumStatusCode getBranch(const INodeId* branchId, ObjectPointer<const Server::Condition>& conditionBranch) const;

			/*! Returns all branches of this condition. */
			EnumStatusCode getBranches(std::vector<NodeId>& conditionBranches) const;

			/*! Deletes a branch of this condition.
			*
			* @param branchId				The identifier of the branch to delete
			*
			* If the branch has set its retain flag to true (see setRetain()), it is set to
			* false and an event is reported for the branch. */
			virtual EnumStatusCode deleteBranch(const INodeId* branchId);
			/*! @overload
			*
			* @param branchId				The identifier of the branch to delete.
			* @param reportDeletedBranch	Denotes whether the deleted branch is reported to clients. */
			EnumStatusCode deleteBranch(const INodeId* branchId, bool reportDeletedBranch);

			/*! This method returns the trunk of the condition.
			*
			* If the object on which getTrunk() is called is a branch of the condition,
			* the condition trunk is returned. If the object is the trunk itself,
			* this method returns 'this'.
			*
			* @param[out] trunk	The trunk of the condition */
			EnumStatusCode getTrunk(ObjectPointer<Server::Condition>& trunk);
			/*! @overload */
			EnumStatusCode getTrunk(ObjectPointer<const Server::Condition>& trunk) const;

			/*! Callback method that is called whenever the input variable changes its value.
			*
			* Please note that the input variable needs to have a 'HasCondition' reference
			* that points to this alarm in order to trigger this callback method.
			* The callback allows the condition instance to react on a
			* value change of the input variable by evaluating its states and if required by sending an event.
			* Both evaluation and resulting actions are dependent on the concrete condition types.
			*
			* The implementation of this abstract class sets the Quality property of the condition to the status
			* of the @p value.
			*
			* @param var	The variable which has changed
			* @param value	The new value of that variable */
			virtual void onVariableChanged(Server::Variable* var, const IDataValue* value);

			/*! Reports the current state of the condition to clients subscribed for notifications.
			*
			* The notification will be sent on the source node (see BaseEvent::setSourceNode()) of the alarm.
			* If the source node property is not specified, the source node is set to the node that points with
			* a "HasCondition" reference to the condition. If the event type is not yet specified, the call sets the
			* event type to the node ID of the correct type node. */
			virtual EnumStatusCode report(const INodeId* reportingNode);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Condition
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the TwoStateVariable that indicates whether the condition is enabled or disabled. */
			ObjectPointer<Server::TwoStateVariable> getEnabledStateVar();
			/*! @overload */
			ObjectPointer<const Server::TwoStateVariable> getEnabledStateVar() const;

			/*! Returns the localized text that describes the current enabled state.
			*
			* @note	Please use TwoStateVariable::getCurrentState() to retrieve the current
			*		enabled state (see Condition::getEnabledStateVar()).
			*		The localized texts that describe the 'true' and 'false' enabled state
			*		can be retrieved by TwoStateVariable::getTrueState() and TwoStateVariable::getFalseState(). */
			LocalizedText getEnabledState() const;

			/*! Returns the BranchId variable.
			*
			* @see getBranchId() */
			ObjectPointer<Server::Variable> getBranchIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getBranchIdVar() const;

			/*! Returns the BranchId that is used to distinguish several branches of the same condition instance.
			*
			* @see setBrachId() */
			NodeId getBranchId() const;
			/*! Sets the BranchId that is used to distinguish several branches of the same condition instance.
			*
			* The BranchId is null (i.e. the null NodeId) for all event notifications that relate to the current state
			* of the condition instance. If the BranchId is not null, it identifies a previous state of this condition
			* instance that still needs attention by an operator.
			*
			* @note	A BranchId is automatically generated and assigned to branches during addBranch(). Server applications
			*		do not need to set the BranchId manually. */
			virtual EnumStatusCode setBranchId(const INodeId* branchId);
			/*! @overload */
			virtual EnumStatusCode setBranchId(const INodeId& branchId);

			/*! Returns the Retain variable that indicates whether this condition is still interesting
			* to a client that wishes to synchronize its state with the server's state.
			*
			* @see getRetain() setRetain() */
			ObjectPointer<Server::Variable> getRetainVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getRetainVar() const;

			/*! Returns whether this condition is still interesting to a client that wishes
			* to synchronize its state with the server's state. */
			bool getRetain() const;
			/*! Defines whether this condition is still interesting to a client that wishes
			* to synchronize its state with the server's state.
			*
			* When a client wishes to synchronize its state with the server (so called "condition refresh")
			* the server evaluates this flag, and only conditions re-announces only those conditions that
			* have this flag set to 'true'. */
			virtual EnumStatusCode setRetain(bool retain);

			/*! Returns the Quality variable that reveals the status of the process values or other resources
			* that this condition instance is based upon.
			*
			* @see setQuality() getQuality() */
			ObjectPointer<Server::ConditionVariable> getQualityVar();
			/*! @overload */
			ObjectPointer<const Server::ConditionVariable> getQualityVar() const;

			/*! Returns the quality that reveals the status of the process values or other resources that this
			* condition instance is based upon.
			*
			* @see setQuality() */
			EnumStatusCode getQuality() const;
			/*! Sets the quality that reveals the status of the process values or other resources that this
			* condition instance is based upon. If, for example, a process value is 'Uncertain', the associated
			* 'LevelAlarm' condition is also questionable. */
			EnumStatusCode setQuality(EnumStatusCode);

			/*! Returns the LastSeverity variable that indicates the previous severity of the condition.
			*
			* @see setLastSeverity() getLastSeverity() */
			ObjectPointer<Server::ConditionVariable> getLastSeverityVar();
			/*! @overload */
			ObjectPointer<const Server::ConditionVariable> getLastSeverityVar() const;

			/*! Returns the previous severity of the condition.
			*
			* @see setLastSeverity() */
			OTUInt16 getLastSeverity() const;
			/*! Sets the previous severity of the condition.
			*
			* Initially this variable contains a zero value; it will return a value only after the
			* condition's severity has changed.
			*
			* @note The current severity of the condition is set by BaseEvent::setSeverity() */
			virtual EnumStatusCode setLastSeverity(OTUInt16 lastSeverity);

			/*! Returns the Comment variable that contains the latest comment for a certain state of the condition.
			*
			* @see setComment() getComment() */
			ObjectPointer<Server::ConditionVariable> getCommentVar();
			/*! @overload */
			ObjectPointer<const Server::ConditionVariable> getCommentVar() const;

			/*! Returns the latest comment for a certain state of the condition.
			* The comment may have been provided by a client using the AddComment method or by some other Method.
			*
			* @see setComment() */
			LocalizedText getComment() const;
			/*! Sets the latest comment for a certain state of the condition.
			* The comment may have been provided by a client using the AddComment method or by some other Method.
			* Initially, the comment is an empty text.
			*
			* @see	setClientUserId()
			*
			* @note The ClientUserId shall be set to the user who inserted the comment. */
			virtual EnumStatusCode setComment(const ILocalizedText* comment);
			/*! @overload */
			virtual EnumStatusCode setComment(const ILocalizedText& comment);

			/*! Returns the ClientUserId variable that contains the UserId of the client that
			* inserted the most recent comment.
			*
			* @see setClientUserId() getClientUserId() */
			ObjectPointer<Server::Variable> getClientUserIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getClientUserIdVar() const;

			/*! Returns the UserId of the client that inserted the most recent comment.
			*
			* @see setClientUserId() */
			tstring getClientUserId() const;
			/*! Sets the UserId of the client that inserted the most recent comment.
			*
			* The ClientUserId can be obtained from the UserIdentityToken passed in the Endpoint::onAuthenticateUser() callback.
			* This token can contain the information in multiple formats depending on the type of User Identity
			* that is passed to the service. If the UserIdentityToken that was passed was defined as a UserName,
			* then the structure contains an explicit string that is the user. If the passed UserIdentityToken was
			* defined as X509v3, then the CertificateData byte string contains an element that is the user string
			* which can be extracted from the subject key in this structure. If the passed UserIdentityToken was
			* defined as WSS, then the user string can be extracted from the WS-Security XML token.
			* If an AnonymousIdentityToken was used, the value is null. */
			virtual EnumStatusCode setClientUserId(const tstring& clientUserId);

			/*! Returns the ConditionEnable method that may be used by clients to enable a condition. */
			ObjectPointer<Server::ConditionEnable> getEnable();
			/*! @overload */
			ObjectPointer<const Server::ConditionEnable> getEnable() const;

			/*! Returns the ConditionDisable method that may be used by clients to disable a condition. */
			ObjectPointer<Server::ConditionDisable> getDisable();
			/*! @overload */
			ObjectPointer<const Server::ConditionDisable> getDisable() const;

			/*! Returns the ConditionRefresh method that may be used by clients to synchronize its state
			* with the server's state. */
			ObjectPointer<Server::ConditionRefresh> getConditionRefresh();
			/*! @overload */
			ObjectPointer<const Server::ConditionRefresh> getConditionRefresh() const;

			/*! Returns the AddComment method that may be used by clients to add a comment for a condition state. */
			ObjectPointer<Server::ConditionAddComment> getAddComment();
			/*! @overload */
			ObjectPointer<const Server::ConditionAddComment> getAddComment() const;

			/*! Sets the mandatory ConditionName property of a condition.
			*
			* @param conditionName ConditionName identifies the Condition instance that the Event originated from. It can be used together with
			the SourceName in a user display to distinguish between different Condition instances. If a
			ConditionSource has only one instance of a ConditionType, and the Server has no instance name, the Server
			shall supply the ConditionType browse name. */
			EnumStatusCode setConditionName(const tstring &conditionName);
			/*! Gets the mandatory ConditionName property of a condition */
			EnumStatusCode getConditionName(tstring &conditionName) const;

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(std::vector<ObjectPointer<Condition> > m_branches)

			/*! Forbid use assignment operator */
			Condition& operator=(const Condition&);
			/*! Forbid use of copy constructor */
			Condition(const Condition&);
		};
		typedef ObjectPointer<Condition> ConditionPtr;
		typedef ObjectPointer<const Condition> ConditionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERCONDITION_H
