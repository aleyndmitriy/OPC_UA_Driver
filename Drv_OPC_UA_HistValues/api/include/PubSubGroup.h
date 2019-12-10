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

#ifndef PUBSUBGROUP_H
#define PUBSUBGROUP_H

#include "Base.h"
#include "KeyValuePair.h"
#include "EndpointDescription.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class DataTypeDescription;
	typedef ObjectPointer<const DataTypeDescription> DataTypeDescriptionConstPtr;

	namespace PubSub
	{
		class Group;
		typedef ObjectPointer<Group> GroupPtr;

	}

	namespace PubSub
	{
		/*! The Group class represents a PubSub Group.
		*
		* This is the abstract base class for both WriterGroup and ReaderGroup.
		* Use the specific classes for publisher or subscriber.
		* Please note that groups have to be added to the connection object. */
		class TBC_EXPORT Group
			: public Base
		{
		protected:
			/*! For internal use only */
			Group(bool suppressCoreInstanceCreate);

		public:
			/*! Default constructor */
			Group();

			/*! Destructor */
			virtual ~Group();

		public:
			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Group
			/////////////////////////////////////////////////////////////////////////
			/*! Sets the name of this Group (WriterGroup or ReaderGroup)
			*
			* The name must be valid and unique among all WriterGroups and ReaderGroups of the same Connection.
			* This name is used to generate NodeIds for the server address space.
			*
			* @see Connection::addWriterGroup() and Connection::addReaderGroup() */
			EnumStatusCode setName(const tstring &name);
			/*! Gets the group name
			*
			* @see setGroupName() */
			tstring getName() const;

			/*! Sets the enabled state of the group
			*
			* @param enabled	enables the group (default is true) */
			void setEnabled(bool enabled);
			/*! Gets the enabled state of the connection
			*
			* @see setEnabled() */
			bool getEnabled() const;

			/*! Gets the status of this PubSub component.
			*
			* The status is calculated by the EnabledFlag, by an internal error status
			* and by the status of the parent (PubSub::Connection).
			*
			* @see EnumPubSubState, setEnabled(), PubSub::Connection::setEnabled() */
			EnumPubSubState getPubSubState() const;

			/*! Sets the security mode
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
			* @see IPubSubGroupDataType::addSecurityKeyService
			* @see EndpointDescription
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setSecurityKeyServices(const std::vector<EndpointDescription> &securityKeyServices);
			/*! Gets the SecurityKeyServices
			*
			* @see setSecurityKeyServices() */
			std::vector<EndpointDescription> getSecurityKeyServices() const;

			/*! Sets the MaxNetworkMessageSize
			*
			* @param maxNetworkMessageSize	the maxNetworkMessageSize of the group
			*
			* @see IPubSubGroupDataType::addSecurityKeyService
			* @note Default is 1400 byte */
			EnumStatusCode setMaxNetworkMessageSize(const OTUInt32 &maxNetworkMessageSize);
			/*! Gets the MaxNetworkMessageSize
			*
			* @see setMaxNetworkMessageSize() */
			OTUInt32 getMaxNetworkMessageSize() const;

			/*! Sets the properties of the group
			*
			* @param properties	The properties of the group
			*
			* @see IPubSubGroupDataType::addGroupProperty
			* @note  The properties are only used by AMQP transport (not yet supported).
			* All other transports will ignore all configured properties.
			*
			* @note <b>This functionality is not yet implemented - any configuration done here is currently ignored.</b> */
			EnumStatusCode setProperties(const std::vector<KeyValuePair> &properties);
			/*! Gets the properties of the group
			*
			* @see setProperties()) */
			std::vector<KeyValuePair> getProperties() const;

			/*! Notification that that the state has changed
			*
			* Overwrite this method to implement specific handling if the state changes.
			*
			* @note The notification can result by changing the enabled state of this object or a "parent" object.
			*		It can be invoked as well independent on the enabled configuration, e.g. in case of errors.
			* @note This notification is executed asynchronously. Between detection of state change and notification, the state can have changed again. */
			virtual void onPubSubStateChanged(EnumPubSubState newState);

			/*! Returns the SDK API class of this node.
			*
			* A static cast to the class is possible without risk. */
			EnumApiClassType getApiClass() const;

			/*! Validates if this node is derived from the given API class.
			*
			* A static cast to this API class is possible without risk.
			*
			* @param apiClass		The API class which shall be verified
			* @return				true: This node is derived from the tested class type */
			bool isOfApiClass(EnumApiClassType apiClass) const;
		private:
			/*! Forbid use assignment operator */
			Group& operator=(const Group&);
			/*! Forbid use of copy constructor */
			Group(const Group&);
		};

		typedef ObjectPointer<Group>GroupPtr;
		typedef ObjectPointer<const Group> GroupConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif //PUBSUBGROUP_H
