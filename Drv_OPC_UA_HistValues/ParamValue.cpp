#include"pch.h"
#include"ParamValue.h"

DrvOPCUAHistValues::TagCondition::TagCondition(const std::string& name, const std::string& condVal, ConditionType condType, CombineOperation condOperation):
	tagName(name), conditionValue(condVal),conditionType(condType), conditionOperation(condOperation)
{

}

DrvOPCUAHistValues::TagCondition::TagCondition(): TagCondition(std::string(), std::string(), ConditionType::CONDTYPE_NONE, CombineOperation::COMBINEOP_NONE)
{

}


DrvOPCUAHistValues::ParamValue::ParamValue(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint) :
	m_conditionsList(), m_Address(address), m_FullAddress(fullAddress), m_Sql(sql), m_bPrevPoint(prevPoint), m_bPostPoint(postPoint)
{
	createConditionsFromParam();
}

DrvOPCUAHistValues::ParamValue::ParamValue():ParamValue(std::string(),std::string(),std::string(),false,false)
{

}

DrvOPCUAHistValues::ParamValue::~ParamValue() {

}

std::string DrvOPCUAHistValues::ParamValue::GetAddress() const
{
	return m_Address;
}

const std::string& DrvOPCUAHistValues::ParamValue::GetFullAddress() const
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

DrvOPCUAHistValues::TagCondition DrvOPCUAHistValues::ParamValue::parseCondition(const std::string& condition, CombineOperation operation)
{
	std::string res;
	size_t posBegin = condition.find("[i#", 0);
	if (posBegin == std::string::npos) {
		return TagCondition();
	}
	posBegin = condition.find(".", posBegin);
	posBegin += 1;
	size_t posEnd = condition.find_last_of(']', condition.size() - 1);
	if (posEnd == std::string::npos) {
		return TagCondition();
	}
	std::string tagName = condition.substr(posBegin, posEnd - posBegin);
	posEnd += 1;
	size_t operationBegin = condition.find("<=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_LESSEQUAL,operation);
	}
	operationBegin = condition.find(">=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_GREATEREQUAL, operation);
	}
	operationBegin = condition.find("!=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 2;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_NOTEQUAL, operation);
	}
	operationBegin = condition.find("<", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_LESS, operation);
	}
	operationBegin = condition.find(">", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_GREATER, operation);
	}
	operationBegin = condition.find("=", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 1;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_EQUAL, operation);
	}
	operationBegin = condition.find("like", posEnd);
	if (operationBegin != std::string::npos) {
		operationBegin += 4;
		std::string val = condition.substr(operationBegin);
		return TagCondition(tagName, val, ConditionType::CONDTYPE_LIKE, operation);
	}
	operationBegin = condition.find("true", posEnd);
	if (operationBegin != std::string::npos) {
		return TagCondition(tagName, std::string(), ConditionType::CONDTYPE_TRUE, operation);
	}
	operationBegin = condition.find("false", posEnd);
	if (operationBegin != std::string::npos) {
		return TagCondition(tagName, std::string(), ConditionType::CONDTYPE_FALSE, operation);
	}
	operationBegin = condition.find("is not null", posEnd);
	if (operationBegin != std::string::npos) {
		return TagCondition(tagName, std::string(), ConditionType::CONDTYPE_ISNOTNULL, operation);
	}
	operationBegin = condition.find("is null", posEnd);
	if (operationBegin != std::string::npos) {
		return TagCondition(tagName, std::string(), ConditionType::CONDTYPE_ISNULL, operation);
	}
	return TagCondition();
}

bool DrvOPCUAHistValues::ParamValue::IsEmpty() const
{
	return m_FullAddress.empty();
}

std::set<std::string> DrvOPCUAHistValues::ParamValue::GetTagsNames() const
{
	std::set<std::string> names;
	if (!m_FullAddress.empty()) {
		names.insert(m_FullAddress);
	}
	for (std::vector<TagCondition>::const_iterator itr = m_conditionsList.cbegin(); itr != m_conditionsList.cend(); itr++) {
		if (itr->tagName.empty() == false) {
			names.insert(itr->tagName);
		}
	}
	return names;
}

void DrvOPCUAHistValues::ParamValue::createConditionsFromParam()
{
	if (m_Sql.empty() || m_FullAddress.empty()) {
		return;
	}
	size_t posBegin = m_Sql.find("[i#", 0);
	if (posBegin == std::string::npos) {
		return;
	}
	size_t posPrevBegin = 0;
	size_t posOrBegin = m_Sql.find(" OR ", 0);
	if (posOrBegin == std::string::npos) {
		posOrBegin = m_Sql.find(" or ", 0);
	}
	size_t posAndBegin = m_Sql.find(" AND ", 0);
	if (posAndBegin == std::string::npos) {
		posAndBegin = m_Sql.find(" and ", 0);
	}
	while (posAndBegin != std::string::npos || posOrBegin != std::string::npos) {
		if (posAndBegin > posOrBegin) {
			m_conditionsList.push_back(parseCondition(m_Sql.substr(posPrevBegin, posOrBegin - posPrevBegin), CombineOperation::COMBINEOP_OR));
			posPrevBegin = posOrBegin + 4;
		}
		else {
			m_conditionsList.push_back(parseCondition(m_Sql.substr(posPrevBegin, posAndBegin - posPrevBegin), CombineOperation::COMBINEOP_AND));
			posPrevBegin = posAndBegin + 5;
		}
		posOrBegin = m_Sql.find(" OR ", posPrevBegin);
		if (posOrBegin == std::string::npos) {
			posOrBegin = m_Sql.find(" or ", posPrevBegin);
		}
		posAndBegin = m_Sql.find("AND", posPrevBegin);
		if (posAndBegin == std::string::npos) {
			posAndBegin = m_Sql.find(" and ", posPrevBegin);
		}
	}
	m_conditionsList.push_back(parseCondition(m_Sql.substr(posPrevBegin, std::string::npos), CombineOperation::COMBINEOP_NONE));
}

const std::vector<DrvOPCUAHistValues::TagCondition>& DrvOPCUAHistValues::ParamValue::GetConditions() const
{
	return m_conditionsList;
}

bool DrvOPCUAHistValues::ParamValueLess(const ParamValue& val1, const ParamValue& val2)
{
	return val1.GetFullAddress() < val2.GetFullAddress();
}