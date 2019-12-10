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

#ifndef SERVERCONDITIONVARIABLE_H
#define SERVERCONDITIONVARIABLE_H
#if TB5_ALARMS
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
		/*! A ConditionVariable is used within a Condition to store information whose
		* change needs to be announced to clients. An event notification shall be triggered
		* for the Condition Whenever the 'value' attribute of this variable changes.
		* The 'SourceTimestamp' property of the variable indicates the time of the last
		* change of the value. */
		class TBC_EXPORT ConditionVariable
			: public Variable
		{
		public:
			/*! Constructs a new ConditionVariable instance */
			static ObjectPointer<ConditionVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ConditionVariable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ConditionVariable();
			/*! For internal use only */
			ConditionVariable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ConditionVariable();

			/*! Returns the 'SourceTimestamp' property that holds the time of the
			* last change of the variable's value. */
			ObjectPointer<Server::Variable> getSourceTimestampVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getSourceTimestampVar() const;

			/*! Returns the value of the 'SourceTimestamp' property.
			*
			* This property indicates the time of the last change of the value attribute of this ConditionVariable.
			* It shall be the same time that would be returned from the Read service inside the DataValue structure
			* for the ConditionVariable value attribute. */
			DateTime getSourceTimestamp() const;
			/*! Sets the value of the 'SourceTimestamp' property.
			*
			* @see getSourceTimestamp() */
			virtual EnumStatusCode setSourceTimestamp(const IDateTime* sourceTimestamp);
			/*! @overload */
			virtual EnumStatusCode setSourceTimestamp(const IDateTime& sourceTimestamp);

		private:
			/*! Forbid use assignment operator */
			ConditionVariable& operator=(const ConditionVariable&);
			/*! Forbid use of copy constructor */
			ConditionVariable(const ConditionVariable&);
		};
		typedef ObjectPointer<ConditionVariable> ConditionVariablePtr;
		typedef ObjectPointer<const ConditionVariable> ConditionVariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERCONDITIONVARIABLE_H
