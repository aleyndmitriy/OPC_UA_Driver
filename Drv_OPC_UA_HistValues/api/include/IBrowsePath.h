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

#ifndef IBROWSEPATH_H
#define IBROWSEPATH_H

#include "BrowsePathStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerRelativePath.h"
#include "RelativePath.h"

namespace SoftingOPCToolbox5
{
	/*! The BrowsePath data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::translateBrowsePathToNodeIds())
	* to specify a relative path (using browse names) from one node to another. */
	class TBC_EXPORT IBrowsePath
	{
	public:
		/*! Destructor */
		virtual ~IBrowsePath(){};

		/*! Returns the NodeId of the starting node for the browse path. */
		virtual const INodeId* getStartingNode() const = 0;
		/*! @overload */
		virtual INodeId* getStartingNode() = 0;
		/*! Sets the NodeId of the starting node for the browse path. */
		virtual void setStartingNode(const INodeId* value) = 0;
		/*! @overload */
		virtual void setStartingNode(const NodeId& value) = 0;

		/*! Returns the path to follow from the starting node. */
		virtual const IRelativePath* getRelativePath() const = 0;
		/*! @overload */
		virtual IRelativePath* getRelativePath() = 0;
		/*! Sets the path to follow from the starting node. */
		virtual void setRelativePath(const IRelativePath* value) = 0;
		/*! @overload */
		virtual void setRelativePath(const RelativePath& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBrowsePath* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePath& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowsePath* other) const = 0;
		/*! @overload */
		virtual int compare(const IBrowsePath& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePath& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePath& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBrowsePath
} // end namespace
#endif	// IBROWSEPATH_H
