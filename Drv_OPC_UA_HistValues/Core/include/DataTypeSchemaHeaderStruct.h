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

#ifndef DATATYPESCHEMAHEADERSTRUCT_H
#define DATATYPESCHEMAHEADERSTRUCT_H

#include "StructureDescriptionStruct.h"
#include "EnumDescriptionStruct.h"
#include "SimpleTypeDescriptionStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(DataTypeSchemaHeaderStruct::clear, cleanup)
//lint -sem(DataTypeSchemaHeaderStruct::init, initializer)
typedef struct TBCORE_IF DataTypeSchemaHeaderStruct
{
	OTChar** pNamespaces;
	OTUInt32 namespaces_count;

	StructureDescriptionStruct* pStructureDataTypes;
	OTUInt32 structureDataTypes_count;

	EnumDescriptionStruct* pEnumDataTypes;
	OTUInt32 enumDataTypes_count;

	SimpleTypeDescriptionStruct* pSimpleDataTypes;
	OTUInt32 simpleDataTypes_count;


	DataTypeSchemaHeaderStruct();
	DataTypeSchemaHeaderStruct(const DataTypeSchemaHeaderStruct&);

	EnumStatusCode set(const DataTypeSchemaHeaderStruct&);
	EnumStatusCode get(DataTypeSchemaHeaderStruct&) const;

	const DataTypeSchemaHeaderStruct& operator=(const DataTypeSchemaHeaderStruct& cp);
	bool operator==(const DataTypeSchemaHeaderStruct& toCompare) const;
	bool operator!=(const DataTypeSchemaHeaderStruct& toCompare) const;
	bool operator<(const DataTypeSchemaHeaderStruct& toCompare) const;
	bool operator>(const DataTypeSchemaHeaderStruct& toCompare) const;

	int compare(const DataTypeSchemaHeaderStruct* pTarget) const;

	void clear();
	~DataTypeSchemaHeaderStruct();
} DataTypeSchemaHeaderStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATATYPESCHEMAHEADERSTRUCT_H
