// ClientSettingsDialog.cpp: файл реализации
//

#include "pch.h"
#include "resource.h"	
#include "ClientSettingsDialog.h"
#include "afxdialogex.h"
#include"Log.h"
#include "Utils.h"
#include"Constants.h"
// Диалоговое окно CClientSettingsDialog

IMPLEMENT_DYNAMIC(CClientSettingsDialog, CDialogEx)

CClientSettingsDialog::CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, CWnd* pParent)
	: CDialogEx(IDD_CLIENT_SETTINGS_DLG, pParent), m_uiFactoryGetter(uiFactiryGetter), m_connectAttributes(attributes), m_pSoftingInteractor(nullptr), m_endPointsConfigurations()
{
	
}

CClientSettingsDialog::~CClientSettingsDialog()
{
	m_connectAttributes.reset();
	m_pSoftingInteractor.reset();
}

void CClientSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COMPUTER_NAME, m_editComputerName);
	DDX_Control(pDX, IDC_COMBO_SELECT_SERVER, m_cmbServerName);
	DDX_Control(pDX, IDC_EDIT_PORT, m_editPort);
	DDX_Control(pDX, IDC_COMBO_CONFIGURATION, m_cmbConfiguration);
	DDX_Control(pDX, IDC_COMBO_LOGIN_TYPE, m_cmbPolicy);
	DDX_Control(pDX, IDC_EDIT_LOGIN, m_editLogin);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);
	DDX_Control(pDX, IDC_EDIT_CERTIFICATE, m_editCertificate);
	DDX_Control(pDX, IDC_BUTTON_CERTIFICATE_PATH, m_btnCertificate);
	DDX_Control(pDX, IDC_EDIT_PRIVATE_KEY, m_editPrivateKey);
	DDX_Control(pDX, IDC_BUTTON_PRIVATE_KEY_PATH, m_btnPrivateKey);
}


BEGIN_MESSAGE_MAP(CClientSettingsDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_COMPUTER_NAME, &CClientSettingsDialog::OnEnChangeEditComputerName)
	ON_EN_UPDATE(IDC_EDIT_COMPUTER_NAME, &CClientSettingsDialog::OnEnUpdateEditComputerName)
	ON_CBN_DROPDOWN(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnDropdownComboSelectServer)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnSelchangeComboSelectServer)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CClientSettingsDialog::OnEnChangeEditPort)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_NETWORK, &CClientSettingsDialog::OnBtnClickedButtonBrowseNetwork)
	ON_BN_CLICKED(IDC_BUTTON_GET_SEVER_PROPERTIES, &CClientSettingsDialog::OnBtnClickedButtonGetSeverProperties)
	ON_BN_CLICKED(IDC_BUTTON_DISCOVER_SERVERS, &CClientSettingsDialog::OnBtnClickedButtonDiscoverServers)
	ON_CBN_SELCHANGE(IDC_COMBO_CONFIGURATION, &CClientSettingsDialog::OnCbnSelChangeComboConfiguration)
	ON_CBN_SELCHANGE(IDC_COMBO_LOGIN_TYPE, &CClientSettingsDialog::OnCbnSelChangeComboLoginType)
	ON_EN_CHANGE(IDC_EDIT_LOGIN, &CClientSettingsDialog::OnEnChangeEditLogin)
	ON_EN_UPDATE(IDC_EDIT_LOGIN, &CClientSettingsDialog::OnEnUpdateEditLogin)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &CClientSettingsDialog::OnEnChangeEditPassword)
	ON_EN_UPDATE(IDC_EDIT_PASSWORD, &CClientSettingsDialog::OnEnUpdateEditPassword)
	ON_EN_CHANGE(IDC_EDIT_CERTIFICATE, &CClientSettingsDialog::OnEnChangeEditCertificate)
	ON_EN_UPDATE(IDC_EDIT_CERTIFICATE, &CClientSettingsDialog::OnEnUpdateEditCertificate)
	ON_BN_CLICKED(IDC_BUTTON_CERTIFICATE_PATH, &CClientSettingsDialog::OnBtnClickedButtonCertificatePath)
	ON_EN_CHANGE(IDC_EDIT_PRIVATE_KEY, &CClientSettingsDialog::OnEnChangeEditPrivateKey)
	ON_EN_UPDATE(IDC_EDIT_PRIVATE_KEY, &CClientSettingsDialog::OnEnUpdateEditPrivateKey)
	ON_BN_CLICKED(IDC_BUTTON_PRIVATE_KEY_PATH, &CClientSettingsDialog::OnBtnClickedButtonPrivateKeyPath)
	ON_BN_CLICKED(IDC_BUTTON_TEST_CONNECTION, &CClientSettingsDialog::OnBtnClickedButtonTestConnection)
	ON_BN_CLICKED(IDCANCEL, &CClientSettingsDialog::OnBtnClickedCancel)
	ON_BN_CLICKED(IDOK, &CClientSettingsDialog::OnBtnClickedOk)
END_MESSAGE_MAP()


BOOL CClientSettingsDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetUpInitialState();
	//m_pSoftingInteractor = std::make_shared<SoftingServerInteractor>(shared_from_this());
	if (!m_connectAttributes->configuration.computerName.empty()) {
		m_editComputerName.SetWindowTextA(m_connectAttributes->configuration.computerName.c_str());
	}
	if (!m_connectAttributes->configuration.serverName.empty()) {
		int ind = m_cmbServerName.AddString(m_connectAttributes->configuration.serverName.c_str());
		m_cmbServerName.SetCurSel(ind);
	}
	if (m_connectAttributes->configuration.port > 0) {
		std::string port = std::to_string(m_connectAttributes->configuration.port);
		m_editPort.SetWindowTextA(port.c_str());
	}
	if (!m_connectAttributes->configurationMode.serverSecurityName.empty()) {
		std::string config = m_connectAttributes->configurationMode.serverSecurityName + std::string(" - ") +
			DrvOPCUAHistValues::GetStringFromSecurityMode(m_connectAttributes->configurationMode.securityMode);
		int ind = m_cmbConfiguration.AddString(config.c_str());
		m_cmbConfiguration.SetCurSel(ind);
	}
	
	switch (m_connectAttributes->configurationAccess.securityType) {
	case DrvOPCUAHistValues::ConfigurationSecurityType::USER_NAME:
		m_cmbServerName.SetCurSel(DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::USER_NAME));
		m_editLogin.EnableWindow(TRUE);
		m_editLogin.SetWindowTextA(m_connectAttributes->configurationAccess.login.c_str());
		m_editPassword.EnableWindow(TRUE);
		m_editPassword.SetWindowTextA(m_connectAttributes->configurationAccess.password.c_str());
		break;
	case DrvOPCUAHistValues::ConfigurationSecurityType::CERTIFICATE:
		m_cmbServerName.SetCurSel(DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::CERTIFICATE));
		m_editCertificate.EnableWindow(TRUE);
		m_editCertificate.SetWindowTextA(m_connectAttributes->configurationAccess.certificate.c_str());
		m_btnCertificate.EnableWindow(TRUE);
		m_editPrivateKey.EnableWindow(TRUE);
		m_editPrivateKey.SetWindowTextA(m_connectAttributes->configurationAccess.certificate.c_str());
		m_btnPrivateKey.EnableWindow(TRUE);
		break;
	default:
		break;
	}
	return TRUE;
}

void CClientSettingsDialog::SetUpInitialState()
{
	m_editComputerName.SetSel(0, -1);
	m_editComputerName.Clear();
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	m_cmbServerName.ResetContent();
	m_cmbConfiguration.ResetContent();

	m_editLogin.SetSel(0, -1);
	m_editLogin.Clear();
	m_editLogin.EnableWindow(FALSE);

	m_editPassword.SetSel(0, -1);
	m_editPassword.Clear();
	m_editPassword.EnableWindow(FALSE);

	m_editCertificate.SetSel(0, -1);
	m_editCertificate.Clear();
	m_editCertificate.EnableWindow(FALSE);
	m_btnCertificate.EnableWindow(FALSE);

	m_editPrivateKey.SetSel(0, -1);
	m_editPrivateKey.Clear();
	m_editPrivateKey.EnableWindow(FALSE);
	m_btnPrivateKey.EnableWindow(FALSE);

	m_cmbPolicy.ResetContent();
	int pos = m_cmbPolicy.AddString(DrvOPCUAHistValues::GetStringFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::ANONYMOUS).c_str());
	m_cmbPolicy.SetItemData(pos, DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::ANONYMOUS));
	pos = m_cmbPolicy.AddString(DrvOPCUAHistValues::GetStringFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::USER_NAME).c_str());
	m_cmbPolicy.SetItemData(pos, DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::USER_NAME));
	pos = m_cmbPolicy.AddString(DrvOPCUAHistValues::GetStringFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::CERTIFICATE).c_str());
	m_cmbPolicy.SetItemData(pos, DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::CERTIFICATE));
	pos = m_cmbPolicy.AddString(DrvOPCUAHistValues::GetStringFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::ISSUED_TOKEN).c_str());
	m_cmbPolicy.SetItemData(pos, DrvOPCUAHistValues::GetIntFromSecurityType(DrvOPCUAHistValues::ConfigurationSecurityType::ISSUED_TOKEN));
}
// Обработчики сообщений CClientSettingsDialog


void CClientSettingsDialog::OnEnChangeEditComputerName()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnUpdateEditComputerName()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnCbnDropdownComboSelectServer()
{
	int index = m_cmbConfiguration.GetCurSel();
}


void CClientSettingsDialog::OnCbnSelchangeComboSelectServer()
{
	int index = m_cmbServerName.GetCurSel();
	m_pSoftingInteractor->ChooseCurrentServer(index);
}


void CClientSettingsDialog::OnEnChangeEditPort()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnBtnClickedButtonBrowseNetwork()
{
	std::string computerName;
	if (getComputerName(computerName)) {
		m_editComputerName.SetWindowTextA(computerName.c_str());
	}
}


void CClientSettingsDialog::OnBtnClickedButtonGetSeverProperties()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnBtnClickedButtonDiscoverServers()
{
	CString str;
	m_editComputerName.GetWindowTextA(str);
	std::string computerName = std::string(str.GetBuffer());
	str.ReleaseBuffer();
	str.Empty();
	m_cmbServerName.ResetContent();
	if(!m_pSoftingInteractor) {
		m_pSoftingInteractor = std::make_shared<SoftingServerInteractor>(this, computerName);
	}
	m_pSoftingInteractor->GetServers();
}


void CClientSettingsDialog::OnCbnSelChangeComboConfiguration()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnCbnSelChangeComboLoginType()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnEnChangeEditLogin()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnUpdateEditLogin()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnChangeEditPassword()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnUpdateEditPassword()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnChangeEditCertificate()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnUpdateEditCertificate()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnBtnClickedButtonCertificatePath()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnEnChangeEditPrivateKey()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnEnUpdateEditPrivateKey()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// с флагом ENM_UPDATE ORed в маске lParam mask.

	// TODO:  Добавьте код элемента управления
}


void CClientSettingsDialog::OnBtnClickedButtonPrivateKeyPath()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnBtnClickedButtonTestConnection()
{
	CString str;
	int len = m_cmbServerName.GetWindowTextLengthA();
	m_cmbServerName.GetWindowTextA(str);
	int index = m_cmbConfiguration.GetCurSel();
	if (index >= 0) {

	}
}


void CClientSettingsDialog::OnBtnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnCancel();
}


void CClientSettingsDialog::OnBtnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

void CClientSettingsDialog::WarningMessage(std::string message)
{
	MessageBox(TEXT(message.c_str()), "Warning", MB_ICONWARNING);
}

void CClientSettingsDialog::ErrorMessage(std::string message)
{
	MessageBox(TEXT(message.c_str()), "Warning", MB_ICONSTOP);
}


void CClientSettingsDialog::StartLoading()
{
	HCURSOR hCurs = LoadCursor(NULL, IDC_WAIT);
	SetCursor(hCurs);
}

void CClientSettingsDialog::StopLoading()
{
	HCURSOR hCurs = LoadCursor(NULL, IDC_ARROW);
	SetCursor(hCurs);
}

void CClientSettingsDialog::ReadAttributes()
{

}


void CClientSettingsDialog::GetServerUrl(std::string& url)
{
	std::string hostName;
	if (getComputerName(hostName) == false)
	{
		// use the default host name
		hostName = std::string("localhost");
	}
	std::string server = std::string(":51510/UA/DemoServer");
	url = std::string("opc.tcp://") + hostName + server;
}

void CClientSettingsDialog::SendMessageError(std::string&& message)
{
	ErrorMessage(message);
}

void CClientSettingsDialog::SendWarning(std::string&& message)
{
	WarningMessage(message);
}

void CClientSettingsDialog::GetServers(std::vector<std::string>&& servers)
{
	size_t index = 0;
	for (std::vector<std::string>::const_iterator itr = servers.cbegin(); itr != servers.cend(); ++itr)
	{
		int pos = m_cmbServerName.AddString(itr->c_str());
		m_cmbServerName.SetItemData(pos, index++);
	}
}

void CClientSettingsDialog::GetEndPoints(std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>&& endPoints)
{
	m_endPointsConfigurations.clear();
	m_endPointsConfigurations.assign(endPoints.cbegin(), endPoints.cend());
	size_t index = 0;
	for (std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>::const_iterator itr = endPoints.cbegin(); itr != endPoints.cend(); ++itr)
	{
		std::string desc = itr->m_endPointDesc.serverSecurityName + std::string("-") + DrvOPCUAHistValues::GetStringFromSecurityMode(itr->m_endPointDesc.securityMode) +
			std::string("-") + DrvOPCUAHistValues::GetStringFromSecurityType(itr->m_endPointPolicy.securityType);
		int pos = m_cmbConfiguration.AddString(desc.c_str());
		m_cmbConfiguration.SetItemData(pos, index++);
	}

}