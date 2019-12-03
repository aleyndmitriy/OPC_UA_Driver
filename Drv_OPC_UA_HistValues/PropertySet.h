#pragma once
#include <IPropertySet.h>
#include <Property.h>
#include <PropertyInfo.h>
#include <map>

namespace DrvOPCUAHistValues
{
	class CPropertySet final : public ODS::IPropertySet {
	public:
		CPropertySet() = default;
		CPropertySet(const CPropertySet& src) = default;
		CPropertySet(CPropertySet&& src) noexcept = default;
		CPropertySet& operator=(const CPropertySet& src) = default;
		CPropertySet& operator=(CPropertySet&& src) = default;
		virtual ~CPropertySet();
		void GetPropertyInfoList(ODS::PropertyInfo** ppPropInfoList, ULONG* pulCount) const override;
		void DestroyPropertyInfoList(ODS::PropertyInfo* pPropInfoList, ULONG ulCount) const override;
		void GetPropertyList(ODS::Property** ppPropList, ULONG* pulCount) const override;
		void DestroyPropertyList(ODS::Property* pPropList, ULONG ulCount) const override;
		INT GetProperty(ULONG ulPropId, ODS::Property* pProperty) const override;
		INT GetProperty(const TCHAR* pPropName, ODS::Property* pProperty) const override;
		INT SetProperty(const ODS::Property* pProperty) override;
		INT AddProperty(const ULONG ulId, const TCHAR* szName, const TCHAR* szValue);
		INT AddProperty(const ULONG ulId, const TCHAR* szName, const VARIANT* pValue);
	private:
		std::map<ULONG, ODS::Property> propertyList;
	};
}