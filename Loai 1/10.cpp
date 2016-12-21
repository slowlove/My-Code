#include <iostream.h>
#include <conio.h>
#include <stdio.h>
/***************************/
int main()
{
  int n,i,j;
  cout<<"Nhap gia tri n:",cin>>n;
  cout<<"Cac so nguyen to nho hon n la:"<<endl;
  for (i=2; i<n; i++)
  {
    for (j=2;j<i;j++)if(i%j==0)break;
    if(j==i)cout<<i<<" ";
  }
  getch();
  return 0;
}
