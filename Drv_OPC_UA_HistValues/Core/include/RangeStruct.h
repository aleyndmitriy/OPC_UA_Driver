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

#ifndef __RANGESTRUCT_H_
#define __RANGESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! Structure sued for transferring ranges. A range is a pair of doubles defining the low and the high end
* of the range. */
//lint -sem(RangeStruct::clear, cleanup)
//lint -sem(RangeStruct::init, initializer)
typedef struct TBCORE_IF RangeStruct
{
	/*! Lowest value in the range. */
	double low;

	/*! Highest value in the range. */
	double high;


	RangeStruct();

	EnumStatusCode set(const RangeStruct&);
	EnumStatusCode get(RangeStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_Range&);
	EnumStatusCode get(OpcUa_Range&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const RangeStruct& operator=(const RangeStruct& cp);
	bool operator==(const RangeStruct& toCompare) const;
	bool operator!=(const RangeStruct& toCompare) const;
	bool operator<(const RangeStruct& toCompare) const;
	bool operator>(const RangeStruct& toCompare) const;

	int compare(const RangeStruct* pTarget) const;

	void clear(void);
	~RangeStruct(void);

}RangeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
