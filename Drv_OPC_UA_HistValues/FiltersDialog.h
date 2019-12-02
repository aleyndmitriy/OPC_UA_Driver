#pragma once


// FiltersDialog dialog

class FiltersDialog : public CDialog
{
	DECLARE_DYNAMIC(FiltersDialog)

public:
	FiltersDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~FiltersDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILTERS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
