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

#ifndef PUBLISHEDEVENTSDATATYPE_H
#define PUBLISHEDEVENTSDATATYPE_H

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
#include "PublishedEventsDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of PublishedDataSetSourceDataType.
	*
	* It is used to store PublishedEvents specific parameters.
	*
	* This structure is used e.g. in
	* @li structure class PublishedDataSetDataType */
	class TBC_EXPORT PublishedEventsDataType
		: public IPublishedEventsDataType
	{
	public:
		/*! Default constructor */
		PublishedEventsDataType();
		/*! Constructs a copy of the given instance @p cp */
		PublishedEventsDataType(const IPublishedEventsDataType* cp);
		/*! @overload */
		PublishedEventsDataType(const IPublishedEventsDataType& cp);
		/*! @overload */
		PublishedEventsDataType(const PublishedEventsDataType& cp);

		/*! Destructor */
		virtual ~PublishedEventsDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		PublishedEventsDataType& operator=(const IPublishedEventsDataType* cp);
		/*! @overload */
		PublishedEventsDataType& operator=(const IPublishedEventsDataType& cp);
		/*! @overload */
		PublishedEventsDataType& operator=(const PublishedEventsDataType& cp);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IPublishedDataSetSourceDataType* other) const;
		/*! @overload */
		virtual int compare(const IPublishedDataSetSourceDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedDataSetSourceDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedDataSetSourceDataType& other) const;

		/*! see IPublishedDataSetSourceDataType::set(IPublishedDataSetSourceDataType*) */
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType& pSrc);

		/* see IPublishedEventsDataType::getEventNotifier */
		virtual const INodeId* getEventNotifier() const;
		/* see IPublishedEventsDataType::setEventNotifier */
		virtual EnumStatusCode setEventNotifier(const INodeId* eventNotifier);
		/*! @overload */
		virtual EnumStatusCode setEventNotifier(const NodeId& eventNotifier);

		/* see IPublishedEventsDataType::getSelectedFields */
		virtual std::vector<SimpleAttributeOperand> getSelectedFields() const;
		/* see IPublishedEventsDataType::addSelectedField */
		virtual EnumStatusCode addSelectedField(const ISimpleAttributeOperand& selectField);

		/* see IPublishedEventsDataType::getFilter */
		virtual const IContentFilter* getFilter() const;
		/* see IPublishedEventsDataType::setFilter */
		virtual EnumStatusCode setFilter(const IContentFilter* filter);
		/*! @overload */
		virtual EnumStatusCode setFilter(const ContentFilter& filter);

		/*! For internal use only */
		virtual PublishedDataSetSourceDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const PublishedDataSetSourceDataTypeStruct* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNodeId m_eventNotifier;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleAttributeOperand> m_pSelectedFields)
		InnerContentFilter m_filter;

		PublishedEventsDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
