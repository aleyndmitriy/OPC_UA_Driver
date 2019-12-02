#include"pch.h"
#include"Utils.h"
#include<memory>

std::string Wstr2Str(const std::wstring& wStr)
{
	size_t wStrSz = wStr.size() + 1;
	std::unique_ptr<char[]> chBuffer = std::make_unique<char[]>(wStrSz);
	WideCharToMultiByte(CP_ACP, 0, wStr.c_str(), wStrSz, chBuffer.get(), (int)wStrSz, NULL, NULL);
	std::string str(chBuffer.get());
	return str;
}

std::string FindAndReplace(std::string tInput, std::string tFind, const std::string& tReplace)
{
	size_t uPos = 0;
	size_t uFindLen = tFind.length();
	size_t uReplaceLen = tReplace.length();
	if (uFindLen == 0)
	{
		return tInput;
	}

	for (; (uPos = tInput.find(tFind, uPos)) != std::string::npos; )
	{
		tInput.replace(uPos, uFindLen, tReplace);
		uPos += uReplaceLen;
	}
	return tInput;
}

std::vector<std::string> split(const std::string& text, const std::string& delimeters)
{
	std::vector<std::string> tokens = std::vector<std::string>{};
	size_t pos = 0;
	size_t prevPos = 0;
	while (pos != std::string::npos) {
		pos = text.find_first_of(delimeters, prevPos);
		if (pos > prevPos) {
			tokens.push_back(text.substr(prevPos, pos - prevPos));
		}
		prevPos = pos + 1;
	}
	return tokens;
}

std::string EncryptPassword(const std::string& password)
{
	return std::string(password);
}

std::string DecryptPassword(const std::string& password)
{
	return std::string(password);
}