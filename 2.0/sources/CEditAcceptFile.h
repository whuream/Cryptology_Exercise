// File name: CEditAcceptFile.h
// Copyright (C) Ream
// All rights reserved.


#ifndef _EDIT_H_BY_OU_
#define _EDIT_H_BY_OU_

#include "../stdafx.h"


class CEditAcceptFile : public CEdit
{
public:
        CEditAcceptFile();
        virtual ~CEditAcceptFile();

		void SetNext(CEditAcceptFile *_next){next = _next;}

protected:
        afx_msg void OnDropFiles(HDROP hDropInfo);
        
		DECLARE_MESSAGE_MAP()

private:
	CEditAcceptFile *next;
};

#endif //_EDIT_H_BY_OU_