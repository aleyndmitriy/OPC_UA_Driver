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

#ifndef SUBSCRIBEDDATASETMIRRORDATATYPE_H
#define SUBSCRIBEDDATASETMIRRORDATATYPE_H

#include "ISubscribedDataSetMirrorDataType.h"
#include "RolePermissionType.h"
#include "IRolePermissionType.h"
#include "InnerRolePermissionType.h"
#include "SubscribedDataSetMirrorDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of SubscribedDataSetDataType.
	*
	* It is used to store SubscribedDataSetMirror specific parameters. */
	class TBC_EXPORT SubscribedDataSetMirrorDataType
		: public ISubscribedDataSetMirrorDataType
	{
	public:
		/*! Default constructor */
		SubscribedDataSetMirrorDataType();
		/*! Constructs a copy of the given instance @p cp */
		SubscribedDataSetMirrorDataType(const ISubscribedDataSetMirrorDataType* cp);
		/*! @overload */
		SubscribedDataSetMirrorDataType(const ISubscribedDataSetMirrorDataType& cp);
		/*! @overload */
		SubscribedDataSetMirrorDataType(const SubscribedDataSetMirrorDataType& cp);

		/*! Destructor */
		virtual ~SubscribedDataSetMirrorDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		SubscribedDataSetMirrorDataType& operator=(const ISubscribedDataSetMirrorDataType* cp);
		/*! @overload */
		SubscribedDataSetMirrorDataType& operator=(const ISubscribedDataSetMirrorDataType& cp);
		/*! @overload */
		SubscribedDataSetMirrorDataType& operator=(const SubscribedDataSetMirrorDataType& cp);

		/*! @see ISubscribedDataSetMirrorDataType::compare(ISubscribedDataSetDataType*) */
		virtual int compare(const ISubscribedDataSetDataType* other) const;
		/*! @overload */
		virtual int compare(const ISubscribedDataSetDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISubscribedDataSetDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISubscribedDataSetDataType& other) const;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISubscribedDataSetDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISubscribedDataSetDataType& pSrc);

		/* see ISubscribedDataSetMirrorDataType::setParentNodeName */
		virtual void setParentNodeName(const tstring& parentNodeName);
		/* see ISubscribedDataSetMirrorDataType::getParentNodeName */
		virtual tstring getParentNodeName() const;

		/* see ISubscribedDataSetMirrorDataType::addRolePermission */
		virtual EnumStatusCode addRolePermission(const IRolePermissionType& rolePermissions);
		/* see ISubscribedDataSetMirrorDataType::getRolePermissions */
		virtual std::vector<RolePermissionType> getRolePermissions() const;

		/*! For internal use only */
		virtual SubscribedDataSetDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const SubscribedDataSetDataTypeStruct* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerRolePermissionType> m_pRolePermissions)

		SubscribedDataSetMirrorDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
