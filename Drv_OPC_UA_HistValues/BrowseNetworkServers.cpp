#include "pch.h"
#include "resource.h"	
#include "BrowseNetworkServers.h"
#include "afxdialogex.h"
#include<winnetwk.h>

#define NETWORK_NEIGHBOUR   _T("Network Neighborhood")

IMPLEMENT_DYNAMIC(CBrowseNetworkServers, CDialog)

CBrowseNetworkServers::CBrowseNetworkServers(CWnd* pParent) :CDialog(IDD_DIALOG_SELECT_NODE, pParent)
{

}

CBrowseNetworkServers::~CBrowseNetworkServers()
{

}

void CBrowseNetworkServers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NETWORK_TREE, m_ctrlTree);
}

BEGIN_MESSAGE_MAP(CBrowseNetworkServers, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_NETWORK_TREE, &CBrowseNetworkServers::OnTvnSelChangedNetworkTree)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_NETWORK_TREE, &CBrowseNetworkServers::OnTvnItemExpandingNetworkTree)
	ON_BN_CLICKED(IDOK, &CBrowseNetworkServers::OnBtnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBrowseNetworkServers::OnBtnClickedCancel)
END_MESSAGE_MAP()

BOOL CBrowseNetworkServers::OnInitDialog()
{
	CDialog::OnInitDialog();
	if (!m_ImageListTree.Create(17, 16, ILC_COLORDDB, 0, 1))
		TRACE(_T("Image list creation fault"));

	CBitmap bm;
	bm.LoadBitmap(IDB_FILE_TYPES);
	m_ImageListTree.Add(&bm, &bm);

	//if( !m_ImageListTree.Create(( IDB_FILE_TYPES, 17, 1, RGB( 255, 255, 255 ) ) )
	 //	TRACE( _T("Image list creation fault") );

	m_ctrlTree.SetImageList(&m_ImageListTree, TVSIL_NORMAL);

	//Network neighbour hood
	m_hNetworkRoot = InsertItem(TVI_ROOT, NULL, NETWORK_NEIGHBOUR, DRIVE_RAMDISK + 1,-1);

	//
	//Expand the Tree to the Inital Path.
	//
	HTREEITEM hCurrent = TVI_ROOT;					//Current item in the list being expanded.
	m_ctrlTree.Expand(hCurrent, TVE_EXPAND);

	// Disable OK button on start
	GetDlgItem(IDOK)->EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	return TRUE;
}

BOOL CBrowseNetworkServers::DestroyWindow()
{
	m_sPath = GetItemPath(m_ctrlTree.GetSelectedItem());

	// remove backslashes
	m_sPath.Remove(_T('\\'));


	return CDialog::DestroyWindow();
}

CString CBrowseNetworkServers::GetPath() const
{
	if (m_sPath.GetLength()) return  m_sPath; else return "";
}

void CBrowseNetworkServers::OnTvnSelChangedNetworkTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	int nImage, nSelectedImage;
	TRACE(_T("CBrowseNetworkServers::OnSelchangedTree(%p)\n"), pNMHDR);
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	ASSERT(pNMTreeView);
	ASSERT(pResult);
	CString sPath;									//Currently selected path or empty if not valid

	//Disable search on Workstation roots - enable only index 9 which is the image of the workstation
	m_ctrlTree.GetItemImage(pNMTreeView->itemNew.hItem, nImage, nSelectedImage);

	if (nImage == 9)
	{
		GetDlgItem(IDOK)->EnableWindow(true);
		sPath = GetItemPath(pNMTreeView->itemNew.hItem);
	}
	else
		GetDlgItem(IDOK)->EnableWindow(false);
	*pResult = 0;
}


void CBrowseNetworkServers::OnTvnItemExpandingNetworkTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	TRACE(_T("CBrowseNetworkServers::OnItemexpandingTree(%p)\n"), pNMHDR);
	//CWaitCursor CursorWaiting;
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	ASSERT(pNMTreeView);
	ASSERT(pResult);
	//Only action 2 notifications
	if (pNMTreeView->action == 2)
	{
		//Update location display
		CString sPath = GetItemPath(pNMTreeView->itemNew.hItem);
		//Refresh children
		if (!m_ctrlTree.GetChildItem(pNMTreeView->itemNew.hItem))
		{
			PopulateTree(sPath, pNMTreeView->itemNew.hItem);
			if (m_ctrlTree.GetSelectedItem() != pNMTreeView->itemNew.hItem)
				m_ctrlTree.SelectItem(pNMTreeView->itemNew.hItem);
		}
	}
	*pResult = 0;
}


void CBrowseNetworkServers::OnBtnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void CBrowseNetworkServers::OnBtnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

HTREEITEM CBrowseNetworkServers::InsertItem(HTREEITEM hParent, NETRESOURCE* const pNetResource, CString sText, int iImage, int iImageSelected)
{
	TRACE(_T("CBrowseNetworkServers::InsertItem(%p,%p,%s +++ )\n"), hParent, pNetResource, sText);
	sText = WindowName(sText);
	TVINSERTSTRUCT InsertStruct;
	InsertStruct.hParent = hParent;
	InsertStruct.hInsertAfter = TVI_LAST;
	InsertStruct.itemex.mask = TVIF_IMAGE | TVIF_TEXT | TVIF_CHILDREN |
		TVIF_SELECTEDIMAGE | TVIF_PARAM;
	InsertStruct.itemex.pszText = sText.GetBuffer(sText.GetLength());  sText.ReleaseBuffer();
	InsertStruct.itemex.iImage = iImage;
	if (iImage != 9)
		InsertStruct.itemex.cChildren = 1;
	else
		InsertStruct.itemex.cChildren = 0;

	InsertStruct.itemex.lParam = (LPARAM)pNetResource;
	if (iImageSelected == -1)
		InsertStruct.itemex.iSelectedImage = iImage;
	else
		InsertStruct.itemex.iSelectedImage = iImageSelected;
	return m_ctrlTree.InsertItem(&InsertStruct);
}


bool CBrowseNetworkServers::EnumNetwork(HTREEITEM hParent)
{
	TRACE(_T("CBrowseNetworkServers::EnumNetwork( %p )\n"), hParent);
	bool bGotChildren = false;						//True if a child is added.	

	//Check if the item already has a network resource and use it.
	NETRESOURCE* const pNetResource = (NETRESOURCE*)(m_ctrlTree.GetItemData(hParent));
	//
	//Setup
	//
	DWORD dwResult;
	HANDLE hEnum;
	DWORD cbBuffer = 16384;
	DWORD cEntries = 0xFFFFFFFF;
	LPNETRESOURCE lpnrDrv;
	DWORD i;
	dwResult = WNetOpenEnum(pNetResource ? RESOURCE_GLOBALNET : RESOURCE_CONTEXT,
		RESOURCETYPE_ANY,//RESOURCETYPE_DISK,
		RESOURCEUSAGE_CONTAINER,
		pNetResource ? pNetResource : NULL,
		&hEnum);
	//Was the read sucessfull
	if (dwResult != NO_ERROR)
	{
		TRACE(_T("*** ERROR %d - Cannot enumerate network drives.\n"), dwResult);
		return false;
	}

	//
	//Get items until no more remain.
	//
	do
	{
		lpnrDrv = (LPNETRESOURCE)GlobalAlloc(GPTR, cbBuffer);
		dwResult = WNetEnumResource(hEnum, &cEntries, lpnrDrv, &cbBuffer);
		if (dwResult == NO_ERROR)
		{
			//Scann through the results
			for (i = 0; i < cEntries; i++)
			{
				CString sNameRemote = lpnrDrv[i].lpRemoteName;
				int nType = 9;
				if (sNameRemote.IsEmpty())
				{
					sNameRemote = lpnrDrv[i].lpComment;
					nType = 8;
				}
				//
				//Remove leading back slashes 
				//
				if (sNameRemote.GetLength() > 0 && sNameRemote[0] == _T('\\'))
					sNameRemote = sNameRemote.Mid(1);
				if (sNameRemote.GetLength() > 0 && sNameRemote[0] == _T('\\'))
					sNameRemote = sNameRemote.Mid(1);

				//
				//Display a share or the appropiate icon
				//
				if (lpnrDrv[i].dwDisplayType == RESOURCEDISPLAYTYPE_SHARE)
				{
					//Display only the share name
					int nPos = sNameRemote.Find(_T('\\'));
					if (nPos >= 0)
						sNameRemote = sNameRemote.Mid(nPos + 1);
					//InsertItem( hParent, NULL, sNameRemote, DRIVE_NO_ROOT_DIR, DRIVE_UNKNOWN );
				}
				else
				{
					NETRESOURCE* pResource = new NETRESOURCE;
					ASSERT(pResource);
					*pResource = lpnrDrv[i];
					pResource->lpLocalName = MakeObjectDynamic(pResource->lpLocalName);
					pResource->lpRemoteName = MakeObjectDynamic(pResource->lpRemoteName);
					pResource->lpComment = MakeObjectDynamic(pResource->lpComment);
					pResource->lpProvider = MakeObjectDynamic(pResource->lpProvider);
					InsertItem(hParent, pResource, sNameRemote, pResource->dwDisplayType + 7, -1);
					bGotChildren = true;
				}
			}
		}
		GlobalFree((HGLOBAL)lpnrDrv);
		if (dwResult != ERROR_NO_MORE_ITEMS)
		{
			TRACE(_T("*** ERROR %d - Cannot complete network drive enumeration\n"), dwResult);
			break;
		}
	} while (dwResult != ERROR_NO_MORE_ITEMS);

	//
	//Let go and go home
	//
	WNetCloseEnum(hEnum);
	return bGotChildren;
}

bool CBrowseNetworkServers::PopulateTree(CString sPath, HTREEITEM hParent)
{
	TRACE(_T("CBrowseNetworkServers::PopulateTree( %s )\n"), sPath);
	bool bGotChildren = false;						//True if a child is added.	

   //
	//Populate Network neighbourhood tree (Entire network and Local-Computers)
	//
	if (hParent == m_hNetworkRoot)
	{
		bGotChildren = EnumNetwork(hParent);
	}
	//
	//Network item(Search deep into the network)
	//
	else if (m_ctrlTree.GetItemData(hParent))
	{
		bGotChildren = EnumNetwork(hParent);
	}

	//
	//Remove the [+] if no children
	//
	if (!bGotChildren)
	{
		TVITEM item = { 0 };
		item.mask = TVIF_HANDLE | TVIF_CHILDREN;
		item.hItem = hParent;
		item.cChildren = 0;
		m_ctrlTree.SetItem(&item);
	}
	return bGotChildren;
}

CString CBrowseNetworkServers::GetItemPath(HTREEITEM hItem)
{
	TRACE(_T("CBrowseNetworkServers::GetItemPath(%p)\n"), hItem);
	CString sRet;
	do
	{
		if (!hItem) break;

		//End with a share name.
		NETRESOURCE* const pNetResource = (NETRESOURCE*)(m_ctrlTree.GetItemData(hItem));
		if (pNetResource)
		{
			sRet = CString(pNetResource->lpRemoteName) + _T('\\') + sRet;
			break;
		}
		//Add the directory name to the path.
		sRet = m_ctrlTree.GetItemText(hItem) + _T('\\') + sRet;
		hItem = m_ctrlTree.GetParentItem(hItem);
	} while (hItem);

	return sRet;
}

CString WindowName(CString sName)
{
	CString sRet;
	//Scan all charactors to determine if their are any lower case items
	for (int n = 0; n < sName.GetLength(); n++)
	{
		TCHAR ch = sName[n];
		if ((ch >= 'a') && (ch <= 'z'))
			return sName;
	}
	sName.MakeLower();
	if (sName.GetLength() > 0)
	{
		CString sFirstChar = CString(sName[0]);
		sFirstChar.MakeUpper();
		sName = sFirstChar + sName.Mid(1);
	}
	return sName;
}

TCHAR* MakeObjectDynamic(LPTSTR szData)
{
	TRACE(_T("MakeObjectDynamic( %s )\n"), szData);
	//Assume a NULL = empty string
	TCHAR* szRet = NULL;
	int nLength = 0;
	if (szData)
		nLength = _tcslen(szData) + 1;
	if (nLength > 0)
	{
		szRet = new TCHAR[nLength];
		ASSERT(szRet);
		_tcscpy_s(szRet, nLength,szData);
	}
	return szRet;
}