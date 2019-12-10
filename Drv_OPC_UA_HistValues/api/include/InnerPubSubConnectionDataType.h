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

#ifndef INNERPUBSUBCONNECTIONDATATYPE_H
#define INNERPUBSUBCONNECTIONDATATYPE_H

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

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPubSubConnectionDataType
		: public IPubSubConnectionDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPubSubConnectionDataType();

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const;
		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& value);

		/*! Gets the PublisherId member of the class */
		virtual const IValue* getPublisherId() const;
		/*! Sets the PublisherId member in the class */
		virtual EnumStatusCode setPublisherId(const IValue* pPublisherId);
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& publisherId);

		/*! Gets the TransportProfileUri member of the class */
		virtual tstring getTransportProfileUri() const;
		/*! Sets the TransportProfileUri member in the class */
		virtual void setTransportProfileUri(const tstring& value);

		/*! Gets the Address member of the class */
		virtual NetworkAddressDataType getAddress() const;
		/*! Sets the Address member in the class */
		virtual EnumStatusCode setAddress(const INetworkAddressDataType* value);
		/*! @overload */
		virtual EnumStatusCode setAddress(const NetworkAddressDataType& value);

		/*! Gets the ConnectionProperties member of the class */
		virtual std::vector<KeyValuePair> getConnectionProperties() const;
		/*! Adds a ConnectionProperty to the ConnectionProperties member of the class */
		virtual EnumStatusCode addConnectionProperty(const IKeyValuePair& connectionProperty);

		/*! Gets the TransportSettings member of the class */
		virtual ConnectionTransportDataType getTransportSettings() const;
		/*! Sets the TransportSettings member in the class */
		virtual EnumStatusCode setTransportSettings(const IConnectionTransportDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ConnectionTransportDataType& value);

		/*! Gets the WriterGroups member of the class */
		virtual std::vector<WriterGroupDataType> getWriterGroups() const;
		/*! Adds a WriterGroup to the WriterGroups member of the class */
		virtual EnumStatusCode addWriterGroup(const IWriterGroupDataType& writerGroup);

		/*! Gets the ReaderGroups member of the class */
		virtual std::vector<ReaderGroupDataType> getReaderGroups() const;
		/*! Adds a ReaderGroup to the ReaderGroups member of the class */
		virtual EnumStatusCode addReaderGroup(const IReaderGroupDataType& readerGroup);

		/*! For internal use only */
		void initInner(PubSubConnectionDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPubSubConnectionDataType* pSrc);
		virtual EnumStatusCode set(const IPubSubConnectionDataType& pSrc);

		virtual int compare(const IPubSubConnectionDataType* other) const;
		virtual int compare(const IPubSubConnectionDataType& other) const;

		virtual bool operator==(const IPubSubConnectionDataType& other) const;
		virtual bool operator!=(const IPubSubConnectionDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerValue m_publisherId;
		InnerNetworkAddressDataType m_address;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pConnectionProperties)
		InnerConnectionTransportDataType m_transportSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerWriterGroupDataType> m_pWriterGroups)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerReaderGroupDataType> m_pReaderGroups)

		PubSubConnectionDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
