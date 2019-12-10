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

#ifndef SERVERSHELVEDSTATEMACHINETIMEDSHELVE_H
#define SERVERSHELVEDSTATEMACHINETIMEDSHELVE_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
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
		/*! The TimedShelve method allows clients to set the alarm condition to the TimedShelved state.
		*
		* @see ShelvedStateMachine AlarmCondition */
		class TBC_EXPORT ShelvedStateMachineTimedShelve
			: public Method
		{
		public:
			/*! Constructs a new ShelvedStateMachineTimedShelve instance */
			static ObjectPointer<ShelvedStateMachineTimedShelve> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ShelvedStateMachineTimedShelve(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ShelvedStateMachineTimedShelve();
			/*! For internal use only */
			ShelvedStateMachineTimedShelve(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ShelvedStateMachineTimedShelve();

			/*! Callback method that is called whenever the 'TimedShelve' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			ShelvedStateMachineTimedShelve& operator=(const ShelvedStateMachineTimedShelve&);
			/*! Forbid use of copy constructor */
			ShelvedStateMachineTimedShelve(const ShelvedStateMachineTimedShelve&);
		};
		typedef ObjectPointer<ShelvedStateMachineTimedShelve> ShelvedStateMachineTimedShelvePtr;
		typedef ObjectPointer<const ShelvedStateMachineTimedShelve> ShelvedStateMachineTimedShelveConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERSHELVEDSTATEMACHINETIMEDSHELVE_H
