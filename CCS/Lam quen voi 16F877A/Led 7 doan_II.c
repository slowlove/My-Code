#include <16F877A.h>
#device *=16   //khong duoc di chuyen dong lenh nay boi vi chuong trinh
               //se bao loi,mac du khong biet loi o cho nao ,,(*.*),.
#include <convert_lib.c>   //dich them file nguon tu dinh nghia
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
 unsigned char a,b;
 /****************Chuong trinh tach so**************************/
 /**** Chuong trinh su dung thuat toan chia lay phan du co  ****/
 /**** the dung lenh div() ho tro boi CCS_Help de thuc hien ****/
 void tachso(unsigned char value)
 {
 a=value/10;   //gia tri hang chuc luu vao a
 b=value%10;   //gia tri hang don vi luu vao b_thuat taoan chia lay phan du
 }
 /***************Chuong trinh hien thi bang phuong phap quet led**************/
 void hienthi(unsigned char display,unsigned char loop)   //bien display the hien so can hien thi,bien loop the hien so lan quet 1 led 7 doan
 {
 unsigned char m;
 tachso(display);                  //thuc hien cong doan tach so truoc khi dua vao xu li
 for(m=0;m<loop;m++)
 {
 output_b(toled7seg(b));
 output_c(0x01);
 delay_ms(50);
 output_b(toled7seg(a));
 output_c(0x02);
 delay_ms(50);
 }
 }
 /*****************Chuong trinh chinh*****************/
 void main(unsigned char x)
 {
 x=0;
 while(true){
 if((input(pin_d0)==0)&&(x<99)){delay_ms(25);x++;}   //neu co phim duoc an se tang len 1 va se tang lien tiep den 99 thi dung lai
 if((input(pin_d1)==0)&&(x>0)){delay_ms(25);x--;}   //tuong tu nhung nguoc lai
 hienthi(x,1);   //goi chuong trinh hien thi
 }
 }
