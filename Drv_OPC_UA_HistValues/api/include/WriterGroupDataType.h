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

#ifndef WRITERGROUPDATATYPE_H
#define WRITERGROUPDATATYPE_H

#include "IWriterGroupDataType.h"
#include "WriterGroupTransportDataType.h"
#include "IWriterGroupTransportDataType.h"
#include "InnerWriterGroupTransportDataType.h"
#include "WriterGroupMessageDataType.h"
#include "IWriterGroupMessageDataType.h"
#include "InnerWriterGroupMessageDataType.h"
#include "DataSetWriterDataType.h"
#include "IDataSetWriterDataType.h"
#include "InnerDataSetWriterDataType.h"
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
	/*! The WriterGroupDataType is used to store the configuration parameters for WriterGroups. */
	class TBC_EXPORT WriterGroupDataType
		: public IWriterGroupDataType
	{
	public:
		/*! Default constructor */
		WriterGroupDataType();
		/*! Constructs a copy of the given instance @p cp */
		WriterGroupDataType(const IWriterGroupDataType* cp);
		/*! @overload */
		WriterGroupDataType(const IWriterGroupDataType& cp);
		/*! @overload */
		WriterGroupDataType(const WriterGroupDataType& cp);

		/*! Destructor */
		virtual ~WriterGroupDataType();

		/* see IWriterGroupDataType::setName */
		virtual void setName(const tstring& name);
		/* see IWriterGroupDataType::getName */
		virtual tstring getName() const;

		/* see IWriterGroupDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IWriterGroupDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/* see IWriterGroupDataType::setSecurityMode */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode);
		/* see IWriterGroupDataType::getSecurityMode */
		virtual EnumMessageSecurityMode getSecurityMode() const;

		/* see IWriterGroupDataType::setSecurityGroupId */
		virtual void setSecurityGroupId(const tstring& securityGroupId);
		/* see IWriterGroupDataType::getSecurityGroupId */
		virtual tstring getSecurityGroupId() const;

		/* see IWriterGroupDataType::addSecurityKeyService */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService);
		/* see IWriterGroupDataType::getSecurityKeyServices */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const;

		/* see IWriterGroupDataType::setMaxNetworkMessageSize */
		virtual void setMaxNetworkMessageSize(const OTUInt32& maxNetworkMessageSize);
		/* see IWriterGroupDataType::getMaxNetworkMessageSize */
		virtual OTUInt32 getMaxNetworkMessageSize() const;

		/* see IWriterGroupDataType::addGroupProperty */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty);
		/* see IWriterGroupDataType::getGroupProperties */
		virtual std::vector<KeyValuePair> getGroupProperties() const;

		/* see IWriterGroupDataType::setWriterGroupId */
		virtual void setWriterGroupId(const OTUInt16& groupId);
		/* see IWriterGroupDataType::getWriterGroupId */
		virtual OTUInt16 getWriterGroupId() const;

		/* see IWriterGroupDataType::setPublishingInterval */
		virtual void setPublishingInterval(const OTDouble& publishingInterval);
		/* see IWriterGroupDataType::getPublishingInterval */
		virtual OTDouble getPublishingInterval() const;

		/* see IWriterGroupDataType::setKeepAliveTime */
		virtual void setKeepAliveTime(const OTDouble& keepAliveTime);
		/* see IWriterGroupDataType::getKeepAliveTime */
		virtual OTDouble getKeepAliveTime() const;

		/* see IWriterGroupDataType::setPriority */
		virtual void setPriority(const OTUInt8& priority);
		/* see IWriterGroupDataType::getPriority */
		virtual OTUInt8 getPriority() const;

		/* see IWriterGroupDataType::setLocaleIds */
		virtual EnumStatusCode setLocaleIds(const std::vector<tstring>& localeIds);
		/* see IWriterGroupDataType::getLocaleIds */
		virtual std::vector<tstring> getLocaleIds() const;

		/* see IWriterGroupDataType::setTransportSettings */
		virtual EnumStatusCode setTransportSettings(const IWriterGroupTransportDataType* transportSettings);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const WriterGroupTransportDataType& transportSettings);
		/* see IWriterGroupDataType::getTransportSettings */
		virtual WriterGroupTransportDataType getTransportSettings() const;

		/* see IWriterGroupDataType::setMessageSettings */
		virtual EnumStatusCode setMessageSettings(const IWriterGroupMessageDataType* messageSettings);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const WriterGroupMessageDataType& messageSettings);
		/* see IWriterGroupDataType::getMessageSettings */
		virtual WriterGroupMessageDataType getMessageSettings() const;

		/* see IWriterGroupDataType::addDataSetWriter */
		virtual EnumStatusCode addDataSetWriter(const IDataSetWriterDataType& writer);
		/* see IWriterGroupDataType::getDataSetWriters */
		virtual std::vector<DataSetWriterDataType> getDataSetWriters() const;

		/*! Assigns the contents of @p cp to this instance */
		WriterGroupDataType& operator=(const IWriterGroupDataType* cp);
		/*! @overload */
		WriterGroupDataType& operator=(const IWriterGroupDataType& cp);
		/*! @overload */
		WriterGroupDataType& operator=(const WriterGroupDataType& cp);

		/* see IWriterGroupDataType::compare(IWriterGroupDataType*) */
		virtual int compare(const IWriterGroupDataType* other) const;
		/*! @overload */
		virtual int compare(const IWriterGroupDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriterGroupDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriterGroupDataType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IWriterGroupDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupDataType& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerWriterGroupTransportDataType m_transportSettings;
		InnerWriterGroupMessageDataType m_messageSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataSetWriterDataType> m_pDataSetWriters)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pGroupProperties)

		WriterGroupDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
