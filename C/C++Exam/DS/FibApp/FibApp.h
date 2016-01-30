// FibApp.h : main header file for the FIBAPP application
//

#if !defined(AFX_FIBAPP_H__796F0C81_380E_4EC0_8A65_3555C09AC79E__INCLUDED_)
#define AFX_FIBAPP_H__796F0C81_380E_4EC0_8A65_3555C09AC79E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFibAppApp:
// See FibApp.cpp for the implementation of this class
//

class CFibAppApp : public CWinApp
{
public:
	CFibAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFibAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFibAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIBAPP_H__796F0C81_380E_4EC0_8A65_3555C09AC79E__INCLUDED_)
