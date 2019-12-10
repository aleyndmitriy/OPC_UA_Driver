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

#ifndef DATASETREADERDATATYPESTRUCT_H
#define DATASETREADERDATATYPESTRUCT_H

#include "ValueStruct.h"
#include "DataSetMetaDataTypeStruct.h"
#include "Enums.h"
#include "EndpointDescriptionStruct.h"
#include "KeyValuePairStruct.h"
#include "DataSetReaderTransportDataTypeStruct.h"
#include "DataSetReaderMessageDataTypeStruct.h"
#include "SubscribedDataSetDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(DataSetReaderDataTypeStruct::clear, cleanup)
//lint -sem(DataSetReaderDataTypeStruct::init, initializer)
typedef struct TBCORE_IF DataSetReaderDataTypeStruct
{
	OTChar* pName;

	OTBoolean enabled;

	ValueStruct publisherId;

	OTUInt16 writerGroupId;

	OTUInt16 dataSetWriterId;

	DataSetMetaDataTypeStruct dataSetMetaData;

	EnumDataSetFieldContentMask dataSetFieldContentMask;

	OTDouble messageReceiveTimeout;

	EnumMessageSecurityMode securityMode;

	OTChar* pSecurityGroupId;

	EndpointDescriptionStruct* pSecurityKeyServices;
	OTUInt32 securityKeyServices_count;

	KeyValuePairStruct* pDataSetReaderProperties;
	OTUInt32 dataSetReaderProperties_count;

	DataSetReaderTransportDataTypeStruct transportSettings;

	DataSetReaderMessageDataTypeStruct messageSettings;

	SubscribedDataSetDataTypeStruct subscribedDataSet;


	DataSetReaderDataTypeStruct();
	DataSetReaderDataTypeStruct(const DataSetReaderDataTypeStruct&);

	EnumStatusCode set(const DataSetReaderDataTypeStruct&);
	EnumStatusCode get(DataSetReaderDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DataSetReaderDataType&);
	EnumStatusCode get(OpcUa_DataSetReaderDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const DataSetReaderDataTypeStruct& operator=(const DataSetReaderDataTypeStruct& cp);
	bool operator==(const DataSetReaderDataTypeStruct& toCompare) const;
	bool operator!=(const DataSetReaderDataTypeStruct& toCompare) const;
	bool operator<(const DataSetReaderDataTypeStruct& toCompare) const;
	bool operator>(const DataSetReaderDataTypeStruct& toCompare) const;

	int compare(const DataSetReaderDataTypeStruct* pTarget) const;
	
	tstring toString() const;

	void clear();
	~DataSetReaderDataTypeStruct();
} DataSetReaderDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATASETREADERDATATYPESTRUCT_H
