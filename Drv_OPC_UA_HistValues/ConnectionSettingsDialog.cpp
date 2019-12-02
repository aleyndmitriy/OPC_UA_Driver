// ConnectionSettingsDialog.cpp : implementation file
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "ConnectionSettingsDialog.h"
#include "afxdialogex.h"


// ConnectingSettingsDialog dialog

IMPLEMENT_DYNAMIC(ConnectionSettingsDialog, CDialog)

ConnectionSettingsDialog::ConnectionSettingsDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CONNECTION_SETTINGS_DLG, pParent)
{

}

ConnectionSettingsDialog::~ConnectionSettingsDialog()
{
}

void ConnectionSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SERVER_NAME, m_cbServerName);
	DDX_Control(pDX, IDC_COMBO_AUTH_TYPE, m_cbAuthType);
	DDX_Control(pDX, IDC_EDIT_USER_NAME, m_editUserName);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);
	DDX_Control(pDX, IDC_COMBO_CONFIGURATION_DATABASE, m_cbConfigDatabase);
	DDX_Control(pDX, IDC_COMBO_HISTORICAL_DATABASE, m_cbHistoricalDatabase);
}


BEGIN_MESSAGE_MAP(ConnectionSettingsDialog, CDialog)
	ON_CBN_DROPDOWN(IDC_COMBO_SERVER_NAME, &ConnectionSettingsDialog::OnCbnDropDownComboServerName)
	ON_CBN_EDITCHANGE(IDC_COMBO_SERVER_NAME, &ConnectionSettingsDialog::OnCbnEditChangeComboServerName)
	ON_CBN_SELENDOK(IDC_COMBO_SERVER_NAME, &ConnectionSettingsDialog::OnCbnSelEndOkComboServerName)
	ON_CBN_SELCHANGE(IDC_COMBO_AUTH_TYPE, &ConnectionSettingsDialog::OnCbnSelChangeComboAuthType)
	ON_EN_CHANGE(IDC_EDIT_USER_NAME, &ConnectionSettingsDialog::OnEnChangeEditUserName)
	ON_EN_CHANGE(IDC_EDIT_PASSWORD, &ConnectionSettingsDialog::OnEnChangeEditPassword)
	ON_CBN_DROPDOWN(IDC_COMBO_CONFIGURATION_DATABASE, &ConnectionSettingsDialog::OnCbnDropDownComboConfigurationDatabase)
	ON_CBN_EDITUPDATE(IDC_COMBO_CONFIGURATION_DATABASE, &ConnectionSettingsDialog::OnCbnEditUpdateComboConfigurationDatabase)
	ON_CBN_EDITCHANGE(IDC_COMBO_CONFIGURATION_DATABASE, &ConnectionSettingsDialog::OnCbnEditChangeComboConfigurationDatabase)
	ON_CBN_SELCHANGE(IDC_COMBO_CONFIGURATION_DATABASE, &ConnectionSettingsDialog::OnCbnSelChangeComboConfigurationDatabase)
	ON_CBN_SELENDOK(IDC_COMBO_CONFIGURATION_DATABASE, &ConnectionSettingsDialog::OnCbnSelEndOkComboConfigurationDatabase)
	ON_CBN_DROPDOWN(IDC_COMBO_HISTORICAL_DATABASE, &ConnectionSettingsDialog::OnCbnDropDownComboHistoricalDatabase)
	ON_CBN_EDITUPDATE(IDC_COMBO_HISTORICAL_DATABASE, &ConnectionSettingsDialog::OnCbnEditUpdateComboHistoricalDatabase)
	ON_CBN_EDITCHANGE(IDC_COMBO_HISTORICAL_DATABASE, &ConnectionSettingsDialog::OnCbnEditChangeComboHistoricalDatabase)
	ON_CBN_SELCHANGE(IDC_COMBO_HISTORICAL_DATABASE, &ConnectionSettingsDialog::OnCbnSelChangeComboHistoricalDatabase)
	ON_CBN_SELENDOK(IDC_COMBO_HISTORICAL_DATABASE, &ConnectionSettingsDialog::OnCbnSelEndOkComboHistoricalDatabase)
	ON_BN_CLICKED(IDC_BUTTON_TEST_CONNECTION, &ConnectionSettingsDialog::OnBtnClickedButtonTestConnection)
END_MESSAGE_MAP()


// ConnectingSettingsDialog message handlers


void ConnectionSettingsDialog::OnCbnDropDownComboServerName()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnEditChangeComboServerName()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelEndOkComboServerName()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelChangeComboAuthType()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnEnChangeEditUserName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void ConnectionSettingsDialog::OnEnChangeEditPassword()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnDropDownComboConfigurationDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnEditUpdateComboConfigurationDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnEditChangeComboConfigurationDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelChangeComboConfigurationDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelEndOkComboConfigurationDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnDropDownComboHistoricalDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnEditUpdateComboHistoricalDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnEditChangeComboHistoricalDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelChangeComboHistoricalDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnCbnSelEndOkComboHistoricalDatabase()
{
	// TODO: Add your control notification handler code here
}


void ConnectionSettingsDialog::OnBtnClickedButtonTestConnection()
{
	// TODO: Add your control notification handler code here
}


BOOL ConnectionSettingsDialog::OnInitDialog()
{
	return TRUE;
}
void ConnectionSettingsDialog::LoadDatabasesList(const std::vector<std::string>& databases)
{

}

void ConnectionSettingsDialog::WarningMessage(std::string message)
{

}

void ConnectionSettingsDialog::ErrorMessage(std::string message)
{

}

void ConnectionSettingsDialog::StartLoading()
{

}

void ConnectionSettingsDialog::StopLoading()
{

}

void ConnectionSettingsDialog::ConnectToServer()
{

}

void ConnectionSettingsDialog::CheckConnectToDatabase()
{

}

void ConnectionSettingsDialog::ReadAttributes()
{

}