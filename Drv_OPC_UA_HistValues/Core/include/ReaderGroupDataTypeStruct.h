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

#ifndef _ReaderGroupDataTypeStruct_H_
#define _ReaderGroupDataTypeStruct_H_

#include "ReaderGroupTransportDataTypeStruct.h"
#include "ReaderGroupMessageDataTypeStruct.h"
#include "DataSetReaderDataTypeStruct.h"
#include "Enums.h"
#include "EndpointDescriptionStruct.h"
#include "KeyValuePairStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(ReaderGroupDataTypeStruct::clear, cleanup)
//lint -sem(ReaderGroupDataTypeStruct::init, initializer)
typedef struct TBCORE_IF ReaderGroupDataTypeStruct
{
	ReaderGroupTransportDataTypeStruct transportSettings;

	// pure virtual class - cannot be instantiated
	// ReaderGroupMessageDataTypeStruct messageSettings;

	DataSetReaderDataTypeStruct* pDataSetReaders;
	OTUInt32 dataSetReaders_count;

	OTChar* pName;

	OTBoolean enabled;

	EnumMessageSecurityMode securityMode;

	OTChar* pSecurityGroupId;

	EndpointDescriptionStruct* pSecurityKeyServices;
	OTUInt32 securityKeyServices_count;

	OTUInt32 maxNetworkMessageSize;

	KeyValuePairStruct* pGroupProperties;
	OTUInt32 groupProperties_count;


	ReaderGroupDataTypeStruct();
	ReaderGroupDataTypeStruct(const ReaderGroupDataTypeStruct&);

	EnumStatusCode set(const ReaderGroupDataTypeStruct&);
	EnumStatusCode get(ReaderGroupDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ReaderGroupDataType&);
	EnumStatusCode get(OpcUa_ReaderGroupDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const ReaderGroupDataTypeStruct& operator=(const ReaderGroupDataTypeStruct& cp);
	bool operator==(const ReaderGroupDataTypeStruct& toCompare) const;
	bool operator!=(const ReaderGroupDataTypeStruct& toCompare) const;
	bool operator<(const ReaderGroupDataTypeStruct& toCompare) const;
	bool operator>(const ReaderGroupDataTypeStruct& toCompare) const;

	int compare(const ReaderGroupDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~ReaderGroupDataTypeStruct(void);
} ReaderGroupDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
