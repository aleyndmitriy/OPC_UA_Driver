#pragma once
#include<memory>
#include<map>
#include<vector>
#include"ConnectionAttributes.h"
#include "StatementCondition.h"
// FiltersDialog dialog

class FiltersDialog : public CDialog
{
	DECLARE_DYNAMIC(FiltersDialog)

public:
	FiltersDialog(std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > filters, CWnd* pParent = nullptr);   // standard constructor
	virtual ~FiltersDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILTERS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> m_connectionAttributes;
	std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > m_conditionFilters;
};
