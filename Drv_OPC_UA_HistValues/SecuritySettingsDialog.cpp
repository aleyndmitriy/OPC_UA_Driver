#include "pch.h"
#include "resource.h"	
#include "SecuritySettingsDialog.h"
const UINT startID = 2000;
const UINT endID = 2003;

IMPLEMENT_DYNAMIC(CSecuritySettingsDialog, CDialogEx)

CSecuritySettingsDialog::CSecuritySettingsDialog(const std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>& endPointsConfigurations, CWnd* pParent):
	CDialogEx(IDD_SECURITY_SETTINGS_DLG, pParent),m_endPointsConfigurations(endPointsConfigurations),m_iSelectedIndex(-1), m_modeButtons(), m_policyButtons()
{

}

CSecuritySettingsDialog::~CSecuritySettingsDialog()
{

}

void CSecuritySettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SECURITY_MODE, m_groupSecurityMode);
	DDX_Control(pDX, IDC_STATIC_SECURITY_POLICY, m_groupSecurityPolicy);
}


BEGIN_MESSAGE_MAP(CSecuritySettingsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CSecuritySettingsDialog::OnBtnClickedOk)
	ON_CONTROL_RANGE(BN_CLICKED,startID + 1, endID, &CSecuritySettingsDialog::OnRangeRadioButtons)
END_MESSAGE_MAP()



BOOL CSecuritySettingsDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (std::vector<DrvOPCUAHistValues::ServerSecurityModeConfiguration>::const_iterator itr = m_endPointsConfigurations.cbegin();
		itr != m_endPointsConfigurations.cend(); ++itr) {
		DrvOPCUAHistValues::ConfigurationSecurityMode mode = itr->securityMode;
		std::string policy = itr->serverSecurityPolicy;
		m_modeButtons.insert(std::make_pair<DrvOPCUAHistValues::ConfigurationSecurityMode, std::unique_ptr<CButton> >(std::move(mode), std::unique_ptr<CButton>()));
		if (mode != DrvOPCUAHistValues::ConfigurationSecurityMode::NONE) {
			m_policyButtons.insert(std::make_pair<std::string, std::unique_ptr<CButton> >(std::move(policy), std::unique_ptr<CButton>()));
		}
	}
	RECT modeRect;
	m_groupSecurityMode.GetClientRect(&modeRect);

	SIZE radioSize;
	radioSize.cx = modeRect.right - 5;
	radioSize.cy = 20;
	int delta = radioSize.cy;
	if (m_modeButtons.size() > 2) {
		delta = (modeRect.bottom - 10 - radioSize.cy * m_modeButtons.size()) / (m_modeButtons.size() - 1);
	}
	m_groupSecurityMode.GetWindowRect(&modeRect);
	POINT point;
	point.x = modeRect.left + 5;
	point.y = modeRect.top + 20;
	this->ScreenToClient(&point);
	UINT startIndex = startID;
	for (std::map<DrvOPCUAHistValues::ConfigurationSecurityMode, std::unique_ptr<CButton>>::iterator itr = m_modeButtons.begin(); itr != m_modeButtons.end(); ++itr) {
		itr->second = std::make_unique<CButton>();
		std::string name = DrvOPCUAHistValues::GetStringFromSecurityMode(itr->first);
		if (itr->first == DrvOPCUAHistValues::ConfigurationSecurityMode::NONE) {
			itr->second->Create(name.c_str(), WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(point, radioSize), this, ++startIndex);
			itr->second->SetCheck(BST_CHECKED);
		}
		else {
			itr->second->Create(name.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(point, radioSize), this, ++startIndex);
		}
		point.y += delta;
	}

	m_groupSecurityPolicy.GetClientRect(&modeRect);
	radioSize.cx = modeRect.right - 5;
	radioSize.cy = 20;
	delta = radioSize.cy;
	if (m_policyButtons.size() > 2) {
		delta = (modeRect.bottom - 10 - radioSize.cy * m_policyButtons.size()) / (m_policyButtons.size() - 1) + 1;
	}
	m_groupSecurityPolicy.GetWindowRect(&modeRect);
	point.x = modeRect.left + 5;
	point.y = modeRect.top + 20;
	this->ScreenToClient(&point);
	bool isGroup = false;
	for (std::map<std::string, std::unique_ptr<CButton>>::iterator itr = m_policyButtons.begin(); itr != m_policyButtons.end(); ++itr) {
		itr->second = std::make_unique<CButton>();
		if (!isGroup) {
			itr->second->Create(itr->first.c_str(), WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(point, radioSize), this, ++startIndex);
			isGroup = true;
		}
		else {
			itr->second->Create(itr->first.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(point, radioSize), this, ++startIndex);
		}
		itr->second->EnableWindow(FALSE);
		point.y += delta;
	}
	return TRUE;
}

int CSecuritySettingsDialog::GetSelectedIndex()
{
	return m_iSelectedIndex;
}

void CSecuritySettingsDialog::CSecuritySettingsDialog::OnRangeRadioButtons(UINT nID)
{
	if (nID == startID + 1) {
		for (std::map<std::string, std::unique_ptr<CButton>>::iterator itr = m_policyButtons.begin(); itr != m_policyButtons.end(); ++itr) {
			itr->second->SetCheck(BST_UNCHECKED);
			itr->second->EnableWindow(FALSE);
		}
	}
	else {
		for (std::map<std::string, std::unique_ptr<CButton>>::iterator itr = m_policyButtons.begin(); itr != m_policyButtons.end(); ++itr) {
			itr->second->EnableWindow(TRUE);
		}
	}
}


void CSecuritySettingsDialog::OnBtnClickedOk()
{
	DrvOPCUAHistValues::ConfigurationSecurityMode mode = DrvOPCUAHistValues::ConfigurationSecurityMode::NONE;
	std::string policy("None");
	for (std::map<DrvOPCUAHistValues::ConfigurationSecurityMode, std::unique_ptr<CButton>>::iterator itr = m_modeButtons.begin(); itr != m_modeButtons.end(); ++itr) {
		if (itr->second->GetCheck() == BST_CHECKED) {
			mode = itr->first;
			break;
		}
	}
	if (mode != DrvOPCUAHistValues::ConfigurationSecurityMode::NONE) {
		for (std::map<std::string, std::unique_ptr<CButton>>::iterator itr = m_policyButtons.begin(); itr != m_policyButtons.end(); ++itr) {
			if (itr->second->GetCheck() == BST_CHECKED) {
				policy = itr->first;
				break;
			}
		}
	}
	for (int index = 0; index < m_endPointsConfigurations.size(); ++index) {
		if (m_endPointsConfigurations.at(index).securityMode == mode && m_endPointsConfigurations.at(index).serverSecurityPolicy == policy) {
			m_iSelectedIndex = index;
			break;
		}
	}
	CDialog::OnOK();
}
