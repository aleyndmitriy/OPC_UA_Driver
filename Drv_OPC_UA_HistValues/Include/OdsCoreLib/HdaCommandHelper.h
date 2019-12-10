/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HDA Command helper classe.
*/


#pragma once

#include <windows.h>
#include <vector>
#include "OdsCoreLib.h"
#include "OdsString.h"

#pragma pack(8)

namespace ODS
{

class HdaCommand;
class HdaCommandResult;
class HdaFunction;
class HdaFunctionResult;
class HdaCommandParam;

namespace Core
{
class Uuid;
}

/**
This class is used as helper for HdaCommand
*/
class ODS_CORE_LIB_EXP HdaCommandHelper
{
public:
	
	HdaCommandHelper(HdaCommand*);
	~HdaCommandHelper();

	int AddParam(const HdaCommandParam& rParam);
	/**<
		@brief Add parameter to command
	*/

	int GetParamList(std::vector<HdaCommandParam*>* pList) const;
	/**<
		@brief Retrieve list of parameters of command
		
	*/

	int GetFunctionList(std::vector<HdaFunction*>* pList) const;
	/**<
		@brief Retrieve function list
		
	*/
	
	int AddFunction(const HdaFunction& rFunc);
	/**<
		@brief Add function to function list for execution
	*/

	int GetTimePeriod(SYSTEMTIME* pStart, SYSTEMTIME* pEnd, SYSTEMTIME* pCurrTime) const;

	int GetTimePeriodBatchDef(ODS::OdsString* pBatchDef) const;

	int GetSessionId(ODS::Core::Uuid* pSessionId) const;

	ODS::HdaFunction* GetFirstFunction() const;


private:

	HdaCommandHelper(const HdaCommandHelper& rOther);
	HdaCommandHelper& operator = (const HdaCommandHelper& rOther);

	HdaCommand* m_pCommand;
};


class ODS_CORE_LIB_EXP HdaCommandResultHelper
{

public:
	
	HdaCommandResultHelper(HdaCommandResult*);
	~HdaCommandResultHelper();

	int GetHdaFunctionResultList(std::vector<HdaFunctionResult*>* pList) const;
	/**<
		@brief Retrieve list of pointers to HdaFunctionResult objects, allocated inside
		
	*/

	int AddFunctionResult(HdaFunctionResult* pFuncResult);
	/**<
	@brief Add function result to function list for execution
	*/

private:

	HdaCommandResultHelper(const HdaCommandResultHelper& rOther);
	HdaCommandResultHelper& operator = (const HdaCommandResultHelper& rOther);

	HdaCommandResult* m_pResult;
};

}

#pragma pack()