#pragma once
#include"ConnectionAttributes.h"
#include<HdaCommand.h>
#include<vector>
#include"SoftingServerInteractorOutput.h"
#include"SoftingServerInteractor.h"
#include<Tvq.h>
#include"ISettingsDataSource.h"

namespace DrvOPCUAHistValues
{
	class HdaCommandHandler: public SoftingServerInteractorOutput, public std::enable_shared_from_this<HdaCommandHandler>
	{
	public:
		HdaCommandHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore);
		HdaCommandHandler() = delete;
		~HdaCommandHandler();
		int Init(std::shared_ptr<ConnectionAttributes> attributes);
		int Shut();
		int HandleCommand(ODS::HdaCommand* pCommand, ODS::HdaCommandResult* pResult);
	private:
		std::shared_ptr<ConnectionAttributes> m_pAttributes;
		std::shared_ptr<SoftingServerInteractor> m_pSoftingInteractor;
		std::vector<std::string> m_connectionsList;
		int ExecuteCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* funcList, int listSize, std::vector<ODS::HdaFunctionResult*>* pResultList);
		int AnalyzeCommand(ODS::HdaCommand* pCommand, ODS::HdaFunction* funcList, int listSize, std::map<int, std::vector<ODS::HdaFunction*> >& requestMap);
		int HandleOpenSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList);
		int HandleCloseSession(ODS::HdaFunction* pFunc, std::vector<ODS::HdaFunctionResult*>* pResultList);
		void SendMessageError(std::string&& message) override;
		void SendWarning(std::string&& message) override;
		void SendMessageInfo(std::string&& message) override;
		void GetServers(std::vector<std::string>&& servers) override;
		void GetEndPoints(std::vector<SoftingServerEndPointDescription>&& servers) override;
		void GetNewConnectionGuide(std::string&& uuid) override;
		void CloseConnectionWithGuide(std::string&& uuid) override;
		/*std::vector<std::string> BuildCmdValueList(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdValueListConditions(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdFirstValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdLastValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdMinValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdMaxValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdSumValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdAvgValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdTimeStampFirstValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdTimeStampLastValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdTimeStampMaxValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		std::vector<std::string> BuildCmdTimeStampMinValue(const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::vector<ODS::HdaFunction*>& rFuncList, const std::map<std::string, TagItemRecord>& tags);
		ParamValueList GetParameterValueList(const ODS::HdaFunction* pHdaFunc);
		ODS::Tvq* CreateTvqFromRecord(const Record& record, bool* condition) const;
		void CreateQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, std::map<int, std::vector<std::string> >& queriesList, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime, const std::string& sessionId);
		void ExecuteQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, const std::map<int, std::vector<std::string> >& queriesList, std::vector<ODS::HdaFunctionResult*>* pResultList, const SYSTEMTIME& startTime,
			const SYSTEMTIME& endTime, const std::string& sessionId);*/
	};
}