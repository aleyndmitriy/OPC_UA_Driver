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

#ifndef DATAVALUE_H
#define DATAVALUE_H

#include "IDataValue.h"
#include "InnerDateTime.h"
#include "DateTime.h"
#include "InnerValue.h"
#include "Value.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataValue data type is a complex type that contains a value along with its quality and timestamps.
	*
	* DataValues are returned by OPC UA servers as result of, for example, Read service calls (see Client::Session::read())
	* or via DataChange notifications (see Client::Subscription::onDataChange()). */
	class TBC_EXPORT DataValue
		: public IDataValue
	{
	public:
		/*! Default constructor */
		DataValue();
		/*! Constructs a copy of the given instance */
		DataValue(const IDataValue*);
		/*! @overload */
		DataValue(const IDataValue&);
		/*! @overload */
		DataValue(const DataValue&);

		/*! Destructor */
		virtual ~DataValue();

		/*! Assigns the contents of @p cp to this instance */
		DataValue& operator=(const IDataValue*);
		/*! @overload */
		DataValue& operator=(const IDataValue&);
		/*! @overload */
		DataValue& operator=(const DataValue&);

		/* see IDataValue::set */
		virtual EnumStatusCode set(const IDataValue* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataValue& pSrc);

		/* see IDataValue::compare */
		virtual int compare(const IDataValue*) const;
		/*! @overload */
		virtual int compare(const IDataValue&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataValue& other) const;

		/* see IDataValue::getValue */
		virtual const IValue* getValue() const;
		/*! @overload */
		virtual IValue* getValue();
		/* see IDataValue::setValue */
		virtual void setValue(const IValue* value);
		/*! @overload */
		virtual void setValue(const Value& value);

		/* see IDataValue::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;
		/* see IDataValue::setStatusCode */
		virtual void setStatusCode(EnumStatusCode value);

		/* see IDataValue::getSourceTimestamp */
		virtual const IDateTime* getSourceTimestamp() const;
		/*! @overload */
		virtual IDateTime* getSourceTimestamp();
		/* see IDataValue::setSourceTimestamp */
		virtual void setSourceTimestamp(const IDateTime* value);
		/*! @overload */
		virtual void setSourceTimestamp(const DateTime& value);

		/* see IDataValue::getSourcePicoseconds */
		virtual unsigned short getSourcePicoseconds() const;
		/* see IDataValue::setSourcePicoseconds */
		virtual void setSourcePicoseconds(unsigned short value);

		/* see IDataValue::getServerTimestamp */
		virtual const IDateTime* getServerTimestamp() const;
		/*! @overload */
		virtual IDateTime* getServerTimestamp();
		/* see IDataValue::setServerTimestamp */
		virtual void setServerTimestamp(const IDateTime* value);
		/*! @overload */
		virtual void setServerTimestamp(const DateTime& value);

		/* see IDataValue::getServerPicoseconds */
		virtual unsigned short getServerPicoseconds() const;
		/* see IDataValue::setServerPicoseconds */
		virtual void setServerPicoseconds(unsigned short value);

		/* see IDateValue::toString */
		virtual tstring toString() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerDateTime m_SourceTimestamp;
		InnerDateTime m_ServerTimestamp;
		InnerValue m_Value;

		DataValueStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATAVALUE_H
