#include <iostream.h>
#include <stdio.h>
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
class contro
{
private:	//khai bao cac thanh phan du lieu rieng
	int x,y;
public:		//khai bao cac ham cong dong
	void toadobandau(int xo,int yo);
	void toadomove(int dx,int dy);
	void hienthi(void);
};
/*---------------------------------------------*/
void contro::toadobandau(int xo,int yo){
	cout<<"toa do ban dau:\n";
	x=xo;
	y=yo;}
/*------------*/
void contro::toadomove(int dx,int dy){
	cout<<"toa do sau khi di chuyen:\n";
	x+=dx;
	y+=dy;}
/*------------*/
void contro::hienthi(void){cout<<"X="<<x<<"  Y="<<y<<"\n";}
/*-----------------------------------------------------------*/
/*-----------------------------------------------------------*/
void main(void){
contro a,b;
a.toadobandau(0,0);
a.hienthi();
a.toadomove(4,5);
a.hienthi();
/*------------------------*/
b.toadobandau(3,4);
b.hienthi();
b.toadomove(10,12);
b.hienthi();
}
