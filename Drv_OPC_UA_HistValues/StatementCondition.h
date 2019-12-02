#pragma once
#include<string>

namespace DrvOPCUAHistValues {

	struct PRIORITY_FILTER   // this structure for example purpose
	{
		unsigned short	m_PriorityFrom;
		unsigned short	m_PriorityTo;

		PRIORITY_FILTER()
		{
			m_PriorityFrom = 0;
			m_PriorityTo = 0;
		}
	};

	enum class PropertyType : int
	{
		PROPTYPE_NONE = -1,
		PROPTYPE_NUMERIC = 0,
		PROPTYPE_TEXT = 1,
		PROPTYPE_BOOLEAN = 2,
		PROPTYPE_DATE = 3
	};

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
		COMBINEOP_OR = 0,
		COMBINEOP_AND = 1
	};

	enum class ColumnTypes
	{
		COLUMNTYPE_NUMERIC = 0,
		COLUMNTYPE_TEXT = 1,
		COLUMNTYPE_BOOLEAN = 2,
		COLUMNTYPE_DATE = 3
	};

	class StatementCondition {
	public:
		StatementCondition();
		StatementCondition(CombineOperation combineOperation, std::string property, PropertyType propertyType, ConditionType conditionType, std::string value1, std::string value2);
		StatementCondition(const StatementCondition& src) = default;
		StatementCondition& operator=(const StatementCondition& src) = default;
		StatementCondition(StatementCondition&& rhs) noexcept = default;
		StatementCondition& operator=(StatementCondition&& rhs) noexcept = default;
		~StatementCondition();
		CombineOperation GetCombineOperation() const;
		ConditionType GetConditionType() const;
		std::string GetProperty() const;
		PropertyType GetPropertyType() const;
		std::string GetValue1() const;
		std::string GetValue2() const;
		std::string PropertyView() const;
		std::string ConditionView() const;
		void SetCombineOperation(CombineOperation operation);
		void SetConditionType(ConditionType conditionType);
		void SetProperty(std::string property);
		void SetPropertyType(PropertyType propertyType);
		void SetValue1(std::string value1);
		void SetValue2(std::string value2);
	private:
		CombineOperation _combineOperation;
		std::string _property;
		PropertyType _propertyType;
		ConditionType _conditionType;
		std::string _value1;
		std::string _value2;
	};

	bool operator==(const StatementCondition& lhs, const StatementCondition& rhs);
	bool operator!=(const StatementCondition& lhs, const StatementCondition& rhs);
	bool operator<(const StatementCondition& lhs, const StatementCondition& rhs);
	bool operator<=(const StatementCondition& lhs, const StatementCondition& rhs);
	bool operator>(const StatementCondition& lhs, const StatementCondition& rhs);
	bool operator>=(const StatementCondition& lhs, const StatementCondition& rhs);

	std::string PropertyTypeToStr(PropertyType type);
	PropertyType IntToPropertyType(int type);
	ConditionType IntToConditionType(int type);
	CombineOperation IntToCombineType(int type);
}
