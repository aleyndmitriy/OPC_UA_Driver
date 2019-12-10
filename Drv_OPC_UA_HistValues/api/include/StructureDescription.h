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

#ifndef STRUCTUREDESCRIPTION_H
#define STRUCTUREDESCRIPTION_H

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

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The StructureDescription data type contains the description for a structured data type. */
	class TBC_EXPORT StructureDescription
		: public IStructureDescription
	{
	public:
		/*! Default constructor */
		StructureDescription();
		/*! Constructs a copy of the given instance @p cp */
		StructureDescription(const IStructureDescription* cp);
		/*! @overload */
		StructureDescription(const IStructureDescription& cp);
		/*! @overload */
		StructureDescription(const StructureDescription& cp);

		/*! Destructor */
		virtual ~StructureDescription();

		/*! Assigns the contents of @p cp to this instance */
		StructureDescription& operator=(const IStructureDescription* cp);
		/*! @overload */
		StructureDescription& operator=(const IStructureDescription& cp);
		/*! @overload */
		StructureDescription& operator=(const StructureDescription& cp);

		/* see IStructureDescription::compare(IStructureDescription*) */
		virtual int compare(const IStructureDescription* other) const;
		/*! @overload */
		virtual int compare(const IStructureDescription& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IStructureDescription& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IStructureDescription& other) const;

		/* see IStructureDescription::set(IStructureDescription*) */
		virtual EnumStatusCode set(const IStructureDescription* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IStructureDescription& pSrc);

		/* see IStructureDescription::getStructureDefinition() */
		virtual const IStructureDefinition* getStructureDefinition() const;
		/* see IStructureDescription::setStructureDefinition() */
		virtual EnumStatusCode setStructureDefinition(const IStructureDefinition* structureDefinition);
		/*! @overload */
		virtual EnumStatusCode setStructureDefinition(const StructureDefinition& structureDefinition);

		/* see IStructureDescription::getDataTypeId() */
		virtual const INodeId* getDataTypeId() const;
		/* see IStructureDescription::setDataTypeId() */
		virtual EnumStatusCode setDataTypeId(const INodeId* dataTypeId);
		/*! @overload */
		virtual EnumStatusCode setDataTypeId(const NodeId& dataTypeId);

		/*! Gets the Name member of the class */
		virtual const IQualifiedName* getName() const;
		/*! Sets the Name member in the class */
		virtual EnumStatusCode setName(const IQualifiedName* name);
		/*! @overload */
		virtual EnumStatusCode setName(const QualifiedName& name);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerStructureDefinition m_structureDefinition;
		InnerNodeId m_dataTypeId;
		InnerQualifiedName m_name;

		StructureDescriptionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
