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

#ifndef IPUBSUBCONNECTIONDATATYPE_H
#define IPUBSUBCONNECTIONDATATYPE_H

#include "PubSubConnectionDataTypeStruct.h"
#include "Value.h"
#include "IValue.h"
#include "NetworkAddressDataType.h"
#include "INetworkAddressDataType.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "ConnectionTransportDataType.h"
#include "IConnectionTransportDataType.h"
#include "WriterGroupDataType.h"
#include "IWriterGroupDataType.h"
#include "ReaderGroupDataType.h"
#include "IReaderGroupDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The interface to PubSubConnectionDataType, which a type to store configuration data of a PubSub::Connection.
	*
	* @note For additional information on the members see also PubSub::Connection */
	class TBC_EXPORT IPubSubConnectionDataType
	{
	public:
		/*! Destructor */
		virtual ~IPubSubConnectionDataType(){};

		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const = 0;

		/*! Sets the PublisherId member in the class.
		*
		* The PublisherId is a unique identifier for a Publisher within a Message Oriented Middleware. It
		* can be included in sent NetworkMessage for identification or filtering.
		* The value of the PublisherId is typically shared between PubSubConnections but the assignment
		* of the PublisherId is vendor specific.
		*
		* @param publisherId	Publisher ID of this connection. Valid data types are OTUInt8, OTUInt16, OTUInt32, OTUInt64 and String */
		virtual EnumStatusCode setPublisherId(const IValue* publisherId) = 0;
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& publisherId) = 0;
		/*! Gets the PublisherId member of the class.
		*
		* @see setPublisherId() */
		virtual const IValue* getPublisherId() const = 0;

		/*! Sets the TransportProfileUri member in the class
		*
		* @param transportProfileUri		The TransportProfileUri parameter indicates the transport protocol mapping and the message mapping used.
		*
		* The profile URI can be one of
		* @li http://opcfoundation.org/UA-Profile/Transport/pubsub-udp-uadp
		* @li http://opcfoundation.org/UA-Profile/Transport/pubsub-mqtt-uadp
		* @li http://opcfoundation.org/UA-Profile/Transport/pubsub-mqtt-json
		*
		* @note Currently the SDK only supports the UDP-UADP transport profile.
		* @note The concrete NetworkAddressUrlDataType provides in the URL member also the protocol.
		*		Currently the transport profile URI is ignored by the SDK and only the protocol of the NetworkAddressUrlDataType URI is used. */
		virtual void setTransportProfileUri(const tstring& transportProfileUri) = 0;
		/*! Gets the TransportProfileUri member of the class */
		virtual tstring getTransportProfileUri() const = 0;

		/*! Sets the Address member in the class
		*
		* @param address		The Address parameter contains the network address information for the communication middleware. */
		virtual EnumStatusCode setAddress(const INetworkAddressDataType* address) = 0;
		/*! @overload */
		virtual EnumStatusCode setAddress(const NetworkAddressDataType& address) = 0;
		/*! Gets the Address member of the class */
		virtual NetworkAddressDataType getAddress() const = 0;

		/*! Adds a ConnectionProperty to the ConnectionProperties member of the class
		*
		* @param connectionProperty		The ConnectionProperties parameter is an array of DataType KeyValuePair specifies
		*								additional properties for the configured connection. */
		virtual EnumStatusCode addConnectionProperty(const IKeyValuePair& connectionProperty) = 0;
		/*! Gets the ConnectionProperties member of the class */
		virtual std::vector<KeyValuePair> getConnectionProperties() const = 0;

		/*! Sets the TransportSettings member in the class
		*
		* @param transportSettings		Transport mapping specific PubSubConnection parameters. */
		virtual EnumStatusCode setTransportSettings(const IConnectionTransportDataType* transportSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ConnectionTransportDataType& transportSettings) = 0;
		/*! Gets the TransportSettings member of the class */
		virtual ConnectionTransportDataType getTransportSettings() const = 0;

		/*! Adds a WriterGroup to the WriterGroups member of the class
		*
		* @param writerGroup		A writer group to be added to this connection */
		virtual EnumStatusCode addWriterGroup(const IWriterGroupDataType& writerGroup) = 0;
		/*! Gets the WriterGroups member of the class */
		virtual std::vector<WriterGroupDataType> getWriterGroups() const = 0;

		/*! Adds a ReaderGroup to the ReaderGroups member of the class
		*
		* @param readerGroup		A writer group to be added to this connection */
		virtual EnumStatusCode addReaderGroup(const IReaderGroupDataType& readerGroup) = 0;
		/*! Gets the ReaderGroups member of the class */
		virtual std::vector<ReaderGroupDataType> getReaderGroups() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPubSubConnectionDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IPubSubConnectionDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubConnectionDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubConnectionDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPubSubConnectionDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubConnectionDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPubSubConnectionDataType
} // end namespace

#endif
