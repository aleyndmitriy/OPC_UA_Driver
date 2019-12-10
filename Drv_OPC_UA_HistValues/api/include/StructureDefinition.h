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

#ifndef STRUCTUREDEFINITION_H
#define STRUCTUREDEFINITION_H

#include "IStructureDefinition.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "StructureField.h"
#include "IStructureField.h"
#include "InnerStructureField.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The StructureDefinition data type contains the meta data for a custom structured data type. */
	class TBC_EXPORT StructureDefinition
		: public IStructureDefinition
	{
	public:
		/*! Default constructor */
		StructureDefinition();
		/*! Constructs a copy of the given instance @p cp */
		StructureDefinition(const IStructureDefinition* cp);
		/*! @overload */
		StructureDefinition(const IStructureDefinition& cp);
		/*! @overload */
		StructureDefinition(const StructureDefinition& cp);

		/*! Destructor */
		virtual ~StructureDefinition();

		/*! Assigns the contents of @p cp to this instance */
		StructureDefinition& operator=(const IStructureDefinition* cp);
		/*! @overload */
		StructureDefinition& operator=(const IStructureDefinition& cp);
		/*! @overload */
		StructureDefinition& operator=(const StructureDefinition& cp);

		/* see IStructureDefinition::compare(IStructureDefinition*) */
		virtual int compare(const IStructureDefinition* other) const;
		/*! @overload */
		virtual int compare(const IStructureDefinition& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IStructureDefinition& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IStructureDefinition& other) const;

		/* see IStructureDefinition::set(IStructureDefinition*) */
		virtual EnumStatusCode set(const IStructureDefinition* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IStructureDefinition& pSrc);

		/* see IStructureDefinition::getDefaultEncodingId() */
		virtual const INodeId* getDefaultEncodingId() const;
		/* see IStructureDefinition::setDefaultEncodingId() */
		virtual EnumStatusCode setDefaultEncodingId(const INodeId* encodingId);
		/*! @overload */
		virtual EnumStatusCode setDefaultEncodingId(const NodeId& encodingId);

		/* see IStructureDefinition::getBaseDataType() */
		virtual const INodeId* getBaseDataType() const;
		/* see IStructureDefinition::setBaseDataType() */
		virtual EnumStatusCode setBaseDataType(const INodeId* baseDataType);
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& baseDataType);

		/* see IStructureDefinition::getStructureType() */
		virtual EnumStructureType getStructureType() const;
		/* see IStructureDefinition::setStructureType() */
		virtual void setStructureType(const EnumStructureType& structureType);

		/*! Gets the Fields member of the class */
		virtual std::vector<StructureField> getFields() const;
		/*! Adds a Field to the Fields member of the class */
		virtual EnumStatusCode addField(const IStructureField& field);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNodeId m_defaultEncodingId;
		InnerNodeId m_baseDataType;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerStructureField> m_pFields)

		StructureDefinitionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
