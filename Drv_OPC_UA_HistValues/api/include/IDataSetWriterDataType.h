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

#ifndef IDATASETWRITERDATATYPE_H
#define IDATASETWRITERDATATYPE_H

#include "DataSetWriterDataTypeStruct.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "DataSetWriterTransportDataType.h"
#include "IDataSetWriterTransportDataType.h"
#include "DataSetWriterMessageDataType.h"
#include "IDataSetWriterMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The DataSetWriterDataType is used to store the DataSetWriter parameters. */
	class TBC_EXPORT IDataSetWriterDataType
	{
	public:
		/*! Destructor */
		virtual ~IDataSetWriterDataType(){};

		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const = 0;

		/*! Sets the DataSetWriterId member in the class
		*
		* @see DataSetWriter::setId */
		virtual void setDataSetWriterId(const OTUInt16& writerId) = 0;
		/*! Gets the DataSetWriterId member of the class */
		virtual OTUInt16 getDataSetWriterId() const = 0;

		/*! Sets the DataSetFieldContentMask member in the class
		*
		* @see DataSetWriter::setDataSetFieldContentMask */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& contentMask) = 0;
		/*! Gets the DataSetFieldContentMask member of the class */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const = 0;

		/*! Sets the KeyFrameCount member in the class
		*
		* @see DataSetWriter::setKeyFrameCount */
		virtual void setKeyFrameCount(const OTUInt32& keyFrameCount) = 0;
		/*! Gets the KeyFrameCount member of the class */
		virtual OTUInt32 getKeyFrameCount() const = 0;

		/*! Sets the name of the corresponding PublishedDataSet of the class */
		virtual void setDataSetName(const tstring& dataSetName) = 0;
		/*! Gets the name of the corresponding PublishedDataSet of the class */
		virtual tstring getDataSetName() const = 0;

		/*! Adds a DataSetWriterProperty to the DataSetWriterProperties member of the class
		*
		* @see DataSetWriter::setProperties */
		virtual EnumStatusCode addDataSetWriterProperty(const IKeyValuePair& writerProperty) = 0;
		/*! Gets the DataSetWriterProperties member of the class */
		virtual std::vector<KeyValuePair> getDataSetWriterProperties() const = 0;

		/*! Sets the TransportSettings member in the class
		*
		* @param transportSettings		Transport mapping specific DataSetWriter parameters. */
		virtual EnumStatusCode setTransportSettings(const IDataSetWriterTransportDataType* transportSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetWriterTransportDataType& transportSettings) = 0;
		/*! Gets the TransportSettings member of the class */
		virtual DataSetWriterTransportDataType getTransportSettings() const = 0;

		/*! Sets the MessageSettings member in the class
		*
		* @see DataSetWriter::setMessageSettings */
		virtual EnumStatusCode setMessageSettings(const IDataSetWriterMessageDataType* messageSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetWriterMessageDataType& messageSettings) = 0;
		/*! Gets the MessageSettings member of the class */
		virtual DataSetWriterMessageDataType getMessageSettings() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IDataSetWriterDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataSetWriterDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetWriterDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetWriterDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataSetWriterDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetWriterDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataSetWriterDataType
} // end namespace

#endif
