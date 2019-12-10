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

#ifndef ISEMANTICCHANGESTRUCTUREDATATYPE_H
#define ISEMANTICCHANGESTRUCTUREDATATYPE_H

#include "SemanticChangeStructureDataTypeStruct.h"
#include "NodeId.h"
#include "INodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The SemanticChangeStructureDataType is used by the SemanticChangeEventType to
	* describe a semantic change in the server's information model. */
	class TBC_EXPORT ISemanticChangeStructureDataType
	{
	public:
		/*! Destructor */
		virtual ~ISemanticChangeStructureDataType(){};

		/*! Returns the NodeId of the node that owns the property that has changed its semantics.
		*
		* @see setAffected() */
		virtual const INodeId* getAffected() const = 0;
		/*! Sets the NodeId of the node that has changed its semantics.
		* The semantics of a node is described by properties that have the
		* SemanticsChange bit set in their AccessLevel. */
		virtual EnumStatusCode setAffected(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAffected(const NodeId& value) = 0;

		/*! Returns the NodeId of the affected node's type node, if the affected node
		* is an Object or a Variable. Otherwise, this method will return a null NodeId. */
		virtual const INodeId* getAffectedType() const = 0;
		/*! If the node that has changed its semantics is an Object or Variable,
		* a server must supply the NodeId of the node's type node. Otherwise,
		* this parameter can be omitted. */
		virtual EnumStatusCode setAffectedType(const INodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setAffectedType(const NodeId& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ISemanticChangeStructureDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISemanticChangeStructureDataType& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISemanticChangeStructureDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const ISemanticChangeStructureDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISemanticChangeStructureDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISemanticChangeStructureDataType& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISemanticChangeStructureDataType
} // end namespace

#endif	// ISEMANTICCHANGESTRUCTUREDATATYPE_H
