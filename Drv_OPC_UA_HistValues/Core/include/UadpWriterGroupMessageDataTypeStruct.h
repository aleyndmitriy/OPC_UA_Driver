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

#ifndef _UadpWriterGroupMessageDataTypeStruct_H_
#define _UadpWriterGroupMessageDataTypeStruct_H_

#include "WriterGroupMessageDataTypeStruct.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct UadpWriterGroupMessageDataTypeInt;

//lint -sem(UadpWriterGroupMessageDataTypeStruct::clear, cleanup)
//lint -sem(UadpWriterGroupMessageDataTypeStruct::init, initializer)
struct TBCORE_IF UadpWriterGroupMessageDataTypeStruct : public WriterGroupMessageDataTypeStruct
{
	/*! Access the time of the last layout change published by the WriterGroup. */
	OTUInt32 getGroupVersion() const;

	/*! Set the time of the last layout change published by the WriterGroup. */
	EnumStatusCode setGroupVersion(OTUInt32 version);

	/*! Get the ordering of the DataSetMessages in the NetworkMessages. */
	EnumDataSetOrderingType getDataSetOrdering() const;

	/*! Set the ordering of the DataSetMessages in the NetworkMessages. */
	EnumStatusCode setDataSetOrdering(EnumDataSetOrderingType ordering);

	/*! Get the optional header fields to be included in the NetworkMessages. */
	EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;

	/*! Set the optional header fields to be included in the NetworkMessages. */
	EnumStatusCode setNetworkMessageContentMask(EnumUadpNetworkMessageContentMask mask);

	/*! Access the time in milliseconds for the offset of creating the NetworkMessage. */
	OTDouble getSamplingOffset() const;

	/*! Set the time in milliseconds for the offset of creating the NetworkMessage. */
	EnumStatusCode setSamplingOffset(OTDouble offset);

	/*! Access the time in milliseconds for the offset in the PublishingInterval cycle of sending the NetworkMessage to the network. */
	const OTDouble* getPublishingOffset(OTUInt32 &count) const;

	/*! Set the time in milliseconds for the offset in the PublishingInterval cycle of sending the NetworkMessage to the network. */
	EnumStatusCode setPublishingOffset(const OTDouble* offsets, OTUInt32 count);

	UadpWriterGroupMessageDataTypeStruct();
	UadpWriterGroupMessageDataTypeStruct(const UadpWriterGroupMessageDataTypeStruct&);
	UadpWriterGroupMessageDataTypeStruct(const WriterGroupMessageDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const UadpWriterGroupMessageDataTypeStruct&);
	EnumStatusCode set(const WriterGroupMessageDataTypeStruct&);
	EnumStatusCode get(UadpWriterGroupMessageDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_UadpWriterGroupMessageDataType&);
	EnumStatusCode get(OpcUa_UadpWriterGroupMessageDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const UadpWriterGroupMessageDataTypeStruct& operator=(const UadpWriterGroupMessageDataTypeStruct& cp);
	bool operator==(const UadpWriterGroupMessageDataTypeStruct& toCompare) const;
	bool operator!=(const UadpWriterGroupMessageDataTypeStruct& toCompare) const;
	bool operator<(const UadpWriterGroupMessageDataTypeStruct& toCompare) const;
	bool operator>(const UadpWriterGroupMessageDataTypeStruct& toCompare) const;

	int compare(const UadpWriterGroupMessageDataTypeStruct* pTarget) const;

	void clear(void);
	~UadpWriterGroupMessageDataTypeStruct(void);

protected:
	void init(void);
};

typedef struct UadpWriterGroupMessageDataTypeStruct UadpWriterGroupMessageDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
