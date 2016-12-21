// bai 2_thiet ke control.h : main header file for the BAI 2_THIET KE CONTROL application
//

#if !defined(AFX_BAI2_THIETKECONTROL_H__D4AC144F_609B_4B22_9182_B802A82E64FA__INCLUDED_)
#define AFX_BAI2_THIETKECONTROL_H__D4AC144F_609B_4B22_9182_B802A82E64FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBai2_thietkecontrolApp:
// See bai 2_thiet ke control.cpp for the implementation of this class
//

class CBai2_thietkecontrolApp : public CWinApp
{
public:
	CBai2_thietkecontrolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai2_thietkecontrolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBai2_thietkecontrolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI2_THIETKECONTROL_H__D4AC144F_609B_4B22_9182_B802A82E64FA__INCLUDED_)
