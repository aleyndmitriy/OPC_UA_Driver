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

#ifndef _DataTypeDescriptionStruct_H_
#define _DataTypeDescriptionStruct_H_

#include "NodeIdStruct.h"
#include "QualifiedNameStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(DataTypeDescriptionStruct::clear, cleanup)
//lint -sem(DataTypeDescriptionStruct::init, initializer)
typedef struct TBCORE_IF DataTypeDescriptionStruct
{
	NodeIdStruct dataTypeId;

	QualifiedNameStruct name;


	DataTypeDescriptionStruct();
	DataTypeDescriptionStruct(const DataTypeDescriptionStruct&);

	EnumStatusCode set(const DataTypeDescriptionStruct&);
	EnumStatusCode get(DataTypeDescriptionStruct&) const;

	const DataTypeDescriptionStruct& operator=(const DataTypeDescriptionStruct& cp);
	bool operator==(const DataTypeDescriptionStruct& toCompare) const;
	bool operator!=(const DataTypeDescriptionStruct& toCompare) const;
	bool operator<(const DataTypeDescriptionStruct& toCompare) const;
	bool operator>(const DataTypeDescriptionStruct& toCompare) const;

	int compare(const DataTypeDescriptionStruct* pTarget) const;

	void clear(void);
	~DataTypeDescriptionStruct(void);
} DataTypeDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
