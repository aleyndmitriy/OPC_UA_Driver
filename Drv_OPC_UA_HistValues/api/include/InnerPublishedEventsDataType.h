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

#ifndef INNERPUBLISHEDEVENTSDATATYPE_H
#define INNERPUBLISHEDEVENTSDATATYPE_H

#include "IPublishedEventsDataType.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "SimpleAttributeOperand.h"
#include "ISimpleAttributeOperand.h"
#include "InnerSimpleAttributeOperand.h"
#include "ContentFilter.h"
#include "IContentFilter.h"
#include "InnerContentFilter.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPublishedEventsDataType
		: public IPublishedEventsDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPublishedEventsDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the EventNotifier member of the class */
		virtual const INodeId* getEventNotifier() const;
		/*! Sets the EventNotifier member in the class */
		virtual EnumStatusCode setEventNotifier(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setEventNotifier(const NodeId& value);

		/*! Gets the SelectedFields member of the class */
		virtual std::vector<SimpleAttributeOperand> getSelectedFields() const;
		/*! Adds a SelectedField to the SelectedFields member of the class */
		virtual EnumStatusCode addSelectedField(const ISimpleAttributeOperand& selectField);

		/*! Gets the Filter member of the class */
		virtual const IContentFilter* getFilter() const;
		/*! Sets the Filter member in the class */
		virtual EnumStatusCode setFilter(const IContentFilter* value);
		/*! @overload */
		virtual EnumStatusCode setFilter(const ContentFilter& value);

		/*! For internal use only */
		void initInner(PublishedEventsDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType* pSrc);
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType& pSrc);

		virtual int compare(const IPublishedDataSetSourceDataType* other) const;
		virtual int compare(const IPublishedDataSetSourceDataType& other) const;

		virtual bool operator==(const IPublishedDataSetSourceDataType& other) const;
		virtual bool operator!=(const IPublishedDataSetSourceDataType& other) const;

		virtual PublishedDataSetSourceDataTypeStruct* getInternHandle();
		virtual const PublishedDataSetSourceDataTypeStruct* getInternHandle() const;

	private:
		InnerNodeId m_eventNotifier;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleAttributeOperand> m_pSelectedFields)
		InnerContentFilter m_filter;

		PublishedEventsDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
