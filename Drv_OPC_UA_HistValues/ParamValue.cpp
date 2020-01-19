#include"pch.h"
#include"ParamValue.h"

DrvOPCUAHistValues::TagCondition::TagCondition(const std::string& condVal, ConditionType condType, CombineOperation condOperation):
	conditionValue(condVal),conditionType(condType), conditionOperation(condOperation)
{

}

DrvOPCUAHistValues::TagCondition::TagCondition(): TagCondition(std::string(), ConditionType::CONDTYPE_NONE, CombineOperation::COMBINEOP_NONE)
{

}


DrvOPCUAHistValues::ParamValue::ParamValue(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint) :
	m_conditionsList(), m_Address(address), m_FullAddress(fullAddress), m_Sql(sql), m_bPrevPoint(prevPoint), m_bPostPoint(postPoint)
{

}

DrvOPCUAHistValues::ParamValue::~ParamValue() {

}

std::string DrvOPCUAHistValues::ParamValue::GetAddress() const
{
	return m_Address;
}

std::string DrvOPCUAHistValues::ParamValue::GetFullAddress() const
{
	return m_FullAddress;
}

std::string DrvOPCUAHistValues::ParamValue::GetSqc() const
{
	return m_Sql;
}

bool DrvOPCUAHistValues::ParamValue::HasPrevPoint() const
{
	return m_bPrevPoint;
}

bool DrvOPCUAHistValues::ParamValue::HasPostPoint() const
{
	return m_bPostPoint;
}

bool DrvOPCUAHistValues::ParamValue::HasSql() const
{
	return !m_Sql.empty();
}

std::pair<std::string, DrvOPCUAHistValues::TagCondition> DrvOPCUAHistValues::ParamValue::parseCondition(const std::string& condition, CombineOperation operation)
{
	std::string res;
	size_t posBegin = condition.find("[i#", 0);
	if (posBegin == std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(),TagCondition());
	}
	posBegin = condition.find(".", posBegin);
	posBegin += 1;
	size_t posEnd = condition.find_last_of(']', condition.size() - 1);
	if (posEnd == std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(), TagCondition());
	}
	std::string tagName = condition.substr(posBegin, posEnd - posBegin);
	posEnd += 1;
	size_t operationBegin = condition.find("<=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_LESSEQUAL,operation));
	}
	operationBegin = condition.find(">=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_GREATEREQUAL, operation));
	}
	operationBegin = condition.find("!=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_NOTEQUAL, operation));
	}
	operationBegin = condition.find("<", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_LESS, operation));
	}
	operationBegin = condition.find(">", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_GREATER, operation));
	}
	operationBegin = condition.find("=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_EQUAL, operation));
	}
	operationBegin = condition.find("like", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 4;
		std::string val = condition.substr(operationBegin);
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(val, ConditionType::CONDTYPE_LIKE, operation));
	}
	operationBegin = condition.find("true", posEnd);
	if (operationBegin != std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(std::string(), ConditionType::CONDTYPE_TRUE, operation));
	}
	operationBegin = condition.find("false", posEnd);
	if (operationBegin != std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(std::string(), ConditionType::CONDTYPE_FALSE, operation));
	}
	operationBegin = condition.find("is not null", posEnd);
	if (operationBegin != std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(std::string(), ConditionType::CONDTYPE_ISNOTNULL, operation));
	}
	operationBegin = condition.find("is null", posEnd);
	if (operationBegin != std::string::npos) {
		return std::make_pair<std::string, TagCondition>(std::string(tagName), TagCondition(std::string(), ConditionType::CONDTYPE_ISNULL, operation));
	}
	return std::make_pair<std::string, TagCondition>(std::string(), TagCondition());
}

void DrvOPCUAHistValues::ParamValue::GetConditionsFromParam(const std::string& sql)
{
	size_t posBegin = sql.find("[i#", 0);
	if (posBegin == std::string::npos) {
		return;
	}
	size_t posPrevBegin = 0;
	size_t posOrBegin = sql.find(" OR ", 0);
	if (posOrBegin == std::string::npos) {
		posOrBegin = sql.find(" or ", 0);
	}
	size_t posAndBegin = sql.find(" AND ", 0);
	if (posAndBegin == std::string::npos) {
		posAndBegin = sql.find(" and ", 0);
	}
	while (posAndBegin != std::string::npos || posOrBegin != std::string::npos) {
		if (posAndBegin > posOrBegin) {
			m_conditionsList.push_back(parseCondition(sql.substr(posPrevBegin, posOrBegin - posPrevBegin), CombineOperation::COMBINEOP_OR));
			posPrevBegin = posOrBegin + 4;
		}
		else {
			m_conditionsList.push_back(parseCondition(sql.substr(posPrevBegin, posAndBegin - posPrevBegin), CombineOperation::COMBINEOP_AND));
			posPrevBegin = posAndBegin + 5;
		}
		posOrBegin = sql.find(" OR ", posPrevBegin);
		if (posOrBegin == std::string::npos) {
			posOrBegin = sql.find(" or ", posPrevBegin);
		}
		posAndBegin = sql.find("AND", posPrevBegin);
		if (posAndBegin == std::string::npos) {
			posAndBegin = sql.find(" and ", posPrevBegin);
		}
	}
	m_conditionsList.push_back(parseCondition(sql.substr(posPrevBegin, std::string::npos), CombineOperation::COMBINEOP_NONE));
}