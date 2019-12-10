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

#ifndef SERVERREADTRANSACTION_H
#define SERVERREADTRANSACTION_H
#include "Base.h"
#include "Enums.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "ServerDataTransaction.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class ReadRequest;
	}

	namespace Server
	{
		/*! The ReadTransaction allows server applications to process 'Read' service calls.
		* Clients use the 'Read' service to read attribute values from one or more nodes on the server.
		* The transaction contains a ReadRequest object for each node and attribute value that is to be read.
		*
		* The SDK creates a new transaction object for every service call and triggers the
		* handleRequests() callback that is responsible for processing the call. The default implementation
		* of handleRequests() calls BaseNode::handleReadRequest() for each node and attribute that is to be read.
		*
		* A transaction is completed when all requests in the transaction have been completed by
		* ReadRequest::complete(). Only when the transaction is completed, the response
		* to the service call is sent to the client. */
		class TBC_EXPORT ReadTransaction
			: public DataTransaction
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ReadTransaction(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			ReadTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ReadTransaction();

			/*! Returns the array of requests contained in this transaction instance. */
			std::vector< ObjectPointer<Server::ReadRequest> > getRequests();
			/*! @overload */
			std::vector< ObjectPointer<const Server::ReadRequest> > getRequests() const;

			/*! Callback method that is called by the SDK whenever a client uses the 'Read' service
			* to read attribute values from one or more nodes.
			*
			* The default implementation calls BaseNode::handleReadRequest() for every node and attribute
			* that is to be read.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			*
			* @note The requests within this transaction are already preprocessed by the SDK.
			*		If the SDK has found any errors (e.g. BadNodeIdUnknown, ...)
			*		in most cases the request should not be processed any more. Just complete the request and continue with the next.
			*		In some cases (e.g. processing "virtual" node, not known to the AddresSpaceRoot) further processing can be executed and the status code can be overwritten. */
			virtual EnumStatusCode handleRequests();

			/*! Removes timestamps from the given DataValue that have not been requested by
			* the client and initializes timestamps that have been requested but not provided
			* by the server application to the current time.
			*
			* @param[in,out] localValue	The DataValue that is to be updated
			* @param attributeId		The attribute that has been requested
			*
			* @see getTimestampToReturn() */
			EnumStatusCode updateTimeStamps(IDataValue* localValue, EnumAttributeId attributeId);

			/*! Returns the timestamps that the server application shall return for each read value
			* attribute of a variable. */
			EnumTimestampsToReturn getTimestampToReturn() const;

			/*! Returns the maximum allowed age of the value (in milliseconds) that is to be read.
			*
			* The age of the value is based on the difference between the server timestamp and
			* the time when the server starts processing the request. For example if the client
			* specifies a maximum age of 500 milliseconds and it takes 100 milliseconds until the server
			* starts processing the request, the age of the returned value could be 600 milliseconds
			* prior to the time it was requested.
			*
			* If the server has one or more values of an attribute that are within the maximum
			* age, it can return any one of the values or it can read a new value from the data
			* source. If the server does not have a value that is within the maximum age, it shall
			* attempt to read a new value from the data source.
			*
			* If the server cannot meet the requested maxAge, it returns its "best effort" value
			* rather than rejecting the request. This may occur when the time it takes the
			* server to process and return the new data value after it has been accessed is
			* greater than the specified maximum age.
			*
			* If maxAge is set to 0, the server shall attempt to read a new value from the data
			* source. If maxAge is set to the max Int32 value or greater, the server shall attempt to get
			* a cached value. Negative values are invalid for maxAge. */
			double getMaxAge() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable std::vector<ObjectPointer<Server::ReadRequest> > m_requests)

			/*! Transactions are always created by the SDK core. */
			ReadTransaction();
			/*! Forbid use assignment operator */
			ReadTransaction& operator=(const ReadTransaction&);
			/*! Forbid use of copy constructor */
			ReadTransaction(const ReadTransaction&);
		};
		typedef ObjectPointer<ReadTransaction> ReadTransactionPtr;
		typedef ObjectPointer<const ReadTransaction> ReadTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERREADTRANSACTION_H
