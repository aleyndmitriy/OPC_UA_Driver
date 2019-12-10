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

#ifndef BROWSEPATHTARGET_H
#define BROWSEPATHTARGET_H

#include "IBrowsePathTarget.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BrowsePathTarget data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::TranslateBrowsePathsToNodeIds())
	* to hold the target node that matches a given browse path. */
	class TBC_EXPORT BrowsePathTarget
		: public IBrowsePathTarget
	{
	public:
		/*! Default constructor */
		BrowsePathTarget();
		/*! Constructs a copy of the given instance */
		BrowsePathTarget(const IBrowsePathTarget*);
		/*! @overload */
		BrowsePathTarget(const IBrowsePathTarget&);
		/*! @overload */
		BrowsePathTarget(const BrowsePathTarget&);

		/*! Destructor */
		virtual ~BrowsePathTarget();

		/*! Assigns the contents of @p cp to this instance */
		BrowsePathTarget& operator=(const IBrowsePathTarget* cp);
		/*! @overload */
		BrowsePathTarget& operator=(const IBrowsePathTarget& cp);
		/*! @overload */
		BrowsePathTarget& operator=(const BrowsePathTarget& cp);

		/* see IBrowsePathTarget::set */
		virtual EnumStatusCode set(const IBrowsePathTarget* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePathTarget& pSrc);

		/* see IBrowsePathTarget::compare */
		virtual int compare(const IBrowsePathTarget*) const;
		/*! @overload */
		virtual int compare(const IBrowsePathTarget&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePathTarget& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePathTarget& other) const;

		/* see IBrowsePathTarget::getTargetId */
		virtual const IExpandedNodeId* getTargetId() const;
		/*! @overload */
		virtual IExpandedNodeId* getTargetId();
		/* see IBrowsePathTarget::setTargetId */
		virtual void setTargetId(const IExpandedNodeId* value);
		/*! @overload */
		virtual void setTargetId(const ExpandedNodeId& value);

		/* see IBrowsePathTarget::getRemainingPathIndex */
		virtual OTUInt32 getRemainingPathIndex() const;
		/* see IBrowsePathTarget::setRemainingPathIndex */
		virtual void setRemainingPathIndex(OTUInt32 remainingPathIndex);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerExpandedNodeId m_TargetId;

		BrowsePathTargetStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BROWSEPATHTARGET_H
