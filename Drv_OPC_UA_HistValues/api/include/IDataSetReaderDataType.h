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

#ifndef IDATASETREADERDATATYPE_H
#define IDATASETREADERDATATYPE_H

#include "DataSetReaderDataTypeStruct.h"
#include "IValue.h"
#include "Value.h"
#include "DataSetMetaDataType.h"
#include "IDataSetMetaDataType.h"
#include "EndpointDescription.h"
#include "IEndpointDescription.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "DataSetReaderTransportDataType.h"
#include "IDataSetReaderTransportDataType.h"
#include "DataSetReaderMessageDataType.h"
#include "IDataSetReaderMessageDataType.h"
#include "SubscribedDataSetDataType.h"
#include "ISubscribedDataSetDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The DataSetReaderDataType is used to store the DataSetReader parameters. */
	class TBC_EXPORT IDataSetReaderDataType
	{
	public:
		/*! Destructor */
		virtual ~IDataSetReaderDataType(){};

		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& enabled) = 0;
		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const = 0;

		/*! Sets the PublisherId member in the class
		*
		* @param publisherId	The publisherId defines the publisher to receive NetworkMessages from.
		*
		* @note Only unsigned integers and strings are allowed as data types. */
		virtual EnumStatusCode setPublisherId(const IValue* publisherId) = 0;
		/*! @overload */
		virtual EnumStatusCode setPublisherId(const Value& publisherId) = 0;
		/*! Gets the PublisherId member of the class */
		virtual const IValue* getPublisherId() const = 0;

		/*! Sets the WriterGroupId member in the class
		*
		* @param groupdId	The groupId defines the identifier of the corresponding WriterGroup.
		*					The default value 0 means this parameter shall be ignored. */
		virtual void setWriterGroupId(const OTUInt16& groupdId) = 0;
		/*! Gets the WriterGroupId member of the class */
		virtual OTUInt16 getWriterGroupId() const = 0;

		/*! Sets the DataSetWriterId member in the class
		*
		* @param writerId	The parameter writerId defines the DataSet selected in the publisher for the DataSetReader.
		*					If the value is 0, the parameter shall be ignored and all received DataSetMessages pass the DataSetWriterId filter. */
		virtual void setDataSetWriterId(const OTUInt16& writerId) = 0;
		/*! Gets the DataSetWriterId member of the class */
		virtual OTUInt16 getDataSetWriterId() const = 0;

		/*! Sets the DataSetMetaData member in the class
		*
		* @param metaData	The metadata provides the information necessary to decode DataSetMessages from the publisher.
		*					If the DataSetMetaData changes in the publisher and the MajorVersion was changed,
		*					the DataSetReader needs an update of the DataSetMetaData for further operation.
		*					If the update cannot be retrieved in the duration of the MessageReceiveTimeout, the State of the
		*					DataSetReader shall change EnumPubSubState_Error. */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* metaData) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& metaData) = 0;
		/*! Gets the DataSetMetaData member of the class */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const = 0;

		/*! Sets the DataSetFieldContentMask member in the class
		*
		* @param contentMask	The contentMask indicates the fields of a DataValue included in the DataSetMessages. */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& contentMask) = 0;
		/*! Gets the DataSetFieldContentMask member of the class */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const = 0;

		/*! Sets the MessageReceiveTimeout member in the class
		*
		* @param receiveTimeout		The receiveTimeout is the maximum acceptable time between two DataSetMessages.
		*							If there is no DataSetMessage received within this period, the DataSetReader State shall be
		*							changed to EnumPubSubState_Error until the next DataSetMessage is received.
		*							The DataSetMessages can be data or keep alive messages.
		*							The MessageReceiveTimeout is related to the Publisher side parameters PublishingInterval, KeepAliveTime and KeyFrameCount. */
		virtual void setMessageReceiveTimeout(const OTDouble& receiveTimeout) = 0;
		/*! Gets the MessageReceiveTimeout member of the class */
		virtual OTDouble getMessageReceiveTimeout() const = 0;

		/*! Sets the SecurityMode member in the class
		*
		* @param securityMode	The SecurityMode indicates the level of security applied to the NetworkMessages published
		*						by a WriterGroup or received by a ReaderGroup.
		*
		* @note Currently only security mode EnumMessageSecurityMode_None is supported. */
		virtual void setSecurityMode(const EnumMessageSecurityMode& securityMode) = 0;
		/*! Gets the SecurityMode member of the class */
		virtual EnumMessageSecurityMode getSecurityMode() const = 0;

		/*! Sets the SecurityGroupId member in the class
		*
		* @param securityGroupId	The SecurityGroupId is the identifier for a SecurityGroup in the Security Key Server (SKS). It is unique within a SKS.
		*
		* @note Security is not yet supported. */
		virtual void setSecurityGroupId(const tstring& securityGroupId) = 0;
		/*! Gets the SecurityGroupId member of the class */
		virtual tstring getSecurityGroupId() const = 0;

		/*! Adds a SecurityKeyService to the SecurityKeyServices member of the class
		*
		* @param securityKeyService		SecurityKeyServices is an array of EndpointDescription and defines one or more
		*								Security Key Servers (SKS) that manage the security keys for the SecurityGroup assigned to the PubSubGroup.
		*
		* @note Security is not yet supported. */
		virtual EnumStatusCode addSecurityKeyService(const IEndpointDescription& securityKeyService) = 0;
		/*! Gets the SecurityKeyServices member of the class */
		virtual std::vector<EndpointDescription> getSecurityKeyServices() const = 0;

		/*! Adds a DataSetReaderProperty to the DataSetReaderProperties member of the class
		*
		* @param readerProperty		The DataSetReaderProperties parameter is an array of KeyValuePair that specifies additional properties
		*							for the configured DataSetReader.
		*							The mapping of the name and value to concrete functionality may be defined by transport protocol mappings,
		*							future versions of this specification or vendor specific extensions.
		*
		* @note DataSetReaderProperties are only necessary for AMQP transport (not yet supported) */
		virtual EnumStatusCode addDataSetReaderProperty(const IKeyValuePair& readerProperty) = 0;
		/*! Gets the DataSetReaderProperties member of the class */
		virtual std::vector<KeyValuePair> getDataSetReaderProperties() const = 0;

		/*! Sets the TransportSettings member in the class
		*
		* @param transportSettings	Transport specific DataSetReader parameters.
		*
		* @note Specific transport settings are only necessary for Broker transport (not yet supported) */
		virtual EnumStatusCode setTransportSettings(const IDataSetReaderTransportDataType* transportSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetReaderTransportDataType& transportSettings) = 0;
		/*! Gets the TransportSettings member of the class */
		virtual DataSetReaderTransportDataType getTransportSettings() const = 0;

		/*! Sets the MessageSettings member in the class
		*
		* @param messageSettings		Transport specific DataSetReader message parameters. */
		virtual EnumStatusCode setMessageSettings(const IDataSetReaderMessageDataType* messageSettings) = 0;
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetReaderMessageDataType& messageSettings) = 0;
		/*! Gets the MessageSettings member of the class */
		virtual DataSetReaderMessageDataType getMessageSettings() const = 0;

		/*! Sets the SubscribedDataSet member in the class
		* * @param dataSetParameters	The SubscribedDataSet specific parameters. */
		virtual EnumStatusCode setSubscribedDataSet(const ISubscribedDataSetDataType* dataSetParameters) = 0;
		/*! @overload */
		virtual EnumStatusCode setSubscribedDataSet(const SubscribedDataSetDataType& dataSetParameters) = 0;
		/*! Gets the SubscribedDataSet member of the class */
		virtual SubscribedDataSetDataType getSubscribedDataSet() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IDataSetReaderDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataSetReaderDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetReaderDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetReaderDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataSetReaderDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetReaderDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataSetReaderDataType
} // end namespace

#endif
