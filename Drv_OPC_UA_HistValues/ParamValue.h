#pragma once
#include<string>

namespace DrvOPCUAHistValues
{
	class ParamValue {
	public:
		ParamValue() = delete;
		ParamValue(std::string&& address, std::string&& fullAddress, bool prevPoint, bool postPoint);
		virtual ~ParamValue();
		ParamValue(const ParamValue& src) = default;
		ParamValue(ParamValue&& src) = default;
		ParamValue& operator=(const ParamValue& rhs) = default;
		ParamValue& operator=(ParamValue&& rhs) = default;
		std::string GetAddress() const;
		std::string GetFullAddress() const;
		bool HasPrevPoint() const;
		bool HasPostPoint() const;
	private:
		std::string m_Address;
		std::string m_FullAddress;
		bool m_bPrevPoint;
		bool m_bPostPoint;
	};
}