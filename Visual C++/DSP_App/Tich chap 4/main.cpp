#include <iostream.h>
#include <conio.h>
int k,n;
float y;
int x_n(int n1)
{
	switch (n1)
	{
	case -1:return 1;break;
	case 0:return 2;break;
	case 1:return 1;break;
	case 2:return -1;break;
	default:return 0;
	}
}
int h_n(int n2)
{
	switch (n2)
	{
	case 0:return 1;break;
	case 1:return 2;break;
	case 2:return 3;break;
	case 3:return 1;break;
	default:return 0;
	}
}
void main(void)
{
	for(n=-20;n<=20;n++)
	{
		y=0;	//tinh toan lai y voi gia tri n moi
		for(k=-1000;k<=1000;k++)y=y+(x_n(k)*h_n(n-k));
		if(y!=0)
		{
			cout<<"  n= "<<n<<endl;
			cout<<"Y("<<n<<")= "<<y<<endl;
			cout<<"----------"<<endl;
		}
	}
	getch();
}
