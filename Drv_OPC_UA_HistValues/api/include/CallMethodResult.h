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

#ifndef CALLMETHODRESULT_H
#define CALLMETHODRESULT_H

#include "ICallMethodResult.h"
#include "InnerValue.h"
#include "Value.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The CallMethodResult data type is used by the Call service (see Client::Session::callMethods())
	* to return a list of results for the called methods. */
	class TBC_EXPORT CallMethodResult
		: public ICallMethodResult
	{
	public:
		/*! Default constructor */
		CallMethodResult();
		/*! Constructs a copy of the given instance */
		CallMethodResult(const ICallMethodResult*);
		/*! @overload */
		CallMethodResult(const ICallMethodResult&);
		/*! @overload */
		CallMethodResult(const CallMethodResult&);

		/*! Destructor */
		virtual ~CallMethodResult();

		/*! Assigns the contents of @p cp to this instance */
		CallMethodResult& operator=(const ICallMethodResult*);
		/*! @overload */
		CallMethodResult& operator=(const ICallMethodResult&);
		/*! @overload */
		CallMethodResult& operator=(const CallMethodResult&);

		/* see ICallMethodResult::set */
		virtual EnumStatusCode set(const ICallMethodResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ICallMethodResult& pSrc);

		/* see ICallMethodResult::compare */
		virtual int compare(const ICallMethodResult*) const;
		/*! @overload */
		virtual int compare(const ICallMethodResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ICallMethodResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ICallMethodResult& other) const;

		/* see ICallMethodResult::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;

		/* see ICallMethodResult::getInputArgumentResults */
		virtual std::vector<EnumStatusCode> getInputArgumentResults() const;

		/* see ICallMethodResult::getInputArgumentDiagnosticInfos */
		virtual std::vector<DiagnosticInfo> getInputArgumentDiagnosticInfos() const;

		/* see ICallMethodResult::getOutputArgumentCount */
		virtual unsigned getOutputArgumentCount() const;
		/* see ICallMethodResult::getOutputArgument */
		virtual const IValue* getOutputArgument(unsigned index) const;
		/* see ICallMethodResult::getOutputArguments */
		virtual std::vector<Value> getOutputArguments() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDiagnosticInfo> m_pInputArgumentDiagnosticInfos)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_OutputArguments)
		CallMethodResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// CALLMETHODRESULT_H
