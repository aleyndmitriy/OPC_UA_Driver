#include"pch.h"
#include"ParamValue.h"

DrvOPCUAHistValues::ParamValue::ParamValue(std::string&& address, std::string&& fullAddress, std::string&& sql, bool prevPoint, bool postPoint) :
	m_Address(address), m_FullAddress(fullAddress), m_Sql(sql), m_bPrevPoint(prevPoint), m_bPostPoint(postPoint)
{

}

DrvOPCUAHistValues::ParamValue::~ParamValue() {

}

std::string DrvOPCUAHistValues::ParamValue::GetAddress() const
{
	return m_Address;
}

std::string DrvOPCUAHistValues::ParamValue::GetFullAddress() const
{
	return m_FullAddress;
}

std::string DrvOPCUAHistValues::ParamValue::GetSqc() const
{
	return m_Sql;
}

bool DrvOPCUAHistValues::ParamValue::HasPrevPoint() const
{
	return m_bPrevPoint;
}

bool DrvOPCUAHistValues::ParamValue::HasPostPoint() const
{
	return m_bPostPoint;
}

bool DrvOPCUAHistValues::ParamValue::HasSql() const
{
	return !m_Sql.empty();
}

void DrvOPCUAHistValues::ParamValue::GetConditionsFromParam(const std::string& sql)
{
	std::vector<std::pair<std::string, CombineOperation> > res;
	size_t posBegin = sql.find("[i#", 0);
	if (posBegin == std::string::npos) {
		return;
	}
	size_t posPrevBegin = 0;
	size_t posOrBegin = sql.find(" OR ", 0);
	if (posOrBegin == std::string::npos) {
		posOrBegin = sql.find(" or ", 0);
	}
	size_t posAndBegin = sql.find(" AND ", 0);
	if (posAndBegin == std::string::npos) {
		posAndBegin = sql.find(" and ", 0);
	}
	while (posAndBegin != std::string::npos || posOrBegin != std::string::npos) {
		if (posAndBegin > posOrBegin) {
			res.push_back(std::make_pair<std::string, CombineOperation>(sql.substr(posPrevBegin, posOrBegin - posPrevBegin), CombineOperation::COMBINEOP_OR));
			posPrevBegin = posOrBegin + 4;
		}
		else {
			res.push_back(std::make_pair<std::string, CombineOperation>(sql.substr(posPrevBegin, posAndBegin - posPrevBegin), CombineOperation::COMBINEOP_AND));
			posPrevBegin = posAndBegin + 5;
		}
		posOrBegin = sql.find(" OR ", posPrevBegin);
		if (posOrBegin == std::string::npos) {
			posOrBegin = sql.find(" or ", posPrevBegin);
		}
		posAndBegin = sql.find("AND", posPrevBegin);
		if (posAndBegin == std::string::npos) {
			posAndBegin = sql.find(" and ", posPrevBegin);
		}
	}
	res.push_back(std::make_pair<std::string, CombineOperation>(sql.substr(posPrevBegin, std::string::npos), CombineOperation::COMBINEOP_NONE));
}