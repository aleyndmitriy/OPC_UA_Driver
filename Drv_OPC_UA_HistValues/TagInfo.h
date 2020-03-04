#pragma once
#include<string>
#include<BrowseItem.h>

namespace DrvOPCUAHistValues {

	struct TagInfo
	{
		std::string m_strName;
		std::string m_strDescription;
		int m_iType;
		TagInfo() = delete;
		TagInfo(const std::string& name, const std::string& desc, int type);
		~TagInfo();
		TagInfo(const TagInfo& src) = default;
		TagInfo& operator=(const TagInfo& src) = default;
		TagInfo(TagInfo&& src) = default;
		TagInfo& operator=(TagInfo&& src) = default;
	};

	bool operator < (const DrvOPCUAHistValues::TagInfo& lhs, const DrvOPCUAHistValues::TagInfo& rhs);

	struct HierarchicalTagInfo
	{
		std::vector<std::string> m_strAddress;
		std::string m_strDescription;
		int m_iType;
		HierarchicalTagInfo() = delete;
		HierarchicalTagInfo(const std::vector<std::string>& address, const std::string& desc, int type);
		~HierarchicalTagInfo();
		HierarchicalTagInfo(const HierarchicalTagInfo& src) = default;
		HierarchicalTagInfo& operator=(const HierarchicalTagInfo& src) = default;
		HierarchicalTagInfo(HierarchicalTagInfo&& src) = default;
		HierarchicalTagInfo& operator=(HierarchicalTagInfo&& src) = default;
	};

	bool operator < (const DrvOPCUAHistValues::HierarchicalTagInfo& lhs, const DrvOPCUAHistValues::HierarchicalTagInfo& rhs);
}

