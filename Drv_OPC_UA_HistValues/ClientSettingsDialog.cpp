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
	DDX_Control(pDX, IDC_EDIT_LOGIN, m_editLogin);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);
	DDX_Control(pDX, IDC_EDIT_CERTIFICATE, m_editCertificate);
	DDX_Control(pDX, IDC_BUTTON_CERTIFICATE_PATH, m_btnCertificate);
	DDX_Control(pDX, IDC_EDIT_PRIVATE_KEY, m_editPrivateKey);
	DDX_Control(pDX, IDC_BUTTON_PRIVATE_KEY_PATH, m_btnPrivateKey);
	DDX_Control(pDX, IDC_LIST_LOGIN_TYPE, m_lstPolicyType);
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
		int ind = m_cmbConfiguration.AddString(m_connectAttributes->configurationMode.serverSecurityName.c_str());
		m_cmbConfiguration.SetCurSel(ind);
	}
	m_endPointsConfigurations.push_back(DrvOPCUAHistValues::SoftingServerEndPointDescription(m_connectAttributes->configurationMode, m_connectAttributes->configurationAccess));
	LVITEM item;
	TCHAR modeStr[20];
	StringCchCopy(modeStr, 20, GetStringFromSecurityMode(m_connectAttributes->configurationMode.securityMode).c_str());
	item.pszText = modeStr;
	item.mask = LVIF_TEXT;
	item.stateMask = (UINT)-1;
	item.cchTextMax = STR_LENGTH;
	item.iSubItem = 0;
	item.state = 0;// LVIS_FOCUSED | LVIS_SELECTED;
	item.iItem = 0;
	item.cColumns = 2;
	item.lParam = MAKELPARAM(DrvOPCUAHistValues::GetIntFromSecurityMode(m_connectAttributes->configurationMode.securityMode), DrvOPCUAHistValues::GetIntFromSecurityType(m_connectAttributes->configurationAccess.securityType));
	m_lstPolicyType.InsertItem(&item);
	item.iSubItem = 1;
	StringCchCopy(modeStr, 20, GetStringFromSecurityType(m_connectAttributes->configurationAccess.securityType).c_str());
	item.pszText = modeStr;
	::SendMessage(m_lstPolicyType.m_hWnd, LVM_SETITEM, 0, (LPARAM)&item);
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
	if (!m_pSoftingInteractor) {
		m_pSoftingInteractor = std::make_shared<SoftingServerInteractor>(this,m_connectAttributes);
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
	m_lstPolicyType.DeleteAllItems();
	m_endPointsConfigurations.clear();
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
	
}


void CClientSettingsDialog::OnCbnSelchangeComboSelectServer()
{
	ReadAttributes();
	if (m_pSoftingInteractor) {
		m_pSoftingInteractor->ChooseCurrentServer();
	}
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
	ReadAttributes();
	if(m_pSoftingInteractor) {
		m_pSoftingInteractor->GetServers();
	}
}


void CClientSettingsDialog::OnCbnSelChangeComboConfiguration()
{
	int index = m_cmbConfiguration.GetCurSel();
	if (index < 0 || index >= m_endPointsConfigurations.size()) {
		return;
	}
	m_lstPolicyType.DeleteAllItems();
	LVITEM item;
	TCHAR modeStr[20];
	StringCchCopy(modeStr, 20, DrvOPCUAHistValues::GetStringFromSecurityMode(m_endPointsConfigurations.at(index).m_endPointDesc.securityMode).c_str());
	item.pszText = modeStr;
	item.mask = LVIF_TEXT;
	item.stateMask = (UINT)-1;
	item.cchTextMax = STR_LENGTH;
	item.iSubItem = 0;
	item.state = 0;// LVIS_FOCUSED | LVIS_SELECTED;
	item.iItem = 0;
	item.cColumns = 2;
	item.lParam = MAKELPARAM(DrvOPCUAHistValues::GetIntFromSecurityMode(m_endPointsConfigurations.at(index).m_endPointDesc.securityMode), DrvOPCUAHistValues::GetIntFromSecurityType(m_endPointsConfigurations.at(index).m_endPointPolicy.securityType));
	m_lstPolicyType.InsertItem(&item);
	item.iSubItem = 1;
	StringCchCopy(modeStr, 20, DrvOPCUAHistValues::GetStringFromSecurityType(m_endPointsConfigurations.at(index).m_endPointPolicy.securityType).c_str());
	item.pszText = modeStr;
	::SendMessage(m_lstPolicyType.m_hWnd, LVM_SETITEM, 0, (LPARAM)&item);
	ReadAttributes();
	if (m_pSoftingInteractor) {
		m_pSoftingInteractor->ChooseCurrentEndPoint();
	}
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
	CString str;
	int len = m_editComputerName.GetWindowTextLengthA();
	m_editComputerName.GetWindowTextA(str);
	m_connectAttributes->configuration.computerName = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_cmbServerName.GetWindowTextLengthA();
	m_cmbServerName.GetWindowTextA(str);
	m_connectAttributes->configuration.serverName = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPort.GetWindowTextLengthA();
	m_editPort.GetWindowTextA(str);
	std::string port = std::string(str.GetBuffer(len));
	if (!port.empty()) {
		m_connectAttributes->configuration.port = std::stoul(port);
	}
	str.ReleaseBuffer();
	str.Empty();
	len = m_cmbConfiguration.GetWindowTextLengthA();
	m_cmbConfiguration.GetWindowTextA(str);
	m_connectAttributes->configurationMode.serverSecurityName = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	DWORD_PTR lParam = m_lstPolicyType.GetItemData(0);
	int mode = LOWORD(lParam);
	int type = HIWORD(lParam);
	m_connectAttributes->configurationMode.securityMode = DrvOPCUAHistValues::GetModeFromInt(mode);
	m_connectAttributes->configurationAccess.securityType = DrvOPCUAHistValues::GetTypeFromInt(type);
	len = m_editLogin.GetWindowTextLengthA();
	m_editLogin.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.login = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPassword.GetWindowTextLengthA();
	m_editPassword.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.password = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editCertificate.GetWindowTextLengthA();
	m_editCertificate.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.certificate = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPrivateKey.GetWindowTextLengthA();
	m_editPrivateKey.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.privateKey = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
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
	m_cmbServerName.ResetContent();
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
	m_cmbConfiguration.ResetContent();
	size_t index = 0;
	for (std::vector<DrvOPCUAHistValues::SoftingServerEndPointDescription>::const_iterator itr = endPoints.cbegin(); itr != endPoints.cend(); ++itr)
	{
		std::string desc = itr->m_endPointDesc.serverSecurityName + std::string("-") + DrvOPCUAHistValues::GetStringFromSecurityMode(itr->m_endPointDesc.securityMode) +
			std::string("-") + DrvOPCUAHistValues::GetStringFromSecurityType(itr->m_endPointPolicy.securityType);
		int pos = m_cmbConfiguration.AddString(desc.c_str());
		m_cmbConfiguration.SetItemData(pos, index++);
	}

}

