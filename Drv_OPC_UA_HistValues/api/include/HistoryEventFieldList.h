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

#ifndef HISTORYEVENTFIELDLIST_H
#define HISTORYEVENTFIELDLIST_H
#if TB5_HISTORY

#include "IHistoryEventFieldList.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The HistoryEventFieldList data type contains a list of historical events being delivered to a
	* client as result of a HistoryRead service call (see Client::Session::historyReadEvent()). The size
	* and order of the elements in this list is determined by the select clauses in the EventFilter
	* (see ReadEventDetails::setFilter()). */
	class TBC_EXPORT HistoryEventFieldList
		: public IHistoryEventFieldList
	{
	public:
		/*! Default constructor */
		HistoryEventFieldList();
		/*! Constructs a copy of the given instance @p cp */
		HistoryEventFieldList(const IHistoryEventFieldList* cp);
		/*! @overload */
		HistoryEventFieldList(const IHistoryEventFieldList& cp);
		/*! @overload */
		HistoryEventFieldList(const HistoryEventFieldList& cp);

		/*! Destructor */
		virtual ~HistoryEventFieldList();

		/*! Assigns the contents of @p cp to this instance */
		HistoryEventFieldList& operator=(const IHistoryEventFieldList* cp);
		/*! @overload */
		HistoryEventFieldList& operator=(const IHistoryEventFieldList& cp);
		/*! @overload */
		HistoryEventFieldList& operator=(const HistoryEventFieldList& cp);

		/* see IHistoryEventFieldList::set */
		virtual EnumStatusCode set(const IHistoryEventFieldList* pSrc);
		/*! overload */
		virtual EnumStatusCode set(const IHistoryEventFieldList& pSrc);

		/* see IHistoryEventFieldList::compare */
		virtual int compare(const IHistoryEventFieldList* other) const;
		/*! @overload */
		virtual int compare(const IHistoryEventFieldList& other) const;
		/*! @overload */
		virtual int compare(const HistoryEventFieldList& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IHistoryEventFieldList& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IHistoryEventFieldList& other) const;

		/* see IHistoryEventFieldList::getEventFields */
		virtual std::vector<Value> getEventFields() const;
		/* see IHistoryEventFieldList::addEventField */
		virtual EnumStatusCode addEventField(const IValue* value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_pEventFields)

		HistoryEventFieldListStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// HISTORYEVENTFIELDLIST_H
