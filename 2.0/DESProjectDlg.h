
// DESProjectDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "sources\CEditAcceptFile.h"

// CDESProjectDlg 对话框
class CDESProjectDlg : public CDialogEx
{
// 构造
public:
	CDESProjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DESPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
