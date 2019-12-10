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

#ifndef _SubscribedDataSetMirrorDataTypeStruct_H_
#define _SubscribedDataSetMirrorDataTypeStruct_H_

#include "SubscribedDataSetDataTypeStruct.h"
#include "RolePermissionTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct SubscribedDataSetMirrorDataTypeInt;

//lint -sem(SubscribedDataSetMirrorDataTypeStruct::clear, cleanup)
//lint -sem(SubscribedDataSetMirrorDataTypeStruct::init, initializer)
struct TBCORE_IF SubscribedDataSetMirrorDataTypeStruct : public SubscribedDataSetDataTypeStruct
{
	const OTChar* getParentNodeName() const;

	EnumStatusCode setParentNodeName(const OTChar *name);

	RolePermissionTypeStruct *getRolePermissions(unsigned &count) const;

	EnumStatusCode setRolePermissions(const RolePermissionTypeStruct *permissions, unsigned count);

	EnumStatusCode addRolePermission(const RolePermissionTypeStruct &permission);

	SubscribedDataSetMirrorDataTypeStruct();
	SubscribedDataSetMirrorDataTypeStruct(const SubscribedDataSetMirrorDataTypeStruct&);
	SubscribedDataSetMirrorDataTypeStruct(const SubscribedDataSetDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const SubscribedDataSetMirrorDataTypeStruct&);
	EnumStatusCode set(const SubscribedDataSetDataTypeStruct&);
	EnumStatusCode get(SubscribedDataSetMirrorDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SubscribedDataSetMirrorDataType&);
	EnumStatusCode get(OpcUa_SubscribedDataSetMirrorDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const SubscribedDataSetMirrorDataTypeStruct& operator=(const SubscribedDataSetMirrorDataTypeStruct& cp);
	bool operator==(const SubscribedDataSetMirrorDataTypeStruct& toCompare) const;
	bool operator!=(const SubscribedDataSetMirrorDataTypeStruct& toCompare) const;
	bool operator<(const SubscribedDataSetMirrorDataTypeStruct& toCompare) const;
	bool operator>(const SubscribedDataSetMirrorDataTypeStruct& toCompare) const;

	int compare(const SubscribedDataSetMirrorDataTypeStruct* pTarget) const;

	void clear(void);
	~SubscribedDataSetMirrorDataTypeStruct(void);

protected:
	void init(void);
};

typedef struct SubscribedDataSetMirrorDataTypeStruct SubscribedDataSetMirrorDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
