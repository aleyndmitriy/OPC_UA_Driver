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

CClientSettingsDialog::CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<SoftingServerInteractor> softingInteractor, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, CWnd* pParent)
	: CDialogEx(IDD_CLIENT_SETTINGS_DLG, pParent), m_uiFactoryGetter(uiFactiryGetter), m_connectAttributes(attributes), m_pSoftingInteractor(softingInteractor), m_endPointsConfigurations(), m_endPointPolicyIds()
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
	DDX_Control(pDX, IDC_PKI_STORE_PATH, m_editPkiStorePath);
	DDX_Control(pDX, IDC_BUTTON_PKI_STORE_PATH, m_btnPkiStorePath);
	DDX_Control(pDX, IDC_COMBO_POLICY_ID, m_cmbPolicyId);
	DDX_Control(pDX, IDC_EDIT_USER_PASSWORD, m_editUserPassword);
}


BEGIN_MESSAGE_MAP(CClientSettingsDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_COMPUTER_NAME, &CClientSettingsDialog::OnEnChangeEditComputerName)
	ON_EN_UPDATE(IDC_EDIT_COMPUTER_NAME, &CClientSettingsDialog::OnEnUpdateEditComputerName)
	ON_CBN_DROPDOWN(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnDropdownComboSelectServer)
	ON_CBN_SELCHANGE(IDC_COMBO_SELECT_SERVER, &CClientSettingsDialog::OnCbnSelchangeComboSelectServer)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CClientSettingsDialog::OnEnChangeEditPort)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE_NETWORK, &CClientSettingsDialog::OnBtnClickedButtonBrowseNetwork)
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
	ON_BN_CLICKED(IDC_BUTTON_PKI_STORE_PATH, &CClientSettingsDialog::OnBtnClickedButtonPkiStorePath)
	ON_CBN_SELCHANGE(IDC_COMBO_POLICY_ID, &CClientSettingsDialog::OnCbnSelChangeComboPolicyId)
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
		std::string desc = m_connectAttributes->configurationMode.serverSecurityName + std::string("#") + DrvOPCUAHistValues::GetStringFromSecurityMode(m_connectAttributes->configurationMode.securityMode) +
			std::string("#") + m_connectAttributes->configurationMode.serverSecurityPolicy;
		int pos = m_cmbConfiguration.AddString(desc.c_str());
		m_cmbConfiguration.SetItemData(pos, 0);
		m_cmbConfiguration.SetCurSel(pos);
	}
	m_endPointsConfigurations.push_back(m_connectAttributes->configurationMode);
	
	if (!m_connectAttributes->configurationAccess.m_policy.m_policyId.empty()) {
		int pos = m_cmbPolicyId.AddString(m_connectAttributes->configurationAccess.m_policy.m_policyId.c_str());
		m_cmbPolicyId.SetItemData(pos, 0);
		m_cmbPolicyId.SetCurSel(pos);
	}
	m_endPointPolicyIds.push_back(m_connectAttributes->configurationAccess.m_policy);

	LVITEM item;
	memset(&item, 0, sizeof(item));
	TCHAR modeStr[256];
	std::string attr = m_connectAttributes->configurationAccess.m_policy.m_securityPolicyUri;
	StringCchCopy(modeStr, attr.size()+1, attr.c_str());
	item.pszText = modeStr;
	item.mask = LVIF_TEXT | LVIF_PARAM;
	item.stateMask = UINT(-1);
	item.cchTextMax = 40;
	item.iSubItem = 0;
	item.state = 0;
	item.iItem = 0;
	item.cColumns = 0;
	item.puColumns = NULL;
	item.lParam = MAKELPARAM(DrvOPCUAHistValues::GetIntFromSecurityMode(m_connectAttributes->configurationMode.securityMode), DrvOPCUAHistValues::GetIntFromSecurityType(m_connectAttributes->configurationAccess.m_policy.m_securityType));
	LRESULT res = ::SendMessage(m_lstPolicyType.m_hWnd, LVM_INSERTITEM, 0, (LPARAM)&item);
	ListView_SetItem(m_lstPolicyType.m_hWnd, &item);
	if (!m_connectAttributes->configurationAccess.m_userLogin.m_login.empty() && m_connectAttributes->configurationAccess.m_userLogin.m_login.size() > 0) {
		m_editLogin.SetWindowTextA(m_connectAttributes->configurationAccess.m_userLogin.m_login.c_str());
	}
	if (!m_connectAttributes->configurationAccess.m_userLogin.m_password.empty() && m_connectAttributes->configurationAccess.m_userLogin.m_password.size() > 0) {
		m_editLogin.SetWindowTextA(m_connectAttributes->configurationAccess.m_userLogin.m_password.c_str());
	}
	if (!m_connectAttributes->configurationAccess.m_certificate.m_password.empty() && m_connectAttributes->configurationAccess.m_certificate.m_password.size() > 0) {
		m_editPassword.SetWindowTextA(m_connectAttributes->configurationAccess.m_certificate.m_password.c_str());
	}
	if (!m_connectAttributes->configurationAccess.m_certificate.m_certificate.empty() && m_connectAttributes->configurationAccess.m_certificate.m_certificate.size() > 0) {
		m_editCertificate.SetWindowTextA(m_connectAttributes->configurationAccess.m_certificate.m_certificate.c_str());
	}
	if (!m_connectAttributes->configurationAccess.m_certificate.m_privateKey.empty() && m_connectAttributes->configurationAccess.m_certificate.m_privateKey.size() > 0) {
		m_editPrivateKey.SetWindowTextA(m_connectAttributes->configurationAccess.m_certificate.m_privateKey.c_str());
	}

	if (!m_connectAttributes->configurationAccess.m_certificate.m_pkiTrustedPath.empty() && m_connectAttributes->configurationAccess.m_certificate.m_pkiTrustedPath.size() > 0) {
		m_editPkiStorePath.SetWindowTextA(m_connectAttributes->configurationAccess.m_certificate.m_pkiTrustedPath.c_str());
	}
	return TRUE;
}

void CClientSettingsDialog::SetUpInitialState()
{
	m_editComputerName.SetSel(0, -1);
	m_editComputerName.Clear();
	m_editPort.SetSel(0, -1);
	m_editPort.Clear();
	m_cmbConfiguration.ResetContent();
	m_cmbPolicyId.ResetContent();
	m_lstPolicyType.DeleteAllItems();
	m_endPointsConfigurations.clear();
	m_editLogin.SetSel(0, -1);
	m_editLogin.Clear();
	m_editUserPassword.SetSel(0, -1);
	m_editUserPassword.Clear();
	m_editPassword.SetSel(0, -1);
	m_editPassword.Clear();

	m_editCertificate.SetSel(0, -1);
	m_editCertificate.Clear();

	m_editPrivateKey.SetSel(0, -1);
	m_editPrivateKey.Clear();
	
	m_editPkiStorePath.SetSel(0, -1);
	m_editPkiStorePath.Clear();

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
	StartLoading();
	m_endPointsConfigurations.clear();
	m_lstPolicyType.DeleteAllItems();
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
	TCHAR szPathname[_MAX_PATH];
	BROWSEINFOA brs;
	brs.hwndOwner = this->m_hWnd;
	brs.pidlRoot = NULL;
	brs.pszDisplayName = szPathname;
	brs.lpszTitle = TEXT("Select Computer Name");
	brs.ulFlags = BIF_NONEWFOLDERBUTTON | BIF_BROWSEFORCOMPUTER;
	brs.lpfn = NULL;
	LPITEMIDLIST list = SHBrowseForFolderA(&brs);
	if (list != NULL) {
		m_editComputerName.SetWindowTextA(szPathname);
	}
}


void CClientSettingsDialog::OnBtnClickedButtonDiscoverServers()
{
	StartLoading();
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
	StartLoading();
	m_lstPolicyType.DeleteAllItems();
	m_cmbPolicyId.ResetContent();
	
	ReadAttributes();
	if (m_pSoftingInteractor) {
		m_pSoftingInteractor->ChooseCurrentEndPoint();
	}
}

void CClientSettingsDialog::OnCbnSelChangeComboPolicyId()
{
	int index = m_cmbPolicyId.GetCurSel();
	if (index < 0 || index >= m_endPointPolicyIds.size()) {
		return;
	}
	StartLoading();
	m_lstPolicyType.DeleteAllItems();
	LVITEM item;
	TCHAR modeStr[256];
	std::string attr = m_endPointPolicyIds.at(index).m_securityPolicyUri;
	StringCchCopy(modeStr, attr.size() + 1, attr.c_str());
	item.pszText = modeStr;
	item.mask = LVIF_TEXT | LVIF_PARAM;
	item.stateMask = (UINT)-1;
	item.cchTextMax = 40;
	item.iSubItem = 0;
	item.state = 0;// LVIS_FOCUSED | LVIS_SELECTED;
	item.iItem = 0;
	item.cColumns = 1;
	item.lParam = MAKELPARAM(DrvOPCUAHistValues::GetIntFromSecurityMode(m_connectAttributes->configurationMode.securityMode),
		DrvOPCUAHistValues::GetIntFromSecurityType(m_endPointPolicyIds.at(index).m_securityType));
	m_lstPolicyType.InsertItem(&item);
	ListView_SetItem(m_lstPolicyType.m_hWnd, &item);
	ReadAttributes();
	if (m_pSoftingInteractor) {
		m_pSoftingInteractor->ChooseCurrentTokenPolicy();
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
	TCHAR szPathname[_MAX_PATH];
	OPENFILENAME ofn = { OPENFILENAME_SIZE_VERSION_400 };
	ofn.hwndOwner = this->m_hWnd;
	ofn.lpstrFilter = TEXT("*.*\0");
	lstrcpy(szPathname, TEXT("*.*"));
	ofn.lpstrFile = szPathname;
	ofn.nMaxFile = _countof(szPathname);
	ofn.lpstrTitle = TEXT("Select certificate file ");
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;
	BOOL bOk = GetOpenFileName(&ofn);
	if (bOk) {
		m_editCertificate.SetWindowTextA(szPathname);
	}
}


void CClientSettingsDialog::OnEnChangeEditPrivateKey()
{
	
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
	TCHAR szPathname[_MAX_PATH];
	OPENFILENAME ofn = { OPENFILENAME_SIZE_VERSION_400 };
	ofn.hwndOwner = this->m_hWnd;
	ofn.lpstrFilter = TEXT("*.*\0");
	lstrcpy(szPathname, TEXT("*.*"));
	ofn.lpstrFile = szPathname;
	ofn.nMaxFile = _countof(szPathname);
	ofn.lpstrTitle = TEXT("Select private key file ");
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;
	BOOL bOk = GetOpenFileName(&ofn);
	if (bOk) {
		m_editPrivateKey.SetWindowTextA(szPathname);
	}
}

void CClientSettingsDialog::OnBtnClickedButtonPkiStorePath()
{
	TCHAR szPathname[_MAX_PATH];
	BROWSEINFOA brs;
	brs.hwndOwner = this->m_hWnd;
	brs.pidlRoot = NULL;
	brs.pszDisplayName = szPathname;
	brs.lpszTitle = TEXT("Select Pki folder for trusted certificates ");
	brs.ulFlags = BIF_NONEWFOLDERBUTTON | BIF_RETURNONLYFSDIRS;
	brs.lpfn = NULL;
	LPITEMIDLIST list = SHBrowseForFolderA(&brs);
	if (list == NULL) {
		return;
	}
	if (SHGetPathFromIDListA(list, szPathname)) {
		m_editPkiStorePath.SetWindowTextA(szPathname);
	}
}


void CClientSettingsDialog::OnBtnClickedButtonTestConnection()
{
	StartLoading();
	ReadAttributes();
	if (m_pSoftingInteractor) {
		m_pSoftingInteractor->TestConnection();
	}
}


void CClientSettingsDialog::OnBtnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CClientSettingsDialog::OnBtnClickedOk()
{
	ReadAttributes();
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
	size_t posPartOfName = std::string::npos;
	std::string fullName = std::string(str.GetBuffer(len));
	posPartOfName = fullName.find_first_of('#');
	std::string servName = fullName.substr(0, fullName.find_first_of('#'));
	m_connectAttributes->configurationMode.serverSecurityName = servName;
	if (posPartOfName != std::string::npos) {
		posPartOfName = fullName.find_first_of('#', posPartOfName + 1);
		servName = fullName.substr(posPartOfName);
		m_connectAttributes->configurationMode.serverSecurityPolicy = servName;
	}
	str.ReleaseBuffer();
	str.Empty();
	DWORD_PTR lParam = m_lstPolicyType.GetItemData(0);
	int mode = LOWORD(lParam);
	int type = HIWORD(lParam);
	m_connectAttributes->configurationMode.securityMode = DrvOPCUAHistValues::GetModeFromInt(mode);
	m_connectAttributes->configurationAccess.m_policy.m_securityType = DrvOPCUAHistValues::GetTypeFromInt(type);
	len = m_cmbPolicyId.GetWindowTextLengthA();
	m_cmbPolicyId.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_policy.m_policyId = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_lstPolicyType.GetWindowTextLengthA();
	m_lstPolicyType.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_policy.m_securityPolicyUri = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editLogin.GetWindowTextLengthA();
	m_editLogin.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_userLogin.m_login = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPassword.GetWindowTextLengthA();
	m_editPassword.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_certificate.m_password = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editCertificate.GetWindowTextLengthA();
	m_editCertificate.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_certificate.m_certificate = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPrivateKey.GetWindowTextLengthA();
	m_editPrivateKey.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_certificate.m_privateKey = std::string(str.GetBuffer(len));
	str.ReleaseBuffer();
	str.Empty();
	len = m_editPkiStorePath.GetWindowTextLengthA();
	m_editPkiStorePath.GetWindowTextA(str);
	m_connectAttributes->configurationAccess.m_certificate.m_pkiTrustedPath = std::string(str.GetBuffer(len));
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

void CClientSettingsDialog::SendMessageInfo(std::string&& message)
{
	
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
	StopLoading();
}

void CClientSettingsDialog::GetEndPoints(std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>&& endPoints)
{
	m_endPointsConfigurations.clear();
	m_endPointsConfigurations.assign(endPoints.cbegin(), endPoints.cend());
	m_cmbConfiguration.ResetContent();
	size_t index = 0;
	for (std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>::const_iterator itr = endPoints.cbegin(); itr != endPoints.cend(); ++itr)
	{
		std::string desc = itr->serverSecurityName + std::string("#") + DrvOPCUAHistValues::GetStringFromSecurityMode(itr->securityMode);
		int pos = m_cmbConfiguration.AddString(desc.c_str());
		m_cmbConfiguration.SetItemData(pos, index++);
	}
	StopLoading();
}

void CClientSettingsDialog::GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds)
{
	m_endPointPolicyIds.clear();
	m_endPointPolicyIds.assign(policyIds.cbegin(),policyIds.cend());
	m_cmbPolicyId.ResetContent();
	size_t index = 0;
	for (std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>::const_iterator itr = policyIds.cbegin(); itr != policyIds.cend(); ++itr)
	{
		int pos = m_cmbPolicyId.AddString(itr->m_policyId.c_str());
		m_cmbPolicyId.SetItemData(pos, index++);
	}
	StopLoading();
}

void CClientSettingsDialog::GetNewConnectionGuide(std::string&& uuid)
{
	StopLoading();
	if (!uuid.empty()) {
		WarningMessage(std::string("Connection Test Succeed!"));
	}
}

void CClientSettingsDialog::CloseConnectionWithGuide(std::string&& uuid)
{
	
}




