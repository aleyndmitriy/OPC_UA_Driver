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

#ifndef DATETIME_H
#define DATETIME_H

#include "IDateTime.h"
#include "DateTimeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DateTime data type defines a Gregorian calender date. The date and time
	* is stored in UTC time. The date and time value is based on 100 nanosecond ticks
	* since 1601 (FILETIME).
	*
	* An initially constructed DateTime instance contains a "null" value for DateTime.
	* The "null" value represents January 1, 1601 00:00:00 (UTC) (see IDateTime::isNull()). */
	class TBC_EXPORT DateTime
		: public IDateTime
	{
	public:
		/*! Default constructor */
		DateTime();
		/*! Initializes a new DateTime instance to a given number of ticks.
		*
		* @param ticks	100 nanosecond ticks since 1601. */
		DateTime(OTUInt64 ticks);
		/*! @overload */
		DateTime(OTUInt32 highDateTime, OTUInt32 lowDateTime);
		/*! Constructs a copy of the given instance */
		DateTime(const IDateTime*);
		/*! @overload */
		DateTime(const DateTime&);

		/*! Destructor */
		virtual ~DateTime();

		/*! Assigns the contents of @p cp to this instance */
		const DateTime& operator=(const IDateTime* cp);
		/*! @overload */
		const DateTime& operator=(const DateTime& cp);

		/* see IDateTime::set */
		virtual EnumStatusCode set(const IDateTime*);
		/*! @overload */
		virtual EnumStatusCode set(const IDateTime&);

		/* see IDateTime::compare */
		virtual int compare(const IDateTime*) const;
		/*! @overload */
		virtual int compare(const IDateTime&) const;

		/* see IDateTime::operator== */
		virtual bool operator==(const IDateTime& other) const;
		/* see IDateTime::operator!= */
		virtual bool operator!=(const IDateTime& other) const;

		/* see IDateTime::get(OTUInt64*) */
		virtual EnumStatusCode get(OTUInt64* pTicks) const;
		/* see IDateTime::set(OTUInt64) */
		virtual EnumStatusCode set(OTUInt64 ticks);

		/* see IDateTime::getUnixTime */
		virtual EnumStatusCode getUnixTime(OTUInt64* pUnixTicks) const;
		/* see IDateTime::setUnixTime */
		virtual EnumStatusCode setUnixTime(OTUInt64 unixTicks);

#ifdef SOOS_WINDOWS
		/*! Returns the stored timestamp as FILETIME timestamp.
		*
		* @note This method is only available on Microsoft Windows operating systems. */
		virtual void get(FILETIME& fileTime) const;
		/*! Sets the given FILETIME timestamp on this DateTime instance.
		*
		* @note This method is only available on Microsoft Windows operating systems. */
		virtual void set(const FILETIME& fileTime);
#endif

		/* see IDateTime::getHighDateTime */
		virtual OTUInt32 getHighDateTime() const;
		/* see IDateTime::getLowDateTime */
		virtual OTUInt32 getLowDateTime() const;

		/* see IDateTime::setHighDateTime */
		virtual void setHighDateTime(OTUInt32 highDateTime);
		/* see IDateTime::setLowDateTime */
		virtual void setLowDateTime(OTUInt32 lowDateTime);

		/* see IDateTime::milliSecondGMT */
		virtual OTUInt32 milliSecondGMT() const;
		/* see IDateTime::milliSecond */
		virtual OTUInt32 milliSecond() const;

		/* see IDateTime::secondGMT */
		virtual OTUInt16 secondGMT() const;
		/* see IDateTime::second */
		virtual OTUInt16 second() const;

		/* see IDateTime::minuteGMT */
		virtual OTUInt16 minuteGMT() const;
		/* see IDateTime::minute */
		virtual OTUInt16 minute() const;

		/* see IDateTime::hourGMT */
		virtual OTUInt16 hourGMT() const;
		/* see IDateTime::hour */
		virtual OTUInt16 hour() const;

		/* see IDateTime::dayGMT */
		virtual OTUInt16 dayGMT() const;
		/* see IDateTime::day */
		virtual OTUInt16 day() const;

		/* see IDateTime::monthGMT */
		virtual OTUInt16 monthGMT() const;
		/* see IDateTime::month */
		virtual OTUInt16 month() const;

		/* see IDateTime::yearGMT */
		virtual OTUInt32 yearGMT() const;
		/* see IDateTime::year */
		virtual OTUInt32 year() const;

		/* see IDateTime::addMilliseconds */
		virtual void addMilliseconds(OTUInt64 milliseconds);

		/* see IDateTime::subtractMilliseconds */
		virtual void subtractMilliseconds(OTUInt64 milliseconds);

		/* see IDateTime::utcNow */
		virtual void utcNow();

		/*! Returns a DateTime instance containing the current date and time. */
		static DateTime getUtcNow();

		/*! Returns the duration in milliseconds between two timestamps if @p from <= @p to.
		* If @p from > @p to, the method returns 0. */
		static OTUInt64 getDurationMilliseconds(const DateTime& from, const DateTime& to);

		/* see IDateTime::isNull */
		virtual bool isNull() const;

		/* see IDateTime::parse */
		virtual EnumStatusCode parse(const tstring& dateString);

		/* see IDateTime::toString */
		virtual tstring toString() const;

		/* see IDateTime::getVersionTime */
		virtual OTUInt32 getVersionTime() const;

		/* see IDateTime::setFromVersionTime */
		virtual void setFromVersionTime(OTUInt32 versionTime);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		void* getInternHandle() const;

	private:
		DateTimeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// DATETIME_H
