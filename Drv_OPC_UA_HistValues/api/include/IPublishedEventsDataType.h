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

#ifndef IPUBLISHEDEVENTSDATATYPE_H
#define IPUBLISHEDEVENTSDATATYPE_H

#include "NodeId.h"
#include "INodeId.h"
#include "SimpleAttributeOperand.h"
#include "ISimpleAttributeOperand.h"
#include "ContentFilter.h"
#include "IContentFilter.h"
#include "IPublishedDataSetSourceDataType.h"

namespace SoftingOPCToolbox5
{
	/*! Interface for PublishedEventsDataType, which is used to store PublishedEvents specific parameters.
	*
	* This structure is used e.g. in
	* @li structure class PublishedDataSetDataType */
	class TBC_EXPORT IPublishedEventsDataType : public IPublishedDataSetSourceDataType
	{
	public:
		/*! Destructor */
		virtual ~IPublishedEventsDataType(){};

		/*! Gets the EventNotifier member of the class */
		virtual const INodeId* getEventNotifier() const = 0;
		/*! Sets the EventNotifier member in the class
		*
		* The parameter EventNotifier defines the NodeId of the Object in the event notifier tree of the
		* OPC UA Server from which Events are collected. */
		virtual EnumStatusCode setEventNotifier(const INodeId* eventNotifier) = 0;
		/*! @overload */
		virtual EnumStatusCode setEventNotifier(const NodeId& eventNotifier) = 0;

		/*! Gets the SelectedFields member of the class */
		virtual std::vector<SimpleAttributeOperand> getSelectedFields() const = 0;
		/*! Adds a SelectedField to the SelectedFields member of the class
		*
		* The parameter SelectedFields defines the selection of Event fields contained in the PublishedDataSet
		* generated for an Event and sent through the DataSetWriter. */
		virtual EnumStatusCode addSelectedField(const ISimpleAttributeOperand& selectField) = 0;

		/*! Gets the Filter member of the class */
		virtual const IContentFilter* getFilter() const = 0;
		/*! Sets the Filter member in the class
		*
		* The parameter Filter defines the filter applied to the Events.
		* It allows the reduction of the DataSets generated from Events through a filter. */
		virtual EnumStatusCode setFilter(const IContentFilter* filter) = 0;
		/*! @overload */
		virtual EnumStatusCode setFilter(const ContentFilter& filter) = 0;

		/*! Conversion from IPublishedDataSetSourceDataType */
		static const IPublishedEventsDataType* castFrom(const IPublishedDataSetSourceDataType* pSrc);
		/*! Conversion from IPublishedDataSetSourceDataType */
		static IPublishedEventsDataType* castFrom(IPublishedDataSetSourceDataType* pSrc);
	}; // end IPublishedEventsDataType
} // end namespace

#endif
