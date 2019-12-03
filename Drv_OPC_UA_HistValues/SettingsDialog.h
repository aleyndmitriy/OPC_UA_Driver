#pragma once
#include"ConnectionSettingsDialog.h"
#include"FiltersDialog.h"
// SettingsDialog dialog

class SettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SettingsDialog)

public:
	SettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, 
		std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > filters, CWnd* pParent);   // standard constructor
	virtual ~SettingsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnClickedOk();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnTcnSelChangeTabSettings(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTcnSelChangingTabSettings(NMHDR* pNMHDR, LRESULT* pResult);
private:
	std::unique_ptr<ConnectionSettingsDialog> m_connectionSettingsDlg;
	std::unique_ptr<FiltersDialog> m_filtersDlg;
	CTabCtrl m_tabSettings;
};
