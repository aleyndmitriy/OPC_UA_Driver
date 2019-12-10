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

#ifndef SERVERACKNOWLEDGEABLECONDITIONCONFIRM_H
#define SERVERACKNOWLEDGEABLECONDITIONCONFIRM_H
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
		/*! This class represents the "Confirm" method of an AcknowledgeableCondition that may
		* be called by clients to confirm the state of a Condition. */
		class TBC_EXPORT AcknowledgeableConditionConfirm
			: public Method
		{
		public:
			/*! Constructs a new AcknowledgeableConditionConfirm instance */
			static ObjectPointer<AcknowledgeableConditionConfirm> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AcknowledgeableConditionConfirm(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			AcknowledgeableConditionConfirm();
			/*! For internal use only */
			AcknowledgeableConditionConfirm(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~AcknowledgeableConditionConfirm();

			/*! Callback method that contains the code that is executed when a clients calls the OPC UA method.
			* The default implementation delegates the execution to AcknowledgeableConditionConfirm::doRequest().
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		protected:
			/*! This method contains the logic to confirm a Condition. */
			EnumStatusCode doRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			AcknowledgeableConditionConfirm& operator=(const AcknowledgeableConditionConfirm&);
			/*! Forbid use of copy constructor */
			AcknowledgeableConditionConfirm(const AcknowledgeableConditionConfirm&);
		};
		typedef ObjectPointer<AcknowledgeableConditionConfirm> AcknowledgeableConditionConfirmPtr;
		typedef ObjectPointer<const AcknowledgeableConditionConfirm> AcknowledgeableConditionConfirmConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERACKNOWLEDGEABLECONDITIONCONFIRM_H
