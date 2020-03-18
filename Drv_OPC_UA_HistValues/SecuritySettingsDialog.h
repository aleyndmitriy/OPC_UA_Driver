#pragma once
#include"ConnectionAttributes.h"
#include "afxdialogex.h"
#include "afxmsg_.h"
#include<map>
#include<memory>

class CSecuritySettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSecuritySettingsDialog)

public:
	CSecuritySettingsDialog(const std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>& endPointsConfigurations , CWnd* pParent);
	virtual ~CSecuritySettingsDialog();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECURITY_SETTINGS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	
	CStatic m_groupSecurityMode;
	CStatic m_groupSecurityPolicy;
	std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration> m_endPointsConfigurations;
	int m_iSelectedIndex;
	std::map<DrvOPCUAHistValues::ConfigurationSecurityMode, std::unique_ptr<CButton>> m_modeButtons;
	std::map<std::string, std::unique_ptr<CButton>> m_policyButtons;
	BOOL OnInitDialog() override;
public:
	int GetSelectedIndex();
	afx_msg void OnRangeRadioButtons(UINT nID);
	afx_msg void OnBtnClickedOk();
};