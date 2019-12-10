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

#ifndef _UadpDataSetWriterMessageDataTypeStruct_H_
#define _UadpDataSetWriterMessageDataTypeStruct_H_

#include "DataSetWriterMessageDataTypeStruct.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct UadpDataSetWriterMessageDataTypeInt;

//lint -sem(UadpDataSetWriterMessageDataTypeStruct::clear, cleanup)
//lint -sem(UadpDataSetWriterMessageDataTypeStruct::init, initializer)
struct TBCORE_IF UadpDataSetWriterMessageDataTypeStruct : public DataSetWriterMessageDataTypeStruct
{
	UadpDataSetWriterMessageDataTypeStruct();
	UadpDataSetWriterMessageDataTypeStruct(const UadpDataSetWriterMessageDataTypeStruct&);
	UadpDataSetWriterMessageDataTypeStruct(const DataSetWriterMessageDataTypeStruct& cp, bool copyContent);
	~UadpDataSetWriterMessageDataTypeStruct(void);

	/*! Access the flags for the content of the DataSetMessage header. */
	EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;

	/*! Set the flags for the content of the DataSetMessage header. */
	EnumStatusCode setDataSetMessageContentMask(EnumUadpDataSetMessageContentMask mask);

	/*! Access the fixed size in bytes a DataSetMessage uses inside a NetworkMessage. */
	OTUInt16 getConfiguredSize() const;

	/*! Set the fixed size in bytes a DataSetMessage uses inside a NetworkMessage. */
	EnumStatusCode setConfiguredSize(OTUInt16 size);

	/*! Access parameter for fixed NetworkMessage layout. */
	OTUInt16 getNetworkMessageNumber() const;

	/*! Set parameter for fixed NetworkMessage layout. */
	EnumStatusCode setNetworkMessageNumber(OTUInt16 value);

	/*! Access the offset in bytes inside a NetworkMessage */
	OTUInt16 getDataSetOffset() const;

	/*! Set the offset in bytes inside a NetworkMessage */
	EnumStatusCode setDataSetOffset(OTUInt16 offset);


	EnumStatusCode set(const UadpDataSetWriterMessageDataTypeStruct&);
	EnumStatusCode set(const DataSetWriterMessageDataTypeStruct&);
	EnumStatusCode get(UadpDataSetWriterMessageDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_UadpDataSetWriterMessageDataType&);
	EnumStatusCode get(OpcUa_UadpDataSetWriterMessageDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const UadpDataSetWriterMessageDataTypeStruct& operator=(const UadpDataSetWriterMessageDataTypeStruct& cp);
	bool operator==(const UadpDataSetWriterMessageDataTypeStruct& toCompare) const;
	bool operator!=(const UadpDataSetWriterMessageDataTypeStruct& toCompare) const;
	bool operator<(const UadpDataSetWriterMessageDataTypeStruct& toCompare) const;
	bool operator>(const UadpDataSetWriterMessageDataTypeStruct& toCompare) const;

	int compare(const UadpDataSetWriterMessageDataTypeStruct* pTarget) const;

	void clear(void);

protected:
	void init();
};

typedef struct UadpDataSetWriterMessageDataTypeStruct UadpDataSetWriterMessageDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
