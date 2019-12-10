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

#ifndef FIELDTARGETDATATYPE_H
#define FIELDTARGETDATATYPE_H

#include "IFieldTargetDataType.h"
#include "Guid.h"
#include "IGuid.h"
#include "NumericRange.h"
#include "INumericRange.h"
#include "InnerNumericRange.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "Value.h"
#include "InnerValue.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The FieldTargetDataType contains the metadata for the relation between a
	* field in a DataSetMessage and a target Variable in a DataSetReader. */
	class TBC_EXPORT FieldTargetDataType
		: public IFieldTargetDataType
	{
	public:
		/*! Default constructor */
		FieldTargetDataType();
		/*! Constructs a copy of the given instance @p cp */
		FieldTargetDataType(const IFieldTargetDataType* cp);
		/*! @overload */
		FieldTargetDataType(const IFieldTargetDataType& cp);
		/*! @overload */
		FieldTargetDataType(const FieldTargetDataType& cp);

		/*! Destructor */
		virtual ~FieldTargetDataType();

		/*! Assigns the contents of @p cp to this instance */
		FieldTargetDataType& operator=(const IFieldTargetDataType* cp);
		/*! @overload */
		FieldTargetDataType& operator=(const IFieldTargetDataType& cp);
		/*! @overload */
		FieldTargetDataType& operator=(const FieldTargetDataType& cp);

		/* see IFieldTargetDataType::compare(IFieldTargetDataType*) */
		virtual int compare(const IFieldTargetDataType* other) const;
		/*! @overload */
		virtual int compare(const IFieldTargetDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFieldTargetDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFieldTargetDataType& other) const;

		/* see IFieldTargetDataType::set(IFieldTargetDataType*) */
		virtual EnumStatusCode set(const IFieldTargetDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IFieldTargetDataType& pSrc);

		/* see IFieldTargetDataType::setDataSetFieldId */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId);
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& dataSetFieldId);
		/* see IFieldTargetDataType::getDataSetFieldId */
		virtual const IGuid* getDataSetFieldId() const;

		/* see IFieldTargetDataType::setReceiverIndexRange */
		virtual EnumStatusCode setReceiverIndexRange(const INumericRange* range);
		/*! @overload */
		virtual EnumStatusCode setReceiverIndexRange(const NumericRange& range);
		/* see IFieldTargetDataType::getReceiverIndexRange */
		virtual const INumericRange* getReceiverIndexRange() const;

		/* see IFieldTargetDataType::setTargetNodeId */
		virtual EnumStatusCode setTargetNodeId(const INodeId* targetNodeId);
		/*! @overload */
		virtual EnumStatusCode setTargetNodeId(const NodeId& targetNodeId);
		/* see IFieldTargetDataType::getTargetNodeId */
		virtual const INodeId* getTargetNodeId() const;

		/* see IFieldTargetDataType::setAttributeId */
		virtual void setAttributeId(EnumAttributeId attributeId);
		/* see IFieldTargetDataType::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;

		/* see IFieldTargetDataType::setWriteIndexRange */
		virtual EnumStatusCode setWriteIndexRange(const INumericRange* range);
		/*! @overload */
		virtual EnumStatusCode setWriteIndexRange(const NumericRange& range);
		/* see IFieldTargetDataType::getWriteIndexRange */
		virtual const INumericRange* getWriteIndexRange() const;

		/* see IFieldTargetDataType::setOverrideValueHandling */
		virtual void setOverrideValueHandling(const EnumOverrideValueHandling& valoverrideValueHandlingue);
		/* see IFieldTargetDataType::getOverrideValueHandling */
		virtual EnumOverrideValueHandling getOverrideValueHandling() const;

		/* see IFieldTargetDataType::setOverrideValue */
		virtual EnumStatusCode setOverrideValue(const IValue* overrideValue);
		/*! @overload */
		virtual EnumStatusCode setOverrideValue(const Value& overrideValue);
		/* see IFieldTargetDataType::getOverrideValue */
		virtual const IValue* getOverrideValue() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		Guid m_dataSetFieldId;
		InnerNumericRange m_receiverIndexRange;
		InnerNodeId m_targetNodeId;
		InnerNumericRange m_writeIndexRange;
		InnerValue m_overrideValue;

		FieldTargetDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
