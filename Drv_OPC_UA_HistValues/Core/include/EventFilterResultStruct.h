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

#ifndef _EventFilterResultStruct_H_
#define _EventFilterResultStruct_H_
#if TB5_ALARMS

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "Enums.h"
#include "DiagnosticInfoStruct.h"
#include "ContentFilterResultStruct.h"

//lint -sem(EventFilterResultStruct::clear, cleanup)
//lint -sem(EventFilterResultStruct::init, initializer)
#ifdef OT_COMPILATION
typedef struct EventFilterResultStruct
{
	/*! List of status codes for the elements in the select clause. The size and
	* order of the list matches the size and order of the elements in the
	* selectClauses request parameter. The Server returns null for unavailable
	* or rejected Event fields. */
	EnumStatusCode* pSelectClauseResults;
	unsigned pSelectClauseResults_count;

	/*! A list of diagnostic information for individual elements in the select clause.
	* The size and order of the list matches the size and order of the elements
	* in the selectClauses request parameter. This list is empty if diagnostics
	* information was not requested in the request header or if no diagnostic
	* information was encountered in processing of the select clauses. */
	DiagnosticInfoStruct* pSelectClauseDiagnosticInfos;
	unsigned pSelectClauseDiagnosticInfos_count;

	/*! results associated with the whereClause request parameter. */
	ContentFilterResultStruct whereClauseResult;


	EventFilterResultStruct();
	EventFilterResultStruct(const EventFilterResultStruct&);

	EnumStatusCode set(const EventFilterResultStruct&);
	EnumStatusCode get(EventFilterResultStruct&) const;

	EnumStatusCode set(const OpcUa_EventFilterResult&);
	EnumStatusCode get(OpcUa_EventFilterResult&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;

	const EventFilterResultStruct& operator=(const EventFilterResultStruct& cp);
	bool operator==(const EventFilterResultStruct& toCompare) const;
	bool operator!=(const EventFilterResultStruct& toCompare) const;
	bool operator<(const EventFilterResultStruct& toCompare) const;
	bool operator>(const EventFilterResultStruct& toCompare) const;

	int compare(const EventFilterResultStruct* pTarget) const;

	void clear(void);
	~EventFilterResultStruct(void);
} EventFilterResultStruct;
#endif

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
