#pragma once
#include"ClientSettingsDialog.h"
#include"SoftingServerInteractorOutput.h"
#include<memory>

namespace DrvOPCUAHistValues
{
	class ClientSettingsDialogWrapper : public SoftingServerInteractorOutput, public std::enable_shared_from_this<ClientSettingsDialogWrapper>
	{
	public:
		ClientSettingsDialogWrapper(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<SoftingServerInteractor> softingDataStore, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes, HWND parentWindow);
		~ClientSettingsDialogWrapper();
		int DoModal();
		void SendMessageError(std::string&& message) override;
		void SendWarning(std::string&& message) override;
		void SendMessageInfo(std::string&& message) override;
		void GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl) override;
		void GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers) override;
		void GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds) override;
		void GetAggregates(std::vector<std::pair<std::string, int> >&& aggregates) override;
		void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName) override;
		void GetNewConnectionGuide(std::string&& uuid) override;
		void CloseConnectionWithGuide(std::string&& uuid) override;
	private:
		std::shared_ptr<SoftingServerInteractor> m_softingDataStore;
		CClientSettingsDialog* m_pMFCdialog;
	};
}