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

#ifndef INODETYPEDESCRIPTION_H
#define INODETYPEDESCRIPTION_H
#if TB5_QUERY

#include "NodeTypeDescriptionStruct.h"
#include "ExpandedNodeId.h"
#include "IExpandedNodeId.h"
#include "QueryDataDescription.h"
#include "IQueryDataDescription.h"

namespace SoftingOPCToolbox5
{
	/*! The NodeTypeDescription data type is used by the Query services (see Client::Session::queryFirst()
	* and Client::Session::queryNext()) to describe the node types that are to be queried in the
	* server's AddressSpace. */
	class TBC_EXPORT INodeTypeDescription
	{
	public:
		/*! Destructor */
		virtual ~INodeTypeDescription(){};

		/*! Returns the NodeId of the originating type definition node of the instances for
		* which data is to be returned. */
		virtual const IExpandedNodeId* getTypeDefinitionNode() const = 0;
		/*! Sets the NodeId of the originating type definition node of the instances for
		* which data is to be returned. */
		virtual EnumStatusCode setTypeDefinitionNode(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setTypeDefinitionNode(const ExpandedNodeId& value) = 0;

		/*! Returns whether the server should include instances of subtypes of the type
		* definition node in the list of instances of the node type. */
		virtual bool getIncludeSubTypes() const = 0;
		/*! Sets a flag that indicates whether the server should include instances of
		* subtypes of the type definition node in the list of instances of the node type. */
		virtual void setIncludeSubTypes(const bool& value) = 0;

		/*! Returns a list of attributes and/or node references that are to be returned
		* for a queried node. */
		virtual std::vector<QueryDataDescription> getDataToReturn() const = 0;
		/*! Adds an entry to the list of attributes and/or node references that are to be returned
		* for a queried node. */
		virtual EnumStatusCode addDataToReturn(const IQueryDataDescription* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const INodeTypeDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const INodeTypeDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INodeTypeDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const INodeTypeDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const INodeTypeDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INodeTypeDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end INodeTypeDescription
} // end namespace
#endif

#endif	// INODETYPEDESCRIPTION_H
