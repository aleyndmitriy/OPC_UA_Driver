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

#ifndef SERVERREADREQUEST_H
#define SERVERREADREQUEST_H
#include "Base.h"
#include "Enums.h"
#include "InnerReadValueId.h"
#include "ReadValueId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "ServerDataRequest.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"
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
		/*! The ReadRequest is part of a ReadTransaction and contains request information for one node and attribute.
		*
		* @see ReadTransaction */
		class TBC_EXPORT ReadRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ReadRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			ReadRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ReadRequest();

			/*! Returns an object that describes the item and the attribute that is to be read.
			*
			* For example, when a client wants to read the value of a variable, IReadValueId::getNodeId()
			* returns the NodeId of the variable and IReadValueId::getAttributeId() returns 'EnumAttributeId_Value'. */
			const IReadValueId* getValueId() const;

			/*! Returns the value that is returned to the client.
			* A server application has to use setDataValue() to provide the client the read value.
			*
			* @see setDataValue() */
			const IDataValue* getDataValue() const;
			/*! Sets the value that is returned to the client.
			*
			* A server application has to use this method to provide the client the read value. */
			EnumStatusCode setDataValue(const IDataValue* dataValue);
			/*! @overload */
			EnumStatusCode setDataValue(const IDataValue& dataValue);

			/*! Returns the node whose attribute is to be read. This could be a variable or
			* some other node type. */
			ObjectPointer<Server::BaseNode> getNode();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNode() const;

			/*! Returns diagnostic information provided for the read request.
			*
			* @see setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the read request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see ReadTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::BaseNode> m_node)

			InnerReadValueId m_valueId;
			InnerDataValue m_dataValue;
			InnerDiagnosticInfo m_diagnosticInfo;

			/*! Requests are always created by the SDK core. */
			ReadRequest();
			/*! Forbid use assignment operator */
			ReadRequest& operator=(const ReadRequest&);
			/*! Forbid use of copy constructor */
			ReadRequest(const ReadRequest&);
		};
		typedef ObjectPointer<ReadRequest> ReadRequestPtr;
		typedef ObjectPointer<const ReadRequest> ReadRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERREADREQUEST_H
