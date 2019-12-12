// ClientSettingsDialog.cpp: файл реализации
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "ClientSettingsDialog.h"
#include "afxdialogex.h"
#include"Log.h"
#include "Utils.h"
// Диалоговое окно CClientSettingsDialog

IMPLEMENT_DYNAMIC(CClientSettingsDialog, CDialogEx)

CClientSettingsDialog::CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, CWnd* pParent)
	: CDialogEx(IDD_CLIENT_SETTINGS_DLG, pParent), m_uiFactoryGetter(uiFactiryGetter), m_connectAttributes(attributes), m_pApp()
{
	EnumStatusCode result;
	// init the SDK to gain access to the SDK functions
	result = SoftingOPCToolbox5::loadToolbox(NULL);
	if (StatusCode::isBad(result))
	{
		_tprintf(_T("ERROR: Failed to load the SDK: %s\n"), getEnumStatusCodeString(result));
		CDialogEx::OnCancel();
	}
	m_pApp = SoftingOPCToolbox5::Application::instance();
	SoftingOPCToolbox5::ApplicationDescription appDesc;

}

CClientSettingsDialog::~CClientSettingsDialog()
{
	m_connectAttributes.reset();
	EnumStatusCode result = SoftingOPCToolbox5::unloadToolbox();
	if (StatusCode::isBad(result))
	{
		_tprintf(_T("ERROR: An error occurred while unloading the SDK: %s\n"), getEnumStatusCodeString(result));
	}
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
	return TRUE;
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
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnCbnSelchangeComboSelectServer()
{
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnBtnClickedButtonGetSeverProperties()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CClientSettingsDialog::OnBtnClickedButtonDiscoverServers()
{
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
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

void CClientSettingsDialog::initApplicationDescription(SoftingOPCToolbox5::ApplicationDescription& appDesc)
{
	std::string hostName;
	if (getComputerName(hostName) == false)
	{
		// use the default host name
		hostName = std::string("localhost");
	}

	appDesc.setApplicationType(EnumApplicationType_Client);
	appDesc.setApplicationName(SoftingOPCToolbox5::LocalizedText(_T("DreamReport OpcUa Histotical Items Client"), _T("en")));
	appDesc.setApplicationUri(_T("urn:") + hostName + _T("/ODS/Dream Report/System"));	// The ApplicationUri should match with the URI in the application certificate
	appDesc.setProductUri(_T("urn:/ODS/Dream Report/System")); 
}