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

#ifndef SERVERMETHODCALLREQUEST_H
#define SERVERMETHODCALLREQUEST_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerValue.h"
#include "Value.h"
#include "ServerDataRequest.h"
#include "DiagnosticInfo.h"
#include "InnerDiagnosticInfo.h"
#include "IDiagnosticInfo.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The MethodCallRequest is part of a MethodCallTransaction and contains
		* request information for one method.
		*
		* @see MethodCallTransaction */
		class TBC_EXPORT MethodCallRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			MethodCallRequest(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			MethodCallRequest(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~MethodCallRequest();

			/*! Returns the NodeId of the object on which the method is called. */
			const INodeId* getObjectId() const;

			/*! Returns The NodeId of the method that is to be called. */
			const INodeId* getMethodId() const;

			/*! Returns the input arguments for the method that have been provided by the client. */
			std::vector<Value> getInputArguments() const;

			/*! Returns the status code of the current request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code of the current request. */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

			/*! Sets the validation results for the input arguments that have been provided by the client. */
			EnumStatusCode setInputArgumentResults(const std::vector<EnumStatusCode>& inputArgumentResults);

			/*! Sets the output arguments for the method that are to be delivered to the client. */
			EnumStatusCode setOutputArguments(const std::vector<Value>& outputArguments);

			/*! Sets vendor-specific diagnostic information for the input arguments (see getInputArguments()).
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfos	The request-specific diagnostic information. The number
			*							of provided diagnostic infos must match the number of
			*							provided input arguments.
			*
			* @see getInputArguments()
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see MethodCallTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setInputArgumentDiagnosticInfos(const std::vector<DiagnosticInfo>& diagnosticInfos);

			/*! Returns diagnostic information provided for the MethodCall request.
			*
			* @see setDiagnosticInfo() */
			const IDiagnosticInfo* getDiagnosticInfo() const;
			/*! Sets vendor-specific diagnostic information for the MethodCall request.
			* The diagnostic information can be omitted if no diagnostic information was encountered
			* during processing of the request.
			*
			* @param diagnosticInfo	The request-specific diagnostic information
			*
			* @note	Server applications should only return that kind of diagnostic information
			*		that has been requested by the client (see MethodCallTransaction::getDiagnosticsToReturn()). */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* diagnosticInfo);
			/*! @overload */
			EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo& diagnosticInfo);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			// attribute member objectId
			InnerNodeId m_objectId;
			// attribute member methodId
			InnerNodeId m_methodId;
			// attribute member inputArguments
			InnerValue m_inputArguments;
			// attribute member outputArguments
			InnerValue m_outputArguments;
			// attribute member diagnosticInfo
			InnerDiagnosticInfo m_diagnosticInfo;

			/*! Forbid use assignment operator */
			MethodCallRequest& operator=(const MethodCallRequest&);
			/*! Forbid use of copy constructor */
			MethodCallRequest(const MethodCallRequest&);

			// Requests are always created by the SDK core.
			MethodCallRequest();
		};
		typedef ObjectPointer<MethodCallRequest> MethodCallRequestPtr;
		typedef ObjectPointer<const MethodCallRequest> MethodCallRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERMETHODCALLREQUEST_H
