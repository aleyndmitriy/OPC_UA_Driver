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

#ifndef _PubSubConfigurationDataTypeStruct_H_
#define _PubSubConfigurationDataTypeStruct_H_

#include "PublishedDataSetDataTypeStruct.h"
#include "PubSubConnectionDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(PubSubConfigurationDataTypeStruct::clear, cleanup)
//lint -sem(PubSubConfigurationDataTypeStruct::init, initializer)
typedef struct TBCORE_IF PubSubConfigurationDataTypeStruct
{
	PublishedDataSetDataTypeStruct* pPublishedDataSets;
	OTUInt32 publishedDataSets_count;

	PubSubConnectionDataTypeStruct* pConnections;
	OTUInt32 connections_count;

	OTBoolean enabled;


	PubSubConfigurationDataTypeStruct();
	PubSubConfigurationDataTypeStruct(const PubSubConfigurationDataTypeStruct&);

	EnumStatusCode set(const PubSubConfigurationDataTypeStruct&);
	EnumStatusCode get(PubSubConfigurationDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PubSubConfigurationDataType&);
	EnumStatusCode get(OpcUa_PubSubConfigurationDataType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const PubSubConfigurationDataTypeStruct& operator=(const PubSubConfigurationDataTypeStruct& cp);
	bool operator==(const PubSubConfigurationDataTypeStruct& toCompare) const;
	bool operator!=(const PubSubConfigurationDataTypeStruct& toCompare) const;
	bool operator<(const PubSubConfigurationDataTypeStruct& toCompare) const;
	bool operator>(const PubSubConfigurationDataTypeStruct& toCompare) const;

	int compare(const PubSubConfigurationDataTypeStruct* pTarget) const;

	void clear(void);
	~PubSubConfigurationDataTypeStruct(void);
} PubSubConfigurationDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
