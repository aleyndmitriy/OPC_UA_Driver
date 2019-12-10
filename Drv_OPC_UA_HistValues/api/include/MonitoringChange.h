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

#ifndef MONITORINGCHANGE_H
#define MONITORINGCHANGE_H

#include "IMonitoringChange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class provides information about changes in the monitoring state of a node in the address space.
		*
		* @see Application::handleMonitoringChange() */
		class TBC_EXPORT MonitoringChange
			: public IMonitoringChange
		{
		public:
			/*! Default constructor */
			MonitoringChange();
			/*! Constructs a copy of the given instance */
			MonitoringChange(const IMonitoringChange*);
			/*! @overload */
			MonitoringChange(const IMonitoringChange&);
			/*! @overload */
			MonitoringChange(const MonitoringChange&);

			/*! Destructor */
			virtual ~MonitoringChange();

			/*! Assigns the contents of @p cp to this instance */
			MonitoringChange& operator=(const IMonitoringChange*);
			/*! @overload */
			MonitoringChange& operator=(const IMonitoringChange&);
			/*! @overload */
			MonitoringChange& operator=(const MonitoringChange&);

			/* see IMonitoringChange::set */
			virtual EnumStatusCode set(const IMonitoringChange* pSrc);
			/*! @overload */
			virtual EnumStatusCode set(const IMonitoringChange& pSrc);

			/* see IMonitoringChange::compare */
			virtual int compare(const IMonitoringChange*) const;
			/*! @overload */
			virtual int compare(const IMonitoringChange&) const;

			/*! Compares two instances for equality */
			virtual bool operator==(const IMonitoringChange& other) const;
			/*! Compares two instances for inequality */
			virtual bool operator!=(const IMonitoringChange& other) const;

			/* see IMonitoringChange::getAttributeId */
			virtual EnumAttributeId getAttributeId() const;

			/* see IMonitoringChange::getMinimumSamplingInterval */
			virtual double getMinimumSamplingInterval() const;

			/* see IMonitoringChange::getPreviousState */
			virtual EnumMonitoringState getPreviousState() const;

			/* see IMonitoringChange::getCurrentState */
			virtual EnumMonitoringState getCurrentState() const;

			/*! Clears the contents of this object to enable its re-use. */
			void clear();

			/*! For internal use only */
			virtual void* getInternHandle() const;

		private:
			/*! For internal use only */
			void initMembers();

			MonitoringChangeStruct m_content;
		};
	} // end Server namespace
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// MONITORINGCHANGE_H
