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

#ifndef _FieldMetaDataStruct_H_
#define _FieldMetaDataStruct_H_

#include "LocalizedTextStruct.h"
#include "Enums.h"
#include "NodeIdStruct.h"
#include "GuidStruct.h"
#include "KeyValuePairStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(FieldMetaDataStruct::clear, cleanup)
//lint -sem(FieldMetaDataStruct::init, initializer)
typedef struct TBCORE_IF FieldMetaDataStruct
{
	OTChar* pName;

	LocalizedTextStruct description;

	EnumDataSetFieldFlags fieldFlags;

	OTUInt8 builtInType;

	NodeIdStruct dataType;

	OTInt32 valueRank;

	OTUInt32* pArrayDimensions;
	OTUInt32 arrayDimensions_count;

	OTUInt32 maxStringLength;

	GuidStruct dataSetFieldId;

	KeyValuePairStruct* pProperties;
	OTUInt32 properties_count;


	FieldMetaDataStruct();
	FieldMetaDataStruct(const FieldMetaDataStruct&);

	EnumStatusCode set(const FieldMetaDataStruct&);
	EnumStatusCode get(FieldMetaDataStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_FieldMetaData&);
	EnumStatusCode get(OpcUa_FieldMetaData&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const FieldMetaDataStruct& operator=(const FieldMetaDataStruct& cp);
	bool operator==(const FieldMetaDataStruct& toCompare) const;
	bool operator!=(const FieldMetaDataStruct& toCompare) const;
	bool operator<(const FieldMetaDataStruct& toCompare) const;
	bool operator>(const FieldMetaDataStruct& toCompare) const;

	int compare(const FieldMetaDataStruct* pTarget) const;

	void clear(void);
	~FieldMetaDataStruct(void);
} FieldMetaDataStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
