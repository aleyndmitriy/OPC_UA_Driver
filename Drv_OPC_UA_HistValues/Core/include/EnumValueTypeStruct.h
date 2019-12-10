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

#ifndef _EnumValueTypeStruct_H_
#define _EnumValueTypeStruct_H_

#include "LocalizedTextStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(EnumValueTypeStruct::clear, cleanup)
//lint -sem(EnumValueTypeStruct::init, initializer)
typedef struct TBCORE_IF EnumValueTypeStruct
{
	/*! The Integer representation of an Enumeration. */
	OTInt64 value;

	/*! A human-readable representation of the Value of the Enumeration. */
	LocalizedTextStruct displayName;

	/*! A localized description of the enumeration value. This field can contain an
	* empty string if no description is available. */
	LocalizedTextStruct description;

	EnumValueTypeStruct();
	EnumValueTypeStruct(const EnumValueTypeStruct&);

	EnumStatusCode set(const EnumValueTypeStruct&, bool targetIsMemberOfNode = false);
	EnumStatusCode get(EnumValueTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_EnumValueType&);
	EnumStatusCode get(OpcUa_EnumValueType&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const EnumValueTypeStruct& operator=(const EnumValueTypeStruct& cp);
	bool operator==(const EnumValueTypeStruct& toCompare) const;
	bool operator!=(const EnumValueTypeStruct& toCompare) const;
	bool operator<(const EnumValueTypeStruct& toCompare) const;
	bool operator>(const EnumValueTypeStruct& toCompare) const;

	int compare(const EnumValueTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~EnumValueTypeStruct(void);
} EnumValueTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
