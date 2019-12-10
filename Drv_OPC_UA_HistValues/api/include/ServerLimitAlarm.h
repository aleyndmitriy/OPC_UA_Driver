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

#ifndef SERVERLIMITALARM_H
#define SERVERLIMITALARM_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerAlarmCondition.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! The LimitAlarm type is the base alarm type for conditions with multiple limits.
		*
		* The alarm becomes active if the value of the input variable exceeds the given limits.
		* If the value of the input variable does not exceed any limit, the alarm becomes inactive.
		*
		* The input variable of an alarm is configured by setting the 'InputNode' property of the alarm
		* (see AlarmCondition::setInputNode()) and adding a 'HasCondition'
		* between the input variable and the alarm. */
		class TBC_EXPORT LimitAlarm
			: public AlarmCondition
		{
		public:
			/*! Constructs a new LimitAlarm instance */
			static ObjectPointer<LimitAlarm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			LimitAlarm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			LimitAlarm();
			/*! For internal use only */
			LimitAlarm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~LimitAlarm();

			/*! Returns the "HighHighLimit" variable.
			*
			* @see getHighHighLimit() setHighHighLimit() */
			ObjectPointer<Server::Variable> getHighHighLimitVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getHighHighLimitVar() const;

			/*! Returns the value of the HighHighLimit. */
			double getHighHighLimit() const;
			/*! @overload */
			EnumStatusCode getHighHighLimit(double& highHighLimit) const;
			/*! Sets the value of the HighHighLimit. */
			virtual EnumStatusCode setHighHighLimit(double highHighLimit);

			/*! Returns the "HighLimit" variable.
			*
			* @see getHighLimit() setHighLimit() */
			ObjectPointer<Server::Variable> getHighLimitVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getHighLimitVar() const;

			/*! Returns the value of the HighLimit. */
			double getHighLimit() const;
			/*! @overload */
			EnumStatusCode getHighLimit(double& highLimit) const;
			/*! Sets the value of the HighLimit. */
			virtual EnumStatusCode setHighLimit(double highLimit);

			/*! Returns the "LowLowLimit" variable.
			*
			* @see getLowLowLimit() setLowLowLimit() */
			ObjectPointer<Server::Variable> getLowLowLimitVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getLowLowLimitVar() const;

			/*! Returns the value of the LowLowLimit. */
			double getLowLowLimit() const;
			/*! @overload */
			EnumStatusCode getLowLowLimit(double& lowLowLimit) const;
			/*! Sets the value of the LowLowLimit. */
			virtual EnumStatusCode setLowLowLimit(double lowLowLimit);

			/*! Returns the "LowLimit" variable.
			*
			* @see getLowLimit() setLowLimit() */
			ObjectPointer<Server::Variable> getLowLimitVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getLowLimitVar() const;

			/*! Returns the value of the LowLimit. */
			double getLowLimit() const;
			/*! @overload */
			EnumStatusCode getLowLimit(double& lowLimit) const;
			/*! Sets the value of the LowLimit. */
			virtual EnumStatusCode setLowLimit(double lowLimit);

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
			LimitAlarm& operator=(const LimitAlarm&);
			/*! Forbid use of copy constructor */
			LimitAlarm(const LimitAlarm&);
		};
		typedef ObjectPointer<LimitAlarm> LimitAlarmPtr;
		typedef ObjectPointer<const LimitAlarm> LimitAlarmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERLIMITALARM_H
