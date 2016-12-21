#include "iostream.h"
////////////////////////////////////////
char mang[]="Xin chao tat ca cac ban";
unsigned int test(char chuoi[])
{
	unsigned int cout=0;
	while(chuoi[cout]!='\0')cout++;
	return cout;
}
int main()
{
	unsigned int x=test(mang);
	cout<<"Tong cac ky tu co trong chuoi la`:"<<x<<endl;
	return 0;
}
