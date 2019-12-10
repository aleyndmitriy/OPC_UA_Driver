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

#ifndef SERVERHISTORYEVENTREQUEST_H
#define SERVERHISTORYEVENTREQUEST_H
#if TB5_HISTORY

#include "Base.h"
#include "ServerHistoryReadEventContinuationPoint.h"
#include "ServerDataRequest.h"
#include "ServerVariable.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"
#include "HistoryEventFieldList.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The HistoryReadEventRequest contains the parameters for reading historical events
		* from an object that has the 'HistoryRead' bit set in its EventNotifier attribute.
		*
		* When the requested historical values have been provided (see setEvents()), the request
		* must be completed by calling complete().
		*
		* @see HistoryReadEventTransaction for details on how to handle requests. */
		class TBC_EXPORT HistoryReadEventRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadEventRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			HistoryReadEventRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~HistoryReadEventRequest();

			/*! Returns whether a continuation point has been set for the request.
			*
			* @return true, if a continuation point has been set for this request */
			bool hasContinuationPoint() const;

			/*! Returns the existing continuation point for the request. The continuation
			* point must have been provided by setContinuationPoint().
			*
			* @param[out] continuationPoint The continuation point for the request
			*
			* @return	A good result, if a continuation point exists.
			*			EnumStatusCode_BadContinuationPointInvalid, if no continuation has been created for request. */
			EnumStatusCode getContinuationPoint(HistoryReadEventContinuationPointPtr& continuationPoint) const;

			/*! Creates the continuation point for the request. The continuation point is only
			* delivered to clients if it has been associated with the request (see setContinuationPoint()).
			*
			* If the request yields more historical values than the server may return in one
			* response (i.e. the maximum number of values per node is exceeded), a continuation
			* point must be created before completing the request. The server application shall fill
			* the continuation point with all information required to continue processing the request
			* when demanded by a client.
			*
			* A continuation point for a request has to be created only when the request is processed
			* for the first time (and yields more data than can be delivered). Further (continued) requests
			* use getContinuationPoint() to retrieve an existing continuation point that contains all information
			* required to resume request processing.
			*
			* @see setContinuationPoint() Server::Session::onDeleteContinuationPoint()
			*
			* @note	The created continuation point must be associated with the request (see setContinuationPoint())
			*		after the server application has provided all information that is required to continue the request.
			* @note The server application can also provide a continuation point if calculation takes a long time, even if not a single event is calculated.
			*       The application can continue processing with the next request from client. */
			EnumStatusCode createContinuationPoint(HistoryReadEventContinuationPointPtr& continuationPoint);

			/*! Associates the given continuation point with the request. Once the request is associated
			* with a continuation point, the association remains valid until the continuation point
			* is deleted (see deleteContinuationPoint()).
			*
			* The lifetime of a continuation point is not bound to the lifetime of the continuation point object.
			* The continuation point is destroyed either
			* @li	on demand by deleteContinuationPoint() when all historical values have been returned
			*		to the client or
			* @li	when the associated session of the request is closed or
			* @li	when the maximum number of continuation points has reached.
			*
			* @note The removal of a continuation point is only reported by Session::onDeleteContinuationPoint()
			*		when the continuation point has been associated with a request. A server application should
			*		expect to be called by that callback function once it has called setContinuationPoint(). */
			EnumStatusCode setContinuationPoint(HistoryReadEventContinuationPointPtr continuationPoint);

			/*! Deletes the continuation point for the request.
			*
			* If the server application has returned all historical values to the client, it must
			* delete the continuation point before completing the request.
			*
			* @return	A good result, if the continuation point could be deleted.
			*			EnumStatusCode_BadContinuationPointInvalid, if the continuation point has not been created.
			*
			* @see Server::Session::onDeleteContinuationPoint() */
			EnumStatusCode deleteContinuationPoint();

			/*! Returns the NodeId of the object whose event history is to be read. */
			NodeId getNodeId() const;

			/*! Returns the index range requested for the historical values.
			*
			* If the historical value is an array, a client may request to retrieve only a subset
			* of this array. The range of this subset is defined by the index range. */
			NumericRange getIndexRange() const;

			/*! Sets the list of historical events that are to be delivered to the client.
			*
			* @param historicalEvents	The requested list of historical events */
			EnumStatusCode setEvents(const std::vector<HistoryEventFieldList>& historicalEvents);

			/*! Returns the status code for this request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code for this request which is returned to the client.
			*
			* @param statusCode The request status code
			* @return A good result, if the provided status code was accepted */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Returns diagnostic information provided for the HistoryReadEvent request.
			*
			* @see setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the HistoryReadEvent request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see HistoryReadEventTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			InnerDiagnosticInfo m_diagnosticInfo;

			// Requests are always created by the SDK core.
			HistoryReadEventRequest();

			/*! Forbid use assignment operator */
			HistoryReadEventRequest& operator=(const HistoryReadEventRequest&);
			/*! Forbid use of copy constructor */
			HistoryReadEventRequest(const HistoryReadEventRequest&);
		};
		typedef ObjectPointer<HistoryReadEventRequest> HistoryReadEventRequestPtr;
		typedef ObjectPointer<const HistoryReadEventRequest> HistoryReadEventRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif

#endif	// SERVERHISTORYEVENTREQUEST_H
