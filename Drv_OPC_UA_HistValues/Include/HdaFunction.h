/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HDA Function interface classes.
*/


#pragma once

#include "OdsCoreLib.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class HdaFunctionParam;

/**
This class represents request to be executed in IServerHda.
Function is an element in the function list of the command
*/
class ODS_CORE_LIB_EXP HdaFunction
{
	struct HdaFunctionBody;

public:

	HdaFunction();
	~HdaFunction();
	HdaFunction(const HdaFunction& rOther);
	HdaFunction& operator = (const HdaFunction& rOther);

	int GetType() const;
	/**<
		@brief Retrieve type of the function
	*/

	void SetType(int type);
	/**<
		@brief Set type of the function, see HdaFunctionTypes.h, VALUE_LIST, etc
	*/

	void SetContext(void* pContext);
	/**<
		@brief Set context that will be passed back in result as transparent parameter
	*/

	void* GetContext() const;
	/**<
		@brief Get context that was set before
	*/

	int AddParameter(const HdaFunctionParam& rParam);
	/**<
		@brief Add parameter to the function
	*/

	int GetParameterList(HdaFunctionParam*** pppList, int* pnCount) const;
	/**<
		@brief Get list of parameters, list will be allocated inside
		@note Call DestroyParameterList after 
	*/

	int DestroyParameterList(HdaFunctionParam** ppList, int nCount) const;
	/**<
		@brief Destroy parameter list that was allocated inside
	*/

private:

	HdaFunctionBody* m_pBody;
};

}

/**
	@}
*/

#pragma pack()