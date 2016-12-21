#include "iostream.h"
#include "string"
////////////////////////////////////////
char mang[100];
char* daochuoi(char *str)		//con tro chi' den chuoi~
{
	unsigned int m,n=0;
	m=n=strlen(str);	//them n de ko anh huong toi m
	char *invert =new char[n];
	for(int b=0;b<=n;b++)invert[b]=*(str+(--m));
	return invert;
}
int main()
{
	unsigned int x=0;
	cout<<"Hay nhap 1 chuoi ki tu:";
	cin.getline(mang,100);	//luu chuoi vao mang
	x=strlen(mang);	//Kiem tra do dai cua chuoi
	/*---------------*/
	cout<<"Tong cac ky tu co trong chuoi la`: "<<x<<endl;
	cout<<"Chuoi sau khi dao nguoc lai la`: "<<daochuoi(mang)<<endl;
	return 0;
}
