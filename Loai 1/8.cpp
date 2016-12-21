#include <iostream.h>
#include <conio.h>
#include <stdio.h>
/***************************/
unsigned int mang[100];
int x,n,i,temp=0;
/************/
int main()
{	
	cout<<"mang co chieu dai la`:",cin>>n;
	cout<<"nhap vao cac gia tri cua mang:"<<endl;
	for(i=0;i<n;i++)cout<<"mang["<<i<<"]=",cin>>mang[i];
	cout<<"mang truoc khi sap xep:"<<endl;
	for(i=0;i<n;i++)cout<<mang[i]<<" "<<endl;
	cout<<"nhap vao gia tri x can chen`:",cin>>mang[n];
	n++;
	for(int a=0;a<n-1;a++)
		for(int b=a+1;b<n;b++)
			if(mang[b]<mang[a])
				{
					temp=mang[a];
					mang[a]=mang[b];
					mang[b]=temp;
				}
	cout<<"mang sau khi sap xep:"<<endl;
	for(i=0;i<n;i++)cout<<mang[i]<<" "<<endl;
	getch();
	return 0;
}
