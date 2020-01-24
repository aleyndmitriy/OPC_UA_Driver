#pragma once
#include<strsafe.h>
#include <string>
#include<vector>
#include <Windows.h>
#include<ByteString.h>
std::string Wstr2Str(const std::wstring& wStr);
std::string FindAndReplace(std::string tInput, std::string tFind, const std::string& tReplace);
std::vector<std::string> split(const std::string& text, const std::string& delimeter);
bool getComputerName(std::string& computerName);
std::string EncryptPassword(const std::string& password);
std::string DecryptPassword(const std::string& password); 
bool loadFileIntoByteString(const std::string& fileName, SoftingOPCToolbox5::ByteString& byteString);