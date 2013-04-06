
// MFC2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include"标头.h"

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


// CMFC2Dlg 对话框
class CMFC2Dlg : public CDialogEx
{
// 构造
public:
	CMFC2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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





