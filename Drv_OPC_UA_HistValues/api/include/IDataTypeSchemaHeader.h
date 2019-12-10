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

#ifndef IDATATYPESCHEMAHEADER_H
#define IDATATYPESCHEMAHEADER_H

#include "DataTypeSchemaHeaderStruct.h"
#include "StructureDescription.h"
#include "IStructureDescription.h"
#include "EnumDescription.h"
#include "IEnumDescription.h"
#include "SimpleTypeDescription.h"
#include "ISimpleTypeDescription.h"

namespace SoftingOPCToolbox5
{
	/*! The interface to DataTypeSchemaHeader, which is an abstract base type used to provide OPC UA DataType definitions
	* for an OPC UA Binary encoded byte blob used outside an OPC UA Server AddressSpace. */
	class TBC_EXPORT IDataTypeSchemaHeader
	{
	public:
		/*! Destructor */
		virtual ~IDataTypeSchemaHeader(){};

		/*! Sets the Namespaces member in the class
		*
		* @param namespaces		Defines an array of namespace URIs. The index into the array is referred to as NamespaceIndex.
		*						The NamespaceIndex is used in NodeIds and QualifiedNames, rather than the longer namespace URI.
		*						NamespaceIndex 0 is reserved for the OPC UA namespace and it is not included in this array.
		*						The array contains the namespaces used in the data that follows the DataTypeSchemaHeader.
		*						The index used in NodeId and QualifiedNames identify an element in this list.
		*						The first entry in this array maps to NamespaceIndex 1. */
		virtual EnumStatusCode setNamespaces(const std::vector<tstring>& namespaces) = 0;
		/*! Gets the Namespaces member of the class */
		virtual std::vector<tstring> getNamespaces() const = 0;

		/*! Adds a StructureDataType to the StructureDataTypes member of the class
		*
		* @param structureDescription	Description of structure and Union (not yet supported) DataTypes used in the data
		*								that follows the DataTypeSchemaHeader. This includes nested structures.
		*								DataType NodeIds for Structure DataTypes used in the data refer to entries in this array. */
		virtual EnumStatusCode addStructureDataType(const IStructureDescription& structureDescription) = 0;
		/*! Gets the StructureDataTypes member of the class */
		virtual std::vector<StructureDescription> getStructureDataTypes() const = 0;

		/*! Adds a EnumDataType to the EnumDataTypes member of the class
		*
		* @param enumDescription		Description of Enumeration or OptionSet DataTypes used in in the data that follows the DataTypeSchemaHeader.
		*								DataType NodeIds for Enumeration or OptionSet (not yet supported) DataTypes used in the data refer to entries in this array. */
		virtual EnumStatusCode addEnumDataType(const IEnumDescription& enumDescription) = 0;
		/*! Gets the EnumDataTypes member of the class */
		virtual std::vector<EnumDescription> getEnumDataTypes() const = 0;

		/*! Adds a SimpleDataType to the SimpleDataTypes member of the class
		*
		* @param simpleTypeDescription	Description of DataTypes derived from built-in DataTypes. This excludes OptionSet DataTypes. */
		virtual EnumStatusCode addSimpleDataType(const ISimpleTypeDescription& simpleTypeDescription) = 0;
		/*! Gets the SimpleDataTypes member of the class */
		virtual std::vector<SimpleTypeDescription> getSimpleDataTypes() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IDataTypeSchemaHeader* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataTypeSchemaHeader& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataTypeSchemaHeader& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataTypeSchemaHeader& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IDataTypeSchemaHeader* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataTypeSchemaHeader& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataTypeSchemaHeader
} // end namespace

#endif
