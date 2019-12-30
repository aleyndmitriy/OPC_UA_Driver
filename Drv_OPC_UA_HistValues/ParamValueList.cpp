#include"pch.h"
#include"ParamValueList.h"

DrvOPCUAHistValues::Limit::Limit(int limitSide, int limitOffset, int limitCount) :m_nLimitSide(limitSide), m_nLimitOffset(limitOffset), m_nLimitCount(limitCount)
{

}

DrvOPCUAHistValues::Limit::Limit() : Limit(0, 0, 0)
{

}

DrvOPCUAHistValues::Limit::~Limit()
{

}

bool DrvOPCUAHistValues::Limit::IsLimit() const
{
	return (m_nLimitOffset != 0 && m_nLimitCount != 0);
}

DrvOPCUAHistValues::ParamValueList::ParamValueList(std::string&& address, std::string&& fullAddress, bool prevPoint, bool postPoint, int valueType, Limit&& limit) :
	ParamValue(std::move(address), std::move(fullAddress), prevPoint, postPoint), m_ValueType(valueType), m_Limit(std::move(limit))
{

}

DrvOPCUAHistValues::ParamValueList::~ParamValueList() {

}

DrvOPCUAHistValues::Limit DrvOPCUAHistValues::ParamValueList::GetLimit() const
{
	return m_Limit;
}

int DrvOPCUAHistValues::ParamValueList::GetValueType() const
{
	return m_ValueType;
}