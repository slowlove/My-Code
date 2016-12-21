#include <iostream.h>
#include <stdio.h>
#include <conio.h>
/*******************************/
int matran[9][9],m,n;
/*******************************/
void ct1(void)
{
	cout<<"-----nhap vao 1 ma tran m.n:-----"<<endl;
	do cout<<"m=",cin>>m;
	while((m<1)|(m>9));
	do cout<<"n=",cin>>n;
	while((n<1)|(n>9));
	cout<<"Nhap vao cac phan tu cho ma tran:"<<endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cout<<"matran["<<i<<"]["<<j<<"]=",cin>>matran[i][j],cout<<endl;
}
/**********************************/
void ct2(void)
{
	cout<<"-----Ma tran ban da nhap-----"<<endl;
	for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<matran[i][j]<<"  ";
			cout<<endl;
		}
}
/**********************************/
void ct3()
{
	int max=matran[0][0];
	unsigned int count=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(max<matran[i][j])max=matran[i][j];
	cout<<"Gia tri lon nhat trong ma tran la: "<<max<<endl;
	cout<<"vi tri cua gia tri max:"<<endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(matran[i][j]==max)
				{
					cout<<"["<<i<<"]["<<j<<"]"<<endl;
					count++;
				}
	cout<<"So phan tu lon nhat la:"<<count<<endl;
}
/**********************************/
void ct4()
{
	int min=matran[0][0];
	unsigned int count=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(min>matran[i][j])min=matran[i][j];
	cout<<"Gia tri nho nhat trong ma tran la: "<<min<<endl;
	cout<<"vi tri cua gia tri min:"<<endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(matran[i][j]==min)
				{
					cout<<"["<<i<<"]["<<j<<"]"<<endl;
					count++;
				}
	cout<<"So phan tu be nhat la:"<<count<<endl;
}
/*************************************/
void ct5()
{
	if(m==n)
	{
		int t_cheochinh=0;
		for(int i=0;i<m;i++)
			t_cheochinh+=matran[i][i];
		cout<<"Tong cac phan tu tren duong cheo chinh:"<<t_cheochinh<<endl;
	}
	else cout<<"Day ko phai la 1 ma tran vuong !"<<endl;
}
/**************************************/
void ct6()
{
	if(m==n)
	{
		int t_cheophu=0;
		for(int i=0;i<n;i++)
			t_cheophu+=matran[i][n-1-i];
		cout<<"Tong cac phan tu tren duong cheo phu:"<<t_cheophu<<endl;
	}
	else cout<<"Day ko phai la 1 ma tran vuong !"<<endl;	
}
/************************************/
void menu(void)
{
	unsigned int ct;
	cout<<"-----Chon chuong trinh tuong ung-----"<<endl;
	cout<<"1-Nhap vao 1 ma tran [m].[n]"<<endl;
	cout<<"2-Hien thi ma tran da nhap"<<endl;
	cout<<"3-Tim phan tu lon nhat trong ma tran"<<endl;
	cout<<"4-Tim phan tu nho nhat trong ma tran"<<endl;
	cout<<"5-Tong duong cheo chinh"<<endl;
	cout<<"6-Tong duong cheo phu"<<endl;
	cout<<"-------------------------------------"<<endl;
	cin>>ct;
	switch(ct)
	{
		case 1:ct1();break;
		case 2:ct2();break;
		case 3:ct3();break;
		case 4:ct4();break;
		case 5:ct5();break;
		case 6:ct6();break;
		default:cout<<"error"<<endl;
	}
}
////////////////////////////////////////////////////////////////
int main()
{
	while(true)menu();
	getch();
	return 0;
}	
