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

#ifndef _PublishedVariableDataTypeStruct_H_
#define _PublishedVariableDataTypeStruct_H_

#include "NodeIdStruct.h"
#include "NumericRangeStruct.h"
#include "ValueStruct.h"
#include "QualifiedNameStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(PublishedVariableDataTypeStruct::clear, cleanup)
//lint -sem(PublishedVariableDataTypeStruct::init, initializer)
typedef struct TBCORE_IF PublishedVariableDataTypeStruct
{
	NodeIdStruct publishedVariable;

	EnumAttributeId attributeId;

	OTDouble samplingIntervalHint;

	EnumDeadbandType deadbandType;

	OTDouble deadbandValue;

	NumericRangeStruct indexRange;

	ValueStruct substituteValue;

	QualifiedNameStruct* pMetaDataProperties;
	OTUInt32 metaDataProperties_count;


	PublishedVariableDataTypeStruct();
	PublishedVariableDataTypeStruct(const PublishedVariableDataTypeStruct&);

	EnumStatusCode set(const PublishedVariableDataTypeStruct&);
	EnumStatusCode get(PublishedVariableDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PublishedVariableDataType&);
	EnumStatusCode get(OpcUa_PublishedVariableDataType&, const std::vector<tstring>&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>&) const;
#endif

	const PublishedVariableDataTypeStruct& operator=(const PublishedVariableDataTypeStruct& cp);
	bool operator==(const PublishedVariableDataTypeStruct& toCompare) const;
	bool operator!=(const PublishedVariableDataTypeStruct& toCompare) const;
	bool operator<(const PublishedVariableDataTypeStruct& toCompare) const;
	bool operator>(const PublishedVariableDataTypeStruct& toCompare) const;

	int compare(const PublishedVariableDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~PublishedVariableDataTypeStruct(void);
} PublishedVariableDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
