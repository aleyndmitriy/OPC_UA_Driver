#include"pch.h"
#include"TagInfo.h"


DrvOPCUAHistValues::TagInfo::TagInfo(const std::string& name, const std::string& desc, int type) : m_strName(name), m_strDescription(desc), m_iType(type)
{

}

DrvOPCUAHistValues::TagInfo::~TagInfo()
{
	m_strName.clear();
	m_strDescription.clear();
	m_iType = 0;
}



bool DrvOPCUAHistValues::operator < (const DrvOPCUAHistValues::TagInfo& lhs, const DrvOPCUAHistValues::TagInfo& rhs)
{
	return lhs.m_strName < rhs.m_strName;
}

DrvOPCUAHistValues::HierarchicalTagInfo::HierarchicalTagInfo(const std::vector<std::string>& address, const std::string& desc, int type):
	m_strAddress(address), m_strDescription(desc), m_iType(type)
{

}

DrvOPCUAHistValues::HierarchicalTagInfo::~HierarchicalTagInfo()
{
	m_strAddress.clear();
	m_strDescription.clear();
	m_iType = 0;
}