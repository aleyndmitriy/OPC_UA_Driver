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

#ifndef HISTORYREADDATARESULT_H
#define HISTORYREADDATARESULT_H
#if TB5_HISTORY

#include "HistoryReadResultStruct.h"
#include "ByteString.h"
#include "InnerDataValue.h"
#include "InnerByteString.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The HistoryReadDataResult data type is used by the HistoryRead service (see Client::Session::historyReadRaw() and
	* Client::Session::historyReadProcessed()) to return historical data for one node to the client.
	*
	* This data type may contain a continuation point if the historical values to return exceeds
	* the requested (or server defined) maximum. In this case, the client shall either use the continuation point
	* to proceed the HistoryRead call or the continuation point shall be released. Both possible actions can be
	* accomplished using the Client::Session::historyReadRaw() resp. Client::Session::historyReadProcessed() service.
	*
	* @note Please note that this data type is not defined by the OPC UA specifications. */
	class TBC_EXPORT HistoryReadDataResult
	{
	public:
		/*! Default constructor */
		HistoryReadDataResult();
		/*! Constructs a copy of the given instance */
		HistoryReadDataResult(const HistoryReadDataResult*);
		/*! @overload */
		HistoryReadDataResult(const HistoryReadDataResult&);

		/*! Destructor */
		virtual ~HistoryReadDataResult();

		/*! Assigns the contents of @p cp to this instance */
		HistoryReadDataResult& operator=(const HistoryReadDataResult& cp);

		/*! Copies the content of @p source to this instance */
		EnumStatusCode set(const HistoryReadDataResult* src);
		/*! @overload */
		EnumStatusCode set(const HistoryReadDataResult& src);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const HistoryReadDataResult* other) const;
		/*! @overload */
		virtual int compare(const HistoryReadDataResult& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const HistoryReadDataResult& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const HistoryReadDataResult& other) const;

		/*! This parameter is used only if the number of values was too large to be returned in a single response.
		* If this parameter is not used, ByteString::getSize() returns 0.
		*
		* The continuation point has to be passed to the next HistoryRead call for that node.
		* If the continuation point is no longer needed, it has to be released by a separate HistoryRead call. */
		ByteString getContinuationPoint() const;

		/*! Returns the status code for the read node. */
		EnumStatusCode getStatusCode() const;

		/*! Returns the number of values that the server returned for the read node.
		*
		* @see getValue() */
		OTUInt32 getNumberOfValues() const;
		/*! Provides access to a specific historical value in the returned list of values.
		*
		* @see getNumberOfValues() */
		const IDataValue* getValue(OTUInt32 index) const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerDataValue> m_Values)
		InnerByteString m_continuationPoint;

		HistoryReadResultStruct m_content;
	}; // end HistoryReadDataResult
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif

#endif	// HISTORYREADDATARESULT_H
