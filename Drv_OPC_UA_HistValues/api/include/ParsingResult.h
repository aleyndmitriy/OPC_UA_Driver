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

#ifndef PARSINGRESULT_H
#define PARSINGRESULT_H

#include "IParsingResult.h"
#include "DiagnosticInfo.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ParsingResult data type is used by the QueryFirst service (see Client::Session::queryFirst())
	* to describe the parsing result for one NodeTypeDescription. */
	class TBC_EXPORT ParsingResult
		: public IParsingResult
	{
	public:
		/*! Default constructor */
		ParsingResult();
		/*! Constructs a copy of the given instance */
		ParsingResult(const IParsingResult*);
		/*! @overload */
		ParsingResult(const IParsingResult&);
		/*! @overload */
		ParsingResult(const ParsingResult&);

		/*! Destructor */
		virtual ~ParsingResult();

		/*! Assigns the contents of @p cp to this instance */
		ParsingResult& operator=(const IParsingResult* cp);
		/*! @overload */
		ParsingResult& operator=(const IParsingResult& cp);
		/*! @overload */
		ParsingResult& operator=(const ParsingResult& cp);

		/* see IParsingResult::set */
		virtual EnumStatusCode set(const IParsingResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IParsingResult& pSrc);

		/* see IParsingResult::compare */
		virtual int compare(const IParsingResult*) const;
		/*! @overload */
		virtual int compare(const IParsingResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IParsingResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IParsingResult& other) const;

		/* see IParsingResult::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;
		/* see IParsingResult::setStatusCode */
		virtual void setStatusCode(const EnumStatusCode& value);

		/* see IParsingResult::getDataStatusCodes */
		virtual std::vector<EnumStatusCode> getDataStatusCodes() const;
		/* see IParsingResult::setDataStatusCodes */
		virtual EnumStatusCode setDataStatusCodes(const std::vector<EnumStatusCode>& values);

		/* see IParsingResult::getDataDiagnosticInfos */
		virtual std::vector<DiagnosticInfo> getDataDiagnosticInfos() const;
		/* see IParsingResult::addDataDiagnosticInfo */
		virtual EnumStatusCode addDataDiagnosticInfo(const IDiagnosticInfo* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDiagnosticInfo> m_pDataDiagnosticInfos)
		ParsingResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// PARSINGRESULT_H
