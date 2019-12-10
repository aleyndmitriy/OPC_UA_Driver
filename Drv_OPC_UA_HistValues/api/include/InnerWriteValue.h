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

#ifndef INNERWRITEVALUE_H
#define INNERWRITEVALUE_H

#include "IWriteValue.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerWriteValue
	class TBC_EXPORT InnerWriteValue
		: public IWriteValue
	{
	public:
		/*! Destructor */
		virtual ~InnerWriteValue();

		/*! The NodeId of the node to write on. */
		virtual const INodeId* getNodeId() const;
		virtual INodeId* getNodeId();
		virtual void setNodeId(const INodeId* value);
		virtual void setNodeId(const NodeId& value);

		/*! The AttributeId of the attribute that shall be written (see enumeration type for possible values). */
		virtual EnumAttributeId getAttributeId() const;
		virtual void setAttributeId(EnumAttributeId value);

		/*! The string based index range of the values to be written (applies only to array types). See also ReadValueId
		* for more details. */
		virtual const INumericRange* getIndexRange() const;
		virtual void setIndexRange(const INumericRange* value);
		virtual void setIndexRange(const NumericRange& value);

		/*! @see IWriteValue */
		virtual const IDataValue* getDataValue() const;
		virtual IDataValue* getDataValue();
		virtual void setDataValue(const IDataValue* value);
		virtual void setDataValue(const DataValue& value);

		// init from otb handle
		void initInner(WriteValueStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IWriteValue* other) const;
		/*! @overload */
		virtual int compare(const IWriteValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriteValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriteValue& other) const;

		// set from interface
		EnumStatusCode set(const IWriteValue* pSrc);
		EnumStatusCode set(const IWriteValue& pSrc);

		// protected:
		// the handle to the related core object
		WriteValueStruct* m_pWriteValue_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerNodeId m_NodeId;
		InnerDataValue m_Value;
		InnerNumericRange m_IndexRange;
	};
}
#endif	// INNERWRITEVALUE_H
