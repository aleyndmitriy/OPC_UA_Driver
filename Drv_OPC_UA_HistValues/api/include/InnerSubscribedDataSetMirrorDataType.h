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

#ifndef INNERSUBSCRIBEDDATASETMIRRORDATATYPE_H
#define INNERSUBSCRIBEDDATASETMIRRORDATATYPE_H

#include "ISubscribedDataSetMirrorDataType.h"
#include "RolePermissionType.h"
#include "IRolePermissionType.h"
#include "InnerRolePermissionType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerSubscribedDataSetMirrorDataType
		: public ISubscribedDataSetMirrorDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerSubscribedDataSetMirrorDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the ParentNodeName member of the class */
		virtual tstring getParentNodeName() const;
		/*! Sets the ParentNodeName member in the class */
		virtual void setParentNodeName(const tstring& value);

		/*! Gets the RolePermissions member of the class */
		virtual std::vector<RolePermissionType> getRolePermissions() const;
		/*! Adds a RolePermission to the RolePermissions member of the class */
		virtual EnumStatusCode addRolePermission(const IRolePermissionType& rolePermission);

		/*! For internal use only */
		void initInner(SubscribedDataSetMirrorDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const ISubscribedDataSetDataType* pSrc);
		virtual EnumStatusCode set(const ISubscribedDataSetDataType& pSrc);

		virtual int compare(const ISubscribedDataSetDataType* other) const;
		virtual int compare(const ISubscribedDataSetDataType& other) const;

		virtual bool operator==(const ISubscribedDataSetDataType& other) const;
		virtual bool operator!=(const ISubscribedDataSetDataType& other) const;

		virtual SubscribedDataSetDataTypeStruct* getInternHandle();
		virtual const SubscribedDataSetDataTypeStruct* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerRolePermissionType> m_pRolePermissions)

		SubscribedDataSetMirrorDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
