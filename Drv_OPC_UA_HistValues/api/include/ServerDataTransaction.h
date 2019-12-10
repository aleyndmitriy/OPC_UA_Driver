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

#ifndef SERVERDATATRANSACTION_H
#define SERVERDATATRANSACTION_H
#include "Base.h"
#include "Enums.h"
#include "DiagnosticInfo.h"
#include "InnerDiagnosticInfo.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class StringTable;
	namespace Server
	{
		class Session;
	}

	namespace Server
	{
		/*! Base class for all transactions.
		*
		* An OPC UA service invocation that is used by clients to request data from a server application
		* is represented as a data transaction in the SDK. Each transaction holds one or more data requests.
		* While each data request contains information that is specific to a certain node, the transaction
		* contains information that applies to all data requests.
		*
		* For example if a client invokes the Read service to request a list of attribute values from certain nodes,
		* the SDK creates a ReadTransaction that contains a ReadRequest for each node provided with the
		* service call.
		*
		* The reply to a service call is only sent when all data requests in a transaction have been completed.
		* The server application must ensure to always complete all requests in a transaction (see DataRequest::complete()).
		* A transaction can be completed forcefully using DataTransaction::complete().
		*
		* @see Server::DataRequest */
		class TBC_EXPORT DataTransaction
			: public Base
		{
		protected:
			/*! Default constructor */
			DataTransaction();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory. */
			DataTransaction(TBHandle otbHandle);

			/*! For internal use only */
			DataTransaction(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~DataTransaction();

			/*! Returns the session related to the transaction. Every transaction is bound to a single session. */
			ObjectPointer<Server::Session> getSession();
			/*! @overload */
			ObjectPointer<const Server::Session> getSession() const;

			/*! Forces the completion of the transaction with the given status code.
			* All contained requests will be set to 'completed' with the given status code as result
			* and a response will be sent to the client.
			*
			* The call to this method is only required if the request processing fails and the
			* transaction shall be completed with a single call.
			*
			* The method returns an error if the response could not be sent to the client.
			* The method does not return an error if the transaction is already completed.
			*
			* @param requestStatus The status code that is assigned to all outstanding requests */
			EnumStatusCode complete(EnumStatusCode requestStatus);

			/*! Indicates whether this service call was canceled by a client. Clients may cancel
			* a service call at any time while the server is processing the transaction.
			*
			* @see Session::onTransactionCancelled() */
			OTBoolean isCancelled() const;

			/*! Returns the 0-based index of the user group to which the user that invoked the
			* OPC UA service belongs to. */
			OTUInt32 getUserGroupIndex() const;

			/*! Returns the identifier that identifies the client's security audit log entry associated
			* with the transaction. */
			tstring getAuditEntryId() const;

			/*! Returns the client request handle for this transaction.
			*
			* This handle is used by Session::onTransactionCancelled() to identity transactions
			* that have been canceled by clients.
			*
			* @note	Please note that two or more transactions may share the same client request handle. */
			OTUInt32 getClientRequestHandle() const;

			//////////////////////////////////////////////////////////////////////////
			// Diagnostics-related methods
			//////////////////////////////////////////////////////////////////////////

			/*! Returns a bit field provided by the client that indicates which kind of
			* diagnostic information the server shall return.
			*
			* The following constants can be used to test for set bits:
			* @li EnumDiagnosticsToReturn_ServiceLevel_SymbolicId
			* @li EnumDiagnosticsToReturn_ServiceLevel_LocalizedText
			* @li EnumDiagnosticsToReturn_ServiceLevel_AdditionalInfo
			* @li EnumDiagnosticsToReturn_ServiceLevel_InnerStatusCode
			* @li EnumDiagnosticsToReturn_ServiceLevel_InnerDiagnostics
			* @li EnumDiagnosticsToReturn_Operationlevel_SymbolicId
			* @li EnumDiagnosticsToReturn_OperationLevel_LocalizedText
			* @li EnumDiagnosticsToReturn_OperationLevel_AdditionalInfo
			* @li EnumDiagnosticsToReturn_OperationLevel_InnerStatusCode
			* @li EnumDiagnosticsToReturn_OperationLevel_InnerDiagnostics
			*
			* @see DiagnosticInfo DiagnosticInfo::returnServiceLevelDiagnostics() DiagnosticInfo::returnOperationLevelDiagnostics() */
			OTUInt32 getDiagnosticsToReturn() const;

			/*! Returns diagnostic information for the service invocation / transaction.
			*
			* @see setServiceDiagnostics() */
			const IDiagnosticInfo* getServiceDiagnostics() const;
			/*! Sets diagnostic information for the service invocation / transaction.
			*
			* @param diagnosticInfo		The transaction-related diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see getDiagnosticsToReturn()). */
			EnumStatusCode setServiceDiagnostics(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setServiceDiagnostics(const IDiagnosticInfo& diagnosticInfo);

			/*! Returns the string table that contains strings which are used by
			* DiagnosticInfo objects conveyed to client.
			*
			* Every transaction initially contains an empty string table. The server
			* does not have to provide a string table (see setStringTable()) explicitly.
			*
			* @see DiagnosticInfo */
			ObjectPointer<StringTable> getStringTable();
			/*! @overload */
			ObjectPointer<const StringTable> getStringTable() const;
			/*! Replaces the string table with the given @p stringTable.
			* The string table is referenced by DiagnosticInfo objects which are conveyed to the client.
			*
			* @param stringTable	The string table referenced by DiagnosticInfo objects.
			*
			* @see getStringTable() */
			EnumStatusCode setStringTable(ObjectPointer<StringTable> stringTable);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::Session> m_session)
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<StringTable> m_stringTable)

			InnerDiagnosticInfo m_serviceDiagnostics;

			/*! Forbid use assignment operator */
			DataTransaction& operator=(const DataTransaction&);
			/*! Forbid use of copy constructor */
			DataTransaction(const DataTransaction&);
		};
		typedef ObjectPointer<DataTransaction> DataTransactionPtr;
		typedef ObjectPointer<const DataTransaction> DataTransactionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDATATRANSACTION_H
