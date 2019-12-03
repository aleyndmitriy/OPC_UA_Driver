// FiltersDialog.cpp : implementation file
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "FiltersDialog.h"
#include "afxdialogex.h"


// FiltersDialog dialog

IMPLEMENT_DYNAMIC(FiltersDialog, CDialog)

FiltersDialog::FiltersDialog(std::shared_ptr<DrvOPCUAHistValues::ConnectionAttributes> attributes, std::shared_ptr<std::map<std::string, std::vector<DrvOPCUAHistValues::StatementCondition> > > filters, CWnd* pParent)
	: CDialog(IDD_FILTERS_DLG, pParent), m_connectionAttributes(attributes), m_conditionFilters(filters)
{

}

FiltersDialog::~FiltersDialog()
{
}

void FiltersDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FiltersDialog, CDialog)
END_MESSAGE_MAP()


// FiltersDialog message handlers
