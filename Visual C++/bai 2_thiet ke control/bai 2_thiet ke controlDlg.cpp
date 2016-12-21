// bai 2_thiet ke controlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bai 2_thiet ke control.h"
#include "bai 2_thiet ke controlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBai2_thietkecontrolDlg dialog

CBai2_thietkecontrolDlg::CBai2_thietkecontrolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBai2_thietkecontrolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBai2_thietkecontrolDlg)
	m_strMessage = _T("");
	m_strProgToRun = _T("");
	m_bEnableMsg = FALSE;
	m_bEnablePgm = FALSE;
	m_bShowMsg = FALSE;
	m_bShowPgm = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBai2_thietkecontrolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBai2_thietkecontrolDlg)
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_CBString(pDX, IDC_PROGTORUN, m_strProgToRun);
	DDX_Check(pDX, IDC_CKENBLMSG, m_bEnableMsg);
	DDX_Check(pDX, IDC_CKENBLPGM, m_bEnablePgm);
	DDX_Check(pDX, IDC_CKSHWMSG, m_bShowMsg);
	DDX_Check(pDX, IDC_CKSHWPGM, m_bShowPgm);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBai2_thietkecontrolDlg, CDialog)
	//{{AFX_MSG_MAP(CBai2_thietkecontrolDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_SHWMSG, OnShwmsg)
	ON_EN_CHANGE(IDC_MSG, OnChangeMsg)
	ON_BN_CLICKED(IDC_CLRMSG, OnClrmsg)
	ON_BN_CLICKED(IDC_CKENBLMSG, OnCkenblmsg)
	ON_BN_CLICKED(IDC_DFLTMSG, OnDfltmsg)
	ON_BN_CLICKED(IDC_CKSHWMSG, OnCkshwmsg)
	ON_BN_CLICKED(IDC_RUNPGM, OnRunpgm)
	ON_BN_CLICKED(IDC_CKENBLPGM, OnCkenblpgm)
	ON_BN_CLICKED(IDC_CKSHWPGM, OnCkshwpgm)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_ANIMATE1, OnOutofmemoryAnimate1)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, OnFieldchangedIpaddress1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_PROGRESS1, OnOutofmemoryProgress1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBai2_thietkecontrolDlg message handlers

BOOL CBai2_thietkecontrolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_strMessage = "Hay dien mesneger vao day !";
	m_bShowMsg = true;
    m_bShowPgm = true;
    m_bEnableMsg = true;
    m_bEnablePgm = true;
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBai2_thietkecontrolDlg::OnPaint() 
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
HCURSOR CBai2_thietkecontrolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBai2_thietkecontrolDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CBai2_thietkecontrolDlg::OnShwmsg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	MessageBox(m_strMessage);	
}

void CBai2_thietkecontrolDlg::OnChangeMsg() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

}
/*****************xu li su kien khi nut xoa ki tu duoc kick*********************/
void CBai2_thietkecontrolDlg::OnClrmsg() 
{
	// TODO: Add your control notification handler code here
	m_strMessage = "";
	UpdateData(false);
}
/********************xu li su kien khi kich vao nut cho phep messenger hoat dong************************/
void CBai2_thietkecontrolDlg::OnCkenblmsg() 
{
	// TODO: Add your control notification handler code here
     UpdateData(true);
     // Is the Enable Message Action check box checked?
     if (m_bEnableMsg == true)
     {
         // Yes, so enable all controls that have anything
         // to do with showing the user message
         GetDlgItem(IDC_MSG)	  ->EnableWindow(true);
         GetDlgItem(IDC_SHWMSG)   ->EnableWindow(true);
         GetDlgItem(IDC_DFLTMSG)  ->EnableWindow(true);
         GetDlgItem(IDC_CLRMSG)	  ->EnableWindow(true);
         GetDlgItem(IDC_STATICMSG)->EnableWindow(true);
     }
     else
     {
         // No, so disable all controls that have anything
         // to do with showing the user message
         GetDlgItem(IDC_MSG)	  ->EnableWindow(false);
         GetDlgItem(IDC_SHWMSG)   ->EnableWindow(false);
         GetDlgItem(IDC_DFLTMSG)  ->EnableWindow(false);
         GetDlgItem(IDC_CLRMSG)	  ->EnableWindow(false);
         GetDlgItem(IDC_STATICMSG)->EnableWindow(false);
     }

}

void CBai2_thietkecontrolDlg::OnDfltmsg() 
{
	// TODO: Add your control notification handler code here
	m_strMessage="Hay dien mesneger vao day !";
	UpdateData(false);
	
}
/*****************xu li su kien khi kick vao nut hien thi mesenger*************************/
void CBai2_thietkecontrolDlg::OnCkshwmsg() 
{
	// TODO: Add your control notification handler code here
	   UpdateData(true);
     // Is the Show Message Action check box checked?
     if (m_bShowMsg == true)
     {
         // Yes, so show all controls that have anything
         // to do with showing the user message
         GetDlgItem(IDC_MSG)      ->ShowWindow(true);
         GetDlgItem(IDC_SHWMSG)   ->ShowWindow(true);
         GetDlgItem(IDC_DFLTMSG)  ->ShowWindow(true);
         GetDlgItem(IDC_CLRMSG)   ->ShowWindow(true);
         GetDlgItem(IDC_STATICMSG)->ShowWindow(true);
     }
     else
     {
         // No, so hide all controls that have anything
         // to do with showing the user message
         GetDlgItem(IDC_MSG)	  ->ShowWindow(false);
         GetDlgItem(IDC_SHWMSG)   ->ShowWindow(false);
         GetDlgItem(IDC_DFLTMSG)  ->ShowWindow(false);
         GetDlgItem(IDC_CLRMSG)   ->ShowWindow(false);
         GetDlgItem(IDC_STATICMSG)->ShowWindow(false);
     }
}
/**********xu li sua kien khi an nut chay chuong trinh***********/
void CBai2_thietkecontrolDlg::OnRunpgm() 
{
	// TODO: Add your control notification handler code here
     UpdateData(true);							//cap nhat gia tri tu man hinh
     CString strPgmName;						//tao ra 1 bien cuc bo de luu ten chuong trinh
     strPgmName = m_strProgToRun;				//gan ten chuong trinh vao bien cuc bo
     strPgmName.MakeUpper();					//thay tat ca ten chuong trinh thanh chu hoa
     if (strPgmName == "MAY TINH")				//neu ten chuong trinh la CALC hc may tinh
         WinExec("calc.exe", SW_SHOW);			//chay chuong trinh calc.exe
     if (strPgmName == "NOTEPAD")				//neu ten chuong trinh la NOTEPAD
         WinExec("notepad.exe", SW_SHOW);
	 if	(strPgmName=="CONG CU VE")
		 WinExec("mspaint.exe",SW_SHOW);
	 if ((strPgmName != "NOTEPAD")&&(strPgmName != "CONG CU VE")&&(strPgmName != "MAY TINH")&&(strPgmName != ""))	//neu khong dung bat ki CT nao!
	 MessageBox("Cac ban chi duoc phep chay cac chuong trinh co trong danh sach !","Chu y !");
}
/**********Xu li su kien khi kich nut cho phep thuc hien chuong trinh************/
void CBai2_thietkecontrolDlg::OnCkenblpgm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_bEnablePgm == true)
	{
	 GetDlgItem(IDC_STATICPRG)->EnableWindow(true);
	 GetDlgItem(IDC_PROGTORUN)->EnableWindow(true);
	 GetDlgItem(IDC_RUNPGM)   ->EnableWindow(true);
	}
	else
	{
	 GetDlgItem(IDC_STATICPRG)->EnableWindow(false);
	 GetDlgItem(IDC_PROGTORUN)->EnableWindow(false);
	 GetDlgItem(IDC_RUNPGM)   ->EnableWindow(false);
	}
}
/******Xu li su kien danh dau cho phep hien thi chuong trinh*******/
void CBai2_thietkecontrolDlg::OnCkshwpgm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_bShowPgm == true)
	{
	 GetDlgItem(IDC_STATICPRG)->ShowWindow(true);
	 GetDlgItem(IDC_PROGTORUN)->ShowWindow(true);
	 GetDlgItem(IDC_RUNPGM)   ->ShowWindow(true);
	}
	else
	{
	 GetDlgItem(IDC_STATICPRG)->ShowWindow(false);
	 GetDlgItem(IDC_PROGTORUN)->ShowWindow(false);
	 GetDlgItem(IDC_RUNPGM)   ->ShowWindow(false);
	}	
}



void CBai2_thietkecontrolDlg::OnOutofmemoryAnimate1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CBai2_thietkecontrolDlg::OnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CBai2_thietkecontrolDlg::OnOutofmemoryProgress1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
