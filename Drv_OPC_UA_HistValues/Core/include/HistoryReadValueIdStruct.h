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

#ifndef __HISTORYREADVALUEIDSTRUCT_H_
#define __HISTORYREADVALUEIDSTRUCT_H_
#if TB5_HISTORY

#include "NodeIdStruct.h"
#include "NumericRangeStruct.h"
#include "QualifiedNameStruct.h"
#include "ByteStringStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(HistoryReadValueIdStruct::clear, cleanup)
//lint -sem(HistoryReadValueIdStruct::init, initializer)
typedef struct TBCORE_IF HistoryReadValueIdStruct
{
	/*! The nodeId of the Nodes whose historical values are to be read. */
	NodeIdStruct nodeId;

	/*! This parameter is used to identify a single element of an array, or a single range of indexes for arrays. */
	NumericRangeStruct indexRange;

	/*! A QualifiedName that specifies the data encoding to be returned for the Value to be read */
	QualifiedNameStruct dataEncoding;

	/*!
	 *  For each NodeToRead this parameter specifies a continuation point returned from a previous HistoryRead call,
	 *  allowing the Client to continue that read from the last value received.
	 */
	ByteStringStruct continuationPoint;

	HistoryReadValueIdStruct();

	EnumStatusCode set(const HistoryReadValueIdStruct&);
	EnumStatusCode get(HistoryReadValueIdStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_HistoryReadValueId&);
	EnumStatusCode get(OpcUa_HistoryReadValueId&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const HistoryReadValueIdStruct& operator=(const HistoryReadValueIdStruct& cp);
	bool operator==(const HistoryReadValueIdStruct& toCompare) const;
	bool operator!=(const HistoryReadValueIdStruct& toCompare) const;
	bool operator<(const HistoryReadValueIdStruct& toCompare) const;
	bool operator>(const HistoryReadValueIdStruct& toCompare) const;

	int compare(const HistoryReadValueIdStruct* pTarget) const;

	void clear(void);
	~HistoryReadValueIdStruct(void);

}HistoryReadValueIdStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
