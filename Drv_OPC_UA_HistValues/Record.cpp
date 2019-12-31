#include"pch.h"
#include"Record.h"

std::pair<typename DrvOPCUAHistValues::Record::const_iterator, bool> DrvOPCUAHistValues::Record::insert(std::string colName, short dataType, std::string value)
{
	typename DrvOPCUAHistValues::Record::FieldData val = std::make_pair(dataType, value);
	std::pair<std::string, typename DrvOPCUAHistValues::Record::FieldData> rec = std::make_pair(colName, val);
	return recordData.insert(rec);
}


const typename DrvOPCUAHistValues::Record::FieldData& DrvOPCUAHistValues::Record::at(const std::string& key) const
{
	return recordData.at(key);
}

typename DrvOPCUAHistValues::Record::const_iterator DrvOPCUAHistValues::Record::cbegin() const
{
	return recordData.cbegin();
}

typename DrvOPCUAHistValues::Record::const_iterator DrvOPCUAHistValues::Record::cend() const
{
	return recordData.cend();
}

typename DrvOPCUAHistValues::Record::const_iterator DrvOPCUAHistValues::Record::findColumnValue(const std::string& key) const
{
	return recordData.find(key);
}

size_t DrvOPCUAHistValues::Record::GetColumnNumber() const
{
	return recordData.size();
}

DrvOPCUAHistValues::Record::~Record()
{
	recordData.clear();
}

bool DrvOPCUAHistValues::operator==(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData == rhs.recordData;
}

bool DrvOPCUAHistValues::operator!=(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData != rhs.recordData;
}

bool DrvOPCUAHistValues::operator<(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData < rhs.recordData;
}

bool DrvOPCUAHistValues::operator<=(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData <= rhs.recordData;
}

bool DrvOPCUAHistValues::operator>(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData > rhs.recordData;
}

bool DrvOPCUAHistValues::operator>=(const DrvOPCUAHistValues::Record& lhs, const DrvOPCUAHistValues::Record& rhs)
{
	return lhs.recordData >= rhs.recordData;
}