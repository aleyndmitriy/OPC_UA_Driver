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

#ifndef PUBSUBCONNECTIONDATATYPE_H
#define PUBSUBCONNECTIONDATATYPE_H

#include "IPubSubConnectionDataType.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
#include "NetworkAddressDataType.h"
#include "INetworkAddressDataType.h"
#include "InnerNetworkAddressDataType.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"
#include "ConnectionTransportDataType.h"
#include "IConnectionTransportDataType.h"
#include "InnerConnectionTransportDataType.h"
#include "WriterGroupDataType.h"
#include "IWriterGroupDataType.h"
#include "InnerWriterGroupDataType.h"
#include "ReaderGroupDataType.h"
#include "IReaderGroupDataType.h"
#include "InnerReaderGroupDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The PubSubConnectionDataType is a type to store configuration data of a PubSub::Connection.
	*
	* This structure is used e.g. in
	* @li structure class PubSubConfigurationDataType
	* @li UA method AddConnection
	*
	* @note For additional information on the members see also PubSub::Connection */
	class TBC_EXPORT PubSubConnectionDataType
		: public IPubSubConnectionDataType
	{
	public:
		/*! Default constructor */
		PubSubConnectionDataType();
		/*! Constructs a copy of the given instance @p cp */
		PubSubConnectionDataType(const IPubSubConnectionDataType* cp);
		/*! @overload */
		PubSubConnectionDataType(const IPubSubConnectionDataType& cp);
		/*! @overload */
		PubSubConnectionDataType(const PubSubConnectionDataType& cp);

		/*! Destructor */
		virtual ~PubSubConnectionDataType();

		/* see IPubSubConnectionDataType::getName */
		virtual tstring getName() const;
		/* see IPubSubConnectionDataType::setName */
		virtual void setName(const tstring& name);

		/* see IPubSubConnectionDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IPubSubConnectionDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/* see IPubSubConnectionDataType::setPublisherId */
		virtual EnumStatusCode setPublisherId(const IValue* pPublisherId);
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& publisherId);
		/* see IPubSubConnectionDataType::getPublisherId */
		virtual const IValue* getPublisherId() const;

		/* see IPubSubConnectionDataType::setTransportProfileUri */
		virtual void setTransportProfileUri(const tstring& transportProfileUri);
		/* see IPubSubConnectionDataType::getTransportProfileUri */
		virtual tstring getTransportProfileUri() const;

		/* see IPubSubConnectionDataType::setAddress */
		virtual EnumStatusCode setAddress(const INetworkAddressDataType* address);
		/*! @overload */
		virtual EnumStatusCode setAddress(const NetworkAddressDataType& address);
		/* see IPubSubConnectionDataType::getAddress */
		virtual NetworkAddressDataType getAddress() const;

		/* see IPubSubConnectionDataType::addConnectionProperty */
		virtual EnumStatusCode addConnectionProperty(const IKeyValuePair& connectionProperty);
		/* see IPubSubConnectionDataType::getConnectionProperties */
		virtual std::vector<KeyValuePair> getConnectionProperties() const;

		/* see IPubSubConnectionDataType::setTransportSettings */
		virtual EnumStatusCode setTransportSettings(const IConnectionTransportDataType* transportSettings);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ConnectionTransportDataType& transportSettings);
		/* see IPubSubConnectionDataType::getTransportSettings */
		virtual ConnectionTransportDataType getTransportSettings() const;

		/* see IPubSubConnectionDataType::addWriterGroup */
		virtual EnumStatusCode addWriterGroup(const IWriterGroupDataType& writerGroup);
		/* see IPubSubConnectionDataType::getWriterGroups */
		virtual std::vector<WriterGroupDataType> getWriterGroups() const;

		/* see IPubSubConnectionDataType::addReaderGroup */
		virtual EnumStatusCode addReaderGroup(const IReaderGroupDataType& readerGroup);
		/* see IPubSubConnectionDataType::getReaderGroups */
		virtual std::vector<ReaderGroupDataType> getReaderGroups() const;

		/*! Assigns the contents of @p cp to this instance */
		PubSubConnectionDataType& operator=(const IPubSubConnectionDataType* cp);
		/*! @overload */
		PubSubConnectionDataType& operator=(const IPubSubConnectionDataType& cp);
		/*! @overload */
		PubSubConnectionDataType& operator=(const PubSubConnectionDataType& cp);

		/* see IPubSubConnectionDataType::compare(IPubSubConnectionDataType*) */
		virtual int compare(const IPubSubConnectionDataType* other) const;
		/*! @overload */
		virtual int compare(const IPubSubConnectionDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPubSubConnectionDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPubSubConnectionDataType& other) const;

		/* see IPubSubConnectionDataType::set(IPubSubConnectionDataType*) */
		virtual EnumStatusCode set(const IPubSubConnectionDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPubSubConnectionDataType& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerValue m_publisherId;
		InnerNetworkAddressDataType m_address;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pConnectionProperties)
		InnerConnectionTransportDataType m_transportSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerWriterGroupDataType> m_pWriterGroups)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerReaderGroupDataType> m_pReaderGroups)

		PubSubConnectionDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
