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

#ifndef IBROWSEDESCRIPTION_H
#define IBROWSEDESCRIPTION_H

#include "BrowseDescriptionStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The BrowseDescription data type is used by the Browse service (see Client::Session::browse()) to
	* specify the node to browse and to define restrictions on browsed references. */
	class TBC_EXPORT IBrowseDescription
	{
	public:
		/*! Destructor */
		virtual ~IBrowseDescription(){};

		/*! Returns the NodeId of the node to browse. */
		virtual const INodeId* getNodeId() const = 0;
		/*! @overload */
		virtual INodeId* getNodeId() = 0;
		/*! Sets the NodeId of the node to browse. */
		virtual void setNodeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setNodeId(const NodeId& value) = 0;

		/*! Returns the direction of references to follow
		*
		* @see setBrowseDirection() */
		virtual EnumBrowseDirection getBrowseDirection() const = 0;
		/*! Sets the direction of references to follow.
		* References can be followed in forward, inverse or both directions.
		*
		* @see EnumBrowseDirection */
		virtual void setBrowseDirection(EnumBrowseDirection value) = 0;

		/*! Returns the NodeId of the reference type to follow.
		*
		* @see setReferenceTypeId() */
		virtual const INodeId* getReferenceTypeId() const = 0;
		/*! @overload */
		virtual INodeId* getReferenceTypeId() = 0;
		/*! Sets the NodeId of the reference type to follow. If the reference type is omitted,
		* all references are returned and IncludeSubtypes (see setIncludeSubtypes()) is ignored. */
		virtual void setReferenceTypeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value) = 0;

		/*! Returns whether subtypes of the specified reference type (see getReferenceTypeId()) are
		* included in the list of returned references.
		*
		* @see setIncludeSubtypes() */
		virtual bool getIncludeSubtypes() const = 0;
		/*! Indicates whether subtypes of the specified reference type (see setReferenceTypeId()) are
		* included in the list of returned references.
		*
		* If set to true, all subtypes of the given reference type are included .
		* If set to false, only the exact matching reference type is considered during the browse. */
		virtual void setIncludeSubtypes(bool value) = 0;

		/*! Returns the node classes of target nodes that are considered in the browse call.
		*
		* @see setNodeClassMask() */
		virtual EnumNodeClass getNodeClassMask() const = 0;
		/*! Sets the node classes of target nodes that are to be considered in the browse call.
		* If set to zero, then nodes of any node class are returned.
		*
		* @see EnumNodeClass */
		virtual void setNodeClassMask(EnumNodeClass value) = 0;

		/*! Returns a bit mask that indicates which kind of information about a node is returned in the browse call.
		*
		* @see setResultMask() */
		virtual EnumResultMask getResultMask() const = 0;
		/*! Sets a bit mask that indicates which kind of information about a node is returned in the browse call.
		*
		* The following bits may be set in the bit mask:
		* @li EnumResultMask_ReferenceType
		* @li EnumResultMask_IsForward
		* @li EnumResultMask_NodeClass
		* @li EnumResultMask_BrowseName
		* @li EnumResultMask_DisplayName
		* @li EnumResultMask_TypeDefinition
		* @li EnumResultMask_All */
		virtual void setResultMask(EnumResultMask value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBrowseDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBrowseDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowseDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IBrowseDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowseDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowseDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBrowseDescription
} // end namespace
#endif	// IBROWSEDESCRIPTION_H
