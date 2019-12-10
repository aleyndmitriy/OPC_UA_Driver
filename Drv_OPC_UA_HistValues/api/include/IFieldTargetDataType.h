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

#ifndef IFIELDTARGETDATATYPE_H
#define IFIELDTARGETDATATYPE_H

#include "FieldTargetDataTypeStruct.h"
#include "Guid.h"
#include "IGuid.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "NodeId.h"
#include "INodeId.h"
#include "Value.h"
#include "IValue.h"

namespace SoftingOPCToolbox5
{
	/*! The FieldTargetDataType contains the metadata for the relation between a
	* field in a DataSetMessage and a target variable in a DataSetReader. */
	class TBC_EXPORT IFieldTargetDataType
	{
	public:
		/*! Destructor */
		virtual ~IFieldTargetDataType(){};

		/*! Sets the DataSetFieldId member in the class
		* * @param pDataSetFieldId	The unique ID of the field in the DataSet.
		*							The fields and their unique IDs are defined in the DataSetMetaData Structure. */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& fieldId) = 0;
		/*! @see setDataSetFieldId() */
		virtual const IGuid* getDataSetFieldId() const = 0;

		/*! Sets the ReceiverIndexRange member in the class
		*
		* @param range		Index range used to extract parts of an array out of the received data.
		*					It is used to identify a single element of an array, or a single range of indexes for arrays for the received DataSet field.
		*					If a range of elements is specified, the values are returned as a composite. The first element is identified by index 0 (zero).
		*					This parameter is null if the specified Attribute is not an array.
		*					However, if the specified Attribute is an array, and this parameter is null, then the complete array is used. */
		virtual EnumStatusCode setReceiverIndexRange(const INumericRange* range) = 0;
		/*! @overload */
		virtual EnumStatusCode setReceiverIndexRange(const NumericRange& range) = 0;
		/*! @see setReceiverIndexRange() */
		virtual const INumericRange* getReceiverIndexRange() const = 0;

		/*! Sets the TargetNodeId member in the class
		*
		* @param targetNodeId	The NodeId of the Variable where to write the received DataSetMessage field value to. */
		virtual EnumStatusCode setTargetNodeId(const INodeId* targetNodeId) = 0;
		/*! @overload */
		virtual EnumStatusCode setTargetNodeId(const NodeId& targetNodeId) = 0;
		/*! Gets the TargetNodeId member of the class */
		virtual const INodeId* getTargetNodeId() const = 0;

		/*! Sets the AttributeId member in the class
		*
		* @param attributeId	Id of the attribute to write e.g. the EnumAttributeId_Value attribute. */
		virtual void setAttributeId(EnumAttributeId attributeId) = 0;
		/*! Gets the AttributeId member of the class */
		virtual EnumAttributeId getAttributeId() const = 0;

		/*! Sets the WriteIndexRange member in the class
		*
		* @param range		The index range used for writing received data to the target node.
		*					It is used to identify a single element of an array, or a single range of indexes for arrays
		*					for the write operation to the target Node.
		*					If a range of elements is specified, the values are written as a composite.
		*					This parameter is null if the specified Attribute is not an array.
		*					However, if the specified Attribute is an array, and this parameter is null, then the complete array is used. */
		virtual EnumStatusCode setWriteIndexRange(const INumericRange* range) = 0;
		/*! @overload */
		virtual EnumStatusCode setWriteIndexRange(const NumericRange& range) = 0;
		/*! @see setWriteIndexRange() */
		virtual const INumericRange* getWriteIndexRange() const = 0;

		/*! Sets the OverrideValueHandling member in the class. */
		virtual void setOverrideValueHandling(const EnumOverrideValueHandling& overrideValueHandling) = 0;
		/*! Gets the OverrideValueHandling member of the class */
		virtual EnumOverrideValueHandling getOverrideValueHandling() const = 0;

		/*! Sets the OverrideValue member in the class
		*
		* @param overrideValue	The value used if the OverrideValueHandling is set to EnumOverrideValueHandling_OverrideValue
		* and the State of the DataSetReader is not EnumPubSubState_Operational or if the corresponding field in the DataSet contains a Bad StatusCode. */
		virtual EnumStatusCode setOverrideValue(const IValue* overrideValue) = 0;
		/*! @overload */
		virtual EnumStatusCode setOverrideValue(const Value& overrideValue) = 0;
		/*! Gets the OverrideValue member of the class */
		virtual const IValue* getOverrideValue() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IFieldTargetDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IFieldTargetDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFieldTargetDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFieldTargetDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IFieldTargetDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IFieldTargetDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IFieldTargetDataType
} // end namespace

#endif
