// ClientSettingsDialog.cpp: файл реализации
//

#include "pch.h"
#include "Drv_OPC_UA_HistValues.h"
#include "ClientSettingsDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CClientSettingsDialog

IMPLEMENT_DYNAMIC(CClientSettingsDialog, CDialogEx)

CClientSettingsDialog::CClientSettingsDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_SETTINGS_DLG, pParent)
{

}

CClientSettingsDialog::~CClientSettingsDialog()
{
}

void CClientSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClientSettingsDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CClientSettingsDialog
