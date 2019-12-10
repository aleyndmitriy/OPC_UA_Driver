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

#ifndef SERVERDATAREQUEST_H
#define SERVERDATAREQUEST_H
#include "Base.h"
#include "Enums.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class for all data requests.
		*
		* An OPC UA service invocation that is used by clients to request data from a server application
		* is represented as a data transaction in the SDK. Each transaction holds one or more data requests.
		* While each data request contains information that is specific to a certain node, the transaction
		* contains information that applies to all data requests.
		*
		* The reply to a service call is only sent when all data requests in a transaction have been completed.
		* The server application must ensure to always complete all requests in a transaction (see DataRequest::complete()).
		*
		* @note If an server application does not complete a request the memory for all requests in the transaction and the transaction itself is not released.
		*       This causes a memory leak!
		*
		* @see Server::DataTransaction */
		class TBC_EXPORT DataRequest
			: public Base
		{
		protected:
			/*! Default constructor */
			DataRequest();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory. */
			DataRequest(TBHandle otbHandle);

			/*! For internal use only */
			DataRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~DataRequest();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class DataRequest
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the status of the request to 'completed'. The method returns an error if
			* the request was already completed.
			*
			* When all requests of a transaction have been completed, the response to the service call
			* will be sent to the client. */
			EnumStatusCode complete();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class DataRequest
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the state of this request (see description of the EnumRequestState for details). */
			EnumRequestState getRequestState() const;
			/*! Sets the state of this request. Usually, complete() is used to set the request state to 'Completed'.
			*
			* @param requestState	The new state of the request. States can be increased only, i.e. setting state from 'Pending' to 'Started' is rejected
			*
			* @note	Setting the request state to 'Completed' will automatically complete the request @see complete() */
			EnumStatusCode setRequestState(EnumRequestState requestState);

			/*! Returns the 0-based index of the user group to which the user that issued the
			* request belongs to. */
			OTUInt32 getUserGroupIndex() const;

			/*! Indicates whether this request was canceled by a client or timed out. Clients may cancel
			* a request at any time while the server is processing the transaction. */
			OTBoolean isCancelled() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			/*! Forbid use assignment operator */
			DataRequest& operator=(const DataRequest&);
			/*! Forbid use of copy constructor */
			DataRequest(const DataRequest&);
		};
		typedef ObjectPointer<DataRequest> DataRequestPtr;
		typedef ObjectPointer<const DataRequest> DataRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDATAREQUEST_H
