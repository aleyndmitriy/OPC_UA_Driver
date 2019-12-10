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

#ifndef _ReadEventDetailsStruct_H_
#define _ReadEventDetailsStruct_H_
#if TB5_HISTORY
#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"
#include "EventFilterStruct.h"

//lint -sem(ReadEventDetailsStruct::clear, cleanup)
//lint -sem(ReadEventDetailsStruct::init, initializer)
typedef struct TBCORE_IF ReadEventDetailsStruct
{
	/*! The maximum number of values returned for any node over the time range.
	* If only one time is specified, the time range must extend to return this number of values.
	* The default value of 0 indicates that there is no maximum. */
	OTUInt32 numValuesPerNode;

	/*! Beginning of period to read. The default value of DateTime.MinValue indicates
	* that the startTime is unspecified. */
	DateTimeStruct startTime;

	/*! End of period to read. The default value of DateTime.MinValue indicates
	* that the endTime is Unspecified. */
	DateTimeStruct endTime;

	/*! A filter used by the server to determine which historical events should be included.
	* This parameter must be specified and at least one EventField is required. */
	EventFilterStruct filter;


	ReadEventDetailsStruct();
	ReadEventDetailsStruct(const ReadEventDetailsStruct&);

	EnumStatusCode set(const ReadEventDetailsStruct&);
	EnumStatusCode get(ReadEventDetailsStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ReadEventDetails&);
	EnumStatusCode get(OpcUa_ReadEventDetails&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const ReadEventDetailsStruct& operator=(const ReadEventDetailsStruct& cp);
	bool operator==(const ReadEventDetailsStruct& toCompare) const;
	bool operator!=(const ReadEventDetailsStruct& toCompare) const;
	bool operator<(const ReadEventDetailsStruct& toCompare) const;
	bool operator>(const ReadEventDetailsStruct& toCompare) const;

	int compare(const ReadEventDetailsStruct* pTarget) const;

	void clear(void);
	~ReadEventDetailsStruct(void);
} ReadEventDetailsStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
