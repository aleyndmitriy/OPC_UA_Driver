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

#ifndef SERVERHISTORICALDATACONFIGURATION_H
#define SERVERHISTORICALDATACONFIGURATION_H
#if TB5_HISTORY

#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class AggregateConfiguration;
	}

	namespace Server
	{
		/*! The HistoricalDataConfiguration object defines the configuration of a HistoricalDataNode. */
		class TBC_EXPORT HistoricalDataConfiguration
			: public Object
		{
		public:
			/*! Constructs a new HistoricalDataConfiguration instance */
			static ObjectPointer<HistoricalDataConfiguration> create();

			/*! Constructs a HistoricalDataConfiguration using an existing AggregateConfiguration object.
			*
			* @param nodeId					The NodeId that is assigned to the HistoricalDataConfiguration object
			* @param displayName			The DisplayName that is assigned to the HistoricalDataConfiguration object
			* @param browseName				The BrowseName that is assigned to the HistoricalDataConfiguration object
			* @param aggregateConfiguration	The AggregateConfiguration object to use for the HistoricalDataConfiguration.
			*								This object must already be initialized (see AggregateConfiguration::init()). */
			static ObjectPointer<HistoricalDataConfiguration> create(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				ObjectPointer<AggregateConfiguration> aggregateConfiguration);

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			HistoricalDataConfiguration(TBHandle otbHandle);

			/*! Destructor */
			virtual ~HistoricalDataConfiguration();

		protected:
			/*! Default constructor */
			HistoricalDataConfiguration();

			/*! Constructs a HistoricalDataConfiguration using an existing AggregateConfiguration object.
			*
			* @param nodeId					The NodeId that is assigned to the HistoricalDataConfiguration object
			* @param displayName			The DisplayName that is assigned to the HistoricalDataConfiguration object
			* @param browseName				The BrowseName that is assigned to the HistoricalDataConfiguration object
			* @param aggregateConfiguration	The AggregateConfiguration object to use for the HistoricalDataConfiguration.
			*								This object must already be initialized (see AggregateConfiguration::init()). */
			HistoricalDataConfiguration(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				ObjectPointer<AggregateConfiguration> aggregateConfiguration);

		public:
			/*! Returns the AggregateConfiguration object that contains information
			* how the server treats aggregate-specific functionality such as handling
			* 'Uncertain' data.
			*
			* @see Server::AggregateConfiguration */
			ObjectPointer<Server::AggregateConfiguration> getAggregateConfiguration();
			/*! @overload */
			ObjectPointer<const Server::AggregateConfiguration> getAggregateConfiguration() const;

			/*! Returns whether the historical data was collected in such a manner that it should be displayed as
			* SlopedInterpolation (sloped line between points) or as SteppedInterpolation (vertically-connected
			* horizontal lines between points) when raw data is examined.
			*
			* @see setStepped() */
			bool getStepped() const;
			/*! Defines whether the historical data was collected in such a manner that it should be displayed as
			* SlopedInterpolation (sloped line between points) or as SteppedInterpolation (vertically-connected
			* horizontal lines between points) when raw data is examined.
			*
			* @param stepped If true, historical data shall be displayed using stepped interpolation.
			*
			* @see Server::AggregateConfiguration::setUseSlopedExtrapolation() */
			EnumStatusCode setStepped(bool stepped);

			/*! Returns a vendor-specific, human readable string that specifies how the value of the
			* HistoricalDataNode is calculated.
			*
			* @see setDefinition() */
			tstring getDefinition() const;
			/*! Sets a vendor-specific, human readable string that specifies how the value of the HistoricalDataNode is calculated.
			* Definition is non-localized and will often contain an equation that can be parsed by certain client.
			* Example: Definition ::= "(TempA - 25) + TempB"
			*
			* @param definition The string that specifies how the value of the HistoricalDataNode is calculated. */
			EnumStatusCode setDefinition(const tstring& definition);

			/*! Returns the maximum interval (in ms) between data points in the history
			* repository regardless of their value change.
			*
			* @see setMaxTimeInterval() */
			double getMaxTimeInterval() const;
			/*! Defines the maximum interval (in ms) between data points in the history
			* repository regardless of their value change.
			*
			* @param maxTimeInterval The maximum time interval in milliseconds. */
			EnumStatusCode setMaxTimeInterval(OTDouble maxTimeInterval);

			/*! Returns the minimum interval (in ms) between data points in the history
			* repository regardless of their value change.
			*
			* @see setMinTimeInterval() */
			double getMinTimeInterval() const;
			/*! Defines the minimum interval (in ms) between data points in the history
			* repository regardless of their value change.
			*
			* @param minTimeInterval The minimum time interval in milliseconds. */
			EnumStatusCode setMinTimeInterval(OTDouble minTimeInterval);

			/*! Returns the minimum amount that the data for the HistoricalDataNode must change
			* in order for the change to be reported to the history database
			*
			* @see setExceptionDeviation() */
			double getExceptionDeviation() const;
			/*! Sets the minimum amount that the data for the HistoricalDataNode must change
			* in order for the change to be reported to the history database. The meaning
			* of this value depends on the exception deviation format.
			*
			* @param exceptionDeviation	The minimum amount data must change in order to be reported to
			*							the history database.
			*
			* @see setExceptionDeviationFormat() */
			EnumStatusCode setExceptionDeviation(OTDouble exceptionDeviation);

			/*! Returns the format of the exception deviation.
			*
			* @see setExceptionDeviation() setExceptionDeviationFormat() */
			EnumExceptionDeviationFormat getExceptionDeviationFormat() const;
			/*! Sets the format of the exception deviation.
			*
			* @param exceptionDeviationFormat The exception deviation format (see EnumExceptionDeviationFormat).
			*
			* @see setExceptionDeviation() */
			EnumStatusCode setExceptionDeviationFormat(EnumExceptionDeviationFormat exceptionDeviationFormat);

			/*! Returns the date before which there is no data in the archive, either online or offline.
			*
			* @see setStartOfArchive() */
			DateTime getStartOfArchive() const;
			/*! Sets the date before which there is no data in the archive, either online or offline.
			*
			* @param startOfArchive The start date of the historical archive for the HistoricalDataNode. */
			EnumStatusCode setStartOfArchive(const IDateTime& startOfArchive);

			/*! Returns the date of the earliest data in the online archive.
			*
			* @see setStartOfOnlineArchive() */
			DateTime getStartOfOnlineArchive() const;
			/*! Sets the date of the earliest data in the online archive.
			*
			* @param startOfOnlineArchive The start date of the online archive for the HistoricalDataNode. */
			EnumStatusCode setStartOfOnlineArchive(const IDateTime& startOfOnlineArchive);

		private:
			/*! Forbid use assignment operator */
			HistoricalDataConfiguration& operator=(const HistoricalDataConfiguration&);
			/*! Forbid use of copy constructor */
			HistoricalDataConfiguration(const HistoricalDataConfiguration&);
		};

		typedef ObjectPointer<HistoricalDataConfiguration> HistoricalDataConfigurationPtr;
		typedef ObjectPointer<const HistoricalDataConfiguration> HistoricalDataConfigurationConstPtr;
	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERHISTORICALDATACONFIGURATION_H
