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

#ifndef _PublishedDataSetDataTypeStruct_H_
#define _PublishedDataSetDataTypeStruct_H_

#include "DataSetMetaDataTypeStruct.h"
#include "KeyValuePairStruct.h"
#include "PublishedDataSetSourceDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(PublishedDataSetDataTypeStruct::clear, cleanup)
//lint -sem(PublishedDataSetDataTypeStruct::init, initializer)
typedef struct TBCORE_IF PublishedDataSetDataTypeStruct
{
	OTChar* pName;

	OTChar** ppDataSetFolder;
	OTUInt32 dataSetFolder_count;

	DataSetMetaDataTypeStruct dataSetMetaData;

	KeyValuePairStruct* pExtensionFields;
	OTUInt32 extensionFields_count;

	PublishedDataSetSourceDataTypeStruct dataSetSource;


	PublishedDataSetDataTypeStruct();
	PublishedDataSetDataTypeStruct(const PublishedDataSetDataTypeStruct&);

	EnumStatusCode set(const PublishedDataSetDataTypeStruct&);
	EnumStatusCode get(PublishedDataSetDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PublishedDataSetDataType&);
	EnumStatusCode get(OpcUa_PublishedDataSetDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const PublishedDataSetDataTypeStruct& operator=(const PublishedDataSetDataTypeStruct& cp);
	bool operator==(const PublishedDataSetDataTypeStruct& toCompare) const;
	bool operator!=(const PublishedDataSetDataTypeStruct& toCompare) const;
	bool operator<(const PublishedDataSetDataTypeStruct& toCompare) const;
	bool operator>(const PublishedDataSetDataTypeStruct& toCompare) const;

	int compare(const PublishedDataSetDataTypeStruct* pTarget) const;

	void clear(void);
	~PublishedDataSetDataTypeStruct(void);
} PublishedDataSetDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
