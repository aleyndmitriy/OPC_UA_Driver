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

#ifndef READERGROUPDATATYPE_H
#define READERGROUPDATATYPE_H

#include "IReaderGroupDataType.h"
#include "ReaderGroupTransportDataType.h"
#include "IReaderGroupTransportDataType.h"
#include "InnerReaderGroupTransportDataType.h"
#include "ReaderGroupMessageDataType.h"
#include "IReaderGroupMessageDataType.h"
#include "InnerReaderGroupMessageDataType.h"
#include "DataSetReaderDataType.h"
#include "IDataSetReaderDataType.h"
#include "InnerDataSetReaderDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "InnerEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ReaderGroupDataType is used to store the configuration parameters for ReaderGroups. */
	class TBC_EXPORT ReaderGroupDataType
		: public IReaderGroupDataType
	{
	public:
		/*! Default constructor */
		ReaderGroupDataType();
		/*! Constructs a copy of the given instance @p cp */
		ReaderGroupDataType(const IReaderGroupDataType* cp);
		/*! @overload */
		ReaderGroupDataType(const IReaderGroupDataType& cp);
		/*! @overload */
		ReaderGroupDataType(const ReaderGroupDataType& cp);

		/*! Destructor */
		virtual ~ReaderGroupDataType();

		/* see IPubSubGroupDataType::setName */
		virtual void setName(const tstring& name);
		/* see IPubSubGroupDataType::getName */
		virtual tstring getName() const;

		/* see IPubSubGroupDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IPubSubGroupDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/* see IPubSubGroupDataType::setSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode);
		/* see IPubSubGroupDataType::getSecurityMode */
		virtual EnumMessageSecurityMode getSecurityMode() const;

		/* see IPubSubGroupDataType::setSecurityGroupId */
		virtual void setSecurityGroupId(const tstring& securityGroupId);
		/* see IPubSubGroupDataType::getSecurityGroupId */
		virtual tstring getSecurityGroupId() const;

		/* see IPubSubGroupDataType::addSecurityKeyService */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService);
		/* see IPubSubGroupDataType::getSecurityKeyServices */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const;

		/* see IPubSubGroupDataType::setMaxNetworkMessageSize */
		virtual void setMaxNetworkMessageSize(const OTUInt32& value);
		/* see IPubSubGroupDataType::getMaxNetworkMessageSize */
		virtual OTUInt32 getMaxNetworkMessageSize() const;

		/* see IPubSubGroupDataType::addGroupProperty */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty);
		/* see IPubSubGroupDataType::getGroupProperties */
		virtual std::vector<KeyValuePair> getGroupProperties() const;

		/* see IReaderGroupDataType::setTransportSettings */
		virtual EnumStatusCode setTransportSettings(const IReaderGroupTransportDataType* transportSettings);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ReaderGroupTransportDataType& transportSettings);
		/* see IReaderGroupDataType::getTransportSettings */
		virtual ReaderGroupTransportDataType getTransportSettings() const;

		/* see IReaderGroupDataType::setName */
		virtual EnumStatusCode setMessageSettings(const IReaderGroupMessageDataType* messageSettings);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const ReaderGroupMessageDataType& messageSettings);
		/* see IReaderGroupDataType::getMessageSettings */
		virtual ReaderGroupMessageDataType getMessageSettings() const;

		/* see IReaderGroupDataType::addDataSetReader */
		virtual EnumStatusCode addDataSetReader(const IDataSetReaderDataType& reader);
		/* see IReaderGroupDataType::getDataSetReaders */
		virtual std::vector<DataSetReaderDataType> getDataSetReaders() const;

		/*! Assigns the contents of @p cp to this instance */
		ReaderGroupDataType& operator=(const IReaderGroupDataType* cp);
		/*! @overload */
		ReaderGroupDataType& operator=(const IReaderGroupDataType& cp);
		/*! @overload */
		ReaderGroupDataType& operator=(const ReaderGroupDataType& cp);

		/* see IReaderGroupDataType::compare(IReaderGroupDataType*) */
		virtual int compare(const IReaderGroupDataType* other) const;
		/*! @overload */
		virtual int compare(const IReaderGroupDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReaderGroupDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReaderGroupDataType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IReaderGroupDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IReaderGroupDataType& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerReaderGroupTransportDataType m_transportSettings;
		InnerReaderGroupMessageDataType m_messageSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataSetReaderDataType> m_pDataSetReaders)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pGroupProperties)

		ReaderGroupDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
