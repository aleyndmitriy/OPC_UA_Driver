/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Value class 
*/

#pragma once

#include <oaidl.h>

#include "OdsCoreLib.h"
#include "OdsCoreLib/ValueType.h"

#ifdef ODS_VALUE_DETAILS
#include "OdsCoreLib\ValueBody.h"
#endif

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

namespace Data
{
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used. If you build DLL with the same settings as ODS modules you can use
	ValueHelper class to simplify work
*/
class ODS_CORE_LIB_EXP Value
{

public:

	Value();
	~Value();

	Value(const Value& rOther);
	Value(Value&& rOther); // move constructor

	Value& operator = (const Value& rOther);
	Value& operator = (Value&& rOther); // move asignement

	bool operator < (const Value& rOther)  const;
	bool operator == (const Value& rOther) const;

	const Value& operator[](ULONG pos) const;
	Value& operator[](ULONG pos);

	Value(double d);
	Value(ULONG64 ul64Value);
	Value(INT64 n64Value);
	Value(const TCHAR* p);
	Value(const SYSTEMTIME& rSt);
	
	/**
	@brief Retrieve value type of the value, see OdsCoreLib\ValueType.h

	@return value type
	*/
	int GetValueType() const;
	

	bool IsEmpty() const;
	bool IsNumber() const;
	bool IsString() const;
	bool IsDateTime() const;
	bool IsArray() const;

	bool IsUnsignedInt() const;
	bool IsSignedInt() const;
	bool IsDouble() const;

	ULONG GetQualityCode() const;
	void SetQualityCode(ULONG ulCode);
	

	int GetTagCopy(TCHAR** ppOut) const;
	static int DestroyTagCopy(TCHAR* p); // call this method after GetTag to release the memory that was allocated by GetTag

	int SetTag(const TCHAR* pTag);

	int GetArrayCopy(ODS::Data::Value** ppArr, ULONG* pulSize) const; // retrieve array with deep copy of each value
	static int DestroyArray(ODS::Data::Value* pArr, ULONG ulSize); // free all values and free array memory

	int SetArray(const ODS::Data::Value* pArr, ULONG ulSize);

	ULONG GetArraySize() const;

	int GetValue(double* pdValue) const;

	int GetValue(ULONG64* pul64Value) const;

	int GetValue(INT64* pn64Value) const;

	int GetValue(TCHAR** ppValue) const;
	static int DestroyValue(TCHAR* p);

	int GetValue(SYSTEMTIME* pValue) const;

	void SetValue(double dValue);
	void SetValue(ULONG64 ul64Value);
	void SetValue(INT64 n64Value);
	void SetValue(const TCHAR* pValue);
	void SetValue(const SYSTEMTIME& rValue);

private:
	struct Align
	{
		ULONG64 m_1, m_2;
	};

	union Container
	{
		ODS::Data::Value::Align m_A; // special member for correct alignment
		unsigned char m_B[16];

#ifdef ODS_VALUE_DETAILS
		ODS::Data::ValueContainer m_Details;
#endif
	};

	Container m_Container;
};

}}

/**
	@}
*/

#pragma pack()