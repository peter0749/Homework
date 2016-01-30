// FibAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FibApp.h"
#include "FibAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFibAppDlg dialog

CFibAppDlg::CFibAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFibAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFibAppDlg)
	m_fibnum = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFibAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFibAppDlg)
	DDX_Text(pDX, IDC_FIBNUM, m_fibnum);
	DDV_MinMaxInt(pDX, m_fibnum, 1, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFibAppDlg, CDialog)
	//{{AFX_MSG_MAP(CFibAppDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_UPDATE(IDC_FIBNUM, OnUpdateFibnum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFibAppDlg message handlers

BOOL CFibAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_fibnum = 1;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFibAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFibAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CFibAppDlg::factorial(int n)
{

	if(n<0)
		MessageBox("Please input number greater than 0");
	if(n==0)
		return 1;
	return n*factorial(n-1);
}

/*
void CFibAppDlg::OnOK() 
{
	CDC* pDC(this);
//	COLORREF color = pDC->GetTextColor();
	// TODO: Add extra validation here
	int result = factorial(m_fibnum);
//	GetDlgItem(IDC_FIBRESULT)->SetWindowText((char*)result);
	char s[81];
//	pDC->SetTextColor(RGB(255,0,0));
	wsprintf(s, "TEXT OPTIONS PAGE ");
	pDC->TextOut(20,20,s);
//	pDC->SetTextColor(color);
	wsprintf(s, "Check1 is checked ");
	
	CDialog::OnOK();
}
*/

void CFibAppDlg::OnOK() 
{
	// TODO: Add extra validation here
		m_fibresult = factorial(m_fibnum);

	
	CDialog::OnOK();
}

void CFibAppDlg::OnUpdateFibnum() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here

		m_fibresult = factorial(m_fibnum);
}
