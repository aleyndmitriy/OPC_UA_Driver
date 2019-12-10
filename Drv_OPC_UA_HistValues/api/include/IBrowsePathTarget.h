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

#ifndef IBROWSEPATHTARGET_H
#define IBROWSEPATHTARGET_H

#include "BrowsePathTargetStruct.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The BrowsePathTarget data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::translateBrowsePathToNodeIds())
	* to hold the target node that matches a given browse path. */
	class TBC_EXPORT IBrowsePathTarget
	{
	public:
		/*! Destructor */
		virtual ~IBrowsePathTarget(){};

		/*! Returns the identifier for a target of the relative path. */
		virtual const IExpandedNodeId* getTargetId() const = 0;
		/*! @overload */
		virtual IExpandedNodeId* getTargetId() = 0;
		/*! Sets the identifier for a target of the relative path. */
		virtual void setTargetId(const IExpandedNodeId* value) = 0;
		/*! @overload */
		virtual void setTargetId(const ExpandedNodeId& value) = 0;

		/*! Returns the index of the first unprocessed element in the RelativePath.
		* This value is equal to the maximum value of OTUInt32 if all elements were processed.
		* Any other value indicates that the remaining path has to be processed on a remote
		* server. The ServerIndex of the ExpandedNodeId identifies the server for further
		* processing.
		*
		* @see IBrowsePathResult::getTargets() */
		virtual OTUInt32 getRemainingPathIndex() const = 0;
		/*! Sets the index of the first unprocessed element in the RelativePath.
		* This value is equal to the maximum value of OTUInt32 if all elements were processed.
		* Any other value indicates that the remaining path has to be processed on a remote
		* server. The ServerIndex of the ExpandedNodeId identifies the server for further
		* processing.
		*
		* @see IBrowsePathResult::setTargets() */
		virtual void setRemainingPathIndex(OTUInt32 remainingPathIndex) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBrowsePathTarget* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePathTarget& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowsePathTarget* other) const = 0;
		/*! @overload */
		virtual int compare(const IBrowsePathTarget& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePathTarget& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePathTarget& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBrowsePathTarget
} // end namespace
#endif	// IBROWSEPATHTARGET_H
