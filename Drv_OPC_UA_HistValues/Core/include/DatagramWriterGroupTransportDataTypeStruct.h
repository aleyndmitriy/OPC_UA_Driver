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

#ifndef _DatagramWriterGroupTransportDataTypeStruct_H_
#define _DatagramWriterGroupTransportDataTypeStruct_H_

#include "WriterGroupTransportDataTypeStruct.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct DatagramWriterGroupTransportDataTypeInt;

//lint -sem(DatagramWriterGroupTransportDataTypeStruct::clear, cleanup)
//lint -sem(DatagramWriterGroupTransportDataTypeStruct::init, initializer)
struct TBCORE_IF DatagramWriterGroupTransportDataTypeStruct : public WriterGroupTransportDataTypeStruct
{
	/*! Access how many times every NetworkMessage is repeated. */
	OTUInt8 getMessageRepeatCount() const;

	/*! Set how many times every NetworkMessage is repeated. */
	EnumStatusCode setMessageRepeatCount(OTUInt8 count);

	/*! Access the time between NetworkMessage repeats in milliseconds. */
	OTDouble getMessageRepeatDelay() const;

	/*! Set the time between NetworkMessage repeats in milliseconds. */
	EnumStatusCode setMessageRepeatDelay(OTDouble delay);

	DatagramWriterGroupTransportDataTypeStruct();
	DatagramWriterGroupTransportDataTypeStruct(const DatagramWriterGroupTransportDataTypeStruct&);
	DatagramWriterGroupTransportDataTypeStruct(const WriterGroupTransportDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const DatagramWriterGroupTransportDataTypeStruct&);
	EnumStatusCode set(const WriterGroupTransportDataTypeStruct&);
	EnumStatusCode get(DatagramWriterGroupTransportDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DatagramWriterGroupTransportDataType&);
	EnumStatusCode get(OpcUa_DatagramWriterGroupTransportDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const DatagramWriterGroupTransportDataTypeStruct& operator=(const DatagramWriterGroupTransportDataTypeStruct& cp);
	bool operator==(const DatagramWriterGroupTransportDataTypeStruct& toCompare) const;
	bool operator!=(const DatagramWriterGroupTransportDataTypeStruct& toCompare) const;
	bool operator<(const DatagramWriterGroupTransportDataTypeStruct& toCompare) const;
	bool operator>(const DatagramWriterGroupTransportDataTypeStruct& toCompare) const;

	int compare(const DatagramWriterGroupTransportDataTypeStruct* pTarget) const;

	void clear(void);
	~DatagramWriterGroupTransportDataTypeStruct(void);

protected:
	void init();
};

typedef struct DatagramWriterGroupTransportDataTypeStruct DatagramWriterGroupTransportDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
