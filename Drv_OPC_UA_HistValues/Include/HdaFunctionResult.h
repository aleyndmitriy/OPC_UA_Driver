/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HDA Function Result interface classes.
*/


#pragma once

#include <tchar.h>
#include "OdsCoreLib.h"
#include <OdsCoreLib\Uuid.h>

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class Alarm;
class Tvq;
class HdaBatchIdInfo;
class HdaSqlTableData;
struct TvqListElementDescription;

namespace Data
{
class Value;
}

/**
Each HdaFunctionResult is a result of execution of
some HdaFunction.
*/
class ODS_CORE_LIB_EXP HdaFunctionResult
{
public:

	virtual ~HdaFunctionResult();

	virtual void* GetContext() const = 0;
	/**<
		@brief Get Context that was set in the HdaFunction
	*/

	virtual void SetContext(void* pContext) = 0;
	/**<
		@brief Set Context 
	*/

	virtual int GetRc() const = 0;

	virtual void SetRc(int nRc) = 0;
};

/**
This class contain object of any type represented by void*
It can be used for custom results that has to be casted
to some structure or class
*/
class ODS_CORE_LIB_EXP HdaFunctionResultObject : public HdaFunctionResult
{
	struct SHdaFunctionResultObjectBody;

public:

	HdaFunctionResultObject();
	~HdaFunctionResultObject();

	HdaFunctionResultObject(const HdaFunctionResultObject& rOther);
	HdaFunctionResultObject& operator = (const HdaFunctionResultObject& rOther);

	virtual void* GetContext() const;
	/**<
	*/

	virtual void SetContext(void* pContext);
	/**<
	*/

	void SetObjectPtr(void* pObject);
	/**<
	*/

	void* GetObjectPtr() const;
	/**<
	*/

   int GetRc() const;

   void SetRc(int nRc);

private:

	SHdaFunctionResultObjectBody* m_pBody;
};

class ODS_CORE_LIB_EXP HdaFunctionResultValueList : public HdaFunctionResult
{
	struct HdaFunctionResultValueListBody;

public:

	HdaFunctionResultValueList();
	~HdaFunctionResultValueList();

	HdaFunctionResultValueList(const HdaFunctionResultValueList& rOther);
	HdaFunctionResultValueList& operator = (const HdaFunctionResultValueList& rOther);

	virtual void* GetContext() const;
	/**<
	*/

	virtual void SetContext(void* pContext);
	/**<
	*/

	int SetTvqList(Tvq** pList, int nCount);
	/**<
		@brief Set Tvq list into the object
		@param[in] pList Pointer to array of Tvq objects
		@param[in] nCount Number of elements in the array

		@return Error code
	*/

	int GetTvqList(Tvq*** pppList, int* pnCount) const;
	/**<
		@brief Retrieve list of Tvq pointers. Array will be allocated inside
		@note Caller has to call DestroyTvqList after this call

		@param[out] ppList Pointer to pointer that will be filled
						   with pointer to array allocated inside

	    @return Error code
	*/

	static int DestroyTvqList(Tvq** pList);
	/**<
		@brief Destroy Tvq list allocated inside
	*/

	void AddTvqList(ODS::Tvq** pList, int nCount);

	void AddTvq(ODS::Tvq* pTvq);

	int GetTvqListCount() const;

	const ODS::Tvq* GetTvq(int nlIndex) const;

   int SetTvqDescList(TvqListElementDescription* pList, int nCount);
	/**<
		@brief Set Tvq description list into the object
		@param[in] pList Pointer to array of objects
		@param[in] nCount Number of elements in the array

		@return Error code
	*/

	int GetTvqDescList(TvqListElementDescription** ppList, int* pnCount) const;
	/**<
		@brief Retrieve list of Tvq Desc. Array will be allocated inside
		@note Caller has to call DestroyTvqDescList after this call

		@param[out] ppList Pointer to pointer that will be filled
						   with pointer to array allocated inside

	    @return Error code
	*/

	int DestroyTvqDescList(TvqListElementDescription* pList) const;
	/**<
		@brief Destroy Tvq Desc list allocated inside
	*/

	virtual int GetRc() const;

	virtual void SetRc(int nRc);

private:

	HdaFunctionResultValueListBody* m_pBody;
};


class ODS_CORE_LIB_EXP HdaFunctionResultAlarmList : public HdaFunctionResult
{
	struct SHdaFunctionResultAlarmListBody;

public:

	HdaFunctionResultAlarmList();
	~HdaFunctionResultAlarmList();

	HdaFunctionResultAlarmList(const HdaFunctionResultAlarmList& rOther);
	HdaFunctionResultAlarmList& operator = (const HdaFunctionResultAlarmList& rOther);

	virtual void* GetContext() const;
	/**<
	*/

	virtual void SetContext(void* pContext);
	/**<
	*/

	int SetAlarmList(Alarm* pList, int nCount);
	/**<
		@brief Set alarm list into the object
	*/

   int AddAlarm(const Alarm& rAlarm);
	/**<
		@brief Add alarm into the object
      @return Number of alarms after insert
	*/

	int GetAlarmList(Alarm** ppList, int* pnCount) const;
	/**<
		@brief Retrieve list of alarms
	*/

   int GetAlarmCount() const;
	/**<
		@brief Retrieve number of alarms
	*/

	int DestroyAlarmList(Alarm* pList);
	/**<
		@brief
	*/

	int GetTimestampOfFirstAlarm(Data::Value& rVal);
	/**<
		@brief Retrieve timestamp of first alarm
	*/

	int GetTimestampOfLastAlarm(Data::Value& rTs);
	/**<
		@brief Retrieve timestamp of last alarm
	*/


	/**
	 *  @brief Retrieve pointer to Alarm list
	 *  
	 *  @param [out] pCount Pointer to count of elements, will be filled on out
	 *  @return In case the list is empty null pointer will be returned
	 *  
	 *  @details Details
	 */
	const ODS::Alarm* GetAlarmListPtr(size_t* pCount) const;

	int GetRc() const;
	void SetRc(int nRc);

private:

	SHdaFunctionResultAlarmListBody* m_pBody;
};

class ODS_CORE_LIB_EXP HdaFunctionResultBatchIdList : public HdaFunctionResult
{
	struct HdaFunctionResultBatchIdListBody;

public:

	HdaFunctionResultBatchIdList();
	~HdaFunctionResultBatchIdList();

	HdaFunctionResultBatchIdList(const HdaFunctionResultBatchIdList& rOther);
	HdaFunctionResultBatchIdList& operator = (const HdaFunctionResultBatchIdList& rOther);

	virtual void* GetContext() const;
	/**<
	*/

	virtual void SetContext(void* pContext);
	/**<
	*/

	int SetBatchIdList(HdaBatchIdInfo* pList, int nCount);
	/**<
		@brief
	*/

	int GetBatchIdList(HdaBatchIdInfo** ppList, int* pnCount) const;
	/**<
		@brief
	*/

	int DestroyBatchIdList(HdaBatchIdInfo* pList);
	/**<
		@brief
	*/

	int GetRc() const;
	void SetRc(int nRc);

private:

	HdaFunctionResultBatchIdListBody* m_pBody;
};

class ODS_CORE_LIB_EXP HdaFunctionResultSqlQuery : public HdaFunctionResult
{
	struct HdaFunctionResultSqlQueryBody;

public:

	HdaFunctionResultSqlQuery();
	~HdaFunctionResultSqlQuery();

	HdaFunctionResultSqlQuery(const HdaFunctionResultSqlQuery& rOther);
	HdaFunctionResultSqlQuery& operator = (const HdaFunctionResultSqlQuery& rOther);

	virtual void* GetContext() const;
	/**<
	*/

	virtual void SetContext(void* pContext);
	/**<
	*/

	int SetData(HdaSqlTableData* pData);
	/**<
		@brief
	*/

	int GetData(HdaSqlTableData** ppData) const;
	/**<
		@brief
	*/

	void SetMsgExec(const TCHAR* szMsg);

	int GetMsgExec(TCHAR** pszMsg) const;

	int DestroyString(TCHAR* p) const;

	void SetRc(int nRc);
	int GetRc() const;

private:

	HdaFunctionResultSqlQueryBody* m_pBody;
};

class ODS_CORE_LIB_EXP HdaFunctionResultVLC : public HdaFunctionResultValueList
{
	struct HdaFunctionResultVLCBody;

public:

	HdaFunctionResultVLC();
	~HdaFunctionResultVLC();

	HdaFunctionResultVLC(const HdaFunctionResultVLC& rOther);
	HdaFunctionResultVLC& operator = (const HdaFunctionResultVLC& rOther);

	void GetConditionValueList(bool** ppList, int* pnCount) const;

   void DestroyConditionValueList(bool* pList, int nCount) const;

   void SetConditionValueList(bool* pList, int pnCount);

   int GetRc() const;
   void SetRc(int nRc);

private:

	HdaFunctionResultVLCBody* m_pBody;
};

// this result is used to convey result of execution of OPEN_SESSION, CLOSE_SESSION functions
class ODS_CORE_LIB_EXP HdaFunctionResultSession : public HdaFunctionResult
{
	struct HdaFunctionResultSessionBody;

public:

	HdaFunctionResultSession();
	~HdaFunctionResultSession();

	HdaFunctionResultSession(const HdaFunctionResultSession& rOther);
	HdaFunctionResultSession& operator = (const HdaFunctionResultSession& rOther);

	virtual void* GetContext() const;
	virtual void SetContext(void* pContext);

	ODS::Core::Uuid GetSessionId() const;
	void SetSessionId(const ODS::Core::Uuid& rSessionId);

	int GetRc() const;
	void SetRc(int nRc);

private:

	HdaFunctionResultSessionBody* m_pBody;
};

} // namespace

/**
	@}
*/

#pragma pack()