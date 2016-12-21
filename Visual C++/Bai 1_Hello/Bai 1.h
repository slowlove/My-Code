// Bai 1.h : main header file for the BAI 1 application
//

#if !defined(AFX_BAI1_H__A37DB70A_9E50_462E_99F9_4CF44BE2F75A__INCLUDED_)
#define AFX_BAI1_H__A37DB70A_9E50_462E_99F9_4CF44BE2F75A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBai1App:
// See Bai 1.cpp for the implementation of this class
//

class CBai1App : public CWinApp
{
public:
	CBai1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBai1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI1_H__A37DB70A_9E50_462E_99F9_4CF44BE2F75A__INCLUDED_)
