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

#ifndef MODELCHANGESTRUCTUREDATATYPE_H
#define MODELCHANGESTRUCTUREDATATYPE_H
#if TB5_ALARMS

#include "IModelChangeStructureDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ModelChangeStructureDataType contains elements that describe changes (added or removed nodes and references)
	* in a server's address space. The data type is primarily used by GeneralModelChangeEvents.
	*
	* @see Server::AddressSpaceRoot::beginModelChange() Server::AddressSpaceRoot::endModelChange() */
	class TBC_EXPORT ModelChangeStructureDataType
		: public IModelChangeStructureDataType
	{
	public:
		/*! Default constructor */
		ModelChangeStructureDataType();
		/*! Constructs a copy of the given instance */
		ModelChangeStructureDataType(const IModelChangeStructureDataType*);
		/*! @overload */
		ModelChangeStructureDataType(const IModelChangeStructureDataType&);
		/*! @overload */
		ModelChangeStructureDataType(const ModelChangeStructureDataType&);

		/*! Destructor */
		virtual ~ModelChangeStructureDataType();

		/*! Assigns the contents of @p cp to this instance */
		ModelChangeStructureDataType& operator=(const IModelChangeStructureDataType*);
		/*! @overload */
		ModelChangeStructureDataType& operator=(const IModelChangeStructureDataType&);
		/*! @overload */
		ModelChangeStructureDataType& operator=(const ModelChangeStructureDataType&);

		/* see IModelChangeStructureDataType::set */
		virtual EnumStatusCode set(const IModelChangeStructureDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IModelChangeStructureDataType& pSrc);

		/* see IModelChangeStructureDataType::compare */
		virtual int compare(const IModelChangeStructureDataType*) const;
		/*! @overload */
		virtual int compare(const IModelChangeStructureDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IModelChangeStructureDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IModelChangeStructureDataType& other) const;

		/* see IModelChangeStructureDataType::getAffected */
		virtual const INodeId* getAffected() const;
		/* see IModelChangeStructureDataType::setAffected */
		virtual EnumStatusCode setAffected(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setAffected(const NodeId& value);

		/* see IModelChangeStructureDataType::getAffectedType */
		virtual const INodeId* getAffectedType() const;
		/* see IModelChangeStructureDataType::setAffectedType */
		virtual EnumStatusCode setAffectedType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setAffectedType(const NodeId& value);

		/* see IModelChangeStructureDataType::getVerb */
		virtual OTUInt8 getVerb() const;
		/* see IModelChangeStructureDataType::setVerb */
		virtual void setVerb(OTUInt8 value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_affected;
		InnerNodeId m_affectedType;

		ModelChangeStructureDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// MODELCHANGESTRUCTUREDATATYPE_H
