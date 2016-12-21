#include <iostream.h>
#include <conio.h>
#include <stdio.h>
/***************************/
int main()
{
  int a[100],n,i;
  cout<<"so phan tu cua day:",cin>>n;
  cout<<"nhap cac phan tu cho day:"<<endl;
  for (i=0;i<n;i++)cout<<"a["<<i<<"]=",cin>>a[i];
  i=1;
  while(i<n)
  {
  	if(a[i]>a[i-1])i++;
  	else break;
  }
  if (i==n)cout<<"day là day so tang.";
  else cout<<"day ko phai la day so tang."<<"vi co phan tu sai dau tien la:"<<a[i];
  getch();
  return 0;
}
