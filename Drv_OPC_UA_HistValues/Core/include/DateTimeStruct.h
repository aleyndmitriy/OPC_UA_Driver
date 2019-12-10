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

#ifndef _DATETIMESTRUCT_H_
#define _DATETIMESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*!
*  @brief Hold date-time information.
*
*  Usage: this structure always store the GMT time inside
*  and local time can be requested with the specific methods.
*/
//lint -sem(DateTimeStruct::clear, cleanup)
//lint -sem(DateTimeStruct::clear, initializer)
typedef struct TBCORE_IF DateTimeStruct
{
public:
	OTUInt32 lowDateTime;
	OTUInt32 highDateTime;


	DateTimeStruct(void);

	EnumStatusCode set(const DateTimeStruct& cp);
	EnumStatusCode get(DateTimeStruct& target) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DateTime& cp);
	EnumStatusCode get(OpcUa_DateTime& target) const;
#endif

	int compare(const DateTimeStruct* with) const
	{
		if(highDateTime > with->highDateTime)
			return 1;
		if(highDateTime < with->highDateTime)
			return -1;
		if(lowDateTime > with->lowDateTime)
			return 1;
		if(lowDateTime < with->lowDateTime)
			return -1;
		return 0;
	}

#ifdef SOOS_WINDOWS
	/*!
	* @brief FILETIME Represents the number of
	* 100-nanosecond intervals since January 1, 1601.
	*/
	void set(const FILETIME& fileTime);
	void get(FILETIME& fileTime) const;
#endif

	void substractMillis(OTUInt64 diff);
	void substract(OTUInt64 diff);
	void addMillis(OTUInt64 diff);
	void add(OTUInt64 diff);

	/*! @brief set the current GMT time for this structure. */
	void utcNow(void);
	int areEqual(const DateTimeStruct& cp) const;
	/*!
	*  @brief Gets the milliseconds component of the date represented by
	*  this instance(Local).
	*/
	OTUInt32 milliSecond(void) const;
	/*!
	*  @brief Gets the milliseconds component of the date represented by
	*  this instance(GMT).
	*/
	OTUInt32 milliSecondGMT(void) const;
	/*!
	* @brief Gets the seconds component of the date represented by this
	* instance(Local).
	*/
	OTUInt16 second(void) const;
	/*!
	* @brief Gets the seconds component of the date represented by this
	* instance(GMT).
	*/
	OTUInt16 secondGMT(void) const;

	/*!
	*   @brief Gets the minute component of the date represented by this
	*   instance(Local).
	*/
	OTUInt16 minute(void) const;
	/*!
	* @brief Gets the minute component of the date represented by this
	* instance(GMT).
	*/
	OTUInt16 minuteGMT(void) const;
	/*!
	*   @brief Gets the hour component of the date represented by this
	*   instance(Local).
	*/
	OTUInt16 hour(void) const;
	/*!
	* @brief Gets the hour component of the date represented by this
	* instance(GMT).
	*/
	OTUInt16 hourGMT(void) const;
	/*!
	*   @brief Gets the day of the month represented by this instance(Local).
	*/
	OTUInt16 day(void) const;
	/*!
	*   @brief Gets the month component of the date represented by this
	*   instance(Local).
	*/
	/*!
	* @brief Gets the day of the month represented by this instance(GMT).
	*/
	OTUInt16 dayGMT(void) const;

	OTUInt16 month(void) const;
	/*!
	* @brief Gets the month component of the date represented by this
	* instance(GMT).
	*/
	OTUInt16 monthGMT(void) const;

	/*!
	*   @brief Gets the year component of the date represented by
	*   this instance(Local).
	*/
	OTUInt32 year(void) const;
	/*!
	* @brief Gets the year component of the date represented by this
	* instance(GMT).
	*/
	OTUInt32 yearGMT(void) const;
	/*! @brief calculate the difference in milliseconds between two
	*   times. If from > to, then 0 is returned.
	*/
	static OTUInt64 getDurationMilliseconds(
		const DateTimeStruct &from,
		const DateTimeStruct &to);

	/*! calculate the difference in 10 nanoseconds between two
	* times. If from > to, then 0 is returned. */
	static OTUInt64 getDuration(
		const DateTimeStruct &from,
		const DateTimeStruct &to);

	/*!
	 * @brief Returns whether the DateTime is null, i.e. is zero
	 * seconds since January 1, 1601 (UTC)
	 */
	bool isNull() const;

#ifdef SOOS_WINDOWS
/*!
	* @brief Calculate the SystemTime from FileTime on Windows OS.
	*/
	bool getWinLocalSystimeFromFileTime(SYSTEMTIME& sysTime) const;
#endif

	const DateTimeStruct& operator=(const DateTimeStruct& cp);
	bool operator==(const DateTimeStruct& toCompare) const;
	bool operator!=(const DateTimeStruct& toCompare) const;

	void clear(void);
	tstring toString(void) const;
	EnumStatusCode fromString(const tstring& dateStr);

	/*! Converts the DateTime to VersionTime in seconds since 1. January 2000 */
	OTUInt32 getVersionTime() const;

	/*! Set a value from a VersionTime representation in seconds since 1. January 2000. */
	void setFromVersionTime(OTUInt32 versionTime);

}DateTimeStruct;

#ifdef OT_COMPILATION
#ifdef SOOS_WINDOWS
inline void DateTimeStruct::set(const FILETIME& fileTime)
{
	lowDateTime  = fileTime.dwLowDateTime;
	highDateTime = fileTime.dwHighDateTime;
}

inline void DateTimeStruct::get(FILETIME& fileTime) const
{
	fileTime.dwLowDateTime = (DWORD)lowDateTime;
	fileTime.dwHighDateTime = (DWORD)highDateTime;
}
#endif

inline void DateTimeStruct::clear(void)
{
	lowDateTime  = 0;
	highDateTime = 0;
}

inline EnumStatusCode DateTimeStruct::set(const DateTimeStruct& cp)
{
	// Avoid self-assignment
	if(this == &cp)
	{
		return EnumStatusCode_Good;
	}

	this->highDateTime = cp.highDateTime;
	this->lowDateTime  = cp.lowDateTime;
	return EnumStatusCode_Good;
}

inline EnumStatusCode DateTimeStruct::get(DateTimeStruct& target) const
{
	target.highDateTime = highDateTime;
	target.lowDateTime  = lowDateTime;
	return EnumStatusCode_Good;
}

inline EnumStatusCode DateTimeStruct::set(const OpcUa_DateTime& cp)
{
	this->highDateTime = cp.dwHighDateTime;
	this->lowDateTime  = cp.dwLowDateTime;
	return EnumStatusCode_Good;
}

inline EnumStatusCode DateTimeStruct::get(OpcUa_DateTime& target) const
{
	target.dwHighDateTime = highDateTime;
	target.dwLowDateTime  = lowDateTime;

	return EnumStatusCode_Good;
}
#endif

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _DATETIMESTRUCT_H_
