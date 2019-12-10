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

#ifndef PUBLISHEDVARIABLEDATATYPE_H
#define PUBLISHEDVARIABLEDATATYPE_H

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

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The PublishedVariableDataType represents the configuration information for one published variable.
	*
	* This class is used in the PublishedDataItemsDataType.
	*
	* @see PublishedDataItemsDataType::addPublishedData */
	class TBC_EXPORT PublishedVariableDataType
		: public IPublishedVariableDataType
	{
	public:
		/*! Default constructor */
		PublishedVariableDataType();
		/*! Constructs a copy of the given instance @p cp */
		PublishedVariableDataType(const IPublishedVariableDataType* cp);
		/*! @overload */
		PublishedVariableDataType(const IPublishedVariableDataType& cp);
		/*! @overload */
		PublishedVariableDataType(const PublishedVariableDataType& cp);

		/*! Destructor */
		virtual ~PublishedVariableDataType();

		/*! Assigns the contents of @p cp to this instance */
		PublishedVariableDataType& operator=(const IPublishedVariableDataType* cp);
		/*! @overload */
		PublishedVariableDataType& operator=(const IPublishedVariableDataType& cp);
		/*! @overload */
		PublishedVariableDataType& operator=(const PublishedVariableDataType& cp);

		/* see IPublishedVariableDataType::compare(IPublishedVariableDataType*) */
		virtual int compare(const IPublishedVariableDataType* other) const;
		/*! @overload */
		virtual int compare(const IPublishedVariableDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedVariableDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedVariableDataType& other) const;

		/* see IPublishedVariableDataType::set(IPublishedVariableDataType*) */
		virtual EnumStatusCode set(const IPublishedVariableDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedVariableDataType& pSrc);

		/* see IPublishedVariableDataType::setPublishedVariable */
		virtual EnumStatusCode setPublishedVariable(const INodeId* variableNodeId);
		/*! @overload */
		virtual EnumStatusCode setPublishedVariable(const NodeId& variableNodeId);
		/* see IPublishedVariableDataType::getPublishedVariable */
		virtual const INodeId* getPublishedVariable() const;

		/* see IPublishedVariableDataType::setAttributeId */
		virtual void setAttributeId(const EnumAttributeId& attributeId);
		/* see IPublishedVariableDataType::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;

		/* see IPublishedVariableDataType::setSamplingIntervalHint */
		virtual void setSamplingIntervalHint(const OTDouble& samplingIntervalHint);
		/* see IPublishedVariableDataType::getSamplingIntervalHint */
		virtual OTDouble getSamplingIntervalHint() const;

		/* see IPublishedVariableDataType::setDeadbandType */
		virtual void setDeadbandType(const EnumDeadbandType& deadbandType);
		/* see IPublishedVariableDataType::getDeadbandType */
		virtual EnumDeadbandType getDeadbandType() const;

		/* see IPublishedVariableDataType::setDeadbandValue */
		virtual void setDeadbandValue(const OTDouble& deadbandValue);
		/* see IPublishedVariableDataType::getDeadbandValue */
		virtual OTDouble getDeadbandValue() const;

		/* see IPublishedVariableDataType::setIndexRange */
		virtual EnumStatusCode setIndexRange(const INumericRange* range);
		/*! @overload */
		virtual EnumStatusCode setIndexRange(const NumericRange& range);
		/* see IPublishedVariableDataType::getIndexRange */
		virtual const INumericRange* getIndexRange() const;

		/* see IPublishedVariableDataType::setSubstituteValue */
		virtual EnumStatusCode setSubstituteValue(const IValue* substiutiteValue);
		/*! @overload */
		virtual EnumStatusCode setSubstituteValue(const Value& substiutiteValue);
		/* see IPublishedVariableDataType::getSubstituteValue */
		virtual const IValue* getSubstituteValue() const;

		/* see IPublishedVariableDataType::addMetaDataProperty */
		virtual EnumStatusCode addMetaDataProperty(const IQualifiedName& metaDataProperty);
		/* see IPublishedVariableDataType::getMetaDataProperties */
		virtual std::vector<QualifiedName> getMetaDataProperties() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNodeId m_publishedVariable;
		InnerNumericRange m_indexRange;
		InnerValue m_substituteValue;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerQualifiedName> m_pMetaDataProperties)

		PublishedVariableDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
