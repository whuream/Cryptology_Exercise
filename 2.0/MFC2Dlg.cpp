
// MFC2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC2.h"
#include "MFC2Dlg.h"
#include "afxdialogex.h"
#include"sources\charshell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2Dlg �Ի���



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



// CMFC2Dlg ��Ϣ�������

BOOL CMFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	cbBox.InsertString(0,_T("En"));
	cbBox.InsertString(1,_T("Des"));
	cbBox.InsertString(2,_T("Ch"));
	cbBox.SetCurSel(0);


	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC2Dlg::OnPaint()
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
HCURSOR CMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC2Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CMFC2Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFC2Dlg::OnLbnSelchangeList2()
{
	((CListBox*)GetDlgItem(IDC_LIST2))->AddString(_T("��kkk��"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnLbnSetfocusList2()
{
	((CListBox*)GetDlgItem(IDC_LIST2))->AddString(_T("����"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnNMThemeChangedCombo1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMFC2Dlg::OnCbnSetfocusCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnCbnCloseupCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	/*
#1015
	*/
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	
//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	/*
#1015
	*/
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFC2Dlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
