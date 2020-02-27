/*
Copyright (c) Ocean Data Systems Ltd.
All rights reserved

USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
@file
@brief
*/

#pragma once

#include <windows.h>
#include "OdsCoreLib.h"

#pragma pack(8)

namespace ODS
{

namespace Data
{

class ODS_CORE_LIB_EXP TimeValue // 8 bytes
{
public:

	void Init();

	USHORT Year() const;  
	BYTE Month() const; // 1 - January
	BYTE Day() const;
	BYTE Hour() const;
	BYTE Minute() const;
	BYTE Second() const;
	USHORT Milli() const;

	void SetYear(USHORT year);
	void SetMonth(BYTE month);
	void SetDay(BYTE day);
	void SetHour(BYTE hour);
	void SetMinute(BYTE minute);
	void SetSecond(BYTE second);
	void SetMilli(USHORT milli);

	bool KindUtc() const;
	bool KindLocal() const;
	void SetKindUtc();
	void SetKindLocal();

	int GetDst() const;
	void SetDst(int nDst); // -1 not set, 1 - dst is in effect, 0 dst is not active

	static SYSTEMTIME ToSystemTime(const ODS::Data::TimeValue& rT);
	static ODS::Data::TimeValue ToTimeValue(const SYSTEMTIME& rSt, int nDST = -1);

	static ODS::Data::TimeValue Create(USHORT y, BYTE m, BYTE d, BYTE h, BYTE min, BYTE sec, USHORT milli, int nDST = -1);
	static ODS::Data::TimeValue CreateEmpty();

	SYSTEMTIME ToSystemTime() const;
	void FromSystemTime(const SYSTEMTIME& rSt, int nDST = -1);

private:

	USHORT m_Year;   // 2017

	struct MF // month and flags
	{
		unsigned char m_Month    : 4; // 1 - 12
		unsigned char m_UTC      : 1;
		unsigned char m_DstSet   : 1;
		unsigned char m_DST      : 1;
		unsigned char m_Reserve1 : 1;
	};

	MF     m_MF;
	BYTE   m_Day;    // 1 - 31
	BYTE   m_Hour;   // 0 - 24
	BYTE   m_Minute; // 0 - 59
	USHORT m_Milli;  // 0 - 59999, 59 seconds 999 milliseconds
};


}}  // namespace

#pragma pack()