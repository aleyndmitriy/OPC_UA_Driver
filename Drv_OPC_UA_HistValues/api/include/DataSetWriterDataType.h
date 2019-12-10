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

#ifndef DATASETWRITERDATATYPE_H
#define DATASETWRITERDATATYPE_H

#include "IDataSetWriterDataType.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"
#include "DataSetWriterTransportDataType.h"
#include "IDataSetWriterTransportDataType.h"
#include "InnerDataSetWriterTransportDataType.h"
#include "DataSetWriterMessageDataType.h"
#include "IDataSetWriterMessageDataType.h"
#include "InnerDataSetWriterMessageDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataSetWriterDataType is used to store the DataSetWriter parameters. */
	class TBC_EXPORT DataSetWriterDataType
		: public IDataSetWriterDataType
	{
	public:
		/*! Default constructor */
		DataSetWriterDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetWriterDataType(const IDataSetWriterDataType* cp);
		/*! @overload */
		DataSetWriterDataType(const IDataSetWriterDataType& cp);
		/*! @overload */
		DataSetWriterDataType(const DataSetWriterDataType& cp);

		/*! Destructor */
		virtual ~DataSetWriterDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetWriterDataType& operator=(const IDataSetWriterDataType* cp);
		/*! @overload */
		DataSetWriterDataType& operator=(const IDataSetWriterDataType& cp);
		/*! @overload */
		DataSetWriterDataType& operator=(const DataSetWriterDataType& cp);

		/* see IDataSetWriterDataType::compare(IDataSetWriterDataType*) */
		virtual int compare(const IDataSetWriterDataType* other) const;
		/*! @overload */
		virtual int compare(const IDataSetWriterDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetWriterDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetWriterDataType& other) const;

		/* see IDataSetWriterDataType::set(IDataSetWriterDataType*) */
		virtual EnumStatusCode set(const IDataSetWriterDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetWriterDataType& pSrc);

		/* see IDataSetWriterDataType::setName */
		virtual void setName(const tstring& name);
		/* see IDataSetWriterDataType::getName */
		virtual tstring getName() const;

		/* see IDataSetWriterDataType::setEnabled */
		virtual void setEnabled(const OTBoolean& enabled);
		/* see IDataSetWriterDataType::getEnabled */
		virtual OTBoolean getEnabled() const;

		/* see IDataSetWriterDataType::setDataSetWriterId */
		virtual void setDataSetWriterId(const OTUInt16& writerId);
		/* see IDataSetWriterDataType::getDataSetWriterId */
		virtual OTUInt16 getDataSetWriterId() const;

		/* see IDataSetWriterDataType::setDataSetFieldContentMask */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& contentMask);
		/* see IDataSetWriterDataType::getDataSetFieldContentMask */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const;

		/* see IDataSetWriterDataType::setKeyFrameCount */
		virtual void setKeyFrameCount(const OTUInt32& keyFrameCount);
		/* see IDataSetWriterDataType::getKeyFrameCount */
		virtual OTUInt32 getKeyFrameCount() const;

		/* see IDataSetWriterDataType::setDataSetName */
		virtual void setDataSetName(const tstring& dataSetName);
		/* see IDataSetWriterDataType::getDataSetName */
		virtual tstring getDataSetName() const;

		/* see IDataSetWriterDataType::addDataSetWriterProperty */
		virtual EnumStatusCode addDataSetWriterProperty(const IKeyValuePair& writerProperty);
		/* see IDataSetWriterDataType::getDataSetWriterProperties */
		virtual std::vector<KeyValuePair> getDataSetWriterProperties() const;

		/* see IDataSetWriterDataType::setTransportSettings */
		virtual EnumStatusCode setTransportSettings(const IDataSetWriterTransportDataType* transportSettings);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetWriterTransportDataType& transportSettings);
		/* see IDataSetWriterDataType::getTransportSettings */
		virtual DataSetWriterTransportDataType getTransportSettings() const;

		/* see IDataSetWriterDataType::setMessageSettings */
		virtual EnumStatusCode setMessageSettings(const IDataSetWriterMessageDataType* messageSettings);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetWriterMessageDataType& messageSettings);
		/* see IDataSetWriterDataType::getMessageSettings */
		virtual DataSetWriterMessageDataType getMessageSettings() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pDataSetWriterProperties)
		InnerDataSetWriterTransportDataType m_transportSettings;
		InnerDataSetWriterMessageDataType m_messageSettings;

		DataSetWriterDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
