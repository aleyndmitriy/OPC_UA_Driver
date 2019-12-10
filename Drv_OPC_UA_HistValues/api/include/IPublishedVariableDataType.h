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

#ifndef IPUBLISHEDVARIABLEDATATYPE_H
#define IPUBLISHEDVARIABLEDATATYPE_H

#include "PublishedVariableDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "IValue.h"
#include "Value.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! Interface to PublishedVariableDataType, which represents the configuration information for one published variable.
	*
	* This class is used in the PublishedDataItemsDataType.
	*
	* @see PublishedDataItemsDataType::addPublishedData */
	class TBC_EXPORT IPublishedVariableDataType
	{
	public:
		/*! Destructor */
		virtual ~IPublishedVariableDataType(){};

		/*! Sets the PublishedVariable member in the class
		*
		* @param variableNodeId	The NodeId of the published Variable. */
		virtual EnumStatusCode setPublishedVariable(const INodeId* variableNodeId) = 0;
		/*! @overload */
		virtual EnumStatusCode setPublishedVariable(const NodeId& variableNodeId) = 0;
		/*! Gets the PublishedVariable member of the class */
		virtual const INodeId* getPublishedVariable() const = 0;

		/*! Sets the AttributeId member in the class
		*
		* Id of the Attribute to publish e.g. the EnumAttributeId_Value. */
		virtual void setAttributeId(const EnumAttributeId& attributeId) = 0;
		/*! Gets the AttributeId member of the class */
		virtual EnumAttributeId getAttributeId() const = 0;

		/*! Sets the SamplingIntervalHint member in the class
		*
		* A recommended rate of acquiring new values for change or deadband evaluation.
		* A Publisher should use this value as hint for setting the internal sampling rate.
		* The value 0 indicates that the Server should use the fastest practical rate.
		* The value -1 indicates that the default sampling interval defined by the PublishingInterval of the WriterGroup is requested.
		* Any negative number is interpreted as -1. */
		virtual void setSamplingIntervalHint(const OTDouble& samplingIntervalHint) = 0;
		/*! Gets the SamplingIntervalHint member of the class */
		virtual OTDouble getSamplingIntervalHint() const = 0;

		/*! Sets the DeadbandType member in the class */
		virtual void setDeadbandType(const EnumDeadbandType& deadbandType) = 0;
		/*! Gets the DeadbandType member of the class */
		virtual EnumDeadbandType getDeadbandType() const = 0;

		/*! Sets the the deadband value for the corresponding DeadbandType.
		*
		* The meaning of the value depends on EnumDeadbandType. */
		virtual void setDeadbandValue(const OTDouble& deadbandValue) = 0;
		/*! Gets the DeadbandValue member of the class */
		virtual OTDouble getDeadbandValue() const = 0;

		/*! Sets the IndexRange member in the class
		*
		* The index range is used to identify a single element of an array, or a single range of indexes for arrays. */
		virtual EnumStatusCode setIndexRange(const INumericRange* range) = 0;
		/*! @overload */
		virtual EnumStatusCode setIndexRange(const NumericRange& range) = 0;
		/*! Gets the IndexRange member of the class */
		virtual const INumericRange* getIndexRange() const = 0;

		/*! Sets the SubstituteValue member in the class
		*
		* The value that is included in the PublishedDataSet if the StatusCode of the DataValue is Bad.
		* In this case the StatusCode is set to Uncertain_SubstituteValue.
		* This Value shall match the DataType of the PublishedVariable since DataSetWriters may depend on a valid Value with the right PublishedDataSet
		* that matches the ConfigurationVersion.
		* If the SubstituteValue is Null, the StatusCode of the DataValue is processed. */
		virtual EnumStatusCode setSubstituteValue(const IValue* substiutiteValue) = 0;
		/*! @overload */
		virtual EnumStatusCode setSubstituteValue(const Value& substiutiteValue) = 0;
		/*! Gets the SubstituteValue member of the class */
		virtual const IValue* getSubstituteValue() const = 0;

		/*! Adds a MetaDataProperty to the MetaDataProperties member of the class
		*
		* This parameter specifies the BrowseNames of Property nodes of this Variable
		* It shall be used to populate the properties element of the resulting FieldMetaData in the DataSetMetaData. */
		virtual EnumStatusCode addMetaDataProperty(const IQualifiedName& metaDataProperty) = 0;
		/*! Gets the MetaDataProperties member of the class */
		virtual std::vector<QualifiedName> getMetaDataProperties() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPublishedVariableDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IPublishedVariableDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedVariableDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedVariableDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPublishedVariableDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedVariableDataType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPublishedVariableDataType
} // end namespace

#endif
