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

#ifndef CLIENTCERTIFICATECHANGE_H
#define CLIENTCERTIFICATECHANGE_H
#include "Base.h"
#include "Enums.h"
#include "ByteString.h"

namespace SoftingOPCToolbox5
{
	namespace Client
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
		class TBC_EXPORT CertificateChangeTransaction
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			CertificateChangeTransaction(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			CertificateChangeTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~CertificateChangeTransaction();

			/*! Returns the new server certificate */
			ByteString geCertificate();

			/*! The validation result of the sessions PKI store. */
			EnumStatusCode getValidationResult() const;


			/*! Completes the transaction.
			*
			* @param result	The result how to continue. A bad result will deny the actual running (re-) connect to the server. */
			void complete(EnumStatusCode result);

		private:
			/*! Transactions are always created by the SDK core. */
			CertificateChangeTransaction();
			/*! Forbid use assignment operator */
			CertificateChangeTransaction& operator=(const CertificateChangeTransaction&);
			/*! Forbid use of copy constructor */
			CertificateChangeTransaction(const CertificateChangeTransaction&);
		};

		typedef ObjectPointer<CertificateChangeTransaction> CertificateChangeTransactionPtr;
		typedef ObjectPointer<const CertificateChangeTransaction> CertificateChangeTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERREADTRANSACTION_H
