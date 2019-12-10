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

#ifndef READEVENTDETAILS_H
#define READEVENTDETAILS_H
#if TB5_HISTORY

#include "ReadEventDetailsStruct.h"
#include "InnerDateTime.h"
#include "InnerEventFilter.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ReadEventDetails data type is used by the HistoryRead service (see Client::Session::historyReadEvent())
	* to specify details for the service call. */
	class TBC_EXPORT ReadEventDetails
	{
	public:
		/*! Default constructor */
		ReadEventDetails();
		/*! Constructs a copy of the given instance @p cp */
		ReadEventDetails(const ReadEventDetails* cp);
		/*! @overload */
		ReadEventDetails(const ReadEventDetails& cp);

		/*! Destructor */
		virtual ~ReadEventDetails();

		/*! Assigns the contents of @p cp to this instance */
		ReadEventDetails& operator=(const ReadEventDetails& cp);

		/*! Copies the content of @p cp to this instance */
		EnumStatusCode set(const ReadEventDetails* src);
		/*! @overload */
		EnumStatusCode set(const ReadEventDetails& src);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ReadEventDetails* other) const;
		/*! @overload */
		virtual int compare(const ReadEventDetails& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ReadEventDetails& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ReadEventDetails& other) const;

		/*! Returns the beginning of the period to read.
		*
		* @see setStartTime() */
		const IDateTime* getStartTime() const;
		/*! Sets the beginning of the period to read.
		* Set the StartTime to the default value of DateTime if no specific StartTime is specified.
		*
		* @note At least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode must be specified. */
		void setStartTime(const IDateTime* startTime);

		/*! Returns the end of period to read.
		*
		* @see setStartTime() */
		const IDateTime* getEndTime() const;
		/*! Sets the end of the period to read.
		* Set the EndTime to the default value of DateTime if no specific StartTime is specified.
		*
		* @note At least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode must be specified. */
		void setEndTime(const IDateTime* startTime);

		/*! Returns the maximum number of events returned for any node over the time range.
		*
		* @see setMaxNumberOfValuesPerNode() */
		OTUInt32 getMaxNumberOfValuesPerNode() const;
		/*! Sets the maximum number of events returned for any node over the time range.
		* If only one time is specified, the time range must extend to return this number of values.
		* The default value of 0 indicates that there is no maximum.
		*
		* @note At least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode must be specified. */
		void setMaxNumberOfValuesPerNode(OTUInt32 maxNumberOfValuesPerNode);

		/*! Returns the filter used by the server to determine which historical events should be included.
		*
		* @see setFilter() */
		const IEventFilter* getFilter() const;
		/*! Sets the filter used by the server to determine which historical events should be included.
		* This parameter must be specified and at least one EventField is required */
		void setFilter(const IEventFilter* eventFilter);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerDateTime m_StartTime;
		InnerDateTime m_EndTime;
		InnerEventFilter m_Filter;

		ReadEventDetailsStruct m_content;
	}; // end ReadEventDetails
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// READEVENTDETAILS_H
