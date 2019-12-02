#pragma once
#include<memory>
#include<functional>
#include <Interface\IAbstractUIFacrory.h>
#include <CommonUI/IDbBrowser.h>

// ConnectionSettingsDialog dialog

class ConnectionSettingsDialog : public CDialog
{
	DECLARE_DYNAMIC(ConnectionSettingsDialog)

public:
	ConnectionSettingsDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ConnectionSettingsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONNECTION_SETTINGS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnDropDownComboServerName();
	afx_msg void OnCbnEditChangeComboServerName();
	afx_msg void OnCbnSelEndOkComboServerName();
	afx_msg void OnCbnSelChangeComboAuthType();
	afx_msg void OnEnChangeEditUserName();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnCbnDropDownComboConfigurationDatabase();
	afx_msg void OnCbnEditUpdateComboConfigurationDatabase();
	afx_msg void OnCbnEditChangeComboConfigurationDatabase();
	afx_msg void OnCbnSelChangeComboConfigurationDatabase();
	afx_msg void OnCbnSelEndOkComboConfigurationDatabase();
	afx_msg void OnCbnDropDownComboHistoricalDatabase();
	afx_msg void OnCbnEditUpdateComboHistoricalDatabase();
	afx_msg void OnCbnEditChangeComboHistoricalDatabase();
	afx_msg void OnCbnSelChangeComboHistoricalDatabase();
	afx_msg void OnCbnSelEndOkComboHistoricalDatabase();
	afx_msg void OnBtnClickedButtonTestConnection();
private:
	CComboBox m_cbServerName;
	CComboBox m_cbAuthType;
	CEdit m_editUserName;
	CEdit m_editPassword;
	CComboBox m_cbConfigDatabase;
	CComboBox m_cbHistoricalDatabase;
	BOOL OnInitDialog() override;
	void LoadDatabasesList(const std::vector<std::string>& databases);
	void WarningMessage(std::string message);
	void ErrorMessage(std::string message);
	void StartLoading();
	void StopLoading();
	void ConnectToServer();
	void CheckConnectToDatabase();
	void ReadAttributes();
};
