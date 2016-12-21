#include <iostream>
#include <string>
//////////////////////////////////
using namespace std;
typedef unsigned int uint;
/*-------------*/
struct strcsv{
	char name[100];
	uint age;
};
/*-----------*/
uint tongsv;
strcsv *ptrsv;
/////////////////////////////////
void menu();
void nhap();
void hienthi();
void htchuoi(char*);
//////////////////////////////////////////////////////////
/*----------------Chuong trinh chinh--------------------*/
//////////////////////////////////////////////////////////
int main()
{
		cout<<"so luong SV can quan ly: ";
		cin>>tongsv;
		ptrsv = new strcsv[tongsv];	//cap phat dong^cho mang cau truc sv
		while(true)
		{
			menu();
		}
		return 0;
}
//////////////////////////////////////////////////////////
/*----------DN cac ham co trong chuong trinh------------*/
//////////////////////////////////////////////////////////
void menu()
{
	uint ct;
	cout<<"1.Nhap vao danh sach SV."<<endl;
	cout<<"2.Hien thi danh sach SV."<<endl;
	cin>>ct;
	switch(ct)
	{
		case 1:nhap();break;
		case 2:hienthi();break;
		default:cout<<"error"<<endl;
	}
}
/*-----------------*/
void nhap()
{
	uint a;
	char temp[10];
	for(a=0;a<tongsv;a++)
	{
		cout<<"Nhap ten SV "<<a+1<<": ";
		cin.get();
		cin.getline(ptrsv[a].name,100);
		cout<<"Nhap tuoi SV "<<a+1<<": ";
		cin.getline(temp,10);
		ptrsv[a].age=atoi(temp);
		cout<<"-----------"<<endl;
	}
}
/*-------------------*/
void hienthi()
{
	uint a=0;
		for(a=0;a<tongsv;a++)
		{
			htchuoi(ptrsv[a].name);		//ptrsv[a].name la` dia chi cua .name
			cout<<"--"<<ptrsv[a].age<<endl;
		}
}
/*--------------------*/
void htchuoi(char *ptr)		//con tro chi' den chuoi~
{
	uint n,b=0;
	n=strlen(ptr);
	for(b=0;b<n;b++)cout<<*(ptr+b);
}
