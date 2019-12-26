#include "pch.h"
#include"ServerHdaItem.h"
#include <OdsErr.h>
#include"XMLSettingsDataSource.h"
#include<HdaFunctionTypes.h>
#include <HdaFunctionResult.h>
#include<HdaCommand.h>

void* DrvOPCUAHistValues::ServerHdaItem::GetInterface(int nIfcId)
{
	return this;
}

int DrvOPCUAHistValues::ServerHdaItem::Init(TCHAR* szCfgString)
{
	XMLSettingsDataSource settingSource;
	if (szCfgString != NULL)
	{
		size_t len = _tcslen(szCfgString);
		if (len > 0) {
			m_pAttributes = std::make_shared<ConnectionAttributes>();
			settingSource.LoadAttributesString(szCfgString, len, *m_pAttributes);
		}
		m_commandHandler.Init(m_pAttributes);
	}
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::ServerHdaItem::Shut()
{
	//m_commandHandler.Shut();
	return ODS::ERR::OK;
}

int DrvOPCUAHistValues::ServerHdaItem::IsHdaFunctionSupported(int nFuncType)
{
	switch (nFuncType)
	{
	case ODS::HdaFunctionType::VALUE_LIST:
	case ODS::HdaFunctionType::VALUE_LIST_CONDITION:
	case ODS::HdaFunctionType::LAST_VALUE:
	case ODS::HdaFunctionType::FIRST_VALUE:
	case ODS::HdaFunctionType::TIMESTAMP_OF_LAST_VALUE:
	case ODS::HdaFunctionType::TIMESTAMP_OF_FIRST_VALUE:
	case ODS::HdaFunctionType::AVG_VALUE:
	case ODS::HdaFunctionType::SUM_VALUE:
	case ODS::HdaFunctionType::MIN_VALUE:
	case ODS::HdaFunctionType::MAX_VALUE:
	case ODS::HdaFunctionType::TIMESTAMP_OF_MINIMUM_VALUE:
	case ODS::HdaFunctionType::TIMESTAMP_OF_MAXIMUM_VALUE:
	case ODS::HdaFunctionType::OPEN_SESSION:
	case ODS::HdaFunctionType::CLOSE_SESSION:
		return 1;
	}
	return 0;
}

int DrvOPCUAHistValues::ServerHdaItem::Execute(ODS::HdaCommand* pCommand, ODS::HdaCommandResult** ppResult)
{
	if (!ppResult)
		return ODS::ERR::BAD_PARAM;
	ODS::HdaCommandResult* pResult = new ODS::HdaCommandResult;
	if (!pResult)
		return ODS::ERR::MEMORY_ALLOCATION_ERR;

	int rc = ODS::ERR::OK;//m_commandHandler.HandleCommand(pCommand, pResult);
	if (ODS::ERR::OK == rc)
	{
		*ppResult = pResult;
		return ODS::ERR::OK;
	}
	else {
		*ppResult = 0;
		return rc;
	}
}

int DrvOPCUAHistValues::ServerHdaItem::DestroyResult(ODS::HdaCommandResult* pResult)
{
	delete pResult;
	return ODS::ERR::OK;
}
