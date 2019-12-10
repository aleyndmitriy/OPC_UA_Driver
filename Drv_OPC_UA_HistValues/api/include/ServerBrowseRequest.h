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

#ifndef SERVERBROWSEREQUEST_H
#define SERVERBROWSEREQUEST_H

#include "Base.h"
#include "ServerDataRequest.h"
#include "ServerBrowseContinuationPoint.h"
#include "ServerVariable.h"
#include "NodeId.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"
#include "ReferenceDescription.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The BrowseRequest is part of a BrowseTransaction and contains the node to browse and properties
		* for how to find adjacent nodes.
		*
		* @see	BrowseTransaction */
		class TBC_EXPORT BrowseRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BrowseRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			BrowseRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BrowseRequest();

			/*! Returns the NodeId of the node from where the browse shall be performed. */
			EnumStatusCode getNodeIdToBrowse(NodeId& nodeId) const;

			/*! Returns a pointer to the Node from where the browse shall be performed. */
			ObjectPointer<Server::BaseNode> getNodeToBrowse();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNodeToBrowse() const;

			/*! Returns the direction of references to follow, whether to search in forward, backward
			* or both directions.
			*
			* @see	EnumBrowseDirection */
			EnumBrowseDirection getBrowseDirection() const;

			/*! Returns the NodeId of the reference type to follow.
			* Only found instances of this type or its subtypes shall be returned.
			*
			* @see	getIncludeSubtypes() */
			EnumStatusCode getReferenceTypeId(NodeId& nodeId) const;

			/*! Returns whether to follow subtypes of the provided reference type.
			*
			* @see	getReferenceTypeId() */
			bool getIncludeSubtypes() const;

			/*! Returns the node classes that are to be followed.
			* This option restricts the returned results to certain node classes.
			*
			* @note	This value is a bit mask and it may be an combination of several values.
			* @see	EnumNodeClass */
			EnumNodeClass getNodeClassMask() const;

			/*! Returns the result mask that is to be applied to the followed nodes.
			* The result mask describes, which information shall be returned for the found nodes additional to their NodeId.
			*
			* @note	This value is a bit mask and it may be an combination of several values.
			* @see	EnumResultMask */
			EnumResultMask getResultMask() const;

			/*! Sets the reference descriptions that are returned to the client as response to the browse request,
			* containing all necessary information about the reference and the target node.
			*
			* @see	ReferenceDescription */
			EnumStatusCode setReferences(const std::vector<ReferenceDescription>& references);

			/*! Returns the status code for this request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code for this request which is returned to the client.
			*
			* @param	statusCode The request status code
			* @return	A good result, if the provided status code was accepted */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Returns diagnostic information provided for the Browse request.
			*
			* @see	setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the Browse request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param	diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see BrowseTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

			/*! Returns whether a continuation point has been set for the request.
			*
			* @return	true, if a continuation point has been set for this request */
			bool hasContinuationPoint() const;
			/*! Returns the existing continuation point for the request. The continuation
			* point must have been provided by setContinuationPoint().
			*
			* @param[out] continuationPoint The continuation point for the request
			*
			* @return	A good result, if a continuation point exists.
			*			EnumStatusCode_BadContinuationPointInvalid, if no continuation has been created for request. */
			EnumStatusCode getContinuationPoint(Server::BrowseContinuationPointPtr& continuationPoint) const;
			/*! Creates the continuation point for the request. The continuation point is only
			* delivered to clients if it has been associated with the request (see setContinuationPoint()).
			*
			* If the request yields more results than the server may return in one response (i.e. the
			* maximum number of values per node is exceeded), a continuation point must be created
			* before completing the request. The server application shall fill the continuation point
			* with all information required to continue processing the request when demanded by a client.
			*
			* A continuation point for a request has to be created only when the request is processed
			* for the first time (and yields more data than can be delivered). Further (continued) requests
			* use getContinuationPoint() to retrieve an existing continuation point that contains all information
			* required to resume request processing.
			*
			* @see	setContinuationPoint() Server::Session::onDeleteContinuationPoint()
			*
			* @note	The created continuation point must be associated with the request (see setContinuationPoint())
			*		after the server application has provided all information that is required to continue the request. */
			EnumStatusCode createContinuationPoint(Server::BrowseContinuationPointPtr& continuationPoint);
			/*! Associates the given continuation point with the request. Once the request is associated
			* with a continuation point, the association remains valid until the continuation point
			* is deleted (see deleteContinuationPoint()).
			*
			* The lifetime of a continuation point is not bound to the lifetime of the continuation point object.
			* The continuation point is destroyed either
			* @li	on demand by deleteContinuationPoint() when all results have been returned to the client or
			* @li	when the associated session of the request is closed or
			* @li	when the maximum number of continuation points has reached.
			*
			* @note	The removal of a continuation point is only reported by Session::onDeleteContinuationPoint()
			*		when the continuation point has been associated with a request. A server application should
			*		expect to be called by that callback function once it has called setContinuationPoint(). */
			EnumStatusCode setContinuationPoint(Server::BrowseContinuationPointPtr continuationPoint);
			/*! Deletes the continuation point for the request.
			*
			* If the server application has returned all results to the client, it must
			* delete the continuation point before completing the request.
			*
			* @return	A good result, if the continuation point could be deleted.
			*			EnumStatusCode_BadContinuationPointInvalid, if the continuation point has not been created.
			*
			* @see	Server::Session::onDeleteContinuationPoint() */
			EnumStatusCode deleteContinuationPoint();

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::BaseNode> m_nodeToBrowse)

			InnerDiagnosticInfo m_diagnosticInfo;

			/*! Requests are always created by the SDK core. */
			BrowseRequest();
			/*! Forbid use assignment operator */
			BrowseRequest& operator=(const BrowseRequest&);
			/*! Forbid use of copy constructor */
			BrowseRequest(const BrowseRequest&);
		};
		typedef ObjectPointer<BrowseRequest> BrowseRequestPtr;
		typedef ObjectPointer<const BrowseRequest> BrowseRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERBROWSEREQUEST_H
