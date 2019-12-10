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

#ifndef SERVERHISTORYREADRAWCONTINUATIONPOINT_H
#define SERVERHISTORYREADRAWCONTINUATIONPOINT_H
#if TB5_HISTORY

#include "Base.h"
#include "ServerContinuationPoint.h"
#include "DateTime.h"
#include "InnerDateTime.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A continuation point for HistoryReadRaw requests.
		*
		* @see ContinuationPoint HistoryReadRawTransaction HistoryReadRawRequest */
		class TBC_EXPORT HistoryReadRawContinuationPoint
			: public ContinuationPoint
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoryReadRawContinuationPoint(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			HistoryReadRawContinuationPoint(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~HistoryReadRawContinuationPoint();

			/*! Returns the type of this continuation point (HistoryReadRaw).
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

			/*! Returns the beginning of the period for which to read historical values.
			*
			* If the client does not provide a start time, this method returns the NULL time (@see IDateTime::isNull) */
			const IDateTime* getStartTime() const;

			/*! Returns the end of the period for which to read historical values.
			*
			* If the client does not provide an end time, this method returns the NULL time (@see IDateTime::isNull) */
			const IDateTime* getEndTime() const;

			/*! Returns the maximum number of historical values to return for every
			* node in a request.
			*
			* If the available number of values exceeds the provided maximum, the
			* server application may create a continuation point to allow the
			* client to fetch more values. */
			OTUInt32 getMaxNumberOfValuesPerNode() const;

			/*! Returns whether bounding values (the first historical value stored before the provided
			* start time and the first historical value stored after the provided end time) are
			* to be included. */
			bool returnBoundingValues() const;

			/*! Returns the timestamps requested by the client: 'ServerTimestamp', 'SourceTimestamp' or 'Both'
			* ('Neither' is not allowed for history read raw requests). */
			EnumTimestampsToReturn getTimestampsToReturn() const;

		private:
			/*! For internal use only */
			void initMembers();

			// Continuation points are provided by the SDK core
			HistoryReadRawContinuationPoint();

			/*! Forbid use assignment operator */
			HistoryReadRawContinuationPoint& operator=(const HistoryReadRawContinuationPoint&);
			/*! Forbid use of copy constructor */
			HistoryReadRawContinuationPoint(const HistoryReadRawContinuationPoint&);

			InnerDateTime m_startTime, m_endTime;
		};
		typedef ObjectPointer<Server::HistoryReadRawContinuationPoint> HistoryReadRawContinuationPointPtr;
		typedef ObjectPointer<const Server::HistoryReadRawContinuationPoint> HistoryReadRawContinuationPointConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif

#endif	// SERVERHISTORYREADRAWCONTINUATIONPOINT_H
