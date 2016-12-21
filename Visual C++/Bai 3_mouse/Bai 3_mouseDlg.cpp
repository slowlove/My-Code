// Bai 3_mouseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bai 3_mouse.h"
#include "Bai 3_mouseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBai3_mouseDlg dialog

CBai3_mouseDlg::CBai3_mouseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBai3_mouseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBai3_mouseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBai3_mouseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBai3_mouseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBai3_mouseDlg, CDialog)
	//{{AFX_MSG_MAP(CBai3_mouseDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBai3_mouseDlg message handlers

BOOL CBai3_mouseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBai3_mouseDlg::OnPaint() 
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
HCURSOR CBai3_mouseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/*********Xu li su kien khi dua chuot qua vung ung dung***********/
void CBai3_mouseDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	     if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
     {
         // Get the Device Context
         CClientDC dc(this);
		  // Draw a line from the previous point to the current point
         dc.MoveTo(m_iPrevX,m_iPrevY);
         dc.LineTo(point.x,point.y);
 
         // Save the current point as the previous point
         m_iPrevX = point.x;
         m_iPrevY = point.y;
     }
         // Draw the pixel
		CDialog::OnMouseMove(nFlags, point);
}

void CBai3_mouseDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 m_iPrevX = point.x;
     m_iPrevY = point.y;
	CDialog::OnLButtonDown(nFlags, point);
}
/**************Xu li su kien khi bam phim***********/
void CBai3_mouseDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	     char lsChar;        // The current character being pressed
     HCURSOR lhCursor;    // The handle to the cursor to be displayed
 
     // Convert the key pressed to a character
     lsChar = char(nChar);
 
     // Is the character "A"
     if (lsChar == 'A')
     {
         // Load the arrow cursor
         lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
         // Set the screen cursor
         SetCursor(lhCursor);
     }
 
     // Is the character "B"
     if (lsChar == 'B')
   {
       // Load the I beam cursor
         lhCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
         // Set the screen cursor
         SetCursor(lhCursor);
     }
 
     // Is the character "C"
     if (lsChar == 'C')
     {
         // Load the hourglass cursor
         lhCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
         // Set the screen cursor
         SetCursor(lhCursor);
     }
 
     // Is the character "X"
     if (lsChar == 'X')
     {
         // Load the arrow cursor
         lhCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
         // Set the screen cursor
         SetCursor(lhCursor);
         // Exit the application
         OnOK();
     }
	      else
     {
         // Set the cursor flag
         m_bCursor = TRUE;
         // Set the screen cursor
         SetCursor(lhCursor);
     }



	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
/************doi kieu chuot trong khi ve****************/
BOOL CBai3_mouseDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	     CDialog::OnInitDialog();
     // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);            // Set big icon
     SetIcon(m_hIcon, FALSE);        // Set small icon
     // Initialize the cursor to the arrow
     m_bCursor = FALSE;
	 return TRUE;  // return TRUE  unless you set the focus to a control
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
