// Mult_Big_Int.cpp : Defines the entry point for the console application.
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#define MAX 100000

int a[4],b[2*MAX];
int n,leng=0,lengb=0;
/*********************************************/
void input();
void Convert(int c[],int y);
void Print();
/*********************************************/
void Print(){
int i;
int newline=0;
FILE*f=fopen("KetQua.txt","w");
for(i=0;i<=lengb;i++)
{
newline++;
printf("%d",b[lengb-i]);
fprintf(f,"%d",b[lengb-i]);
if(newline==75){
fprintf(f,"\n");
newline=0;
}
}
}
void input(){
printf("Chuong tring tinh n!tac gia:hungd02cntt@gmail.com\n");
printf("N=");scanf("%d",&n);

}
/*********************************************/
void Mang(int n){
leng=0;
while(n>0){
a[leng]=n%10;
n=n/10;
leng++;
}
leng--;
}

/*********************************************/
void Multi(int a[],int n,int b[],int m){

int i,j,k;
int c[2*MAX];

for(k=0;k<=m+n;k++)
c[k]=0;
for(i=0;i<=n;i++)
for(j=0;j<=m;j++)
for(k=0;k<=m+n;k++)
if(i+j==k)
{
c[k]=c[k]+a[i]*b[j];
}
for(i=0;i<=m+n;i++)
b[i]=c[i];
Convert(b,m+n);
}
/*********************************************/
void Convert(int c[],int m){
int i,h;

for(i=0;i<m;i++)
{
c[i+1]=c[i+1]+c[i]/10;
c[i]=c[i]%10;
}
h=m;
if(c[m]>9)
{
int x;
x=c[m];
c[m]=x%10;
c[m+1]=x/10;
h=m+1;
}
lengb=h;
}
/*********************************************/

/*********************************************/
void main()
{


int i;
b[lengb]=1;
input();

for(i=2;i<=n;i++)
{
Mang(i);
Multi(a,leng,b,lengb);
}
Print();
getch();
}
