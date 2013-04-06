//MyEdit.cpp

#include "StdAfx.h"
#include"БъЭЗ.h"

IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
//{{AFX_MSG_MAP(CDlgName)
        ON_WM_DROPFILES()
       // ON_WM_VSCROLL()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CMyEdit::CMyEdit()
{
}

CMyEdit::~CMyEdit()
{
}

void CMyEdit::OnDropFiles(HDROP hDropInfo)
{
     UINT count;
	TCHAR  filePath[100]={_T("kdjf")};
	LPTSTR o;
	//CDialogEx::OnDropFiles(hDropInfo);
	DragQueryFile(hDropInfo, 0,filePath,sizeof(filePath));
	this->SetWindowTextW(filePath);
	//KeyPath.SetWindowTextW(filePath);
}