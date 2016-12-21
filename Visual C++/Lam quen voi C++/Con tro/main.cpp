#include <iostream>	//khai bao thu vien SD ham cout va cin
#include <conio.h>	//khia boa thu vien ham getch()
using namespace std;	
//lenh nay co tac dung khai boa cho chuong trinh SD vung std de khong phai danh lai std o dau moi lenh nua
void main()
{
	unsigned int value;
	unsigned char mang[4];	//khai bao 1 mang de luu gia tri cua tung chu so trong value
	unsigned char *p;	//khai bao con tro p co dia chi la dia chi cua gia tri dau tien trong mang
	unsigned int a;
	value=1567;
	p=mang;
	for(a=3;a>=0;a--)
	{
		*(p+a)=value%10;
		value/=10;
	}
	for(a=0;a<4;a++)cout<<mang[a]<<"\n";
	getch();
}