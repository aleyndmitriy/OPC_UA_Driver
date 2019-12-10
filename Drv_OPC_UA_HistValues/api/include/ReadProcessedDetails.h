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

#ifndef READPROCESSEDDETAILS_H
#define READPROCESSEDDETAILS_H
#if TB5_HISTORY

#include "DateTime.h"
#include "IDateTime.h"
#include "InnerDateTime.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "AggregateConfiguration.h"
#include "IAggregateConfiguration.h"
#include "InnerAggregateConfiguration.h"
#include "ReadProcessedDetailsStruct.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ReadProcessedDetails data type is used by the HistoryRead service (see Client::Session::historyReadProcessed())
	* to specify details for the service call. */
	class TBC_EXPORT ReadProcessedDetails
	{
	public:
		/*! Default constructor */
		ReadProcessedDetails();
		/*! Constructs a copy of the given instance @p cp */
		ReadProcessedDetails(const ReadProcessedDetails* cp);
		/*! @overload */
		ReadProcessedDetails(const ReadProcessedDetails& cp);

		/*! Destructor */
		virtual ~ReadProcessedDetails();

		/*! Assigns the contents of @p cp to this instance */
		ReadProcessedDetails& operator=(const ReadProcessedDetails* cp);
		/*! @overload */
		ReadProcessedDetails& operator=(const ReadProcessedDetails& cp);

		/*! Copies the content of @p pSrc to this instance */
		EnumStatusCode set(const ReadProcessedDetails* pSrc);
		/*! @overload */
		EnumStatusCode set(const ReadProcessedDetails& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		int compare(const ReadProcessedDetails* other) const;
		/*! @overload */
		int compare(const ReadProcessedDetails& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ReadProcessedDetails& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ReadProcessedDetails& other) const;

		/*! Returns the beginning of the period for which to calculate aggregated historical values
		*
		* @see setStartTime() */
		virtual const IDateTime* getStartTime() const;
		/*! Sets the beginning of the period for which to calculate aggregated historical values.
		* If the StartTime is greater than the EndTime, aggregated values are returned in reverse order,
		* i.e. beginning from the value at EndTime. */
		virtual EnumStatusCode setStartTime(const IDateTime* value);
		/*! @overload */
		virtual EnumStatusCode setStartTime(const DateTime& value);

		/*! Returns the end of the period for which to calculate aggregated historical values
		*
		* @see setEndTime() */
		virtual const IDateTime* getEndTime() const;
		/*! Sets the end of the period for which to calculate aggregated historical values.
		* If the StartTime is greater than the EndTime, aggregated values are returned in reverse order,
		* i.e. beginning from the value at EndTime.
		*
		* @param value The end time */
		virtual EnumStatusCode setEndTime(const IDateTime* value);
		/*! @overload */
		virtual EnumStatusCode setEndTime(const DateTime& value);

		/*! Returns the processing interval (in ms) that divides the total range |StartTime - EndTime|
		* into sub-ranges of the given length.
		*
		* @see setProcessingInterval() */
		virtual OTDouble getProcessingInterval() const;
		/*! Sets the processing interval (in ms) that divides the total range |StartTime - EndTime|
		* into sub-ranges of the given length. The server shall return aggregate values for each
		* sub-range. If the processing interval is zero, only one aggregate value shall be calculated for
		* the total time range |StartTime - EndTime|.
		*
		* @see setProcessingInterval() */
		virtual void setProcessingInterval(const OTDouble& value);

		/*! Returns the NodeIds of the aggregates to calculate.
		*
		* @see addAggregateType() */
		virtual std::vector<NodeId> getAggregateType() const;
		/*! Adds the NodeId of an aggregate to calculate.
		*
		* The number of provided aggregate types must match the number of nodes
		* to read (see Client::Session::historyReadProcessed()).
		*
		* The OPC UA specification defines the following standard aggregates
		* that servers may implement:
		* @li EnumNumericNodeId_AggregateFunction_Average
		* @li EnumNumericNodeId_AggregateFunction_TimeAverage
		* @li EnumNumericNodeId_AggregateFunction_Total
		* @li EnumNumericNodeId_AggregateFunction_Minimum
		* @li EnumNumericNodeId_AggregateFunction_Maximum
		* @li EnumNumericNodeId_AggregateFunction_MinimumActualTime
		* @li EnumNumericNodeId_AggregateFunction_MaximumActualTime
		* @li EnumNumericNodeId_AggregateFunction_Range
		* @li EnumNumericNodeId_AggregateFunction_AnnotationCount
		* @li EnumNumericNodeId_AggregateFunction_Count
		* @li EnumNumericNodeId_AggregateFunction_NumberOfTransitions
		* @li EnumNumericNodeId_AggregateFunction_Start
		* @li EnumNumericNodeId_AggregateFunction_End
		* @li EnumNumericNodeId_AggregateFunction_Delta
		* @li EnumNumericNodeId_AggregateFunction_DurationGood
		* @li EnumNumericNodeId_AggregateFunction_DurationBad
		* @li EnumNumericNodeId_AggregateFunction_PercentGood
		* @li EnumNumericNodeId_AggregateFunction_PercentBad
		* @li EnumNumericNodeId_AggregateFunction_WorstQuality */
		virtual EnumStatusCode addAggregateType(const INodeId* value);

		/*! Returns the configuration that is to be used for calculating aggregate values.
		*
		* @see IAggregateConfiguration */
		virtual const IAggregateConfiguration* getAggregateConfiguration() const;
		/*! Sets the configuration that is to be used for calculating aggregate values. */
		virtual EnumStatusCode setAggregateConfiguration(const IAggregateConfiguration* value);
		/*! @overload */
		virtual EnumStatusCode setAggregateConfiguration(const AggregateConfiguration& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerDateTime m_startTime;
		InnerDateTime m_endTime;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerNodeId> m_pAggregateType)
		InnerAggregateConfiguration m_aggregateConfiguration;

		ReadProcessedDetailsStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// READPROCESSEDDETAILS_H
