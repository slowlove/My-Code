#include "iostream.h"
#include "string"
////////////////////////////////////////
char mang[100];
unsigned int test(char chuoi[])	//ham kiem tra do dai cua chuoi
{
	unsigned int cout=0;	//khoi tao can thiet
	while(chuoi[cout]!='\0')cout++;
	return cout;
}
int main()
{
	unsigned int x=0;
	cout<<"Hay nhap 1 chuoi ki tu:";
	cin.getline(mang,100);	//luu chuoi vao mang
	x=strlen(mang);	//Kiem tra do dai cua chuoi
	cout<<"Tong cac ky tu co trong chuoi la`:"<<x<<endl;
	return 0;
}
