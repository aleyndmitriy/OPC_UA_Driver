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

#ifndef INNERDATASETWRITERDATATYPE_H
#define INNERDATASETWRITERDATATYPE_H

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

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataSetWriterDataType
		: public IDataSetWriterDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerDataSetWriterDataType();

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the Enabled member of the class */
		virtual OTBoolean getEnabled() const;
		/*! Sets the Enabled member in the class */
		virtual void setEnabled(const OTBoolean& value);

		/*! Gets the DataSetWriterId member of the class */
		virtual OTUInt16 getDataSetWriterId() const;
		/*! Sets the DataSetWriterId member in the class */
		virtual void setDataSetWriterId(const OTUInt16& value);

		/*! Gets the DataSetFieldContentMask member of the class */
		virtual EnumDataSetFieldContentMask getDataSetFieldContentMask() const;
		/*! Sets the DataSetFieldContentMask member in the class */
		virtual void setDataSetFieldContentMask(const EnumDataSetFieldContentMask& value);

		/*! Gets the KeyFrameCount member of the class */
		virtual OTUInt32 getKeyFrameCount() const;
		/*! Sets the KeyFrameCount member in the class */
		virtual void setKeyFrameCount(const OTUInt32& value);

		/*! Gets the DataSetName member of the class */
		virtual tstring getDataSetName() const;
		/*! Sets the DataSetName member in the class */
		virtual void setDataSetName(const tstring& value);

		/*! Gets the DataSetWriterProperties member of the class */
		virtual std::vector<KeyValuePair> getDataSetWriterProperties() const;
		/*! Adds a DataSetWriterProperty to the DataSetWriterProperties member of the class */
		virtual EnumStatusCode addDataSetWriterProperty(const IKeyValuePair& writerProperty);

		/*! Gets the TransportSettings member of the class */
		virtual DataSetWriterTransportDataType getTransportSettings() const;
		/*! Sets the TransportSettings member in the class */
		virtual EnumStatusCode setTransportSettings(const IDataSetWriterTransportDataType* value);
		/*! @overload */
		virtual EnumStatusCode setTransportSettings(const DataSetWriterTransportDataType& value);

		/*! Gets the MessageSettings member of the class */
		virtual DataSetWriterMessageDataType getMessageSettings() const;
		/*! Sets the MessageSettings member in the class */
		virtual EnumStatusCode setMessageSettings(const IDataSetWriterMessageDataType* value);
		/*! @overload */
		virtual EnumStatusCode setMessageSettings(const DataSetWriterMessageDataType& value);

		/*! For internal use only */
		void initInner(DataSetWriterDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IDataSetWriterDataType* pSrc);
		virtual EnumStatusCode set(const IDataSetWriterDataType& pSrc);

		virtual int compare(const IDataSetWriterDataType* other) const;
		virtual int compare(const IDataSetWriterDataType& other) const;

		virtual bool operator==(const IDataSetWriterDataType& other) const;
		virtual bool operator!=(const IDataSetWriterDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pDataSetWriterProperties)
		InnerDataSetWriterTransportDataType m_transportSettings;
		InnerDataSetWriterMessageDataType m_messageSettings;

		DataSetWriterDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
