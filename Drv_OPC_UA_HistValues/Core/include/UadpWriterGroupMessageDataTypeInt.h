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

#ifndef _UadpWriterGroupMessageDataTypeInt_H_
#define _UadpWriterGroupMessageDataTypeInt_H_

#include "WriterGroupMessageDataTypeInt.h"

//lint -sem(UadpWriterGroupMessageDataTypeInt::clearInternal, cleanup)
struct UadpWriterGroupMessageDataTypeInt : public WriterGroupMessageDataTypeInt
{
	UadpWriterGroupMessageDataTypeInt();
	UadpWriterGroupMessageDataTypeInt(const UadpWriterGroupMessageDataTypeInt &source);
	virtual ~UadpWriterGroupMessageDataTypeInt();

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
	const OTDouble* getPublishingOffset(unsigned &count) const;

	/*! Set the time in milliseconds for the offset in the PublishingInterval cycle of sending the NetworkMessage to the network. */
	EnumStatusCode setPublishingOffset(const OTDouble* offsets, unsigned count);

	virtual WriterGroupMessageDataTypeInt *clone() const;
	virtual EnumStatusCode set(const WriterGroupMessageDataTypeInt &source);
	virtual int compare(const WriterGroupMessageDataTypeInt* pTarget) const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode setInternal(const UadpWriterGroupMessageDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_UadpWriterGroupMessageDataType &source);
	EnumStatusCode get(OpcUa_UadpWriterGroupMessageDataType &target) const;
#endif

protected:
	/*! The time of the last layout change published by the WriterGroup. */
	OTUInt32 groupVersion;

	/*! The ordering of the DataSetMessages in the NetworkMessages. */
	EnumDataSetOrderingType dataSetOrdering;

	/*! Optional header fields to be included in the NetworkMessages. */
	EnumUadpNetworkMessageContentMask networkMessageContentMask;

	/*! The time in milliseconds for the offset of creating the NetworkMessage. */
	OTDouble samplingOffset;

	/*! The time in milliseconds for the offset in the PublishingInterval cycle of sending the NetworkMessage to the network. */
	OTDouble* pPublishingOffset;
	unsigned pPublishingOffset_count;

	void clearInternal();

};

#endif //_UadpWriterGroupMessageDataTypeInt_H_