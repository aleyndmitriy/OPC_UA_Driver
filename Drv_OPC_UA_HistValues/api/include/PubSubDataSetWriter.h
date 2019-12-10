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

#ifndef PUBSUBDATASETWRITER_H
#define PUBSUBDATASETWRITER_H

#include "Base.h"
#include "KeyValuePair.h"
#include "DataSetWriterMessageDataType.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations

	namespace PubSub
	{
		class PublishedDataSet;
		typedef ObjectPointer<PublishedDataSet> PublishedDataSetPtr;

		/*! The DataSetWriter class represents a PubSub DataSetWriter.
		*
		* The DataSetWrter creates messages for a PublishedDataSet according its configuration. */
		class TBC_EXPORT DataSetWriter
			: public Base
		{
		public:
			/*! Constructs a new DataSetWriter instance */
			static ObjectPointer<DataSetWriter> create();

		protected:
			/*! Default constructor */
			DataSetWriter();

			/*! For internal use only */
			DataSetWriter(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~DataSetWriter();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class DataSetWriter
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the name of the DataSetWriter
			*
			* The name must be valid and unique among all DataSetWriters of the same WriterGroup.
			* This name is used to generate NodeIds for the server address space.
			*
			* @see WriterGroup::addDataSetWriter() */
			EnumStatusCode setName(const tstring &name);
			/*! gets the name of the DataSetWriter
			*
			* @see nsetName */
			tstring getName() const;

			/*! Sets the enabled state of the DataSetWriter
			*
			* Only a enabled DataSetWriter will publish data.
			*
			* @param enabled	enables the DataSetWriter (default is true) */
			void setEnabled(bool enabled);
			/*! Gets the enabled state of the DataSetWriter
			*
			* @see setEnabled() */
			bool getEnabled() const;

			/*! Gets the status of this PubSub component.
			*
			* The status is calculated by the EnabledFlag, by an internal error status
			* and by the status of the parent (PubSub::Group).
			*
			* @see EnumPubSubState, setEnabled(), PubSub::Group::setEnabled() */
			EnumPubSubState getPubSubState() const;

			/*! Sets the DataSetWriterId of the DataSetWriter
			*
			* The Id defines the unique ID of the DataSetWriter for a PublishedDataSet.
			* It is used to select DataSetMessages for a PublishedDataSet on the Subscriber side.
			* It shall be unique across all DataSetWriters for a PublisherId.
			* All values, except for 0, are valid DataSetWriterIds.
			*
			* @param dataSetWriterId	The ID of the DataSetWriter */
			EnumStatusCode setId(OTUInt16 dataSetWriterId);
			/*! Gets the DataSetWriterId of the DataSetWriter
			*
			* @see setId()) */
			OTUInt16 getId() const;

			/*! Sets the DataSetFieldContentMask of the DataSetWriter
			*
			* A data set field consists of a value and related metadata.
			* In most cases the value comes with status and timestamp information.
			* This mask defines flags to include data set field related information like status and
			* timestamp in addition to the value in the DataSetMessage.
			* If no bit is set, then the value is encoded as a variant.
			*
			* @param dataSetContentMask	The content mask of the DataSetWriter */
			EnumStatusCode setDataSetFieldContentMask(EnumDataSetFieldContentMask dataSetContentMask);
			/*! Gets the DataSetFieldContentMask of the DataSetWriter
			*
			* @see setDataSetFieldContentMask()) */
			OTUInt32 getDataSetFieldContentMask() const;

			/*! Sets the KeyFrameCount of the DataSetWriter
			*
			* The KeyFrameCount is the multiplier of the PublishingInterval that defines the maximum number
			* of times the PublishingInterval expires before a key frame message with values for all published Variables is sent.
			* The delta frame DataSetMessages contains just the changed values. If no changes exist, the delta frame DataSetMessage shall
			* not be sent.
			*
			* If the KeyFrameCount is set to 1, every message contains a key frame.
			* For PublishedDataSets like PublishedDataItems that provide cyclic updates of the DataSet, the value shall be greater or equal to 1.
			* For non-cyclic PublishedDataSets, like PublishedEvents, that provide event based DataSets, the value shall be 0.
			*
			* The default value is 1.
			*
			* @param keyFrameCount	The key frame count of the DataSetWriter */
			EnumStatusCode setKeyFrameCount(OTUInt32 keyFrameCount);
			/*! Gets the KeyFrameCount of the DataSetWriter
			*
			* @see setKeyFrameCount()) */
			OTUInt32 getKeyFrameCount() const;

			/*! Assigns a DataSet to this writer and add this writer to a DataSet
			*
			* A Writer has one DataSet assigned, which is used to produce the DataSetMessages.
			*
			* @param dataSet		The DataSet which shall be assigned
			* @note To allow different use cases, it is also possible to add, remove or access DataSetWriters from the DataSet side
			* @see PublishedDataSet::addDataSetWriter() */
			EnumStatusCode setDataSet(PublishedDataSetPtr dataSet);
			/*! Gets the assigned DataSet (may return NULL if no data set is configured)
			*
			* @see setDataSet */
			PublishedDataSetPtr getDataSet() const;

			/*! Sets the properties of the DataSetWriter
			*
			* The properties specify additional properties for the configured DataSetWriter.
			* The mapping of the name and value to concrete functionality may be defined by transport
			* protocol mappings, future versions of this specification or vendor specific extensions.
			*
			* @param properties	The properties of the DataSetWriter
			*
			* @note  Group properties are only used by AMQP transport (not yet supported).
			* All other transports will ignore all configured properties.
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setProperties(const std::vector<KeyValuePair> &properties);
			/*! Gets the properties of the DataSetWriter
			*
			* @see setProperties()) */
			std::vector<KeyValuePair> getProperties() const;

			/*! Sets the message settings of the writer
			*
			* A Writer may have specific message settings, dependent on the transport.
			* Valid concrete message settings can be defined via UadpDataSetWriterMessageDataType or JsonDataSetWriterMessageDataType (not yet supported)
			*
			* @param messageSettings		The message settings which shall be used
			*
			* @note <b>Some functionality of the message settings is not yet implemented. E.g ConfiguredSize, DataSetOffset - any configuration done here is currently ignored.</b> */
			EnumStatusCode setMessageSettings(const DataSetWriterMessageDataType &messageSettings);
			/*! Gets the message settings
			*
			* @see setMessageSettings */
			DataSetWriterMessageDataType getMessageSettings() const;

			/*! Notification that that the state has changed
			*
			* Overwrite this method to implement specific handling if the state changes.
			*
			* @note The notification can result by changing the enabled state of this object or a "parent" object.
			*		It can be invoked as well independent on the enabled configuration, e.g. in case of errors.
			* @note This notification is executed asynchronously. Between detection of state change and notification, the state can have changed again. */
			virtual void onPubSubStateChanged(EnumPubSubState newState);

			protected:
			/*! For internal use only */
			void initMembers();

		private:
			/*! Forbid use assignment operator */
			DataSetWriter& operator=(const DataSetWriter&);
			/*! Forbid use of copy constructor */
			DataSetWriter(const DataSetWriter&);

		};

		typedef ObjectPointer<DataSetWriter>DataSetWriterPtr;
		typedef ObjectPointer<const DataSetWriter> DataSetWriterConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBDATASETWRITER_H
