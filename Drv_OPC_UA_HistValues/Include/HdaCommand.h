/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HDA Command interface classes.
*/


#pragma once

#include "OdsCoreLib.h"


#pragma pack(8)

/**
	@add to group ods_sdk
	@{
*/

namespace ODS
{

class HdaFunction;
class HdaFunctionResult;
class HdaCommandParam;

/**
This class is used to send command to IServerHda.
Command can contain several function to be executed
*/
class ODS_CORE_LIB_EXP HdaCommand
{
	struct HdaCommandBody;

public:
	
	HdaCommand();
	~HdaCommand();

	HdaCommand(const HdaCommand& rOther);
	HdaCommand& operator = (const HdaCommand& rOther);

   void SetContext(void* pContext);
   /**<
		@brief Set some context into the command that will be returned in HdaCommandResult
		@param[in] pContext
		@return void
	*/

   void* GetContext() const;
   /**<
		@brief Get context that was set into the command
		@return Context
	*/

	int AddParam(const HdaCommandParam& rParam);
	/**<
		@brief Add parameter to command
		@param[in] rParam Reference to parameter to be added. Parameter will be clonned
		                  and new object will be saved inside the command object

		@return Error code
	*/

	int GetParamList(HdaCommandParam*** pppList, int* pnCount) const;
	/**<
		@brief Retrieve list of parameters of command
		@note List will be allocated inside, call DestroyParamList() after usage

		@param[out] pppList List to be allocated inside and returned, note that it will return
		                    pointers to objects inside the command, do not use them after command deletion
		@param[out] pnCount Pointer to fill with number of parameters in the list

	*/

	int DestroyParamList(HdaCommandParam** ppList, int nCount);
	/**<
		@brief Destroy list of parameters that was allocated inside

		@param[in] ppList Pointer to list that was allocated
		@param[in] nCount Number of elements

		@return Error code
	*/
	
	int AddFunction(const HdaFunction& rFunc);
	/**<
		@brief Add function to function list for execution
		@param[in] rFunc Reference to function to be added. Function will be clonned
		                  and new object will be saved inside the command object

		@return Error code
	*/

	int GetFunctionList(HdaFunction*** pppList, int* pnCount) const;
	/**<
		@brief Retrieve function list
		@note List will be allocated inside

		@param[out] pppList List to be allocated inside and returned, note that it will return
		                    pointers to objects inside the command, do not use them after command deletion

		@param[out] pnCount Pointer to fill with number of functions in the list
	*/

	int DestroyFunctionList(HdaFunction** ppList, int nCount);
	/**<
		@brief Destroy allocated inside function list

		@param[in] ppList Pointer to list that was allocated
		@param[in] nCount Number of elements

		@return Error code
	*/
	
private:
	HdaCommandBody* m_pBody;
};


class ODS_CORE_LIB_EXP HdaCommandResult
{
	struct HdaCommandResultBody;

public:
	
	HdaCommandResult();
	~HdaCommandResult();

	HdaCommandResult(const HdaCommandResult& rOther);
	HdaCommandResult& operator = (const HdaCommandResult& rOther);

   void SetContext(void* pContext);
	/**<
		@brief Set context that was set into the command
		@param[in] pContext
		@return void
	*/

	void* GetContext() const;
	/**<
		@brief Get context
		@return Context
	*/

	int GetHdaFunctionResultList(HdaFunctionResult*** pppList, int* pnCount) const;
	/**<
		@brief Retrieve list of pointers to HdaFunctionResult objects, allocated inside
		@note Call DestroyHdaFunctionResultList() when the list is not needed anymore

		@param[out] pppList List to be allocated inside and returned, note that it will return
		                    pointers to objects inside the result, do not use them after result deletion

		@param[out] pnCount Pointer to fill with number of functions in the list
	*/

	int DestroyHdaFunctionResultList(HdaFunctionResult** ppList, int nCount);
	/**<
		@brief Destroy allocated inside list

		@param[in] ppList Pointer to list that was allocated
		@param[in] nCount Number of elements

		@return Error code
	*/

	int AddFunctionResult(HdaFunctionResult* pFuncResult);
	/**<
		@brief Add function result to result
		@param[in] rFunc Pointer to result to be added. Result will keep pointer to this object
		                 to avoid copying of huge data sets. Object will be deleted during result deletion

		@return Error code
	*/

private:
	HdaCommandResultBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()