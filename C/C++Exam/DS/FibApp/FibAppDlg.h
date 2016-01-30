// FibAppDlg.h : header file
//

#if !defined(AFX_FIBAPPDLG_H__62ECBA57_5B91_4200_8E8A_4C5425CAD65A__INCLUDED_)
#define AFX_FIBAPPDLG_H__62ECBA57_5B91_4200_8E8A_4C5425CAD65A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFibAppDlg dialog

class CFibAppDlg : public CDialog
{
// Construction
public:
	int m_fibresult;
	int factorial(int n);
	CFibAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFibAppDlg)
	enum { IDD = IDD_FIBAPP_DIALOG };
	int		m_fibnum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFibAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFibAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnUpdateFibnum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIBAPPDLG_H__62ECBA57_5B91_4200_8E8A_4C5425CAD65A__INCLUDED_)
