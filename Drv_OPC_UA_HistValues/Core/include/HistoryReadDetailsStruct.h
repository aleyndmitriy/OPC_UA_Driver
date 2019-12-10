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

#ifndef __HISTORYREADDETAILSSTRUCT_H_
#define __HISTORYREADDETAILSSTRUCT_H_
#if TB5_HISTORY

#include "Enums.h"
#include "ReadRawModifiedDetailsStruct.h"
#include "ReadProcessedDetailsStruct.h"
#include "ReadEventDetailsStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

enum EnumHistoryReadDetailsType
{
	EnumHistoryReadDetailsType_ReadEventDetails,
	EnumHistoryReadDetailsType_ReadRawModifiedDetails,
	EnumHistoryReadDetailsType_ReadProcessedDetails,
	EnumHistoryReadDetailsType_ReadAtTimeDetails
};

//lint -sem(HistoryReadDetailsStruct::clear, cleanup)
//lint -sem(HistoryReadDetailsStruct::init, initializer)
typedef struct TBCORE_IF HistoryReadDetailsStruct
{
	union
	{
		/*! This structure selects a set of values from the history database by specifying a time domain for one or more Variables */
		ReadRawModifiedDetailsStruct*	readRawModifiedDetails;
		ReadProcessedDetailsStruct*		readProcessedDetails;
		ReadEventDetailsStruct*			readEventDetails;
		// not supported yet: ReadAtTimeDetails* readAtTimeDetails;
	}
	historyReadDetails;

	EnumHistoryReadDetailsType historyReadDetailsType;

	HistoryReadDetailsStruct();
private:
	HistoryReadDetailsStruct(const HistoryReadDetailsStruct& cp);
public:
	EnumStatusCode set(const HistoryReadDetailsStruct&);
	EnumStatusCode get(HistoryReadDetailsStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExtensionObject& src);
	EnumStatusCode get(OpcUa_ExtensionObject& target, const std::vector<tstring>& preferredLocales) const;
#endif

	const HistoryReadDetailsStruct& operator=(const HistoryReadDetailsStruct& cp);
	bool operator==(const HistoryReadDetailsStruct& toCompare) const;
	bool operator!=(const HistoryReadDetailsStruct& toCompare) const;
	bool operator<(const HistoryReadDetailsStruct& toCompare) const;
	bool operator>(const HistoryReadDetailsStruct& toCompare) const;

	int compare(const HistoryReadDetailsStruct* pTarget) const;

	void clear(void);
	~HistoryReadDetailsStruct(void);

}HistoryReadDetailsStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif
