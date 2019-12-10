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

#ifndef DATASETMETADATATYPE_H
#define DATASETMETADATATYPE_H

#include "IDataSetMetaDataType.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"
#include "FieldMetaData.h"
#include "IFieldMetaData.h"
#include "InnerFieldMetaData.h"
#include "Guid.h"
#include "IGuid.h"
#include "ConfigurationVersionDataType.h"
#include "IConfigurationVersionDataType.h"
#include "InnerConfigurationVersionDataType.h"
#include "StructureDescription.h"
#include "IStructureDescription.h"
#include "InnerStructureDescription.h"
#include "EnumDescription.h"
#include "IEnumDescription.h"
#include "InnerEnumDescription.h"
#include "SimpleTypeDescription.h"
#include "ISimpleTypeDescription.h"
#include "InnerSimpleTypeDescription.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataSetMetaDataType provides the metadata for a PublishedDataSet. */
	class TBC_EXPORT DataSetMetaDataType
		: public IDataSetMetaDataType
	{
	public:
		/*! Default constructor */
		DataSetMetaDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetMetaDataType(const IDataSetMetaDataType* cp);
		/*! @overload */
		DataSetMetaDataType(const IDataSetMetaDataType& cp);
		/*! @overload */
		DataSetMetaDataType(const DataSetMetaDataType& cp);

		/*! Destructor */
		virtual ~DataSetMetaDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetMetaDataType& operator=(const IDataSetMetaDataType* cp);
		/*! @overload */
		DataSetMetaDataType& operator=(const IDataSetMetaDataType& cp);
		/*! @overload */
		DataSetMetaDataType& operator=(const DataSetMetaDataType& cp);

		/* see IDataSetMetaDataType::compare(IDataSetMetaDataType*) */
		virtual int compare(const IDataSetMetaDataType* other) const;
		/*! @overload */
		virtual int compare(const IDataSetMetaDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetMetaDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetMetaDataType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataSetMetaDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetMetaDataType& pSrc);

		/* see IDataSetMetaDataType::setName() */
		virtual void setName(const tstring& name);
		/* see IDataSetMetaDataType::getName() */
		virtual tstring getName() const;

		/* see IDataSetMetaDataType::setDescription() */
		virtual EnumStatusCode setDescription(const ILocalizedText* description);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description);
		/* see IDataSetMetaDataType::getDescription() */
		virtual const ILocalizedText* getDescription() const;

		/* see IDataSetMetaDataType::addField() */
		virtual EnumStatusCode addField(const IFieldMetaData& field);
		/* see IDataSetMetaDataType::getFields() */
		virtual std::vector<FieldMetaData> getFields() const;

		/* see IDataSetMetaDataType::setDataSetClassId() */
		virtual EnumStatusCode setDataSetClassId(const IGuid* pDataSetClassId);
		/*! @overload */
		virtual EnumStatusCode setDataSetClassId(const Guid& dataSetClassId);
		/* see IDataSetMetaDataType::getDataSetClassId() */
		virtual const IGuid* getDataSetClassId() const;

		/* see IDataSetMetaDataType::setConfigurationVersion() */
		virtual void setConfigurationVersion(const IConfigurationVersionDataType* version);
		/*! @overload */
		virtual void setConfigurationVersion(const ConfigurationVersionDataType& version);
		/* see IDataSetMetaDataType::getConfigurationVersion() */
		virtual const IConfigurationVersionDataType* getConfigurationVersion() const;

		/*! Sets the Namespaces member in the class
		*
		* @see IDataSetMetaDataType::setNamespaces() */
		virtual EnumStatusCode setNamespaces(const std::vector<tstring>& namespaces);
		/*! Gets the Namespaces member in the class
		*
		* @see IDataSetMetaDataType::getNamespaces() */
		virtual std::vector<tstring> getNamespaces() const;

		/*! Adds a StructureDataType to the StructureDataTypes member of the class
		*
		* @see IDataSetMetaDataType::addStructureDataType() */
		virtual EnumStatusCode addStructureDataType(const IStructureDescription& structureType);
		/*! Gets the StructureDataTypes member of the class
		*
		* @see IDataSetMetaDataType::addStructureDataType() */
		virtual std::vector<StructureDescription> getStructureDataTypes() const;

		/*! Adds a EnumDataType to the EnumDataTypes member of the class
		*
		* @see IDataSetMetaDataType::addEnumDataType() */
		virtual EnumStatusCode addEnumDataType(const IEnumDescription& enumType);
		/*! Gets the EnumDataTypes member of the class
		*
		* @see IDataSetMetaDataType::getEnumDataTypes() */
		virtual std::vector<EnumDescription> getEnumDataTypes() const;

		/*! Adds a SimpleDataType to the SimpleDataTypes member of the class
		*
		* @see IDataSetMetaDataType::addSimpleDataType() */
		virtual EnumStatusCode addSimpleDataType(const ISimpleTypeDescription& simpleType);
		/*! Gets the SimpleDataTypes member of the class
		*
		* @see IDataSetMetaDataType::getSimpleDataTypes() */
		virtual std::vector<SimpleTypeDescription> getSimpleDataTypes() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerLocalizedText m_description;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerFieldMetaData> m_pFields)
		Guid m_dataSetClassId;
		InnerConfigurationVersionDataType m_configurationVersion;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerStructureDescription> m_pStructureDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEnumDescription> m_pEnumDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleTypeDescription> m_pSimpleDataTypes)

		DataSetMetaDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
