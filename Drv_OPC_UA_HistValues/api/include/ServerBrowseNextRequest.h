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

#ifndef SERVERBROWSENEXTREQUEST_H
#define SERVERBROWSENEXTREQUEST_H

#include "Base.h"
#include "ServerDataRequest.h"
#include "ServerBrowseContinuationPoint.h"
#include "ServerVariable.h"
#include "NodeId.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"
#include "ReferenceDescription.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The BrowseNextRequest is part of a BrowseNextTransaction and contains a continuation point
		* that allows server applications to continue a browse of the address space.
		*
		* @see BrowseNextTransaction */
		class TBC_EXPORT BrowseNextRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BrowseNextRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			BrowseNextRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BrowseNextRequest();

			/*! Returns the existing continuation point for the request.
			*
			* @param[out] continuationPoint The continuation point for the request
			*
			* @return	A good result, if a continuation point exists.
			*			EnumStatusCode_BadContinuationPointInvalid, if the continuation point provided by
			*			the client has been invalid. */
			EnumStatusCode getContinuationPoint(BrowseContinuationPointPtr& continuationPoint) const;

			/*! Deletes the continuation point for the request.
			*
			* If the server application has returned all references to the client, it must
			* delete the continuation point before completing the request.
			*
			* @return	A good result, if the continuation point could be deleted.
			*			EnumStatusCode_BadContinuationPointInvalid, if the continuation point provided
			*			by the client has been invalid.
			*
			* @see Server::Session::onDeleteContinuationPoint() */
			EnumStatusCode deleteContinuationPoint();

			/*! Sets the reference descriptions that are returned to the client as response to the browse request,
			* containing all necessary information about the reference and the target node.
			*
			* @see	ReferenceDescription */
			EnumStatusCode setReferences(const std::vector<ReferenceDescription>& references);

			/*! Returns the status code for this request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code for this request which is returned to the client.
			*
			* @param statusCode The request status code
			* @return A good result, if the provided status code was accepted */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Returns diagnostic information provided for the BrowseNext request.
			*
			* @see setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the BrowseNext request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see BrowseNextTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			InnerDiagnosticInfo m_diagnosticInfo;

			// Requests are always created by the SDK core.
			// Use the protected constructor when deriving from this class.
			BrowseNextRequest();

			/*! Forbid use assignment operator */
			BrowseNextRequest& operator=(const BrowseNextRequest&);
			/*! Forbid use of copy constructor */
			BrowseNextRequest(const BrowseNextRequest&);
		};
		typedef ObjectPointer<BrowseNextRequest> BrowseNextRequestPtr;
		typedef ObjectPointer<const BrowseNextRequest> BrowseNextRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERBROWSENEXTREQUEST_H
