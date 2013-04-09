
// DESProjectDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDESProjectDlg �Ի���



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


// CDESProjectDlg ��Ϣ�������

BOOL CDESProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// Initialize Mode
	ModeCComboBox.InsertString(0,  _T("Encryption"));
	ModeCComboBox.InsertString(1, _T("Decryption"));
	ModeCComboBox.InsertString(2, _T("Check"));
	ModeCComboBox.SetCurSel(0);

	// Initialize keyMode
	KeyModeCComboBox.InsertString(0, _T("FILE"));
	KeyModeCComboBox.InsertString(1, _T("TEXT"));
	KeyModeCComboBox.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDESProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
