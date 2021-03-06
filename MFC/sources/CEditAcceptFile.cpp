// File name: CEditAcceptFile.cpp
// Copyright (C) Ream
// All rights reserved.
// Description: CEdit control can accept file

#include"CEditAcceptFile.h"

BEGIN_MESSAGE_MAP(CEditAcceptFile, CEdit)
        ON_WM_DROPFILES()
END_MESSAGE_MAP()

CEditAcceptFile::CEditAcceptFile()
{
	next = 0;
}

CEditAcceptFile::~CEditAcceptFile()
{
}

void CEditAcceptFile::OnDropFiles(HDROP hDropInfo)
{
	TCHAR  *filePath;

	UINT size;

	size = DragQueryFile(hDropInfo, 0,NULL,0);
	
	size ++;

	filePath = new TCHAR[size];

	DragQueryFile(hDropInfo, 0, filePath, sizeof(TCHAR) * size);

	this->SetWindowTextW(filePath);

	if(next != 0)
	{
		next->SetWindowTextW(CString(filePath) + _T(".DES"));
	}

	delete[] filePath;

	filePath = 0;
}