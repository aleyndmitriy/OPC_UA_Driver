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

#ifndef PUBSUBSUBSCRIBEDDATASET_H
#define PUBSUBSUBSCRIBEDDATASET_H

#include "Base.h"
#include "DataValue.h"
#include "InnerDataValue.h"
#include "InnerConfigurationVersionDataType.h"

namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
		// Forward declarations
		class DataSetReader;
		typedef ObjectPointer<DataSetReader> DataSetReaderPtr;

		/*! The SubscribedDataSet class represents a configuration of application-data to be published as DataSet.
		*
		* A SubscribedDataSet is similar to either a list of data MonitoredItems or an Event MonitoredItem in
		* the Client Server Subscription model.
		* Similar to data MonitoredItems, the SubscribedDataSet can contain a list of Variables.
		* However the published values must not represent any data provided in the address space; the data source
		* may be independent to variables.
		* Similar to an Event MonitoredItem, a SubscribedDataSet can select a list of Event field.
		*
		* @see PublishedEvents PublishedDataItems */
		class TBC_EXPORT SubscribedDataSet
			: public Base
		{
		public:
			/*! Constructs a new SubscribedDataSet instance */
			static ObjectPointer<SubscribedDataSet> create();

		protected:
			/*! For internal use only */
			SubscribedDataSet(bool suppressCoreInstanceCreate);

			/*! Default constructor */
			SubscribedDataSet();

		public:
			/*! Destructor */
			virtual ~SubscribedDataSet();


			/*! The helper class ReceivedValuesInformation is used to provide the information of received subscribed data.
			*
			* This class provides the received values from a KeyFrameMessage, DeltaFrameMessage or EventMessages and some information
			* to identify the origin of the data. */
			class TBC_EXPORT ReceivedValuesInformation
			{
			public:
				/*! For internal use only */
				ReceivedValuesInformation(ValueStruct& publisherId,
					GuidStruct& dataSetClassId,
					OTUInt16 writerGroupId,
					OTUInt16 writerId,
					ConfigurationVersionDataTypeStruct* pConfigVersion,
					OTUInt32 noOfValues,
					OTUInt32* pIndices,
					DataValueStruct** ppValues);

				/*! Destructor */
				~ReceivedValuesInformation();

				/*! Returns the indices in the meta data fields which belong to the published values.
				*
				* @note The indices and values belong to the current meta data of the publisher, this might be different to the
				*       local meta data of the DataSetReader.
				*       Make sure to check the configuration version of the received message (when it was part of the sent message) with
				*       the configuration version of the local meta data.
				* @see getConfigurationVersion */
				const std::vector<OTUInt32>& getIndices() const;

				/*! Returns the received values.
				*
				* The reported values belong to the reported indices of the meta data fields.
				* KeyFrameMessages and EventMessages always contain all fields, while DeltaFrameMessages report only the changed data.
				*
				* @see getIndices() */
				std::vector<DataValue> getValues() const;

				/*! Returns the PublisherId from the published data.
				*
				* @note Returns a NULL-Value when the publisher didn't send the PublisherId as part of the NetworkMessage
				* @note The returned values might be limited by the PublisherId filter of the related PubSub::DataSetReader
				* @see PubSub::DataSetReader::setPublisherId() */
				const IValue& getPublisherId() const;

				/*! Returns the DataSetClassId from the published data.
				*
				* @note Returns a NULL-Guid when the publisher didn't send the DataSetClassId as part of the NetworkMessage
				* @note The returned values might be limited by the DataSetClassId filter of the related PubSub::DataSetReader within the MetaData
				* @see PubSub::DataSetReader::setDataSetMetaData() */
				Guid getDataSetClassId() const;

				/*! Returns the WriterGroupId from the published data.
				*
				* @note Returns 0 when the publisher didn't send the WriterGroupId as part of the NetworkMessage
				* @note The returned values might be limited by the WriterGroupId filter of the related PubSub::DataSetReader
				* @see PubSub::DataSetReader::setWriterGroupId() */
				OTUInt16 getWriterGroupId() const;

				/*! Returns the WriterId from the published data.
				*
				* @note Returns 0 when the publisher didn't send the WriterId as part of the DataSetMessage
				* @note The returned values might be limited by the WriterId filter of the related PubSub::DataSetReader
				* @see PubSub::DataSetReader::setDataSetWriterId() */
				OTUInt16 getWriterId() const;

				/*! Returns the ConfigurationVersion from the published data.
				*
				* @note The publisher may not send the configuration version with the published data.
				*		In this case, the configuration version is 0 / 0.
				* @note If a valid version is reported and this version differs from the stored version in the readers metadata,
				*		the reader may request an update of the meta data from the publisher. */
				const IConfigurationVersionDataType* getConfigurationVersion() const;

			private:
				/*! Forbid direct usage */
				ReceivedValuesInformation();
				/*! Forbid use of copy constructor */
				ReceivedValuesInformation(const ReceivedValuesInformation&);
				/*! Forbid use assignment operator */
				ReceivedValuesInformation& operator=(const ReceivedValuesInformation&);

				InnerValue m_publisherId;
				GuidStruct m_dataSetClassId;
				OTUInt16 m_writerGroupId;
				OTUInt16 m_writerId;
				InnerConfigurationVersionDataType m_configrationVersion;
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<OTUInt32> m_indices)
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataValue> m_values)
			};

			/*! Notification that new values are received for this DataSet
			*
			* This method is invoked by the SDK when a publisher has sent new values for the subscribed DataSet.
			*
			* @param receivedValues	Contains the information about the received values and about the source of the data */
			virtual void onValuesReceived(const ReceivedValuesInformation& receivedValues);

			/*! Sets the Name of the SubscribedDataSet */
			EnumStatusCode setName(const tstring& name);
			/*! Gets the Name of the SubscribedDataSet */
			tstring getName() const;

			/*! Gets the DataSetReader configured for this subscribed data set */
			DataSetReaderPtr getDataSetReader();

			/*! Gets the SDK API class of the instance
			*
			* Since there are derived classes via this method the type of this instance can be retrieved.
			* The instance can be casted to the actual type.
			*
			* @return The ApiClassType of the instance. Possible values:
			*		@li EnumApiClassType_PubSubSubscribedDataSet	The base class SubscribedDataSet
			*
			* @note Additional derived classes are note yet implemented. */
			EnumApiClassType getApiClass() const;

			/*! Validates if this instance is derived from the given API class.
			*
			* A static cast to this API class is possible without risk.
			*
			* @param apiClass		The API class which shall be verified
			* @return				true: This node is derived from the tested class type */
			bool isOfApiClass(EnumApiClassType apiClass) const;
		private:
			/*! Forbid use assignment operator */
			SubscribedDataSet& operator=(const SubscribedDataSet&);
			/*! Forbid use of copy constructor */
			SubscribedDataSet(const SubscribedDataSet&);
		};

		typedef ObjectPointer<SubscribedDataSet>SubscribedDataSetPtr;
		typedef ObjectPointer<const SubscribedDataSet> SubscribedDataSetConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBSUBSCRIBEDDATASET_H
