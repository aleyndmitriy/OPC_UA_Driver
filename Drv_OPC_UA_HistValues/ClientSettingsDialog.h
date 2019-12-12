﻿#pragma once
#include<memory>
#include<functional>
#include <Interface\IAbstractUIFacrory.h>
#include"ConnectionAttributes.h"
#include<Application.h>
// Диалоговое окно CClientSettingsDialog

class CClientSettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CClientSettingsDialog)

public:
	CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, CWnd* pParent);
	virtual ~CClientSettingsDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_SETTINGS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
private:
	std::function<ODS::UI::IAbstractUIFacrory * (void)> m_uiFactoryGetter;
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> m_connectAttributes;
	SoftingOPCToolbox5::ApplicationPtr m_pApp;
	CEdit m_editComputerName;
	CComboBox m_cmbServerName;
	CEdit m_editPort;
	CComboBox m_cmbConfiguration;
	CComboBox m_cmbPolicy;
	CEdit m_editLogin;
	CEdit m_editPassword;
	CEdit m_editCertificate;
	CButton m_btnCertificate;
	CEdit m_editPrivateKey;
	CButton m_btnPrivateKey;
	
	BOOL OnInitDialog() override;
	void WarningMessage(std::string message);
	void ErrorMessage(std::string message);
	void StartLoading();
	void StopLoading();
	void ReadAttributes();
	void initApplicationDescription(SoftingOPCToolbox5::ApplicationDescription& appDesc);

public:
	afx_msg void OnEnChangeEditComputerName();
	afx_msg void OnEnUpdateEditComputerName();
	afx_msg void OnCbnDropdownComboSelectServer();
	afx_msg void OnCbnSelchangeComboSelectServer();
	afx_msg void OnEnChangeEditPort();
	afx_msg void OnBtnClickedButtonBrowseNetwork();
	afx_msg void OnBtnClickedButtonGetSeverProperties();
	afx_msg void OnBtnClickedButtonDiscoverServers();
	afx_msg void OnCbnSelChangeComboConfiguration();
	afx_msg void OnCbnSelChangeComboLoginType();
	afx_msg void OnEnChangeEditLogin();
	afx_msg void OnEnUpdateEditLogin();
	afx_msg void OnEnChangeEditPassword();
	afx_msg void OnEnUpdateEditPassword();
	afx_msg void OnEnChangeEditCertificate();
	afx_msg void OnEnUpdateEditCertificate();
	afx_msg void OnBtnClickedButtonCertificatePath();
	afx_msg void OnEnChangeEditPrivateKey();
	afx_msg void OnEnUpdateEditPrivateKey();
	afx_msg void OnBtnClickedButtonPrivateKeyPath();
	afx_msg void OnBtnClickedButtonTestConnection();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnBtnClickedOk();
};
