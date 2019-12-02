#pragma once
#include<functional>
#include"ConnectionAttributes.h"
#include"StatementCondition.h"
#include <Interface\IAbstractUIFacrory.h>
#include<map>
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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnClickedOk();
	afx_msg void OnBtnClickedCancel();
	afx_msg void OnTcnSelChangeTabSettings(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTcnSelChangingTabSettings(NMHDR* pNMHDR, LRESULT* pResult);
private:
	std::function<ODS::UI::IAbstractUIFacrory * (void)> m_uiFactoryGetter;
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> m_connectionAttributes;
	std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > m_conditionFilters;
};
