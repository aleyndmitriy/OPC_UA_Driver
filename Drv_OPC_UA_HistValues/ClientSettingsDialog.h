#pragma once
#include<memory>
#include<functional>
#include <Interface\IAbstractUIFacrory.h>
#include"ConnectionAttributes.h"
#include"SoftingServerInteractorOutput.h"
#include"SoftingServerInteractor.h"
// Диалоговое окно CClientSettingsDialog

class CClientSettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CClientSettingsDialog)

public:
	CClientSettingsDialog(std::function<ODS::UI::IAbstractUIFacrory * (void)> uiFactiryGetter, std::shared_ptr<DrvOPCUAHistValues::SoftingServerInteractor> softingInteractor, std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, std::shared_ptr<DrvOPCUAHistValues::DataTypeAttributes> dataAttributes, CWnd* pParent);
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
	std::shared_ptr<DrvOPCUAHistValues::DataTypeAttributes> m_dataAttributes;
	std::shared_ptr<DrvOPCUAHistValues::SoftingServerInteractor> m_pSoftingInteractor;
	std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration> m_endPointsConfigurations;
	std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy> m_endPointPolicyIds;
	CEdit m_editComputerName;
	CComboBox m_cmbServerName;
	CEdit m_editPort;
	CComboBox m_cmbConfiguration;
	CListCtrl m_lstPolicyType;
	CEdit m_editLogin;
	CEdit m_editUserPassword;
	CEdit m_editPassword;
	CEdit m_editCertificate;
	CButton m_btnCertificate;
	CEdit m_editPrivateKey;
	CButton m_btnPrivateKey;
	CEdit m_editPkiStorePath;
	CButton m_btnPkiStorePath;
	CComboBox m_cmbPolicyId;
	BOOL OnInitDialog() override;
	void SetUpInitialState();
	void StartLoading();
	void StopLoading();
	void ReadAttributes();
	void GetConfigurationsListForSelectedServer();
	void GetPolicyListForSelectedConfiguration();
	void WarningMessage(std::string message);
	void ErrorMessage(std::string message);

public:
	afx_msg void OnEnChangeEditComputerName();
	afx_msg void OnEnUpdateEditComputerName();
	afx_msg void OnCbnSelchangeComboSelectServer();
	afx_msg void OnCbnEditChangeComboSelectServer();
	afx_msg void OnBtnClickedServerPropertyButton();
	afx_msg void OnEnChangeEditPort();
	afx_msg void OnBtnClickedButtonBrowseNetwork();
	afx_msg void OnBtnClickedButtonDiscoverServers();
	afx_msg void OnCbnSelChangeComboConfiguration();
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
	afx_msg void OnBtnClickedButtonPkiStorePath();
	afx_msg void OnBtnClickedButtonTestConnection();
	afx_msg void OnCbnSelChangeComboPolicyId();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnBtnClickedOk();
	void SendMessageError(std::string&& message);
	void SendWarning(std::string&& message);
	void SendMessageInfo(std::string&& message);
	void GetServers(std::vector<std::string>&& servers, std::string&& discoveryUrl);
	void SelectFoundedServer(const std::string& compName, unsigned int port, const std::string& serverName);
	void GetEndPoints(std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>&& endPoints);
	void GetPolicyIds(std::vector<DrvOPCUAHistValues::SecurityUserTokenPolicy>&& policyIds);
	void GetNewConnectionGuide(std::string&& uuid);
	void CloseConnectionWithGuide(std::string&& uuid);	
};
