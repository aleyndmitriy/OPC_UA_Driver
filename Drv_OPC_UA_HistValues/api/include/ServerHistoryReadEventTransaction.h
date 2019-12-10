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

#ifndef SERVERHISTORYREADEVENTTRANSACTION_H
#define SERVERHISTORYREADEVENTTRANSACTION_H
#if TB5_HISTORY

#include "Base.h"
#include "Enums.h"
#include "AggregateConfiguration.h"
#include "ServerDataTransaction.h"
#include "ServerHistoryReadEventRequest.h"
#include "EventFilter.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The HistoryReadEventTransaction class encapsulates client requests for historical events
		* and allows the server application to handle such requests.
		*
		* The default implementation handles read requests for historical events by dispatching
		* each request of a transaction to the Server::Object::handleHistoryReadEventRequest() method of
		* the affected object. In order to provide the requested historical events, a server application
		* may want to override this method.
		*
		* For optimization reasons, a server application may want to change the request dispatching
		* behavior of the transaction (e.g. to bundle requests for nodes when requesting event field values
		* from an underlying historian). This can be achieved by subclassing the transaction and
		* providing a custom implementation for handleRequests(). Please note that the subclass must
		* also be added to the application's Creator (Transactions are created by the toolbox core -
		* so the it must be able to instantiate the derived class). */
		class TBC_EXPORT HistoryReadEventTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadEventTransaction(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~HistoryReadEventTransaction();

			/*! Callback function that is called to handle all requests of the transaction in one call.
			* That allows to sort the different requests e.g. depending on the target which contains the requested value.
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
			std::vector<ObjectPointer<HistoryReadEventRequest> > getRequests();
			/*! @overload */
			std::vector<ObjectPointer<const HistoryReadEventRequest> > getRequests() const;

			/*! Returns the beginning of the period to read. If the start time equals the minimum value of DateTime,
			* no specific start time is specified.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			DateTime getStartTime() const;

			/*! Returns the end of the period to read. If the start time equals the minimum value of DateTime,
			* no specific end time is specified.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			DateTime getEndTime() const;

			/*! Returns the maximum number of historical values to return for every
			* node in a request.
			*
			* If the available number of values exceeds the provided maximum, the
			* server application may create a continuation point to allow the
			* client to fetch more values.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			OTUInt32 getMaxNumberOfValuesPerNode() const;

			/*! Returns the filter that shall be used by the server application to determine which historical events to include in
			* the response and which event fields to return. This parameter must be specified and at least one EventField must be selected.
			*
			* @see EventFilterEvaluator */
			EnumStatusCode getFilter(EventFilter& filter) const;

			/*! Returns which timestamps to return for DataValues in event fields.
			* This parameter can be ignored for event fields that are not of type DataValue.
			*
			* @note This parameter applies only to event fields that are of type DataValue.
			* @note If the server does not support the requested timestamps the status code EnumStatusCode_BadTimestampNotSupported shall be used for every request. */
			EnumTimestampsToReturn getTimestampToReturn() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<HistoryReadEventRequest> > m_requests)

			// Transactions are always created by the SDK core.
			HistoryReadEventTransaction();

			/*! Forbid use assignment operator */
			HistoryReadEventTransaction& operator=(const HistoryReadEventTransaction&);
			/*! Forbid use of copy constructor */
			HistoryReadEventTransaction(const HistoryReadEventTransaction&);
		};
		typedef ObjectPointer<HistoryReadEventTransaction> HistoryReadEventTransactionPtr;
		typedef ObjectPointer<const HistoryReadEventTransaction> HistoryReadEventTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif

#endif	// SERVERHISTORYREADEVENTTRANSACTION_H
