// Bai 1Dlg.h : header file
//

#if !defined(AFX_BAI1DLG_H__49A4370A_EC76_46FB_BFEC_1793E4F4A50A__INCLUDED_)
#define AFX_BAI1DLG_H__49A4370A_EC76_46FB_BFEC_1793E4F4A50A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBai1Dlg dialog

class CBai1Dlg : public CDialog
{
// Construction
public:
	CBai1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBai1Dlg)
	enum { IDD = IDD_BAI1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBai1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI1DLG_H__49A4370A_EC76_46FB_BFEC_1793E4F4A50A__INCLUDED_)
