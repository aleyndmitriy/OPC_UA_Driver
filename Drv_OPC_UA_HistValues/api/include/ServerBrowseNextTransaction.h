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

#ifndef SERVERBROWSENEXTTRANSACTION_H
#define SERVERBROWSENEXTTRANSACTION_H

#include "Base.h"
#include "Enums.h"
#include "ServerDataTransaction.h"
#include "ServerBrowseNextRequest.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The BrowseNextTransaction allows server applications to process 'BrowseNext' service calls.
		* Clients use the 'BrowseNext' service to follow-up a browse request issued earlier.
		* The transaction contains a BrowseNextRequest object for each node to browse.
		*
		* The SDK creates a new transaction object for every service call and triggers the
		* handleRequests() callback that is responsible for processing the call. The default implementation
		* of handleRequests() calls browses the address space of this server and returns the according results.
		*
		* A transaction is completed when all requests in the transaction have been completed by
		* BrowseRequest::complete(). Only when the transaction is completed, the response
		* to the service call is sent to the client. */
		class TBC_EXPORT BrowseNextTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BrowseNextTransaction(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~BrowseNextTransaction();

			/*! Callback function that is called to handle all BrowseNext requests of the data transaction in one call.
			* That allows to sort the different requests e.g. depending on the target which contains the requested value.
			*
			* The default implementation handles all not completed requests.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			*
			* @note The requests within this transaction are already preprocessed by the SDK.
			*		If the SDK has found any errors (e.g. BadNodeIdUnknown, BadContinuationPointInvalid, ...)
			*		in most cases the request should not be processed any more. Just complete the request and continue with the next.
			*		In some cases (e.g. processing "virtual" node, not known to the AddresSpaceRoot) further processing can be executed and the status code can be overwritten. */
			virtual EnumStatusCode handleRequests();

			/*! Returns the array of requests contained in this transaction instance. */
			std::vector<ObjectPointer<BrowseNextRequest> > getRequests();
			/*! @overload */
			std::vector<ObjectPointer<const BrowseNextRequest> > getRequests() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::BrowseNextRequest> > m_requests)

			// Transactions are always created by the SDK core.
			// Use the constructor BrowseNextTransaction(TBHandle) when deriving from this class.
			BrowseNextTransaction();

			/*! Forbid use assignment operator */
			BrowseNextTransaction& operator=(const BrowseNextTransaction&);
			/*! Forbid use of copy constructor */
			BrowseNextTransaction(const BrowseNextTransaction&);
		};
		typedef ObjectPointer<BrowseNextTransaction> BrowseNextTransactionPtr;
		typedef ObjectPointer<const BrowseNextTransaction> BrowseNextTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end


#endif	// SERVERBROWSENEXTTRANSACTION_H
