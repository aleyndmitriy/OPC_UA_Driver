#include"pch.h"
#include"ParamUtils.h"
#include <HdaFunctionParam.h>
#include <AddressComponent.h>
#include <Address.h>
#include <OdsErr.h>


namespace ParamUtils
{

	void GetAddress(ODS::OdsString& rAddress, ODS::OdsString& rFullAddress, const ODS::HdaFunctionParam* pParam)
	{
		ODS::HdaFunctionParamItemAddress* pIap = (ODS::HdaFunctionParamItemAddress*)pParam;

		ODS::ItemAddress ia;
		pIap->GetItemAddress(&ia);
		ODS::AddressComponent* addrComp = nullptr;
		int nCount = 0;
		int nIndex = 0;
		TCHAR* plainAddress = nullptr;
		ia.GetPlainAddress(&plainAddress);
		if (plainAddress != nullptr) {
			rFullAddress = ODS::OdsString(plainAddress);
		}
		ia.DestroyString(plainAddress);
		std::vector<ODS::AddressComponent> al;
		ia.GetAddress(&addrComp, &nCount, &nIndex);
		for (int index = 0; index < nCount; index++) {
			al.push_back(addrComp[index]);
		}
		ia.DestroyAddress(addrComp, nCount);
		if (al.size() > 0)
		{
			TCHAR* address = nullptr;
			al.at(al.size() - 1).GetValue(&address);
			if (address != nullptr) {
				rAddress = ODS::OdsString(address);
				ia.DestroyString(address);
			}
		}
	}

	void GetAddress(const ODS::OdsString& rPlainAddress, ODS::OdsString& rAddress)
	{
		ODS::ItemAddress ia;
		ia.SetPlainAddress((LPCTSTR)rPlainAddress);
		ODS::AddressComponent* addrComp = nullptr;
		int nCount = 0;
		int nIndex = 0;
		std::vector<ODS::AddressComponent> al;
		ia.GetAddress(&addrComp, &nCount, &nIndex);
		for (int index = 0; index < nCount; index++) {
			al.push_back(addrComp[index]);
		}
		ia.DestroyAddress(addrComp, nCount);

		if (al.size() > 0)
		{
			TCHAR* address = nullptr;
			al.at(al.size() - 1).GetValue(&address);
			if (address != nullptr) {
				rAddress = ODS::OdsString(address);
				ia.DestroyString(address);
			}
		}
	}

	ODS::OdsString GetSql(const ODS::HdaFunctionParam* pParam)
	{
		ODS::HdaFunctionParamSql* pSql = (ODS::HdaFunctionParamSql*)pParam;

		ODS::OdsString text(_T(""));

		TCHAR* szText = 0;
		int rc = pSql->GetText(&szText);
		if (ODS::ERR::OK == rc)
		{
			text = szText;
			pSql->DestroyString(szText);
		}
		return text;
	}
}