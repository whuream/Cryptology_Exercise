//MyEdit.h
#ifndef _EDIT_H_BY_OU_
#define _EDIT_H_BY_OU_

class CMyEdit : public CEdit
{
        DECLARE_DYNAMIC(CMyEdit)

protected:
        CString Text;

        // Generated message map functions
        //{{AFX_MSG(CMyEdit)
        afx_msg void OnDropFiles(HDROP hDropInfo);
        afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
        DECLARE_MESSAGE_MAP()
        //}}AFX_MSG

public:
        CMyEdit();
        virtual ~CMyEdit();
};

#endif //_EDIT_H_BY_OU_
