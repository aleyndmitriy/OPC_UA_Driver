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

#ifndef ISUBSCRIBEDDATASETMIRRORDATATYPE_H
#define ISUBSCRIBEDDATASETMIRRORDATATYPE_H

#include "RolePermissionType.h"
#include "IRolePermissionType.h"
#include "ISubscribedDataSetDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The SubscribedDataSetDataType is used to store SubscribedDataSetMirror specific parameters. */
	class TBC_EXPORT ISubscribedDataSetMirrorDataType : public ISubscribedDataSetDataType
	{
	public:
		/*! Destructor */
		virtual ~ISubscribedDataSetMirrorDataType(){};

		/*! Sets the ParentNodeName member in the class
		*
		* @param parentNodeName		This member defines the BrowseName and DisplayName of the parent
		*							Node for the variables representing the fields of the subscribed DataSet. */
		virtual void setParentNodeName(const tstring& parentNodeName) = 0;
		/*! Gets the ParentNodeName member of the class */
		virtual tstring getParentNodeName() const = 0;

		/*! Adds a RolePermission to the RolePermissions member of the class
		*
		* @param rolePermissions	This member defines the value of the RolePermissions attribute to be set on the parent Node.
		*							This value is also used as RolePermissions for all Variables of the DataSet mirror. */
		virtual EnumStatusCode addRolePermission(const IRolePermissionType& rolePermissions) = 0;
		/*! Gets the RolePermissions member of the class */
		virtual std::vector<RolePermissionType> getRolePermissions() const = 0;

		/*! Conversion from ISubscribedDataSetDataType */
		static const ISubscribedDataSetMirrorDataType* castFrom(const ISubscribedDataSetDataType* pSrc);
		/*! Conversion from ISubscribedDataSetDataType */
		static ISubscribedDataSetMirrorDataType* castFrom(ISubscribedDataSetDataType* pSrc);

	}; // end ISubscribedDataSetMirrorDataType
} // end namespace

#endif
