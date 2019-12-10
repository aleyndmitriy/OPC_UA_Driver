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

#ifndef PUBSUBDATASETREADER_H
#define PUBSUBDATASETREADER_H

#include "Base.h"
#include "KeyValuePair.h"
#include "DataSetReaderMessageDataType.h"
#include "Value.h"
#include "EndpointDescription.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations

	namespace PubSub
	{
		class SubscribedDataSet;
		typedef ObjectPointer<SubscribedDataSet> SubscribedDataSetPtr;

		/*! The DataSetReader class represents a PubSub DataSetReader.
		*
		* The DataSetWrter creates messages for a PublishedDataSet according its configuration. */
		class TBC_EXPORT DataSetReader
			: public Base
		{
		public:
			/*! Constructs a new DataSetReader instance */
			static ObjectPointer<DataSetReader> create();

		protected:
			/*! For internal use only */
			DataSetReader(bool suppressCoreInstanceCreate);

			/*! Default constructor */
			DataSetReader();

		public:
			/*! Destructor */
			virtual ~DataSetReader();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class DataSetReader
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the name of the DataSetReader.
			*
			* The name must be valid and unique among all DataSetReaders of the same ReaderGroup.
			* This name is used to generate NodeIds for the server address space.
			*
			* @see ReaderGroup::addDataSetReader() */
			EnumStatusCode setName(const tstring &name);
			/*! gets the name of the DataSetReader
			*
			* @see nsetName */
			tstring getName() const;

			/*! Sets the enabled state of the DataSetReader
			*
			* Only a enabled DataSetReader will publish data.
			*
			* @param enabled	enables the DataSetReader (default is true) */
			void setEnabled(bool enabled);
			/*! Gets the enabled state of the DataSetReader
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

			/*! Sets the SubscribedDataSet
			*
			* A Reader has one DataSet assigned, which is used to process the DataSetMessages.
			*
			* @param dataSet		The DataSet which shall be assigned */
			EnumStatusCode setDataSet(SubscribedDataSetPtr dataSet);
			/*! Gets the assigned DataSet (may return NULL if no data set is configured)
			*
			* @see setDataSet */
			SubscribedDataSetPtr getDataSet() const;

			/*! Sets the PublisherId filter
			*
			* The Id identifies the publisher to receive data from.
			* All network messages with a different PublisherId are ignored.
			* If a NULL PublisherId is provided, all received message pass the DataSetWriterId filter.
			*
			* @note If the publisher does not send a PublisherId, then this filter must be NULL to accept the network messages. */
			EnumStatusCode setPublisherId(const Value &publisherId);
			/*! Gets the DataSetWriterId of the DataSetReader
			*
			* @see setPublisherId()) */
			Value getPublisherId() const;

			/*! Sets the WriterGroupId filter
			*
			* The Id identifies the WriterGroup to receive data from.
			* All network messages with a different WriterGroupId are ignored.
			* If the WriterGroupId is 0, all received message pass the WriterGroupId filter.
			*
			* @note If the publisher does not send a WriterGroupId, then this filter must be 0 to accept the network messages. */
			EnumStatusCode setWriterGroupId(OTUInt16 writerGroupId);
			/*! Gets the WriterGroupId of the DataSetReader
			*
			* @see setWriterGroupId()) */
			OTUInt16 getWriterGroupId() const;

			/*! Sets the DataSetWriterId filter
			*
			* The Id identifies DataSetWriter to receive data from.
			* All DataSetMessages with a different DataSetWriterId are ignored.
			* If the DataSetWriterId is 0, all received DataSetMessages within a NetworkMessage pass the DataSetWriterId filter.
			*
			* @note If the publisher does not send a DataSetWriterId, then this filter must be 0 to accept the network messages. */
			EnumStatusCode setDataSetWriterId(OTUInt16 dataSetWriterId);
			/*! Gets the DataSetWriterId of the DataSetReader
			*
			* @see setDataSetWriterId()) */
			OTUInt16 getDataSetWriterId() const;

			/*! Sets the DataSetMetaData
			*
			* The DataSetMetaData provides the information necessary to decode DataSetMessages from the publisher.
			* If the DataSetMetaData changes in the publisher and the MajorVersion was changed, the DataSetReader
			* needs an update of the DataSetMetaData for further operation.
			* If the update cannot be retrieved in the duration of the MessageReceiveTimeout,
			* the PubSubState of the DataSetReader shall change to EnumPubSubState_Error.
			*
			* @see PublishedDataSet
			*
			* @note The meta data also contains a DataSetClassId member, which is used to filter network messages, except the class ID is not set (NULL).
			*
			* @note If the built-in type of the fields in the metaData to not provided by application, the SDK tries to calculate it correctly.
			*		In case calculation does not succeed, EnumStatusCode_BadInvalidArgument will be returned. */
			EnumStatusCode setDataSetMetaData(const DataSetMetaDataType &metaData);
			/*! Gets the DataSetMetaData of the DataSetReader
			*
			* @see setDataSetWriterId()) */
			EnumStatusCode getDataSetMetaData(DataSetMetaDataType &metaData) const;

			/*! Sets the DataSetFieldContentMask of the DataSetReader
			*
			* @see DataSetWriter::setDataSetFieldContentMask */
			EnumStatusCode setDataSetFieldContentMask(OTUInt32 dataSetContentMask);
			/*! Gets the DataSetFieldContentMask of the DataSetReader
			*
			* @see setDataSetFieldContentMask()) */
			OTUInt32 getDataSetFieldContentMask() const;

			/*! Sets the MessageReceiveTimeout of the DataSetReader
			*
			* The MessageReceiveTimeout is the maximum acceptable time in milliseconds between two DataSetMessages.
			* If there is no DataSetMessage received within this period, the PubSubState shall be changed to EnumPubSubState_Error until the next DataSetMessage is received.
			* The DataSetMessages can be data or keep alive messages.
			*
			* The MessageReceiveTimeout is related to the Publisher side parameters PublishingInterval, KeepAliveTime and KeyFrameCount.
			*
			* @note Fraction part of messageReceiveTimeout is ignored; values greater that std::numeric_limits<OTUInt64>::max() are revised. */
			EnumStatusCode setMessageReceiveTimeout(OTDouble messageReceiveTimeout);
			/*! Gets the MessageReceiveTimeout of the DataSetReader
			*
			* @see setMessageReceiveTimeout()) */
			OTDouble getMessageReceiveTimeout() const;

			/*! Sets the security mode
			*
			* This parameter overwrites the corresponding setting on the ReaderGroup if the value is not EnumMessageSecurityMode_Invalid.
			*
			* @see IPubSubGroupDataType::setSecurityMode()
			* @note Default security mode is None
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setSecurityMode(EnumMessageSecurityMode securityMode);
			/*! Gets the security mode
			*
			* @see setSecurityMode()) */
			EnumMessageSecurityMode getSecurityMode() const;

			/*! Sets the SecurityGroupId
			*
			* The parameter shall be an empty string if the SecurityMode is EnumMessageSecurityMode_Invalid.
			*
			* @see IPubSubGroupDataType::setSecurityMode()
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setSecurityGroupId(const tstring &securityGroupId);
			/*! Gets the SecurityGroupId
			*
			* @see setSecurityGroupId() */
			tstring getSecurityGroupId() const;

			/*! Sets the SecurityKeyServices
			*
			* The parameter shall be an empty array if the SecurityMode is EnumMessageSecurityMode_Invalid.
			*
			* @see IPubSubGroupDataType::addSecurityKeyService
			* @see EndpointDescription
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setSecurityKeyServices(const std::vector<EndpointDescription> &securityKeyServices);
			/*! Gets the SecurityKeyServices
			*
			* @see setSecurityKeyServices() */
			std::vector<EndpointDescription> getSecurityKeyServices() const;

			/*! Sets the properties of the DataSetReader
			*
			* The properties specify additional properties for the configured DataSetReader.
			* The mapping of the name and value to concrete functionality may be defined by transport
			* protocol mappings, future versions of this specification or vendor specific extensions.
			*
			* @param properties	The properties of the DataSetReader
			*
			* @note  The properties are only used by AMQP transport (not yet supported).
			* All other transports will ignore all configured properties.
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setProperties(const std::vector<KeyValuePair> &properties);
			/*! Gets the properties of the DataSetReader
			*
			* @see setProperties()) */
			std::vector<KeyValuePair> getProperties() const;

			/*! Sets the message settings of the writer
			*
			* A Reader may have specific message settings, dependent on the transport.
			* Valid concrete message settings can be defined via UadpDataSetReaderMessageDataType or JsonDataSetReaderMessageDataType (not yet supported)
			*
			* @param messageSettings		The message settings which shall be used
			*
			* @note <b>Only the setting of PublishingInterval in UadpDataSetReaderMessageDataType is supported.
			*		All other settings are not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setMessageSettings(const DataSetReaderMessageDataType &messageSettings);
			/*! Gets the message settings
			*
			* @see setMessageSettings */
			DataSetReaderMessageDataType getMessageSettings() const;

			/*! Notification that that the state has changed
			*
			* Overwrite this method to implement specific handling if the state changes.
			*
			* @note The notification can result by changing the enabled state of this object or a "parent" object.
			*		It can be invoked as well independent on the enabled configuration, e.g. in case of errors.
			* @note This notification is executed asynchronously. Between detection of state change and notification, the state can have changed again. */
			virtual void onPubSubStateChanged(EnumPubSubState newState);

			/*! Request data set meta data information from writer
			*
			* Data set meta data it typically known by a DataSetReader, otherwise a reader cannot process the received values.
			* A PublishedDataSet however can be changed by the publisher. In this case the PublishedDataSet shall update the configuration version of the meta data.
			* Another use case is a generic reader, which does not know about meta data at all.
			*
			* In such cases a reader can request the meta data from the publisher, which will be reported some time later via the onMetaDataChanged method.
			*
			* @param publisherId	The PublisherId, where the MetaData belongs to.
			*						If omitted, the configured PublisherId filter is used.
			* @param writerId		The WriterId, where the MetaData belongs to.
			*						If 0 is provided, then the configured writer ID filter is used.
			*						If both are 0 an error is returned.
			*
			* @note Only a DataSetReader in state EnumPubSubState_Operational or EnumPubSubState_Error can request meta data.
			* @note The onMetaDataChanged is invoked only if the received meta data differs from the already configured (see setDataSetMetaData).
			* @note	If both parameter writerId and configured writer ID filter are 0 an error is returned. */
			EnumStatusCode requestMetaData(const IValue &publisherId = Value(), OTUInt16 writerId = 0);

			/*! Notification that a MetaDataMessage was received, containing changed MetaData or a bad status
			*
			* Overwrite this method to react on MetaData changes, e.g. update the SubscribedDataSet and the handling of received values
			*
			* @param publisherId	The PublisherId of the publisher which send the MetaDataMessage
			* @param writerId		The WriterId, where the MetaData belongs to
			* @param responseStatus	This status indicates, if the publisher was able to send MetaData information for the requested WriterId
			* @param metaData		The changed metadata. It's content is only valid when @p responseStatus is valid.
			*
			* @note	The parameters @p publisherId and @p writerId are usually only of interest when no related filter is configured on this DataSetReader,
			*		otherwise the reported parameter values will match the values of the filters. */
			virtual void onMetaDataChanged(const IValue& publisherId, OTUInt16 writerId, EnumStatusCode responseStatus, const IDataSetMetaDataType& metaData);

			protected:
			/*! For internal use only */
			void initMembers();

		private:
			/*! Forbid use assignment operator */
			DataSetReader& operator=(const DataSetReader&);
			/*! Forbid use of copy constructor */
			DataSetReader(const DataSetReader&);

		};

		typedef ObjectPointer<DataSetReader>DataSetReaderPtr;
		typedef ObjectPointer<const DataSetReader> DataSetReaderConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBDATASETREADER_H
