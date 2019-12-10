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

#ifndef IDATETIME_H
#define IDATETIME_H

namespace SoftingOPCToolbox5
{
	/*! The DateTime data type defines a Gregorian calender date. The date and time
	* is stored in UTC time. The date and time value is based on 100 nanosecond ticks
	* since 1601 (FILETIME).
	*
	* An initially constructed DateTime instance contains a "null" value for DateTime.
	* The "null" value represents January 1, 1601 00:00:00 (UTC) (see IDateTime::isNull()). */
	class TBC_EXPORT IDateTime
	{
	public:
		/*! Destructor */
		virtual ~IDateTime() {}

		/*! Returns the number of 100 nanosecond ticks that represent the date and time of this instance.
		* DateTime is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual EnumStatusCode get(OTUInt64* pTicks) const = 0;
		/*! Sets the DateTime instance to the given number of 100 nanosecond ticks.
		* DateTime is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual EnumStatusCode set(OTUInt64 ticks) = 0;

		/*! Returns the number of seconds in Unix time that represent the date and time of this instance.
		* Unix time is a system for describing instances in time, defined as the number of seconds that have elapsed since midnight Coordinated Universal Time (UTC), 1 January 1970, not counting leap seconds.
		* @note	The conversion can fail with EnumStatusCode_BadOutOfRange if the date is before 1 January 1970. */
		virtual EnumStatusCode getUnixTime(OTUInt64* pUnixTicks) const = 0;
		/*! Sets the DateTime instance to the given number of seconds in Unix time.
		* Unix time is a system for describing instances in time, defined as the number of seconds that have elapsed since midnight Coordinated Universal Time (UTC), 1 January 1970, not counting leap seconds. */
		virtual EnumStatusCode setUnixTime(OTUInt64 unixTicks) = 0;

		/*! Returns the upper 32 bits of the 64 bit timestamp.
		* The timestamp is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual OTUInt32 getHighDateTime() const = 0;
		/*! Returns the lower 32 bits of the 64 bit timestamp.
		* The timestamp is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual OTUInt32 getLowDateTime() const = 0;

		/*! Sets the upper 32 bits of the 64 bit timestamp.
		* The timestamp is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual void setHighDateTime(OTUInt32 highDateTime) = 0;
		/*! Sets the lower 32 bits of the 64 bit timestamp.
		* The timestamp is based on 100 nanosecond ticks since 1601 (FILETIME). */
		virtual void setLowDateTime(OTUInt32 lowDateTime) = 0;

		/*! Returns the millisecond component of the date represented by the DateTime instance. */
		virtual OTUInt32 milliSecondGMT() const = 0;
		/*! Returns the millisecond component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use milliSecondGMT() to return the component based on UTC time. */
		virtual OTUInt32 milliSecond() const = 0;

		/*! Returns the second component of the date represented by the DateTime instance. */
		virtual OTUInt16 secondGMT() const = 0;
		/*! Returns the second component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use secondGMT() to return the component based on UTC time. */
		virtual OTUInt16 second() const = 0;

		/*! Returns the minute component of the date represented by the DateTime instance. */
		virtual OTUInt16 minuteGMT() const = 0;
		/*! Returns the minute component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use minuteGMT() to return the component based on UTC time. */
		virtual OTUInt16 minute() const = 0;

		/*! Returns the hour component of the date represented by the DateTime instance. */
		virtual OTUInt16 hourGMT() const = 0;
		/*! Returns the hour component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use hourGMT() to return the component based on UTC time. */
		virtual OTUInt16 hour() const = 0;

		/*! Returns the day component of the date represented by the DateTime instance. */
		virtual OTUInt16 dayGMT() const = 0;
		/*! Returns the day component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use dayGMT() to return the component based on UTC time. */
		virtual OTUInt16 day() const = 0;

		/*! Returns the month component of the date represented by the DateTime instance. */
		virtual OTUInt16 monthGMT() const = 0;
		/*! Returns the month component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use monthGMT() to return the component based on UTC time. */
		virtual OTUInt16 month() const = 0;

		/*! Returns the year component of the date represented by the DateTime instance. */
		virtual OTUInt32 yearGMT() const = 0;
		/*! Returns the year component of the date represented by the DateTime instance.
		* The component is converted to the system's local time before being returned.
		*
		* @note	The component of the date returned by this method is converted to local time.
		*		Please use yearGMT() to return the component based on UTC time. */
		virtual OTUInt32 year() const = 0;

		/*! Adds the specified number of milliseconds to the date represented by the DateTime instance.
		*
		* @param milliseconds	The number of milliseconds to add
		*
		* @see subtractMilliseconds() */
		virtual void addMilliseconds(OTUInt64 milliseconds) = 0;

		/*! Subtracts the specified number of milliseconds from the date represented by the DateTime instance.
		*
		* @param milliseconds	The number of milliseconds to subtract
		*
		* @see addMilliseconds() */
		virtual void subtractMilliseconds(OTUInt64 milliseconds) = 0;

		/*! Sets this DateTime instance to the current date and time. */
		virtual void utcNow() = 0;

		/*! Returns whether this DateTime instance contains a "null" value.
		*
		* The "null" value is represented by January 1, 1601 00:00:00 (UTC) */
		virtual bool isNull() const = 0;

		/*! Parses the given string and sets the parsed date on the DateTime instance.
		*
		* The string must conform to the following syntax: YYYY-MM-DDThh:mm:ssZ
		* Example: 2000-01-31T13:00:00Z */
		virtual EnumStatusCode parse(const tstring& dateString) = 0;

		/*! Returns a string representation of the DateTime instance for debugging purposes */
		virtual tstring toString() const = 0;

		/*! Returns a VersionTime representation of this DateTime.
		*
		* The VersionTime represents the time since January 1, 2000 00:00:00 (UTC) in seconds
		*
		* Returns 0 if the DateTime value is out of range for a VersionTime */
		virtual OTUInt32 getVersionTime() const = 0;

		/*! Sets a time from a VersionTime representation.
		*
		* The VersionTime represents the time since January 1, 2000 00:00:00 (UTC) in seconds */
		virtual void setFromVersionTime(OTUInt32 versionTime) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IDateTime* source) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IDateTime& source) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDateTime* other) const = 0;
		/*! @overload */
		virtual int compare(const IDateTime& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDateTime& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDateTime& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	};
} // end namespace
#endif	// IDATETIME_H
