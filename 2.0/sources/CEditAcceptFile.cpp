// File name: CEditAcceptFile.cpp
// Copyright (C) Ream
// All rights reserved.

#include"CEditAcceptFile.h"

BEGIN_MESSAGE_MAP(CEditAcceptFile, CEdit)
        ON_WM_DROPFILES()
END_MESSAGE_MAP()

CEditAcceptFile::CEditAcceptFile()
{
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

	delete[] filePath;

	filePath = 0;
}