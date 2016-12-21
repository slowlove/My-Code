#include <iostream>	//khai bao thu vien SD ham cout va cin
#include <conio.h>	//khia boa thu vien ham getch()
using namespace std;
void main()
{
	double n;	//phai khai bao bien n truoc neu khong p khong biet tham chieu den dau
	double &p=n;	//luc nay p giong nhu bi danh cua n=>nhung thao tac tren p va thao tac tren n la nhu nhau
	while(true)
	{
		cout<<"Xin moi nhap vao 1 gia tri cua n"<<endl;
		cin>>n;
		cout<<"Gia tri tham chieu cua p den bien n la:"<<p<<"\n";
	}
}
/*
Neu tham chieu den 1 bien thi phai khai bao tham chieu do nhu la 1 bien
neu tham chieu den 1 hang''''''''''''''''''''''''''''''''''''''''''hang
VD:	const int n;
	const int &p=n;
*/
