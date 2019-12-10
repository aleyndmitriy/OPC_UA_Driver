/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file  HdaBatchIdInfo.h
	@brief Interface
*/

#pragma once

#include <windows.h>
#include <tchar.h>

#include "OdsCoreLib.h"

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
	used.
*/
class ODS_CORE_LIB_EXP HdaBatchIdInfo
{
	struct HdaBatchIdInfoBody;

public:

	HdaBatchIdInfo();
	~HdaBatchIdInfo();
	HdaBatchIdInfo(const HdaBatchIdInfo& rOther);
	HdaBatchIdInfo& operator = (const HdaBatchIdInfo& rOther);

	int SetId(const TCHAR* szId);

	int GetId(TCHAR** pszId) const;

	int DestroyString(TCHAR* szId) const;

	SYSTEMTIME GetStartTime() const;

	void SetStartTime(const SYSTEMTIME& rTime);

	SYSTEMTIME GetEndTime() const;

	void SetEndTime(const SYSTEMTIME& rTime);
	
private:

	HdaBatchIdInfoBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()