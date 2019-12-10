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

#ifndef SERVERBROWSETRANSACTION_H
#define SERVERBROWSETRANSACTION_H

#include "Base.h"
#include "Enums.h"
#include "ServerDataTransaction.h"
#include "ViewDescription.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// forward declaration
		class BrowseRequest;

		/*! The BrowseTransaction allows server applications to process 'Browse' service calls.
		* Clients use the 'Browse' service to discover the address space of the server.
		* The transaction contains a BrowseRequest object for each node to browse.
		*
		* The SDK creates a new transaction object for every service call and triggers the
		* handleRequests() callback that is responsible for processing the call. The default implementation
		* of handleRequests() calls browses the address space of this server and returns the according results.
		*
		* A transaction is completed when all requests in the transaction have been completed by
		* BrowseRequest::complete(). Only when the transaction is completed, the response
		* to the service call is sent to the client. */
		class TBC_EXPORT BrowseTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BrowseTransaction(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			BrowseTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BrowseTransaction();

			/*! Returns the array of requests contained in this transaction instance.
			* Each request contains the information for one node to browse.
			*
			* @see Server::BrowseRequest */
			std::vector< ObjectPointer<Server::BrowseRequest> > getRequests();
			/*! @overload */
			std::vector< ObjectPointer<const Server::BrowseRequest> > getRequests() const;

			/*! Callback method that is called by the SDK whenever a client uses the 'Browse' service
			* to discover the nodes of the address space.
			*
			* The default implementation handles all not completed requests and performs the browse on the
			* address space of this server including the creation of ContinuationPoints.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			*
			* @note The requests within this transaction are already preprocessed by the SDK.
			*		If the SDK has found any errors (e.g. BadNodeIdUnknown, BadContinuationPointInvalid, ...)
			*		in most cases the request should not be processed any more. Just complete the request and continue with the next.
			*		In some cases (e.g. processing "virtual" node, not known to the AddresSpaceRoot) further processing can be executed and the status code can be overwritten. */
			virtual EnumStatusCode handleRequests();

			/*! Returns the description of the view to browse.
			*
			* The view describes if the browse shall be performed on the entire address space or with certain
			* restriction, where only a part of the address space is visible.
			* An empty ViewDescription value indicates the entire address space.
			*
			* @see IViewDescription, Server::View */
			EnumStatusCode getView(ViewDescription& view) const;

			/*! Returns the maximum number of references to return for each starting node.
			* This value applies for every request of this transaction.
			*
			* A client application can request this to restrict the number of returned references.
			* When the number of requests is reached, a ContinuationPoint shall be created so that the client
			* can continue the request via the 'BrowseNext' service.
			*
			* The value 0 indicates that the client is imposing no limitation.
			*
			* @see Server::ContinuationPoint, Server::BrowseNextTransaction */
			OTUInt32 getRequestedMaxReferencesPerNode() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::BrowseRequest> > m_requests)

			/*! Transactions are always created by the SDK core. */
			BrowseTransaction();
			/*! Forbid use assignment operator */
			BrowseTransaction& operator=(const BrowseTransaction&);
			/*! Forbid use of copy constructor */
			BrowseTransaction(const BrowseTransaction&);
		};
		typedef ObjectPointer<BrowseTransaction> BrowseTransactionPtr;
		typedef ObjectPointer<const BrowseTransaction> BrowseTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERBROWSETRANSACTION_H
