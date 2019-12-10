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

#ifndef PUBSUBPUBLISHEDEVENTS_H
#define PUBSUBPUBLISHEDEVENTS_H

#include "PubSubPublishedDataSet.h"

namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
#ifdef NOT_YET_IMPLEMENTED
		/*! The PublishedEvents class is a subclass of PublishedDataSet.
		* It is used to configure the collection of OPC UA Events as the source for the creation of DataSets sent through one or more DataSetWriters.
		*
		* The published values represent a list of Event fields reported on a specific node, including an event filter.
		* The functionality is similar to an Event MonitoredItem.
		* Configuration which events shall be published is done by setting the data source by invoking
		* PublishedDataSet::setDataSetSource with the derived PublishedEventsDataType.
		*
		* The properties in address space "EventNotifier", "SelectedField" and "Filter" are automatically filled with this information.
		*
		* @note The functionality of this class is not yet fully implemented.
		*		Especially providing of event data to be published is not yet implemented.
		*		Please do @p NOT use this class! */
		class TBC_EXPORT PublishedEvents
			: public PublishedDataSet
		{
		public:
			/*! Constructs a new PublishedEvents instance */
			static ObjectPointer<PublishedEvents> create();

		protected:
			/*! Default constructor */
			PublishedEvents();

			/*! For internal use only */
			PublishedEvents(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~PublishedEvents();

		private:
			/*! Forbid use assignment operator */
			PublishedEvents& operator=(const PublishedEvents&);
			/*! Forbid use of copy constructor */
			PublishedEvents(const PublishedEvents&);
		};

		typedef ObjectPointer<PublishedEvents>PublishedEventsPtr;
		typedef ObjectPointer<const PublishedEvents> PublishedEventsConstPtr;
#endif
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBPUBLISHEDEVENTS_H
