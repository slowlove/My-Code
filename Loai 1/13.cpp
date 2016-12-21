#include<conio.h>
#include<stdio.h>
#include<string.h>
void nhapchuoi(char s[])
    {
    printf("\n Nhap chuoi ki tu: ");
    gets(s);
    }
int ktchuoi(char s[])
    {
    int i,j,k=0;
    j=strlen(s)-1;
    for(i=0;i<=strlen(s)/2;i++)
     { 
     if(s[i]==s[j])
      {
        k++;
        j--;
        if(k>=strlen(s)/2) return 1;
      }
     else {
         return 0;
         break;
    }
    }
    }
void main()
    {
    char s[50];
    nhapchuoi(s);
    if(ktchuoi(s)==1) printf("\n Chuoi Palindrome");
    else printf("\n Khong phai chuoi Palindrome");
    getch();
    }
