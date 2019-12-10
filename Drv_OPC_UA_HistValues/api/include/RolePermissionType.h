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

#ifndef ROLEPERMISSIONTYPE_H
#define ROLEPERMISSIONTYPE_H

#include "IRolePermissionType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! Specifies the Permissions that apply to a Node for all Roles which have access to the Node. */
	class TBC_EXPORT RolePermissionType
		: public IRolePermissionType
	{
	public:
		/*! Default constructor */
		RolePermissionType();
		/*! Constructs a copy of the given instance @p cp */
		RolePermissionType(const IRolePermissionType* cp);
		/*! @overload */
		RolePermissionType(const IRolePermissionType& cp);
		/*! @overload */
		RolePermissionType(const RolePermissionType& cp);

		/*! Destructor */
		virtual ~RolePermissionType();

		/*! Assigns the contents of @p cp to this instance */
		RolePermissionType& operator=(const IRolePermissionType* cp);
		/*! @overload */
		RolePermissionType& operator=(const IRolePermissionType& cp);
		/*! @overload */
		RolePermissionType& operator=(const RolePermissionType& cp);

		/*! @see IRolePermissionType::compare(IRolePermissionType*) */
		virtual int compare(const IRolePermissionType* other) const;
		/*! @overload */
		virtual int compare(const IRolePermissionType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRolePermissionType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRolePermissionType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IRolePermissionType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IRolePermissionType& pSrc);

		/* see IRolePermissionType::setRoleId */
		virtual EnumStatusCode setRoleId(const INodeId* roleId);
		/*! @overload */
		virtual EnumStatusCode setRoleId(const NodeId& roleId);
		/* see IRolePermissionType::getRoleId */
		virtual const INodeId* getRoleId() const;

		/* see IRolePermissionType::setPermissions */
		virtual void setPermissions(const OTUInt32& permissions);
		/* see IRolePermissionType::getPermissions */
		virtual OTUInt32 getPermissions() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNodeId m_roleId;

		RolePermissionTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
