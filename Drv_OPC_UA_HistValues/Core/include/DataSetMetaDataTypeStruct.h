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

#ifndef DATASETMETADATATYPESTRUCT_H
#define DATASETMETADATATYPESTRUCT_H

#include "LocalizedTextStruct.h"
#include "FieldMetaDataStruct.h"
#include "GuidStruct.h"
#include "ConfigurationVersionDataTypeStruct.h"
#include "StructureDescriptionStruct.h"
#include "EnumDescriptionStruct.h"
#include "SimpleTypeDescriptionStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(DataSetMetaDataTypeStruct::clear, cleanup)
//lint -sem(DataSetMetaDataTypeStruct::init, initializer)
typedef struct TBCORE_IF DataSetMetaDataTypeStruct
{
	OTChar* pName;

	LocalizedTextStruct description;

	FieldMetaDataStruct* pFields;
	OTUInt32 fields_count;

	GuidStruct dataSetClassId;

	ConfigurationVersionDataTypeStruct configurationVersion;

	OTChar** pNamespaces;
	OTUInt32 namespaces_count;

	StructureDescriptionStruct* pStructureDataTypes;
	OTUInt32 structureDataTypes_count;

	EnumDescriptionStruct* pEnumDataTypes;
	OTUInt32 enumDataTypes_count;

	SimpleTypeDescriptionStruct* pSimpleDataTypes;
	OTUInt32 simpleDataTypes_count;


	DataSetMetaDataTypeStruct();
	DataSetMetaDataTypeStruct(const DataSetMetaDataTypeStruct&);

	EnumStatusCode set(const DataSetMetaDataTypeStruct&);
	EnumStatusCode get(DataSetMetaDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DataSetMetaDataType&);
	EnumStatusCode get(OpcUa_DataSetMetaDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const DataSetMetaDataTypeStruct& operator=(const DataSetMetaDataTypeStruct& cp);
	bool operator==(const DataSetMetaDataTypeStruct& toCompare) const;
	bool operator!=(const DataSetMetaDataTypeStruct& toCompare) const;
	bool operator<(const DataSetMetaDataTypeStruct& toCompare) const;
	bool operator>(const DataSetMetaDataTypeStruct& toCompare) const;

	int compare(const DataSetMetaDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear();
	~DataSetMetaDataTypeStruct();
} DataSetMetaDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATASETMETADATATYPESTRUCT_H
