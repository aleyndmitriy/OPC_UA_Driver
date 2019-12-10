/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file  Tvq.h
	@brief Tvq (timestamp, value quality) interface
*/

#pragma once

#include <windows.h>
#include <oaidl.h>

#include "OdsCoreLib.h"
#include "Value.h"
#include "OdsCoreLib\TimeValue.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	ItemHelper class to simplify work
*/
class ODS_CORE_LIB_EXP Tvq
{

public:

	static const int QUALITY_GOOD = 0;
	static const int QUALITY_BAD = 1;
	static const int QUALITY_UNCERTAIN = 2;

	Tvq();
	Tvq(const ODS::Data::Value& rValue);

	~Tvq();
	Tvq(const Tvq& rOther);
	Tvq& operator = (const Tvq& rOther);

	/**
		@brief Retrieve timestamp of the value in milliseconds since 1970-01-01 00:00:00 UTC
		
		@return Timestamp in milliseconds
	*/
	ULONG64 GetTimestamp() const;

	/**
		@brief Retrieve timestamp of the value in SYSTEMTIME structure, in Local

		@note The timestamp returned is in local time. If Tvq contains
		UTC kind timestamp, it will be converted to local time

		@return void
	*/
	void GetTimestamp(SYSTEMTIME* pTime) const;

	/**
		@brief Retrieve timestamp of the value in SYSTEMTIME structure, in Local

		@note The timestamp returned is in local time. If Tvq contains
		UTC kind timestamp, it will be converted to local time

		@return timestamp
	*/
	SYSTEMTIME GetTimestampLoc() const;

	/**
		@brief Retrieve timestamp of the value in SYSTEMTIME structure, in UTC

		@note The timestamp returned is in UTC time. If Tvq contains
		Local kind timestamp it will be converted to UTC

		@return void

	*/
	void GetTimestampUtc(SYSTEMTIME* pTime) const;

	/**
		@brief Retrieve timestamp of the value in SYSTEMTIME structure, in UTC

		@note The timestamp returned is in UTC time. If Tvq contains
		Local kind timestamp it will be converted to UTC

		@return timestamp

	*/
	SYSTEMTIME GetTimestampUtc() const;

	/**
		@brief Retrieve value type of the item (ItemValue::VALUE_TYPE_NUMBER, etc)

		@return Item value type
	*/
	int GetValueType() const;

	/**
		@brief Return value of the item

		@param[out] ppValue Pointer to variant to be filled with value

		@return Error code
	*/
	int GetValue(VARIANT* pValue) const;


	/**
		@brief Return pointer to value

		@return Error code
	*/
	Data::Value* GetValue() const;
	
	/**
		@brief Return quality of the value

		@return Quality
	*/
	int GetQuality() const;
	
	/**
		@brief Set timestamp in milliseconds since 1970-01-01 00:00:00 UTC

		@param[in] timestamp Number of milliseconds since 1970-01-01 00:00:00 UTC

		@note The timestamp will be Local kind

		@return Error code
	*/
	int SetTimestamp(ULONG64 timestamp);
	
	/**
		@brief Set timestamp in local time

		@return Error code
	*/
	int SetTimestamp(const SYSTEMTIME* pTime);
	
	/**
		@brief Set timestamp in UTC time, timestamp will be UTC kind

		@return Error code
	*/
	int SetTimestampUtc(const SYSTEMTIME& rTimeUtc);
	
	/**
		@brief Set timestamp from VARIANT date, timestamp is local time

		@param[in] pValue Variant date

		@return Error code
	*/
	int SetTimestamp(const VARIANT* pValue);
	
	/**
		@brief Set value for the item. It will clear the previous value
				and set the variant

		@param[in] pValue Pointer to value to be set

		@return VOID
	*/
	void SetValue(const VARIANT* pValue);
	
	/**
		@brief Set value for the item. It will clear the previous value
				and set the variant

		@param[in] rValue Reference to value to be set

		@return VOID
	*/
	void SetValue(const VARIANT& rValue);
	
	/**
		@brief Set value for the item. It will clear the previous value

		@param[in] rValue Reference to value to be set

		@return VOID
	*/
	void SetValue(const ODS::Data::Value& rValue);
	
	/**
		@brief Set value for the item. It will clear the previous value

		@param[in] pValue Reference to value to be set

		@return VOID
	*/
	void SetValue(const ODS::Data::Value* pValue);
	
	/**
		@brief Set quality of the value

		@param[in] nQuality Quality of the value to set

		@return VOID
	*/
	void SetQuality(int nQuality);
	

private:

	ODS::Data::TimeValue m_Ts;
	ODS::Data::Value m_Val;
};

struct TvqListElementDescription
{
	static const ULONG PREV_POINT = 0x00000001;
	static const ULONG POST_POINT = 0x00000002;

	int   m_nIndex;     // index in the list
	ULONG m_ulFlags;    // flags for Tvq
};

} // namespace

/**
	@}
*/

#pragma pack()