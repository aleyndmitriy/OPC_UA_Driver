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

#ifndef _PublishedDataItemsDataTypeStruct_H_
#define _PublishedDataItemsDataTypeStruct_H_

#include "PublishedDataSetSourceDataTypeStruct.h"
#include "PublishedVariableDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct PublishedDataItemsDataTypeInt;

//lint -sem(PublishedDataItemsDataTypeStruct::init, initializer)
struct TBCORE_IF PublishedDataItemsDataTypeStruct : public PublishedDataSetSourceDataTypeStruct
{
	/*! Access the content of a DataSet created from Variable Values. */
	EnumStatusCode getPublishedData(OTUInt32 *pCount, PublishedVariableDataTypeStruct **ppPublishedData);

	/*! Set the content of a DataSet created from Variable Values. */
	EnumStatusCode setPublishedData(const PublishedVariableDataTypeStruct *publishedData, OTUInt32 count);

	EnumStatusCode addPublishedData(const PublishedVariableDataTypeStruct &value);

	PublishedDataItemsDataTypeStruct();
	PublishedDataItemsDataTypeStruct(const PublishedDataItemsDataTypeStruct&);
	PublishedDataItemsDataTypeStruct(const PublishedDataSetSourceDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const PublishedDataItemsDataTypeStruct&);
	EnumStatusCode set(const PublishedDataSetSourceDataTypeStruct&);
	EnumStatusCode get(PublishedDataItemsDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PublishedDataItemsDataType&);
	EnumStatusCode get(OpcUa_PublishedDataItemsDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const PublishedDataItemsDataTypeStruct& operator=(const PublishedDataItemsDataTypeStruct& cp);
	bool operator==(const PublishedDataItemsDataTypeStruct& toCompare) const;
	bool operator!=(const PublishedDataItemsDataTypeStruct& toCompare) const;
	bool operator<(const PublishedDataItemsDataTypeStruct& toCompare) const;
	bool operator>(const PublishedDataItemsDataTypeStruct& toCompare) const;

	int compare(const PublishedDataItemsDataTypeStruct* pTarget) const;

	void clear(void);
	~PublishedDataItemsDataTypeStruct(void);

protected:
	void init(void);
};

typedef struct PublishedDataItemsDataTypeStruct PublishedDataItemsDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
