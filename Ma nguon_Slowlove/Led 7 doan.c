#include <16F877A.h>
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
 /***********Program conver data on port to led 7 seg***********/
 unsigned char toled7seg(unsigned char n)
 {
 switch(n)   //bien n trong ham switch co the thay bang 1 ham bat ki nhu data
 {
 case 0x00:n=0x40;break;   //conver number 0
 case 0x01:n=0x79;break;
 case 0x02:n=0x24;break;
 case 0x03:n=0x30;break;
 case 0x04:n=0x19;break;
 case 0x05:n=0x12;break;
 case 0x06:n=0x02;break;
 case 0x07:n=0x78;break;
 case 0x08:n=0x00;break;
 case 0x09:n=0x10;break;   //conver number 9
 case 0x0a:n=0x08;break;   //conver character a
 case 0x0b:n=0x03;break;   //...b
 case 0x0c:n=0x46;break;   //...c
 case 0x0d:n=0x21;break;   //...d
 case 0x0e:n=0x06;break;   //...e
 case 0x0f:n=0x0e;break;   //...f
 case 0x10:n=0x09;break;   //...h
 case 0x11:n=0x47;break;   //...l
 case 0x12:n=0x48;break;   //...n
 case 0x13:n=0x0c;break;   //...p
 case 0x14:n=0x18;break;   //...q
 case 0x15:n=0x41;break;   //...u
 case 0x16:n=0x11;break;   //...y
 }
 return(n);                //tra lai ket qua cho bien n
 }
 /********************chuong trinh chinh*********************/
 void main(unsigned char x)
 {
 while(1)
 {
 for(x=0x00;x<=0x16;x++){
 output_b(toled7seg(x));delay_ms(800);}
 }
 }

