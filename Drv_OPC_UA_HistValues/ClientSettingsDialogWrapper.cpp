#include"pch.h"
#include"ClientSettingsDialogWrapper.h"

DrvOPCUAHistValues::ClientSettingsDialogWrapper::ClientSettingsDialogWrapper(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<SoftingServerInteractor> softingDataStore, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, std::shared_ptr<DataTypeAttributes> dataAttributes, HWND parentWindow):m_pMFCdialog(nullptr)
{
	CWnd* parent = CWnd::FromHandle(parentWindow);
	m_softingDataStore = softingDataStore;
	m_softingDataStore->SetAttributes(attributes);
	m_softingDataStore->SetDataAttributes(dataAttributes);
	m_pMFCdialog = new CClientSettingsDialog(uiFactiryGetter, softingDataStore, attributes, dataAttributes, parent);
}

DrvOPCUAHistValues::ClientSettingsDialogWrapper::~ClientSettingsDialogWrapper()
{
	delete m_pMFCdialog;
	m_pMFCdialog = nullptr;
}

int DrvOPCUAHistValues::ClientSettingsDialogWrapper::DoModal()
{
	m_softingDataStore->SetOutput(shared_from_this());
	return m_pMFCdialog->DoModal();
}


void DrvOPCUAHistValues::ClientSettingsDialogWrapper::SendMessageError(std::string&& message)
{
	m_pMFCdialog->SendMessageError(std::move(message));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::SendWarning(std::string&& message)
{
	m_pMFCdialog->SendWarning(std::move(message));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::SendMessageInfo(std::string&& message)
{
	m_pMFCdialog->SendMessageInfo(std::move(message));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl)
{
	m_pMFCdialog->GetServers(std::move(servers), std::move(discoveryUrl));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers)
{
	m_pMFCdialog->GetEndPoints(std::move(servers));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds)
{
	m_pMFCdialog->GetPolicyIds(std::move(policyIds));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetAggregates(std::vector<std::pair<std::string, int> >&& aggregates)
{
	m_pMFCdialog->GetAggregates(std::move(aggregates));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName)
{
	m_pMFCdialog->SelectFoundedServer(compName,port, serverName);
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::ChooseSecurityConfiguration()
{
	m_pMFCdialog->ChooseSecurityConfiguration();
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetNewConnectionGuide(std::string&& uuid)
{
	m_pMFCdialog->GetNewConnectionGuide(std::move(uuid));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::CloseConnectionWithGuide(std::string&& uuid)
{
	m_pMFCdialog->CloseConnectionWithGuide(std::move(uuid));
}