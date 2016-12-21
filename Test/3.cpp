#include "iostream.h"
#include "string"
////////////////////////////////////////
char mang[100];
int daochuoi(char *ptr)		//con tro chi' den chuoi~
{
	unsigned int m,n=0;
	m=n=strlen(ptr);	//them n de ko anh huong toi m
	for(int b=0;b<n;b++)cout<<*(ptr+(--m));
	return 0;
}
int main()
{
	unsigned int x=0;
	cout<<"Hay nhap 1 chuoi ki tu:";
	cin.getline(mang,100);	//luu chuoi vao mang
	x=strlen(mang);	//Kiem tra do dai cua chuoi
	/*---------------*/
	cout<<"Tong cac ky tu co trong chuoi la`: "<<x<<endl;
	cout<<"Chuoi sau khi dao nguoc lai la`: ";
	daochuoi(mang);
	cout<<endl;
	return 0;
}
