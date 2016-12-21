#include <16F877A.h>
#device *=16 adc=10
#include <lcd4b_lib.c>
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20M)  //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/**************Ket thuc khai bao*****************/
#bit RS   = 0x08.0   //chan d0
#bit RW   = 0x08.1
#bit E    = 0x08.2
#bit d0   = 0x08.3
#bit d1   = 0x08.4
#bit d2   = 0x08.5
#bit d3   = 0x08.6
/*--------------------------*/
#bit c0 = 0x07.0
#bit c1 = 0x07.1
#bit c2 = 0x07.2
#bit c3 = 0x07.3
#bit c4 = 0x07.4
#bit c5 = 0x07.5
#bit c6 = 0x07.6
#bit c7 = 0x07.7
#byte Port_C = 0x07
/*---------------------------------------------------*/
#define kiemtra (c4+(c5<<1)+(c6<<2)+(c7<<3))
const unsigned char str1[]={"bam phim bat ki"};
const unsigned char str2[]={"de bat dau CT !"};
unsigned int8 phim,phimbam,a;
/*-----------------------------*/
#int_timer0
void keyscan(void){
set_timer0(236);  //sau gan 1ms
/*------------------------*/
Port_C=1;   //mo toan bo hang 1
switch(kiemtra){
case 1:phim=1;break;
case 2:phim=2;break;
case 4:phim=3;break;
case 8:phim=4;break;
default:phim=0;
}
Port_C=2;
switch(kiemtra){
case 1:phim=5;break;
case 2:phim=6;break;
case 4:phim=7;break;
case 8:phim=8;break;
}
Port_C=4;
switch(kiemtra){
case 1:phim=9;break;
case 2:phim=10;break;
case 4:phim=11;break;
case 8:phim=12;break;
}
Port_C=8;
switch(kiemtra){
case 1:phim=13;break;
case 2:phim=14;break;
case 4:phim=15;break;
case 8:phim=16;break;
}
/*------------------------*/
Port_C=0;
phimbam=phim;
}
void main(void){
enable_interrupts(int_timer0);   //cho phep ngat timer 0 hoat dong
setup_timer_0(rtcc_internal|rtcc_div_256);  //thiet dat cac thong so cho timer 0
enable_interrupts(global); //cho phep ngat toan cuc hoat dong
set_tris_c(0xf0);
set_tris_d(0x00);
OE=0;
/*--------------------*/
khoitao(0,1,0);   //che do 4bit,2 dong,5x8
cursor(1,1,0);
/*-----------*/
data=0x7e;display();delay_ms(2000); //dau mui ten
clear();
/*-------------------------------------------------------*/
for(a=0;str1[a]!='\0';a++){data=str1[a];display();}
moveto(2,1);
for(a=0;str2[a]!='\0';a++){data=str2[a];display();}
while(phimbam==0);clear();
while(true){
switch(phimbam){
case 1:while(phimbam==1);data='7';display();break;
case 2:while(phimbam==2);data='8';display();break;
case 3:while(phimbam==3);data='9';display();break;
case 4:while(phimbam==4);data=0xfd;display();break;
case 5:while(phimbam==5);data='4';display();break;
case 6:while(phimbam==6);data='5';display();break;
case 7:while(phimbam==7);data='6';display();break;
case 8:while(phimbam==8);data='x';display();break;
case 9:while(phimbam==9);data='1';display();break;
case 10:while(phimbam==10);data='2';display();break;
case 11:while(phimbam==11);data='3';display();break;
case 12:while(phimbam==12);data='-';display();break;
case 13:while(phimbam==13);clear();break;
case 14:while(phimbam==14);data='0';display();break;
case 15:while(phimbam==15);data='=';display();break;
case 16:while(phimbam==16);data='+';display();break;
}
}
}
