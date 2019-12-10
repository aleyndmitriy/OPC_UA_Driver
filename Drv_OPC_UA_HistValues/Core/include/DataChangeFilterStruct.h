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

#ifndef __DATACHANGEFILTERSTRUCT_H_
#define __DATACHANGEFILTERSTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! Definition of a structure, able to store a filter definition as required by monitored items.
* @note It must have the same memory representation as OpcUa_DataChangeFilter */
//lint -sem(DataChangeFilterStruct::clear, cleanup)
//lint -sem(DataChangeFilterStruct::init, initializer)
typedef struct TBCORE_IF DataChangeFilterStruct
{
	/*! Defines the events/changes which can cause the value to be reported. */
	EnumDataChangeTrigger trigger;

	/*! The type of the deadband to apply.
	* The data type on OpcUa_DataChangeFilter is UInt32, but the highest bit (sign bit) is ensured to be always 0 */
	EnumDeadbandType deadbandType;

	/*! The value of the deadband. */
	double deadbandValue;


	DataChangeFilterStruct();

	EnumStatusCode set(const DataChangeFilterStruct&);
	EnumStatusCode get(DataChangeFilterStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DataChangeFilter&);
	EnumStatusCode get(OpcUa_DataChangeFilter&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const DataChangeFilterStruct& operator=(const DataChangeFilterStruct& cp);
	bool operator==(const DataChangeFilterStruct& toCompare) const;
	bool operator!=(const DataChangeFilterStruct& toCompare) const;
	bool operator<(const DataChangeFilterStruct& toCompare) const;
	bool operator>(const DataChangeFilterStruct& toCompare) const;

	int compare(const DataChangeFilterStruct* pTarget) const;

	void clear(void);
	~DataChangeFilterStruct(void);

}DataChangeFilterStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
