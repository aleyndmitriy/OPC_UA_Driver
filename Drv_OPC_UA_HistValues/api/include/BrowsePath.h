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

#ifndef BROWSEPATH_H
#define BROWSEPATH_H

#include "IBrowsePath.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerRelativePath.h"
#include "RelativePath.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BrowsePath data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::translateBrowsePathToNodeIds())
	* to specify a relative path (using browse names) from one node to another. */
	class TBC_EXPORT BrowsePath
		: public IBrowsePath
	{
	public:
		/*! Default constructor */
		BrowsePath();
		/*! Constructs a copy of the given instance */
		BrowsePath(const IBrowsePath*);
		/*! @overload */
		BrowsePath(const IBrowsePath&);
		/*! @overload */
		BrowsePath(const BrowsePath&);

		/*! Destructor */
		virtual ~BrowsePath();

		/*! Assigns the contents of @p cp to this instance */
		BrowsePath& operator=(const IBrowsePath* cp);
		/*! @overload */
		BrowsePath& operator=(const IBrowsePath& cp);
		/*! @overload */
		BrowsePath& operator=(const BrowsePath& cp);

		/* see IBrowsePath::set */
		virtual EnumStatusCode set(const IBrowsePath* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePath& pSrc);

		/* see IBrowsePath::compare */
		virtual int compare(const IBrowsePath*) const;
		/*! @overload */
		virtual int compare(const IBrowsePath&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePath& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePath& other) const;

		/* see IBrowsePath::getStartingNode */
		virtual const INodeId* getStartingNode() const;
		/*! @overload */
		virtual INodeId* getStartingNode();
		/* see IBrowsePath::setStartingNode */
		virtual void setStartingNode(const INodeId* value);
		/*! @overload */
		virtual void setStartingNode(const NodeId& value);

		/* see IBrowsePath::getRelativePath */
		virtual const IRelativePath* getRelativePath() const;
		/*! @overload */
		virtual IRelativePath* getRelativePath();
		/* see IBrowsePath::setRelativePath */
		virtual void setRelativePath(const IRelativePath* value);
		/*! @overload */
		virtual void setRelativePath(const RelativePath& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_StartingNode;
		InnerRelativePath m_RelativePath;

		BrowsePathStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BROWSEPATH_H
