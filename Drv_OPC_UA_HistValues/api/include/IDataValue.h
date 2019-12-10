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

#ifndef IDATAVALUE_H
#define IDATAVALUE_H

#include "DataValueStruct.h"
#include "InnerDateTime.h"
#include "DateTime.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The DataValue data type is a complex type that contains a value along with its quality and timestamps.
	*
	* DataValues are returned by OPC UA servers as result of, for example, Read service calls (see Client::Session::read())
	* or via DataChange notifications (see Client::Subscription::onDataChange()). */
	class TBC_EXPORT IDataValue
	{
	public:
		/*! Destructor */
		virtual ~IDataValue(){};

		/*! Returns the actual data value. If the status code indicates an error then the value
		* is to be ignored and the server shall set it to null. */
		virtual const IValue* getValue() const = 0;
		/*! @overload */
		virtual IValue* getValue() = 0;
		/*! Sets the actual data value. If the status code indicates an error then the value
		* is to be ignored and the server shall set it to null. */
		virtual void setValue(const IValue* value) = 0;
		/*! @overload */
		virtual void setValue(const Value& value) = 0;

		/*! Returns the status code that defines the server's ability to access and/or provide the value. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Sets the status code that defines the server's ability to access and/or provide the value. */
		virtual void setStatusCode(EnumStatusCode value) = 0;

		/*! Returns the source timestamp (in UTC time) of the value.
		*
		* @see setSourceTimestamp() */
		virtual const IDateTime* getSourceTimestamp() const = 0;
		/*! @overload */
		virtual IDateTime* getSourceTimestamp() = 0;
		/*! Sets the source timestamp (in UTC time) of the value.
		*
		* The source timestamp is used to reflect the timestamp that was applied to a value by the data source.
		* Once a value has been assigned a source timestamp, the source timestamp for that value instance never changes.
		* In this context, "value instance" refers to the value received, independent of its actual value. */
		virtual void setSourceTimestamp(const IDateTime* value) = 0;
		/*! @overload */
		virtual void setSourceTimestamp(const DateTime& value) = 0;

		/*! Returns the number of 10 picoseconds (1.0 e-11 seconds) intervals which are
		* added to the source timestamp. */
		virtual unsigned short getSourcePicoseconds() const = 0;
		/*! Sets the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
		* be added to the source timestamp.
		*
		* @see setSourceTimestamp() */
		virtual void setSourcePicoseconds(unsigned short value) = 0;

		/*! Returns the server timestamp (in UTC time) of the value.
		*
		* @see setServerTimestamp() */
		virtual const IDateTime* getServerTimestamp() const = 0;
		/*! @overload */
		virtual IDateTime* getServerTimestamp() = 0;
		/*! Sets the server timestamp (in UTC time) of the value.
		*
		* The server timestamp is the time a server
		* @li received a value or
		* @li received the status for the value or
		* @li made the last attempt to recover from a bad or uncertain status. */
		virtual void setServerTimestamp(const IDateTime* value) = 0;
		/*! @overload */
		virtual void setServerTimestamp(const DateTime& value) = 0;

		/*! Returns the number of 10 picoseconds (1.0 e-11 seconds) intervals which are
		* added to the server timestamp. */
		virtual unsigned short getServerPicoseconds() const = 0;
		/*! Sets the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
		* be added to the server timestamp.
		*
		* @see setServerTimestamp() */
		virtual void setServerPicoseconds(unsigned short value) = 0;

		/*! Returns a string representation of the DataValue for debugging purposes */
		virtual tstring toString() const = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IDataValue* source) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDataValue& source) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDataValue* other) const = 0;
		/*! @overload */
		virtual int compare(const IDataValue& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataValue& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataValue& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IDataValue
} // end namespace
#endif	// IDATAVALUE_H
