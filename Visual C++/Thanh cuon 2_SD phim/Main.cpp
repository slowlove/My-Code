#include <windows.h>
#include "sysmets.h"
LRESULT CALLBACK Xulithongdiep ( HWND, UINT, WPARAM, LPARAM );	//khai bao truoc vi trong winmain co SD
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	static TCHAR szAppName [] = TEXT ("Cua so chinh");	//ten ung dung
	HWND hwnd;	//handle cua mot window
	MSG msg;	//cau truc thong diep
	/*------------------------Dinh nghia kieu cua so------------------------*/
	WNDCLASS wndclass;	//cau truc lop window
	/*de DN cua so nguoi ta xay dung 1 cau truc du lieu (struct) la wndclass,wndclass.xxx la cac truong cau tao len 1 lop cua so bao gom rat nhieu thanh phan */
	wndclass.style = CS_HREDRAW|CS_VREDRAW;	//ve lai cua so khi thay doi chieu ngang hoac chieu doc
	wndclass.lpfnWndProc = Xulithongdiep;	//giao nhiem vu xu li thong diep cho ham xulithongdiep(WndProc)
	wndclass.cbClsExtra =0;
	wndclass.cbWndExtra =0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon ( NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor ( NULL, IDC_ARROW);
	wndclass.hbrBackground =(HBRUSH)GetStockObject ( WHITE_BRUSH);	//to hinh nen la mau trang
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	/*-------Dang ki lop cua so--------*/
	if ( !RegisterClass ( &wndclass ) )		//neu viec dang ky cua so that bai
	{
		MessageBox(NULL, TEXT ("Chuong trinh nay chi chay tren Windows XP"),szAppName,MB_ICONERROR);	
		return 0;
	}
	/*-----Tao lap cua so bang ham CreatWindows-----*/
	hwnd = CreateWindow (
		szAppName,	//Ten cua so da dang ky
		TEXT (" Chuong trinh dialog cua Slowlove"),	//ten tieu de(Title)cua cua so
		WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL,	//kieu cua so thong thuong(co du cac chuc nang phong to thu nho)
		//hien thi giua man hinh(1440*900)
		(1440-500)/2,	//toa do ban dau theo x(mac dinh co tham so la CW_USEDEFAULT)
		(900-300)/2,	//toa do ban dau theo y(mac dinh co tham so la CW_USEDEFAULT)
		//co kich thuoc 500x300
		500,	//size chieu ngang ban dau(mac dinh co tham so la CW_USEDEFAULT)
		300,	//size chieu doc ban dau(mac dinh co tham so la CW_USEDEFAULT)
		NULL,	//handle cua so cha
		NULL,	//handle danh menu
		hInstance, //handle the hien cua chuong trinh
		NULL ); //Thong so tao
	/*-----Hien thi cua so------*/
	ShowWindow (hwnd, iCmdShow );
	UpdateWindow ( hwnd );
	/*----Vong lap xu li thong diep------*/
	while ( GetMessage ( &msg, NULL, 0, 0) )
	{
		TranslateMessage (&msg);	//Dich mot so thong diep chuot & ban phim
		DispatchMessage (&msg) ;	//Gui mot thong diep den mot thu tuc windows
	} 
	return msg.wParam;
} // End WinMain
/*-----------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------Ham xu li thong diep-----------------------------------------------*/
/*-----------------------------------------------------------------------------------------------------------------*/
LRESULT CALLBACK Xulithongdiep (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static int cxChar,cxCaps,cyChar;
	static int cxClient,cyClient,iMAxWidth;
	int i,x,y,iVertPos,iHrozPos,iPaintBeg,iPaintEnd;
	HDC hdc;	//handle cua DC(Dvice context-ngu canh thiet bi)
	TEXTMETRIC tm;
	PAINTSTRUCT ps;	//cau truc paint
	SCROLLINFO si;	//Cau truc scrooll
	switch ( msg )
	{
	case WM_CREATE:	//thong diep khoi tao
		hdc=GetDC(hwnd);
		GetTextMetrics(hdc,&tm);
		cxChar=tm.tmAveCharWidth;
		cxCaps=(tm.tmPitchAndFamily & 1 ? 3 : 2)*cxChar/2;
		cyChar=tm.tmHeight+tm.tmExternalLeading;
		ReleaseDC(hwnd,hdc);
		/*-------------Luu chieu rong cua 3 cot---------*/
		iMAxWidth=40*cxChar+22*cxCaps;
		return 0;
		//////////////////////////////////////////////////////////////////////
	case WM_SIZE:
		cxClient=LOWORD(lParam);	//cac gia tri khi thay doi kick thuoc cua vung cua so
		cyClient=HIWORD(lParam);
		/*----Dat lai vung kick thuoc cua thanh cuon doc----*/
		si.cbSize=sizeof(si);
		si.fMask=SIF_RANGE|SIF_PAGE;
		si.nMin=0;
		si.nMax=NUMLINES-1;
		si.nPage=cyClient/cyChar;	//kick thuoc trang bang chieu cao cua cua so/chieu cao ki tu
		SetScrollInfo(hwnd,SB_VERT,&si,TRUE);
		/*----Dat lai vung kick thuoc cua thanh cuon ngang----*/
		si.cbSize=sizeof(si);
		si.fMask=SIF_RANGE|SIF_PAGE;
		si.nMin=0;
		si.nMax=2+iMAxWidth/cxChar;
		si.nPage=cxClient/cxChar;	//kick thuoc trang bang chieu rong cua cua so/chieu rong ki tu
		SetScrollInfo(hwnd,SB_HORZ,&si,TRUE);
		return 0;
		/////////////////////////////////////////////////////////////////////
	case WM_VSCROLL:	//Thong diep xu li thanh cuon doc
		/*-------Lay tat ca thong tin thanh cuon doc------*/
		si.cbSize=sizeof(si);
		si.fMask=SIF_ALL;
		GetScrollInfo(hwnd,SB_VERT,&si);
		/*---------------------------------*/
		iVertPos=si.nPos;	//Luu vi tri de so sanh
		switch (LOWORD(wParam))	//Xu li nhung tac dong cua chuot tren thanh cuon(doc)
		{
		case SB_TOP:si.nPos=si.nMin;break;
		case SB_BOTTOM:si.nPos=si.nMax;break;
		case SB_LINEUP:si.nPos-=1;break;
		case SB_LINEDOWN:si.nPos+=1;break;
		case SB_PAGEUP:si.nPos-=si.nPage;break;
		case SB_PAGEDOWN:si.nPos+=si.nPage;break;
		case SB_THUMBTRACK:si.nPos=si.nTrackPos;break;
		}
		si.fMask=SIF_POS;
		SetScrollInfo(hwnd,SB_VERT,&si,TRUE);
		GetScrollInfo(hwnd,SB_VERT,&si);
		/*--------Neu thay doi,cuon cua so roi cap ngat no---------*/
		if(si.nPos!=iVertPos)
		{
			ScrollWindow(hwnd,0,cyChar*(iVertPos-si.nPos),NULL,NULL);
			UpdateWindow(hwnd);
		}
		return 0;
		/////////////////////////////////////////////////////////////////////
	case WM_HSCROLL:	//Thong diep xu li thanh cuon ngang
		/*-------Lay tat ca thong tin thanh cuon ngang------*/
		si.cbSize=sizeof(si);
		si.fMask=SIF_ALL;
		GetScrollInfo(hwnd,SB_HORZ,&si);
		/*---------------------------------*/
		iHrozPos=si.nPos;	//Luu vi tri de so sanh
		switch (LOWORD(wParam))	//Xu li nhung tac dong cua chuot tren thanh cuon(ngang)
		{
		case SB_LEFT:si.nPos=si.nMin;break;
		case SB_RIGHT:si.nPos=si.nMax;break;
		case SB_LINELEFT:si.nPos-=1;break;
		case SB_LINERIGHT:si.nPos+=1;break;
		case SB_PAGELEFT:si.nPos-=si.nPage;break;
		case SB_PAGERIGHT:si.nPos+=si.nPage;break;
		case SB_THUMBPOSITION:si.nPos=si.nTrackPos;break;
		}
		si.fMask=SIF_POS;
		SetScrollInfo(hwnd,SB_HORZ,&si,TRUE);
		GetScrollInfo(hwnd,SB_HORZ,&si);
		if(si.nPos!=iHrozPos)
		{
			ScrollWindow(hwnd,0,cxChar*(iHrozPos-si.nPos),NULL,NULL);
			UpdateWindow(hwnd);
		}
		return 0;
		//////////////////////////////////////////////////////////////////////
	case WM_KEYDOWN:	//Xu li thong diep khi nhan phim
		switch(wParam)
		{
		case VK_HOME:SendMessage(hwnd,WM_VSCROLL,SB_TOP,0);break;
		case VK_END:SendMessage(hwnd,WM_VSCROLL,SB_BOTTOM,0);break;
		case VK_PRIOR:SendMessage(hwnd,WM_VSCROLL,SB_PAGEUP,0);break;
		case VK_NEXT:SendMessage(hwnd,WM_VSCROLL,SB_PAGEDOWN,0);break;
		case VK_UP:SendMessage(hwnd,WM_VSCROLL,SB_LINEUP,0);break;
		case VK_DOWN:SendMessage(hwnd,WM_VSCROLL,SB_LINEDOWN,0);break;
		case VK_LEFT:SendMessage(hwnd,WM_HSCROLL,SB_PAGELEFT,0);break;
		case VK_RIGHT:SendMessage(hwnd,WM_HSCROLL,SB_PAGERIGHT,0);break;
		}
		return 0;
		//////////////////////////////////////////////////////////////////////
	case WM_PAINT:	//xxu  li thong diep yeu cau ve lai cua so
		hdc = BeginPaint ( hwnd, &ps);
		/*-----Lay vi tri thanh cuon doc------*/
		si.cbSize=sizeof(si);
		si.fMask=SIF_POS;
		GetScrollInfo(hwnd,SB_VERT,&si);
		iVertPos=si.nPos;
		/*-----Lay vi tri thanh cuon ngang-------*/
		GetScrollInfo(hwnd,SB_HORZ,&si);
		iHrozPos=si.nPos;
		/*-----Tim gioi han ve-----*/
		iPaintBeg=max(0,iVertPos+ps.rcPaint.top/cyChar);
		iPaintEnd=min(NUMLINES-1,iVertPos+ps.rcPaint.bottom/cyChar);
		for (i=iPaintBeg;i<=iPaintEnd;i++)
		{
			x=cxChar*(1-iHrozPos);
			y=cyChar*(1-iVertPos);
			TextOut(hdc,x,y,sysmetrics[i].szLabel,lstrlen(sysmetrics[i].szLabel));
			TextOut(hdc,x+22*cxCaps,y,sysmetrics[i].szDesc,lstrlen(sysmetrics[i].szDesc));
		}
		EndPaint ( hwnd, &ps);
		return 0;
		//////////////////////////////////////////////////////////////////////
	case WM_DESTROY:	//thong diep huy
		PostQuitMessage (0);return 0;	//dua thong diep thoat vao hang doi thong diep
		//////////////////////////////////////////////////////////////////////
	}
	return DefWindowProc ( hwnd, msg, wParam, lParam);	/*neu Messenger khong thuoc quan ly cua "cua so" thi tra lai quyen kiem soat cho win*/
}