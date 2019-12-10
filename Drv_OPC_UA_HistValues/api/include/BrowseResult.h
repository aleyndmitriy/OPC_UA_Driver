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

#ifndef BROWSERESULT_H
#define BROWSERESULT_H

#include "IBrowseResult.h"
#include "InnerReferenceDescription.h"
#include "ReferenceDescription.h"
#include "InnerByteString.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BrowseResult data type is used by the Browse and BrowseNext services (see Client::Session::browse() and
	* Client::Session::browseNext()) and contains a list of browse results for one browsed node.
	*
	* The browse result may contain a continuation point if the number of references to return exceeds
	* the requested (or server defined) maximum. In this case, the client shall either use the continuation point
	* to proceed the browse call or the continuation point shall be released. Both possible actions can be
	* accomplished using the BrowseNext service. */
	class TBC_EXPORT BrowseResult
		: public IBrowseResult
	{
	public:
		/*! Default constructor */
		BrowseResult();
		/*! Constructs a copy of the given instance */
		BrowseResult(const IBrowseResult*);
		/*! @overload */
		BrowseResult(const IBrowseResult&);
		/*! @overload */
		BrowseResult(const BrowseResult&);

		/*! Destructor */
		virtual ~BrowseResult();

		/*! Assigns the contents of @p cp to this instance */
		BrowseResult& operator=(const IBrowseResult* cp);
		/*! @overload */
		BrowseResult& operator=(const IBrowseResult& cp);
		/*! @overload */
		BrowseResult& operator=(const BrowseResult& cp);

		/* see IBrowseResult::set */
		virtual EnumStatusCode set(const IBrowseResult* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBrowseResult& pSrc);

		/* see IBrowseResult::compare */
		virtual int compare(const IBrowseResult*) const;
		/*! @overload */
		virtual int compare(const IBrowseResult&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowseResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowseResult& other) const;

		/* see IBrowseResult::getStatusCode */
		virtual EnumStatusCode getStatusCode() const;

		/* see IBrowseResult::getContinuationPoint */
		virtual ByteString getContinuationPoint() const;

		/* see IBrowseResult::getReferenceCount */
		virtual unsigned getReferenceCount() const;
		/* see IBrowseResult::getReference */
		virtual const IReferenceDescription* getReference(unsigned index) const;
		/* see IBrowseResult::getReferences */
		virtual std::vector<ReferenceDescription> getReferences() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerReferenceDescription> m_References)
		InnerByteString m_continuationPoint;
		BrowseResultStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BROWSERESULT_H
