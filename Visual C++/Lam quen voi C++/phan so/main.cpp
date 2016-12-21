#include <iostream.h>
#include <conio.h>
/*---------------------------------------*/
class ps{
private:
	int tu,mau;
	void toigian(int tuso,int mauso);
public:
	ps(){mau=1;}
	void nhap(void);
	void cong_ps(void);
	void hienthi(void);
};
/*------------------------------*/
void main(void)
{
	while(true)
	{
		ps a;
		a.nhap();
		a.cong_ps();
		a.hienthi();
	}
}
/*------------------------------*/
void ps::nhap(void)
{
	cout<<"Xin moi nhap cac gia tri cho phan so:\n";
	cout<<"Tu so : ";cin>>tu;
	cout<<"Mau so: ";cin>>mau;
}
void ps::cong_ps(void)
{
	int tuso0,mauso0;
	cout<<"---------------------\n";
	cout<<"Tu so : ";cin>>tuso0;
	cout<<"Mau so: ";cin>>mauso0;
	tu=tu*mauso0+tuso0*mau;
	mau=mau*mauso0;
	toigian(tu,mau);
}
void ps::toigian(int tuso,int mauso)
{
	int dem;
	if((mauso!=0)&&(tuso==mauso))tu=mau=1;
	if(tuso>mauso)
	{
		for(dem=1;dem<=mauso;++dem)
		{
			if((tuso%dem==0)&&(mauso%dem==0)){tu=tuso/dem;mau=mauso/dem;}
		}
	}
	if(tuso<mauso)
	{
		for(dem=1;dem<=tuso;++dem)
		{
			if((tuso%dem==0)&&(mauso%dem==0)){tu=tuso/dem;mau=mauso/dem;}
		}
	}
}
void ps::hienthi(void)
{
	if(mau!=0)
	{
		cout<<"KQ cua phep cong PS la: "<<tu;
		if(mau!=1)cout<<"/"<<mau<<"\n";
		else cout<<"\n";
	}
	else cout<<"Xin loi mau so phai # 0  ---  "<<"Xin moi nhap lai\n"<<"======================\n";
}
