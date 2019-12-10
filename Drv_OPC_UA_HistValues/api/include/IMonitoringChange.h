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

#ifndef IMONITORINGCHANGE_H
#define IMONITORINGCHANGE_H

#include "MonitoringChangeStruct.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class provides information about changes in the monitoring state of a node in the address space.
		*
		* @see Application::handleMonitoringChange() */
		class TBC_EXPORT IMonitoringChange
		{
		public:
			/*! Destructor */
			virtual ~IMonitoringChange() {};

			/*! Returns the monitored attribute. */
			virtual EnumAttributeId getAttributeId() const = 0;

			/*! Returns the minimum sampling interval that is used by all monitored items monitoring a specific node. */
			virtual double getMinimumSamplingInterval() const = 0;

			/*! Returns the monitoring state of the node before the last change. */
			virtual EnumMonitoringState getPreviousState() const = 0;

			/*! Returns the current monitoring state for the monitored item. */
			virtual EnumMonitoringState getCurrentState() const = 0;

			/*! Copies the content of @p cp to this instance */
			virtual EnumStatusCode set(const IMonitoringChange*) = 0;
			/*! @overload */
			virtual EnumStatusCode set(const IMonitoringChange&) = 0;

			/*! Compares this instance to the given @p other instance.
			*
			* @li Returns <0, if "this < other"
			* @li Returns 0, if "this == other"
			* @li Returns >0, if "this > other" */
			virtual int compare(const IMonitoringChange* other) const = 0;
			/*! @overload */
			virtual int compare(const IMonitoringChange& other) const = 0;

			/*! Compares two instances for equality */
			virtual bool operator==(const IMonitoringChange& other) const = 0;
			/*! Compares two instances for inequality */
			virtual bool operator!=(const IMonitoringChange& other) const = 0;

			/*! For internal use only */
			virtual void* getInternHandle() const = 0;
		}; // end IMonitoringChange
	}
} // end namespace

#endif	// IMONITORINGCHANGE_H
