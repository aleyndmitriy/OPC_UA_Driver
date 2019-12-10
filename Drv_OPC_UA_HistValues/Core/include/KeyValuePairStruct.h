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

#ifndef _KeyValuePairStruct_H_
#define _KeyValuePairStruct_H_

#include "QualifiedNameStruct.h"
#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

typedef struct TBCORE_IF KeyValuePairStruct
{
	QualifiedNameStruct key;

	ValueStruct value;

	KeyValuePairStruct();
	KeyValuePairStruct(const KeyValuePairStruct&);

	EnumStatusCode set(const KeyValuePairStruct&, bool targetIsMemberOfNode = false);
	EnumStatusCode get(KeyValuePairStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_KeyValuePair&);
	EnumStatusCode get(OpcUa_KeyValuePair&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const KeyValuePairStruct& operator=(const KeyValuePairStruct& cp);
	bool operator==(const KeyValuePairStruct& toCompare) const;
	bool operator!=(const KeyValuePairStruct& toCompare) const;
	bool operator<(const KeyValuePairStruct& toCompare) const;
	bool operator>(const KeyValuePairStruct& toCompare) const;

	int compare(const KeyValuePairStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~KeyValuePairStruct(void);
} KeyValuePairStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
