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

#ifndef __EVENTFILTERSTRUCT_H_
#define __EVENTFILTERSTRUCT_H_
#if TB5_ALARMS
#include "SimpleAttributeOperandStruct.h"
#include "ContentFilterStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Class that stores the filtering options for an event. */
//lint -sem(EventFilterStruct::clear, cleanup)
//lint -sem(EventFilterStruct::init, initializer)
typedef struct TBCORE_IF EventFilterStruct
{
	OTUInt32 selectClauses_count;
	SimpleAttributeOperandStruct* pSelectClauses;

	ContentFilterStruct whereClause;

	EventFilterStruct();
	EnumStatusCode addSelectClause(const SimpleAttributeOperandStruct* pSimpleAttributeOperand);

	EnumStatusCode set(const EventFilterStruct&);
	EnumStatusCode get(EventFilterStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_EventFilter&);
	EnumStatusCode get(OpcUa_EventFilter&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const EventFilterStruct& operator=(const EventFilterStruct& cp);
	bool operator==(const EventFilterStruct& toCompare) const;
	bool operator!=(const EventFilterStruct& toCompare) const;
	bool operator<(const EventFilterStruct& toCompare) const;
	bool operator>(const EventFilterStruct& toCompare) const;

	int compare(const EventFilterStruct* pTarget) const;

	void clear(void);
	~EventFilterStruct(void);

}EventFilterStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
