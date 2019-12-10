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

#ifndef _StructureDescriptionStruct_H_
#define _StructureDescriptionStruct_H_

#include "StructureDefinitionStruct.h"
#include "NodeIdStruct.h"
#include "QualifiedNameStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(StructureDescriptionStruct::clear, cleanup)
//lint -sem(StructureDescriptionStruct::init, initializer)
typedef struct TBCORE_IF StructureDescriptionStruct
{
	StructureDefinitionStruct structureDefinition;

	NodeIdStruct dataTypeId;

	QualifiedNameStruct name;


	StructureDescriptionStruct();
	StructureDescriptionStruct(const StructureDescriptionStruct&);

	EnumStatusCode set(const StructureDescriptionStruct&);
	EnumStatusCode get(StructureDescriptionStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_StructureDescription&);
	EnumStatusCode get(OpcUa_StructureDescription&, const std::vector<tstring>& preferredLocales) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif

	const StructureDescriptionStruct& operator=(const StructureDescriptionStruct& cp);
	bool operator==(const StructureDescriptionStruct& toCompare) const;
	bool operator!=(const StructureDescriptionStruct& toCompare) const;
	bool operator<(const StructureDescriptionStruct& toCompare) const;
	bool operator>(const StructureDescriptionStruct& toCompare) const;

	int compare(const StructureDescriptionStruct* pTarget) const;

	void clear(void);
	~StructureDescriptionStruct(void);
} StructureDescriptionStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
