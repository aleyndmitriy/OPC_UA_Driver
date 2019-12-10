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

#ifndef DATASETWRITERDATATYPESTRUCT_H
#define DATASETWRITERDATATYPESTRUCT_H

#include "Enums.h"
#include "KeyValuePairStruct.h"
#include "DataSetWriterTransportDataTypeStruct.h"
#include "DataSetWriterMessageDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(DataSetWriterDataTypeStruct::clear, cleanup)
//lint -sem(DataSetWriterDataTypeStruct::init, initializer)
typedef struct TBCORE_IF DataSetWriterDataTypeStruct
{
	OTChar* pName;

	OTBoolean enabled;

	OTUInt16 dataSetWriterId;

	EnumDataSetFieldContentMask dataSetFieldContentMask;

	OTUInt32 keyFrameCount;

	OTChar* pDataSetName;

	KeyValuePairStruct* pDataSetWriterProperties;
	OTUInt32 dataSetWriterProperties_count;

	DataSetWriterTransportDataTypeStruct transportSettings;

	DataSetWriterMessageDataTypeStruct messageSettings;


	DataSetWriterDataTypeStruct();
	DataSetWriterDataTypeStruct(const DataSetWriterDataTypeStruct&);

	EnumStatusCode set(const DataSetWriterDataTypeStruct&);
	EnumStatusCode get(DataSetWriterDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DataSetWriterDataType&);
	EnumStatusCode get(OpcUa_DataSetWriterDataType&, const std::vector<tstring>&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>&) const;
#endif

	const DataSetWriterDataTypeStruct& operator=(const DataSetWriterDataTypeStruct& cp);
	bool operator==(const DataSetWriterDataTypeStruct& toCompare) const;
	bool operator!=(const DataSetWriterDataTypeStruct& toCompare) const;
	bool operator<(const DataSetWriterDataTypeStruct& toCompare) const;
	bool operator>(const DataSetWriterDataTypeStruct& toCompare) const;

	int compare(const DataSetWriterDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear();
	~DataSetWriterDataTypeStruct();
} DataSetWriterDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATASETWRITERDATATYPESTRUCT_H
