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

#ifndef DATASETREADERDATATYPE_H
#define DATASETREADERDATATYPE_H

#include "IDataSetReaderDataType.h"
#include "Value.h"
#include "DataSetMetaDataType.h"
#include "IDataSetMetaDataType.h"
#include "InnerDataSetMetaDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "InnerEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"
#include "DataSetReaderTransportDataType.h"
#include "IDataSetReaderTransportDataType.h"
#include "InnerDataSetReaderTransportDataType.h"
#include "DataSetReaderMessageDataType.h"
#include "IDataSetReaderMessageDataType.h"
#include "InnerDataSetReaderMessageDataType.h"
#include "SubscribedDataSetDataType.h"
#include "ISubscribedDataSetDataType.h"
#include "InnerSubscribedDataSetDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataSetReaderDataType is used to store the DataSetReader parameters. */
	class TBC_EXPORT DataSetReaderDataType
		: public IDataSetReaderDataType
	{
	public:
		/*! Default constructor */
		DataSetReaderDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetReaderDataType(const IDataSetReaderDataType* cp);
		/*! @overload */
		DataSetReaderDataType(const IDataSetReaderDataType& cp);
		/*! @overload */
		DataSetReaderDataType(const DataSetReaderDataType& cp);

		/*! Destructor */
		virtual ~DataSetReaderDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetReaderDataType& operator=(const IDataSetReaderDataType* cp);
		/*! @overload */
		DataSetReaderDataType& operator=(const IDataSetReaderDataType& cp);
		/*! @overload */
		DataSetReaderDataType& operator=(const DataSetReaderDataType& cp);

		/* see IDataSetReaderDataType::compare(IDataSetReaderDataType*) */
		virtual int compare(const IDataSetReaderDataType* other) const;
		/*! @overload */
		virtual int compare(const IDataSetReaderDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetReaderDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetReaderDataType& other) const;

		/* see IDataSetReaderDataType::set(IDataSetReaderDataType*) */
		virtual EnumStatusCode set(const IDataSetReaderDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetReaderDataType& pSrc);

		/* see IDataSetReaderDataType::setName() */
		virtual void setName(const tstring& name);
		/* see IDataSetReaderDataType::getName() */
		virtual tstring getName() const;

		/* see IDataSetReaderDataType::setEnabled() */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IDataSetReaderDataType::getEnabled() */
		virtual OTBoolean getEnabled() const;

		/* see IDataSetReaderType::setPublisherId */
		virtual EnumStatusCode setPublisherId(const IValue* publisherId);
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& publisherId);
		/* see IDataSetReaderType::getPublisherId */
		virtual const IValue* getPublisherId() const;

		/* see IDataSetReaderDataType::setWriterGroupId() */
		virtual void setWriterGroupId(const OTUInt16& groupdId);
		/* see IDataSetReaderDataType::getWriterGroupId() */
		virtual OTUInt16 getWriterGroupId() const;

		/* see IDataSetReaderDataType::setDataSetWriterId() */
		virtual void setDataSetWriterId(const OTUInt16& writerId);
		/* see IDataSetReaderDataType::getDataSetWriterId() */
		virtual OTUInt16 getDataSetWriterId() const;

		/* see IDataSetReaderDataType::setDataSetMetaData() */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* metaData);
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& metaData);
		/* see IDataSetReaderDataType::getDataSetMetaData() */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const;

		/* see IDataSetReaderDataType::setDataSetFieldContentMask() */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& contentMask);
		/* see IDataSetReaderDataType::getDataSetFieldContentMask() */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const;

		/* see IDataSetReaderDataType::setMessageReceiveTimeout() */
		virtual void setMessageReceiveTimeout(const OTDouble& receiveTimeout);
		/* see IDataSetReaderDataType::getMessageReceiveTimeout() */
		virtual OTDouble getMessageReceiveTimeout() const;

		/* see IDataSetReaderDataType::setSecurityMode() */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode);
		/* see IDataSetReaderDataType::getSecurityMode() */
		virtual EnumMessageSecurityMode getSecurityMode() const;

		/* see IDataSetReaderDataType::setSecurityGroupId() */
		virtual void setSecurityGroupId(const tstring& securityGroupId);
		/* see IDataSetReaderDataType::getSecurityGroupId() */
		virtual tstring getSecurityGroupId() const;

		/* see IDataSetReaderDataType::addSecurityKeyService() */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService);
		/* see IDataSetReaderDataType::getSecurityKeyServices() */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const;

		/* see IDataSetReaderDataType::addDataSetReaderProperty() */
		virtual EnumStatusCode addDataSetReaderProperty(const IKeyValuePair& readerProperty);
		/* see IDataSetReaderDataType::getDataSetReaderProperties() */
		virtual std::vector<KeyValuePair> getDataSetReaderProperties() const;

		/* see IDataSetReaderDataType::setTransportSettings() */
		virtual EnumStatusCode setTransportSettings(const IDataSetReaderTransportDataType* transportSettings);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetReaderTransportDataType& transportSettings);
		/* see IDataSetReaderDataType::getTransportSettings() */
		virtual DataSetReaderTransportDataType getTransportSettings() const;

		/* see IDataSetReaderDataType::setMessageSettings() */
		virtual EnumStatusCode setMessageSettings(const IDataSetReaderMessageDataType* messageSettings);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetReaderMessageDataType& messageSettings);
		/* see IDataSetReaderDataType::getMessageSettings() */
		virtual DataSetReaderMessageDataType getMessageSettings() const;

		/* see IDataSetReaderDataType::setSubscribedDataSet() */
		virtual EnumStatusCode setSubscribedDataSet(const ISubscribedDataSetDataType* dataSet);
		/*! @overload */
		virtual EnumStatusCode setSubscribedDataSet(const SubscribedDataSetDataType& dataSet);
		/* see IDataSetReaderDataType::getSubscribedDataSet() */
		virtual SubscribedDataSetDataType getSubscribedDataSet() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerValue m_publisherId;
		InnerDataSetMetaDataType m_dataSetMetaData;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pDataSetReaderProperties)
		InnerDataSetReaderTransportDataType m_transportSettings;
		InnerDataSetReaderMessageDataType m_messageSettings;
		InnerSubscribedDataSetDataType m_subscribedDataSet;

		DataSetReaderDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
