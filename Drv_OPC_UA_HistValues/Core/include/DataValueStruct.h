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

#ifndef __DATAVALUESTRUCT_H_
#define __DATAVALUESTRUCT_H_

#include "DateTimeStruct.h"
#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*! Structure representing a Value send from a server either by a Subscription's report or as result of a
* Client::Session::Read() call.
*
* A DataValue has a contained Value and additional information (timestamps and status information). Always
* if values are exchanged between Client and Server this struct is used.
* On Server side the struct can be found in ReadRequests as return value and also in WriteRequests containing
* the Value to write into a Variable. */
//lint -sem(DataValueStruct::clear, cleanup)
//lint -sem(DataValueStruct::init, initializer)
typedef struct TBCORE_IF DataValueStruct
{
	/*! The StatusCode that defines with the Server's ability to access/provide the value. */
	EnumStatusCode statusCode;

	/*! The source timestamp for the value given as UTC time.The source timestamp is the time where the value
	* was changed by the data source. */
	DateTimeStruct sourceTimestamp;

	/*! The server timestamp of the returned value given in UTC time.
	*
	* The server timestamp is the time a server
	*
	* -- received a value or
	*
	* -- received the status for the value or
	*
	* -- made the last trial to recover from a bad or uncertain status. */
	DateTimeStruct serverTimestamp;

	/*! Specifies the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
	* be added to the sourceTimestamp. */
	unsigned short sourcePicoseconds;

	/*! Specifies the number of 10 picoseconds (1.0 e-11 seconds) intervals which shall
	* be added to the serverTimestamp. */
	unsigned short serverPicoseconds;

	/*! The contained value. */
	ValueStruct value;

	/*!
	 * Holds whether this DataValueStruct is a member variable of a node class
	 */
	bool isMemberOfNode;

	DataValueStruct();

	EnumStatusCode set(const DataValueStruct&);
	EnumStatusCode get(DataValueStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DataValue&, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_DataValue&, const std::vector<tstring>& preferredLocales) const;
#endif
//	EnumStatusCode set(EnumStatusCode statusCode, DateTimeStruct sourceTimestamp, unsigned short sourcePicoseconds, DateTimeStruct serverTimestamp, unsigned short serverPicoseconds, ValueStruct value);

	const DataValueStruct& operator=(const DataValueStruct& cp);
	bool operator==(const DataValueStruct& toCompare) const;
	bool operator!=(const DataValueStruct& toCompare) const;
	bool operator<(const DataValueStruct& toCompare) const;
	bool operator>(const DataValueStruct& toCompare) const;

	int compare(const DataValueStruct* pTarget) const;

	void clear(void);
	~DataValueStruct(void);
}DataValueStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
