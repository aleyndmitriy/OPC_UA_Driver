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

#ifndef INNERSTRUCTUREDESCRIPTION_H
#define INNERSTRUCTUREDESCRIPTION_H

#include "IStructureDescription.h"
#include "StructureDefinition.h"
#include "IStructureDefinition.h"
#include "InnerStructureDefinition.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"
#include "InnerQualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerStructureDescription
		: public IStructureDescription
	{
	public:
		/*! Destructor */
		virtual ~InnerStructureDescription();

		/*! Gets the StructureDefinition member of the class */
		virtual const IStructureDefinition* getStructureDefinition() const;
		/*! Sets the StructureDefinition member in the class */
		virtual EnumStatusCode setStructureDefinition(const IStructureDefinition* value);
		/*! @overload */
		virtual EnumStatusCode setStructureDefinition(const StructureDefinition& value);

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
		void initInner(StructureDescriptionStruct* pHandle);

		virtual EnumStatusCode set(const IStructureDescription* pSrc);
		virtual EnumStatusCode set(const IStructureDescription& pSrc);

		virtual int compare(const IStructureDescription* other) const;
		virtual int compare(const IStructureDescription& other) const;

		virtual bool operator==(const IStructureDescription& other) const;
		virtual bool operator!=(const IStructureDescription& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerStructureDefinition m_structureDefinition;
		InnerNodeId m_dataTypeId;
		InnerQualifiedName m_name;

		StructureDescriptionStruct* m_pContent;
	};
} // end namespace

#endif
