/*----------------------------------------------------------------------*/
/*Chuong trinh`Quan ly SV theo Ten va`tuoi,co'chuc nang loc rieng ho-ten*/
/*----------------------------------------------------------------------*/
#include <iostream>
#include <string>
//////////////////////////////////
using namespace std;
typedef unsigned int uint;
/*-------------*/
struct strcsv{
	char fullname[100];
	uint age;};
/*-----------*/
uint tongsv;
strcsv *ptrsv;
/////////////////////////////////////////////////////////
void menu();
void nhap();
void hienthi();
void hienthi_ht();
void tach_ht(strcsv*);
void htchuoi(char*);
char* std_chuoi(char*,char);
//////////////////////////////////////////////////////////
/*----------------Chuong trinh chinh--------------------*/
//////////////////////////////////////////////////////////
int main()
{
		cout<<"so luong SV can quan ly: ";
		cin>>tongsv;
		ptrsv = new strcsv[tongsv];	//cap phat dong^cho mang cau truc sv
		while(true)menu();
		return 0;
}
//////////////////////////////////////////////////////////
/*----------DN cac ham co trong chuong trinh------------*/
//////////////////////////////////////////////////////////
void menu()
{
	uint ct;
	cout<<"1.Nhap vao danh sach SV."<<endl;
	cout<<"2.Hien thi danh sach ten-tuoi SV."<<endl;
	cout<<"3.Hien thi Ho va Ten SV doc lap."<<endl;
	cin>>ct;
	cin.ignore(1);	//bo qua "ENTER"
	switch(ct)
	{
		case 1:nhap();break;
		case 2:hienthi();break;
		case 3:hienthi_ht();break;
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
		cin.getline(ptrsv[a].fullname,100);
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
			htchuoi(std_chuoi(ptrsv[a].fullname,' '));
			//ptrsv[a].name la`dia chi cua .name
			cout<<"/"<<ptrsv[a].age<<endl;
		}
}
/*--------------------*/
void hienthi_ht()
{
	uint a=0;
	for(a=0;a<tongsv;a++)tach_ht(ptrsv+a);
}
/*--------------------*/
void htchuoi(char *ptr)		//con tro chi' den chuoi~
{
	uint n,b;
	n=strlen(ptr);
	for(b=0;b<n;b++)cout<<*(ptr+b);
}
/*---------------------*/
char* std_chuoi(char *begin,char c)	//Ham chuan hoa chuoi~
{
	uint a;
	char *b;
	//Loai bo nhung~ki tu dac biet
	a=0;
	while(*(begin+a)!='\0')
	{
		b=begin+a;
		if((*b<'A'|*b>'Z')&(*b<'a'|*b>'z')& *b!=' ')*b=' ';
		a++;
	}
	//xoa khoang trang 2 dau
	char *end=begin+strlen(begin);
	while(*begin==' ')begin++;
	while((*end==' ')|(*end=='\0'))end--;
	*(++end)='\0';	//tao null cuoi'chuoi~
	//xoa ki tu trung`(space)
	a=0;
	while(*(begin+a)!='\0')
	{
		b=begin+a;
		while(*b==c && *(b+1)==c)memmove(b,b+1,strlen(b));
		a++;
	}
	return begin;
}
/*--------------------*/
void tach_ht(strcsv *sv)
{
	char *begin,*end,*t,*p;
	char tmp_fullname[100];
	uint space=0;
	//---------------------//
	begin=strcpy(tmp_fullname,std_chuoi((*sv).fullname,' '));
	end=begin+strlen(begin);	//tro' den phan tu cuoi chuoi~
	for(t=end-1;t>begin && space<2;t--)	//duyet tu`cuoi'chuoi~
		if(*t==' ')
		{
			space++;
			if(space==1)
			{
				*t='\0';	//cat cho~nay`
				p=t+1;
			}
		}
	if(space==0)cout<<"ten:"<<begin<<endl;
	else cout<<"(ho//ten):"<<begin<<"//"<<p<<endl;
}
//////////////////////////////////////////////////////////
