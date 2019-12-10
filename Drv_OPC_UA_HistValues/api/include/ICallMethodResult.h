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

#ifndef ICALLMETHODRESULT_H
#define ICALLMETHODRESULT_H

#include "CallMethodResultStruct.h"
#include "InnerValue.h"
#include "Value.h"
#include "DiagnosticInfo.h"
#include "InnerDiagnosticInfo.h"

namespace SoftingOPCToolbox5
{
	/*! The CallMethodResult data type is used by the Call service (see Client::Session::callMethods())
	* to return a list of results for the called methods. */
	class TBC_EXPORT ICallMethodResult
	{
	public:
		/*! Destructor */
		virtual ~ICallMethodResult(){};

		/*! Returns a status code for the method execution on the server.
		* If at least one of the arguments did not meet the method's constraints (wrong data type, ...),
		* the status code EnumStatusCode_BadInvalidArgument is returned. */
		virtual EnumStatusCode getStatusCode() const = 0;

		/*! Returns a list of status code for the provided input arguments (see CallMethodRequest::getInputArguments()). */
		virtual std::vector<EnumStatusCode> getInputArgumentResults() const = 0;

		/*! Returns diagnostic information that has been provided for each input argument
		* of the called method. This list is empty if diagnostics information was not requested in the request
		* or if no diagnostic information was encountered in processing of the request.
		*
		* @see Client::Session::callMethods() addInputArgumentDiagnosticInfo() */
		virtual std::vector<DiagnosticInfo> getInputArgumentDiagnosticInfos() const = 0;

		/*! The methods getOutputArgumentCount() and getOutputArgument() are provided for efficient access to data.
		* The semantics of these methods are documented in getOutputArguments(). */
		virtual unsigned getOutputArgumentCount() const = 0;
		/*! The methods getOutputArgumentCount() and getOutputArgument() are provided for efficient access to data.
		* The semantics of these methods are documented in getOutputArguments(). */
		virtual const IValue* getOutputArgument(unsigned index) const = 0;
		/*! Returns a list of output argument values. An empty list indicates that there are no output arguments.
		*
		* The size and order of this list matches the size and order of the output arguments defined by the OutputArguments
		* property of the method. */
		virtual std::vector<Value> getOutputArguments() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ICallMethodResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ICallMethodResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ICallMethodResult* other) const = 0;
		/*! @overload */
		virtual int compare(const ICallMethodResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ICallMethodResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ICallMethodResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ICallMethodResult
} // end namespace
#endif	// ICALLMETHODRESULT_H
