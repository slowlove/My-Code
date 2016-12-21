#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
unsigned char i,x;
#int_ext
void thaongo(){
i++;
if(i==3)i=0;}
/***************************************************/
void led1(){
      for(x =0x01;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri ban dau la 01h
      for(x=0x03;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri la 03h
      output_d(0x01);delay_ms(100);
      output_d(0x03);delay_ms(100);
      output_d(0x07);delay_ms(100);
      for(x=0x07;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri ban dau la 0x7 (00000111)
      output_d(0x80);delay_ms(100);
      output_d(0xC0);delay_ms(100);
      output_d(0x70);delay_ms(100);}
void led2(){
      for(x =0x01;x<0xff;output_d(x=1+2*x),delay_ms(100));    //sang dan
      for(x =0xff;x>0x01;output_d(x=(x-1)/2),delay_ms(100));    //tat dan
      output_d(0x01);delay_ms(600);
      for(x =0x01;x<0x55;output_d(x =1+4*x),delay_ms(600));    //sang xen ke
      for(x=0x01;x<=0x14;x++){output_d(0xaa);delay_ms(100);output_d(0x55);delay_ms(100);}   //nhap nhay xen ke
      for(x=0x01;x<=0x14;x++){output_d(0xff);delay_ms(60);output_d(0);delay_ms(110);}}   //nhap nhay
 /**********************************************************/
void main(){
enable_interrupts(int_ext);
enable_interrupts(global);
ext_int_edge(h_to_l);
i=1;
while(1){
switch(i){
case 1:led1();break;
case 2:led2();break;
}
}
}





