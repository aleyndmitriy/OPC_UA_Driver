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

#ifndef IWRITERGROUPDATATYPE_H
#define IWRITERGROUPDATATYPE_H

#include "WriterGroupDataTypeStruct.h"
#include "WriterGroupTransportDataType.h"
#include "IWriterGroupTransportDataType.h"
#include "WriterGroupMessageDataType.h"
#include "IWriterGroupMessageDataType.h"
#include "DataSetWriterDataType.h"
#include "IDataSetWriterDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"

namespace SoftingOPCToolbox5
{
	/*! The WriterGroupDataType is used to store the configuration parameters for WriterGroups. */
	class TBC_EXPORT IWriterGroupDataType
	{
	public:
		/*! Destructor */
		virtual ~IWriterGroupDataType(){};

		/*! Sets the Name member in the class
		*
		* @see IPubSubGroupDataType::setName */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class
		*
		* @see IPubSubGroupDataType::getName */
		virtual tstring getName() const = 0;

		/*! Sets the Enabled member in the class
		*
		* @see IPubSubGroupDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class
		*
		* @see IPubSubGroupDataType::getEnabled */
		virtual OTBoolean getEnabled() const = 0;

		/*! Sets the SecurityMode member in the class
		*
		* @see IPubSubGroupDataType::setSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode) = 0;
		/*! Gets the SecurityMode member of the class
		*
		* @see IPubSubGroupDataType::getSecurityMode */
		virtual EnumMessageSecurityMode getSecurityMode() const = 0;

		/*! Sets the SecurityGroupId member in the class
		*
		* @see IPubSubGroupDataType::setSecurityGroupId */
		virtual void setSecurityGroupId(const tstring& securityGroupId) = 0;
		/*! Gets the SecurityGroupId member of the class
		*
		* @see IPubSubGroupDataType::getSecurityGroupId */
		virtual tstring getSecurityGroupId() const = 0;

		/*! Adds a SecurityKeyService to the SecurityKeyServices member of the class
		*
		* @see IPubSubGroupDataType::addSecurityKeyService */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService) = 0;
		/*! Gets the SecurityKeyServices member of the class
		*
		* @see IPubSubGroupDataType::getSecurityKeyServices */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const = 0;

		/*! Sets the MaxNetworkMessageSize member in the class
		*
		* @see IPubSubGroupDataType::setMaxNetworkMessageSize */
		virtual void setMaxNetworkMessageSize(const OTUInt32& maxNetworkMessageSize) = 0;
		/*! Gets the MaxNetworkMessageSize member of the class
		*
		* @see IPubSubGroupDataType::getMaxNetworkMessageSize */
		virtual OTUInt32 getMaxNetworkMessageSize() const = 0;

		/*! Adds a GroupProperty to the GroupProperties member of the class
		*
		* @see IPubSubGroupDataType::addGroupProperty */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty) = 0;
		/*! Gets the GroupProperties member of the class
		*
		* @see IPubSubGroupDataType::getGroupProperties */
		virtual std::vector<KeyValuePair> getGroupProperties() const = 0;

		/*! Sets the WriterGroupId member in the class
		*
		* The WriterGroupId is an identifier for the WriterGroup and shall be unique across all WriterGroups for a PublisherId.
		* All values, except for 0, are valid. The value 0 is defined as null value. */
		virtual void setWriterGroupId(const OTUInt16& groupId) = 0;
		/*! Gets the WriterGroupId member of the class */
		virtual OTUInt16 getWriterGroupId() const = 0;

		/*! Sets the PublishingInterval member in the class
		*
		* The PublishingInterval defines the interval in milliseconds for publishing NetworkMessages and the
		* embedded DataSetMessages created by the related DataSetWriters.
		*
		* In the case of Event based DataSets, this may result in zero to many
		* DataSetMessages produced for one PublishedDataSet in a PublishingInterval.
		* All Events that occur between two PublishingIntervals shall be buffered until
		* the next NetworkMessage is sent. If the number of Events exceeds the buffer
		* capability of the DataSetWriter, an Event of type EventQueueOverflowEventType
		* is inserted into the buffer.
		*
		* @param publishingInterval	The publishingInterval */
		virtual void setPublishingInterval(const OTDouble& publishingInterval) = 0;
		/*! Gets the PublishingInterval member of the class */
		virtual OTDouble getPublishingInterval() const = 0;

		/*! Sets the KeepAliveTime member in the class
		*
		* The KeepAliveTime defines the time in milliseconds until the publisher sends a keep alive DataSetMessage
		* in the case where no DataSetMessage was sent in this period by a DataSetWriter.
		* The minimum value shall equal the PublishingInterval. */
		virtual void setKeepAliveTime(const OTDouble& keepAliveTime) = 0;
		/*! Gets the KeepAliveTime member of the class */
		virtual OTDouble getKeepAliveTime() const = 0;

		/*! Sets the Priority member in the class
		*
		* The Priority with DataType Byte defines the relative priority of the WriterGroup to
		* all other WriterGroups across all PubSubConnections of the publisher.
		*
		* If more than one WriterGroup needs to be processed, the priority number defines the
		* order of processing. The highest priority is processed first.
		*
		* The lowest priority is zero and the highest is 255.
		*
		* @param priority	The new priority */
		virtual void setPriority(const OTUInt8& priority) = 0;
		/*! Gets the Priority member of the class */
		virtual OTUInt8 getPriority() const = 0;

		/*! Sets the LocaleIds member in the class
		*
		* The LocaleIds defines a list of locale ids in priority order for localized strings for all DataSetWriters in the WriterGroup.
		* The first LocaleId in the list has the highest priority.
		* If the publisher sends a localized string, the publisher shall send the translation with the highest priority that it can.
		* If it does not have a translation for any of the locales identified in this list, then it shall send the string value
		* that it has and include the LocaleId with the string.
		* If no locale id is configured, the Publisher shall use any that it has.
		*
		* @param localeIds	The locale ids to be used. */
		virtual EnumStatusCode setLocaleIds(const std::vector<tstring>& localeIds) = 0;
		/*! Gets the LocaleIds member of the class */
		virtual std::vector<tstring> getLocaleIds() const = 0;

		/*! Sets the TransportSettings member in the class
		*
		* A WriterGroup may have specific transport settings, dependent on the connection.
		* Valid concrete message settings can be defined via DatagramWriterGroupTransportDataType or BrokerWriterGroupTransportDataType (not yet supported)
		*
		* @param transportSettings		Transport mapping specific WriterGroup parameters. */
		virtual EnumStatusCode setTransportSettings(const IWriterGroupTransportDataType* transportSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const WriterGroupTransportDataType& transportSettings) = 0;
		/*! Gets the TransportSettings member of the class */
		virtual WriterGroupTransportDataType getTransportSettings() const = 0;

		/*! Sets the MessageSettings member in the class
		*
		* A WriterGroup may have specific message settings, dependent on the transport.
		* Valid concrete message settings can be defined via UadpDataSetWriterMessageDataType or JsonDataSetWriterMessageDataType (not yet supported)
		*
		* @param messageSettings		The message settings which shall be used */
		virtual EnumStatusCode setMessageSettings(const IWriterGroupMessageDataType* messageSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const WriterGroupMessageDataType& messageSettings) = 0;
		/*! Gets the MessageSettings member of the class */
		virtual WriterGroupMessageDataType getMessageSettings() const = 0;

		/*! Adds a DataSetWriter to the DataSetWriters member of the class */
		virtual EnumStatusCode addDataSetWriter(const IDataSetWriterDataType& writer) = 0;
		/*! Gets the DataSetWriters contained in the class */
		virtual std::vector<DataSetWriterDataType> getDataSetWriters() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IWriterGroupDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IWriterGroupDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriterGroupDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriterGroupDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IWriterGroupDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IWriterGroupDataType
} // end namespace

#endif
