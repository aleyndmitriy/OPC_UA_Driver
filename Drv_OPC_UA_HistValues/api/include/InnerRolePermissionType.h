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

#ifndef INNERROLEPERMISSIONTYPE_H
#define INNERROLEPERMISSIONTYPE_H

#include "IRolePermissionType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerRolePermissionType
		: public IRolePermissionType
	{
	public:
		/*! Destructor */
		virtual ~InnerRolePermissionType();

		/*! Gets the RoleId member of the class */
		virtual const INodeId* getRoleId() const;
		/*! Sets the RoleId member in the class */
		virtual EnumStatusCode setRoleId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setRoleId(const NodeId& value);

		/*! Gets the Permissions member of the class */
		virtual OTUInt32 getPermissions() const;
		/*! Sets the Permissions member in the class */
		virtual void setPermissions(const OTUInt32& value);

		/*! For internal use only */
		void initInner(RolePermissionTypeStruct* pHandle);

		virtual EnumStatusCode set(const IRolePermissionType* pSrc);
		virtual EnumStatusCode set(const IRolePermissionType& pSrc);

		virtual int compare(const IRolePermissionType* other) const;
		virtual int compare(const IRolePermissionType& other) const;

		virtual bool operator==(const IRolePermissionType& other) const;
		virtual bool operator!=(const IRolePermissionType& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerNodeId m_roleId;

		RolePermissionTypeStruct* m_pContent;
	};
} // end namespace

#endif
