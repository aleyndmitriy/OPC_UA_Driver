#pragma once
#include"SettingsDataSource.h"

namespace DrvOPCUAHistValues {

	class XMLSettingsDataSource : public ISettingsDataSource
	{
	public:
		XMLSettingsDataSource() = default;
		XMLSettingsDataSource(const XMLSettingsDataSource& src) = delete;
		XMLSettingsDataSource(XMLSettingsDataSource&& src) = delete;
		XMLSettingsDataSource& operator=(const XMLSettingsDataSource& rhs) = delete;
		XMLSettingsDataSource& operator=(XMLSettingsDataSource&& rhs) = delete;
		bool Save(const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream) override;
		bool Save(const ConnectionAttributes& attributes, std::ostream& stream) override;
		bool Load(std::map<std::string, std::vector<StatementCondition> >& filters, std::istream& stream) override;
		bool Load(ConnectionAttributes& attributes, std::istream& stream) override;
		bool LoadSettingsString(const char* source, size_t length, ConnectionAttributes& attributes, std::map<std::string, std::vector<StatementCondition> >& filters) override;
		bool LoadAttributesSettingsString(const char* source, size_t length, ConnectionAttributes& attributes) override;
		bool SaveSettingsString(const ConnectionAttributes& attributes, const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream) override;
		std::vector<std::string> GetFiltersName(const char* source, size_t length) override;
		~XMLSettingsDataSource() {};
	};
}