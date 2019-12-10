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

#ifndef INNERDATATYPEDESCRIPTION_H
#define INNERDATATYPEDESCRIPTION_H

#include "IDataTypeDescription.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataTypeDescription
		: public IDataTypeDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerDataTypeDescription();

		/*! Gets the DataTypeId member of the class */
		virtual const INodeId* getDataTypeId() const;
		/*! Sets the DataTypeId member in the class */
		virtual EnumStatusCode setDataTypeId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setDataTypeId(const NodeId& value);

		/*! Gets the Name member of the class */
		virtual const IQualifiedName* getName() const;
		/*! Sets the Name member in the class */
		virtual EnumStatusCode setName(const IQualifiedName* value);
		/*! @overload */
		virtual EnumStatusCode setName(const QualifiedName& value);

		/*! For internal use only */
		void initInner(DataTypeDescriptionStruct* pHandle);

		virtual EnumStatusCode set(const IDataTypeDescription* pSrc);
		virtual EnumStatusCode set(const IDataTypeDescription& pSrc);

		virtual int compare(const IDataTypeDescription* other) const;
		virtual int compare(const IDataTypeDescription& other) const;

		virtual bool operator==(const IDataTypeDescription& other) const;
		virtual bool operator!=(const IDataTypeDescription& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerNodeId m_dataTypeId;
		InnerQualifiedName m_name;

		DataTypeDescriptionStruct* m_pContent;
	};
} // end namespace

#endif
