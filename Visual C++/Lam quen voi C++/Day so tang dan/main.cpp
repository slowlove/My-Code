#include <iostream.h>
#include <conio.h>
/*-------------------------*/

void main()
{
unsigned long dayso;
cout<<"Hay nhap vao 1 day so:"<<endl;
cin>>dayso;
for(;dayso>0;dayso/=10)cout<<dayso%10;
cout<<endl;
getch();
}

