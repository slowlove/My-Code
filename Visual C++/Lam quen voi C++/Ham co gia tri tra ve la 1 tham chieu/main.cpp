#include <iostream.h>
#include <conio.h>
int a[5];
int &fr(int *d,int i);
void main() 
{
  cout<<"Nhap gia tri cho mang a:\n";
  for(int i=0;i<5;i++) {
    cout<<"a["<<i<<"]= ";
    cin>>fr(a,i);
    }
  cout<<"Mang a sau khi nhap\n";
  for(i=0;i<5;i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  getch();
  }

int &fr(int *d,int i) 
{
  return d[i];
  }
