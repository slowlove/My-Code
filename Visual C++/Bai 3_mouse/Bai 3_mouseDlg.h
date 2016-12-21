// Bai 3_mouseDlg.h : header file
//

#if !defined(AFX_BAI3_MOUSEDLG_H__2B7C3E89_D1F2_479C_B02F_87B389DE291D__INCLUDED_)
#define AFX_BAI3_MOUSEDLG_H__2B7C3E89_D1F2_479C_B02F_87B389DE291D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBai3_mouseDlg dialog

class CBai3_mouseDlg : public CDialog
{
// Construction
public:
	CBai3_mouseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBai3_mouseDlg)
	enum { IDD = IDD_BAI3_MOUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai3_mouseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBai3_mouseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bCursor;
	int m_iPrevY;
	int m_iPrevX;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI3_MOUSEDLG_H__2B7C3E89_D1F2_479C_B02F_87B389DE291D__INCLUDED_)
