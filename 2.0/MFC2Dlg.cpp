// MFC2Dlg.cpp : ʵ���ļ�

#include "MFC2Dlg.h"

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

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}