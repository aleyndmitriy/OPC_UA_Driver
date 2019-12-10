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

#ifndef INNERPUBLISHEDVARIABLEDATATYPE_H
#define INNERPUBLISHEDVARIABLEDATATYPE_H

#include "IPublishedVariableDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "InnerNumericRange.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPublishedVariableDataType
		: public IPublishedVariableDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPublishedVariableDataType();

		/*! Gets the PublishedVariable member of the class */
		virtual const INodeId* getPublishedVariable() const;
		/*! Sets the PublishedVariable member in the class */
		virtual EnumStatusCode setPublishedVariable(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setPublishedVariable(const NodeId& value);

		/*! Gets the AttributeId member of the class */
		virtual EnumAttributeId getAttributeId() const;
		/*! Sets the AttributeId member in the class */
		virtual void setAttributeId(const EnumAttributeId& value);

		/*! Gets the SamplingIntervalHint member of the class */
		virtual OTDouble getSamplingIntervalHint() const;
		/*! Sets the SamplingIntervalHint member in the class */
		virtual void setSamplingIntervalHint(const OTDouble& value);

		/*! Gets the DeadbandType member of the class */
		virtual EnumDeadbandType getDeadbandType() const;
		/*! Sets the DeadbandType member in the class */
		virtual void setDeadbandType(const EnumDeadbandType& value);

		/*! Gets the DeadbandValue member of the class */
		virtual OTDouble getDeadbandValue() const;
		/*! Sets the DeadbandValue member in the class */
		virtual void setDeadbandValue(const OTDouble& value);

		/*! Gets the IndexRange member of the class */
		virtual const INumericRange* getIndexRange() const;
		/*! Sets the IndexRange member in the class */
		virtual EnumStatusCode setIndexRange(const INumericRange* value);
		/*! @overload */
		virtual EnumStatusCode setIndexRange(const NumericRange& value);

		/*! Gets the SubstituteValue member of the class */
		virtual const IValue* getSubstituteValue() const;
		/*! Sets the SubstituteValue member in the class */
		virtual EnumStatusCode setSubstituteValue(const IValue* value);
		/*! @overload */
		virtual EnumStatusCode setSubstituteValue(const Value& value);

		/*! Gets the MetaDataProperties member of the class */
		virtual std::vector<QualifiedName> getMetaDataProperties() const;
		/*! Adds a MetaDataProperty to the MetaDataProperties member of the class */
		virtual EnumStatusCode addMetaDataProperty(const IQualifiedName& metaDataProperty);

		/*! For internal use only */
		void initInner(PublishedVariableDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPublishedVariableDataType* pSrc);
		virtual EnumStatusCode set(const IPublishedVariableDataType& pSrc);

		virtual int compare(const IPublishedVariableDataType* other) const;
		virtual int compare(const IPublishedVariableDataType& other) const;

		virtual bool operator==(const IPublishedVariableDataType& other) const;
		virtual bool operator!=(const IPublishedVariableDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerNodeId m_publishedVariable;
		InnerNumericRange m_indexRange;
		InnerValue m_substituteValue;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerQualifiedName> m_pMetaDataProperties)

		PublishedVariableDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
