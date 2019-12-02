// FiltersDialog.cpp : implementation file
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "FiltersDialog.h"
#include "afxdialogex.h"


// FiltersDialog dialog

IMPLEMENT_DYNAMIC(FiltersDialog, CDialog)

FiltersDialog::FiltersDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FILTERS_DLG, pParent)
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
