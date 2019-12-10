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

#ifndef HISTORYREADVALUEID_H
#define HISTORYREADVALUEID_H
#if TB5_HISTORY

#include "HistoryReadValueIdStruct.h"
#include "InnerNodeId.h"
#include "InnerDateTime.h"
#include "InnerNumericRange.h"
#include "InnerQualifiedName.h"
#include "InnerByteString.h"
#include "ByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The HistoryReadValueId data type is used by the HistoryRead services (see Client::Session::historyReadRaw(),
	* Client::Session::historyReadProcessed(), and Client::Session::historyReadEvent()) to specify the node
	* on which the historical retrieval is to be performed. */
	class TBC_EXPORT HistoryReadValueId
	{
	public:
		/*! Default constructor */
		HistoryReadValueId();
		/*! Constructs a copy of the given instance */
		HistoryReadValueId(const HistoryReadValueId*);
		/*! @overload */
		HistoryReadValueId(const HistoryReadValueId&);

		/*! Destructor */
		virtual ~HistoryReadValueId();

		/*! Assigns the contents of @p cp to this instance */
		HistoryReadValueId& operator=(const HistoryReadValueId& cp);

		/*! Copies the content of @p source to this instance */
		EnumStatusCode set(const HistoryReadValueId* cp);
		/*! @overload */
		EnumStatusCode set(const HistoryReadValueId& cp);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		int compare(const HistoryReadValueId* other) const;
		/*! @overload */
		int compare(const HistoryReadValueId& other) const;

		/*! Compares two instances for equality */
		bool operator==(const HistoryReadValueId& other) const;
		/*! Compares two instances for inequality */
		bool operator!=(const HistoryReadValueId& other) const;

		/*! Returns the NodeId of the node whose historical values are to be read. */
		const INodeId* getNodeId() const;
		/*! Sets the NodeId of the node whose historical values are to be read. */
		void setNodeId(const INodeId* pNodeId);

		/*! Returns the IndexRange that the server applies to historical values of type "array". */
		const INumericRange* getIndexRange() const;
		/*! Sets the IndexRange that the server applies to historical values of type "array".
		*
		* This parameter must not be specified if the value is not an array. However, if the value
		* is an array, and this parameter is not specified, then all elements are to be included in the range. */
		void setIndexRange(const INumericRange* pIndexRange);

		/*! Returns the continuation point that the server shall use to continue a HistoryRead service call. */
		ByteString getContinuationPoint() const;
		/*! Sets the continuation point that the server shall use to continue a HistoryRead service call.
		* An empty ByteString (i.e. ByteString::getSize() returns 0) indicates that the continuation point is not used. */
		void setContinuationPoint(const ByteString& continuationPoint);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only. */
		void* getInternHandle() const;

	private:
		/*! For internal use only. */
		void initMembers();

		InnerNumericRange m_IndexRange;
		InnerNodeId m_NodeId;
		InnerByteString m_continuationPoint;

		HistoryReadValueIdStruct m_content;
	}; // end HistoryReadValueId
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif	// HISTORYREADVALUEID_H
