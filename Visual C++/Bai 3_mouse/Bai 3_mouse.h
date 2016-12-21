// Bai 3_mouse.h : main header file for the BAI 3_MOUSE application
//

#if !defined(AFX_BAI3_MOUSE_H__3DB623BA_C811_4638_9C8F_12C1DA4779AE__INCLUDED_)
#define AFX_BAI3_MOUSE_H__3DB623BA_C811_4638_9C8F_12C1DA4779AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBai3_mouseApp:
// See Bai 3_mouse.cpp for the implementation of this class
//

class CBai3_mouseApp : public CWinApp
{
public:
	CBai3_mouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai3_mouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBai3_mouseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI3_MOUSE_H__3DB623BA_C811_4638_9C8F_12C1DA4779AE__INCLUDED_)
