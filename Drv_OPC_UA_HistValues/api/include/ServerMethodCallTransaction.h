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

#ifndef SERVERMETHODCALLTRANSACTION_H
#define SERVERMETHODCALLTRANSACTION_H
#include "Base.h"
#include "Enums.h"
#include "ServerDataTransaction.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class MethodCallRequest;
	}

	namespace Server
	{
		/*! The MethodCallTransaction allows server applications to process 'Call' service calls.
		* Clients use the 'Call' service to trigger the execution of one or more methods on the server.
		* The transaction contains a MethodCallRequest object for each method that is to be executed.
		*
		* The SDK creates a new transaction object for every service call and triggers the
		* handleRequests() callback that is responsible for processing the call. The default implementation
		* of handleRequests() calls Method::handleExecuteRequest() for every method that is to be executed.
		*
		* A transaction is completed when all requests in the transaction have been completed by
		* MethodCallRequest::complete(). Only when the transaction is completed, the response
		* to the service call is sent to the client. */
		class TBC_EXPORT MethodCallTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			MethodCallTransaction(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			MethodCallTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~MethodCallTransaction();

			/*! Returns the array of MethodCallRequests contained in this transaction instance. */
			std::vector< ObjectPointer<Server::MethodCallRequest> > getRequests();
			/*! @overload */
			std::vector< ObjectPointer<const Server::MethodCallRequest> > getRequests() const;

			/*! Callback method that is called by the SDK whenever a client uses the 'Call' service
			* to execute one or more methods on the server.
			*
			* The default implementation calls Method::handleExecuteRequest() for every method
			* that is to be executed.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			*
			* @note The requests within this transaction are already preprocessed by the SDK.
			*		If the SDK has found any errors (e.g. BadNodeIdUnknown, ...)
			*		in most cases the request should not be processed any more. Just complete the request and continue with the next.
			*		In some cases (e.g. processing "virtual" node, not known to the AddresSpaceRoot) further processing can be executed and the status code can be overwritten. */
			virtual EnumStatusCode handleRequests();

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::MethodCallRequest> > m_requests)

			/*! Transactions are always created by the SDK core. */
			MethodCallTransaction();

			/*! Forbid use assignment operator */
			MethodCallTransaction& operator=(const MethodCallTransaction&);
			/*! Forbid use of copy constructor */
			MethodCallTransaction(const MethodCallTransaction&);
		};
		typedef ObjectPointer<MethodCallTransaction> MethodCallTransactionPtr;
		typedef ObjectPointer<const MethodCallTransaction> MethodCallTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERMETHODCALLTRANSACTION_H
