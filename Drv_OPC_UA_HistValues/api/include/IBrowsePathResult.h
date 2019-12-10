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

#ifndef IBROWSEPATHRESULT_H
#define IBROWSEPATHRESULT_H

#include "BrowsePathResultStruct.h"
#include "InnerBrowsePathTarget.h"
#include "BrowsePathTarget.h"

namespace SoftingOPCToolbox5
{
	/*! The BrowsePathResult data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::translateBrowsePathToNodeIds())
	* to return a list of results for the list of provided browse paths (see BrowsePath). */
	class TBC_EXPORT IBrowsePathResult
	{
	public:
		/*! Destructor */
		virtual ~IBrowsePathResult(){};

		/*! Returns the status code for the provided browse path. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Sets the status code for the provided browse path. */
		virtual void setStatusCode(EnumStatusCode value) = 0;

		/*! The methods getTargetCount() and getTarget() are provided for efficient access to data.
		* The semantics of these methods are documented in getTargets(). */
		virtual OTUInt32 getTargetCount() const = 0;
		/*! The methods getTargetCount() and getTarget() are provided for efficient access to data.
		* The semantics of these methods are documented in getTargets(). */
		virtual const IBrowsePathTarget* getTarget(OTUInt32 index) const = 0;
		/*! Returns the list of target nodes for the relative path from the starting node.
		*
		* A server may encounter a reference to a node in another server which it cannot follow
		* while it is processing the relative path. If this happens the server returns the NodeId
		* of the external node and sets the RemainingPathIndex (see IBrowsePathTarget::getRemainingPathIndex())
		* parameter to indicate which relative path elements still need to be processed. To complete the operation
		* the client shall connect to the other server and call this service again using the target as the
		* starting node and the unprocessed elements as the relative path. */
		virtual std::vector<BrowsePathTarget> getTargets() const = 0;
		/*! Adds a target node to the list of target nodes.
		*
		* @see getTargets() */
		virtual EnumStatusCode addTarget(const IBrowsePathTarget* value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBrowsePathResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePathResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowsePathResult* other) const = 0;
		/*! @overload */
		virtual int compare(const IBrowsePathResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePathResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePathResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBrowsePathResult
} // end namespace
#endif	// IBROWSEPATHRESULT_H
