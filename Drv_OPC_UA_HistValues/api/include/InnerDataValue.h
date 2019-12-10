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

#ifndef INNERDATAVALUE_H
#define INNERDATAVALUE_H

#include "IDataValue.h"
#include "InnerDateTime.h"
#include "DateTime.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerDataValue
	class TBC_EXPORT InnerDataValue
		: public IDataValue
	{
	public:
		/*! Destructor */
		virtual ~InnerDataValue();

		/*! The StatusCode that defines with the Server's ability to access/provide the value. */
		virtual EnumStatusCode getStatusCode() const;
		virtual void setStatusCode(EnumStatusCode value);

		/*! The source timestamp for the value given as UTC time. The source timestamp is the time where the value
		* was changed by the data source. */
		virtual const IDateTime* getSourceTimestamp() const;
		virtual IDateTime* getSourceTimestamp();
		virtual void setSourceTimestamp(const IDateTime* value);
		virtual void setSourceTimestamp(const DateTime& value);

		/*! The server timestamp of the returned value given in UTC time.
		*
		* The server timestamp is the time a server
		* @li received a value or
		* @li received the status for the value or
		* @li made the last trial to recover from a bad or uncertain status. */
		virtual const IDateTime* getServerTimestamp() const;
		virtual IDateTime* getServerTimestamp();
		virtual void setServerTimestamp(const IDateTime* value);
		virtual void setServerTimestamp(const DateTime& value);

		/*! Specifies the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
		* be added to the sourceTimestamp. */
		virtual unsigned short getSourcePicoseconds() const;
		virtual void setSourcePicoseconds(unsigned short value);

		/*! Specifies the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
		* be added to the serverTimestamp. */
		virtual unsigned short getServerPicoseconds() const;
		virtual void setServerPicoseconds(unsigned short value);

		/*! The contained value. */
		virtual const IValue* getValue() const;
		virtual IValue* getValue();
		virtual void setValue(const IValue* value);
		virtual void setValue(const Value& value);

		virtual tstring toString() const;

		// init from otb handle
		void initInner(DataValueStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDataValue* other) const;
		/*! @overload */
		virtual int compare(const IDataValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataValue& other) const;

		// set from interface
		EnumStatusCode set(const IDataValue* pSrc);
		EnumStatusCode set(const IDataValue& pSrc);

		// protected:
		// the handle to the related core object
		DataValueStruct* m_pDataValue_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerDateTime m_SourceTimestamp;
		InnerDateTime m_ServerTimestamp;
		InnerValue m_Value;
	};
}
#endif	// INNERDATAVALUE_H
