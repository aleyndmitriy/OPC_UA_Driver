#pragma once
#include<map>
#include<string>
#include"ParamValue.h"
#include <any>
namespace DrvOPCUAHistValues {

	class Record {
	public:
		Record() = delete;
		Record(const std::any& val, short type, unsigned int status, const SYSTEMTIME& dataTime);
		Record(const Record& src) = default;
		Record& operator=(const Record& src) = default;
		Record(Record&& src) noexcept = default;
		const void* GetValue() const;
		short GetType() const;
		unsigned int GetStatus() const;
		void GetDataTime(SYSTEMTIME& dataTime) const;
		~Record();
	private:
		std::any m_Value;
		short m_Type;
		unsigned int m_Status;
		SYSTEMTIME m_DataTime;
	};

	bool CompareRecordsValueLessMax(const Record& lhs, const Record& rhs);
	bool CompareRecordsValueLessMin(const Record& lhs, const Record& rhs);
	bool CompareRecordsDataTimeLessMax(const Record& lhs, const Record& rhs);
	bool CompareRecordsDataTimeLessMin(const Record& lhs, const Record& rhs);
	bool CompareRecordsDataTime(const Record& lhs, const Record& rhs);
	Record RecordsSum(const Record& lhs, const Record& rhs);
	Record RecordAvg(const Record& record, unsigned int quantity);
}