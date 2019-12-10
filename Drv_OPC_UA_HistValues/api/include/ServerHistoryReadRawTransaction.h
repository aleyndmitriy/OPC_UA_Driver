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

#ifndef SERVERHISTORYREADRAWTRANSACTION_H
#define SERVERHISTORYREADRAWTRANSACTION_H
#if TB5_HISTORY

#include "Base.h"
#include "Enums.h"
#include "ServerDataTransaction.h"
#include "ServerHistoryReadRawRequest.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The HistoryReadRawTransaction class encapsulates client requests for raw historical data of variables
		*and allows the server application to handle such requests.
		*
		* The default implementation handles read requests for raw historical data by dispatching
		* each request of a transaction to the Server::Variable::handleHistoryReadRawRequest() method of
		* the affected variable. In order to provide the requested historical values for the variable,
		* a server application may want to override this method.
		*
		* For optimization reasons, a server application may want to change the request dispatching
		* behavior of the transaction (e.g. to bundle requests for nodes when requesting values
		* from an underlying historian). This can be achieved by subclassing the transaction and
		* providing a custom implementation for handleRequests(). Please note that the subclass must
		* also be added to the application's Creator (Transactions are created by the toolbox core -
		* so the it must be able to instantiate the derived class). */
		class TBC_EXPORT HistoryReadRawTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadRawTransaction(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~HistoryReadRawTransaction();

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
			std::vector<ObjectPointer<HistoryReadRawRequest> > getRequests();
			/*! @overload */
			std::vector<ObjectPointer<const HistoryReadRawRequest> > getRequests() const;

			/*! Returns the beginning of the period for which to read historical values.
			*
			* If the client does not provide a start time, this method returns the NULL time (@see IDateTime::isNull) */
			DateTime getStartTime() const;

			/*! Returns the end of the period for which to read historical values.
			*
			* If the client does not provide an end time, this method returns the NULL time (@see IDateTime::isNull) */
			DateTime getEndTime() const;

			/*! Returns the maximum number of historical values to return for every
			* node in a request.
			*
			* If the available number of values exceeds the provided maximum, the
			* server application may create a continuation point to allow the
			* client to fetch more values. */
			OTUInt32 getMaxNumberOfValuesPerNode() const;

			/*! Returns whether bounding values (the first historical value stored before the provided
			* start time and the first historical value stored after the provided end time) are
			* to be included. */
			bool returnBoundingValues() const;

			/*! Returns the timestamps requested by the client: 'ServerTimestamp', 'SourceTimestamp' or 'Both'
			* ('Neither' is not allowed for history read raw requests).
			*
			* @note If the server does not support the requested timestamps the status code EnumStatusCode_BadTimestampNotSupported shall be used for every request. */
			EnumTimestampsToReturn getTimestampToReturn() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::HistoryReadRawRequest> > m_requests)

			// Transactions are always created by the SDK core.
			// Use the constructor HistoryReadRawTransaction(TBHandle) when deriving from this class.
			HistoryReadRawTransaction();

			/*! Forbid use assignment operator */
			HistoryReadRawTransaction& operator=(const HistoryReadRawTransaction&);
			/*! Forbid use of copy constructor */
			HistoryReadRawTransaction(const HistoryReadRawTransaction&);
		};
		typedef ObjectPointer<HistoryReadRawTransaction> HistoryReadRawTransactionPtr;
		typedef ObjectPointer<const HistoryReadRawTransaction> HistoryReadRawTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif

#endif	// SERVERHISTORYREADRAWTRANSACTION_H
