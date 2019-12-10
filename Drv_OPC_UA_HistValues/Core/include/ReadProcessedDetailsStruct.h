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

#ifndef _ReadProcessedDetailsStruct_H_
#define _ReadProcessedDetailsStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "DateTimeStruct.h"
#include "NodeIdStruct.h"
#include "AggregateConfigurationStruct.h"

/*! Specifies the details used to perform a 'processed' history read */
//lint -sem(ReadProcessedDetailsStruct::clear, cleanup)
//lint -sem(ReadProcessedDetailsStruct::init, initializer)
typedef struct TBCORE_IF ReadProcessedDetailsStruct
{
	/*! Beginning of period to read */
	DateTimeStruct startTime;

	/*! End of period to read */
	DateTimeStruct endTime;

	/*! Interval between returned Aggregate values. The value 0 indicates that there
	 * is no ProcessingInterval defined. */
	OTDouble processingInterval;

	/*! The NodeId of the HistoryAggregate object that indicates the list of Aggregates to
	 *  be used when retrieving processed history. See [UA Part 13] for details. */
	NodeIdStruct* pAggregateType;
	OTUInt32 aggregateType_count;

	/*! Aggregate configuration structure */
	AggregateConfigurationStruct aggregateConfiguration;

	ReadProcessedDetailsStruct();
	ReadProcessedDetailsStruct(const ReadProcessedDetailsStruct&);

	EnumStatusCode set(const ReadProcessedDetailsStruct&);
	EnumStatusCode get(ReadProcessedDetailsStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ReadProcessedDetails&);
	EnumStatusCode get(OpcUa_ReadProcessedDetails&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const ReadProcessedDetailsStruct& operator=(const ReadProcessedDetailsStruct& cp);
	bool operator==(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator!=(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator<(const ReadProcessedDetailsStruct& toCompare) const;
	bool operator>(const ReadProcessedDetailsStruct& toCompare) const;

	int compare(const ReadProcessedDetailsStruct* pTarget) const;

	void clear(void);
	~ReadProcessedDetailsStruct(void);
} ReadProcessedDetailsStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
