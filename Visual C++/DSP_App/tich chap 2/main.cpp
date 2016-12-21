#include <iostream.h>
#include <conio.h>
int k,n;
float y;
float x_n(float n1)
{
	if(n1>=0)return (1-n1/3);
	else return 0;
}
float h_n(float n2)
{
	if(((n2-1)>=0)&((n2-1)<=1))return 1;
	else return 0;
}
void main(void)
{
	for(n=-20;n<=20;n++)
	{
		y=0;	//tinh toan lai y voi gia tri n moi
		for(k=-1000;k<=1000;k++)y=y+(x_n((float)k)*h_n((float)(n-k)));
		if(y!=0)
		{
			cout<<" n= "<<n<<endl;
			cout<<" Y("<<n<<")= "<<y<<endl;
			cout<<"------------------"<<endl;
		}
	}
	getch();
}
