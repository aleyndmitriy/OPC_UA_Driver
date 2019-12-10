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

#ifndef PUBSUBPUBLISHEDDATAIITEMS_H
#define PUBSUBPUBLISHEDDATAIITEMS_H

#include "PubSubPublishedDataSet.h"
#include "PublishedVariableDataType.h"

namespace SoftingOPCToolbox5
{
	namespace PubSub
	{
		/*! The PublishedDataItems class is a subclass of PublishedDataSet.
		* It is used to select a list of OPC UA Variables as the source for the creation of DataSets sent through one or more DataSetWriters.
		*
		* The published values represent any data provided in the address space.
		* Configuration which variables shall be published is done by setting the data source by invoking
		* PublishedDataSet::setDataSetSource with the derived PublishedDataItemsDataType. */
		class TBC_EXPORT PublishedDataItems
			: public PublishedDataSet
		{
		public:
			/*! Constructs a new PublishedDataItems instance */
			static ObjectPointer<PublishedDataItems> create();

		protected:
			/*! Default constructor */
			PublishedDataItems();

			/*! For internal use only */
			PublishedDataItems(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~PublishedDataItems();

		private:
			/*! Forbid use assignment operator */
			PublishedDataItems& operator=(const PublishedDataItems&);
			/*! Forbid use of copy constructor */
			PublishedDataItems(const PublishedDataItems&);
		};

		typedef ObjectPointer<PublishedDataItems>PublishedDataItemsPtr;
		typedef ObjectPointer<const PublishedDataItems> PublishedDataItemsConstPtr;
	} // end PubSub namespace
} // toolbox namespace end

#endif	// PUBSUBPUBLISHEDDATAIITEMS_H
