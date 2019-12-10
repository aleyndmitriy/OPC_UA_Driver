#pragma once
#include<memory>
#include<functional>
#include <Interface\IAbstractUIFacrory.h>
#include <CommonUI/IDbBrowser.h>

// Диалоговое окно CClientSettingsDialog

class CClientSettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CClientSettingsDialog)

public:
	CClientSettingsDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CClientSettingsDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_SETTINGS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
