#include <16F877A.h>
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
/*******************************************************************************/
void main(unsigned char x)
{
   while(true)            //vong lap khong gioi han voi gia tri kiem tra luon bang 1
   {
      for(x=0x01;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri ban dau la 01h
      for(x=0x03;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri la 03h
      output_d(0x01);delay_ms(100);
      output_d(0x03);delay_ms(100);
      output_d(0x07);delay_ms(100);
      for(x=0x07;x<0x80;output_d(x=x<<1),delay_ms(100));    //dich trai 1 bit voi gia tri ban dau la 0x7 (00000111)
      output_d(0x80);delay_ms(100);
      output_d(0xC0);delay_ms(100);
      output_d(0x70);delay_ms(100);
      for(x=0x70;x>0x01;output_d(x=x>>1),delay_ms(100));    //dich phai 1 bit voi gia tri ban dau la 0x70 (11100000)
      for(x =0x01;x<0xff;output_d(x=1+2*x),delay_ms(100));    //sang dan
      for(x =0xff;x>0x01;output_d(x=(x-1)/2),delay_ms(100));    //tat dan
      output_d(0x01);delay_ms(600);
      for(x =0x01;x<0x55;output_d(x =1+4*x),delay_ms(600));    //sang xen ke
      for(x=0x01;x<=0x14;x++){output_d(0xaa);delay_ms(100);output_d(0x55);delay_ms(100);}   //nhap nhay xen ke
      for(x=0;x<8;x++){output_d((1<<x)+(1<<(7-x)));delay_ms(100);}   //sang 2 dau vao
      for(x=0xff;x>0;x-=0x05){output_d(0xff);delay_ms(x);output_d(0x00);delay_ms(x);} //nhay nhanh dan deu
   }
}
