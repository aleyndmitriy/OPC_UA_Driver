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

#ifndef TIMEZONE_H
#define TIMEZONE_H

#include "ITimeZone.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The TimeZone data type defines the local time that may or may not take
	* daylight saving time into account. */
	class TBC_EXPORT TimeZone
		: public ITimeZone
	{
	public:
		/*! Default constructor */
		TimeZone();
		/*! Constructs a TimeZone that defines a given offset in minutes.
		*
		* @param offset						The offset in minutes from UTC time
		* @param daylightSavingInOffset		If true, the daylight saving time (DST) is in effect
		*									and the offset includes the DST correction. */
		TimeZone(OTInt16 offset, bool daylightSavingInOffset);
		/*! Constructs a copy of the given instance */
		TimeZone(const ITimeZone*);
		/*! @overload */
		TimeZone(const ITimeZone&);
		/*! @overload */
		TimeZone(const TimeZone&);

		/*! Destructor */
		virtual ~TimeZone();

		/*! Assigns the contents of @p cp to this instance */
		TimeZone& operator=(const ITimeZone* cp);
		/*! @overload */
		TimeZone& operator=(const ITimeZone& cp);
		/*! @overload */
		TimeZone& operator=(const TimeZone& cp);

		/*! see ITimeZone::set */
		virtual EnumStatusCode set(const ITimeZone* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ITimeZone& pSrc);

		/* see ITimeZone::compare */
		virtual int compare(const ITimeZone*) const;
		/*! @overload */
		virtual int compare(const ITimeZone&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ITimeZone& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ITimeZone& other) const;

		/* see ITimeZone::getOffset */
		virtual OTInt16 getOffset() const;
		/* see ITimeZone::setOffset */
		virtual void setOffset(OTInt16 value);

		/* see ITimeZone::getDaylightSavingInOffset */
		virtual bool getDaylightSavingInOffset() const;
		/* see ITimeZone::setDaylightSavingInOffset */
		virtual void setDaylightSavingInOffset(bool value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		TimeZoneStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// TIMEZONE_H
