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

protected:
        afx_msg void OnDropFiles(HDROP hDropInfo);
        
		DECLARE_MESSAGE_MAP()
};

#endif //_EDIT_H_BY_OU_