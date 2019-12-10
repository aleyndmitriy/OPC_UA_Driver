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

#ifndef IMODELCHANGESTRUCTUREDATATYPE_H
#define IMODELCHANGESTRUCTUREDATATYPE_H
#if TB5_ALARMS

#include "ModelChangeStructureDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"


namespace SoftingOPCToolbox5
{
	/*! The ModelChangeStructureDataType contains elements that describe changes (added or removed nodes and references)
	* in a server's address space. The data type is primarily used by GeneralModelChangeEvents.
	*
	* @see Server::AddressSpaceRoot::beginModelChange() Server::AddressSpaceRoot::endModelChange() */
	class TBC_EXPORT IModelChangeStructureDataType
	{
	public:
		/*! Destructor */
		virtual ~IModelChangeStructureDataType(){};

		/*! Returns the NodeId of the node that was changed. The client should assume that the
		* affected node has been created or deleted, had a reference added or deleted, or the data type
		* has changed.
		*
		* @see getVerb() */
		virtual const INodeId* getAffected() const = 0;
		/*! Sets the NodeId of the node that was changed.
		*
		* @see setVerb() */
		virtual EnumStatusCode setAffected(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAffected(const NodeId& value) = 0;

		/*! If the affected node was an Object or Variable, this method returns the NodeId of the
		* affected node's type definition node. Otherwise, this method returns the null NodeId. */
		virtual const INodeId* getAffectedType() const = 0;
		/*! Sets the NodeId of the affected node's type, if the affected node is
		* an Object or Variable.
		*
		* @see getAffectedType() */
		virtual EnumStatusCode setAffectedType(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAffectedType(const NodeId& value) = 0;

		/*! Returns a bit-field that describes the changes to the affected node.
		*
		* @li	Bit 0: If set, indicates that the affected node has been added
		* @li	Bit 1: If set, indicates that the affected node has been deleted
		* @li	Bit 2: If set, indicates that a reference has been added. The affected node
		*		may be either the source or target of a reference. Note that an added bidirectional
		*		reference is reflected by two ModelChangeStructure entries.
		* @li	Bit 3: If set, indicates that a reference has been removed. The affected node
		*		may be either the source or target of a reference. Note that an added bidirectional
		*		reference is reflected by two ModelChangeStructure entries.
		* @li	Bit 4: If set, indicates that the DataType attribute of a Variable or VariableType
		*		has changed.
		* @li	Bit 5-7: Reserved for future use. Shall always be zero.
		*
		* A verb may identify several changes on the affected node at once. Note that all verbs
		* shall always be considered in the context where the ModelChangeStructureDataType is used.
		* A set bit 1 may indicate that a node was removed from a view but still exists in other views.
		*
		* @see EnumModelChangeStructureVerbMask */
		virtual OTUInt8 getVerb() const = 0;
		/*! Sets a bit-field that describes the changes to the affected node.
		*
		* @see getVerb() EnumModelChangeStructureVerbMask */
		virtual void setVerb(OTUInt8 value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IModelChangeStructureDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IModelChangeStructureDataType& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IModelChangeStructureDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IModelChangeStructureDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IModelChangeStructureDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IModelChangeStructureDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IModelChangeStructureDataType
} // end namespace

#endif
#endif	// IMODELCHANGESTRUCTUREDATATYPE_H
