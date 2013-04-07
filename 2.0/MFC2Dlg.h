// MFC2Dlg.h : 头文件
// Copyright (C) Ream
// All rights reserved.

#pragma once
#include "afxwin.h"
#include "MFC2.h"
#include "afxdialogex.h"
#include "CEditAcceptFile.h"

#include"sources\charshell.h"

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
	CComboBox cbBox;
	afx_msg void OnBnClickedButton1();

	CEditAcceptFile m_1;
	CEditAcceptFile m_2;
	CEditAcceptFile m_3;
	CComboBox CComBox1;
	CComboBox CComboBox2;
	CComboBox CComBoBox3;
	CEdit CEditlog;
};





