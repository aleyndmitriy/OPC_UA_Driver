#include"pch.h"
#include"Record.h"
#include"Constants.h"
#include<OdsCoreLib/TimeUtils.h>

DrvOPCUAHistValues::Record::Record(const std::any& val, short type, unsigned int status, const SYSTEMTIME& dataTime):
	m_Value(val), m_Type(type), m_Status(status), m_DataTime{ 0 }
{
	m_DataTime.wYear = dataTime.wYear;
	m_DataTime.wMonth = dataTime.wMonth;
	m_DataTime.wDay = dataTime.wDay;
	m_DataTime.wDayOfWeek = dataTime.wDayOfWeek;
	m_DataTime.wHour = dataTime.wHour;
	m_DataTime.wMinute = dataTime.wMinute;
	m_DataTime.wSecond = dataTime.wSecond;
	m_DataTime.wMilliseconds = dataTime.wMilliseconds;
}

DrvOPCUAHistValues::Record::~Record()
{
	m_Value.reset();
}

const void* DrvOPCUAHistValues::Record::GetValue() const
{
	if (!m_Value.has_value()) {
		return nullptr;
	}
	else {
		if (m_Value.type() == typeid(bool)) {
			return std::any_cast<bool>(&m_Value);
		}
		else if (m_Value.type() == typeid(char)) {
			return std::any_cast<char>(&m_Value);
		}
		else if (m_Value.type() == typeid(short)) {
			return std::any_cast<short>(&m_Value);
		}
		else if (m_Value.type() == typeid(int)) {
			return std::any_cast<int>(&m_Value);
		}
		else if (m_Value.type() == typeid(long long)) {
			return std::any_cast<long long>(&m_Value);
		}
		else if (m_Value.type() == typeid(unsigned char)) {
			return std::any_cast<unsigned char>(&m_Value);
		}
		else if (m_Value.type() == typeid(unsigned short)) {
			return std::any_cast<unsigned short>(&m_Value);
		}
		else if (m_Value.type() == typeid(unsigned int)) {
			return std::any_cast<unsigned int>(&m_Value);
		}
		else if (m_Value.type() == typeid(unsigned long long)) {
			return std::any_cast<unsigned long long>(&m_Value);
		}
		else if (m_Value.type() == typeid(double)) {
			return std::any_cast<double>(&m_Value);
		}
		else if (m_Value.type() == typeid(float)) {
			return std::any_cast<float>(&m_Value);
		}
		else if (m_Value.type() == typeid(SYSTEMTIME)) {
			return std::any_cast<SYSTEMTIME>(&m_Value);
		}
		else if (m_Value.type() == typeid(std::string)) {
			return std::any_cast<std::string>(&m_Value);
		}
		else {
			return nullptr;
		}
	}
}

short DrvOPCUAHistValues::Record::GetType() const
{
	return m_Type;
}

unsigned int DrvOPCUAHistValues::Record::GetStatus() const
{
	return m_Status;
}

void DrvOPCUAHistValues::Record::GetDataTime(SYSTEMTIME& dataTime) const
{
	dataTime.wYear = m_DataTime.wYear;
	dataTime.wMonth = m_DataTime.wMonth;
	dataTime.wDay = m_DataTime.wDay;
	dataTime.wDayOfWeek = m_DataTime.wDayOfWeek;
	dataTime.wHour = m_DataTime.wHour;
	dataTime.wMinute = m_DataTime.wMinute;
	dataTime.wSecond = m_DataTime.wSecond;
	dataTime.wMilliseconds = m_DataTime.wMilliseconds;
}

bool DrvOPCUAHistValues::CompareRecordsValueLessMax(const Record& lhs, const Record& rhs)
{
	short lType = lhs.GetType();
	short rType = rhs.GetType();
	const void* lVal = lhs.GetValue();
	const void* rVal = rhs.GetValue();
	switch (lType)
	{
	case EnumNumericNodeId_Null:
		if (rType != EnumNumericNodeId_Null) {
			return true;
		}
		else {
			return false;
		}
		break;
	case EnumNumericNodeId_Boolean:
	{
		const bool* boollVal = static_cast<const bool*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const bool* boolrVal = static_cast<const bool*>(rVal);
			return *boollVal < *boolrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_SByte:
	{
		const char* charlVal = static_cast<const char*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const char* charrVal = static_cast<const char*>(rVal);
			return *charlVal < *charrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Int16:
	{
		const short* shortlVal = static_cast<const short*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const short* shortrVal = static_cast<const short*>(rVal);
			return *shortlVal < *shortrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Int32:
	{
		const int* intlVal = static_cast<const int*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const int* intrVal = static_cast<const int*>(rVal);
			return *intlVal < *intrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Int64:
	{
		const long long* longlVal = static_cast<const long long*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const long long* longrVal = static_cast<const long long*>(rVal);
			return *longlVal < *longrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Byte:
	{
		const unsigned char* charlVal = static_cast<const unsigned char*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned char* charrVal = static_cast<const unsigned char*>(rVal);
			return *charlVal < *charrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_UInt16:
	{
		const unsigned short* shortlVal = static_cast<const unsigned short*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned short* shortrVal = static_cast<const unsigned short*>(rVal);
			return *shortlVal < *shortrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_UInt32:
	{
		const unsigned int* intlVal = static_cast<const unsigned int*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned int* intrVal = static_cast<const unsigned int*>(rVal);
			return *intlVal < *intrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		const unsigned long long* longlVal = static_cast<const unsigned long long*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned long long* longrVal = static_cast<const unsigned long long*>(rVal);
			return *longlVal < *longrVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Double:
	{
		const double* doublelVal = static_cast<const double*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const double* doublerVal = static_cast<const double*>(rVal);
			return *doublelVal < *doublerVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_Float:
	{
		const float* doublelVal = static_cast<const float*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const float* doublerVal = static_cast<const float*>(rVal);
			return *doublelVal < *doublerVal;
		}
		else {
			return false;
		}
	}
	break;
	case EnumNumericNodeId_DateTime:
	{
		const SYSTEMTIME* strlVal = static_cast<const SYSTEMTIME*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const SYSTEMTIME* strrVal = static_cast<const SYSTEMTIME*>(rVal);
			return ODS::TimeUtils::SysTimeCompare(*strlVal, *strrVal) < 0;
		}
		else {
			return false;
		}
	}
	break;
	default:
	{
		const std::string* strlVal = static_cast<const std::string*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const std::string* strrVal = static_cast<const std::string*>(rVal);
			return *strlVal < *strrVal;
		}
		else {
			return false;
		}
	}
	break;
	}
}

bool DrvOPCUAHistValues::CompareRecordsValueLessMin(const Record& lhs, const Record& rhs)
{
	short lType = lhs.GetType();
	short rType = rhs.GetType();
	const void* lVal = lhs.GetValue();
	const void* rVal = rhs.GetValue();
	switch (lType)
	{
	case EnumNumericNodeId_Null:
		if (rType != EnumNumericNodeId_Null) {
			return false;
		}
		else {
			return true;
		}
		break;
	case EnumNumericNodeId_Boolean:
	{
		const bool* boollVal = static_cast<const bool*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const bool* boolrVal = static_cast<const bool*>(rVal);
			return *boollVal < *boolrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_SByte:
	{
		const char* charlVal = static_cast<const char*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const char* charrVal = static_cast<const char*>(rVal);
			return *charlVal < *charrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Int16:
	{
		const short* shortlVal = static_cast<const short*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const short* shortrVal = static_cast<const short*>(rVal);
			return *shortlVal < *shortrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Int32:
	{
		const int* intlVal = static_cast<const int*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const int* intrVal = static_cast<const int*>(rVal);
			return *intlVal < *intrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Int64:
	{
		const long long* longlVal = static_cast<const long long*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const long long* longrVal = static_cast<const long long*>(rVal);
			return *longlVal < *longrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Byte:
	{
		const unsigned char* charlVal = static_cast<const unsigned char*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned char* charrVal = static_cast<const unsigned char*>(rVal);
			return *charlVal < *charrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_UInt16:
	{
		const unsigned short* shortlVal = static_cast<const unsigned short*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned short* shortrVal = static_cast<const unsigned short*>(rVal);
			return *shortlVal < *shortrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_UInt32:
	{
		const unsigned int* intlVal = static_cast<const unsigned int*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned int* intrVal = static_cast<const unsigned int*>(rVal);
			return *intlVal < *intrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		const unsigned long long* longlVal = static_cast<const unsigned long long*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const unsigned long long* longrVal = static_cast<const unsigned long long*>(rVal);
			return *longlVal < *longrVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Double:
	{
		const double* doublelVal = static_cast<const double*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const double* doublerVal = static_cast<const double*>(rVal);
			return *doublelVal < *doublerVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_Float:
	{
		const float* doublelVal = static_cast<const float*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const float* doublerVal = static_cast<const float*>(rVal);
			return *doublelVal < *doublerVal;
		}
		else {
			return true;
		}
	}
	break;
	case EnumNumericNodeId_DateTime:
	{
		const SYSTEMTIME* strlVal = static_cast<const SYSTEMTIME*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const SYSTEMTIME* strrVal = static_cast<const SYSTEMTIME*>(rVal);
			return ODS::TimeUtils::SysTimeCompare(*strlVal, *strrVal) < 0;
		}
		else {
			return true;
		}
	}
	break;
	default:
	{
		const std::string* strlVal = static_cast<const std::string*>(lVal);
		if (rType != EnumNumericNodeId_Null) {
			const std::string* strrVal = static_cast<const std::string*>(rVal);
			return *strlVal < *strrVal;
		}
		else {
			return true;
		}
	}
	break;
	}
}


bool DrvOPCUAHistValues::CompareRecordsDataTimeLessMax(const Record& lhs, const Record& rhs)
{
	short lType = lhs.GetType();
	short rType = rhs.GetType();
	if (lType == EnumNumericNodeId_Null) {
		if (rType != EnumNumericNodeId_Null) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (rType == EnumNumericNodeId_Null) {
			return false;
		}
	}
	SYSTEMTIME timeStampStructLeft;
	lhs.GetDataTime(timeStampStructLeft);
	SYSTEMTIME timeStampStructRight;
	rhs.GetDataTime(timeStampStructRight);
	return ODS::TimeUtils::SysTimeCompare(timeStampStructLeft, timeStampStructRight) < 0;
}

bool DrvOPCUAHistValues::CompareRecordsDataTimeLessMin(const Record& lhs, const Record& rhs)
{
	short lType = lhs.GetType();
	short rType = rhs.GetType();
	if (lType == EnumNumericNodeId_Null) {
		return false;
	}
	else {
		if (rType == EnumNumericNodeId_Null) {
			return true;
		}
	}
	SYSTEMTIME timeStampStructLeft;
	lhs.GetDataTime(timeStampStructLeft);
	SYSTEMTIME timeStampStructRight;
	rhs.GetDataTime(timeStampStructRight);
	return ODS::TimeUtils::SysTimeCompare(timeStampStructLeft, timeStampStructRight) < 0;
}


bool DrvOPCUAHistValues::CompareRecordsDataTime(const Record& lhs, const Record& rhs)
{
	SYSTEMTIME timeStampStructLeft;
	lhs.GetDataTime(timeStampStructLeft);
	SYSTEMTIME timeStampStructRight;
	rhs.GetDataTime(timeStampStructRight);
	return ODS::TimeUtils::SysTimeCompare(timeStampStructLeft, timeStampStructRight) == 0;
}


DrvOPCUAHistValues::Record DrvOPCUAHistValues::RecordsSum(const Record& lhs, const Record& rhs)
{
	short lType = lhs.GetType();
	short rType = rhs.GetType();
	const void* lVal = lhs.GetValue();
	const void* rVal = rhs.GetValue();
	SYSTEMTIME sysTime { 0 };
		switch (rType) {
		case EnumNumericNodeId_SByte:
		{
			const char* charVal = static_cast<const char*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*charVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*charVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*charVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				long long sum = static_cast<long long>(*charVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Int16:
		{
			const short* shortVal = static_cast<const short*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*shortVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				long long sum = static_cast<long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Int32:
		{
			const int* intVal = static_cast<const int*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*intVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*intVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*intVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				long long sum = static_cast<long long>(*intVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Int64:
		{
			const long long* longVal = static_cast<const long long*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += *longVal;
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*longVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*longVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				long long sum = static_cast<long long>(*longVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Byte:
		{
			const unsigned char* charVal = static_cast<const unsigned char*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*charVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*charVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*charVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				unsigned long long sum = static_cast<unsigned long long>(*charVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_UInt16:
		{
			const unsigned short* shortVal = static_cast<const unsigned short*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*shortVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				unsigned long long sum = static_cast<unsigned long long>(*shortVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_UInt32:
		{
			const unsigned int* intVal = static_cast<const unsigned int*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*intVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += static_cast<unsigned long long>(*intVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*intVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				unsigned long long sum = static_cast<unsigned long long>(*intVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_UInt64:
		{
			const unsigned long long* intVal = static_cast<const unsigned long long*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				sum += static_cast<long long>(*intVal);
				return Record(sum, EnumNumericNodeId_Int64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				sum += *intVal;
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				sum += static_cast<double>(*intVal);
				return Record(sum, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				unsigned long long sum = static_cast<unsigned long long>(*intVal);
				return Record(sum, EnumNumericNodeId_UInt64, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Double:
		{
			const double* doubleVal = static_cast<const double*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				double res = *doubleVal + static_cast<double>(sum);
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				double res = *doubleVal + static_cast<double>(sum);
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				double res = *doubleVal + sum;
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				double res = *doubleVal;
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		case EnumNumericNodeId_Float:
		{
			const float* doubleVal = static_cast<const float*>(rVal);
			switch (lType) {
			case EnumNumericNodeId_Int64:
			{
				long long sum = *(static_cast<const long long*>(lVal));
				double res = static_cast<double>(*doubleVal) + static_cast<double>(sum);
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_UInt64:
			{
				unsigned long long sum = *(static_cast<const unsigned long long*>(lVal));
				double res = static_cast<double>(*doubleVal) + static_cast<double>(sum);
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			case EnumNumericNodeId_Double:
			{
				double sum = *(static_cast<const double*>(lVal));
				double res = static_cast<double>(*doubleVal) + sum;
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			default:
			{
				double res = static_cast<double>(*doubleVal);
				return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
			}
			break;
			}
		}
		break;
		default:
			return Record(lhs);
			break;
		}
}

DrvOPCUAHistValues::Record DrvOPCUAHistValues::RecordAvg(const Record& record, unsigned int quantity)
{
	const void* val = record.GetValue();
	SYSTEMTIME sysTime{ 0 };
	double res = 0.0;
	switch (record.GetType())
	{	
	case EnumNumericNodeId_SByte:
	{
		char charVal = *(static_cast<const char*>(val));
		res = static_cast<double>(charVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Int16:
	{
		short shortVal = *(static_cast<const short*>(val));
		res = static_cast<double>(shortVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Int32:
	{
		int intVal = *(static_cast<const int*>(val));
		res = static_cast<double>(intVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Int64:
	{
		long long longVal = *(static_cast<const long long*>(val));
		res = static_cast<double>(longVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Byte:
	{
		unsigned char charVal = *(static_cast<const unsigned char*>(val));
		res = static_cast<double>(charVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_UInt16:
	{
		unsigned short shortVal = *(static_cast<const unsigned short*>(val));
		res = static_cast<double>(shortVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_UInt32:
	{
		unsigned int intVal = *(static_cast<const unsigned int*>(val));
		res = static_cast<double>(intVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_UInt64:
	{
		unsigned long long longVal = *(static_cast<const unsigned long long*>(val));
		res = static_cast<double>(longVal) / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Double:
	{
		double doubleVal = *(static_cast<const double*>(val));
		res = doubleVal / static_cast<double>(quantity);
	}
	break;
	case EnumNumericNodeId_Float:
	{
		float floatVal = *(static_cast<const float*>(val));
		res = static_cast<double>(floatVal) / static_cast<double>(quantity);
	}
	break;
	default:
	{
		return Record(std::any(), EnumNumericNodeId_Null, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
	}
	break;
	}
	return Record(res, EnumNumericNodeId_Double, (unsigned int)EnumStatusCode::EnumStatusCode_Good, sysTime);
}