/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HDA Function Parameter interface classes.
*/


#pragma once

#include <windows.h>
#include <vector>

#include "OdsCoreLib.h"
#include <tchar.h>
#include <OdsCoreLib\Uuid.h>

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class ItemAddress;
class AlarmFilter;

namespace Core
{
namespace Hda
{
class BatchPeriodDef;
}
}

/**
This class represents parameter for HdaFunction
*/
class ODS_CORE_LIB_EXP HdaFunctionParam
{
public:

	static const int TYPE_ITEM_ADDRESS				= 0;
	static const int TYPE_SPEC_POINT				= 1;
	static const int TYPE_ALARM_FILTER_LIST			= 2;
	static const int TYPE_VALUE_RANGE				= 3;
	static const int TYPE_SQL						= 4;  // This is SQC parameter
	static const int TYPE_DYNAMIC_SQL				= 5;  // not in use
	static const int TYPE_LIMIT						= 6;
	static const int TYPE_BATCH_ID_LIST				= 7;
	static const int TYPE_BATCH_INFO				= 8;
	static const int TYPE_SQL_QUERY					= 9;
	static const int TYPE_OBJECT					= 10;
	static const int TYPE_TIME_PERIOD_LIMIT_RULE	= 11;
	static const int TYPE_SESSION                   = 12; // session info, used in function close_session


	virtual ~HdaFunctionParam() = 0;

	virtual int GetType() const = 0;

	virtual HdaFunctionParam* Clone() const = 0;

	static void DestroyClone(HdaFunctionParam* pParam);
};

/** HdaFunctionParamItemAddress
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamItemAddress : public HdaFunctionParam
{
	struct SHdaFunctionParamItemAddressBody;

public:

	HdaFunctionParamItemAddress();
	virtual ~HdaFunctionParamItemAddress();

	HdaFunctionParamItemAddress(const HdaFunctionParamItemAddress& rOther);
	HdaFunctionParamItemAddress& operator = (const HdaFunctionParamItemAddress& rOther);

	virtual int GetType() const;

	virtual HdaFunctionParam* Clone() const;

	int SetItemAddress(const ItemAddress* pAddress);
	/**<
		@brief 
	*/

	int GetItemAddress(ItemAddress* pAddress) const;
	/**<
		@brief 
	*/

private:

	SHdaFunctionParamItemAddressBody* m_pBody;
};

/** HdaFunctionParamSpecPoint */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamSpecPoint : public HdaFunctionParam
{
	struct SHdaFunctionParamSpecPointBody;

public:

	static const int POINT_TYPE_PREV = 0;
	static const int POINT_TYPE_POST = 1;
	static const int POINT_TYPE_BOTH = 2;

	HdaFunctionParamSpecPoint();
	virtual ~HdaFunctionParamSpecPoint();

	HdaFunctionParamSpecPoint(const HdaFunctionParamSpecPoint& rOther);
	HdaFunctionParamSpecPoint& operator = (const HdaFunctionParamSpecPoint& rOther);

	virtual int GetType() const;
	/**<
		@brief 
	*/

	virtual HdaFunctionParam* Clone() const;

	void SetSpecPointFlag(int nPointType);
	/**<
		@brief 
	*/

	int GetSpecPointFlag() const;
	/**<
		@brief 
	*/

private:

	SHdaFunctionParamSpecPointBody* m_pBody;
};

/** HdaFunctionParamAlarmFilterList */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamAlarmFilterList : public HdaFunctionParam
{
	struct FPAFLBody;

public:

	HdaFunctionParamAlarmFilterList();
	virtual ~HdaFunctionParamAlarmFilterList();

	HdaFunctionParamAlarmFilterList(const HdaFunctionParamAlarmFilterList& rOther);
	HdaFunctionParamAlarmFilterList& operator = (const HdaFunctionParamAlarmFilterList& rOther);

	virtual int GetType() const;

	virtual HdaFunctionParam* Clone() const;

	void SetFilterList(AlarmFilter** ppFilterList, int nCount);
	/**<
	@brief Set Alarm Filter list
   @note This function will clone filter objects and save new objects inside
         Filters can be deleted on client side after call of this method

	@param[in] ppFilterList Array of pointers to filters
	*/

	void GetFilterList(AlarmFilter*** pppFilterList, int* pnCount);
	/**<
	@brief Retrieve Alarm Filter list
	@param[out] rFilterList Filters
	*/

	void DeleteFilterList(AlarmFilter** ppFilterList, int nCount);

private:

	FPAFLBody* m_pBody;
};

/** HdaFunctionParamValueRange */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamValueRange : public HdaFunctionParam
{
	struct HdaFunctionParamValueRangeBody;

public:

	HdaFunctionParamValueRange();
	~HdaFunctionParamValueRange();
	HdaFunctionParamValueRange(const HdaFunctionParamValueRange& rOther);
	HdaFunctionParamValueRange& operator = (const HdaFunctionParamValueRange& rOther);

	virtual int GetType() const;
	/**<
		@brief
	*/

	virtual HdaFunctionParam* Clone() const;

	int GetValueRange(VARIANT* pvFrom, VARIANT* pvTo) const;
	/**<
		@brief
	*/

	int SetValueRange(const VARIANT* pvFrom, const VARIANT* pvTo);
	/**<
		@brief 
	*/

private:

	HdaFunctionParamValueRangeBody* m_pBody;
};

/** HdaFunctionParamSql */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamSql : public HdaFunctionParam
{
	struct HdaFunctionParamSqlBody;

public:

	HdaFunctionParamSql();
	~HdaFunctionParamSql();

	HdaFunctionParamSql(const HdaFunctionParamSql& rOther);
	HdaFunctionParamSql& operator = (const HdaFunctionParamSql& rOther);

	virtual int GetType() const;
	/**<
		@brief 
	*/

	virtual HdaFunctionParam* Clone() const;

	int SetText(const TCHAR* szText, BOOL bIsDynamicSql);
	/**<
		@brief 
	*/

	int GetText(TCHAR** pszText) const;
	/**<
		@brief
	*/

	int DestroyString(TCHAR* szText);
	/**<
		@brief
	*/
private:

	HdaFunctionParamSqlBody* m_pBody;
};


/** HdaFunctionParamLimit */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamLimit : public HdaFunctionParam
{
	struct HdaFunctionParamLimitBody;
public:

	/**
	This structure represents limitation parameters for arrays of data
	*/
	struct LimitParam
	{
		static const int LIMIT_FROM_START = 0;
		static const int LIMIT_FROM_END   = 1;

		int m_nLimitSide;   // from which side to take data (START/END)
		int m_nLimitOffset; // how many elements to skip from specified side
		// in case of limit from END the elements are skipped from END to START direction
		int m_nLimitCount;  // how many elements to take, direction is always from START to END
	};

	HdaFunctionParamLimit();
	~HdaFunctionParamLimit();

	HdaFunctionParamLimit(const HdaFunctionParamLimit& rOther);
	HdaFunctionParamLimit& operator = (const HdaFunctionParamLimit& rOther);

	virtual int GetType() const;

	virtual HdaFunctionParam* Clone() const;

	int SetLimit(const LimitParam* pParam);
	/**<
		@brief 
	*/

	int GetLimit(LimitParam* pParam) const;
	/**<
		@brief
	*/

private:
	HdaFunctionParamLimitBody* m_pBody;
};

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamBatchIdList : public HdaFunctionParam
{
	struct HdaFunctionParamBatchIdListBody;

public:

	HdaFunctionParamBatchIdList();
	~HdaFunctionParamBatchIdList();

	HdaFunctionParamBatchIdList(const HdaFunctionParamBatchIdList& rOther);
	HdaFunctionParamBatchIdList& operator = (const HdaFunctionParamBatchIdList& rOther);

	virtual int GetType() const;
	/**<
		@brief 
	*/

	virtual HdaFunctionParam* Clone() const;
	/**<
		@brief Clone the object
	*/

	int SetTimeRange(const SYSTEMTIME& rStart, const SYSTEMTIME& rEnd);
	/**<
		@brief Set time range for batch id list. It will be requested in specified range

		@param[in] rStart
		@param[in] rEnd

		@return Error code
	*/

	int GetTimeRange(SYSTEMTIME* pStart, SYSTEMTIME* pEnd);
	/**<
		@brief Get time range for batch id list

		@param[out] pStart
		@param[out] pEnd

		@return Error code
	*/

private:

	HdaFunctionParamBatchIdListBody* m_pBody;
};

/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamBatchInfo : public HdaFunctionParam
{
	struct HdaFunctionParamBatchInfoBody;

public:

	HdaFunctionParamBatchInfo();
	~HdaFunctionParamBatchInfo();

	HdaFunctionParamBatchInfo(const HdaFunctionParamBatchInfo& rOther);
	HdaFunctionParamBatchInfo& operator = (const HdaFunctionParamBatchInfo& rOther);

	virtual int GetType() const;
	/**<
		@brief return TYPE_BATCH_INFO
	*/

	virtual HdaFunctionParam* Clone() const;
	/**<
		@brief Clone the object
	*/

	void GetBatchPeriodDef(ODS::Core::Hda::BatchPeriodDef* pPeriod) const;

	void SetBatchPeriodDef(const ODS::Core::Hda::BatchPeriodDef& rPeriod);

private:

	HdaFunctionParamBatchInfoBody* m_pBody;
};

/** HdaFunctionParamSql */
/**
	This class will cross boundaries of DLL that potentialy can be developped
	by third party. This is the reason why in the class plain-old-data types are
	used.
*/
class ODS_CORE_LIB_EXP HdaFunctionParamSqlQuery : public HdaFunctionParam
{
	struct HdaFunctionParamSqlQueryBody;

public:

	HdaFunctionParamSqlQuery();
	~HdaFunctionParamSqlQuery();

	HdaFunctionParamSqlQuery(const HdaFunctionParamSqlQuery& rOther);
	HdaFunctionParamSqlQuery& operator = (const HdaFunctionParamSqlQuery& rOther);

	virtual int GetType() const;
	/**<
		@brief 
	*/

	virtual HdaFunctionParam* Clone() const;

	void SetParams(int nDbProviderType, const TCHAR* szConnStr, const TCHAR* szUser, 
		const TCHAR* szPwd, const TCHAR* szQuery);
	/**<
		@brief 
	*/

	int GetParams(int* pnDbProviderType, TCHAR** pszConnStr, TCHAR** pszUser,
		TCHAR** pszPwd, TCHAR** pszQuery) const;
	/**<
		@brief
	*/

	void DestroyString(TCHAR* szText) const;
	/**<
		@brief
	*/
private:

	HdaFunctionParamSqlQueryBody* m_pBody;
};

/**
This class contain object of any type represented by void*
It can be used for custom params that has to be casted
to some structure or class
*/
class ODS_CORE_LIB_EXP HdaFunctionParamObject : public HdaFunctionParam
{

public:

	HdaFunctionParamObject();
	~HdaFunctionParamObject();

	virtual int GetType() const;
	/**<
		@brief 
	*/

	virtual HdaFunctionParam* Clone() const;

	void SetObjectPtr(void* pObject);
	/**<
	*/

	void* GetObjectPtr() const;
	/**<
	*/

private:

	void* m_pObj;
};

class ODS_CORE_LIB_EXP HdaFunctionParamTimePeriodLimitRule : public HdaFunctionParam
{

public:

	HdaFunctionParamTimePeriodLimitRule();
	virtual ~HdaFunctionParamTimePeriodLimitRule();

	virtual int GetType() const;
	/**<
		@brief Retrieve type of the parameter
		@return Type
	*/

	virtual HdaFunctionParam* Clone() const;

	void SetRule(BOOL bIncludeStart, BOOL bIncludeEnd);
	/**<
		@brief Set rules for time period
		@param[in] bIncludeStart Start time will be included , >= Start
		@param[in] bIncludeEnd End time will be included , <= End
		@return void
	*/

	void GetRule(BOOL* pbIncludeStart, BOOL* pbIncludeEnd) const;
	/**<
		@brief Get rules for time period
		@param[out] pbIncludeStart Include or not
		@param[out] pbIncludeEnd Include or not
		@return void
	*/

private:

	BOOL m_bIncludeStart;
	BOOL m_bIncludeEnd;
};

class ODS_CORE_LIB_EXP HdaFunctionParamSession : public HdaFunctionParam
{
	struct HdaFunctionParamSessionBody;

public:

	HdaFunctionParamSession();
	~HdaFunctionParamSession();

	HdaFunctionParamSession(const HdaFunctionParamSession& rOther);
	HdaFunctionParamSession& operator = (const HdaFunctionParamSession& rOther);

	virtual int GetType() const;
	virtual HdaFunctionParam* Clone() const;

	void SetSessionId(const ODS::Core::Uuid& rSessionId);
	ODS::Core::Uuid GetSessionId() const;

private:

	HdaFunctionParamSessionBody* m_pBody;
};

} // namespace

/**
	@}
*/

#pragma pack()