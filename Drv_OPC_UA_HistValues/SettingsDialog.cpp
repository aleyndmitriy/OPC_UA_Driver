// SettingsDialog.cpp : implementation file
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "SettingsDialog.h"
#include "afxdialogex.h"


// SettingsDialog dialog

IMPLEMENT_DYNAMIC(SettingsDialog, CDialogEx)

SettingsDialog::SettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes,
	std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > filters, CWnd* pParent)
	: CDialogEx(IDD_SETTINGS_DIALOG, pParent),m_connectionSettingsDlg(nullptr), m_filtersDlg(nullptr)
{
	m_connectionSettingsDlg = std::make_unique<ConnectionSettingsDialog>(uiFactiryGetter, attributes, this);
	m_filtersDlg = std::make_unique<FiltersDialog>(attributes, filters, this);
}

SettingsDialog::~SettingsDialog()
{
}

BOOL SettingsDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	TCITEM tia;
	tia.mask = TCIF_TEXT;
	tia.pszText = "Connection settings";
	m_tabSettings.InsertItem(0, &tia);
	tia.pszText = "Alarm filters";
	m_tabSettings.InsertItem(1, &tia);
	CRect rc;
	m_tabSettings.GetWindowRect(&rc);
	m_tabSettings.ScreenToClient(&rc);
	m_tabSettings.AdjustRect(FALSE, &rc);
	m_connectionSettingsDlg->Create(IDD_CONNECTION_SETTINGS_DLG, &m_tabSettings);
	m_connectionSettingsDlg->MoveWindow(&rc);
	m_connectionSettingsDlg->ShowWindow(SW_SHOW);
	m_filtersDlg->Create(IDD_FILTERS_DLG, &m_tabSettings);
	m_filtersDlg->MoveWindow(&rc);
	m_filtersDlg->ShowWindow(SW_HIDE);
	return TRUE;
}

void SettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SETTINGS, m_tabSettings);
}


BEGIN_MESSAGE_MAP(SettingsDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &SettingsDialog::OnBtnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SettingsDialog::OnBtnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SETTINGS, &SettingsDialog::OnTcnSelChangeTabSettings)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB_SETTINGS, &SettingsDialog::OnTcnSelChangingTabSettings)
END_MESSAGE_MAP()


// SettingDialog message handlers


void SettingsDialog::OnBtnClickedOk()
{
	CDialogEx::OnOK();
}


void SettingsDialog::OnBtnClickedCancel()
{
	CDialogEx::OnCancel();
}


void SettingsDialog::OnTcnSelChangeTabSettings(NMHDR* pNMHDR, LRESULT* pResult)
{
	int iTabIndex = m_tabSettings.GetCurSel();
	if (iTabIndex) {
		m_filtersDlg->ShowWindow(SW_SHOW);
	}
	else {
		m_connectionSettingsDlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}


void SettingsDialog::OnTcnSelChangingTabSettings(NMHDR* pNMHDR, LRESULT* pResult)
{
	int iTabIndex = m_tabSettings.GetCurSel();
	if (iTabIndex) {
		m_filtersDlg->ShowWindow(SW_HIDE);
	}
	else {
		m_connectionSettingsDlg->ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}
