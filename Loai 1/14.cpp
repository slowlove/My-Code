#include <iostream.h>
#include <conio.h>
#include <stdio.h>
/*******************************/
unsigned long giaithua(int n)
{
   unsigned long ketqua = 1;
   int i;
   for (i=2;i<=n;i++)ketqua *= i;
   return ketqua;
}
unsigned long to_hop_chap(int k, int n)
{
   return giaithua(n)/(giaithua(k)*giaithua(n-k));
}
void main()
{
  int n,k;
  cout<<"Nhap vao gia tri n va k:",cin>>n>>k;
  cout<<"to hop nCk la`:"<<to_hop_chap(k,n);
  getch();
}
