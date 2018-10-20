// wc.h : main header file for the WC application
//

#if !defined(AFX_WC_H__3E7BC084_0E2C_4EEB_AAE9_4417CC1DB223__INCLUDED_)
#define AFX_WC_H__3E7BC084_0E2C_4EEB_AAE9_4417CC1DB223__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWcApp:
// See wc.cpp for the implementation of this class
//

class CWcApp : public CWinApp
{
public:
	CWcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WC_H__3E7BC084_0E2C_4EEB_AAE9_4417CC1DB223__INCLUDED_)
