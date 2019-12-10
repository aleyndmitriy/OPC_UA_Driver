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

#ifndef INNERWRITERGROUPDATATYPE_H
#define INNERWRITERGROUPDATATYPE_H

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

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerWriterGroupDataType
		: public IWriterGroupDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerWriterGroupDataType();

		/*! Gets the WriterGroupId member of the class */
		virtual OTUInt16 getWriterGroupId() const;
		/*! Sets the WriterGroupId member in the class */
		virtual void setWriterGroupId(const OTUInt16& value);

		/*! Gets the PublishingInterval member of the class */
		virtual OTDouble getPublishingInterval() const;
		/*! Sets the PublishingInterval member in the class */
		virtual void setPublishingInterval(const OTDouble& value);

		/*! Gets the KeepAliveTime member of the class */
		virtual OTDouble getKeepAliveTime() const;
		/*! Sets the KeepAliveTime member in the class */
		virtual void setKeepAliveTime(const OTDouble& value);

		/*! Gets the Priority member of the class */
		virtual OTUInt8 getPriority() const;
		/*! Sets the Priority member in the class */
		virtual void setPriority(const OTUInt8& value);

		/*! Gets the LocaleIds member of the class */
		virtual std::vector<tstring> getLocaleIds() const;
		/*! Sets the LocaleIds member in the class */
		virtual EnumStatusCode setLocaleIds(const std::vector<tstring>& values);

		/*! Gets the TransportSettings member of the class */
		virtual WriterGroupTransportDataType getTransportSettings() const;
		/*! Sets the TransportSettings member in the class */
		virtual EnumStatusCode setTransportSettings(const IWriterGroupTransportDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const WriterGroupTransportDataType& value);

		/*! Gets the MessageSettings member of the class */
		virtual WriterGroupMessageDataType getMessageSettings() const;
		/*! Sets the MessageSettings member in the class */
		virtual EnumStatusCode setMessageSettings(const IWriterGroupMessageDataType* value);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const WriterGroupMessageDataType& value);

		/*! Gets the DataSetWriters member of the class */
		virtual std::vector<DataSetWriterDataType> getDataSetWriters() const;
		/*! Adds a DataSetWriter to the DataSetWriters member of the class */
		virtual EnumStatusCode addDataSetWriter(const IDataSetWriterDataType& value);

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const;
		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& value);

		/*! Gets the SecurityMode member of the class */
		virtual EnumMessageSecurityMode getSecurityMode() const;
		/*! Sets the SecurityMode member in the class */
		virtual void setSecurityMode(const EnumMessageSecurityMode& value);

		/*! Gets the SecurityGroupId member of the class */
		virtual tstring getSecurityGroupId() const;
		/*! Sets the SecurityGroupId member in the class */
		virtual void setSecurityGroupId(const tstring& value);

		/*! Gets the SecurityKeyServices member of the class */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const;
		/*! Adds a SecurityKeyService to the SecurityKeyServices member of the class */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService);

		/*! Gets the MaxNetworkMessageSize member of the class */
		virtual OTUInt32 getMaxNetworkMessageSize() const;
		/*! Sets the MaxNetworkMessageSize member in the class */
		virtual void setMaxNetworkMessageSize(const OTUInt32& value);

		/*! Gets the GroupProperties member of the class */
		virtual std::vector<KeyValuePair> getGroupProperties() const;
		/*! Adds a GroupProperty to the GroupProperties member of the class */
		virtual EnumStatusCode addGroupProperty(const IKeyValuePair& groupProperty);

		/*! For internal use only */
		void initInner(WriterGroupDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IWriterGroupDataType* pSrc);
		virtual EnumStatusCode set(const IWriterGroupDataType& pSrc);

		virtual int compare(const IWriterGroupDataType* other) const;
		virtual int compare(const IWriterGroupDataType& other) const;

		virtual bool operator==(const IWriterGroupDataType& other) const;
		virtual bool operator!=(const IWriterGroupDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerWriterGroupTransportDataType m_transportSettings;
		InnerWriterGroupMessageDataType m_messageSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataSetWriterDataType> m_pDataSetWriters)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pGroupProperties)

		WriterGroupDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
