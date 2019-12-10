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

#ifndef IDATASETMETADATATYPE_H
#define IDATASETMETADATATYPE_H

#include "DataSetMetaDataTypeStruct.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "FieldMetaData.h"
#include "IFieldMetaData.h"
#include "Guid.h"
#include "IGuid.h"
#include "ConfigurationVersionDataType.h"
#include "IConfigurationVersionDataType.h"
#include "StructureDescription.h"
#include "IStructureDescription.h"
#include "EnumDescription.h"
#include "IEnumDescription.h"
#include "SimpleTypeDescription.h"
#include "ISimpleTypeDescription.h"

namespace SoftingOPCToolbox5
{
	/*! The DataSetMetaDataType used to store the metadata for a PublishedDataSet. */
	class TBC_EXPORT IDataSetMetaDataType
	{
	public:
		/*! Destructor */
		virtual ~IDataSetMetaDataType(){};
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;

		/*! Sets the Description member in the class */
		virtual EnumStatusCode setDescription(const ILocalizedText* description) = 0;
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description) = 0;
		/*! Gets the Description member of the class */
		virtual const ILocalizedText* getDescription() const = 0;

		/*! Adds the metadata of a field to the class */
		virtual EnumStatusCode addField(const IFieldMetaData& field) = 0;
		/*! Gets the field metadata of the class */
		virtual std::vector<FieldMetaData> getFields() const = 0;

		/*! Sets the DataSetClassId member in the class
		*
		* This field provides the globally unique identifier of the class of DataSet if the DataSet is based on a DataSetClass.
		* In this case, this field shall match the DataSetClassId of the concrete DataSet configuration.
		* If the DataSets are not created from a class, this field is null.
		*
		* A DataSetReader uses this class ID to filter network messages, if the class ID is not a NULL Guid. */
		virtual EnumStatusCode setDataSetClassId(const IGuid* pDataSetClassId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetClassId(const Guid& dataSetClassId) = 0;
		/*! Gets the DataSetClassId member of the class */
		virtual const IGuid* getDataSetClassId() const = 0;

		/*! Sets the ConfigurationVersion member in the class.
		*
		* @param version	The configuration version for the current configuration of the DataSet.
		*
		* @see ConfigurationVersionDataType */
		virtual void setConfigurationVersion(const IConfigurationVersionDataType* version) = 0;
		/*! @overload */
		virtual void setConfigurationVersion(const ConfigurationVersionDataType& version) = 0;
		/*! Gets the ConfigurationVersion member of the class */
		virtual const IConfigurationVersionDataType* getConfigurationVersion() const = 0;

		/*! Sets the Namespaces member in the class
		*
		* @see IDataTypeSchemaHeader::setNamespaces() */
		virtual EnumStatusCode setNamespaces(const std::vector<tstring>& namespaces) = 0;
		/*! Gets the Namespaces member of the class
		*
		* Qsee IDataTypeSchemaHeader::setNamespaces() */
		virtual std::vector<tstring> getNamespaces() const = 0;

		/*! Adds a StructureDataType to the StructureDataTypes member of the class
		*
		* @see IDataTypeSchemaHeader::addStructureDataType() */
		virtual EnumStatusCode addStructureDataType(const IStructureDescription& structureType) = 0;
		/*! Gets the StructureDataTypes member of the class
		*
		* @see IDataTypeSchemaHeader::addStructureDataType() */
		virtual std::vector<StructureDescription> getStructureDataTypes() const = 0;

		/*! Adds a EnumDataType to the EnumDataTypes member of the class
		*
		* @see IDataTypeSchemaHeader::addEnumDataType() */
		virtual EnumStatusCode addEnumDataType(const IEnumDescription& enumType) = 0;
		/*! Gets the EnumDataTypes member of the class
		*
		* @see IDataTypeSchemaHeader::addEnumDataType() */
		virtual std::vector<EnumDescription> getEnumDataTypes() const = 0;

		/*! Adds a SimpleDataType to the SimpleDataTypes member of the class
		*
		* see IDataTypeSchemaHeader::addSimpleDataType() */
		virtual EnumStatusCode addSimpleDataType(const ISimpleTypeDescription& simpleType) = 0;
		/*! Gets the SimpleDataTypes member of the class
		*
		* @see IDataTypeSchemaHeader::addSimpleDataType() */
		virtual std::vector<SimpleTypeDescription> getSimpleDataTypes() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IDataSetMetaDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataSetMetaDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetMetaDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetMetaDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataSetMetaDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetMetaDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataSetMetaDataType
} // end namespace

#endif
