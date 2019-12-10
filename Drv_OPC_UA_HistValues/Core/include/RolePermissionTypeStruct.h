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

#ifndef _RolePermissionTypeStruct_H_
#define _RolePermissionTypeStruct_H_

#include "NodeIdStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(RolePermissionTypeStruct::clear, cleanup)
//lint -sem(RolePermissionTypeStruct::init, initializer)
typedef struct TBCORE_IF RolePermissionTypeStruct
{
	NodeIdStruct roleId;

	OTUInt32 permissions;


	RolePermissionTypeStruct();
	RolePermissionTypeStruct(const RolePermissionTypeStruct&);

	EnumStatusCode set(const RolePermissionTypeStruct&);
	EnumStatusCode get(RolePermissionTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_RolePermissionType&);
	EnumStatusCode get(OpcUa_RolePermissionType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const RolePermissionTypeStruct& operator=(const RolePermissionTypeStruct& cp);
	bool operator==(const RolePermissionTypeStruct& toCompare) const;
	bool operator!=(const RolePermissionTypeStruct& toCompare) const;
	bool operator<(const RolePermissionTypeStruct& toCompare) const;
	bool operator>(const RolePermissionTypeStruct& toCompare) const;

	int compare(const RolePermissionTypeStruct* pTarget) const;

	tstring toString() const;

	void clear(void);
	~RolePermissionTypeStruct(void);
} RolePermissionTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
