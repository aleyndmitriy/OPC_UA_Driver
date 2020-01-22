#pragma once
#include"ConnectionAttributes.h"
#include<HdaCommand.h>
#include<vector>
#include<set>
#include"SoftingServerInteractorOutput.h"
#include"SoftingServerInteractor.h"
#include<Tvq.h>
#include"ISettingsDataSource.h"
#include"ParamValueList.h"
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
		void GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers) override;
		void GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds) override;
		void GetNewConnectionGuide(std::string&& uuid) override;
		void CloseConnectionWithGuide(std::string&& uuid) override;
		void CreateQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, std::map<int, std::vector<ParamValueList> >& paramList, std::set<std::string>& tagsForQuery);
		ParamValueList GetParameterValueList(const ODS::HdaFunction* pHdaFunc);
		std::vector<ParamValueList> BuildCmdValueList(const std::vector<ODS::HdaFunction*>& rFuncList);
		void ExecuteQueriesList(const std::map<int, std::vector<ODS::HdaFunction*> >& requestFunctions, const std::map<int, std::vector<ParamValueList> >& paramList,
			const std::set<std::string>& tagsForQuery, std::vector<ODS::HdaFunctionResult*>* pResultList, const SYSTEMTIME& startTime,
			const SYSTEMTIME& endTime, const std::string& sessionId);
		ODS::Tvq* CreateTvqFromRecord(const Record& record, bool* condition) const;
		bool AdjustConditions(const std::vector<TagCondition>& condition, const std::map<std::string, std::vector<DrvOPCUAHistValues::Record> >& tagsData, const Record& record);
	};
}