#pragma once
#include<memory>
#include<OdsString.h>
#include<IBrowserItem.h>
#include<BrowseItem.h>
#include<vector>
#include"SoftingServerInteractor.h"
#include"ConnectionAttributes.h"

namespace DrvOPCUAHistValues
{
	struct STagItem
	{
		std::vector<ODS::OdsString> m_vAddress;
		ODS::OdsString m_szDescription;
		int m_nType;

		STagItem()
		{
			m_nType = ODS::BrowseItem::TYPE_ITEM;
		}
	};
	
	class BrowserHandler : public SoftingServerInteractorOutput, public std::enable_shared_from_this<BrowserHandler>
	{
	public:
		BrowserHandler(std::shared_ptr<SoftingServerInteractor> softingDataStore);
		BrowserHandler() = delete;
		~BrowserHandler();
		int Init(std::shared_ptr<ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes);
		int GetTagList(std::vector<ODS::OdsString>& rEntry, std::vector<STagItem>* pTagList);
		void SendMessageError(std::string&& message) override;
		void SendWarning(std::string&& message) override;
		void SendMessageInfo(std::string&& message) override;
		void GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl) override;
		void GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers) override;
		void GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds) override;
		void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName) override;
		void GetNewConnectionGuide(std::string&& uuid) override;
		void CloseConnectionWithGuide(std::string&& uuid) override;
	private:
		std::shared_ptr<ConnectionAttributes> m_pAttributes;
		std::shared_ptr<DataTypeAttributes> m_pDataAttributes;
		std::shared_ptr<SoftingServerInteractor> m_pSoftingInteractor;
		std::string m_ConnectionId;
	};

	STagItem mapFromHierarchicalTagInfo(const HierarchicalTagInfo& tag);
}