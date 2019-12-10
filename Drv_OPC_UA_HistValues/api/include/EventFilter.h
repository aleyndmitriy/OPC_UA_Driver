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

#ifndef EVENTFILTER_H
#define EVENTFILTER_H
#if TB5_ALARMS

#include "IEventFilter.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"
#include "InnerContentFilter.h"
#include "ContentFilter.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EventFilter data type is used by event MonitoredItems (see Client::MonitoredItem::setEventFilter()) to
	* specify the content of reported events (select clauses) and criteria for an event to be reported (where clause). */
	class TBC_EXPORT EventFilter
		: public IEventFilter
	{
	public:
		/*! Default constructor */
		EventFilter();
		/*! Constructs a copy of the given instance */
		EventFilter(const IEventFilter*);
		/*! @overload */
		EventFilter(const IEventFilter&);
		/*! @overload */
		EventFilter(const EventFilter&);

		/*! Destructor */
		virtual ~EventFilter();

		/*! Assigns the contents of @p cp to this instance */
		EventFilter& operator=(const IEventFilter*);
		/*! @overload */
		EventFilter& operator=(const IEventFilter&);
		/*! @overload */
		EventFilter& operator=(const EventFilter&);

		/* see IEventFilter::set */
		virtual EnumStatusCode set(const IEventFilter* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEventFilter& pSrc);

		/* see IEventFilter::compare */
		virtual int compare(const IEventFilter*) const;
		/*! @overload */
		virtual int compare(const IEventFilter&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFilter& other) const;

		/* see IEventFilter::getSelectClauseCount */
		virtual OTUInt32 getSelectClauseCount() const;
		/* see IEventFilter::getSelectClause */
		virtual const ISimpleAttributeOperand* getSelectClause(OTUInt32 index) const;
		/* see IEventFilter::getSelectClauses */
		virtual std::vector<SimpleAttributeOperand> getSelectClauses() const;
		/* see IEventFilter::addSelectClause */
		virtual EnumStatusCode addSelectClause(const ISimpleAttributeOperand* pValue);
		/*! @overload */
		virtual EnumStatusCode addSelectClause(const SimpleAttributeOperand& value);

		/* see IEventFilter::getWhereClause */
		virtual const IContentFilter* getWhereClause() const;
		/*! @overload */
		virtual IContentFilter* getWhereClause();
		/* see IEventFilter::setWhereClause */
		virtual void setWhereClause(const IContentFilter* value);
		/*! @overload */
		virtual void setWhereClause(const ContentFilter& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleAttributeOperand> m_SelectClauses)
		InnerContentFilter m_WhereClause;

		EventFilterStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// EVENTFILTER_H
