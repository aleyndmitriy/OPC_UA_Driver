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

#ifndef _PubSubConnectionDataTypeStruct_H_
#define _PubSubConnectionDataTypeStruct_H_

#include "ValueStruct.h"
#include "NetworkAddressDataTypeStruct.h"
#include "KeyValuePairStruct.h"
#include "ConnectionTransportDataTypeStruct.h"
#include "WriterGroupDataTypeStruct.h"
#include "ReaderGroupDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(PubSubConnectionDataTypeStruct::clear, cleanup)
//lint -sem(PubSubConnectionDataTypeStruct::init, initializer)
typedef struct TBCORE_IF PubSubConnectionDataTypeStruct
{
	OTChar* pName;

	OTBoolean enabled;

	ValueStruct publisherId;

	OTChar* pTransportProfileUri;

	NetworkAddressDataTypeStruct address;

	KeyValuePairStruct* pConnectionProperties;
	OTUInt32 connectionProperties_count;

	ConnectionTransportDataTypeStruct transportSettings;

	WriterGroupDataTypeStruct* pWriterGroups;
	OTUInt32 writerGroups_count;

	ReaderGroupDataTypeStruct* pReaderGroups;
	OTUInt32 readerGroups_count;


	PubSubConnectionDataTypeStruct();
	PubSubConnectionDataTypeStruct(const PubSubConnectionDataTypeStruct&);

	EnumStatusCode set(const PubSubConnectionDataTypeStruct&);
	EnumStatusCode get(PubSubConnectionDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PubSubConnectionDataType&);
	EnumStatusCode get(OpcUa_PubSubConnectionDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const PubSubConnectionDataTypeStruct& operator=(const PubSubConnectionDataTypeStruct& cp);
	bool operator==(const PubSubConnectionDataTypeStruct& toCompare) const;
	bool operator!=(const PubSubConnectionDataTypeStruct& toCompare) const;
	bool operator<(const PubSubConnectionDataTypeStruct& toCompare) const;
	bool operator>(const PubSubConnectionDataTypeStruct& toCompare) const;

	int compare(const PubSubConnectionDataTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~PubSubConnectionDataTypeStruct(void);
} PubSubConnectionDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
