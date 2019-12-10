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

#ifndef _SimpleTypeDescriptionStruct_H_
#define _SimpleTypeDescriptionStruct_H_

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(SimpleTypeDescriptionStruct::clear, cleanup)
//lint -sem(SimpleTypeDescriptionStruct::init, initializer)
typedef struct TBCORE_IF SimpleTypeDescriptionStruct
{
	NodeIdStruct baseDataType;

	OTUInt8 builtInType;


	SimpleTypeDescriptionStruct();
	SimpleTypeDescriptionStruct(const SimpleTypeDescriptionStruct&);

	EnumStatusCode set(const SimpleTypeDescriptionStruct&);
	EnumStatusCode get(SimpleTypeDescriptionStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SimpleTypeDescription&);
	EnumStatusCode get(OpcUa_SimpleTypeDescription&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const SimpleTypeDescriptionStruct& operator=(const SimpleTypeDescriptionStruct& cp);
	bool operator==(const SimpleTypeDescriptionStruct& toCompare) const;
	bool operator!=(const SimpleTypeDescriptionStruct& toCompare) const;
	bool operator<(const SimpleTypeDescriptionStruct& toCompare) const;
	bool operator>(const SimpleTypeDescriptionStruct& toCompare) const;

	int compare(const SimpleTypeDescriptionStruct* pTarget) const;

	void clear(void);
	~SimpleTypeDescriptionStruct(void);
} SimpleTypeDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
