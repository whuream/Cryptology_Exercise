
// MFC2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include"��ͷ.h"

class ClxEdit : public CEdit
{
	 //DECLARE_DYNAMIC(CMyEdit)
public:
ClxEdit();
virtual ~ClxEdit();

protected:
        CString Text;

        // Generated message map functions
        //{{AFX_MSG(CMyEdit)
        afx_msg void OnDropFiles(HDROP hDropInfo);
     //   afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
       // DECLARE_MESSAGE_MAP()
        //}}AFX_MSG
};


// CMFC2Dlg �Ի���
class CMFC2Dlg : public CDialogEx
{
// ����
public:
	CMFC2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeList2();

	afx_msg void OnLbnSetfocusList2();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnNMThemeChangedCombo1(NMHDR *pNMHDR, LRESULT *pResult);
	CComboBox cbBox;
	afx_msg void OnCbnSetfocusCombo1();
	afx_msg void OnCbnCloseupCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CEdit mEdit;
	CEdit KeyPath;
	CEdit InputPath;
	CEdit OutputPath;
	afx_msg void OnEnChangeEdit3();

	afx_msg void OnDropFiles(HDROP hDropInfo);
	//afx_msg void OnDropFiles(HDROP hDropInfo);
	ClxEdit m_ex1;
	afx_msg void OnEnChangeEdit2();
	CMyEdit m_1;
	afx_msg void OnEnChangeEdit6();
	CMyEdit m_2;
	CMyEdit m_3;
};





