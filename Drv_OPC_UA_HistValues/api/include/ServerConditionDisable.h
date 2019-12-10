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

#ifndef SERVERCONDITIONDISABLE_H
#define SERVERCONDITIONDISABLE_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerMethod.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class MethodCallTransaction;
		class MethodCallRequest;
	}

	namespace Server
	{
		/*! This class represents the 'Condition' method that clients may call
		* to disable a condition.
		*
		* @see Condition */
		class TBC_EXPORT ConditionDisable
			: public Method
		{
		public:
			/*! Constructs a new ConditionDisable instance */
			static ObjectPointer<ConditionDisable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ConditionDisable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ConditionDisable();
			/*! For internal use only */
			ConditionDisable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ConditionDisable();

			/*! Callback method that is called whenever the 'Disable' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			ConditionDisable& operator=(const ConditionDisable&);
			/*! Forbid use of copy constructor */
			ConditionDisable(const ConditionDisable&);
		};
		typedef ObjectPointer<ConditionDisable> ConditionDisablePtr;
		typedef ObjectPointer<const ConditionDisable> ConditionDisableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERCONDITIONDISABLE_H
