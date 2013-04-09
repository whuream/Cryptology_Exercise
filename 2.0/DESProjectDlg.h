
// DESProjectDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "sources\CEditAcceptFile.h"

// CDESProjectDlg �Ի���
class CDESProjectDlg : public CDialogEx
{
// ����
public:
	CDESProjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DESPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox ModeCComboBox;
	afx_msg void OnBnClickedButton1();
	CButton StartCButton;
	CEditAcceptFile KeyPathCEditAcceptFile;
	CEditAcceptFile InputFilePathCEditAcceptFile;
	CEditAcceptFile OutputFilePathCEditAcceptFile;
	//CEdit LogCEdit;
	CComboBox KeyModeCComboBox;
	CListBox LogListBox;
};
