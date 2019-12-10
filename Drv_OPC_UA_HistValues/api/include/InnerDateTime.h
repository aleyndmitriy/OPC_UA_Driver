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

#ifndef INNERDATETIME_H
#define INNERDATETIME_H

#include "IDateTime.h"
#include "DateTimeStruct.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerDateTime
	class TBC_EXPORT InnerDateTime
		: public IDateTime
	{
	public:
		/*! Destructor */
		virtual ~InnerDateTime();

		// init from otb handle
		void initInner(DateTimeStruct* handle);

		// set from interface
		EnumStatusCode set(const IDateTime* source);
		EnumStatusCode set(const IDateTime& source);

		virtual bool isNull() const;

		virtual EnumStatusCode get(OTUInt64* pTicks) const;
		virtual EnumStatusCode set(OTUInt64 ticks);

		virtual EnumStatusCode getUnixTime(OTUInt64* pUnixTicks) const;
		virtual EnumStatusCode setUnixTime(OTUInt64 unixTicks);

		virtual OTUInt32 getHighDateTime(void) const;
		virtual OTUInt32 getLowDateTime(void) const;

		virtual void setHighDateTime(OTUInt32 highDateTime);
		virtual void setLowDateTime(OTUInt32 lowDateTime);

		virtual OTUInt32 milliSecondGMT() const;
		virtual OTUInt32 milliSecond() const;

		virtual OTUInt16 secondGMT() const;
		virtual OTUInt16 second() const;

		virtual OTUInt16 minuteGMT() const;
		virtual OTUInt16 minute() const;

		virtual OTUInt16 hourGMT() const;
		virtual OTUInt16 hour() const;

		virtual OTUInt16 dayGMT() const;
		virtual OTUInt16 day() const;

		virtual OTUInt16 monthGMT() const;
		virtual OTUInt16 month() const;

		virtual OTUInt32 yearGMT() const;
		virtual OTUInt32 year() const;

		virtual void addMilliseconds(OTUInt64 milliseconds);
		virtual void subtractMilliseconds(OTUInt64 milliseconds);

		virtual void utcNow();

		virtual EnumStatusCode parse(const tstring& dateString);
		virtual tstring toString() const;

		/* see IDateTime::getVersionTime */
		virtual OTUInt32 getVersionTime() const;

		/* see IDateTime::setFromVersionTime */
		virtual void setFromVersionTime(OTUInt32 versionTime);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDateTime* other) const;
		/*! @overload */
		virtual int compare(const IDateTime& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDateTime& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDateTime& other) const;

		/*! For internal use only */
		virtual void* getInternHandle() const;

	protected:
		// the handle to the related core object
		DateTimeStruct* m_otbHandle;
	};
}
#endif	// INNERDATETIME_H
