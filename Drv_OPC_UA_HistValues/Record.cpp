#include"pch.h"
#include"Record.h"
#include"Constants.h"
#include<OdsCoreLib/TimeUtils.h>

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

bool DrvOPCUAHistValues::CompareRecordsValueLess(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = nullptr;
	const SYSTEMTIME* timeStampStructRight = nullptr;
	Record::const_iterator itrLhs = lhs.findColumnValue(OPC_UA_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OPC_UA_VALUE);
	if (itrLhs == lhs.cend() || itrRhs == rhs.cend()) {
		return false;
	}
	if (itrLhs->second.first != itrRhs->second.first) {
		return false;
	}
	switch (itrLhs->second.first)
	{
	case EnumNumericNodeId_Null:
		return false;
		break;
	case EnumNumericNodeId_Boolean:
	case EnumNumericNodeId_SByte:
	case EnumNumericNodeId_Int16:
	case EnumNumericNodeId_Int32:
		return std::stoi(itrLhs->second.second) < std::stoi(itrRhs->second.second);
		break;
	case EnumNumericNodeId_Int64:
		return std::stoll(itrLhs->second.second) < std::stoll(itrRhs->second.second);
		break;
	case EnumNumericNodeId_Byte:
	case EnumNumericNodeId_UInt16:
	case EnumNumericNodeId_UInt32:
		return std::stoul(itrLhs->second.second) < std::stoul(itrRhs->second.second);
		break;
	case EnumNumericNodeId_UInt64:
		return std::stoull(itrLhs->second.second) < std::stoull(itrRhs->second.second);
		break;
	case EnumNumericNodeId_Double:
		return std::stod(itrLhs->second.second) < std::stod(itrRhs->second.second);
		break;
	case EnumNumericNodeId_Float:
		return std::stof(itrLhs->second.second) < std::stof(itrRhs->second.second);
		break;
	case EnumNumericNodeId_DateTime:
		timeStampStructLeft = reinterpret_cast<const SYSTEMTIME*>(itrLhs->second.second.c_str());
		timeStampStructRight = reinterpret_cast<const SYSTEMTIME*>(itrRhs->second.second.c_str());
		return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
		break;
	default:
		return itrLhs->second.second < itrRhs->second.second;
		break;
	}
}

const SYSTEMTIME* DrvOPCUAHistValues::GetTimeStampFromRecord(const Record& rec)
{
	Record::const_iterator itr = rec.findColumnValue(OPC_UA_SERVER_TIMESTAMP);
	if (itr == rec.cend()) {
		return nullptr;
	}
	if (itr->second.first != EnumNumericNodeId_DateTime) {
		return nullptr;
	}
	return reinterpret_cast<const SYSTEMTIME*>(itr->second.second.c_str());
}

bool DrvOPCUAHistValues::CompareRecordsDataTimeLess(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = GetTimeStampFromRecord(lhs);
	const SYSTEMTIME* timeStampStructRight = GetTimeStampFromRecord(rhs);
	if (timeStampStructLeft == nullptr || timeStampStructRight == nullptr) {
		return false;
	}
	return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
}

bool DrvOPCUAHistValues::CompareRecordsDataTime(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = GetTimeStampFromRecord(lhs);
	const SYSTEMTIME* timeStampStructRight = GetTimeStampFromRecord(rhs);
	if (timeStampStructLeft == nullptr || timeStampStructRight == nullptr) {
		return false;
	}
	return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) == 0;
}


DrvOPCUAHistValues::Record DrvOPCUAHistValues::RecordsSum(const Record& lhs, const Record& rhs)
{
	DrvOPCUAHistValues::Record record;
	Record::const_iterator itrLhs = lhs.findColumnValue(OPC_UA_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OPC_UA_VALUE);
	if (itrLhs == lhs.cend() || itrLhs->second.first < EnumNumericNodeId_SByte || itrLhs->second.first > EnumNumericNodeId_Double) {
		if (itrRhs != rhs.cend() && itrRhs->second.first > EnumNumericNodeId_Boolean&& itrRhs->second.first < EnumNumericNodeId_String) {
			record.insert(OPC_UA_VALUE, itrRhs->second.first, itrRhs->second.second);
			return record;
		}
		else {
			record.insert(OPC_UA_VALUE, EnumNumericNodeId_Null, std::string());
			return record;
		}
	}
	if (itrRhs == rhs.cend() || itrRhs->second.first < EnumNumericNodeId_SByte || itrRhs->second.first > EnumNumericNodeId_Double) {
		record.insert(OPC_UA_VALUE, itrLhs->second.first, itrLhs->second.second);
		return record;
	}
	switch (itrLhs->second.first)
	{
	case EnumNumericNodeId_SByte:
	case EnumNumericNodeId_Int16:
	case EnumNumericNodeId_Int32:
	{
		int res = std::stoi(itrLhs->second.second) + std::stoi(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case EnumNumericNodeId_Int64:
	{
		long long res = std::stoll(itrLhs->second.second) + std::stoll(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case EnumNumericNodeId_Byte:
	case EnumNumericNodeId_UInt16:
	case EnumNumericNodeId_UInt32:
	{
		unsigned long res = std::stoul(itrLhs->second.second) + std::stoul(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		unsigned long long res = std::stoull(itrLhs->second.second) + std::stoull(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case EnumNumericNodeId_Double:
	{
		double res = std::stod(itrLhs->second.second) + std::stod(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	case EnumNumericNodeId_Float:
	{
		float res = std::stof(itrLhs->second.second) + std::stof(itrRhs->second.second);
		record.insert(OPC_UA_VALUE, itrLhs->second.first, std::to_string(res));
		return record;
	}
	break;
	default:
		record.insert(OPC_UA_VALUE, EnumNumericNodeId_Null, std::string());
		return record;
		break;
	}
}

DrvOPCUAHistValues::Record DrvOPCUAHistValues::RecordAvg(const Record& record, unsigned int quantity)
{
	DrvOPCUAHistValues::Record avgRecord;
	Record::const_iterator itr = record.findColumnValue(OPC_UA_VALUE);
	if (itr == record.cend()) {
		avgRecord.insert(OPC_UA_VALUE, EnumNumericNodeId_Null, std::string());
		return avgRecord;
	}
	double res = 0.0;
	switch (itr->second.first)
	{
	case EnumNumericNodeId_SByte:
	case EnumNumericNodeId_Int16:
	case EnumNumericNodeId_Int32:
	{
		int val = std::stoi(itr->second.second);
		res = (double)val / (double)quantity;

	}
	break;
	case EnumNumericNodeId_Int64:
	{
		long long val = std::stoll(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case EnumNumericNodeId_Byte:
	case EnumNumericNodeId_UInt16:
	case EnumNumericNodeId_UInt32:
	{
		unsigned long val = std::stoul(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		unsigned long long val = std::stoull(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	case EnumNumericNodeId_Double:
	{
		double val = std::stod(itr->second.second);
		res = val / (double)quantity;
	}
	break;
	case EnumNumericNodeId_Float:
	{
		float val = std::stof(itr->second.second);
		res = (double)val / (double)quantity;
	}
	break;
	default:
		avgRecord.insert(OPC_UA_VALUE, EnumNumericNodeId_Null, std::string());
		return avgRecord;
		break;
	}
	avgRecord.insert(OPC_UA_VALUE, EnumNumericNodeId_Double, std::to_string(res));
	return avgRecord;
}