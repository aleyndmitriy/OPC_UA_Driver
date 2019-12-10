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

#ifndef SERVERSHELVEDSTATEMACHINEONESHOTSHELVE_H
#define SERVERSHELVEDSTATEMACHINEONESHOTSHELVE_H
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
		/*! The OneShotShelve method allows clients to set the alarm condition to the OneShotShelved state.
		*
		* @see ShelvedStateMachine AlarmCondition */
		class TBC_EXPORT ShelvedStateMachineOneShotShelve
			: public Method
		{
		public:
			/*! Constructs a new ShelvedStateMachineOneShotShelve instance */
			static ObjectPointer<ShelvedStateMachineOneShotShelve> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ShelvedStateMachineOneShotShelve(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ShelvedStateMachineOneShotShelve();
			/*! For internal use only */
			ShelvedStateMachineOneShotShelve(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ShelvedStateMachineOneShotShelve();

			/*! Callback method that is called whenever the 'OneShotShelve' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			ShelvedStateMachineOneShotShelve& operator=(const ShelvedStateMachineOneShotShelve&);
			/*! Forbid use of copy constructor */
			ShelvedStateMachineOneShotShelve(const ShelvedStateMachineOneShotShelve&);
		};
		typedef ObjectPointer<ShelvedStateMachineOneShotShelve> ShelvedStateMachineOneShotShelvePtr;
		typedef ObjectPointer<const ShelvedStateMachineOneShotShelve> ShelvedStateMachineOneShotShelveConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERSHELVEDSTATEMACHINEONESHOTSHELVE_H
