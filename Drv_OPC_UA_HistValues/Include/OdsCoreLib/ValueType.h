/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Value Types
*/

#pragma once

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

namespace Data
{

namespace ValueType
{
	static const int EMPTY      = 0; /** does not have value */
	static const int STRING     = 2; /** value type is string */
	static const int NUMBER     = 3; /** any numeric value */
	static const int BOOLEAN    = 4; /** value can be only 1 or 0 */
	static const int ARRAY      = 5; /** value is an array of values */
	static const int DATETIME   = 6; /** value type is timestamp */
	static const int TIMEPERIOD = 7; /** value type is time period */
}}}

/**
	@}
*/

#pragma pack()