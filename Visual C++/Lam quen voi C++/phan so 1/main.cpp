#include <iostream.h>
/*-----------------------*/
class phanso
{
private:
	int tu,mau;
public:
	phanso(){tu=0;mau=0;}
	phanso(int tuso,int mauso){tu=tuso;mau=mauso;}
	void nhap(void);
	void hienthi(phanso);
	void cong(phanso,phanso);
	friend bool error(phanso);
	friend phanso toigian(phanso);
};
/*------------------*/
void phanso::nhap(void)
{
	cout<<"Xin moi nhap gia tri cho phan so:\n";
	cout<<"tu so:  ";cin>>tu;
	cout<<"------------\n";
	cout<<"mau so: ";cin>>mau;
}
void phanso::hienthi(phanso a)
{
	cout<<a.tu<<"/"<<a.mau;
}
void phanso::cong(phanso a,phanso b)
{
	tu=a.tu*b.mau+b.tu*a.mau;
	mau=a.mau*b.mau;
}
/*------------------------------*/
bool error(phanso a)
{
	if(a.mau==0)
	{
		cout<<"Syntax Error:mau so phai #0,xin moi ban nhap lai !";
		cout<<"\n=====================\n";
		return 1;
	}
	else return 0;
}
phanso toigian(phanso a)
{
	int dem;
	if((a.mau!=0)&&(a.tu==a.mau))a.tu=a.mau=1;
	if(a.tu>a.mau)
	{
		for(dem=1;dem<=a.mau;++dem)
		{
			if((a.tu%dem==0)&&(a.mau%dem==0)){a.tu=a.tu/dem;a.mau=a.mau/dem;}
		}
	}
	if(a.tu<a.mau)
	{
		for(dem=1;dem<=a.tu;++dem)
		{
			if((a.tu%dem==0)&&(a.mau%dem==0)){a.tu=a.tu/dem;a.mau=a.mau/dem;}
		}
	}
	return a;
}
/*------------------------------------*/
void main(void)
{
	while(true)
	{
	phanso x,y,tong;
	x.nhap();
	y.nhap();
	tong.cong(x,y);
	if(error(tong))continue;	//neu mau so==0 thi bao loi va nhap lai
	tong=toigian(tong);
	cout<<"Thuc hien phep tinh: ";
	x.hienthi(x);cout<<"+";y.hienthi(y);cout<<"=";
	tong.hienthi(tong);
	cout<<"\n=====================\n";
	}
}
