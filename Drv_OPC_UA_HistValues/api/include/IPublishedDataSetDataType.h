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

#ifndef IPUBLISHEDDATASETDATATYPE_H
#define IPUBLISHEDDATASETDATATYPE_H

#include "PublishedDataSetDataTypeStruct.h"
#include "DataSetMetaDataType.h"
#include "IDataSetMetaDataType.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "PublishedDataSetSourceDataType.h"
#include "IPublishedDataSetSourceDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The interface to PublishedDataSetDataType, which is a type to store configuration data of a PubSub::PublishedDataSet.
	*
	* This structure is used e.g. in
	* @li structure class PubSubConfigurationDataType
	*
	* @note For additional information on the members see also PubSub::PublishedDataSet */
	class TBC_EXPORT IPublishedDataSetDataType
	{
	public:
		/*! Destructor */
		virtual ~IPublishedDataSetDataType(){};

		/*! Sets the Name member in the class
		*
		* @param  name		Name of the PublishedDataSet. The name of the PublishedDataSet shall be unique in the publisher. */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the DataSetFolder member in the class
		*
		* Optional path of the DataSet folder used to group PublishedDataSets where each entry in the string
		* array represents one level in a DataSet folder hierarchy.
		* If no grouping is needed the parameter is an empty array (default). */
		virtual EnumStatusCode setDataSetFolder(const std::vector<tstring>& dataSetFolder) = 0;
		/*! Gets the DataSetFolder member of the class */
		virtual std::vector<tstring> getDataSetFolder() const = 0;

		/*! Sets the DataSetMetaData member in the class
		*
		* @param metaData	DataSetMetaData describe the content and semantic of a DataSet. The order of the fields in the
		*					DataSetMetaData shall matches the order of DataSet fields when they are included in the published DataSetMessages. */
		virtual EnumStatusCode setDataSetMetaData(const IDataSetMetaDataType* metaData) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaData(const DataSetMetaDataType& metaData) = 0;
		/*! Gets the DataSetMetaData member of the class */
		virtual const IDataSetMetaDataType* getDataSetMetaData() const = 0;

		/*! Adds an ExtensionField to the ExtensionFields member of the class
		*
		* The ExtensionFields parameter allows the configuration of fields with values to be included in
		* the DataSet when the existing AddressSpace of the Publisher does not provide the necessary information. */
		virtual EnumStatusCode addExtensionField(const IKeyValuePair& extensionField) = 0;
		/*! Gets the ExtensionFields member of the class */
		virtual std::vector<KeyValuePair> getExtensionFields() const = 0;

		/*! Sets the DataSetSource member in the class
		*
		* The PublishedDataSetSourceDataType Structure is an abstract base type without fields for
		* the definition of the PublishedDataSet source. */
		virtual EnumStatusCode setDataSetSource(const IPublishedDataSetSourceDataType* dataSetSource) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetSource(const PublishedDataSetSourceDataType& dataSetSource) = 0;
		/*! Gets the DataSetSource member of the class */
		virtual PublishedDataSetSourceDataType getDataSetSource() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPublishedDataSetDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IPublishedDataSetDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedDataSetDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedDataSetDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPublishedDataSetDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedDataSetDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPublishedDataSetDataType
} // end namespace

#endif
