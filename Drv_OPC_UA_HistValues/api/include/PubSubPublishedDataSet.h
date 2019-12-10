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

#ifndef PUBSUBPUBLISHEDDATASET_H
#define PUBSUBPUBLISHEDDATASET_H

#include "Base.h"
#include "KeyValuePair.h"
#include "Value.h"
#include "DataSetMetaDataType.h"
#include "PublishedDataSetSourceDataType.h"

namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
		// Forward declarations
		class DataSetWriter;
		typedef ObjectPointer<DataSetWriter> DataSetWriterPtr;

		/*! The PublishedDataSet class represents a configuration of application-data to be published as DataSet.
		*
		* A PublishedDataSet is similar to either a list of data MonitoredItems or an Event MonitoredItem in
		* the Client Server Subscription model.
		* Similar to data MonitoredItems, the PublishedDataSet can contain a list of Variables.
		* However the published values must not represent any data provided in the address space; the data source
		* may be independent to variables.
		* Similar to an Event MonitoredItem, a PublishedDataSet can select a list of Event field.
		*
		* @see PublishedEvents PublishedDataItems */
		class TBC_EXPORT PublishedDataSet
			: public Base
		{
		public:
			/*! Constructs a new PublishedDataSet instance */
			static ObjectPointer<PublishedDataSet> create();

		protected:
			/*! Default constructor */
			PublishedDataSet();

			/*! For internal use only */
			PublishedDataSet(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~PublishedDataSet();

			/*! Provide current values to this data set
			*
			* @param dataValues		The current values of this data set
			*						The order of the values shall match the order of the fields in the DataSetMetaData.
			*
			* @note This method should be used only on the base class PublishedDataSet.
			*       The current values of the subclasses PublishedDataItems and PublishedEvents are filled automatically
			*       from the data of the address space */
			virtual EnumStatusCode provideCurrentValues(const std::vector<DataValue> &dataValues);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class PublishedDataSet
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the Name of the PublishedDataSet */
			EnumStatusCode setName(const tstring& name);
			/*! Gets the Name of the PublishedDataSet */
			tstring getName() const;

			/*! Gets the configuration version of the attached DataSetMetaDataType
			*
			* @see setDataSetMetaData() */
			EnumStatusCode getConfigurationVersion(ConfigurationVersionDataType &version) const;

			/*! Sets the dataSetClassId
			*
			* The DataSetClassId is the globally unique identifier for a DataSetClass, which means that the order and content of
			* the fields match to a certain representation.
			* The class ID shall be present if the DataSetClassId of the DataSetMetaData is not null.
			* If the DataSetClassId is set, the publisher shall reject any configuration changes that change the DataSetMetaData.
			*
			* @param classId	The new classId of the PublishedDataSet */
			EnumStatusCode setDataSetClassId(const Guid& classId);
			/*! Gets the dataSetClassId
			*
			* @see setDataSetClassId() */
			EnumStatusCode getDataSetClassId(Guid& classId) const;

			/*! Sets the DatasetMetaData
			*
			* DataSetMetaData describes the content and semantic of a DataSet.
			* The order of the fields in the DataSetMetaData shall match the order of values in provideCurrentValues or the order of variable information in PublishedDataItemsDataType.
			*
			* The configuration version of DataSetMetaData shall be initialized with the time of initial configuration.
			* It shall be updated, whenever the meta data changes.
			* See ConfigurationVersionDataType for further details, when major / minor version shall change and what values shall be provided.
			*
			* @param metaData	the metaData Value
			*
			* @note If the built-in type of the fields in the metaData to not provided by application, the SDK tries to calculate it correctly.
			*		In case calculation does not succeed, EnumStatusCode_BadInvalidArgument will be returned. */
			EnumStatusCode setDataSetMetaData(const DataSetMetaDataType &metaData);
			/*! Gets the DatasetMetaData
			*
			* @see setDataSetMetaData */
			EnumStatusCode getDataSetMetaData(DataSetMetaDataType &metaData) const;

			/*! Sets the ExtensionFields
			*
			* The ExtensionFields parameter allows the configuration of fields with values to be included in
			* the DataSet when the existing AddressSpace of the Publisher does not provide the necessary information.
			* The ExtensionFields are represented as array of KeyValuePair Structures.
			*
			* @param extensionFields	the array of extension Fields of the PublishedDataSet
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setExtensionFields(const std::vector<KeyValuePair> &extensionFields);
			/*! Gets the ExtensionFields
			*
			* @see setExtensionFields */
			EnumStatusCode getExtensionFields(std::vector<KeyValuePair> &extensionFields) const;

			/*! Sets the DataSetSource
			*
			* The PublishedDataSetSourceDataType structure is an abstract base type without
			* fields for the definition of the PublishedDataSet source.
			*
			* A published data set can be used without source information; the source information just links the published data to sources within the address space.
			* Please use concrete structures like PublishedDataItemsDataType or PublishedEventsDataType to set source information.
			*
			* @param sourceData	the sourceData of the PublishedDataSet */
			EnumStatusCode setDataSetSource(const PublishedDataSetSourceDataType &sourceData);
			/*! Gets the DataSetSource
			*
			* @see setDataSetSource */
			EnumStatusCode getDataSetSource(PublishedDataSetSourceDataType &sourceData) const;


			/*! Attaches a DataSetWriter to this DataSet and registers this DataSet to that DataSetWriter
			*
			* Only data sets configured with a writer are published.
			* A data set can be configured for multiple writers, but a writer can handle only one data set.
			*
			* @param writer		A writer which publishes the data set
			* @note To allow different use cases, it is also possible to set or reset a DataSet from the DataSetWriter side
			* @see DataSetWriter::setDataSet() */
			EnumStatusCode addDataSetWriter(DataSetWriterPtr writer);

			/*! Removes a writer from this data set */
			EnumStatusCode removeDataSetWriter(DataSetWriterPtr writer);

			/*! Gets all writers configured for this data set */
			std::vector<DataSetWriterPtr> getDataSetWriters() const;

			/*! Gets the SDK API class of the instance
			*
			* Since there are derived classes via this method the type of this instance can be retrieved.
			* The instance can be casted to the actual type.
			*
			* @return The ApiClassType of the instance. Possible values:
			*		@li EnumApiClassType_PubSubPublishedDataSet		The base class PublishedDataSet.
			*		@li EnumApiClassType_PubSubPublishedDataItems	The derived class PublishedDataItems
			*		@li EnumApiClassType_PubSubPublishedEvents		The derived class PublishedEvents */
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
			PublishedDataSet& operator=(const PublishedDataSet&);
			/*! Forbid use of copy constructor */
			PublishedDataSet(const PublishedDataSet&);
		};

		typedef ObjectPointer<PublishedDataSet>PublishedDataSetPtr;
		typedef ObjectPointer<const PublishedDataSet> PublishedDataSetConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBPUBLISHEDDATASET_H
