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

#ifndef IFIELDMETADATA_H
#define IFIELDMETADATA_H

#include "FieldMetaDataStruct.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "NodeId.h"
#include "INodeId.h"
#include "Guid.h"
#include "IGuid.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"

namespace SoftingOPCToolbox5
{
	/*! The FieldMetaData data type contains the metadata for a field in a PublishedDataSet. */
	class TBC_EXPORT IFieldMetaData
	{
	public:
		/*! Destructor */
		virtual ~IFieldMetaData(){};

		/*! Sets the Name member in the class
		*
		* @param name		Name of the field.
		*					The name shall be unique in the DataSet. */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Description member in the class */
		virtual EnumStatusCode setDescription(const ILocalizedText* description) = 0;
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description) = 0;
		/*! Gets the Description member of the class */
		virtual const ILocalizedText* getDescription() const = 0;

		/*! Sets the FieldFlags member in the class */
		virtual void setFieldFlags(const EnumDataSetFieldFlags& flags) = 0;
		/*! Gets the FieldFlags member of the class */
		virtual EnumDataSetFieldFlags getFieldFlags() const = 0;

		/*! Sets the number of the built-in data type of this field.
		*
		* All data types are transferred in DataSetMessages as one of the built-in data types.
		* Built-in types are all data types (with NamespaceIndex 0) from EnumNumericNodeId_Null (0) to EnumNumericNodeId_DiagnosticInfo (25).
		* So in most cases the identifier of the DataType NodeId matches the built-in type.
		*
		* The following special cases must be handled in addition:
		* (1) Abstract types always have the built-in type EnumNumericNodeId_BaseDataType since they can result in
		*     different concrete types in a DataSetMessage.
		*     The dataType field may provide additional restrictions e.g. if the abstract type is Number.
		*     Abstract types shall not be used if the field is represented as RawData set by the
		*     DataSetFieldContentMask.
		* (2) Enumeration DataTypes are encoded as Int32. The Enumeration strings
		*     are defined through a DataType referenced through the dataType field.
		* (3) Structure and Union DataTypes are encoded as EnumNumericNodeId_Structure.
		*     The encoding rules are defined through a DataType referenced through the dataType field.
		* (4) DataTypes derived from built-in types have the BuiltInType of the corresponding base DataType.
		*     The concrete subtype is defined through the dataType field.
		* (5) OptionSet DataTypes are either encoded as one of the concrete UInteger
		*     DataTypes or as an instance of an OptionSetType in an ExtensionObject.
		*
		* @note OptionSet is not yet supported. */
		virtual void setBuiltInType(const OTUInt8& builtInType) = 0;
		/*! Gets the NodeId of the built-in data type of this field */
		virtual OTUInt8 getBuiltInType() const = 0;

		/*! Sets the NodeId of the DataType of this field.
		*
		* The NodeId of the DataType of this field.
		* If the DataType is an Enumeration or an OptionSet (not yet supported), the semantic of the
		* Enumeration DataType is provided through the enumDataTypes field of the DataSetMetaData.
		* If the DataType is a Structure or Union (not yet supported), the encoding and decoding description
		* of the Structure DataType is provided through the structureDataTypes field of the DataSetMetaData. */
		virtual EnumStatusCode setDataType(const INodeId* dataType) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataType(const NodeId& dataType) = 0;
		/*! Gets the DataType member of the class */
		virtual const INodeId* getDataType() const = 0;

		/*! Sets the ValueRank member in the class
		*
		* @param valueRank	Indicates whether the dataType is an array and how many dimensions the array has. */
		virtual void setValueRank(const OTInt32& valueRank) = 0;
		/*! Gets the ValueRank member of the class */
		virtual OTInt32 getValueRank() const = 0;

		/*! Sets the ArrayDimensions member in the class
		*
		* This field specifies the maximum supported length of each dimension.
		* If the maximum is unknown the value shall be 0.
		* The number of elements shall be equal to the value of the valueRank field.
		* This field shall be empty if valueRank = 0. */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions) = 0;
		/*! Gets the ArrayDimensions member of the class */
		virtual std::vector<OTUInt32> getArrayDimensions() const = 0;

		/*! Sets the MaxStringLength member in the class
		*
		* If the dataType field is a String or ByteString then this field specifies the maximum supported length.
		* If the maximum is unknown the value shall be 0.
		* If the dataType field is not a String or ByteString the value shall be 0.
		* If the valueRank is greater than 0 this field applies to each element of the array. */
		virtual void setMaxStringLength(const OTUInt32& maxStringLength) = 0;
		/*! Gets the MaxStringLength member of the class */
		virtual OTUInt32 getMaxStringLength() const = 0;

		/*! Sets the DataSetFieldId member in the class
		*
		* The dataSetFieldId shall be unique among all fields of one DataSet.
		* A change of the position of the field in the list shall not change the ID. */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& dataSetFieldId) = 0;
		/*! Gets the DataSetFieldId member of the class */
		virtual const IGuid* getDataSetFieldId() const = 0;

		/*! Adds a Property to the Properties member of the class
		*
		* A list of property values providing additional semantic for the field.
		* If at least one property value changes, the MajorVersion of the ConfigurationVersion shall be updated.
		* If the property is EngineeringUnits, the unit of the field value shall match the
		* unit of the FieldMetaData. */
		virtual EnumStatusCode addProperty(const IKeyValuePair& fieldProperty) = 0;
		/*! Gets the Properties member of the class */
		virtual std::vector<KeyValuePair> getProperties() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IFieldMetaData* other) const = 0;
		/*! @overload */
		virtual int compare(const IFieldMetaData& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFieldMetaData& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFieldMetaData& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IFieldMetaData* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IFieldMetaData& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IFieldMetaData
} // end namespace

#endif
