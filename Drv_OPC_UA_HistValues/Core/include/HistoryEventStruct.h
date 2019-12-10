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

#ifndef _HistoryEventStruct_H_
#define _HistoryEventStruct_H_
#if TB5_HISTORY

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "HistoryEventFieldListStruct.h"

//lint -sem(HistoryEventStruct::clear, cleanup)
//lint -sem(HistoryEventStruct::init, initializer)
typedef struct TBCORE_IF HistoryEventStruct
{
	/*! The list of historical events */
	HistoryEventFieldListStruct* pEvents;
	unsigned pEvents_count;


	HistoryEventStruct();
	HistoryEventStruct(const HistoryEventStruct&);

	EnumStatusCode set(const HistoryEventStruct&);
	EnumStatusCode get(HistoryEventStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_HistoryEvent&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_HistoryEvent&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const HistoryEventStruct& operator=(const HistoryEventStruct& cp);
	bool operator==(const HistoryEventStruct& toCompare) const;
	bool operator!=(const HistoryEventStruct& toCompare) const;
	bool operator<(const HistoryEventStruct& toCompare) const;
	bool operator>(const HistoryEventStruct& toCompare) const;

	int compare(const HistoryEventStruct* pTarget) const;

	void clear(void);
	~HistoryEventStruct(void);
} HistoryEventStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
