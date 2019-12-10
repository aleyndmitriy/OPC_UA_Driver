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

#ifndef ITIMEZONE_H
#define ITIMEZONE_H

#include "TimeZoneStruct.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The TimeZone data type defines the local time that may or may not take
	* daylight saving time into account. */
	class TBC_EXPORT ITimeZone
	{
	public:
		/*! Destructor */
		virtual ~ITimeZone(){};

		/*! Returns the offset in minutes from UTC time */
		virtual OTInt16 getOffset() const = 0;
		/*! Sets the offset in minutes from UTC time */
		virtual void setOffset(OTInt16 offset) = 0;

		/*! Returns true, if the daylight saving time (DST) is in effect
		* and the offset includes the DST correction. */
		virtual bool getDaylightSavingInOffset() const = 0;
		/*! Indicates whether the daylight saving time (DST) is in effect
		* and the offset includes the DST correction. */
		virtual void setDaylightSavingInOffset(bool daylightSavingInOffset) = 0;

		/*! Copies the content of @p pSrc to this instance */
		virtual EnumStatusCode set(const ITimeZone* pSrc) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ITimeZone& pSrc) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ITimeZone* other) const = 0;
		/*! @overload */
		virtual int compare(const ITimeZone& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ITimeZone& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ITimeZone& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ITimeZone
} // end namespace
#endif	// ITIMEZONE_H
