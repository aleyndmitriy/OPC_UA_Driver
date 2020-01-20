#pragma once
#include<map>
#include<string>

namespace DrvOPCUAHistValues {

	class Record {
	public:
		using FieldData = std::pair<short, std::string>;
		using const_iterator = std::map<std::string, FieldData>::const_iterator;
		Record() = default;
		Record(const Record& src) = default;
		Record& operator=(const Record& src) = default;
		Record(Record&& src) noexcept = default;
		Record& operator=(Record&& src) noexcept = default;
		std::pair<const_iterator, bool> insert(std::string colName, short dataType, std::string value);
		const FieldData& at(const std::string& key) const;
		const_iterator cbegin() const;
		const_iterator cend() const;
		const_iterator findColumnValue(const std::string& key) const;
		size_t GetColumnNumber() const;
		~Record();
		friend bool operator==(const Record& lhs, const Record& rhs);
		friend bool operator!=(const Record& lhs, const Record& rhs);
		friend bool operator<(const Record& lhs, const Record& rhs);
		friend bool operator<=(const Record& lhs, const Record& rhs);
		friend bool operator>(const Record& lhs, const Record& rhs);
		friend bool operator>=(const Record& lhs, const Record& rhs);
	protected:
		std::map<std::string, FieldData> recordData;
	};

	bool operator==(const Record& lhs, const Record& rhs);
	bool operator!=(const Record& lhs, const Record& rhs);
	bool operator<(const Record& lhs, const Record& rhs);
	bool operator<=(const Record& lhs, const Record& rhs);
	bool operator>(const Record& lhs, const Record& rhs);
	bool operator>=(const Record& lhs, const Record& rhs);
	const SYSTEMTIME* GetTimeStampFromRecord(const Record& rec);
	bool CompareRecordsValueLess(const Record& lhs, const Record& rhs);
	bool CompareRecordsDataTimeLess(const Record& lhs, const Record& rhs);
	bool CompareRecordsDataTime(const Record& lhs, const Record& rhs);
	Record RecordsSum(const Record& lhs, const Record& rhs);
	Record RecordAvg(const Record& record, unsigned int quantity);
}