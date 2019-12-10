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

#ifndef _ReaderGroupTransportDataTypeStruct_H_
#define _ReaderGroupTransportDataTypeStruct_H_

#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct ReaderGroupTransportDataTypeInt;

//lint -sem(ReaderGroupTransportDataTypeStruct::clear, cleanup)
//lint -sem(ReaderGroupTransportDataTypeStruct::init, initializer)
typedef struct TBCORE_IF ReaderGroupTransportDataTypeStruct
{
	ReaderGroupTransportDataTypeStruct();
	ReaderGroupTransportDataTypeStruct(const ReaderGroupTransportDataTypeStruct&);

	EnumDataTypeId getDataType() const;

	EnumStatusCode set(const ReaderGroupTransportDataTypeStruct&);
	EnumStatusCode get(ReaderGroupTransportDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExtensionObject& source);
	EnumStatusCode get(OpcUa_ExtensionObject& target) const;
#endif

	const ReaderGroupTransportDataTypeStruct& operator=(const ReaderGroupTransportDataTypeStruct& cp);
	bool operator==(const ReaderGroupTransportDataTypeStruct& toCompare) const;
	bool operator!=(const ReaderGroupTransportDataTypeStruct& toCompare) const;
	bool operator<(const ReaderGroupTransportDataTypeStruct& toCompare) const;
	bool operator>(const ReaderGroupTransportDataTypeStruct& toCompare) const;

	int compare(const ReaderGroupTransportDataTypeStruct* pTarget) const;

	void clear(void);
	~ReaderGroupTransportDataTypeStruct(void);

	ReaderGroupTransportDataTypeInt *getContent() const;
protected:
	// Internal object
	ReaderGroupTransportDataTypeInt *pContent;
	// Flag set in subclasses when the content is not owned
	bool bNoRelease;
} ReaderGroupTransportDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
