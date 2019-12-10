/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file  HdaCommandParam.h
	@brief HDA Command Parameter interface classes.
*/


#pragma once

#include <windows.h>

#include "OdsCoreLib.h"
#include <OdsCoreLib\Uuid.h>

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

/**
This class represents parameter for HdaCommand
*/
class ODS_CORE_LIB_EXP HdaCommandParam
{
public:

	static const int TYPE_TIME_PERIOD = 0;
	static const int TYPE_SESSION     = 1; // session in which the command has to be executed
	
	virtual ~HdaCommandParam();

	virtual int GetType() const = 0;

	virtual HdaCommandParam* Clone() const = 0;

	static void DestroyClone(HdaCommandParam* pParam);
};

class ODS_CORE_LIB_EXP HdaCommandParamTimePeriod : public HdaCommandParam
{
	struct HdaCommandParamTimePeriodBody;

public:

	HdaCommandParamTimePeriod();
	virtual ~HdaCommandParamTimePeriod();

	HdaCommandParamTimePeriod(const HdaCommandParamTimePeriod& rOther);
	HdaCommandParamTimePeriod& operator = (const HdaCommandParamTimePeriod& rOther);

	virtual int GetType() const;

	virtual HdaCommandParam* Clone() const;

	int SetTimePeriod(const SYSTEMTIME& rStart, const SYSTEMTIME& rEnd, const SYSTEMTIME& rCurrTime);
	/**<
		@brief 
	*/

	int GetTimePeriod(SYSTEMTIME* pStart, SYSTEMTIME* pEnd, SYSTEMTIME* pCurrTime) const;
	/**<
		@brief 
	*/

   void SetBatchDefName(const TCHAR* pName);
   /**<
      @brief Set batch def name if time was resolved from batch based timedef
   */

   int GetBatchDefName(TCHAR** ppName) const;
   /**<
      @brief Get batch def name if time was resolved from batch based timedef
   */

   int DestroyString(TCHAR* pName) const;

private:

	HdaCommandParamTimePeriodBody* m_pBody;
};

class ODS_CORE_LIB_EXP HdaCommandParamSession : public HdaCommandParam
{
	struct HdaCommandParamSessionBody;

public:

	HdaCommandParamSession();
	virtual ~HdaCommandParamSession();

	HdaCommandParamSession(const HdaCommandParamSession& rOther);
	HdaCommandParamSession& operator = (const HdaCommandParamSession& rOther);

	virtual int GetType() const;

	virtual HdaCommandParam* Clone() const;

	ODS::Core::Uuid GetSessionId() const;
	void SetSessionId(const ODS::Core::Uuid& rSessionId);

private:

	HdaCommandParamSessionBody* m_pBody;
};

}// namespace

/**
	@}
*/

#pragma pack()