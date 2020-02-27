#pragma once

#include"SoftingApplication.h"
#include<map>
#include<queue>
#include"SoftingServerInteractorOutput.h"
#include "Record.h"
#include"TagInfo.h"

namespace DrvOPCUAHistValues
{
	class SoftingServerInteractor: public SoftingApplicationOutput, public std::enable_shared_from_this<SoftingServerInteractor> {
	public:
		SoftingServerInteractor();
		SoftingServerInteractor(const SoftingServerInteractor& src) = delete;
		SoftingServerInteractor& operator=(const SoftingServerInteractor& src) = delete;
		SoftingServerInteractor(SoftingServerInteractor&& src) = delete;
		SoftingServerInteractor& operator=(SoftingServerInteractor&& src) = delete;
		~SoftingServerInteractor();
		void SetAttributes(std::shared_ptr<ConnectionAttributes> attributes);
		void SetOutput(std::shared_ptr<SoftingServerInteractorOutput> output);
		void GetServers();
		void ChooseCurrentServer();
		void ChooseCurrentEndPoint();
		void ChooseCurrentTokenPolicy();
		void OpenConnectionWithUUID(const std::string& connectionID);
		void CloseConnectionWithUUID(const std::string& connectionID);
		void OpenConnection();
		void TestConnection();
		void BrowseSession(const std::string& connectionID);
		void GetTags(std::vector<TagInfo>& tags, std::queue<std::string>& tagsPath, const std::string& connectionID);
		void GetRecords(std::map<std::string, std::vector<Record> >& tagsData, const SYSTEMTIME& startTime, const SYSTEMTIME& endTime,
			const std::map<std::string, std::vector<std::string> >& fullPaths, const std::string& connectionID);
		void SendMessageError(std::string&& message) override;
		void SendWarning(std::string&& message) override;
		void SendMessageInfo(std::string&& message) override;
		void GetAggregateFunctions(SoftingOPCToolbox5::Client::SessionPtr session);
	private:
		std::shared_ptr<ConnectionAttributes> m_pServerAttributes;
		std::weak_ptr<SoftingServerInteractorOutput> m_pOutput;
		EnumStatusCode m_enumResult;
		std::unique_ptr<SoftingOPCToolbox5::EndpointDescription> m_selectedEndPointDescription;
		std::unique_ptr<SoftingOPCToolbox5::UserTokenPolicy> m_userToken;
		std::map<std::string, SoftingOPCToolbox5::Client::SessionPtr> m_sessionsList;
		bool startApplication();
		void chooseEndPointAndPolicyId();
		EnumNodeClass getNodeInfo(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session);
		void nodeWalk(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session);
		void readNode(const SoftingOPCToolbox5::NodeId& nodeId, SoftingOPCToolbox5::Client::SessionPtr session);
		bool findNode(const SoftingOPCToolbox5::NodeId& originNodeId, SoftingOPCToolbox5::NodeId& finalNodeId, const std::string& path, SoftingOPCToolbox5::Client::SessionPtr session);
		bool findNode(SoftingOPCToolbox5::NodeId& nodeId, const std::vector<std::string>& fullPath, SoftingOPCToolbox5::Client::SessionPtr session);
		void getTags(SoftingOPCToolbox5::NodeId& nodeId, std::vector<TagInfo>& tags, std::queue<std::string>& receivedTags, SoftingOPCToolbox5::Client::SessionPtr session);
		void getHistoricalValues(const std::vector<SoftingOPCToolbox5::NodeId>& nodesToRead, const SoftingOPCToolbox5::DateTime& startTime, const SoftingOPCToolbox5::DateTime& endTime,
			std::vector< std::vector<SoftingOPCToolbox5::DataValue> >& historicalValuesOfNodes, SoftingOPCToolbox5::Client::SessionPtr session);
	};
}

bool admitToAttributes(const SoftingOPCToolbox5::EndpointDescription& desc, const DrvOPCUAHistValues::ConnectionAttributes& attributes);
bool admitToSecurityPolicy(const SoftingOPCToolbox5::UserTokenPolicy& policy, const DrvOPCUAHistValues::SecurityUserTokenPolicy& attributesPolicy);
DrvOPCUAHistValues::ServerSecurityModeConfiguration mapConfigFromEndPointDesc(const SoftingOPCToolbox5::EndpointDescription& desc);
DrvOPCUAHistValues::SecurityUserTokenPolicy mapEndPointTokenFromPolicy(const SoftingOPCToolbox5::UserTokenPolicy& policy);
DrvOPCUAHistValues::Record mapRecordFromDataValue(const SoftingOPCToolbox5::DataValue& dataValue);