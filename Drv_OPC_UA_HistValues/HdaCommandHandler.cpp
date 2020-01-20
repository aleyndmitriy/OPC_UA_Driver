#include"pch.h"
#include"HdaCommandHandler.h"
#include <HdaFunctionParam.h>
#include <HdaCommandParam.h>
#include<HdaFunction.h>
#include <HdaFunctionResult.h>
#include<HdaFunctionTypes.h>
#include"Constants.h"
#include"Log.h"
#include"ParamUtils.h"
#include<OdsCoreLib/TimeUtils.h>
#include <OdsErr.h>
#include"Utils.h"
#include<numeric>

DrvOPCUAHistValues::HdaCommandHandler::HdaCommandHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore): m_pAttributes(nullptr), m_pSoftingInteractor(softingDataStore), m_connectionsList()
{

}

DrvOPCUAHistValues::HdaCommandHandler::~HdaCommandHandler()
{

}

int DrvOPCUAHistValues::HdaCommandHandler::Init(std::shared_ptr<ConnectionAttributes> attributes)
{
	m_pAttributes = attributes;
	m_pSoftingInteractor->SetAttributes(attributes);
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::HdaCommandHandler::Shut()
{
	m_pSoftingInteractor.reset();
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::HdaCommandHandler::HandleCommand(ODS::HdaCommand* pCommand, ODS::HdaCommandResult* pResult)
{
	m_pSoftingInteractor->SetOutput(shared_from_this());
	std::vector<ODS::HdaFunctionResult*> resultList;
	ODS::HdaFunction** pList = nullptr;
	int nCount = 0;
	int iRes = pCommand->GetFunctionList(&pList, &nCount);
	iRes = ExecuteCommand(pCommand, *pList, nCount, &resultList);
	if (iRes == ODS::ERR::OK) {
		for (std::vector<ODS::HdaFunctionResult*>::const_iterator iterRes = resultList.cbegin(); iterRes != resultList.cend(); iterRes++)
		{
			pResult->AddFunctionResult(*iterRes);
		}
	}
	pCommand->DestroyFunctionList(pList, nCount);
	return iRes;
}


int DrvOPCUAHistValues::HdaCommandHandler::AnalyzeCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* list, int listSize, std::map<int, std::vector<ODS::HdaFunction*> >& requestMap)
{
	requestMap.clear();
	std::vector<ODS::HdaFunction*> funcList;
	for (int i = 0; i < listSize; i++) {
		funcList.push_back(list + i);
	}
	if (funcList.size() <= 0) {
		return ODS::ERR::NOT_SUPPORTED;
	}
	if (ODS::HdaFunctionType::OPEN_SESSION == funcList[0]->GetType() || ODS::HdaFunctionType::CLOSE_SESSION == funcList[0]->GetType()) {
		int nFuncType = funcList[0]->GetType();
		std::pair<int, std::vector<ODS::HdaFunction*> > pair = std::make_pair<int, std::vector<ODS::HdaFunction*> >(std::move(nFuncType), std::vector<ODS::HdaFunction*>());
		std::pair<std::map<int, std::vector<ODS::HdaFunction*> >::iterator, bool > insertedPair = requestMap.insert(pair);
		insertedPair.first->second.push_back(funcList[0]);
		return ODS::ERR::OK;
	}

	for (std::vector<ODS::HdaFunction*>::const_iterator itr = funcList.cbegin(); itr != funcList.cend(); ++itr) {
		int nFuncType = (*itr)->GetType();
		std::pair<int, std::vector<ODS::HdaFunction*> > pair = std::make_pair<int, std::vector<ODS::HdaFunction*> >(std::move(nFuncType), std::vector<ODS::HdaFunction*>());
		std::pair<std::map<int, std::vector<ODS::HdaFunction*> >::iterator, bool > insertedPair = requestMap.insert(pair);
		insertedPair.first->second.push_back(*itr);
	}
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::HdaCommandHandler::HandleOpenSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	ODS::HdaFunctionResultSession* pSession = new ODS::HdaFunctionResultSession;
	pSession->SetContext(pFunc->GetContext());
	ODS::Core::Uuid sessionId;
	std::string uuid = std::string(sessionId.ToString().GetString());
	m_pSoftingInteractor->OpenConnectionWithUUID(uuid);
	std::vector<std::string>::const_iterator findIterator =
		std::find_if(m_connectionsList.cbegin(), m_connectionsList.cend(), [&](const std::string& existingUuid) {
		return existingUuid == uuid; });
	if (findIterator == m_connectionsList.cend()) {
		pSession->SetSessionId(ODS::Core::Uuid::EmptyUuid());
		pSession->SetRc(ODS::ERR::DB_CONNECTION_FAILED);
		Log::GetInstance()->WriteErrorDebug(_T("Connect failed, %s"), (LPCTSTR)sessionId.ToString());
	}
	else {
		pSession->SetSessionId(sessionId);
		pSession->SetRc(ODS::ERR::OK);
		Log::GetInstance()->WriteInfoDebug(_T("OpenSession ok,  session id %s"), (LPCTSTR)sessionId.ToString());
	}
	pResultList->push_back(pSession);

	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::HdaCommandHandler::HandleCloseSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	ODS::HdaFunctionParam** pParam = nullptr;
	int nCount = 0;
	int res = pFunc->GetParameterList(&pParam, &nCount);
	ODS::Core::Uuid sessionId;
	if (pParam != nullptr && nCount > 0) {
		for (int ind = 0; ind < nCount; ind++) {
			if ((*pParam + ind)->GetType() == ODS::HdaFunctionParam::TYPE_SESSION) {
				ODS::HdaFunctionParamSession* ptrParamSession = dynamic_cast<ODS::HdaFunctionParamSession*>(*pParam + ind);
				if (ptrParamSession != nullptr) {
					sessionId = ptrParamSession->GetSessionId();
				}
				break;
			}
		}
	}
	else {
		return ODS::ERR::BAD_PARAM;
	}
	pFunc->DestroyParameterList(pParam, nCount);
	std::string uuid = std::string(sessionId.ToString().GetString());
	std::vector<std::string>::const_iterator findIterator =
		std::find_if(m_connectionsList.cbegin(), m_connectionsList.cend(), [&](const std::string& existingUuid) {
		return existingUuid == uuid; });
	if (findIterator != m_connectionsList.cend()) {
		m_pSoftingInteractor->CloseConnectionWithUUID(uuid);
		Log::GetInstance()->WriteInfoDebug(_T("CloseSession ok,  session id %s"), (LPCTSTR)sessionId.ToString());
		ODS::HdaFunctionResultSession* pSession = new ODS::HdaFunctionResultSession;
		pSession->SetContext(pFunc->GetContext());
		pSession->SetRc(ODS::ERR::OK);
		pResultList->push_back(pSession);
		return ODS::ERR::OK;
	}
	else {
		Log::GetInstance()->WriteInfoDebug(_T("Can't closeSession,  session id %s"), (LPCTSTR)sessionId.ToString());
		return ODS::ERR::DB_CONNECTION_FAILED;
	}
}

int DrvOPCUAHistValues::HdaCommandHandler::ExecuteCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* funcList, int listSize, std::vector<ODS::HdaFunctionResult*>* pResultList)
{
	std::map<int, std::vector<ODS::HdaFunction*> > requestMap;
	int res = AnalyzeCommand(pCommand, funcList, listSize, requestMap);
	if (res == ODS::ERR::OK) {
		std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator itr = requestMap.find(ODS::HdaFunctionType::OPEN_SESSION);
		if (itr != requestMap.cend() && itr->second.size() == 1) {
			return HandleOpenSession(itr->second[0], pResultList);
		}
		itr = requestMap.find(ODS::HdaFunctionType::CLOSE_SESSION);
		if (itr != requestMap.cend() && itr->second.size() == 1) {
			return HandleCloseSession(itr->second[0], pResultList);
		}
		ODS::HdaCommandParam** ppCmdParamList = NULL;
		int nCount = 0;
		int iRes = pCommand->GetParamList(&ppCmdParamList, &nCount);
		ODS::Core::Uuid sessionId = ODS::Core::Uuid::EmptyUuid();
		SYSTEMTIME currTime;
		SYSTEMTIME start;
		SYSTEMTIME end;
		if (iRes == ODS::ERR::OK)
		{
			for (int i = 0; i < nCount; i++)
			{
				if (ppCmdParamList[i]->GetType() == ODS::HdaCommandParam::TYPE_TIME_PERIOD)
				{
					ODS::HdaCommandParamTimePeriod* pTimePeriod = (ODS::HdaCommandParamTimePeriod*)ppCmdParamList[i];

					if (ODS::ERR::OK != pTimePeriod->GetTimePeriod(&start, &end, &currTime))
					{
						pCommand->DestroyParamList(ppCmdParamList, nCount);
						return ODS::ERR::BAD_PARAM;
					}
				}
				if (ppCmdParamList[i]->GetType() == ODS::HdaCommandParam::TYPE_SESSION)
				{
					ODS::HdaCommandParamSession* pSession = (ODS::HdaCommandParamSession*)ppCmdParamList[i];
					sessionId = pSession->GetSessionId();
				}
			}
			pCommand->DestroyParamList(ppCmdParamList, nCount);
		}
		SYSTEMTIME startUtc, endUtc;
		ODS::TimeUtils::SysTimeLocalToUtc(start, &startUtc);
		ODS::TimeUtils::SysTimeLocalToUtc(end, &endUtc);
		std::map<int, std::vector<ParamValueList> > paramList;
		std::string sessionID;
		if (sessionId.IsEmpty()) {
			m_pSoftingInteractor->OpenConnection();
			if (m_connectionsList.empty()) {
				return ODS::ERR::DB_CONNECTION_FAILED;
			}
			sessionID = m_connectionsList.at(m_connectionsList.size() - 1);
		}
		else {
			sessionID = std::string(sessionId.ToString().GetString());
			m_pSoftingInteractor->OpenConnectionWithUUID(sessionID);
		}
		std::set<std::string> tags;
		CreateQueriesList(requestMap, paramList,tags);
		if (paramList.empty()) {
			m_pSoftingInteractor->CloseConnectionWithUUID(sessionID);
			return ODS::ERR::DB_NO_DATA;
		}
		ExecuteQueriesList(requestMap, paramList, tags, pResultList, startUtc, endUtc, sessionID);
		
		m_pSoftingInteractor->CloseConnectionWithUUID(sessionID);
		return ODS::ERR::OK;
	}
	else {
		return res;
	}
}

void DrvOPCUAHistValues::HdaCommandHandler::CreateQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions,
	std::map<int, std::vector<ParamValueList> >& paramList, std::set<std::string>& tagsForQuery)
{
	paramList.clear();
	tagsForQuery.clear();
	std::pair<int, std::vector<ParamValueList> > pair;
	std::pair<std::map<int, std::vector<ParamValueList> >::iterator, bool > insertedPair;
	for (std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator itr = requestFunctions.cbegin(); itr != requestFunctions.cend(); ++itr) {
		int type = itr->first;
		pair = std::make_pair<int, std::vector<ParamValueList> >(std::move(type), BuildCmdValueList(itr->second));
		for (std::vector<ParamValueList>::const_iterator paramItr = pair.second.cbegin(); paramItr != pair.second.cend(); ++paramItr) {
			tagsForQuery.merge(paramItr->GetTagsNames());
		}
		insertedPair = paramList.insert(pair);
	}
}

void DrvOPCUAHistValues::HdaCommandHandler::ExecuteQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, const std::map<int, std::vector<ParamValueList> >& queriesList, 
	const std::set<std::string>& tagsForQuery, std::vector<ODS::HdaFunctionResult*>* pResultList, const SYSTEMTIME& startTime,
	const SYSTEMTIME& endTime, const std::string& sessionId)
{
	SYSTEMTIME localStartDataTime = { 0 };
	SYSTEMTIME localEndDataTime = { 0 };
	ODS::TimeUtils::SysTimeUtcToLocal(startTime, &localStartDataTime);
	ODS::TimeUtils::SysTimeUtcToLocal(endTime, &localEndDataTime);
	std::map<std::string, std::vector<std::string> > fullPaths;
	for (std::set<std::string>::const_iterator queriesIterator = tagsForQuery.cbegin(); queriesIterator != tagsForQuery.cend(); ++queriesIterator) {
		std::pair<std::string, std::vector<std::string> > pair = std::make_pair<std::string, std::vector<std::string> >(std::string(*queriesIterator),split(*queriesIterator,std::string("/")));
		fullPaths.insert(pair);
	}
	std::map<std::string, std::vector<DrvOPCUAHistValues::Record> > tagsData;
	m_pSoftingInteractor->GetRecords(tagsData, localStartDataTime, localEndDataTime, fullPaths, sessionId);
	if (tagsData.empty()) {
		return;
	}
	for (std::map<int, std::vector<ParamValueList> >::const_iterator queriesIterator = queriesList.cbegin(); queriesIterator != queriesList.cend(); ++queriesIterator) {
		size_t length = queriesIterator->second.size();
		std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator funcIterator = requestFunctions.find(queriesIterator->first);
		if (funcIterator != requestFunctions.cend()) {
			for (size_t index = 0; index < length; ++index) {
				std::map<std::string, std::vector<DrvOPCUAHistValues::Record> >::const_iterator tagsIterator = tagsData.find(queriesIterator->second.at(index).GetFullAddress());
				if (tagsIterator != tagsData.cend()) {
					if (tagsIterator->second.empty()) {
						return;
					}
					ODS::HdaFunctionResultValueList* pFuncResult = new ODS::HdaFunctionResultValueList;
					pFuncResult->SetContext(funcIterator->second.at(index)->GetContext());
					std::vector<ODS::TvqListElementDescription> listDesc;
					switch (queriesIterator->first) {
					case ODS::HdaFunctionType::VALUE_LIST_CONDITION:
						break;
					case ODS::HdaFunctionType::LAST_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_LAST_VALUE:
					{
						std::vector<DrvOPCUAHistValues::Record>::const_iterator maxItr =
							std::max_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsDataTimeLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*maxItr, nullptr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::FIRST_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_FIRST_VALUE:
					{
						std::vector<DrvOPCUAHistValues::Record>::const_iterator minItr =
							std::min_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsDataTimeLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*minItr, nullptr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::AVG_VALUE:
					{
						Record record = std::accumulate(tagsIterator->second.cbegin(), tagsIterator->second.cend(), Record(), RecordsSum);
						Record avgRecord = RecordAvg(record, tagsIterator->second.size());
						ODS::Tvq* tvq = CreateTvqFromRecord(avgRecord, nullptr);
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::SUM_VALUE:
					{
						Record record = std::accumulate(tagsIterator->second.cbegin(), tagsIterator->second.cend(), Record(), RecordsSum);
						ODS::Tvq* tvq = CreateTvqFromRecord(record, nullptr);
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::MIN_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_MINIMUM_VALUE:
					{
						std::vector<DrvOPCUAHistValues::Record>::const_iterator minItr =
							std::min_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsValueLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*minItr, nullptr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::MAX_VALUE:
					case ODS::HdaFunctionType::TIMESTAMP_OF_MAXIMUM_VALUE:
					{
						std::vector<DrvOPCUAHistValues::Record>::const_iterator maxItr =
							std::max_element(tagsIterator->second.cbegin(), tagsIterator->second.cend(), CompareRecordsValueLess);
						ODS::Tvq* tvq = CreateTvqFromRecord(*maxItr, nullptr);
						SYSTEMTIME tm = tvq->GetTimestampLoc();
						pFuncResult->AddTvq(tvq);
						pResultList->push_back(pFuncResult);
					}
						break;
					case ODS::HdaFunctionType::VALUE_LIST:
						for (std::vector<Record>::const_iterator itr = tagsIterator->second.cbegin(); itr != tagsIterator->second.cend(); ++itr) {
							ODS::Tvq* tvq = CreateTvqFromRecord(*itr, nullptr);
							SYSTEMTIME tm = tvq->GetTimestampLoc();
							if (tm.wYear != 0) {
								if (itr == tagsIterator->second.cbegin()) {

									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), localStartDataTime) < 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = 0;
										desc.m_ulFlags = ODS::TvqListElementDescription::PREV_POINT;
										listDesc.push_back(desc);
									}
								}
								if (itr == tagsIterator->second.cend() - 1) {
									if (ODS::TimeUtils::SysTimeCompare(tvq->GetTimestampLoc(), localEndDataTime) > 0) {
										ODS::TvqListElementDescription desc;
										desc.m_nIndex = tagsIterator->second.size() - 1;
										desc.m_ulFlags = ODS::TvqListElementDescription::POST_POINT;
										listDesc.push_back(desc);
									}
								}
							}
							pFuncResult->AddTvq(tvq);
						}
						if (!listDesc.empty()) {
							ODS::TvqListElementDescription* desc = new ODS::TvqListElementDescription[listDesc.size()];
							for (size_t descItr = 0; descItr < listDesc.size(); descItr++) {
								(desc + descItr)->m_nIndex = listDesc.at(descItr).m_nIndex;
								(desc + descItr)->m_ulFlags = listDesc.at(descItr).m_ulFlags;
							}
							pFuncResult->SetTvqDescList(desc, listDesc.size());
						}
						pResultList->push_back(pFuncResult);
						break;
					default:
						break;
					}
				}
			}
		}
	}
}

std::vector<DrvOPCUAHistValues::ParamValueList> DrvOPCUAHistValues::HdaCommandHandler::BuildCmdValueList(const std::vector<ODS::HdaFunction*>& rFuncList)
{
	std::vector<ParamValueList> vec;
	for (std::vector<ODS::HdaFunction*>::const_iterator itr = rFuncList.cbegin(); itr != rFuncList.cend(); ++itr) {
		vec.push_back(GetParameterValueList(*itr));
	}
	return vec;
}

ODS::Tvq* DrvOPCUAHistValues::HdaCommandHandler::CreateTvqFromRecord(const Record& record, bool* condition) const
{
	VARIANT vValue;
	std::string str;
	const SYSTEMTIME* timeStampStruct = nullptr;
	SYSTEMTIME dataTime = { 0 };
	SYSTEMTIME localDataTime = { 0 };
	float val = 0.0;
	bool bitVal = false;
	ODS::Tvq* tvq = new ODS::Tvq();
	for (Record::const_iterator itr = record.cbegin(); itr != record.cend(); ++itr) {
		switch (itr->second.first)
		{
		case EnumNumericNodeId_Null:
			break;
		case EnumNumericNodeId_Boolean:
			::VariantInit(&vValue);
			vValue.vt = VT_BOOL;
			if (std::stoi(itr->second.second) > 0) {
				bitVal = true;
			}
			else {
				bitVal = false;
			}
			vValue.boolVal = bitVal;
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_SByte:
		case EnumNumericNodeId_Int16:
		case EnumNumericNodeId_Int32:
			::VariantInit(&vValue);
			vValue.vt = VT_INT;
			vValue.intVal = std::stoi(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_Int64:
			::VariantInit(&vValue);
			vValue.vt = VT_I8;
			vValue.llVal = std::stoll(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_Byte:
		case EnumNumericNodeId_UInt16:
		case EnumNumericNodeId_UInt32:
			::VariantInit(&vValue);
			vValue.vt = VT_UINT;
			vValue.ulVal = std::stoul(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_UInt64:
			::VariantInit(&vValue);
			vValue.vt = VT_UI8;
			vValue.ullVal = std::stoull(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_Double:
			::VariantInit(&vValue);
			vValue.vt = VT_R8;
			vValue.dblVal = std::stod(itr->second.second);
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_Float:
			::VariantInit(&vValue);
			vValue.vt = VT_R8;
			val = std::stof(itr->second.second);
			vValue.dblVal = val;
			tvq->SetValue(vValue);
			::VariantClear(&vValue);
			break;
		case EnumNumericNodeId_DateTime:
			timeStampStruct = reinterpret_cast<const SYSTEMTIME*>(itr->second.second.c_str());
			dataTime.wYear = timeStampStruct->wYear;
			dataTime.wMonth = timeStampStruct->wMonth;
			dataTime.wDay = timeStampStruct->wDay;
			dataTime.wHour = timeStampStruct->wHour;
			dataTime.wMinute = timeStampStruct->wMinute;
			dataTime.wSecond = timeStampStruct->wSecond;
			dataTime.wMilliseconds = timeStampStruct->wMilliseconds;
			break;
		default:
			tvq->SetValue(ODS::Data::Value(itr->second.second.c_str()));
			break;
		}
	}
	ODS::TimeUtils::SysTimeUtcToLocal(dataTime, &localDataTime);
	if (localDataTime.wYear != 0) {
		tvq->SetTimestamp(&localDataTime);
	}
	tvq->SetQuality(ODS::Tvq::QUALITY_GOOD);
	return tvq;
}


DrvOPCUAHistValues::ParamValueList DrvOPCUAHistValues::HdaCommandHandler::GetParameterValueList(const ODS::HdaFunction* pHdaFunc)
{
	std::vector<ODS::HdaFunctionParam*> paramList;
	ODS::HdaFunctionParam** pParam = nullptr;
	int nCount = 0;
	int res = pHdaFunc->GetParameterList(&pParam, &nCount);
	for (int i = 0; i < nCount; i++) {
		paramList.push_back(pParam[i]);
	}
	ODS::OdsString address;
	ODS::OdsString fullAddress;
	ODS::OdsString sql;
	bool prevPoint = false;
	bool postPoint = false;
	ODS::HdaFunctionParamLimit::LimitParam limit;
	limit.m_nLimitCount = 0;
	limit.m_nLimitOffset = 0;
	limit.m_nLimitSide = 0;
	int nSpecPoint = 0;
	int valueType = 0;
	for (std::vector<ODS::HdaFunctionParam*>::const_iterator itr = paramList.cbegin(); itr != paramList.cend(); ++itr) {
		int nParamType = (*itr)->GetType();

		switch (nParamType)
		{
		case ODS::HdaFunctionParam::TYPE_ITEM_ADDRESS:
			ParamUtils::GetAddress(address, fullAddress, *itr);
			break;
		case ODS::HdaFunctionParam::TYPE_SQL:
			sql = ParamUtils::GetSql(*itr);
			break;
		case ODS::HdaFunctionParam::TYPE_LIMIT:
			((ODS::HdaFunctionParamLimit*) * itr)->GetLimit(&limit);
			break;
		case ODS::HdaFunctionParam::TYPE_OBJECT:
			valueType = ((ODS::HdaFunctionParamObject*) * itr)->GetType();
			break;
		case ODS::HdaFunctionParam::TYPE_SPEC_POINT:
			nSpecPoint = ((ODS::HdaFunctionParamSpecPoint*) * itr)->GetSpecPointFlag();
			if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_PREV == nSpecPoint)
				prevPoint = true;
			else if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_POST == nSpecPoint)
				postPoint = true;
			else if (ODS::HdaFunctionParamSpecPoint::POINT_TYPE_BOTH == nSpecPoint)
			{
				prevPoint = true;
				postPoint = true;
			}
			break;
		default:
			break;
		}
	}
	pHdaFunc->DestroyParameterList(pParam, nCount);
	ParamValueList valList(std::string(address.GetString()), std::string(fullAddress.GetString()), std::string(sql.GetString()), prevPoint, postPoint, valueType, Limit(limit.m_nLimitSide, limit.m_nLimitOffset, limit.m_nLimitCount));
	return valList;
}
void DrvOPCUAHistValues::HdaCommandHandler::SendMessageError(std::string&& message)
{

}

void DrvOPCUAHistValues::HdaCommandHandler::SendWarning(std::string&& message)
{

}

void DrvOPCUAHistValues::HdaCommandHandler::SendMessageInfo(std::string&& message)
{

}

void DrvOPCUAHistValues::HdaCommandHandler::GetServers(std::vector<std::string>&& servers)
{

}

void DrvOPCUAHistValues::HdaCommandHandler::GetEndPoints(std::vector<SoftingServerEndPointDescription>&& servers)
{

}

void DrvOPCUAHistValues::HdaCommandHandler::GetNewConnectionGuide(std::string&& uuid)
{
	if (uuid.empty() == false) {
		std::vector<std::string>::const_iterator findIterator =
			std::find_if(m_connectionsList.cbegin(), m_connectionsList.cend(), [&](const std::string& existingUuid) {
			return existingUuid == uuid; });
		if (findIterator == m_connectionsList.cend()) {
			m_connectionsList.push_back(uuid);
		}
	}
}

void DrvOPCUAHistValues::HdaCommandHandler::CloseConnectionWithGuide(std::string&& uuid)
{
	if (uuid.empty() == false) {
		std::vector<std::string>::const_iterator findIterator =
			std::find_if(m_connectionsList.cbegin(), m_connectionsList.cend(), [&](const std::string& existingUuid) {
			return existingUuid == uuid; });
		if (findIterator != m_connectionsList.cend()) {
			m_connectionsList.erase(findIterator);
		}
	}
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

bool DrvOPCUAHistValues::CompareRecordsDataTimeLess(const Record& lhs, const Record& rhs)
{
	const SYSTEMTIME* timeStampStructLeft = nullptr;
	const SYSTEMTIME* timeStampStructRight = nullptr;
	Record::const_iterator itrLhs = lhs.findColumnValue(OPC_UA_SERVER_TIMESTAMP);
	Record::const_iterator itrRhs = rhs.findColumnValue(OPC_UA_SERVER_TIMESTAMP);
	if (itrLhs == lhs.cend() || itrRhs == rhs.cend()) {
		return false;
	}
	if (itrLhs->second.first != itrRhs->second.first) {
		return false;
	}
	if (itrLhs->second.first != EnumNumericNodeId_DateTime) {
		return false;
	}
	timeStampStructLeft = reinterpret_cast<const SYSTEMTIME*>(itrLhs->second.second.c_str());
	timeStampStructRight = reinterpret_cast<const SYSTEMTIME*>(itrRhs->second.second.c_str());
	return ODS::TimeUtils::SysTimeCompare(*timeStampStructLeft, *timeStampStructRight) < 0;
}

DrvOPCUAHistValues::Record DrvOPCUAHistValues::RecordsSum(const Record& lhs, const Record& rhs)
{
	DrvOPCUAHistValues::Record record;
	Record::const_iterator itrLhs = lhs.findColumnValue(OPC_UA_VALUE);
	Record::const_iterator itrRhs = rhs.findColumnValue(OPC_UA_VALUE);
	if (itrLhs == lhs.cend() || itrLhs->second.first < EnumNumericNodeId_SByte || itrLhs->second.first > EnumNumericNodeId_Double) {
		if (itrRhs != rhs.cend() && itrRhs->second.first > EnumNumericNodeId_Boolean && itrRhs->second.first < EnumNumericNodeId_String) {
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
		res = val/ (double)quantity;
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
