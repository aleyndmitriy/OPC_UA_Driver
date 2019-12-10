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

#ifndef INNERSIMPLETYPEDESCRIPTION_H
#define INNERSIMPLETYPEDESCRIPTION_H

#include "ISimpleTypeDescription.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerSimpleTypeDescription
		: public ISimpleTypeDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerSimpleTypeDescription();

		/*! Gets the BaseDataType member of the class */
		virtual const INodeId* getBaseDataType() const;
		/*! Sets the BaseDataType member in the class */
		virtual EnumStatusCode setBaseDataType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& value);

		/*! Gets the BuiltInType member of the class */
		virtual OTUInt8 getBuiltInType() const;
		/*! Sets the BuiltInType member in the class */
		virtual void setBuiltInType(const OTUInt8& value);

		/*! For internal use only */
		void initInner(SimpleTypeDescriptionStruct* pHandle);

		virtual EnumStatusCode set(const ISimpleTypeDescription* pSrc);
		virtual EnumStatusCode set(const ISimpleTypeDescription& pSrc);

		virtual int compare(const ISimpleTypeDescription* other) const;
		virtual int compare(const ISimpleTypeDescription& other) const;

		virtual bool operator==(const ISimpleTypeDescription& other) const;
		virtual bool operator!=(const ISimpleTypeDescription& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerNodeId m_baseDataType;

		SimpleTypeDescriptionStruct* m_pContent;
	};
} // end namespace

#endif
