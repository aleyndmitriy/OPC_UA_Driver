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

#ifndef __HISTORYDATAEXTENSIONOBJECTSTRUCT_H_
#define __HISTORYDATAEXTENSIONOBJECTSTRUCT_H_
#if TB5_HISTORY

#include "Enums.h"
#include "HistoryDataStruct.h"
#include "HistoryEventStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

enum EnumHistoryDataType
{
	EnumHistoryDataType_HistoryData = 0,
	EnumHistoryDataType_HistoryModifiedData = 1,
	EnumHistoryDataType_HistoryEvent = 2
};

//lint -sem(HistoryDataExtensionObjectStruct::clear, cleanup)
//lint -sem(HistoryDataExtensionObjectStruct::init, initializer)
typedef struct TBCORE_IF HistoryDataExtensionObjectStruct
{
	union
	{
		HistoryDataStruct* historyData;
		HistoryEventStruct* historyEvent;
		// not supported yet: HistoryModifiedDataStruct* historyModifiedData
	}
	;

	EnumHistoryDataType historyDataType;

	HistoryDataExtensionObjectStruct();

	EnumStatusCode init(EnumHistoryDataType hDataType);

	EnumStatusCode set(const HistoryDataExtensionObjectStruct&);
	EnumStatusCode get(HistoryDataExtensionObjectStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExtensionObject& src, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_ExtensionObject& target, const std::vector<tstring>& preferredLocales) const;
#endif

	const HistoryDataExtensionObjectStruct& operator=(const HistoryDataExtensionObjectStruct& cp);
	bool operator==(const HistoryDataExtensionObjectStruct& toCompare) const;
	bool operator!=(const HistoryDataExtensionObjectStruct& toCompare) const;
	bool operator<(const HistoryDataExtensionObjectStruct& toCompare) const;
	bool operator>(const HistoryDataExtensionObjectStruct& toCompare) const;

	int compare(const HistoryDataExtensionObjectStruct* pTarget) const;

	void clear(void);
	~HistoryDataExtensionObjectStruct(void);

}HistoryDataExtensionObjectStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
