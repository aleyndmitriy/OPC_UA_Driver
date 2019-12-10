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

#ifndef SERVERHISTORYREADPROCESSEDTRANSACTION_H
#define SERVERHISTORYREADPROCESSEDTRANSACTION_H
#if TB5_HISTORY

#include "Base.h"
#include "Enums.h"
#include "AggregateConfiguration.h"
#include "ServerDataTransaction.h"
#include "ServerHistoryReadProcessedRequest.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The HistoryReadProcessedTransaction class encapsulates client requests for processed (aggregated) historical data
		* of variables and allows the server application to handle such requests.
		*
		* The default implementation handles read requests for processed historical data by dispatching
		* each request of a transaction to the Server::Variable::handleHistoryReadProcessedRequest() method of
		* the affected variable. In order to provide the requested aggregated values for the variable,
		* a server application may want to override this method.
		*
		* For optimization reasons, a server application may want to change the request dispatching
		* behavior of the transaction (e.g. to bundle requests for nodes when requesting values
		* from an underlying historian). This can be achieved by sub-classing the transaction and
		* providing a custom implementation for handleRequests(). Please note that the subclass must
		* also be added to the application's Creator (Transactions are created by the toolbox core -
		* so the it must be able to instantiate the derived class).
		*
		* @see HistoryReadProcessedRequest Creator */
		class TBC_EXPORT HistoryReadProcessedTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadProcessedTransaction(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~HistoryReadProcessedTransaction();

			/*! Callback function that is called to handle all read requests of the data transaction in one call.
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
			std::vector<ObjectPointer<HistoryReadProcessedRequest> > getRequests();
			/*! @overload */
			std::vector<ObjectPointer<const HistoryReadProcessedRequest> > getRequests() const;

			/*! Returns the beginning of the period for which to calculate aggregated historical values
			*
			* If the client does not provide a start time, this method returns the NULL time (@see IDateTime::isNull) */
			DateTime getStartTime() const;

			/*! Returns the end of the period for which to calculate aggregated historical values
			*
			* If the client does not provide an end time, this method returns the NULL time (@see IDateTime::isNull) */
			DateTime getEndTime() const;

			/*! Returns the processing interval (in ms) that divides the total range |StartTime - EndTime|
			* into sub-ranges of the given length. The server shall return aggregate values for each
			* sub-range. If the processing interval is zero, only one aggregate value shall be calculated for
			* the total time range |StartTime - EndTime|. */
			double getProcessingInterval() const;

			/*! Returns the configuration that is to be used for calculating aggregate values.
			*
			* @see IAggregateConfiguration */
			SoftingOPCToolbox5::AggregateConfiguration getAggregateConfiguration() const;

			/*! Returns the timestamps requested by the client: 'ServerTimestamp', 'SourceTimestamp' or 'Both'
			* ('Neither' is not allowed for history read processed requests).
			*
			* @note If the server does not support the requested timestamps the status code EnumStatusCode_BadTimestampNotSupported shall be used for every request. */
			EnumTimestampsToReturn getTimestampToReturn() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::HistoryReadProcessedRequest> > m_requests)

			// Transactions are always created by the SDK core.
			// Use the constructor HistoryReadProcessedTransaction(TBHandle) when deriving from this class.
			HistoryReadProcessedTransaction();

			/*! Forbid use assignment operator */
			HistoryReadProcessedTransaction& operator=(const HistoryReadProcessedTransaction&);
			/*! Forbid use of copy constructor */
			HistoryReadProcessedTransaction(const HistoryReadProcessedTransaction&);
		};
		typedef ObjectPointer<HistoryReadProcessedTransaction> HistoryReadProcessedTransactionPtr;
		typedef ObjectPointer<const HistoryReadProcessedTransaction> HistoryReadProcessedTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif

#endif	// SERVERHISTORYREADPROCESSEDTRANSACTION_H
