/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HdaFunctionResult helper classes.
*/


#pragma once

#include <vector>

#include "OdsCoreLib.h"
#include "OdsString.h"


#pragma pack(8)


namespace ODS
{

class Tvq;
class HdaFunctionResultValueList;
struct TvqListElementDescription;
class HdaFunctionResultVLC;
class HdaFunctionResultSqlQuery;

class ODS_CORE_LIB_EXP HdaFRVLHelper
{
public:

   HdaFRVLHelper(HdaFunctionResultValueList* pResult);

   ~HdaFRVLHelper();

   void GetTvqDescList(std::vector<TvqListElementDescription>* pList) const;

   void GetTvqList(std::vector<Tvq*>* pList) const;

   void SetTvqDescList(std::vector<TvqListElementDescription>& rList);

   void SetTvqList(std::vector<Tvq*>& rList);

   void SetTvqList(std::vector<Tvq>& rList);

   void SetTvqDescPrevPoint(int nIndex);

private:

   HdaFunctionResultValueList* m_pResult;
};

class ODS_CORE_LIB_EXP HdaFRVLCHelper : public HdaFRVLHelper
{
public:

   HdaFRVLCHelper(HdaFunctionResultVLC* pResult);

   ~HdaFRVLCHelper();

   void GetConditionValueList(std::vector<bool>* pList) const;

   void SetConditionValueList(const std::vector<bool>& rList);

private:

   HdaFunctionResultVLC* m_pResult;
};

class ODS_CORE_LIB_EXP HdaFRSQLHelper
{
public:

	HdaFRSQLHelper(HdaFunctionResultSqlQuery* pResult);
	~HdaFRSQLHelper();

	ODS::OdsString GetMsgExec();

private:

	HdaFunctionResultSqlQuery* m_pResult;
};


} // namespace

#pragma pack()