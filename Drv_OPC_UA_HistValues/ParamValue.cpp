#include"pch.h"
#include"ParamValue.h"

DrvOPCUAHistValues::ParamValue::ParamValue(std::string&& address, std::string&& fullAddress, bool prevPoint, bool postPoint) :
	m_Address(address), m_FullAddress(fullAddress), m_bPrevPoint(prevPoint), m_bPostPoint(postPoint)
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

bool DrvOPCUAHistValues::ParamValue::HasPrevPoint() const
{
	return m_bPrevPoint;
}

bool DrvOPCUAHistValues::ParamValue::HasPostPoint() const
{
	return m_bPostPoint;
}
