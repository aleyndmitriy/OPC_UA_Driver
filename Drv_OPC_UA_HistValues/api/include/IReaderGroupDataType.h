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

#ifndef IREADERGROUPDATATYPE_H
#define IREADERGROUPDATATYPE_H

#include "ReaderGroupDataTypeStruct.h"
#include "ReaderGroupTransportDataType.h"
#include "IReaderGroupTransportDataType.h"
#include "ReaderGroupMessageDataType.h"
#include "IReaderGroupMessageDataType.h"
#include "DataSetReaderDataType.h"
#include "IDataSetReaderDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"

namespace SoftingOPCToolbox5
{
	/*! The ReaderGroupDataType is used to store the configuration parameters for PunSub ReaderGroups. */
	class TBC_EXPORT IReaderGroupDataType
	{
	public:
		/*! Destructor */
		virtual ~IReaderGroupDataType(){};

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

		/*! Sets the TransportSettings member in the class
		*
		* @param transportSettings	Transport mapping specific ReaderGroup parameters
		*
		* @note There is currently no transport protocol mapping specific setting defined. */
		virtual EnumStatusCode setTransportSettings(const IReaderGroupTransportDataType* transportSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ReaderGroupTransportDataType& transportSettings) = 0;
		/*! Gets the TransportSettings member of the class */
		virtual ReaderGroupTransportDataType getTransportSettings() const = 0;

		/*! Sets the MessageSettings member in the class
		*
		* @param messageSettings	NetworkMessage mapping specific ReaderGroup parameters. */
		virtual EnumStatusCode setMessageSettings(const IReaderGroupMessageDataType* messageSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const ReaderGroupMessageDataType& messageSettings) = 0;
		/*! Gets the MessageSettings member of the class */
		virtual ReaderGroupMessageDataType getMessageSettings() const = 0;

		/*! Adds a DataSetReader to the DataSetReaders member of the class
		*
		* @param reader		A DataSetReaders contained in the ReaderGroup. */
		virtual EnumStatusCode addDataSetReader(const IDataSetReaderDataType& reader) = 0;
		/*! Gets the DataSetReaders member of the class */
		virtual std::vector<DataSetReaderDataType> getDataSetReaders() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IReaderGroupDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IReaderGroupDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReaderGroupDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReaderGroupDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IReaderGroupDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IReaderGroupDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IReaderGroupDataType
} // end namespace

#endif
