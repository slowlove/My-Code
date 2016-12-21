#include <iostream.h>
#include <conio.h>
#include <stdio.h>
/***************************/
unsigned long long so;
int temp;
int main()
{
	cout<<"Nhap vao 1 so nguyen bat ky`:";
	cin>>so;
	while(true)
	{
		temp+=so%10;
		so/=10;
		if((so%10)==0)break;
	}
	cout<<"Tong cac chu so la`:"<<temp;
	getch();
	return 0;
}
