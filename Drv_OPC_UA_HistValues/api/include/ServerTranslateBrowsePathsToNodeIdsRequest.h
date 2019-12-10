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

#ifndef SERVERTRANSLATEBROWSEPATHSTONODEIDSREQUEST_H
#define SERVERTRANSLATEBROWSEPATHSTONODEIDSREQUEST_H

#include "Base.h"
#include "ServerDataRequest.h"
#include "ServerBaseNode.h"
#include "NodeId.h"
#include "RelativePath.h"
#include "BrowsePathTarget.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The TranslateBrowsePathsToNodeIdsRequest contains one browse path that
		* is to be translated into NodeIds.
		*
		* Once the request has been processed, it needs to be completed
		* by calling complete().
		*
		* @see Server::TranslateBrowsePathsToNodeIdsTransaction */
		class TBC_EXPORT TranslateBrowsePathsToNodeIdsRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			TranslateBrowsePathsToNodeIdsRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			TranslateBrowsePathsToNodeIdsRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~TranslateBrowsePathsToNodeIdsRequest();

			/*! Returns the NodeId of the starting node for the browse path. */
			EnumStatusCode getStartingNodeId(NodeId& nodeId) const;

			/*! Returns the starting node for the browse path. This method returns NULL
			* if the starting node was not found in the server's address space. */
			ObjectPointer<Server::BaseNode> getStartingNode();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getStartingNode() const;

			/*! Returns the path to follow from the starting node. */
			EnumStatusCode getRelativePath(RelativePath& relativePath) const;

			/*! Sets the list of targets for the relative path from the starting node.
			*
			* A Server may encounter a reference to a node in another server which it
			* cannot follow while it is processing the relative path. If this happens the
			* server returns the NodeId of the external node and sets the RemainingPathIndex
			* parameter to indicate which relative path elements still need to be processed.
			* To complete the operation the client shall connect to the other server and call
			* this service again using the target as the starting node and the unprocessed
			* elements as the relative path. */
			EnumStatusCode setTargets(const std::vector<BrowsePathTarget>& targets);

			/*! Returns the status code for this request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code for this request which is returned to the client.
			*
			* @param	statusCode The request status code
			* @return	A good result, if the provided status code was accepted */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Returns diagnostic information provided for the TranslateBrowsePathsToNodeIds request.
			*
			* @see	setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the TranslateBrowsePathsToNodeIds request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param	diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see DataTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::BaseNode> m_startingNode)
			InnerDiagnosticInfo m_diagnosticInfo;

			/*! Requests are always created by the SDK core. */
			TranslateBrowsePathsToNodeIdsRequest();
			/*! Forbid use assignment operator */
			TranslateBrowsePathsToNodeIdsRequest& operator=(const TranslateBrowsePathsToNodeIdsRequest&);
			/*! Forbid use of copy constructor */
			TranslateBrowsePathsToNodeIdsRequest(const TranslateBrowsePathsToNodeIdsRequest&);
		};
		typedef ObjectPointer<TranslateBrowsePathsToNodeIdsRequest> TranslateBrowsePathsToNodeIdsRequestPtr;
		typedef ObjectPointer<const TranslateBrowsePathsToNodeIdsRequest> TranslateBrowsePathsToNodeIdsRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERTRANSLATEBROWSEPATHSTONODEIDSREQUEST_H
