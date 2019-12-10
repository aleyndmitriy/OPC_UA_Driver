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

#ifndef IQUERYDATASET_H
#define IQUERYDATASET_H

#include "QueryDataSetStruct.h"
#include "ExpandedNodeId.h"
#include "IExpandedNodeId.h"
#include "Value.h"
#include "IValue.h"

namespace SoftingOPCToolbox5
{
	/*! The QueryDataSet data type is used by the Query services (see Client::Session::queryFirst()
	* and Client::Session::queryNext()) to return data related to a node. The returned data matches
	* the criteria defined in the NodeTypeDescription provided with the QueryFirst service call. */
	class TBC_EXPORT IQueryDataSet
	{
	public:
		/*! Destructor */
		virtual ~IQueryDataSet(){};

		/*! Returns the NodeId of the queried node. */
		virtual const IExpandedNodeId* getNodeId() const = 0;
		/*! Sets the NodeId of the queried node. */
		virtual EnumStatusCode setNodeId(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setNodeId(const ExpandedNodeId& value) = 0;

		/*! Returns the NodeId of the queried node's type definition node. */
		virtual const IExpandedNodeId* getTypeDefinitionNode() const = 0;
		/*! Sets the NodeId of the queried node's type definition node. */
		virtual EnumStatusCode setTypeDefinitionNode(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setTypeDefinitionNode(const ExpandedNodeId& value) = 0;

		/*! Returns the values for the attributes selected by the NodeTypeDescription.
		*
		* The order of returned items matches the order of the requested items.
		* There is an entry for each requested item for the given type definition node
		* that matches the selected instance, this includes any related nodes that were
		* specified using a RelativePath from the selected instance's type definition node.
		*
		* If no values where found for a given requested item a null value is returned for
		* that item. If multiple values exist for a requested item then an array of values
		* is returned.
		*
		* If the requested item is a reference then a ReferenceDescription or array of
		* ReferenceDescriptions are returned for that item. */
		virtual std::vector<Value> getValues() const = 0;
		/*! Adds a value to the list of values for the attributes selected
		* by the NodeTypeDescription.
		*
		* @see getValues() */
		virtual EnumStatusCode addValue(const IValue* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IQueryDataSet* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IQueryDataSet& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IQueryDataSet* other) const = 0;
		/*! @overload */
		virtual int compare(const IQueryDataSet& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQueryDataSet& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQueryDataSet& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IQueryDataSet
} // end namespace

#endif	// IQUERYDATASET_H
