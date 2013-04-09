
// DESProjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DESProject.h"
#include "DESProjectDlg.h"
#include "afxdialogex.h"
#include "sources\charshell.h"
#include<vector>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDESProjectDlg 对话框



CDESProjectDlg::CDESProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDESProjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDESProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, ModeCComboBox);
	DDX_Control(pDX, IDC_BUTTON1, StartCButton);
	DDX_Control(pDX, IDC_EDIT1, KeyPathCEditAcceptFile);
	DDX_Control(pDX, IDC_EDIT2, InputFilePathCEditAcceptFile);
	DDX_Control(pDX, IDC_EDIT3, OutputFilePathCEditAcceptFile);
	//DDX_Control(pDX, IDC_EDIT4, LogCEdit);
	DDX_Control(pDX, IDC_COMBO2, KeyModeCComboBox);
	DDX_Control(pDX, IDC_LIST1, LogListBox);
}

BEGIN_MESSAGE_MAP(CDESProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDESProjectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDESProjectDlg 消息处理程序

BOOL CDESProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// Initialize Mode
	ModeCComboBox.InsertString(0,  _T("Encryption"));
	ModeCComboBox.InsertString(1, _T("Decryption"));
	ModeCComboBox.InsertString(2, _T("Check"));
	ModeCComboBox.SetCurSel(0);

	// Initialize keyMode
	KeyModeCComboBox.InsertString(0, _T("FILE"));
	KeyModeCComboBox.InsertString(1, _T("TEXT"));
	KeyModeCComboBox.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDESProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDESProjectDlg::OnPaint()
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
HCURSOR CDESProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDESProjectDlg::OnBnClickedButton1()
{
	vector<string> data(6);
	bool keymode = false;

	CString cstmp;
	
	data[0] = (char)(ModeCComboBox.GetCurSel() + '1');

	if(KeyModeCComboBox.GetCurSel() == 1)
	{
		keymode = true;
	}

	KeyPathCEditAcceptFile.GetWindowTextW(cstmp);
	data[1] = CStringA(cstmp);

	InputFilePathCEditAcceptFile.GetWindowTextW(cstmp);
	data[2] = CStringA(cstmp);

	OutputFilePathCEditAcceptFile.GetWindowTextW(cstmp);
	data[3] = CStringA(cstmp);

	charshell m_shell;
	
	if( m_shell.Initialize(data, LogListBox, keymode) == true )
	{
		m_shell.Handle();
	}

	// TODO: 在此添加控件通知处理程序代码
}
