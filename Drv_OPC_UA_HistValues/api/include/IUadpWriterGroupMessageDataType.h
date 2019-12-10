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

#ifndef IUADPWRITERGROUPMESSAGEDATATYPE_H
#define IUADPWRITERGROUPMESSAGEDATATYPE_H

#include "IWriterGroupMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The UadpWriterGroupMessageDataType is used to store the UADP NetworkMessage mapping specific WriterGroup parameters. */
	class TBC_EXPORT IUadpWriterGroupMessageDataType : public IWriterGroupMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~IUadpWriterGroupMessageDataType(){};

		/*! Sets the GroupVersion member in the class
		*
		* The GroupVersion reflects the time of the last layout change of the content of the NetworkMessages published by the WriterGroup.
		* The GroupVersion changes when one of the following parameters is modified:
		* @li NetworkMessageContentMask of this WriterGroup
		* @li Offset of any DataSetWriter in this WriterGroup
		* @li ConfigurationVersion of the DataSet of any DataSetWriter in this WriterGroup
		* @li DataSetFieldContentMask of any DataSetWriter in this WriterGroup
		* @li DataSetMessageContentMask of any DataSetWriter in this WriterGroup
		* @li DataSetWriterId of any DataSetWriter in this WriterGroup
		* The GroupVersion is valid for all NetworkMessages resulting from this WriterGroup.
		*
		* @param versionTime	The time of the group version
		*						The value represents the  time in seconds since the year 2000.
		*						The epoch date is midnight UTC (00:00) on January 1, 2000. */
		virtual void setGroupVersion(const OTUInt32& versionTime) = 0;
		/*! @see setGroupVersion() */
		virtual OTUInt32 getGroupVersion() const = 0;

		/*! Sets the DataSetOrdering member in the class */
		virtual void setDataSetOrdering(const EnumDataSetOrderingType& ordering) = 0;
		/*! @see setDataSetOrdering() */
		virtual EnumDataSetOrderingType getDataSetOrdering() const = 0;

		/*! Sets the NetworkMessageContentMask member in the class
		*
		* A network message contains several optional information.
		* By setting the bits, a writer group defines the information to be published. */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& contentMask) = 0;
		/*! @see setNetworkMessageContentMask() */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const = 0;

		/*! Sets the SamplingOffset member in the class
		*
		* The SamplingOffset defines the time in milliseconds for the offset of creating the NetworkMessage in the PublishingInterval cycle.
		* Any negative value indicates that the optional parameter is not configured.
		* In this case the publisher shall calculate the time before the PublishingOffset that is necessary to create the network message
		* in time for sending at the PublishingOffset.
		*
		* @note The sampling offset is currently ignored. */
		virtual void setSamplingOffset(const OTDouble& samplingOffset) = 0;
		/*! @see setSamplingOffset() */
		virtual OTDouble getSamplingOffset() const = 0;

		/*! Sets the PublishingOffset member in the class
		*
		* The PublishingOffset defines the time in milliseconds for the offset(s) in the PublishingInterval cycle of sending
		* the network message(s) to the network.
		* The message - created at SamplingOffset - is sent at first at the first element of the vector.
		* If a message has to be split into multiple messages, the other messages are sent at the according index of the vector.
		*
		* If the vector contains only one element, following messages are sent immediately after the first.
		* If the vector contains less elements that messages, the next offset is calculated by the difference of the last two elements.
		*
		* @note publishing offset(s) are currently not supported and will be ignored. */
		virtual EnumStatusCode setPublishingOffset(const std::vector<OTDouble>& publishingOffsets) = 0;
		/*! @see setPublishingOffset() */
		virtual std::vector<OTDouble> getPublishingOffset() const = 0;

		/*! Conversion from IWriterGroupMessageDataType */
		static const IUadpWriterGroupMessageDataType* castFrom(const IWriterGroupMessageDataType* pSrc);
		/*! Conversion from IWriterGroupMessageDataType */
		static IUadpWriterGroupMessageDataType* castFrom(IWriterGroupMessageDataType* pSrc);
	}; // end IUadpWriterGroupMessageDataType
} // end namespace

#endif
