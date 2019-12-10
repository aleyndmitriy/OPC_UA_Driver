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

#ifndef NUMERICRANGE_H
#define NUMERICRANGE_H

#include "INumericRange.h"
#include "NumericRangeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The NumericRange data type is used to define a range of elements in
	* an array, a matrix, a ByteString, or a string.
	*
	* A NumericRange is a list of integer pairs <k_1, k_2>
	* whereas k_1 describes the lower and k_2 the higher bound
	* of the range. In order to describe a 2x2 matrix within a 4x4 matrix using
	* a NumericRange one would use the pair list (<0, 1>, <0, 1>) for the
	* upper left 2x2 matrix.
	*
	* @note		The NumericRange data type is actually transmitted as string across the wire.
	*			Therefore, the getParseResult() method must be used to verify that any NumericRange
	*			received by a client has been successfully parsed. */
	class TBC_EXPORT NumericRange
		: public INumericRange
	{
	public:
		/*! Default constructor */
		NumericRange();
		/*! Constructs a copy of the given instance */
		NumericRange(const INumericRange*);
		/*! @overload */
		NumericRange(const INumericRange&);
		/*! @overload */
		NumericRange(const NumericRange&);

		/*! Destructor */
		virtual ~NumericRange();

		/*! Assigns the contents of @p cp to this instance */
		NumericRange& operator=(const INumericRange* cp);
		/*! @overload */
		NumericRange& operator=(const INumericRange& cp);
		/*! @overload */
		NumericRange& operator=(const NumericRange& cp);

		/* see INumericRange::set */
		virtual EnumStatusCode set(const INumericRange*);
		/*! @overload */
		virtual EnumStatusCode set(const INumericRange&);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const INumericRange* other) const;
		/*! @overload */
		virtual int compare(const INumericRange& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INumericRange& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INumericRange& other) const;

		/* see INumericRange::getDimensions */
		virtual OTUInt32 getDimensions() const;

		/* see INumericRange::getRanges */
		virtual std::vector<std::pair<OTUInt32, OTUInt32> > getRanges() const;
		/* see INumericRange::addRange */
		virtual EnumStatusCode addRange(OTUInt32 lowerBound, OTUInt32 upperBound);
		/*! @overload */
		virtual EnumStatusCode addRange(const std::pair<OTUInt32, OTUInt32>& range);

		/* see INumericRange::reserve */
		virtual void reserve(OTUInt32 n);

		/* see INumericRange::parse */
		EnumStatusCode parse(const tstring& numericRangeString);

		/* see INumericRange::toString */
		tstring toString() const;

		/*! For internal use only */
		void* getInternHandle() const;

	private:
		NumericRangeStruct m_content;
	}; // end INumericRange
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// NUMERICRANGE_H
