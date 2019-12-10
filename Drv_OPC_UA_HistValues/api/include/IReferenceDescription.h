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

#ifndef IREFERENCEDESCRIPTION_H
#define IREFERENCEDESCRIPTION_H

#include "ReferenceDescriptionStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The ReferenceDescription data type is used by the Browse service (see Client::Session::browse())
	* to return the description of a reference from a source node to a target node that was encountered during browse. */
	class TBC_EXPORT IReferenceDescription
	{
	public:
		/*! Destructor */
		virtual ~IReferenceDescription(){};

		/*! Returns the NodeId of the reference type that defines the reference. */
		virtual const INodeId* getReferenceTypeId() const = 0;
		/*! @overload */
		virtual INodeId* getReferenceTypeId() = 0;
		/*! Sets the NodeId of the reference type that defines the reference. */
		virtual void setReferenceTypeId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setReferenceTypeId(const NodeId& value) = 0;

		/*! Returns true if the server followed a forward reference. */
		virtual bool getIsForward() const = 0;
		/*! Indicates whether the server followed a forward reference. */
		virtual void setIsForward(bool value) = 0;

		/*! Returns the NodeId of the reference's target node. If IExpandedNodeId::getServerIndex()
		* returns a server index different from 0, then the target node is located at a
		* remote server. */
		virtual const IExpandedNodeId* getNodeId() const = 0;
		/*! @overload */
		virtual IExpandedNodeId* getNodeId() = 0;
		/*! Sets the NodeId of the reference's target node.
		*
		* @see getNodeId() */
		virtual void setNodeId(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual void setNodeId(const ExpandedNodeId& value) = 0;

		/*! Returns the browse name of the target node. */
		virtual const IQualifiedName* getBrowseName() const = 0;
		/*! @overload */
		virtual IQualifiedName* getBrowseName() = 0;
		/*! Sets the browse name of the target node. */
		virtual void setBrowseName(const IQualifiedName* value) = 0;
		/*! @overload */
		virtual void setBrowseName(const QualifiedName& value) = 0;

		/*! Returns the display name of the target node. */
		virtual const ILocalizedText* getDisplayName() const = 0;
		/*! @overload */
		virtual ILocalizedText* getDisplayName() = 0;
		/*! Sets the display name of the target node. */
		virtual void setDisplayName(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual void setDisplayName(const LocalizedText& value) = 0;

		/*! Returns the node class of the target node. */
		virtual EnumNodeClass getNodeClass() const = 0;
		/*! Sets the node class of the target node. */
		virtual void setNodeClass(EnumNodeClass value) = 0;

		/*! Returns the NodeId of the target node's type definition. */
		virtual const IExpandedNodeId* getTypeDefinition() const = 0;
		/*! @overload */
		virtual IExpandedNodeId* getTypeDefinition() = 0;
		/*! Sets the NodeId of the target node's type definition. */
		virtual void setTypeDefinition(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual void setTypeDefinition(const ExpandedNodeId& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IReferenceDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IReferenceDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IReferenceDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IReferenceDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReferenceDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReferenceDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IReferenceDescription
} // end namespace
#endif	// IREFERENCEDESCRIPTION_H
