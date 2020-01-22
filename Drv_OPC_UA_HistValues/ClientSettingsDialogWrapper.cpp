#include"pch.h"
#include"ClientSettingsDialogWrapper.h"

DrvOPCUAHistValues::ClientSettingsDialogWrapper::ClientSettingsDialogWrapper(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<SoftingServerInteractor> softingDataStore, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, HWND parentWindow):m_pMFCdialog(nullptr)
{
	CWnd* parent = CWnd::FromHandle(parentWindow);
	m_softingDataStore = softingDataStore;
	m_softingDataStore->SetAttributes(attributes);
	m_pMFCdialog = new CClientSettingsDialog(uiFactiryGetter, softingDataStore, attributes, parent);
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

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetServers(std::vector<std::string>&& servers)
{
	m_pMFCdialog->GetServers(std::move(servers));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetEndPoints(std::vector<ServerSecurityModeConfiguration>&& servers)
{
	m_pMFCdialog->GetEndPoints(std::move(servers));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::GetNewConnectionGuide(std::string&& uuid)
{
	m_pMFCdialog->GetNewConnectionGuide(std::move(uuid));
}

void DrvOPCUAHistValues::ClientSettingsDialogWrapper::CloseConnectionWithGuide(std::string&& uuid)
{
	m_pMFCdialog->CloseConnectionWithGuide(std::move(uuid));
}