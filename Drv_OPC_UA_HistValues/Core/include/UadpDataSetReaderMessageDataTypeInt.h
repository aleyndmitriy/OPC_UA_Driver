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

#ifndef _UadpDataSetReaderMessageDataTypeInt_H_
#define _UadpDataSetReaderMessageDataTypeInt_H_

#include "DataSetReaderMessageDataTypeInt.h"
#include "GuidStruct.h"
#include "Enums.h"

//lint -sem(UadpDataSetReaderMessageDataTypeInt::clearInternal, cleanup)
struct UadpDataSetReaderMessageDataTypeInt : public DataSetReaderMessageDataTypeInt
{
	UadpDataSetReaderMessageDataTypeInt();
	UadpDataSetReaderMessageDataTypeInt(const UadpDataSetReaderMessageDataTypeInt &source);
	virtual ~UadpDataSetReaderMessageDataTypeInt();

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
	const GuidStruct &getDataSetClassId() const;

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

	virtual DataSetReaderMessageDataTypeInt *clone() const;
	virtual EnumStatusCode set(const DataSetReaderMessageDataTypeInt &source);
	EnumStatusCode set(const UadpDataSetReaderMessageDataTypeInt &source);
	virtual int compare(const DataSetReaderMessageDataTypeInt* pTarget) const;
	
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_UadpDataSetReaderMessageDataType &source);
	EnumStatusCode get(OpcUa_UadpDataSetReaderMessageDataType &target) const;
#endif

protected:
	/*! The expected value in the field GroupVersion in the header of the NetworkMessage. */
	OTUInt32 groupVersion;

	/*! The number of the NetworkMessage inside a PublishingInterval. */
	OTUInt16 networkMessageNumber;

	/*! The offset for the DataSetMessage inside the corresponding NetworkMessage. */
	OTUInt16 dataSetOffset;

	/*! A DataSet class related filter. */
	GuidStruct dataSetClassId;

	/*! The optional header fields included in the received NetworkMessages. */
	EnumUadpNetworkMessageContentMask networkMessageContentMask;

	/*! The optional header fields included in the DataSetMessages. */
	EnumUadpDataSetMessageContentMask dataSetMessageContentMask;

	/*! The rate the Publisher sends NetworkMessages related to the DataSet. */
	OTDouble publishingInterval;

	/*! The time in milliseconds for the offset in the PublishingInterval cycle for the expected receive time. */
	OTDouble receiveOffset;

	/*! The time in milliseconds for the offset in the PublishingInterval cycle when the received DataSet must be processed. */
	OTDouble processingOffset;

	void clearInternal();

};

#endif //_UadpDataSetReaderMessageDataTypeInt_H_