#pragma once
#include <OdsString.h>


namespace ODS
{
	class HdaFunctionParam;
}


namespace ParamUtils
{

	void GetAddress(ODS::OdsString& rAddress, ODS::OdsString& rFullAddress, const ODS::HdaFunctionParam* pParam);

	void GetAddress(const ODS::OdsString& rPlainAddress, ODS::OdsString& rAddress);

	ODS::OdsString GetSql(const ODS::HdaFunctionParam* pParam);

}