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

#ifndef WRITEVALUE_H
#define WRITEVALUE_H

#include "IWriteValue.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "InnerNumericRange.h"
#include "NumericRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The WriteValue data type is used by the Write service (see Client::Session::write())
	* to specify a node and its attribute to write. */
	class TBC_EXPORT WriteValue
		: public IWriteValue
	{
	public:
		/*! Default constructor */
		WriteValue();
		/*! Constructs a copy of the given instance */
		WriteValue(const IWriteValue*);
		/*! @overload */
		WriteValue(const IWriteValue&);
		/*! @overload */
		WriteValue(const WriteValue&);

		/*! Destructor */
		virtual ~WriteValue();

		/*! Assigns the contents of @p cp to this instance */
		WriteValue& operator=(const IWriteValue* cp);
		/*! @overload */
		WriteValue& operator=(const IWriteValue& cp);
		/*! @overload */
		WriteValue& operator=(const WriteValue& cp);

		/* see IWriteValue::set */
		virtual EnumStatusCode set(const IWriteValue* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IWriteValue& pSrc);

		/* see IWriteValue::compare */
		virtual int compare(const IWriteValue*) const;
		/*! @overload */
		virtual int compare(const IWriteValue&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriteValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriteValue& other) const;

		/* see IWriteValue::getNodeId */
		virtual const INodeId* getNodeId() const;
		/*! @overload */
		virtual INodeId* getNodeId();
		/* see IWriteValue::setNodeId */
		virtual void setNodeId(const INodeId* value);
		/*! @overload */
		virtual void setNodeId(const NodeId& value);

		/* see IWriteValue::getAttributeId */
		virtual EnumAttributeId getAttributeId() const;
		/* see IWriteValue::setAttributeId */
		virtual void setAttributeId(EnumAttributeId value);

		/* see IWriteValue::getIndexRange */
		virtual const INumericRange* getIndexRange() const;
		/* see IWriteValue::setIndexRange */
		virtual void setIndexRange(const INumericRange* value);
		/*! @overload */
		virtual void setIndexRange(const NumericRange& value);

		/* see IWriteValue::getDataValue */
		virtual const IDataValue* getDataValue() const;
		/*! @overload */
		virtual IDataValue* getDataValue();
		/* see IWriteValue::setDataValue */
		virtual void setDataValue(const IDataValue* value);
		/*! @overload */
		virtual void setDataValue(const DataValue& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_NodeId;
		InnerDataValue m_Value;
		InnerNumericRange m_IndexRange;

		WriteValueStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// WRITEVALUE_H
