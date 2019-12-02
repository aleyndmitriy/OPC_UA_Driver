/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief HdaFunction helper class.
*/


#pragma once

#include <vector>
#include "OdsCoreLib.h"


#pragma pack(8)


namespace ODS
{

class HdaFunction;
class HdaFunctionParam;

namespace Core
{
class Uuid;
}

/**
This class is used as helper for HdaFunction
*/
class ODS_CORE_LIB_EXP HdaFunctionHelper
{
public:
	
	HdaFunctionHelper(HdaFunction*);
	~HdaFunctionHelper();

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

	void* GetContext();
	/**<
		@brief Get context that was set before
	*/

	int AddParameter(const HdaFunctionParam& rParam);
	/**<
		@brief Add parameter to the function
	*/

	int GetParameterList(std::vector<HdaFunctionParam*>* pList) const;
	/**<
		@brief Get list of parameters	
	*/

	HdaFunctionParam* FindParamByType(int nParamType);

	int GetParamSessionId(ODS::Core::Uuid* pSessionId) const;

private:

	HdaFunctionHelper(const HdaFunctionHelper& rOther);
	HdaFunctionHelper& operator = (const HdaFunctionHelper& rOther);

	HdaFunction* m_pFunction;
};

}

#pragma pack()