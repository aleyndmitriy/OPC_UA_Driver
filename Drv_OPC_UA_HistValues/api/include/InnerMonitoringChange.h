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

#ifndef INNERMONITORINGCHANGE_H
#define INNERMONITORINGCHANGE_H

#include "IMonitoringChange.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// class declaration for class InnerMonitoringChange
		class TBC_EXPORT InnerMonitoringChange
			: public IMonitoringChange
		{
		public:
			/*! Destructor */
			virtual ~InnerMonitoringChange();

			/* see IMonitoringChange::getAttributeId */
			virtual EnumAttributeId getAttributeId() const;

			/*! The minimum sampling interval that is used by all monitored items monitoring a specific node. */
			virtual double getMinimumSamplingInterval() const;

			/*! The monitoring state of the node before the last change. */
			virtual EnumMonitoringState getPreviousState() const;

			/*! The current monitoring state for the monitored item. */
			virtual EnumMonitoringState getCurrentState() const;


			// init from otb handle
			void initInner(MonitoringChangeStruct* pHandle);

			/*! Compares this instance to the given @p other instance.
			*
			* @li Returns <0, if "this < other"
			* @li Returns 0, if "this == other"
			* @li Returns >0, if "this > other" */
			virtual int compare(const IMonitoringChange* other) const;
			/*! @overload */
			virtual int compare(const IMonitoringChange& other) const;

			/*! Compares two instances for equality */
			virtual bool operator==(const IMonitoringChange& other) const;
			/*! Compares two instances for inequality */
			virtual bool operator!=(const IMonitoringChange& other) const;

			// set from interface
			EnumStatusCode set(const IMonitoringChange* pSrc);
			EnumStatusCode set(const IMonitoringChange& pSrc);

			// protected:
			// the handle to the related core object
			MonitoringChangeStruct* m_pMonitoringChange_Data;

			/*! For internal use only */
			virtual void* getInternHandle() const;
		};
	}
}
#endif	// INNERMONITORINGCHANGE_H
