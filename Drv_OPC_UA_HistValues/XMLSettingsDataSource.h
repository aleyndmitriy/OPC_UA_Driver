#pragma once
#include"ISettingsDataSource.h"

namespace DrvOPCUAHistValues
{
	class XMLSettingsDataSource : public ISettingsDataSource
	{
	public:
		XMLSettingsDataSource() = default;
		XMLSettingsDataSource(const XMLSettingsDataSource& src) = delete;
		XMLSettingsDataSource(XMLSettingsDataSource&& src) = delete;
		XMLSettingsDataSource& operator=(const XMLSettingsDataSource& rhs) = delete;
		XMLSettingsDataSource& operator=(XMLSettingsDataSource&& rhs) = delete;
		bool Save(const ConnectionAttributes& attributes, std::ostream& stream) override;
		bool Load(ConnectionAttributes& attributes, std::istream& stream) override;
		bool LoadAttributesString(const char* source, size_t length, ConnectionAttributes& attributes) override;
		~XMLSettingsDataSource() {};
	};
}