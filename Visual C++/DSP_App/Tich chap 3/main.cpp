#include <iostream.h>
#include <conio.h>
int k,n;
float y;
int x_n(int n1)
{
	int x1,x2;
	if((n1+1)==0)x1=1;
	else x1=0;
	if((n1-2)==0)x2=1;
	else x2=0;
	return (x1+x2);
}
float h_n(float n2)
{
	if(((n2)>=0)&((n2)<=2))return 1;
	else return 0;
}
void main(void)
{
	for(n=-20;n<=20;n++)
	{
		y=0;	//tinh toan lai y voi gia tri n moi
		for(k=-1000;k<=1000;k++)y=y+(x_n(k)*h_n((float)(n-k)));
		if(y!=0)
		{
			cout<<"  n= "<<n<<endl;
			cout<<"Y("<<n<<")= "<<y<<endl;
			cout<<"----------"<<endl;
		}
	}
	getch();
}
