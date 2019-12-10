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

#ifndef IBROWSERESULT_H
#define IBROWSERESULT_H

#include "BrowseResultStruct.h"
#include "InnerReferenceDescription.h"
#include "ReferenceDescription.h"

namespace SoftingOPCToolbox5
{
	/*! The BrowseResult data type is used by the Browse and BrowseNext services (see Client::Session::browse() and
	* Client::Session::browseNext()) and contains a list of browse results for one browsed node.
	*
	* The browse result may contain a continuation point, if the number of references to return exceeds
	* the requested (or server-defined) maximum. In this case, the client shall either use the continuation point
	* to proceed the browse call or the continuation point shall be released. Both possible actions can be
	* accomplished using the BrowseNext service. */
	class TBC_EXPORT IBrowseResult
	{
	public:
		/*! Destructor */
		virtual ~IBrowseResult(){};

		/*! Returns the status code for the browse result of a single node. */
		virtual EnumStatusCode getStatusCode() const = 0;

		/*! Returns the continuation point provided by the server. If the continuation point is
		* empty (i.e. ByteString::getSize() returns 0), the server did not provide a continuation point.
		*
		* The browse result may contain a continuation point, if the number of references to return exceeds
		* the requested (or server-defined) maximum. In this case, the client shall either use the continuation point
		* to proceed the browse call or the continuation point shall be released. Both possible actions can be
		* accomplished using the BrowseNext service.
		*
		* @see Client::Session::browseNext() */
		virtual ByteString getContinuationPoint() const = 0;

		/*! The methods getReferenceCount() and getReference() are provided for efficient access to data.
		* The semantics of these methods are documented in getReferences(). */
		virtual unsigned getReferenceCount() const = 0;
		/*! The methods getReferenceCount() and getReference() are provided for efficient access to data.
		* The semantics of these methods are documented in getReferences(). */
		virtual const IReferenceDescription* getReference(unsigned index) const = 0;
		/*! Returns the set of references that meet the criteria specified in the BrowseDescription.
		* Since each node can have more than one reference, an array of references is returned for each node. */
		virtual std::vector<ReferenceDescription> getReferences() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBrowseResult* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBrowseResult& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowseResult* other) const = 0;
		/*! @overload */
		virtual int compare(const IBrowseResult& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowseResult& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowseResult& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBrowseResult
} // end namespace
#endif	// IBROWSERESULT_H
