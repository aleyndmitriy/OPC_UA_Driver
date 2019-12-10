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

#ifndef RANGE_H
#define RANGE_H

#include "IRange.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The Range data type defines a range for a value. It is used, for example, to describe the
	* instrument range or engineering unit range of an AnalogItem. */
	class TBC_EXPORT Range
		: public IRange
	{
	public:
		/*! Default constructor */
		Range();
		/*! Constructs a copy of the given instance */
		Range(const IRange*);
		/*! @overload */
		Range(const IRange&);
		/*! @overload */
		Range(const Range&);
		/*! Constructor with initial sets */
		Range(double low, double high);

		/*! Destructor */
		virtual ~Range();

		/*! Assigns the contents of @p cp to this instance */
		Range& operator=(const IRange* cp);
		/*! @overload */
		Range& operator=(const IRange& cp);
		/*! @overload */
		Range& operator=(const Range& cp);

		/* see IRange::set */
		virtual EnumStatusCode set(const IRange* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IRange& pSrc);

		/* see IRange::compare */
		virtual int compare(const IRange*) const;
		/*! @overload */
		virtual int compare(const IRange&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IRange& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IRange& other) const;

		/* see IRange::getLow */
		virtual double getLow() const;
		/* see IRange::setLow */
		virtual void setLow(double value);

		/* see IRange::getHigh */
		virtual double getHigh() const;
		/* see IRange::setHigh */
		virtual void setHigh(double value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		RangeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// RANGE_H
