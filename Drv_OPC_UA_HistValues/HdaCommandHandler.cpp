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
	ExecuteCommand(pCommand, *pList, nCount, &resultList);
	for (std::vector<ODS::HdaFunctionResult*>::const_iterator iterRes = resultList.cbegin(); iterRes != resultList.cend(); iterRes++)
	{
		pResult->AddFunctionResult(*iterRes);
	}
	pCommand->DestroyFunctionList(pList, nCount);
	return ODS::ERR::OK;
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
		std::map<int, std::vector<std::string> > queriesList;
		std::string sessionID;
		if (sessionId.IsEmpty()) {
			return ODS::ERR::DB_CONNECTION_FAILED;
		}
		else {
			sessionID = std::string(sessionId.ToString().GetString());
			m_pSoftingInteractor->OpenConnectionWithUUID(sessionID);
		}
		CreateQueriesList(requestMap, queriesList, startUtc, endUtc, sessionID);
		if (queriesList.empty()) {
			m_pSoftingInteractor->CloseConnectionWithUUID(sessionID);
			return ODS::ERR::DB_NO_DATA;
		}
		//ExecuteQueriesList(requestMap, queriesList, pResultList, startUtc, endUtc, sessionID);
		
		m_pSoftingInteractor->CloseConnectionWithUUID(sessionID);
		return ODS::ERR::OK;
	}
	else {
		return res;
	}
}

void DrvOPCUAHistValues::HdaCommandHandler::CreateQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, std::map<int, std::vector<std::string> >& queriesList, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::string& sessionId)
{
	queriesList.clear();
	
	std::pair<int, std::vector<std::string> > pair;
	std::pair<std::map<int, std::vector<std::string> >::iterator, bool > insertedPair;
	for (std::map<int, std::vector<ODS::HdaFunction*> >::const_iterator itr = requestFunctions.cbegin(); itr != requestFunctions.cend(); ++itr) {
		switch (itr->first) {
		case ODS::HdaFunctionType::VALUE_LIST:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::VALUE_LIST), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::VALUE_LIST_CONDITION:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::VALUE_LIST_CONDITION), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::LAST_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::LAST_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::FIRST_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::FIRST_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::TIMESTAMP_OF_LAST_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::TIMESTAMP_OF_LAST_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::TIMESTAMP_OF_FIRST_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::TIMESTAMP_OF_FIRST_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::AVG_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::AVG_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::SUM_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::SUM_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::MIN_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::MIN_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::MAX_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::MAX_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::TIMESTAMP_OF_MINIMUM_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::TIMESTAMP_OF_MINIMUM_VALUE), BuildCmdValueList(itr->second));
			break;
		case ODS::HdaFunctionType::TIMESTAMP_OF_MAXIMUM_VALUE:
			pair = std::make_pair<int, std::vector<std::string> >(int(ODS::HdaFunctionType::TIMESTAMP_OF_MAXIMUM_VALUE), BuildCmdValueList(itr->second));
			break;
		default:
			break;
		}
		insertedPair = queriesList.insert(pair);
	}
}

std::vector<std::string> DrvOPCUAHistValues::HdaCommandHandler::BuildCmdValueList(const std::vector<ODS::HdaFunction*>& rFuncList)
{
	std::vector<std::string> vec;
	for (std::vector<ODS::HdaFunction*>::const_iterator itr = rFuncList.cbegin(); itr != rFuncList.cend(); ++itr) {
		ParamValueList paramList = GetParameterValueList(*itr);
		vec.push_back(paramList.GetFullAddress());
	}
	return vec;
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
	ParamValueList valList(std::string(address.GetString()), std::string(fullAddress.GetString()), prevPoint, postPoint, valueType, Limit(limit.m_nLimitSide, limit.m_nLimitOffset, limit.m_nLimitCount));
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
