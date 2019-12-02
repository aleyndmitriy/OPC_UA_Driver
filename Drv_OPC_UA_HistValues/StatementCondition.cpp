#include"pch.h"
#include"StatementCondition.h"

DrvOPCUAHistValues::StatementCondition::StatementCondition(CombineOperation combineOperation, std::string property, PropertyType propertyType, ConditionType conditionType, std::string value1, std::string value2) :
	_combineOperation(combineOperation), _property(property), _propertyType(propertyType), _conditionType(conditionType), _value1(value1), _value2(value2)
{

}

DrvOPCUAHistValues::StatementCondition::StatementCondition() :StatementCondition(CombineOperation::COMBINEOP_OR, std::string(), PropertyType::PROPTYPE_NUMERIC, ConditionType::CONDTYPE_EQUAL, std::string(), std::string())
{

}

DrvOPCUAHistValues::StatementCondition::~StatementCondition()
{
	_property.clear();
	_value1.clear();
	_value2.clear();
}

DrvOPCUAHistValues::CombineOperation DrvOPCUAHistValues::StatementCondition::GetCombineOperation() const
{
	return _combineOperation;
}

std::string DrvOPCUAHistValues::StatementCondition::GetProperty() const
{
	return _property;
}

DrvOPCUAHistValues::ConditionType DrvOPCUAHistValues::StatementCondition::GetConditionType() const
{
	return _conditionType;
}

DrvOPCUAHistValues::PropertyType DrvOPCUAHistValues::StatementCondition::GetPropertyType() const
{
	return _propertyType;
}

std::string DrvOPCUAHistValues::StatementCondition::GetValue1() const
{
	return _value1;
}

std::string DrvOPCUAHistValues::StatementCondition::GetValue2() const
{
	return _value2;
}


std::string DrvOPCUAHistValues::StatementCondition::PropertyView() const
{
	std::string type;
	switch (_propertyType)
	{
	case PropertyType::PROPTYPE_NUMERIC:
		type = std::string(" (NUMERIC)");
		break;
	case PropertyType::PROPTYPE_TEXT:
		type = std::string(" (TEXT)");
		break;
	case PropertyType::PROPTYPE_BOOLEAN:
		type = std::string(" (BOOLEAN)");
		break;
	case PropertyType::PROPTYPE_DATE:
		type = std::string(" (DATE)");
		break;
	default:
		type = std::string(" (NONE)");
		break;
	}
	std::string res = _property + type;
	return res;
}

std::string DrvOPCUAHistValues::StatementCondition::ConditionView() const
{
	std::string type;
	switch (_conditionType)
	{
	case ConditionType::CONDTYPE_EQUAL:
		type = std::string("EQUAL TO");
		break;
	case ConditionType::CONDTYPE_LESS:
		type = std::string("LESS THAN");
		break;
	case ConditionType::CONDTYPE_GREATER:
		type = std::string("GREATER THAN");
		break;
	case ConditionType::CONDTYPE_LESSEQUAL:
		type = std::string("LESS OR EQUAL");
		break;
	case ConditionType::CONDTYPE_GREATEREQUAL:
		type = std::string("GREATER OR EQUAL");
		break;
	case ConditionType::CONDTYPE_NOTEQUAL:
		type = std::string("NOT EQUAL");
		break;
	case ConditionType::CONDTYPE_BETWEEN:
		type = std::string("BETWEEN");
		break;
	case ConditionType::CONDTYPE_ISNULL:
		type = std::string("IS NULL");
		break;
	case ConditionType::CONDTYPE_ISNOTNULL:
		type = std::string("IS NOT NULL");
		break;
	case ConditionType::CONDTYPE_LIKE:
		type = std::string("LIKE");
		break;
	case ConditionType::CONDTYPE_TRUE:
		type = std::string("TRUE");
		break;
	case ConditionType::CONDTYPE_FALSE:
		type = std::string("FALSE");
		break;
	default:
		type = std::string("(NONE)");
		break;
	}
	return type;
}


void DrvOPCUAHistValues::StatementCondition::SetCombineOperation(CombineOperation operation)
{
	_combineOperation = operation;
}

void DrvOPCUAHistValues::StatementCondition::SetConditionType(ConditionType conditionType)
{
	_conditionType = conditionType;
}

void DrvOPCUAHistValues::StatementCondition::SetProperty(std::string property)
{
	_property = property;
}

void DrvOPCUAHistValues::StatementCondition::SetPropertyType(PropertyType propertyType)
{
	_propertyType = propertyType;
}

void DrvOPCUAHistValues::StatementCondition::SetValue1(std::string value1)
{
	_value1 = value1;
}

void DrvOPCUAHistValues::StatementCondition::SetValue2(std::string value2)
{
	_value2 = value2;
}


bool DrvOPCUAHistValues::operator==(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() == rhs.GetProperty();
}

bool DrvOPCUAHistValues::operator!=(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() != rhs.GetProperty();
}

bool DrvOPCUAHistValues::operator<(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() < rhs.GetProperty();
}

bool DrvOPCUAHistValues::operator<=(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() <= rhs.GetProperty();
}

bool DrvOPCUAHistValues::operator>(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() > rhs.GetProperty();
}

bool DrvOPCUAHistValues::operator>=(const DrvOPCUAHistValues::StatementCondition& lhs, const DrvOPCUAHistValues::StatementCondition& rhs)
{
	return lhs.GetProperty() >= rhs.GetProperty();
}

std::string DrvOPCUAHistValues::PropertyTypeToStr(PropertyType type)
{
	std::string strType;
	switch (type)
	{
	case PropertyType::PROPTYPE_NUMERIC:
		strType = std::string(" (NUMERIC)");
		break;
	case PropertyType::PROPTYPE_TEXT:
		strType = std::string(" (TEXT)");
		break;
	case PropertyType::PROPTYPE_BOOLEAN:
		strType = std::string(" (BOOLEAN)");
		break;
	case PropertyType::PROPTYPE_DATE:
		strType = std::string(" (DATE)");
		break;
	default:
		strType = std::string(" (NONE)");
		break;
	}
	return strType;
}

DrvOPCUAHistValues::PropertyType DrvOPCUAHistValues::IntToPropertyType(int type)
{
	PropertyType res;
	switch (type)
	{
	case 0:
		res = PropertyType::PROPTYPE_NUMERIC;
		break;
	case 1:
		res = PropertyType::PROPTYPE_TEXT;
		break;
	case 2:
		res = PropertyType::PROPTYPE_BOOLEAN;
		break;
	case 3:
		res = PropertyType::PROPTYPE_DATE;
		break;
	default:
		res = PropertyType::PROPTYPE_NONE;
		break;
	}
	return res;
}

DrvOPCUAHistValues::ConditionType DrvOPCUAHistValues::IntToConditionType(int type)
{
	ConditionType res;
	switch (type)
	{
	case 0:
		res = ConditionType::CONDTYPE_EQUAL;
		break;
	case 1:
		res = ConditionType::CONDTYPE_LESS;
		break;
	case 2:
		res = ConditionType::CONDTYPE_GREATER;
		break;
	case 3:
		res = ConditionType::CONDTYPE_LESSEQUAL;
		break;
	case 4:
		res = ConditionType::CONDTYPE_GREATEREQUAL;
		break;
	case 5:
		res = ConditionType::CONDTYPE_NOTEQUAL;
		break;
	case 6:
		res = ConditionType::CONDTYPE_BETWEEN;
		break;
	case 7:
		res = ConditionType::CONDTYPE_ISNULL;
		break;
	case 8:
		res = ConditionType::CONDTYPE_ISNOTNULL;
		break;
	case 9:
		res = ConditionType::CONDTYPE_LIKE;
		break;
	case 10:
		res = ConditionType::CONDTYPE_TRUE;
		break;
	case 11:
		res = ConditionType::CONDTYPE_FALSE;
		break;
	default:
		res = ConditionType::CONDTYPE_NONE;
		break;
	}
	return res;
}

DrvOPCUAHistValues::CombineOperation DrvOPCUAHistValues::IntToCombineType(int type)
{
	CombineOperation res = CombineOperation::COMBINEOP_OR;
	if (type > 0) {
		res = CombineOperation::COMBINEOP_AND;
	}
	return res;
}