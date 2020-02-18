#pragma once

class CBrowseNetworkServers : public CDialog
{
	DECLARE_DYNAMIC(CBrowseNetworkServers)
public:
	CBrowseNetworkServers(CWnd* pParent);
	virtual ~CBrowseNetworkServers();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SELECT_NODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	DECLARE_MESSAGE_MAP()
private:
	BOOL OnInitDialog() override;
	virtual BOOL DestroyWindow() override;
	HTREEITEM InsertItem(HTREEITEM hParent, NETRESOURCE* const pNetResource, CString sText, int iImage, int iImageSelected);
	bool	EnumNetwork(HTREEITEM hParent);
	bool	PopulateTree(CString sPath, HTREEITEM hParent);
	CString GetItemPath(HTREEITEM hItem);

	CImageList	m_ImageListTree;					//Item in the Tree image list				
	HTREEITEM	m_hNetworkRoot;						//Network neighbourhood root
	CString		m_sPath;
	CTreeCtrl m_ctrlTree;
public:
	afx_msg void OnTvnSelChangedNetworkTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTvnItemExpandingNetworkTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnClickedOk();
	afx_msg void OnBtnClickedCancel();
	CString GetPath() const;
};

CString WindowName(CString sName);
TCHAR* MakeObjectDynamic(LPTSTR szData);