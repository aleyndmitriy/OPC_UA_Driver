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

#ifndef IROLEPERMISSIONTYPE_H
#define IROLEPERMISSIONTYPE_H

#include "RolePermissionTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"

namespace SoftingOPCToolbox5
{
	/*! Specifies the Permissions that apply to a Node for all Roles which have access to the Node. */
	class TBC_EXPORT IRolePermissionType
	{
	public:
		/*! Destructor */
		virtual ~IRolePermissionType(){};

		/*! Sets the RoleId member in the class
		*
		* @param roleId		The NodeId of the Role Object. */
		virtual EnumStatusCode setRoleId(const INodeId* roleId) = 0;
		/*! @overload */
		virtual EnumStatusCode setRoleId(const NodeId& roleId) = 0;
		/*! Gets the RoleId member of the class */
		virtual const INodeId* getRoleId() const = 0;

		/*! Sets the Permissions member in the class
		*
		* @param permissions	A mask specifying which Permissions are available to the Role. */
		virtual void setPermissions(const OTUInt32& permissions) = 0;
		/*! Gets the Permissions member of the class */
		virtual OTUInt32 getPermissions() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IRolePermissionType* other) const = 0;
		/*! @overload */
		virtual int compare(const IRolePermissionType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRolePermissionType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRolePermissionType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IRolePermissionType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IRolePermissionType& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IRolePermissionType
} // end namespace

#endif
