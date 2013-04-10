// File name: CEditAcceptFile.h
// Copyright (C) Ream
// All rights reserved.
// Description: CEdit control can accept file

#ifndef _EDIT_H_BY_OU_
#define _EDIT_H_BY_OU_

#include "../stdafx.h"


class CEditAcceptFile : public CEdit
{
public:
        CEditAcceptFile();
        virtual ~CEditAcceptFile();

		// set _next
		void SetNext(CEditAcceptFile *_next){next = _next;}

protected:

		// can accept file and show file name in *this and show file name in _next
        afx_msg void OnDropFiles(HDROP hDropInfo);
        
		DECLARE_MESSAGE_MAP()

private:
	CEditAcceptFile *next;
};

#endif //_EDIT_H_BY_OU_