#pragma once
#include"ConnectionAttributes.h"
#include<iostream>

namespace DrvOPCUAHistValues
{
	class ISettingsDataSource {
	public:
		virtual bool Save(const ConnectionAttributes& connectionAttributes, const DataTypeAttributes& dataAttributes, std::ostream& stream) = 0;
		virtual bool Load(ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes, std::istream& stream) = 0;
		virtual bool LoadAttributesString(const char* source, size_t length, ConnectionAttributes& connectionAttributes, DataTypeAttributes& dataAttributes) = 0;
		virtual ~ISettingsDataSource() {};
	};
}