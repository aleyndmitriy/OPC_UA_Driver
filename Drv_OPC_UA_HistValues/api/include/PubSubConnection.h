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

#ifndef PUBSUBCONNECTION_H
#define PUBSUBCONNECTION_H

#include "Base.h"
#include "KeyValuePair.h"
#include "NetworkAddressDataType.h"
#include "ConnectionTransportDataType.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations

	namespace PubSub
	{
		class Connection;
		class WriterGroup;
		typedef ObjectPointer<WriterGroup> WriterGroupPtr;
		class ReaderGroup;
		typedef ObjectPointer<ReaderGroup> ReaderGroupPtr;
	}

	namespace PubSub
	{
		/*! The Connection class represents a PubSub connection.
		*
		* This class is used both for publisher and subscriber.
		* Please note that connections have to be added to the Application object (see Application::addPubSubConnection()). */
		class TBC_EXPORT Connection
			: public Base
		{
		public:
			/*! Constructs a new Connection instance */
			static ObjectPointer<Connection> create();

		protected:
			/*! Default constructor */
			Connection();

			/*! For internal use only */
			Connection(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Connection();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Connection
			/////////////////////////////////////////////////////////////////////////

			/*! Sets the Name of the Connection.
			*
			* The name must be valid and unique among all Connections of the Application.
			* This name is used to generate NodeIds for the server address space.
			*
			* @see Application::addPubSubConnection() */
			EnumStatusCode setName(const tstring& name);
			/*! Gets the Name of the Connection */
			tstring getName() const;

			/*! Sets the publisher ID to the connection
			*
			* The PublisherId is a unique identifier for a publisher within a Message Oriented Middleware.
			* It can be included in sent NetworkMessage for identification or filtering.
			* The value of the PublisherId is typically shared between PubSubConnections but the assignment
			* of the PublisherId is vendor specific.
			*
			* @param publisherId	Publisher ID of this connection. Valid data types are OTUInt8, OTUInt16, OTUInt32, OTUInt64 and String */
			EnumStatusCode setPublisherId(const Value &publisherId);
			/*! Gets the publisher ID of the connection
			*
			* @see setPublisherId() */
			EnumStatusCode getPublisherId(Value &publisherId) const;

			/*! Sets the enabled state of the connection
			*
			* Only an enabled connection will publish or subscribe data for their writer or reader groups.
			*
			* @param enabled	enables the connection (default is true) */
			void setEnabled(bool enabled);
			/*! Gets the enabled state of the connection
			*
			* @see setEnabled() */
			bool getEnabled() const;

			/*! Gets the status of this PubSub component.
			*
			* The status is calculated by the EnabledFlag, by an internal error status
			* and by the status of the parent (Application).
			*
			* @see EnumPubSubState, setEnabled() */
			EnumPubSubState getPubSubState() const;

			/*! Sets the TransportProfileUri of the connection
			*
			* The TransportProfileUri indicates the transport protocol mapping and the message mapping used.
			* Defined transports are:
			* @li TransportProfileUri_PubSub_Udp_Uadp (default)
			* @li TransportProfileUri_PubSub_Mqtt_Uadp (not supported)
			* @li TransportProfileUri_PubSub_Mqtt_Json (not supported)
			*
			* @param transportProfileUri	The transport profile URI
			*
			* @note Currently only TransportProfileUri_PubSub_Udp_Uadp is supported.
			*
			* @note This setting is currently ignored. The used transport profile is detected from the network address. */
			EnumStatusCode setTransportProfileUri(const tstring &transportProfileUri);
			/*! Gets the TransportProfileUri of the connection
			*
			* @see setTransportProfileUri()) */
			tstring getTransportProfileUri() const;

			/*! Sets the mandatory network address of the connection
			*
			* The network address used for the communication relation.
			* The NetworkAddressDataType represents the network address information.
			* For UDP connections the derived class NetworkAddressUrlDataType shall be used as address information.
			*
			* @param networkAddress	The address used for publishing or subscribing */
			EnumStatusCode setNetworkAddress(const NetworkAddressDataType &networkAddress);
			/*! Gets the NetworkInterface of the connection
			*
			* @see setNetworkInterface()) */
			EnumStatusCode getNetworkAddress(NetworkAddressDataType &networkAddress) const;

			/*! Sets the optional transport settings of the connection
			*
			* The ConnectionTransportDataType represents the transport mapping specific PubSubConnection parameters.
			* For UDP connections the derived class DatagramConnectionTransportDataType shall be used as transport mapping.
			*
			* @param transportSettings	The address used for publishing or subscribing
			*
			* @note <b>All settings in DatagramConnectionTransportDataType are not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setTransportSettings(const ConnectionTransportDataType &transportSettings);
			/*! Gets the NetworkInterface of the connection
			*
			* @see setNetworkInterface()) */
			EnumStatusCode getTransportSettings(IConnectionTransportDataType &transportSettings) const;

			/*! Sets the properties of the connection
			*
			* The properties specify additional properties for the configured connection.
			* The mapping of the namespace, name, and value to concrete functionality may be defined by transport protocol mappings,
			* future versions of this specification or vendor specific extensions.
			*
			* @param properties	The properties of the connection
			*
			* @note  connection properties are only used by AMQP transport (not yet supported).
			* All other transports will ignore all configured properties.
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setProperties(const std::vector<KeyValuePair> &properties);
			/*! Gets the properties of the connection
			*
			* @see setProperties()) */
			std::vector<KeyValuePair> getProperties() const;

			/*! Adds a PubSub writer group to the connection
			*
			* A writer group can publish data only if configured for a connection.
			* A connection can contain multiple groups but a group can belong only to one connection.
			*
			* @param	writerGroup		The writer group to be added to this connection
			*
			* @note The name of the WriterGroup must be valid and unique among all other WriterGroups and ReaderGroups of this Connection */
			EnumStatusCode addWriterGroup(WriterGroupPtr writerGroup);

			/*! Removes a PubSub writer group from the connection */
			EnumStatusCode removeWriterGroup(WriterGroupPtr writerGroup);

			/*! Gets all writer groups from the connection */
			std::vector<WriterGroupPtr> getWriterGroups() const;

			/*! Adds a PubSub reader group to the connection
			*
			* A writer group can publish data only if configured for a connection.
			* A connection can contain multiple groups but a group can belong only to one connection.
			*
			* @note The name of the ReaderGroup must be valid and unique among all other ReaderGroups and WriterGroups of this Connection */
			EnumStatusCode addReaderGroup(ReaderGroupPtr readerGroup);
			/*! Removes a PubSub reader group from the connection */
			EnumStatusCode removeReaderGroup(ReaderGroupPtr readerGroup);
			/*! Gets all writer reader from the connection */
			std::vector<ReaderGroupPtr> getReaderGroups() const;

			/*! Notification that that the state has changed
			*
			* Overwrite this method to implement specific handling if the state changes.
			*
			* @note The notification can result by changing the enabled state of this object or registering / unregistering the connection at application.
			*		It can be invoked as well independent on the enabled configuration, e.g. in case of errors.
			* @see Application::addPubSubConnection, Application::removePubSubConnection
			*
			* @note This notification is executed asynchronously. Between detection of state change and notification, the state can have changed again. */
			virtual void onPubSubStateChanged(EnumPubSubState newState);

		private:
			/*! Forbid use assignment operator */
			Connection& operator=(const Connection&);
			/*! Forbid use of copy constructor */
			Connection(const Connection&);
		};

		typedef ObjectPointer<Connection>ConnectionPtr;
		typedef ObjectPointer<const Connection> ConnectionConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBCONNECTION_H
