// MFC2Dlg.h : ͷ�ļ�
// Copyright (C) Ream
// All rights reserved.

#pragma once
#include "afxwin.h"
#include "MFC2.h"
#include "afxdialogex.h"
#include "CEditAcceptFile.h"

#include"sources\charshell.h"

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





