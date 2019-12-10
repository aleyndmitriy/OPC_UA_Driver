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

#ifndef SERVEROFFNORMALALARM_H
#define SERVEROFFNORMALALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerDiscreteAlarm.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! An OffNormal alarm is a specialization of a DiscreteAlarm intended to represent a
		* discrete condition that is considered to be not normal.
		*
		* An OffNormal alarm is becoming active when the value of the alarm's input variable is different
		* from some "normal" value. The input variable of an alarm is configured by setting the
		* 'InputNode' property of the alarm (see AlarmCondition::setInputNode()) and adding a 'HasCondition'
		* between the input variable and the alarm. The "normal" value is held by another variable
		* which can be assigned to the alarm by setNormalState(). */
		class TBC_EXPORT OffNormalAlarm
			: public DiscreteAlarm
		{
		public:
			/*! Constructs a new OffNormalAlarm instance */
			static ObjectPointer<OffNormalAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			OffNormalAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			OffNormalAlarm();
			/*! For internal use only */
			OffNormalAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~OffNormalAlarm();

			/*! Returns the "NormalState" variable.
			*
			* @see getNormalState() */
			ObjectPointer<Server::Variable> getNormalStateVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getNormalStateVar() const;

			/*! Returns the NodeId of the variable that holds the "normal" value.
			* When the "normal" value does not match the value of the input variable,
			* the alarm becomes active. */
			NodeId getNormalState() const;
			/*! Sets the NodeId of the variable that holds the "normal" value.
			* When the "normal" value does not match the value of the input variable,
			* the alarm becomes active. */
			virtual EnumStatusCode setNormalState(const INodeId* normalState);
			/*! @overload */
			virtual EnumStatusCode setNormalState(const INodeId& normalState);

			/*! Callback method that is called whenever the input variable changes its value.
			*
			* Please note that the input variable needs to have a 'HasCondition' reference
			* that points to this alarm in order to trigger this callback method.
			*
			* An application should override this method to match its own requirements.
			* The method needs to be overridden, for example, if
			* @li alarms are generated in an underlying system or
			* @li alarms use condition branches
			*
			* @param var	The variable which has changed
			* @param value	The new value of that variable
			*
			* @see Condition::onVariableChanged() */
			virtual void onVariableChanged(Server::Variable* var, const IDataValue* value);

			/*! Creates a new branch (copy) of this condition. The branch is made available after construction
			* by calling Condition::addBranch().
			*
			* The caller must provide a valid pointer to an "empty" branch (instance of a condition (sub-)type).
			* Override this method to add custom components (Objects, Variables, Methods) to your branch instance.
			* Default implementations populate the branch with all components of a condition (sub-)type
			* except for state machines. */
			virtual EnumStatusCode createBranch(Server::Condition* branchToConstruct);

		private:
			/*! Forbid use assignment operator */
			OffNormalAlarm& operator=(const OffNormalAlarm&);
			/*! Forbid use of copy constructor */
			OffNormalAlarm(const OffNormalAlarm&);
		};
		typedef ObjectPointer<OffNormalAlarm> OffNormalAlarmPtr;
		typedef ObjectPointer<const OffNormalAlarm> OffNormalAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVEROFFNORMALALARM_H
