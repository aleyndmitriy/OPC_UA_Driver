#pragma once
#include"ParamValue.h"

namespace DrvOPCUAHistValues {

	struct Limit
	{
		int m_nLimitSide;   // from which side to take data (START/END)
		int m_nLimitOffset; // how many elements to skip from specified side
							// in case of limit from END the elements are skipped
							// from END to START direction
		int m_nLimitCount;  // how many elements to take, direction is always from START to END
		Limit();
		~Limit();
		Limit(int limitSide, int limitOffset, int limitCount);
		Limit(const Limit& src) = default;
		Limit(Limit&& src) = default;
		Limit& operator=(const Limit& src) = default;
		Limit& operator=(Limit&& src) = default;
		bool IsLimit() const;
	};

	class ParamValueList : public ParamValue {
	public:
		static const int LIMIT_FROM_START = 0;
		static const int LIMIT_FROM_END = 1;
		ParamValueList() = delete;
		ParamValueList(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint, int valueType, Limit&& limit);
		~ParamValueList();
		ParamValueList(const ParamValueList& src) = default;
		ParamValueList(ParamValueList&& src) = default;
		ParamValueList& operator=(const ParamValueList& rhs) = default;
		ParamValueList& operator=(ParamValueList&& rhs) = default;
		Limit GetLimit() const;
		int GetValueType() const;
	private:
		int m_ValueType;
		Limit m_Limit;
	};
}