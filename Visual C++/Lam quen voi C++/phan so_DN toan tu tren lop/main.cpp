#include <iostream.h>
/*------------------------------*/
class phanso
{
private:
	int tu,mau;
public:
	phanso(int tuso,int mauso=1){tu=tuso;mau=mauso;}
	phanso(){tu=0;mau=1;}
	void nhap(void);
	void hienthi(void);
	bool error(void);
	/*------Cac ham thanh phan "qua tai ham" toan tu tren lop-----*/
	phanso operator+(phanso);	//phep cong voi 1 ps
	phanso operator-(phanso);
	phanso operator*(phanso);	
	phanso operator/(phanso);
	phanso operator+(int);		//phep cong voi 1 so nguyen
	phanso operator-(int);
	phanso operator*(int);
	phanso operator/(int);
	phanso operator-(void);	//phep dao dau phan so(dau '-' )
	/*---------Cac ham ban----------*/
	friend bool operator==(phanso,phanso);
	friend phanso toigian(phanso &);	//ham ban
};
/*----------DN cac ham thanh phan-----------*/
void phanso::nhap(void)
{
	cout<<"tu: ";cin>>tu;
	cout<<"mau:";cin>>mau;
	cout<<"------\n";
}
void phanso::hienthi(void)
{	
	if(mau==1||tu==0)cout<<tu<<endl;
	if(mau!=0&&mau!=1)cout<<tu<<"/"<<mau<<endl;
}
bool phanso::error(void)
{
	if(mau==0)
	{
		cout<<"Syntax Error:mau so phai #0,xin moi ban nhap lai !\n";
		return 1;
	}
	else return 0;
}
/*-------------DN lai cac ham toan tu tren lop-------------*/
phanso phanso::operator+(phanso a)
{
	phanso c;
	c.tu=tu*a.mau+a.tu*mau;
	c.mau=mau*a.mau;
	return c;
}
phanso phanso::operator-(phanso a)
{
	phanso c;
	c.tu=tu*a.mau-a.tu*mau;
	c.mau=mau*a.mau;
	return c;
}
phanso phanso::operator*(phanso a)
{
	phanso c;
	c.tu=tu*a.tu;
	c.mau=mau*a.mau;
	return c;
}
phanso phanso::operator/(phanso a)
{
	phanso c;
	c.tu=tu*a.mau;
	c.mau=mau*a.tu;
	return c;
}
phanso phanso::operator+(int a)
{
	phanso c;
	c.tu=tu+a*mau;
	c.mau=mau;
	return c;
}
phanso phanso::operator-(int a)
{
	phanso c;
	c.tu=tu-a*mau;
	c.mau=mau;
	return c;
}
phanso phanso::operator*(int a)
{
	phanso c;
	c.tu=tu*a;
	c.mau=mau;
	return c;
}
phanso phanso::operator/(int a)
{
	phanso c;
	c.tu=tu;
	c.mau=a*mau;
	return c;
}
phanso phanso::operator-(void)	//ham DN dau am(dau '-' )
{
	phanso c;
	c.tu=-tu;
	c.mau=mau;
	return c;
}
/*-----------------DN cac ham ban------------------*/
bool operator==(phanso a,phanso b)
{
	toigian(a);
	toigian(b);
	if((a.tu==b.tu)&&(a.mau==b.mau))return 1;
	else return 0;
}
phanso toigian(phanso &a)
{
	int dem;
	if((a.mau!=0)&&(a.tu==a.mau))a.tu=a.mau=1;
	if(a.tu<a.mau)
	{
		int temp;
		for(dem=1;dem<=a.tu;++dem){if((a.tu%dem==0)&&(a.mau%dem==0))temp=dem;}
		a.tu/=temp;
		a.mau/=temp;
	}
	if(a.tu>a.mau)
	{
		int temp;
		for(dem=1;dem<=a.mau;++dem){if((a.tu%dem==0)&&(a.mau%dem==0))temp=dem;}
		a.tu/=temp;
		a.mau/=temp;
	}
	return a;
}
/*---------------------------------------------------------*/
void main(void)
{
	while(true)
	{
	cout<<"***********************************\n";
	cout<<"**   Chuong trinh cong phan so   **\n";
	cout<<"***********************************\n";
	phanso a,b,c,tong;
	a.nhap();b.nhap();c.nhap();	//nhap gia tri cua cac phan so
	tong=a+b+c;
	if(tong.error())continue;	//neu co loi thi nhap lai tu dau
	cout<<"Phan so truoc khi toi gian:  ";
	tong.hienthi();
	toigian(tong);	//ham nay co gia tri tra ve nhung trong CT nay chua dung den
	cout<<"Phan so sau khi toi gian  :  ";
	tong.hienthi();
	(a==b)?cout<<"2 phan so a va b bang nhau.\n":cout<<"2 phan  so a va b khac nhau.\n";
	}
}