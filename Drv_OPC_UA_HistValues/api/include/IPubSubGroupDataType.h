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

#ifndef IPUBSUBGROUPDATATYPE_H
#define IPUBSUBGROUPDATATYPE_H

#include "PubSubGroupDataTypeStruct.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"

namespace SoftingOPCToolbox5
{
	/*! The interface to PubSubGroupDataType, which is an abstract base type to store configuration data of a PubSub::Group.
	*
	* Concrete subclasses are WriterGroupDataType and ReaderGroupDataType, which are used e.g. in
	* @li structure class PubSubConnectionDataType
	* @li UA method AddWriterGroup
	*
	* @note For additional information on the members see also PubSub::Group */
	class TBC_EXPORT IPubSubGroupDataType
	{
	public:
		/*! Destructor */
		virtual ~IPubSubGroupDataType(){};

		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const = 0;

		/*! Sets the SecurityMode member in the class
		*
		* The SecurityMode indicates the level of security applied to the
		* NetworkMessages published by a WriterGroup or received by a ReaderGroup.
		*
		* @param securityMode	security mode of the group
		* @see EnumMessageSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode) = 0;
		/*! Gets the SecurityMode member of the class */
		virtual EnumMessageSecurityMode getSecurityMode() const = 0;

		/*! Sets the SecurityGroupId
		*
		* The SecurityGroupId with DataType String is the identifier for a SecurityGroup
		* in the Security Key Server (SKS). It is unique within a SKS.
		*
		* The SecurityGroupId is irrelevant if the SecurityMode is EnumMessageSecurityMode_None.
		*
		* If the SecurityMode is not EnumMessageSecurityMode_None the SecurityGroupId identifies the SecurityGroup.
		* The SecurityGroupId defines the SecurityPolicy and the security keys used for
		* the NetworkMessage security.
		*
		* @param securityGroupId	the SecurityGroupId of this group
		*
		* @see setSecurityMode */
		virtual void setSecurityGroupId(const tstring& securityGroupId) = 0;
		/*! Gets the SecurityGroupId member of the class
		*
		* @see setSecurityGroupId() */
		virtual tstring getSecurityGroupId() const = 0;

		/*! Adds a SecurityKeyService to the SecurityKeyServices member of the class
		*
		* SecurityKeyServices is an array of the DataType EndpointDescription and defines
		* one or more Security Key Servers (SKS) that manage the security keys for the
		* SecurityGroup assigned to this Group.
		*
		* The SecurityKeyServices is irrelevant if the SecurityMode is EnumMessageSecurityMode_None.
		*
		* Each element in the array is an Endpoint for an SKS that can supply the security
		* keys for the SecurityGroupId. Multiple Endpoints exist because an SKS may support
		* multiple transport profiles and/or may have multiple redundant instances.
		*
		* @param securityKeyService		An additional securityKeyService of the group */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService) = 0;
		/*! Gets the SecurityKeyServices member of the class
		*
		* @see addSecurityKeyService */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const = 0;

		/*! Sets the MaxNetworkMessageSize member in the class
		*
		* The MaxNetworkMessageSize with DataType UInt32 indicates the maximum size in bytes
		* for NetworkMessages created by the WriterGroup. It refers to the size of the
		* complete NetworkMessage including padding and signature without any additional
		* headers added by the transport protocol mapping. If the size of a NetworkMessage
		* exceeds the MaxNetworkMessageSize, the behavior depends on the message mapping.
		*
		* The transport protocol mappings may define restrictions for the maximum value of
		* this parameter.
		*
		* @param maxNetworkMessageSize	the maxNetworkMessageSize of the group
		*
		* @note For UDP it is recommended to limit the MaxNetworkMessageSize plus additional
		* headers to a MTU size. The number of frames used for a UADP NetworkMessage influences
		* the probability that UADP NetworkMessages get lost. */
		virtual void setMaxNetworkMessageSize(const OTUInt32& maxNetworkMessageSize) = 0;
		/*! Gets the MaxNetworkMessageSize member of the class */
		virtual OTUInt32 getMaxNetworkMessageSize() const = 0;

		/*! Adds a GroupProperty to the GroupProperties member of the class
		*
		* The GroupProperties parameter is an array of DataType KeyValuePair that specifies
		* additional properties for the configured group. The KeyValuePair DataType consists
		* of a QualifiedName and a value of any type.
		*
		* The mapping of the name and value to concrete functionality may be defined by
		* transport protocol mappings, future versions of this specification or vendor
		* specific extensions.
		*
		* @param groupProperty	The GroupProperties
		*
		* @note  Group properties are only used by AMQP transport (not yet supported).
		* All other transports will ignore all configured properties. */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty) = 0;
		/*! Gets the GroupProperties member of the class */
		virtual std::vector<KeyValuePair> getGroupProperties() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPubSubGroupDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IPubSubGroupDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubGroupDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubGroupDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPubSubGroupDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubGroupDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPubSubGroupDataType
} // end namespace

#endif
