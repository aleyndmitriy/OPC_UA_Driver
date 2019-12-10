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

#ifndef IUADPDATASETREADERMESSAGEDATATYPE_H
#define IUADPDATASETREADERMESSAGEDATATYPE_H

#include "Guid.h"
#include "IGuid.h"
#include "IDataSetReaderMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The UadpDataSetReaderMessageDataType is used to store UADP message mapping specific DataSetReader parameters. */
	class TBC_EXPORT IUadpDataSetReaderMessageDataType : public IDataSetReaderMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~IUadpDataSetReaderMessageDataType(){};

		/*! Sets the GroupVersion member in the class
		*
		* @param groupVersion	The member GroupVersion defines the expected value in the field GroupVersion in the header of the NetworkMessage.
		*						The default value 0 is defined as null value, and means this member shall be ignored.
		*
		* @see IUadpWriterGroupMessageDataType::setGroupVersion */
		virtual void setGroupVersion(const OTUInt32& groupVersion) = 0;
		/*! Gets the GroupVersion member of the class */
		virtual OTUInt32 getGroupVersion() const = 0;

		/*! Sets the NetworkMessageNumber member in the class
		* @param messageNumber		The member NetworkMessageNumber is the number of the NetworkMessage inside a PublishingInterval in which this DataSetMessage is published.
		*							The default value 0 is defined as null value, and means this member shall be ignored. */
		virtual void setNetworkMessageNumber(const OTUInt16& messageNumber) = 0;
		/*! Gets the NetworkMessageNumber member of the class */
		virtual OTUInt16 getNetworkMessageNumber() const = 0;

		/*! Sets the DataSetOffset member in the class
		*
		* @param dataSetOffset		The member DataSetOffset defines the offset for the DataSetMessage inside the corresponding NetworkMessage.
		*							The default value 0 is defined as null value, and means this member shall be ignored. */
		virtual void setDataSetOffset(const OTUInt16& dataSetOffset) = 0;
		/*! Gets the DataSetOffset member of the class */
		virtual OTUInt16 getDataSetOffset() const = 0;

		/*! Sets the DataSetClassId member in the class
		*
		* @param pDataSetClassId	The parameter DataSetClassId with DataType Guid defines a DataSet class related filter.
		*							If the value is null, the DataSetClassId filter is not applied. */
		virtual EnumStatusCode setDataSetClassId(const IGuid* pDataSetClassId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetClassId(const Guid& dataSetClassId) = 0;
		/*! Gets the DataSetClassId member of the class */
		virtual const IGuid* getDataSetClassId() const = 0;

		/*! Sets the NetworkMessageContentMask member in the class
		*
		* @param contentMask	The NetworkMessageContentMask indicates the optional header fields included in the received NetworkMessages. */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& contentMask) = 0;
		/*! Gets the NetworkMessageContentMask member of the class */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const = 0;

		/*! Sets the DataSetMessageContentMask member in the class
		*
		* @param contentMask	The DataSetMessageContentMask indicates the optional header fields included in the DataSetMessages. */
		virtual void setDataSetMessageContentMask(const EnumUadpDataSetMessageContentMask& contentMask) = 0;
		/*! Gets the DataSetMessageContentMask member of the class */
		virtual EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const = 0;

		/*! Sets the PublishingInterval member in the class
		*
		* @param publishingInterval		The PublishingInterval indicates the rate the Publisher sends NetworkMessages related to the DataSet.
		*								The start time for the periodic execution of the Subscriber shall be a multiple of the PublishingInterval
		*								relative to the start of the time base. */
		virtual void setPublishingInterval(const OTDouble& publishingInterval) = 0;
		/*! Gets the PublishingInterval member of the class */
		virtual OTDouble getPublishingInterval() const = 0;

		/*! Sets the ReceiveOffset member in the class
		*
		* @param receiveOffset		The ReceiveOffset defines the time in milliseconds for the offset in the PublishingInterval cycle
		*							for the expected receive time of the NetworkMessage for the DataSet from the network. */
		virtual void setReceiveOffset(const OTDouble& receiveOffset) = 0;
		/*! Gets the ReceiveOffset member of the class */
		virtual OTDouble getReceiveOffset() const = 0;

		/*! Sets the ProcessingOffset member in the class
		+
		+ @param processingOfffset		The ProcessingOffset defines the time in milliseconds for the offset in the PublishingInterval cycle
		+								when the received DataSet must be processed by the application in the Subscriber. */
		virtual void setProcessingOffset(const OTDouble& processingOfffset) = 0;
		/*! Gets the ProcessingOffset member of the class */
		virtual OTDouble getProcessingOffset() const = 0;

		/*! Conversion from IDataSetReaderMessageDataType */
		static const IUadpDataSetReaderMessageDataType* castFrom(const IDataSetReaderMessageDataType* pSrc);
		/*! Conversion from IDataSetReaderMessageDataType */
		static IUadpDataSetReaderMessageDataType* castFrom(IDataSetReaderMessageDataType* pSrc);
	}; // end IUadpDataSetReaderMessageDataType
} // end namespace

#endif
