#pragma once
#include<string>
#include<BrowseItem.h>

namespace DrvOPCUAHistValues {

	struct TagInfo
	{
		std::string m_strName;
		std::string m_strDescription;
		int m_iType;
		TagInfo();
		TagInfo(const std::string& name, const std::string& desc, int type);
		~TagInfo();
		TagInfo(const TagInfo& src) = default;
		TagInfo& operator=(const TagInfo& src) = default;
		TagInfo(TagInfo&& src) = default;
		TagInfo& operator=(TagInfo&& src) = default;
	};
}