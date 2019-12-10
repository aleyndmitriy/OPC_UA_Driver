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

#ifndef INNERPUBLISHEDDATASETDATATYPE_H
#define INNERPUBLISHEDDATASETDATATYPE_H

#include "IPublishedDataSetDataType.h"
#include "DataSetMetaDataType.h"
#include "IDataSetMetaDataType.h"
#include "InnerDataSetMetaDataType.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"
#include "PublishedDataSetSourceDataType.h"
#include "IPublishedDataSetSourceDataType.h"
#include "InnerPublishedDataSetSourceDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPublishedDataSetDataType
		: public IPublishedDataSetDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPublishedDataSetDataType();

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the DataSetFolder member of the class */
		virtual std::vector<tstring> getDataSetFolder() const;
		/*! Sets the DataSetFolder member in the class */
		virtual EnumStatusCode setDataSetFolder(const std::vector<tstring>& values);

		/*! Gets the DataSetMetaData member of the class */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const;
		/*! Sets the DataSetMetaData member in the class */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& value);

		/*! Gets the ExtensionFields member of the class */
		virtual std::vector<KeyValuePair> getExtensionFields() const;
		/*! Adds a ExtensionField to the ExtensionFields member of the class */
		virtual EnumStatusCode addExtensionField(const IKeyValuePair& extensionField);

		/*! Gets the DataSetSource member of the class */
		virtual PublishedDataSetSourceDataType getDataSetSource() const;
		/*! Sets the DataSetSource member in the class */
		virtual EnumStatusCode setDataSetSource(const IPublishedDataSetSourceDataType* value);
		/*! @overload */
		virtual EnumStatusCode setDataSetSource(const PublishedDataSetSourceDataType& value);

		/*! For internal use only */
		void initInner(PublishedDataSetDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPublishedDataSetDataType* pSrc);
		virtual EnumStatusCode set(const IPublishedDataSetDataType& pSrc);

		virtual int compare(const IPublishedDataSetDataType* other) const;
		virtual int compare(const IPublishedDataSetDataType& other) const;

		virtual bool operator==(const IPublishedDataSetDataType& other) const;
		virtual bool operator!=(const IPublishedDataSetDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerDataSetMetaDataType m_dataSetMetaData;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pExtensionFields)
		InnerPublishedDataSetSourceDataType m_dataSetSource;

		PublishedDataSetDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
