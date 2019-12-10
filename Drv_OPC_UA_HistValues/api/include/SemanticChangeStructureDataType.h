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

#ifndef SEMANTICCHANGESTRUCTUREDATATYPE_H
#define SEMANTICCHANGESTRUCTUREDATATYPE_H
#if TB5_ALARMS

#include "ISemanticChangeStructureDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SemanticChangeStructureDataType is used by the SemanticChangeEventType to
	* describe a semantic change in the server's information model. */
	class TBC_EXPORT SemanticChangeStructureDataType
		: public ISemanticChangeStructureDataType
	{
	public:
		/*! Default constructor */
		SemanticChangeStructureDataType();
		/*! Constructs a copy of the given instance */
		SemanticChangeStructureDataType(const ISemanticChangeStructureDataType*);
		/*! @overload */
		SemanticChangeStructureDataType(const ISemanticChangeStructureDataType&);
		/*! @overload */
		SemanticChangeStructureDataType(const SemanticChangeStructureDataType&);

		/*! Destructor */
		virtual ~SemanticChangeStructureDataType();

		/*! Assigns the contents of @p cp to this instance */
		SemanticChangeStructureDataType& operator=(const ISemanticChangeStructureDataType* cp);
		/*! @overload */
		SemanticChangeStructureDataType& operator=(const ISemanticChangeStructureDataType& cp);
		/*! @overload */
		SemanticChangeStructureDataType& operator=(const SemanticChangeStructureDataType& cp);

		/* see ISemanticChangeStructureDataType::set */
		virtual EnumStatusCode set(const ISemanticChangeStructureDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISemanticChangeStructureDataType& pSrc);

		/* see ISemanticChangeStructureDataType::compare */
		virtual int compare(const ISemanticChangeStructureDataType*) const;
		/*! @overload */
		virtual int compare(const ISemanticChangeStructureDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISemanticChangeStructureDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISemanticChangeStructureDataType& other) const;

		/* see ISemanticChangeStructureDataType::getAffected */
		virtual const INodeId* getAffected() const;
		/* see ISemanticChangeStructureDataType::setAffected */
		virtual EnumStatusCode setAffected(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setAffected(const NodeId& value);

		/* see ISemanticChangeStructureDataType::getAffectedType */
		virtual const INodeId* getAffectedType() const;
		/* see ISemanticChangeStructureDataType::setAffectedType */
		virtual EnumStatusCode setAffectedType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setAffectedType(const NodeId& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_affected;
		InnerNodeId m_affectedType;

		SemanticChangeStructureDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// SEMANTICCHANGESTRUCTUREDATATYPE_H
