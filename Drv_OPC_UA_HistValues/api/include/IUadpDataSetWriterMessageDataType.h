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

#ifndef IUADPDATASETWRITERMESSAGEDATATYPE_H
#define IUADPDATASETWRITERMESSAGEDATATYPE_H

#include "IDataSetWriterMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! Interface to the concrete data type UadpDataSetWriterMessageDataType, which is used to store UADP DataSetMessage mapping specific DataSetWriter parameters. */
	class TBC_EXPORT IUadpDataSetWriterMessageDataType : public IDataSetWriterMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~IUadpDataSetWriterMessageDataType(){};

		/*! Sets the DataSetMessageContentMask member in the class
		*
		* A data set header can contain several optional information.
		* By setting the bits, a data set writer defines the information to be published. */
		virtual void setDataSetMessageContentMask(const EnumUadpDataSetMessageContentMask& contentMask) = 0;
		/*! @see setDataSetMessageContentMask */
		virtual EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const = 0;

		/*! Sets the ConfiguredSize member in the class
		*
		* The parameter ConfiguredSize defines the fixed size in bytes a DataSetMessage uses inside a NetworkMessage.
		* The default value is 0 and it indicates a dynamic length.
		* If a DataSetMessage would be smaller in size (e.g. because of the current values that are encoded) the DataSetMessage
		* is padded with bytes with value zero.
		* In case it would be larger, the publisher shall set bit 0 of the DataSetFlags1 to false to indicate that the DataSetMessage is not valid.
		*
		* @note Fixed size is currently not supported. */
		virtual void setConfiguredSize(const OTUInt16& configuredSize) = 0;
		/*! @see setConfiguredSize */
		virtual OTUInt16 getConfiguredSize() const = 0;

		/*! Gets the NetworkMessageNumber member in the class
		*
		* The parameter NetworkMessageNumber is a read-only parameter set by the publisher in the case of a fixed NetworkMessage layout.
		* The default value is 0 and indicates that the position of the DataSetMessage in a NetworkMessage is not fixed.
		* If the NetworkMessage layout is fixed and all DataSetMessages of a WriterGroup fit into one single NetworkMessage the value
		* of NetworkMessageNumber shall be 1.
		* If the DataSetMessages of a WriterGroup are distributed or chunked over more than one NetworkMessage the first NetworkMessage
		* in a PublishingInterval shall be generated with the value 1, the following NetworkMessages shall be generated with incrementing NetworkMessageNumbers.
		* To avoid a roll-over the number of NetworkMessages generated from one WriterGroup within one PublishingInterval is limited to 65535. */
		virtual OTUInt16 getNetworkMessageNumber() const = 0;

		/*! Gets the DataSetOffset member in the class
		*
		* The parameter DataSetOffset is a read-only parameter set by the publisher that specifies the offset in bytes inside a NetworkMessage
		* at which the DataSetMessage is located, relative to the beginning of the NetworkMessage.
		* The default value 0 indicates that the position of the DataSetMessage in a NetworkMessage is not fixed. */
		virtual OTUInt16 getDataSetOffset() const = 0;

		/*! Conversion from IDataSetWriterMessageDataType */
		static const IUadpDataSetWriterMessageDataType* castFrom(const IDataSetWriterMessageDataType* pSrc);
		/*! Conversion from IDataSetWriterMessageDataType */
		static IUadpDataSetWriterMessageDataType* castFrom(IDataSetWriterMessageDataType* pSrc);
	}; // end IUadpDataSetWriterMessageDataType
} // end namespace

#endif
