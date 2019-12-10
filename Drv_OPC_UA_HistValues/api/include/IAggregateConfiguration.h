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

#ifndef IAGGREGATECONFIGURATION_H
#define IAGGREGATECONFIGURATION_H
#if TB5_HISTORY

#include "AggregateConfigurationStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The AggregateConfiguration data type is used by clients in requests that return
	* aggregated historical data (see Client::Session::historyReadProcessed()) to tell
	* the server whether to use the default or a custom configuration for calculating aggregated values. */
	class TBC_EXPORT IAggregateConfiguration
	{
	public:
		/*! Destructor */
		virtual ~IAggregateConfiguration(){};

		/*! Returns whether the server uses default values to calculate aggregate values.
		*
		* @see setUseServerCapabilitiesDefaults() */
		virtual OTBoolean getUseServerCapabilitiesDefaults() const = 0;
		/*! Sets whether the server shall use default values to calculate aggregate values.
		* If @p value is 'false', the server uses the configuration provided by this object
		* to calculate aggregate values.
		*
		* @param value	If true, the server ignores the other values of this object. */
		virtual void setUseServerCapabilitiesDefaults(const OTBoolean& value) = 0;

		/*! Returns whether values with 'Uncertain' status code are considered equally as values
		* with 'Bad' status code when calculating an aggregate value.
		*
		* @see setTreatUncertainAsBad() */
		virtual OTBoolean getTreatUncertainAsBad() const = 0;
		/*! Sets whether values with 'Uncertain' status code are considered equally as values
		* with 'Bad' status code when calculating aggregate values.
		*
		* @param value	If true, 'Uncertain' values are considered as 'Bad' values when
		*				calculating aggregate values, i.e. 'Uncertain' values are not included
		*				in the aggregate calculation. */
		virtual void setTreatUncertainAsBad(const OTBoolean& value) = 0;

		/*! Returns the minimum percentage of 'Bad' values in a processing interval required for
		* status code of the interval to be set to 'Bad'.
		*
		* @see setPercentDataBad() */
		virtual OTUInt8 getPercentDataBad() const = 0;
		/*! Sets the minimum percentage of 'Bad' values in a processing interval required for
		* status code of the interval to be set to 'Bad'.
		*
		* Please note that the following relationship must hold true for PercentDataGood and PercentDataBad:
		* PercentDataGood >= (100 - PercentDataBad). If both sides of the inequation are equal, the result
		* of the PercentDataGood calculation is used.
		*
		* @param value	The minimum percentage of 'Bad' values required for the status code
		*				of the processing interval to become 'Bad'.
		*
		* @note If the value exceeds 100 the server shall return EnumStatusCode_BadAggregateInvalidInputs.
		* @note If the relationship of PercentDataGood >= (100 - PercentDataBad) is not fulfilled the server shall return EnumStatusCode_BadAggregateInvalidInputs. */
		virtual void setPercentDataBad(const OTUInt8& value) = 0;

		/*! Returns the minimum percentage of 'Good' values in a processing interval required for
		* status code of the interval to be set to 'Good'.
		*
		* @see setPercentDataGood() */
		virtual OTUInt8 getPercentDataGood() const = 0;
		/*! Sets the minimum percentage of 'Good' values in a processing interval required for
		* status code of the interval to be set to 'Good'.
		*
		* Please note that the following relationship must hold true for PercentDataGood and PercentDataBad:
		* PercentDataGood >= (100 - PercentDataBad). If both sides of the inequation are equal, the result
		* of the PercentDataGood calculation is used.
		*
		* @param value	The minimum percentage of 'Good' values required for the status code
		*				of the processing interval to become 'Good'.
		*
		* @note If the value exceeds 100 the server shall return EnumStatusCode_BadAggregateInvalidInputs.
		* @note If the relationship of PercentDataGood >= (100 - PercentDataBad) is not fulfilled the server shall return EnumStatusCode_BadAggregateInvalidInputs. */
		virtual void setPercentDataGood(const OTUInt8& value) = 0;

		/*! Returns whether the server uses linear extrapolation (sloped extrapolation) or
		* extrapolation based on horizontal line fit (stepped extrapolation) for projecting
		* values that are farther in the future than available in the historian.
		*
		* @see setUseSlopedExtrapolation() */
		virtual OTBoolean getUseSlopedExtrapolation() const = 0;
		/*! Defines whether the server uses linear extrapolation (sloped extrapolation) or
		* extrapolation based on horizontal line fit (stepped extrapolation) for projecting
		* values that are farther in the future than available in the historian.
		*
		* @param value	If true, the server uses linear extrapolation for projecting values.
		*				If false, the server uses horizontal line fit (i.e. the last non-bad value
		*				is assumed as constant and used as projected value). */
		virtual void setUseSlopedExtrapolation(const OTBoolean& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IAggregateConfiguration* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IAggregateConfiguration& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAggregateConfiguration* other) const = 0;
		/*! @overload */
		virtual int compare(const IAggregateConfiguration& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAggregateConfiguration& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAggregateConfiguration& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IAggregateConfiguration
} // end namespace

#endif
#endif	// IAGGREGATECONFIGURATION_H
