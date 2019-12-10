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

#ifndef SERVERHISTORYREADEVENTCONTINUATIONPOINT_H
#define SERVERHISTORYREADEVENTCONTINUATIONPOINT_H
#if TB5_HISTORY

#include "Base.h"
#include "ServerContinuationPoint.h"
#include "DateTime.h"
#include "InnerDateTime.h"
#include "EventFilter.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A continuation point for HistoryReadEvent requests.
		*
		* @see ContinuationPoint HistoryReadEventTransaction HistoryReadEventRequest */
		class TBC_EXPORT HistoryReadEventContinuationPoint
			: public ContinuationPoint
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadEventContinuationPoint(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			HistoryReadEventContinuationPoint(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~HistoryReadEventContinuationPoint();

			/*! Returns the type of this continuation point (HistoryReadEvent).
			*
			* @return The continuation point type */
			virtual EnumContinuationPointType getType() const;

			/*! Interprets and returns the context information as timestamp (DateTime).
			*
			* @return The context information interpreted as DateTime */
			DateTime getContextAsTimestamp() const;
			/*! Stores the provided @p timestamp as context information for this
			* continuation point.
			*
			* Any previously stored context information is deleted. */
			EnumStatusCode setContextFromTimestamp(const IDateTime* timestamp);
			/*! @overload */
			EnumStatusCode setContextFromTimestamp(const DateTime& timestamp);

			/*! Interprets and returns the context information as ByteString.
			*
			* @return The context information interpreted as ByteString */
			ByteString getContextAsByteString() const;
			/*! Stores the provided @p byteString as context information for this
			* continuation point.
			*
			* Any previously stored context information is deleted. */
			EnumStatusCode setContextFromByteString(const ByteString& byteString);

			/*! Returns the beginning of the period to read. If the start time equals the minimum value of DateTime,
			* no specific start time is specified.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			const IDateTime* getStartTime() const;

			/*! Returns the end of the period to read. If the start time equals the minimum value of DateTime,
			* no specific end time is specified.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			const IDateTime* getEndTime() const;

			/*! Returns the maximum number of historical values to return for every
			* node in a request.
			*
			* If the available number of values exceeds the provided maximum, the
			* server application may create a continuation point to allow the
			* client to fetch more values.
			*
			* @note	The client must have specified at least two of the three parameters StartTime, EndTime and MaxNumberOfValuesPerNode.
			*		This precondition is already verified by the SDK. */
			OTUInt32 getMaxNumberOfValuesPerNode() const;

			/*! Returns the filter that shall be used by the server application to determine which historical events to include in
			* the response and which event fields to return. This parameter must be specified and at least one EventField must be selected.
			*
			* @see EventFilterEvaluator */
			EnumStatusCode getFilter(EventFilter& filter) const;

			/*! Returns which timestamps to return for DataValues in event fields.
			* This parameter can be ignored for event fields that are not of type DataValue.
			*
			* @note This parameter applies only to event fields that are of type DataValue. */
			EnumTimestampsToReturn getTimestampsToReturn() const;

		private:
			/*! For internal use only */
			void initMembers();

			// Continuation points are provided by the SDK core
			HistoryReadEventContinuationPoint();

			InnerDateTime m_startTime, m_endTime;

			/*! Forbid use assignment operator */
			HistoryReadEventContinuationPoint& operator=(const HistoryReadEventContinuationPoint&);
			/*! Forbid use of copy constructor */
			HistoryReadEventContinuationPoint(const HistoryReadEventContinuationPoint&);
		};
		typedef ObjectPointer<Server::HistoryReadEventContinuationPoint> HistoryReadEventContinuationPointPtr;
		typedef ObjectPointer<const Server::HistoryReadEventContinuationPoint> HistoryReadEventContinuationPointConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERHISTORYREADEVENTCONTINUATIONPOINT_H
