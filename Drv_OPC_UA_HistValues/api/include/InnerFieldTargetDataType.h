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

#ifndef INNERFIELDTARGETDATATYPE_H
#define INNERFIELDTARGETDATATYPE_H

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
#include "IValue.h"
#include "InnerValue.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerFieldTargetDataType
		: public IFieldTargetDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerFieldTargetDataType();

		/*! Gets the DataSetFieldId member of the class */
		virtual const IGuid* getDataSetFieldId() const;
		/*! Sets the DataSetFieldId member in the class */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId);
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& dataSetFieldId);

		/*! Gets the ReceiverIndexRange member of the class */
		virtual const INumericRange* getReceiverIndexRange() const;
		/*! Sets the ReceiverIndexRange member in the class */
		virtual EnumStatusCode setReceiverIndexRange(const INumericRange* value);
		/*! @overload */
		virtual EnumStatusCode setReceiverIndexRange(const NumericRange& value);

		/*! Gets the TargetNodeId member of the class */
		virtual const INodeId* getTargetNodeId() const;
		/*! Sets the TargetNodeId member in the class */
		virtual EnumStatusCode setTargetNodeId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setTargetNodeId(const NodeId& value);

		/*! Gets the AttributeId member of the class */
		virtual EnumAttributeId getAttributeId() const;
		/*! Sets the AttributeId member in the class */
		virtual void setAttributeId(EnumAttributeId value);

		/*! Gets the WriteIndexRange member of the class */
		virtual const INumericRange* getWriteIndexRange() const;
		/*! Sets the WriteIndexRange member in the class */
		virtual EnumStatusCode setWriteIndexRange(const INumericRange* value);
		/*! @overload */
		virtual EnumStatusCode setWriteIndexRange(const NumericRange& value);

		/*! Gets the OverrideValueHandling member of the class */
		virtual EnumOverrideValueHandling getOverrideValueHandling() const;
		/*! Sets the OverrideValueHandling member in the class */
		virtual void setOverrideValueHandling(const EnumOverrideValueHandling& value);

		/*! Gets the OverrideValue member of the class */
		virtual const IValue* getOverrideValue() const;
		/*! Sets the OverrideValue member in the class */
		virtual EnumStatusCode setOverrideValue(const IValue* value);
		/*! @overload */
		virtual EnumStatusCode setOverrideValue(const Value& value);

		/*! For internal use only */
		void initInner(FieldTargetDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IFieldTargetDataType* pSrc);
		virtual EnumStatusCode set(const IFieldTargetDataType& pSrc);

		virtual int compare(const IFieldTargetDataType* other) const;
		virtual int compare(const IFieldTargetDataType& other) const;

		virtual bool operator==(const IFieldTargetDataType& other) const;
		virtual bool operator!=(const IFieldTargetDataType& other) const;

		virtual void* getInternHandle() const;

	private:
		Guid m_dataSetFieldId;
		InnerNumericRange m_receiverIndexRange;
		InnerNodeId m_targetNodeId;
		InnerNumericRange m_writeIndexRange;
		InnerValue m_overrideValue;

		FieldTargetDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
