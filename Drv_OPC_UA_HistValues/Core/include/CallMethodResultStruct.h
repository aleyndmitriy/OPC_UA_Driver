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

#ifndef __CALLMETHODRESULTSTRUCT_H_
#define __CALLMETHODRESULTSTRUCT_H_

#include "ValueStruct.h"
#include "DiagnosticInfoStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

//lint -sem(CallMethodResultStruct::clear, cleanup)
//lint -sem(CallMethodResultStruct::init, initializer)
typedef struct TBCORE_IF CallMethodResultStruct
{
	unsigned pInputArgumentResults_count;
	EnumStatusCode* pInputArgumentResults;

	unsigned pOutputArguments_count;
	ValueStruct* pOutputArguments;

	EnumStatusCode statusCode;

	DiagnosticInfoStruct* pInputArgumentDiagnosticInfos;
	unsigned pInputArgumentDiagnosticInfos_count;

	CallMethodResultStruct();
	EnumStatusCode getInputArgumentResults(unsigned* pCount, EnumStatusCode** ppValues);
	EnumStatusCode setOutputArguments(unsigned OutputArgumentsCount, const ValueStruct* OutputArguments);

	EnumStatusCode set(const CallMethodResultStruct&);
	EnumStatusCode get(CallMethodResultStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_CallMethodResult&);
	EnumStatusCode get(OpcUa_CallMethodResult&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const CallMethodResultStruct& operator=(const CallMethodResultStruct& cp);
	bool operator==(const CallMethodResultStruct& toCompare) const;
	bool operator!=(const CallMethodResultStruct& toCompare) const;
	bool operator<(const CallMethodResultStruct& toCompare) const;
	bool operator>(const CallMethodResultStruct& toCompare) const;

	int compare(const CallMethodResultStruct* pTarget) const;

	void clear(void);
	~CallMethodResultStruct(void);

}CallMethodResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
