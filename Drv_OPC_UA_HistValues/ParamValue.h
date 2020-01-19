#pragma once
#include<string>

namespace DrvOPCUAHistValues
{
	enum class ConditionType : int
	{
		CONDTYPE_NONE = -1,
		CONDTYPE_EQUAL = 0,
		CONDTYPE_LESS = 1,
		CONDTYPE_GREATER = 2,
		CONDTYPE_LESSEQUAL = 3,
		CONDTYPE_GREATEREQUAL = 4,
		CONDTYPE_NOTEQUAL = 5,
		CONDTYPE_BETWEEN = 6,
		CONDTYPE_ISNULL = 7,
		CONDTYPE_ISNOTNULL = 8,
		CONDTYPE_LIKE = 9,
		CONDTYPE_TRUE = 10,
		CONDTYPE_FALSE = 11
	};
	
	enum class CombineOperation : int
	{
		COMBINEOP_NONE = -1,
		COMBINEOP_OR = 0,
		COMBINEOP_AND = 1
	};

	struct TagCondition {
		std::string conditionValue;
		ConditionType conditionType;
		CombineOperation conditionOperation;
		TagCondition(const std::string& condVal, ConditionType condType, CombineOperation condOperation);
		TagCondition();
		TagCondition(const TagCondition& src) = default;
		TagCondition(TagCondition&& src) = default;
		TagCondition& operator=(const TagCondition& rhs) = default;
		TagCondition& operator=(TagCondition&& rhs) = default;
	};

	class ParamValue {
	public:
		ParamValue() = delete;
		ParamValue(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint);
		virtual ~ParamValue();
		ParamValue(const ParamValue& src) = default;
		ParamValue(ParamValue&& src) = default;
		ParamValue& operator=(const ParamValue& rhs) = default;
		ParamValue& operator=(ParamValue&& rhs) = default;
		std::string GetAddress() const;
		std::string GetFullAddress() const;
		std::string GetSqc() const;
		bool HasPrevPoint() const;
		bool HasPostPoint() const;
		bool HasSql() const;
		void GetConditionsFromParam(const std::string& sql);
	private:
		std::vector<std::pair<std::string, TagCondition> > m_conditionsList;
		std::string m_Address;
		std::string m_FullAddress;
		std::string m_Sql;
		bool m_bPrevPoint;
		bool m_bPostPoint;
		std::pair<std::string, TagCondition> parseCondition(const std::string& condition, CombineOperation operation);
	};
}