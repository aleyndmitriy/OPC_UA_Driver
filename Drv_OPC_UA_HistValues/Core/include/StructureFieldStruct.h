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

#ifndef _StructureFieldStruct_H_
#define _StructureFieldStruct_H_

#include "LocalizedTextStruct.h"
#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(StructureFieldStruct::clear, cleanup)
//lint -sem(StructureFieldStruct::init, initializer)
typedef struct TBCORE_IF StructureFieldStruct
{
	OTChar* pName;

	LocalizedTextStruct description;

	NodeIdStruct dataType;

	OTInt32 valueRank;

	OTUInt32* pArrayDimensions;
	OTUInt32 arrayDimensions_count;

	OTUInt32 maxStringLength;

	OTBoolean isOptional;


	StructureFieldStruct();
	StructureFieldStruct(const StructureFieldStruct&);

	EnumStatusCode set(const StructureFieldStruct&);
	EnumStatusCode get(StructureFieldStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_StructureField&);
	EnumStatusCode get(OpcUa_StructureField&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const StructureFieldStruct& operator=(const StructureFieldStruct& cp);
	bool operator==(const StructureFieldStruct& toCompare) const;
	bool operator!=(const StructureFieldStruct& toCompare) const;
	bool operator<(const StructureFieldStruct& toCompare) const;
	bool operator>(const StructureFieldStruct& toCompare) const;

	int compare(const StructureFieldStruct* pTarget) const;

	void clear(void);
	~StructureFieldStruct(void);
} StructureFieldStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
