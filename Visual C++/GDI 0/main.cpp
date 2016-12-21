#include <windows.h>
LRESULT CALLBACK WndProc ( HWND, UINT, WPARAM, LPARAM );	//khai bao truoc vi trong winmain co SD
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
static TCHAR szAppName [] = TEXT ("Cua so chinh");	//ten ung dung
HWND hwnd;	//handle cua mot window
MSG msg;	//cau truc thong diep
/*------------------------Dinh nghia kieu cua so------------------------*/
WNDCLASS wndclass;	//cau truc lop window
/*de DN cua so nguoi ta xay dung 1 cau truc du lieu (struct) la wndclass,wndclass.xxx la cac truong cau tao len 1 lop cua so bao gom rat nhieu thanh phan */
wndclass.style = CS_HREDRAW|CS_VREDRAW;	//ve lai cua so khi thay doi chieu ngang hoac chieu doc
wndclass.lpfnWndProc = WndProc;
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
/*----------------------------------------------------------------------------*/
/*---------------------------Ham xu li thong diep------------------------*/
LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
HDC hdc;	//handle cua DC(Dvice context-ngu canh thiet bi)
PAINTSTRUCT ps;	//cau truc paint
static POINT pt[100];
static int iCount;
int i,j;
	switch ( msg )
	{
	case WM_LBUTTONDOWN:
		iCount=0;
		InvalidateRect(hwnd,NULL,TRUE);
		return 0;
	case WM_MOUSEMOVE:
		if(wParam & MK_LBUTTON && iCount<100)
		{
			pt[iCount].x=LOWORD(lParam);
			pt[iCount++].y=HIWORD(lParam);
			hdc=GetDC(hwnd);
			SetPixel(hdc,LOWORD(lParam),HIWORD(lParam),0);
			ReleaseDC(hwnd,hdc);
		}
		return 0;
	case WM_LBUTTONUP:
		InvalidateRect(hwnd,NULL,FALSE);
		return 0;
	case WM_PAINT:	//neu thong diep yeu cau ve lai cua so
		hdc = BeginPaint ( hwnd, &ps);
		SetCursor(LoadCursor(NULL,IDC_WAIT));
		ShowCursor(TRUE);
		for(i=0;i<iCount;i++)
			for(j=i;j<iCount;j++)
			{
				MoveToEx(hdc,pt[i].x,pt[i].y,NULL);	//di chuyen toi diem cu
				LineTo(hdc,pt[j].x,pt[j].y);	//ve duong thang toi diem moi
			}
		ShowCursor(FALSE);
		SetCursor(LoadCursor(NULL,IDC_ARROW));
		EndPaint ( hwnd, &ps);
		return 0;
	case WM_DESTROY:	//thong diep huy
		PostQuitMessage (0);return 0;	//dua thong diep thoat vao hang doi thong diep
	}
	return DefWindowProc ( hwnd, msg, wParam, lParam);	/*neu Messenger khong thuoc quan ly cua "cua so" thi tra lai quyen kiem soat cho win*/
}
