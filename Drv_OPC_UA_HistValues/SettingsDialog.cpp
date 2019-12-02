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
	: CDialogEx(IDD_SETTINGS_DIALOG, pParent), m_uiFactoryGetter(uiFactiryGetter), m_connectionAttributes(attributes), m_conditionFilters(filters)
{

}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void SettingsDialog::OnBtnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void SettingsDialog::OnTcnSelChangeTabSettings(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void SettingsDialog::OnTcnSelChangingTabSettings(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
