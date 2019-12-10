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

#ifndef _SubscribedDataSetMirrorDataTypeInt_H_
#define _SubscribedDataSetMirrorDataTypeInt_H_

#include "SubscribedDataSetDataTypeInt.h"
#include "RolePermissionTypeStruct.h"
#include "Enums.h"

//lint -sem(SubscribedDataSetMirrorDataTypeInt::clearInternal, cleanup)
struct SubscribedDataSetMirrorDataTypeInt : public SubscribedDataSetDataTypeInt
{
	SubscribedDataSetMirrorDataTypeInt();
	SubscribedDataSetMirrorDataTypeInt(const SubscribedDataSetMirrorDataTypeInt &source);
	virtual ~SubscribedDataSetMirrorDataTypeInt();

	const OTChar* getParentNodeName() const;

	EnumStatusCode setParentNodeName(const OTChar *name);

	RolePermissionTypeStruct *getRolePermissions(unsigned &count) const;

	EnumStatusCode setRolePermissions(const RolePermissionTypeStruct *permissions, unsigned count);

	EnumStatusCode addRolePermission(const RolePermissionTypeStruct &permission);

	virtual SubscribedDataSetDataTypeInt *clone() const;
	virtual EnumStatusCode set(const SubscribedDataSetDataTypeInt &source);
	virtual int compare(const SubscribedDataSetDataTypeInt *pTarget) const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const SubscribedDataSetMirrorDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& extensionObject) const;

	EnumStatusCode set(const OpcUa_SubscribedDataSetMirrorDataType &source);
	EnumStatusCode get(OpcUa_SubscribedDataSetMirrorDataType &target) const;
#endif

protected:
	/*! The BrowseName and DisplayName of the parent Node for the Variables. */
	OTChar* pParentNodeName;

	/*! The value of the RolePermissions Attribute to be set on the parent Node. */
	RolePermissionTypeStruct* pRolePermissions;
	unsigned pRolePermissions_count;

	void clearInternal();

};

#endif //_SubscribedDataSetMirrorDataTypeInt_H_