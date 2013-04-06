
// MFC2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC2.h"
#include "MFC2Dlg.h"
#include "afxdialogex.h"
#include"sources\charshell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2Dlg 对话框



CMFC2Dlg::CMFC2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, cbBox);
	DDX_Control(pDX, IDC_EDIT1, mEdit);
	DDX_Control(pDX, IDC_EDIT3, KeyPath);
	DDX_Control(pDX, IDC_EDIT4, InputPath);
	DDX_Control(pDX, IDC_EDIT5, OutputPath);
	DDX_Control(pDX, IDC_EDIT2, m_ex1);
	DDX_Control(pDX, IDC_EDIT6, m_1);
	DDX_Control(pDX, IDC_EDIT7, m_2);
	DDX_Control(pDX, IDC_EDIT8, m_3);
}

BEGIN_MESSAGE_MAP(CMFC2Dlg, CDialogEx)
	ON_WM_DROPFILES()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFC2Dlg::OnBnClickedCancel)
	//ON_LBN_SELCHANGE(IDC_LIST1, &CMFC2Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDOK, &CMFC2Dlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST2, &CMFC2Dlg::OnLbnSelchangeList2)
	ON_LBN_SETFOCUS(IDC_LIST2, &CMFC2Dlg::OnLbnSetfocusList2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFC2Dlg::OnCbnSelchangeCombo1)
	ON_NOTIFY(NM_THEMECHANGED, IDC_COMBO1, &CMFC2Dlg::OnNMThemeChangedCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, &CMFC2Dlg::OnCbnSetfocusCombo1)
	ON_CBN_CLOSEUP(IDC_COMBO1, &CMFC2Dlg::OnCbnCloseupCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC2Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CMFC2Dlg::OnEnChangeEdit3)
	ON_WM_DROPFILES()
	ON_EN_CHANGE(IDC_EDIT2, &CMFC2Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT6, &CMFC2Dlg::OnEnChangeEdit6)
END_MESSAGE_MAP()



// CMFC2Dlg 消息处理程序

BOOL CMFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	cbBox.InsertString(0,_T("En"));
	cbBox.InsertString(1,_T("Des"));
	cbBox.InsertString(2,_T("Ch"));
	cbBox.SetCurSel(0);


	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC2Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFC2Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFC2Dlg::OnLbnSelchangeList2()
{
	((CListBox*)GetDlgItem(IDC_LIST2))->AddString(_T("北kkk京"));
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnLbnSetfocusList2()
{
	((CListBox*)GetDlgItem(IDC_LIST2))->AddString(_T("北京"));
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnNMThemeChangedCombo1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFC2Dlg::OnCbnSetfocusCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnCbnCloseupCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnBnClickedButton1()
{
	int nIndex = cbBox.GetCurSel();
	//MessageBox(
	int a = 0;
	CString s(char(nIndex + '1'));
	mEdit.SetWindowTextW(s);

	int argc = 5;
	char **argv;
	argv = new char*[argc];

	CString keypath;
	CString InputPath;
	CString OutputPath;
	m_1.GetWindowText(keypath);
	m_2.GetWindowText(InputPath);
	m_3.GetWindowText(OutputPath);

	char ctmp[]={"1"};
	
	

	 USES_CONVERSION;
	argv[1] = T2A(s);
	 argv[2] = T2A(keypath);
	argv[3] = T2A(InputPath);
	argv[4] = T2A(OutputPath);
	
	charshell m_shell(argc, argv);
	m_shell.Handle();

	// TODO: 在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	/*
#1015
	*/
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
//#1015

	// TODO:  在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT count;
	TCHAR  filePath[100]={_T("kdjf")};
	LPTSTR o;
	//CDialogEx::OnDropFiles(hDropInfo);
	DragQueryFile(hDropInfo, 0,filePath,sizeof(filePath));

	KeyPath.SetWindowTextW(filePath);

}


ClxEdit::ClxEdit()
{ }

ClxEdit::~ClxEdit()
{ }


void ClxEdit::OnDropFiles(HDROP hDropInfo)
{
// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT count;
	TCHAR  filePath[100]={_T("kdjf")};
	LPTSTR o;
	//CDialogEx::OnDropFiles(hDropInfo);
	DragQueryFile(hDropInfo, 0,filePath,sizeof(filePath));
	this->SetWindowTextW(filePath);
	//KeyPath.SetWindowTextW(filePath);
}


void CMFC2Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	/*
#1015
	*/
	// TODO:  在此添加控件通知处理程序代码
}


void CMFC2Dlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
}
