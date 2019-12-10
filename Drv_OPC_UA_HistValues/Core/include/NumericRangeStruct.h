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

#ifndef _NUMERICRANGESTRUCT_H_
#define _NUMERICRANGESTRUCT_H_

#include <vector>

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*! @brief A NumericRange selects a range of elements of
 *        a structure, an array, or a matrix.
 *
 * A NumericRange is a list of integer pairs <k_1, k_2>
 * whereas k_1 describes the lower and k_2 the higher bound
 * of the range. In order to describe a 2x2 matrix within a 4x4 matrix using
 * a NumericRange one would use the pair list (<0, 1>, <0, 1>) for the
 * upper left 2x2 matrix.
 *
 * The OPC Foundation defines the NumericRange type as string adhering to
 * a given BNF. This is also how the NumericRange is transmitted across the wire.
 * Therefore, the string has to be parsed on reception. In order to check whether
 * the received string was parsed correctly, the member @ref parseResult is provided. */
//lint -sem(NumericRangeStruct::clear, cleanup)
//lint -sem(NumericRangeStruct::init, initializer)
//lint -sem(NumericRangeStruct::parse,initializer)
typedef struct TBCORE_IF NumericRangeStruct
{
	OTUInt32 pairCount;
	OTUInt32* pairElement;

	/*!
	 * FOR INTERNAL USE ONLY
	 *
	 * Holds the number of bytes assigned to the @p pairElement member */
	OTUInt32 pairElementCapacity;

	NumericRangeStruct(void);
	NumericRangeStruct(const NumericRangeStruct& cp);

	EnumStatusCode set(const NumericRangeStruct& source);
	EnumStatusCode get(NumericRangeStruct& target) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_String& cp);
	EnumStatusCode get(OpcUa_String& target) const;
#endif

	const NumericRangeStruct& operator=(const NumericRangeStruct& cp);
	bool operator==(const NumericRangeStruct& cp) const;
	bool operator!=(const NumericRangeStruct& cp) const;

	std::pair<OTUInt32, OTUInt32> operator[](size_t index) const;
	std::pair<OTUInt32, OTUInt32> operator[](size_t index);

	int compare(const NumericRangeStruct* with) const;

	/*!
	 * @brief Reserves the given amount of bytes for storing range pairs
	 *
	 * @param n the number of bytes that will be reserved for range pairs */
	void reserve(OTUInt32 n);

	/*! @brief Adds a range pair
	 *
	 * @param lowerBound the lower bound of the range
	 * @param upperBound the upper bound of the range
	 *
	 * Precondition: lowerBound <= upperBound */
	EnumStatusCode addRange(OTUInt32 lowerBound, OTUInt32 upperBound);

	/*! @brief Returns the ranges for all dimensions */
	std::vector<std::pair<OTUInt32, OTUInt32> > getRanges() const;

	/*! Uses a NumericRange and array dimensions to calculate a list of sub ranges within a flat matrix vector.
	*
	* @param pairCount				The amount of range pairs of a NumericRange
	* @param pairElements			The array pair values. The array contains both pair value, thus has the double size of @p pairCount
	* @param arrayDimensionsCount	The number of dimension in the array dimensions
	* @param pArrayDimensions		The array dimensions
	* @param subRanges				The sub ranges to be returned from this method call.
	* @param offset					The start index of the indexes. This argument is optional and mainly used within the recursive call.
	* @param inputSize				The total amount of values to be handled for the current dimension.
	*								This argument is optional and mainly used for the recursive call.
	*								If set to 0, the amount is calculated once from the array dimensions
	*
	* For example the index range "2 , 0:1 , 2:3" in the matrix "3,3,3" will be converted to the ranges ("19:20", "22:23"),
	* that can be copied by appending the sub ranges */
	static EnumStatusCode toFlatSubranges(OTUInt32 pairCount, const OTUInt32* pairElements,
		OTUInt32 arrayDimensionsCount, OTUInt32* pArrayDimensions,
		std::vector<std::pair<OTUInt32, OTUInt32> >& subRanges,
		bool expectRangeMatch, OTUInt32 offset = 0, OTUInt32 inputSize = 0);

	/*! Calculates and allocates the effective array dimensions from this NumericRange and the input array dimensions of an array or a matrix.
	* @note The effective dimensions will match the input array dimensions, except when the ranges match only partially
	*       e.g. IndexRange [3:5,1:9] on Matrix [4,5] will have the effective dimensions [1,4] (matching to the effective IndexRange [3,1:4]) */
	EnumStatusCode getEffectiveDimensions(OTUInt32 arrayDimensionsCount, OTUInt32* pArrayDimensions,
		OTUInt32* pEffectiveDimensionsCount, OTUInt32** ppEffectiveDimensions) const;

	/*! @brief Parses a NumericRange provided as string adhering to the
	 *        BNF specified in OPC UA Spec. Part 4
	 *
	 * @param numericRange the NumericRange to parse */
	EnumStatusCode parse(const std::string& numericRange);
#ifdef _UNICODE
	EnumStatusCode parse(const std::wstring& numericRange);
#endif

	/*! @brief Returns the NumericRange as string adhering to the BNF
	 *        specified in OPC UA Spec. Part 4 */
	tstring toString() const;

	void clear(void);
	~NumericRangeStruct(void);

}NumericRangeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _NUMERICRANGESTRUCT_H_


