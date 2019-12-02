#pragma once
#include"StatementCondition.h"
#include"ConnectionAttributes.h"
#include<iostream>
#include<vector>
#include<map>

namespace DrvOPCUAHistValues {

	class ISettingsDataSource {
	public:
		virtual bool Save(const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream) = 0;
		virtual bool Save(const ConnectionAttributes& attributes, std::ostream& stream) = 0;
		virtual bool Load(std::map<std::string, std::vector<StatementCondition> >& filters, std::istream& stream) = 0;
		virtual bool Load(ConnectionAttributes& attributes, std::istream& stream) = 0;
		virtual bool LoadSettingsString(const char* source, size_t length, ConnectionAttributes& attributes, std::map<std::string, std::vector<StatementCondition> >& filters) = 0;
		virtual bool LoadAttributesSettingsString(const char* source, size_t length, ConnectionAttributes& attributes) = 0;
		virtual bool SaveSettingsString(const ConnectionAttributes& attributes, const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream) = 0;
		virtual std::vector<std::string> GetFiltersName(const char* source, size_t length) = 0;
		virtual ~ISettingsDataSource() {};
	};

}