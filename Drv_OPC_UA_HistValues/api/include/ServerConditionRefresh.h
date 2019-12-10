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

#ifndef SERVERCONDITIONREFRESH_H
#define SERVERCONDITIONREFRESH_H
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
		/*! This class represents the 'Refresh' method that clients may call
		* to synchronize its state with the current server state.
		*
		* ConditionRefresh allows a client to request a refresh of all condition instances that currently are in
		* an interesting state (i.e. they have the 'Retain' flag set). This includes previous states of a Condition instance
		* for which the server maintains branches. A client would typically invoke this method when it initially
		* connects to a server and following any situations, such as communication disruptions, in which it would
		* require resynchronization with the server. */
		class TBC_EXPORT ConditionRefresh
			: public Method
		{
		public:
			/*! Constructs a new ConditionRefresh instance */
			static ObjectPointer<ConditionRefresh> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ConditionRefresh(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			ConditionRefresh();
			/*! For internal use only */
			ConditionRefresh(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ConditionRefresh();

			/*! Callback method that is called whenever the 'Refresh' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			ConditionRefresh& operator=(const ConditionRefresh&);
			/*! Forbid use of copy constructor */
			ConditionRefresh(const ConditionRefresh&);
		};
		typedef ObjectPointer<ConditionRefresh> ConditionRefreshPtr;
		typedef ObjectPointer<const ConditionRefresh> ConditionRefreshConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERCONDITIONREFRESH_H
