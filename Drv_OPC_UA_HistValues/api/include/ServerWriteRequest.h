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

#ifndef SERVERWRITEREQUEST_H
#define SERVERWRITEREQUEST_H
#include "Base.h"
#include "Enums.h"
#include "InnerWriteValue.h"
#include "WriteValue.h"
#include "ServerDataRequest.h"
#include "DiagnosticInfo.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class BaseNode;
	}

	namespace Server
	{
		/*! The WriteRequest is part of a WriteTransaction and contains request information for one node and attribute.
		*
		* @see WriteTransaction */
		class TBC_EXPORT WriteRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			WriteRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			WriteRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~WriteRequest();

			/*! Returns an object that describes the item and the attribute that is to be written.
			*
			* For example, when a client wants to write the value of a variable, IWriteValue::getNodeId()
			* returns the NodeId of the variable, IWriteValue::getAttributeId() returns 'EnumAttributeId_Value'
			* and IWriteValue::getDataValue() returns the value that is to be written.
			*
			* @note	Please note that server applications need to verify whether the data type of the
			*		provided DataValue matches the data type of the attribute that is to be written. */
			const IWriteValue* getWriteValue();

			/*! Returns the node whose attribute is to be written. This could be a variable or
			* some other node type. */
			ObjectPointer<Server::BaseNode> getNode();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNode() const;

			/*! Returns whether the server application succeeded in processing the write request. This
			* value is returned to the client.
			*
			* @see setStatusCode() */
			EnumStatusCode getStatusCode() const;
			/*! Sets whether the server application succeeded in processing the write request. This
			* value is returned to the client. */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Returns diagnostic information provided for the Write request.
			*
			* @see setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the Write request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see WriteTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::BaseNode> m_node)

			InnerWriteValue m_writeValue;
			InnerDiagnosticInfo m_diagnosticInfo;

			/*! Requests are always created by the SDK core. */
			WriteRequest();
			/*! Forbid use assignment operator */
			WriteRequest& operator=(const WriteRequest&);
			/*! Forbid use of copy constructor */
			WriteRequest(const WriteRequest&);
		};
		typedef ObjectPointer<WriteRequest> WriteRequestPtr;
		typedef ObjectPointer<const WriteRequest> WriteRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERWRITEREQUEST_H
