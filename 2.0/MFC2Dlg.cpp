// MFC2Dlg.cpp : 实现文件

#include "MFC2Dlg.h"

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

	DDX_Control(pDX, IDC_EDIT6, m_1);
	DDX_Control(pDX, IDC_EDIT7, m_2);
	DDX_Control(pDX, IDC_EDIT8, m_3);
	DDX_Control(pDX, IDC_COMBO2, CComBox1);
	DDX_Control(pDX, IDC_COMBO3, CComboBox2);
	DDX_Control(pDX, IDC_COMBO4, CComBoBox3);
	DDX_Control(pDX, IDC_EDIT1, CEditlog);
}

BEGIN_MESSAGE_MAP(CMFC2Dlg, CDialogEx)
	ON_WM_DROPFILES()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CMFC2Dlg::OnBnClickedButton1)
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

	CString text(_T("TEXT"));
	CString file(_T("FILE"));

	CComBox1.InsertString(0, text);
	CComBox1.InsertString(1, file);
	CComBox1.SetCurSel(0);

	CComboBox2.InsertString(0, text);
	CComboBox2.InsertString(1, file);
	CComboBox2.SetCurSel(0);
	
	CComBoBox3.InsertString(0, text);
	CComBoBox3.InsertString(1, file);
	CComBoBox3.SetCurSel(0);


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

void CMFC2Dlg::OnBnClickedButton1()
{
	int nIndex = cbBox.GetCurSel();
	CString s(char(nIndex + '1'));
	
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