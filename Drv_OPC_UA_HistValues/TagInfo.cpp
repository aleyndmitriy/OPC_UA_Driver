#include"pch.h"
#include"TagInfo.h"


DrvOPCUAHistValues::TagInfo::TagInfo(const std::string& name, const std::string& desc, int type) : m_strName(name), m_strDescription(desc), m_iType(type)
{

}

DrvOPCUAHistValues::TagInfo::TagInfo() : TagInfo(std::string(), std::string(), ODS::BrowseItem::TYPE_ITEM)
{

}

DrvOPCUAHistValues::TagInfo::~TagInfo()
{
	m_strName.clear();
	m_strDescription.clear();
	m_iType = 0;
}