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

#ifndef INNERREADERGROUPDATATYPE_H
#define INNERREADERGROUPDATATYPE_H

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

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerReaderGroupDataType
		: public IReaderGroupDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerReaderGroupDataType();

		/*! Gets the TransportSettings member of the class */
		virtual ReaderGroupTransportDataType getTransportSettings() const;
		/*! Sets the TransportSettings member in the class */
		virtual EnumStatusCode setTransportSettings(const IReaderGroupTransportDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const ReaderGroupTransportDataType& value);

		/*! Gets the MessageSettings member of the class */
		virtual ReaderGroupMessageDataType getMessageSettings() const;
		/*! Sets the MessageSettings member in the class */
		virtual EnumStatusCode setMessageSettings(const IReaderGroupMessageDataType* value);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const ReaderGroupMessageDataType& value);

		/*! Gets the DataSetReaders member of the class */
		virtual std::vector<DataSetReaderDataType> getDataSetReaders() const;
		/*! Adds a DataSetReader to the DataSetReaders member of the class */
		virtual EnumStatusCode addDataSetReader(const IDataSetReaderDataType& reader);

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
		void initInner(ReaderGroupDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IReaderGroupDataType* pSrc);
		virtual EnumStatusCode set(const IReaderGroupDataType& pSrc);

		virtual int compare(const IReaderGroupDataType* other) const;
		virtual int compare(const IReaderGroupDataType& other) const;

		virtual bool operator==(const IReaderGroupDataType& other) const;
		virtual bool operator!=(const IReaderGroupDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerReaderGroupTransportDataType m_transportSettings;
		// pure virtual class - cannot be instantiated
		// InnerReaderGroupMessageDataType m_messageSettings;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataSetReaderDataType> m_pDataSetReaders)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEndpointDescription> m_pSecurityKeyServices)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pGroupProperties)

		ReaderGroupDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
