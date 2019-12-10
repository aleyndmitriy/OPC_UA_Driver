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

#ifndef SERVERAGGREGATECONFIGURATION_H
#define SERVERAGGREGATECONFIGURATION_H
#if TB5_HISTORY

#include "Base.h"
#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents an AggregateConfiguration object. The AggregateConfiguration object is
		* attached to a HistoricalDataConfiguration object and defines a configuration that can be used
		* to calculate aggregate values.
		*
		* @see HistoricalDataConfiguration */
		class TBC_EXPORT AggregateConfiguration
			: public Object
		{
		public:
			/*! Constructs a new AggregateConfiguration instance */
			static ObjectPointer<AggregateConfiguration> create();

		protected:
			/*! Default constructor */
			AggregateConfiguration();

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AggregateConfiguration(TBHandle otbHandle);

			/*! Destructor */
			virtual ~AggregateConfiguration();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class AggregateConfiguration
			/////////////////////////////////////////////////////////////////////////

			/*! Returns whether values with 'Uncertain' status code are considered equally as values
			* with 'Bad' status code when calculating an aggregate value.
			*
			* @see setTreatUncertainAsBad() */
			bool getTreatUncertainAsBad() const;
			/*! Sets whether values with 'Uncertain' status code are considered equally as values
			* with 'Bad' status code when calculating aggregate values.
			*
			* @param treatUncertainAsBad	If true, 'Uncertain' values are considered as 'Bad' values when
			*								calculating aggregate values, i.e. 'Uncertain' values are not included
			*								in the aggregate calculation.
			*
			* @note Default value is true. */
			EnumStatusCode setTreatUncertainAsBad(bool treatUncertainAsBad);

			/*! Returns the minimum percentage of 'Bad' values in a processing interval required for
			* status code of the interval to be set to 'Bad'.
			*
			* @see setPercentDataBad() */
			OTUInt8 getPercentDataBad() const;
			/*! Sets the minimum percentage of 'Bad' values in a processing interval required for
			* status code of the interval to be set to 'Bad'.
			*
			* Please note that the following relationship must hold true for PercentDataGood and PercentDataBad:
			* PercentDataGood >= (100 - PercentDataBad). If both sides of the inequation are equal, the result
			* of the PercentDataGood calculation is used.
			*
			* @param percentDataBad	The minimum percentage of 'Bad' values required for the status code
			*						of the processing interval to become 'Bad'.
			*
			* @note Default value is 100. */
			EnumStatusCode setPercentDataBad(OTUInt8 percentDataBad);

			/*! Returns the minimum percentage of 'Good' values in a processing interval required for
			* status code of the interval to be set to 'Good'.
			*
			* @see setPercentDataGood() */
			OTUInt8 getPercentDataGood() const;
			/*! Sets the minimum percentage of 'Good' values in a processing interval required for
			* status code of the interval to be set to 'Good'.
			*
			* Please note that the following relationship must hold true for PercentDataGood and PercentDataBad:
			* PercentDataGood >= (100 - PercentDataBad). If both sides of the inequation are equal, the result
			* of the PercentDataGood calculation is used.
			*
			* @param percentDataGood	The minimum percentage of 'Good' values required for the status code
			*							of the processing interval to become 'Good'.
			*
			* @note Default value is 100. */
			EnumStatusCode setPercentDataGood(OTUInt8 percentDataGood);

			/*! Returns whether the server uses linear extrapolation (sloped extrapolation) or
			* extrapolation based on horizontal line fit (stepped extrapolation) for projecting
			* values that are farther in the future than available in the historian.
			*
			* @see setUseSlopedExtrapolation() */
			bool getUseSlopedExtrapolation() const;
			/*! Defines whether the server uses linear extrapolation (sloped extrapolation) or
			* extrapolation based on horizontal line fit (stepped extrapolation) for projecting
			* values that are farther in the future than available in the historian.
			*
			* @param useSlopedExtrapolation	If true, the server uses linear extrapolation for projecting values.
			*								If false, the server uses horizontal line fit (i.e. the last non-bad value
			*								is assumed as constant and used as projected value).
			*
			* @note Default value is false. */
			EnumStatusCode setUseSlopedExtrapolation(bool useSlopedExtrapolation);

		private:
			/*! Forbid use assignment operator */
			AggregateConfiguration& operator=(const AggregateConfiguration&);
			/*! Forbid use of copy constructor */
			AggregateConfiguration(const AggregateConfiguration&);
		};

		typedef ObjectPointer<AggregateConfiguration> AggregateConfigurationPtr;
		typedef ObjectPointer<const AggregateConfiguration> AggregateConfigurationConstPtr;
	} // end Server namespace
} // toolbox namespace end

#endif
#endif // SERVERAGGREGATECONFIGURATION_H
