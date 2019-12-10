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

#ifndef PUBLISHEDDATASETDATATYPE_H
#define PUBLISHEDDATASETDATATYPE_H

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

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The PublishedDataSetDataType is a type to store configuration data of a PubSub::PublishedDataSet.
	*
	* This structure is used e.g. in
	* @li structure class PubSubConfigurationDataType
	*
	* @note For additional information on the members see also PubSub::PublishedDataSet */
	class TBC_EXPORT PublishedDataSetDataType
		: public IPublishedDataSetDataType
	{
	public:
		/*! Default constructor */
		PublishedDataSetDataType();
		/*! Constructs a copy of the given instance @p cp */
		PublishedDataSetDataType(const IPublishedDataSetDataType* cp);
		/*! @overload */
		PublishedDataSetDataType(const IPublishedDataSetDataType& cp);
		/*! @overload */
		PublishedDataSetDataType(const PublishedDataSetDataType& cp);

		/*! Destructor */
		virtual ~PublishedDataSetDataType();

		/*! Assigns the contents of @p cp to this instance */
		PublishedDataSetDataType& operator=(const IPublishedDataSetDataType* cp);
		/*! @overload */
		PublishedDataSetDataType& operator=(const IPublishedDataSetDataType& cp);
		/*! @overload */
		PublishedDataSetDataType& operator=(const PublishedDataSetDataType& cp);

		/*! @see IPublishedDataSetDataType::compare(IPublishedDataSetDataType*) */
		virtual int compare(const IPublishedDataSetDataType* other) const;
		/*! @overload */
		virtual int compare(const IPublishedDataSetDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedDataSetDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedDataSetDataType& other) const;

		/* see IPublishedDataSetDataType::set(IPublishedDataSetDataType*) */
		virtual EnumStatusCode set(const IPublishedDataSetDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedDataSetDataType& pSrc);

		/* see IPublishedDataSetDataType::getName */
		virtual tstring getName() const;
		/* see IPublishedDataSetDataType::setName */
		virtual void setName(const tstring& name);

		/* see IPublishedDataSetDataType::getDataSetFolder */
		virtual std::vector<tstring> getDataSetFolder() const;
		/* see IPublishedDataSetDataType::setDataSetFolder */
		virtual EnumStatusCode setDataSetFolder(const std::vector<tstring>& dataSetFolder);

		/* see IPublishedDataSetDataType::setDataSetMetaData */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* metaData);
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& metaData);
		/* see IPublishedDataSetDataType::getDataSetMetaData */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const;

		/* see IPublishedDataSetDataType::getExtensionFields */
		virtual std::vector<KeyValuePair> getExtensionFields() const;
		/* see IPublishedDataSetDataType::addExtensionField */
		virtual EnumStatusCode addExtensionField(const IKeyValuePair& extensionField);

		/* see IPublishedDataSetDataType::setDataSetSource */
		virtual EnumStatusCode setDataSetSource(const IPublishedDataSetSourceDataType* dataSetSource);
		/*! @overload */
		virtual EnumStatusCode setDataSetSource(const PublishedDataSetSourceDataType& dataSetSource);
		/* see IPublishedDataSetDataType::getDataSetSource */
		virtual PublishedDataSetSourceDataType getDataSetSource() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerDataSetMetaDataType m_dataSetMetaData;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pExtensionFields)
		InnerPublishedDataSetSourceDataType m_dataSetSource;

		PublishedDataSetDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
