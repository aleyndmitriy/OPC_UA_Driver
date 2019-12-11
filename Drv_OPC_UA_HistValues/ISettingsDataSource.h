#pragma once
#include"ConnectionAttributes.h"
#include<iostream>

namespace DrvOPCUAHistValues
{
	class ISettingsDataSource {
	public:
		virtual bool Save(const ConnectionAttributes& attributes, std::ostream& stream) = 0;
		virtual bool Load(ConnectionAttributes& attributes, std::istream& stream) = 0;
		virtual bool LoadAttributesString(const char* source, size_t length, ConnectionAttributes& attributes) = 0;
		virtual ~ISettingsDataSource() {};
	};
}