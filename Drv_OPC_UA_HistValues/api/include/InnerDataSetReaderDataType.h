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

#ifndef INNERDATASETREADERDATATYPE_H
#define INNERDATASETREADERDATATYPE_H

#include "IDataSetReaderDataType.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
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

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataSetReaderDataType
		: public IDataSetReaderDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerDataSetReaderDataType();

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
		virtual EnumStatusCode setPublisherId(const IValue* value);
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& value);

		/*! Gets the WriterGroupId member of the class */
		virtual OTUInt16 getWriterGroupId() const;
		/*! Sets the WriterGroupId member in the class */
		virtual void setWriterGroupId(const OTUInt16& value);

		/*! Gets the DataSetWriterId member of the class */
		virtual OTUInt16 getDataSetWriterId() const;
		/*! Sets the DataSetWriterId member in the class */
		virtual void setDataSetWriterId(const OTUInt16& value);

		/*! Gets the DataSetMetaData member of the class */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const;
		/*! Sets the DataSetMetaData member in the class */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& value);

		/*! Gets the DataSetFieldContentMask member of the class */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const;
		/*! Sets the DataSetFieldContentMask member in the class */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& value);

		/*! Gets the MessageReceiveTimeout member of the class */
		virtual OTDouble getMessageReceiveTimeout() const;
		/*! Sets the MessageReceiveTimeout member in the class */
		virtual void setMessageReceiveTimeout(const OTDouble& value);

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

		/*! Gets the DataSetReaderProperties member of the class */
		virtual std::vector<KeyValuePair> getDataSetReaderProperties() const;
		/*! Adds a DataSetReaderProperty to the DataSetReaderProperties member of the class */
		virtual EnumStatusCode addDataSetReaderProperty(const IKeyValuePair& readerProperty);

		/*! Gets the TransportSettings member of the class */
		virtual DataSetReaderTransportDataType getTransportSettings() const;
		/*! Sets the TransportSettings member in the class */
		virtual EnumStatusCode setTransportSettings(const IDataSetReaderTransportDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetReaderTransportDataType& value);

		/*! Gets the MessageSettings member of the class */
		virtual DataSetReaderMessageDataType getMessageSettings() const;
		/*! Sets the MessageSettings member in the class */
		virtual EnumStatusCode setMessageSettings(const IDataSetReaderMessageDataType* value);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetReaderMessageDataType& value);

		/*! Gets the SubscribedDataSet member of the class */
		virtual SubscribedDataSetDataType getSubscribedDataSet() const;
		/*! Sets the SubscribedDataSet member in the class */
		virtual EnumStatusCode setSubscribedDataSet(const ISubscribedDataSetDataType* value);
		/*! @overload */
		virtual EnumStatusCode setSubscribedDataSet(const SubscribedDataSetDataType& value);

		/*! For internal use only */
		void initInner(DataSetReaderDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IDataSetReaderDataType* pSrc);
		virtual EnumStatusCode set(const IDataSetReaderDataType& pSrc);

		virtual int compare(const IDataSetReaderDataType* other) const;
		virtual int compare(const IDataSetReaderDataType& other) const;

		virtual bool operator==(const IDataSetReaderDataType& other) const;
		virtual bool operator!=(const IDataSetReaderDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerValue m_publisherId;
		InnerDataSetMetaDataType m_dataSetMetaData;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pDataSetReaderProperties)
		InnerDataSetReaderTransportDataType m_transportSettings;
		InnerDataSetReaderMessageDataType m_messageSettings;
		InnerSubscribedDataSetDataType m_subscribedDataSet;

		DataSetReaderDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
