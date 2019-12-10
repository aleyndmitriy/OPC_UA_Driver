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

#ifndef IPARSINGRESULT_H
#define IPARSINGRESULT_H

#include "ParsingResultStruct.h"
#include "DiagnosticInfo.h"

namespace SoftingOPCToolbox5
{
	/*! The ParsingResult data type is used by the QueryFirst service (see Client::Session::queryFirst())
	* to describe the parsing result for one NodeTypeDescription. */
	class TBC_EXPORT IParsingResult
	{
	public:
		/*! Destructor */
		virtual ~IParsingResult(){};

		/*! Returns the parsing result for the NodeTypeDescription provided with the QueryFirst service call. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Sets the parsing result for the NodeTypeDescription provided with the QueryFirst service call. */
		virtual void setStatusCode(const EnumStatusCode& value) = 0;

		/*! Returns a list of results for the "DataToReturn" parameter of
		* the NodeTypeDescription provided with the QueryFirst service call.
		*
		* The size and order of the list matches the size and order of the
		* QueryDataDescription elements provided with the "DataToReturn" parameter.
		* The vector can be empty if no errors where encountered. */
		virtual std::vector<EnumStatusCode> getDataStatusCodes() const = 0;
		/*! Sets the list of results for the "DataToReturn" parameter of
		* the NodeTypeDescription provided with the QueryFirst service call.
		*
		* @see setDataStatusCodes() */
		virtual EnumStatusCode setDataStatusCodes(const std::vector<EnumStatusCode>& values) = 0;

		/*! Returns a list of diagnostic information for the "DataToReturn" parameter of
		* the NodeTypeDescription provided with the QueryFirst service call.
		*
		* The size and order of the list matches the size and order of the
		* QueryDataDescription elements provided with the "DataToReturn" parameter.
		* The vector can be empty if no diagnostic information was encountered in
		* processing the request. */
		virtual std::vector<DiagnosticInfo> getDataDiagnosticInfos() const = 0;
		/*! Adds an entry to the list of diagnostic information for the "DataToReturn" parameter of
		* the NodeTypeDescription provided with the QueryFirst service call.
		*
		* The size and order of the list matches the size and order of the
		* QueryDataDescription elements provided with the "DataToReturn" parameter.
		* The vector can be empty if no diagnostic information was encountered in
		* processing the request. */
		virtual EnumStatusCode addDataDiagnosticInfo(const IDiagnosticInfo* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IParsingResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IParsingResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IParsingResult* other) const = 0;
		/*! @overload */
		virtual int compare(const IParsingResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IParsingResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IParsingResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IParsingResult
} // end namespace

#endif	// IPARSINGRESULT_H
