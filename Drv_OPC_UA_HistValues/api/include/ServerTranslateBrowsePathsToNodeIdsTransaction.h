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

#ifndef SERVERTRANSLATEBROWSEPATHSTONODEIDSTRANSACTION_H
#define SERVERTRANSLATEBROWSEPATHSTONODEIDSTRANSACTION_H

#include "Base.h"
#include "Enums.h"
#include "ServerDataTransaction.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// forward declaration
		class TranslateBrowsePathsToNodeIdsRequest;

		/*! The TranslateBrowsePathsToNodeIdsTransaction allows server applications to process
		* 'TranslateBrowsePathsToNodeIds' service calls. Clients use this service to translate
		* one or more browse paths to NodeIds. The transaction contains a request object for
		* each starting node of a browse path. */
		class TBC_EXPORT TranslateBrowsePathsToNodeIdsTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TranslateBrowsePathsToNodeIdsTransaction(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			TranslateBrowsePathsToNodeIdsTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~TranslateBrowsePathsToNodeIdsTransaction();

			/*! Returns the array of requests contained in this transaction instance.
			* Each request contains one browse path to resolve.
			*
			* @see Server::TranslateBrowsePathsToNodeIdsRequest */
			std::vector< ObjectPointer<Server::TranslateBrowsePathsToNodeIdsRequest> > getRequests();
			/*! @overload */
			std::vector< ObjectPointer<const Server::TranslateBrowsePathsToNodeIdsRequest> > getRequests() const;

			/*! Callback method that is called by the SDK whenever a client uses the
			* 'TranslateBrowsePathsToNodeIds' service to translate one or more browse paths
			* to NodeIds.
			*
			* The default implementation services the requests by following references
			* that have been defined for nodes (see BaseNode::addReference()).
			*
			* @note	When overriding this method you must not use blocking calls within this method since
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
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<TranslateBrowsePathsToNodeIdsRequest> > m_requests)

			/*! Transactions are always created by the SDK core. */
			TranslateBrowsePathsToNodeIdsTransaction();
			/*! Forbid use assignment operator */
			TranslateBrowsePathsToNodeIdsTransaction& operator=(const TranslateBrowsePathsToNodeIdsTransaction&);
			/*! Forbid use of copy constructor */
			TranslateBrowsePathsToNodeIdsTransaction(const TranslateBrowsePathsToNodeIdsTransaction&);
		};
		typedef ObjectPointer<TranslateBrowsePathsToNodeIdsTransaction> TranslateBrowsePathsToNodeIdsTransactionPtr;
		typedef ObjectPointer<const TranslateBrowsePathsToNodeIdsTransaction> TranslateBrowsePathsToNodeIdsTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTRANSLATEBROWSEPATHSTONODEIDSTRANSACTION_H
