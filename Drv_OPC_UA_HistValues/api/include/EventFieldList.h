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

#ifndef EVENTFIELDLIST_H
#define EVENTFIELDLIST_H
#if TB5_FILTER

#include "IEventFieldList.h"
#include "InnerValue.h"
#include "Value.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EventFieldList data type contains a list of events being delivered to a
	* client (see Client::Subscription::onEventsReceived()). The size and order of the elements
	* in this list is determined by the select clauses in the EventFilter. */
	class TBC_EXPORT EventFieldList
		: public IEventFieldList
	{
	public:
		/*! Default constructor */
		EventFieldList();
		/*! Constructs a copy of the given instance */
		EventFieldList(const IEventFieldList*);
		/*! @overload */
		EventFieldList(const IEventFieldList&);
		/*! @overload */
		EventFieldList(const EventFieldList&);

		/*! Destructor */
		virtual ~EventFieldList();

		/*! Assigns the contents of @p cp to this instance */
		EventFieldList& operator=(const IEventFieldList* cp);
		/*! @overload */
		EventFieldList& operator=(const IEventFieldList& cp);
		/*! @overload */
		EventFieldList& operator=(const EventFieldList& cp);

		/* see IEventFieldList::set */
		virtual EnumStatusCode set(const IEventFieldList* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEventFieldList& pSrc);

		/* see IEventFieldList::compare */
		virtual int compare(const IEventFieldList*) const;
		/*! @overload */
		virtual int compare(const IEventFieldList&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFieldList& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFieldList& other) const;

		/* see IEventFieldList::getEventFieldCount */
		virtual OTUInt32 getEventFieldCount() const;
		/* see IEventFieldList::getEventField */
		virtual const IValue* getEventField(OTUInt32 index) const;
		/* see IEventFieldList::getEventFields */
		virtual std::vector<Value> getEventFields() const;
		/* see IEventFieldList::addEventField */
		virtual EnumStatusCode addEventField(const IValue* pValue);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_EventFields)
		EventFieldListStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// EVENTFIELDLIST_H
