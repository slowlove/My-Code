// bai 2_thiet ke controlDlg.h : header file
//

#if !defined(AFX_BAI2_THIETKECONTROLDLG_H__93541FAB_D0F9_4D3F_96B5_53188BC1E732__INCLUDED_)
#define AFX_BAI2_THIETKECONTROLDLG_H__93541FAB_D0F9_4D3F_96B5_53188BC1E732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBai2_thietkecontrolDlg dialog

class CBai2_thietkecontrolDlg : public CDialog
{
// Construction
public:
	CBai2_thietkecontrolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBai2_thietkecontrolDlg)
	enum { IDD = IDD_BAI2_THIETKECONTROL_DIALOG };
	CString	m_strMessage;
	CString	m_strProgToRun;
	BOOL	m_bEnableMsg;
	BOOL	m_bEnablePgm;
	BOOL	m_bShowMsg;
	BOOL	m_bShowPgm;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBai2_thietkecontrolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBai2_thietkecontrolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnShwmsg();
	afx_msg void OnChangeMsg();
	afx_msg void OnClrmsg();
	afx_msg void OnCkenblmsg();
	afx_msg void OnDfltmsg();
	afx_msg void OnCkshwmsg();
	afx_msg void OnRunpgm();
	afx_msg void OnCkenblpgm();
	afx_msg void OnCkshwpgm();
	afx_msg void OnOutofmemoryAnimate1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOutofmemoryProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAI2_THIETKECONTROLDLG_H__93541FAB_D0F9_4D3F_96B5_53188BC1E732__INCLUDED_)
