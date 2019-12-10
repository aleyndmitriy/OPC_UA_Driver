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

#ifndef DATACHANGEFILTER_H
#define DATACHANGEFILTER_H

#include "IDataChangeFilter.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataChangeFilter data type is used by data change subscriptions (see Client::MonitoredItem::setFilter())
	* to specify the conditions under which a data change notification should be reported and, optionally, a
	* range or band for value changes where no data change notification is generated. This range is called "deadband". */
	class TBC_EXPORT DataChangeFilter
		: public IDataChangeFilter
	{
	public:
		/*! Default constructor */
		DataChangeFilter();
		/*! Constructs a copy of the given instance */
		DataChangeFilter(const IDataChangeFilter*);
		/*! @overload */
		DataChangeFilter(const IDataChangeFilter&);
		/*! @overload */
		DataChangeFilter(const DataChangeFilter&);

		/*! Destructor */
		virtual ~DataChangeFilter();

		/*! Assigns the contents of @p cp to this instance */
		DataChangeFilter& operator=(const IDataChangeFilter*);
		/*! @overload */
		DataChangeFilter& operator=(const IDataChangeFilter&);
		/*! @overload */
		DataChangeFilter& operator=(const DataChangeFilter&);

		/* see IDataChangeFilter::set */
		virtual EnumStatusCode set(const IDataChangeFilter* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataChangeFilter& pSrc);

		/* see IDataChangeFilter::compare */
		virtual int compare(const IDataChangeFilter*) const;
		/*! @overload */
		virtual int compare(const IDataChangeFilter&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataChangeFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataChangeFilter& other) const;

		/* see IDataChangeFilter::getTrigger */
		virtual EnumDataChangeTrigger getTrigger() const;
		/* see IDataChangeFilter::setTrigger */
		virtual void setTrigger(EnumDataChangeTrigger value);

		/* see IDataChangeFilter::getDeadbandType */
		virtual EnumDeadbandType getDeadbandType() const;
		/* see IDataChangeFilter::setDeadbandType */
		virtual void setDeadbandType(EnumDeadbandType value);

		/* see IDataChangeFilter::getDeadbandValue */
		virtual double getDeadbandValue() const;
		/* see IDataChangeFilter::setDeadbandValue */
		virtual void setDeadbandValue(double value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		DataChangeFilterStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATACHANGEFILTER_H
