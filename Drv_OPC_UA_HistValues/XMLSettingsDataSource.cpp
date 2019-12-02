#include"pch.h"
#include "XMLSettingsDataSource.h"
#include "Utils.h"
#include"pugixml.hpp"
#include "Constants.h"

bool DrvOPCUAHistValues::XMLSettingsDataSource::Save(const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Filters");
	for (std::map<std::string, std::vector<StatementCondition> >::const_iterator filterItr = filters.cbegin(); filterItr != filters.cend(); ++filterItr)
	{
		pugi::xml_node alarmNode = rootNode.append_child("AlarmFilter");
		alarmNode.append_attribute("Name").set_value(filterItr->first.c_str());
		for (std::vector<StatementCondition>::const_iterator conditionItr = filterItr->second.cbegin(); conditionItr != filterItr->second.cend(); ++conditionItr) {
			pugi::xml_node conditionNode = alarmNode.append_child("Condition");
			conditionNode.append_attribute("CombineOperation").set_value(static_cast<int>(conditionItr->GetCombineOperation()));
			conditionNode.append_attribute("Property").set_value(conditionItr->GetProperty().c_str());
			conditionNode.append_attribute("PropertyType").set_value(static_cast<int>(conditionItr->GetPropertyType()));
			conditionNode.append_attribute("ConditionType").set_value(static_cast<int>(conditionItr->GetConditionType()));
			if (conditionItr->GetValue1().empty() == false) {
				conditionNode.append_attribute("Value1").set_value(conditionItr->GetValue1().c_str());
			}
			if (conditionItr->GetValue2().empty() == false) {
				conditionNode.append_attribute("Value2").set_value(conditionItr->GetValue2().c_str());
			}
		}
	}
	doc.save(stream);
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::Save(const ConnectionAttributes& attributes, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Settings");
	pugi::xml_node connectionNode = rootNode.append_child("Connection");
	connectionNode.append_attribute("Version").set_value(attributes.driver.c_str());
	connectionNode.append_attribute("Server").set_value(attributes.serverName.c_str());
	connectionNode.append_attribute("AuthenticationType").set_value(attributes.isServerAuthentication);
	connectionNode.append_attribute("ReportType").set_value(attributes.isAlarmReport);
	connectionNode.append_attribute("ConfigDataBase").set_value(attributes.databaseName.c_str());
	connectionNode.append_attribute("User").set_value(attributes.loginName.c_str());
	std::string encryptPass = EncryptPassword(attributes.password);
	connectionNode.append_attribute("Password").set_value(encryptPass.c_str());
	doc.save(stream);
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::Load(std::map<std::string, std::vector<StatementCondition> >& filters, std::istream& stream)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load(stream);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Filters");
	for (pugi::xml_node alarmNode = rootNode.child("AlarmFilter"); alarmNode; alarmNode = alarmNode.next_sibling("AlarmFilter"))
	{
		std::vector<StatementCondition> conditions;
		for (pugi::xml_node conditionNode = alarmNode.child("Condition"); conditionNode; conditionNode = conditionNode.next_sibling("Condition"))
		{
			CombineOperation combine = IntToCombineType(conditionNode.attribute("CombineOperation").as_int());
			PropertyType propertyType = IntToPropertyType(conditionNode.attribute("PropertyType").as_int());
			ConditionType conditionType = IntToConditionType(conditionNode.attribute("ConditionType").as_int());
			conditions.push_back(StatementCondition(combine, std::string(conditionNode.attribute("Property").as_string()), propertyType, conditionType, std::string(conditionNode.attribute("Value1").as_string()), std::string(conditionNode.attribute("Value2").as_string())));
		}
		std::pair<std::string, std::vector<StatementCondition> > mapVal =
			std::make_pair<std::string, std::vector<StatementCondition> >(std::string(alarmNode.attribute("Name").as_string()), std::vector<StatementCondition>(conditions));
		filters.insert(mapVal);
	}
	return true;
}


bool DrvOPCUAHistValues::XMLSettingsDataSource::Load(ConnectionAttributes& attributes, std::istream& stream)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load(stream);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node connectionNode = rootNode.child("Connection");
	attributes.driver = std::string(connectionNode.attribute("Version").as_string());
	attributes.serverName = std::string(connectionNode.attribute("Server").as_string());
	attributes.isServerAuthentication = connectionNode.attribute("AuthenticationType").as_bool();
	attributes.isAlarmReport = connectionNode.attribute("ReportType").as_bool();
	attributes.databaseName = std::string(connectionNode.attribute("ConfigDataBase").as_string());
	attributes.loginName = std::string(connectionNode.attribute("User").as_string());
	std::string pass = std::string(connectionNode.attribute("Password").as_string());
	attributes.password = std::string(DecryptPassword(pass));
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::LoadSettingsString(const char* source, size_t length, ConnectionAttributes& attributes, std::map<std::string, std::vector<StatementCondition> >& filters)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_buffer(source, length);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node connectionNode = rootNode.child("Connection");
	attributes.driver = std::string(connectionNode.attribute("Version").as_string());
	attributes.serverName = std::string(connectionNode.attribute("Server").as_string());
	attributes.isServerAuthentication = connectionNode.attribute("AuthenticationType").as_bool();
	attributes.isAlarmReport = connectionNode.attribute("ReportType").as_bool();
	attributes.databaseName = std::string(connectionNode.attribute("ConfigDataBase").as_string());
	attributes.loginName = std::string(connectionNode.attribute("User").as_string());
	std::string pass = std::string(connectionNode.attribute("Password").as_string());
	attributes.password = std::string(DecryptPassword(pass));

	pugi::xml_node filterNode = doc.child("Filters");
	for (pugi::xml_node alarmNode = filterNode.child("AlarmFilter"); alarmNode; alarmNode = alarmNode.next_sibling("AlarmFilter"))
	{
		std::vector<StatementCondition> conditions;
		for (pugi::xml_node conditionNode = alarmNode.child("Condition"); conditionNode; conditionNode = conditionNode.next_sibling("Condition"))
		{
			CombineOperation combine = IntToCombineType(conditionNode.attribute("CombineOperation").as_int());
			PropertyType propertyType = IntToPropertyType(conditionNode.attribute("PropertyType").as_int());
			ConditionType conditionType = IntToConditionType(conditionNode.attribute("ConditionType").as_int());
			conditions.push_back(StatementCondition(combine, std::string(conditionNode.attribute("Property").as_string()), propertyType, conditionType, std::string(conditionNode.attribute("Value1").as_string()), std::string(conditionNode.attribute("Value2").as_string())));
		}
		std::pair<std::string, std::vector<StatementCondition> > mapVal =
			std::make_pair<std::string, std::vector<StatementCondition> >(std::string(alarmNode.attribute("Name").as_string()), std::vector<StatementCondition>(conditions));
		filters.insert(mapVal);
	}
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::LoadAttributesSettingsString(const char* source, size_t length, ConnectionAttributes& attributes)
{
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_buffer(source, length);
	if (!res) {
		return false;
	}
	pugi::xml_node rootNode = doc.child("Settings");
	pugi::xml_node connectionNode = rootNode.child("Connection");
	attributes.driver = std::string(connectionNode.attribute("Version").as_string());
	attributes.serverName = std::string(connectionNode.attribute("Server").as_string());
	attributes.isServerAuthentication = connectionNode.attribute("AuthenticationType").as_bool();
	attributes.isAlarmReport = connectionNode.attribute("ReportType").as_bool();
	attributes.databaseName = std::string(connectionNode.attribute("ConfigDataBase").as_string());
	attributes.loginName = std::string(connectionNode.attribute("User").as_string());
	std::string pass = std::string(connectionNode.attribute("Password").as_string());
	attributes.password = std::string(DecryptPassword(pass));
	return true;
}

bool DrvOPCUAHistValues::XMLSettingsDataSource::SaveSettingsString(const ConnectionAttributes& attributes, const std::map<std::string, std::vector<StatementCondition> >& filters, std::ostream& stream)
{
	pugi::xml_document doc;
	pugi::xml_node rootNode = doc.append_child("Settings");
	pugi::xml_node connectionNode = rootNode.append_child("Connection");
	connectionNode.append_attribute("Version").set_value(attributes.driver.c_str());
	connectionNode.append_attribute("Server").set_value(attributes.serverName.c_str());
	connectionNode.append_attribute("AuthenticationType").set_value(attributes.isServerAuthentication);
	connectionNode.append_attribute("ReportType").set_value(attributes.isAlarmReport);
	connectionNode.append_attribute("ConfigDataBase").set_value(attributes.databaseName.c_str());
	connectionNode.append_attribute("User").set_value(attributes.loginName.c_str());
	std::string encryptPass = EncryptPassword(attributes.password);
	connectionNode.append_attribute("Password").set_value(encryptPass.c_str());

	rootNode = doc.append_child("Filters");
	for (std::map<std::string, std::vector<StatementCondition> >::const_iterator filterItr = filters.cbegin(); filterItr != filters.cend(); ++filterItr)
	{
		pugi::xml_node alarmNode = rootNode.append_child("AlarmFilter");
		alarmNode.append_attribute("Name").set_value(filterItr->first.c_str());
		for (std::vector<StatementCondition>::const_iterator conditionItr = filterItr->second.cbegin(); conditionItr != filterItr->second.cend(); ++conditionItr) {
			pugi::xml_node conditionNode = alarmNode.append_child("Condition");
			conditionNode.append_attribute("CombineOperation").set_value(static_cast<int>(conditionItr->GetCombineOperation()));
			conditionNode.append_attribute("Property").set_value(conditionItr->GetProperty().c_str());
			conditionNode.append_attribute("PropertyType").set_value(static_cast<int>(conditionItr->GetPropertyType()));
			conditionNode.append_attribute("ConditionType").set_value(static_cast<int>(conditionItr->GetConditionType()));
			if (conditionItr->GetValue1().empty() == false) {
				conditionNode.append_attribute("Value1").set_value(conditionItr->GetValue1().c_str());
			}
			if (conditionItr->GetValue2().empty() == false) {
				conditionNode.append_attribute("Value2").set_value(conditionItr->GetValue2().c_str());
			}
		}
	}
	doc.save(stream);
	return true;
}

std::vector<std::string> DrvOPCUAHistValues::XMLSettingsDataSource::GetFiltersName(const char* source, size_t length)
{
	std::vector<std::string> vec;
	pugi::xml_document doc;
	pugi::xml_parse_result res = doc.load_buffer(source, length);
	if (!res) {
		return vec;
	}
	pugi::xml_node filterNode = doc.child("Filters");
	for (pugi::xml_node alarmNode = filterNode.child("AlarmFilter"); alarmNode; alarmNode = alarmNode.next_sibling("AlarmFilter"))
	{
		vec.push_back(std::string(alarmNode.attribute("Name").as_string()));
	}
	return vec;
}