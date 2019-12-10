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

#ifndef BROWSEPATHRESULT_H
#define BROWSEPATHRESULT_H

#include "IBrowsePathResult.h"
#include "InnerBrowsePathTarget.h"
#include "BrowsePathTarget.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BrowsePathResult data type is used by the TranslateBrowsePathsToNodeIds service (see Client::Session::translateBrowsePathToNodeIds())
	* to return a list of results for the list of provided browse paths (see BrowsePath). */
	class TBC_EXPORT BrowsePathResult
		: public IBrowsePathResult
	{
	public:
		/*! Default constructor */
		BrowsePathResult();
		/*! Constructs a copy of the given instance */
		BrowsePathResult(const IBrowsePathResult*);
		/*! @overload */
		BrowsePathResult(const IBrowsePathResult&);
		/*! @overload */
		BrowsePathResult(const BrowsePathResult&);

		/*! Destructor */
		virtual ~BrowsePathResult();

		/*! Assigns the contents of @p cp to this instance */
		BrowsePathResult& operator=(const IBrowsePathResult* cp);
		/*! @overload */
		BrowsePathResult& operator=(const IBrowsePathResult& cp);
		/*! @overload */
		BrowsePathResult& operator=(const BrowsePathResult& cp);

		/* see IBrowsePathResult::set */
		virtual EnumStatusCode set(const IBrowsePathResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBrowsePathResult& pSrc);

		/* see IBrowsePathResult::compare */
		virtual int compare(const IBrowsePathResult*) const;
		/*! @overload */
		virtual int compare(const IBrowsePathResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePathResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePathResult& other) const;

		/* see IBrowsePathResult::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;
		/* see IBrowsePathResult::setStatusCode */
		virtual void setStatusCode(EnumStatusCode value);

		/* see IBrowsePathResult::getTargetCount */
		virtual OTUInt32 getTargetCount() const;
		/* see IBrowsePathResult::getTarget */
		virtual const IBrowsePathTarget* getTarget(OTUInt32 index) const;
		/* see IBrowsePathResult::getTargets */
		virtual std::vector<BrowsePathTarget> getTargets() const;
		/* see IBrowsePathResult::addTarget */
		virtual EnumStatusCode addTarget(const IBrowsePathTarget* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerBrowsePathTarget> m_Targets)
		BrowsePathResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BROWSEPATHRESULT_H
