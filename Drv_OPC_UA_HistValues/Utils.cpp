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

bool getComputerName(std::string& computerName)
{
	TCHAR buffer[256];
	DWORD bufferSize = sizeof(buffer);
	bool result = false;
	computerName = std::string();
	result = (GetComputerName(buffer, &bufferSize) != 0);
	if (result)
	{
		computerName = buffer;
	}
	return result;
}

std::string EncryptPassword(const std::string& password)
{
	return std::string(password);
}

std::string DecryptPassword(const std::string& password)
{
	return std::string(password);
}

bool loadFileIntoByteString(const std::string& fileName, SoftingOPCToolbox5::ByteString& byteString)
{
	HANDLE hFileHandle = CreateFile(fileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	BOOL isRead = false;
	DWORD readSize = 0;
	if (hFileHandle == INVALID_HANDLE_VALUE) {
		return false;
	}
	DWORD dwfileSize = GetFileSize(hFileHandle, NULL);
	if (dwfileSize == INVALID_FILE_SIZE) {
		DWORD error = GetLastError();
		CloseHandle(hFileHandle);
		return false;
	}
	std::unique_ptr<unsigned char[]> chBuffer = std::make_unique<unsigned char[]>(dwfileSize);
	isRead = ReadFile(hFileHandle, chBuffer.get(), dwfileSize, &readSize, NULL);
	if (isRead == FALSE || readSize != dwfileSize) {
		DWORD error = GetLastError();
		CloseHandle(hFileHandle);
		return false;
	}
	CloseHandle(hFileHandle);
	if (StatusCode::isSUCCEEDED(byteString.init(dwfileSize, chBuffer.get())))
	{
		return true;
	}
	else {
		return false;
	}
}