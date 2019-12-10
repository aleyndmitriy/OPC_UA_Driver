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

#ifndef _UadpDataSetReaderMessageDataTypeStruct_H_
#define _UadpDataSetReaderMessageDataTypeStruct_H_

#include "DataSetReaderMessageDataTypeStruct.h"
#include "GuidStruct.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct UadpDataSetReaderMessageDataTypeInt;

//lint -sem(UadpDataSetReaderMessageDataTypeStruct::clear, cleanup)
//lint -sem(UadpDataSetReaderMessageDataTypeStruct::init, initializer)
struct TBCORE_IF UadpDataSetReaderMessageDataTypeStruct : public DataSetReaderMessageDataTypeStruct
{
	/*! Access the expected value in the field GroupVersion in the header of the NetworkMessage. */
	OTUInt32 getGroupVersion() const;

	/*! Set the expected value in the field GroupVersion in the header of the NetworkMessage. */
	EnumStatusCode setGroupVersion(OTUInt32 version);

	/*! Access the number of the NetworkMessage inside a PublishingInterval. */
	OTUInt16 getNetworkMessageNumber() const;

	/*! Set the number of the NetworkMessage inside a PublishingInterval. */
	EnumStatusCode setNetworkMessageNumber(OTUInt16 number);

	/*! Access the offset for the DataSetMessage inside the corresponding NetworkMessage. */
	OTUInt16 getDataSetOffset() const;

	/*! Set the offset for the DataSetMessage inside the corresponding NetworkMessage. */
	EnumStatusCode setDataSetOffset(OTUInt16 offset);

	/*! Get DataSet class related filter. */
	const GuidStruct *getDataSetClassId() const;

	/*! Set DataSet class related filter. */
	EnumStatusCode setDataSetClassId(const GuidStruct &id);

	/*! Get the optional header fields included in the received NetworkMessages. */
	EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;

	/*! Set the optional header fields included in the received NetworkMessages. */
	EnumStatusCode setNetworkMessageContentMask(EnumUadpNetworkMessageContentMask mask);

	/*! Get the optional header fields included in the DataSetMessages. */
	EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;

	/*! Set the optional header fields included in the DataSetMessages. */
	EnumStatusCode setDataSetMessageContentMask(EnumUadpDataSetMessageContentMask mask);

	/*! Get the rate the Publisher sends NetworkMessages related to the DataSet. */
	OTDouble getPublishingInterval() const;

	/*! Set the rate the Publisher sends NetworkMessages related to the DataSet. */
	EnumStatusCode setPublishingInterval(OTDouble interval);

	/*! Get the time in milliseconds for the offset in the PublishingInterval cycle for the expected receive time. */
	OTDouble getReceiveOffset() const;

	/*! Set the time in milliseconds for the offset in the PublishingInterval cycle for the expected receive time. */
	EnumStatusCode setReceiveOffset(OTDouble offset);

	/*! Get the time in milliseconds for the offset in the PublishingInterval cycle when the received DataSet must be processed. */
	OTDouble getProcessingOffset() const;

	/*! Set the time in milliseconds for the offset in the PublishingInterval cycle when the received DataSet must be processed. */
	EnumStatusCode setProcessingOffset(OTDouble offset);

	UadpDataSetReaderMessageDataTypeStruct();
	UadpDataSetReaderMessageDataTypeStruct(const UadpDataSetReaderMessageDataTypeStruct&);
	UadpDataSetReaderMessageDataTypeStruct(const DataSetReaderMessageDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const UadpDataSetReaderMessageDataTypeStruct&);
	EnumStatusCode set(const DataSetReaderMessageDataTypeStruct&);
	EnumStatusCode get(UadpDataSetReaderMessageDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_UadpDataSetReaderMessageDataType&);
	EnumStatusCode get(OpcUa_UadpDataSetReaderMessageDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const UadpDataSetReaderMessageDataTypeStruct& operator=(const UadpDataSetReaderMessageDataTypeStruct& cp);
	bool operator==(const UadpDataSetReaderMessageDataTypeStruct& toCompare) const;
	bool operator!=(const UadpDataSetReaderMessageDataTypeStruct& toCompare) const;
	bool operator<(const UadpDataSetReaderMessageDataTypeStruct& toCompare) const;
	bool operator>(const UadpDataSetReaderMessageDataTypeStruct& toCompare) const;

	int compare(const UadpDataSetReaderMessageDataTypeStruct* pTarget) const;

	void clear(void);
	~UadpDataSetReaderMessageDataTypeStruct(void);

protected:
	void init(void);
};

typedef struct UadpDataSetReaderMessageDataTypeStruct UadpDataSetReaderMessageDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
