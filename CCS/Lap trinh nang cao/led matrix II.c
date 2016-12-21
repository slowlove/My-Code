#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20M)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
#byte led1=0x06   //port_B
#byte led2=0x07   //     C
#byte data=0x08   //     D
/*----------------------*/
unsigned int8 dong,kitu;
unsigned int8 m,x;
const unsigned char ma_kitu[32][8]=    //neu so luong dong vuot qua 32 se bi tran ram vi khai bao qua so luong mang
             {                           
               {0x00,0x66,0xE7,0xE7,0xE7,0xE7,0x66,0x00}  //I
               {0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3B,0x03}  //L
               {0xFF,0x99,0x66,0x7E,0xBD,0xDB,0xE7,0xFF}  //heart
               {0x18,0xBD,0xBD,0xBD,0xBD,0xBD,0xDB,0xE7}  //V
               {0x01,0x3D,0x37,0x07,0x07,0x37,0x3D,0x01}  //E
               {0x18,0xBD,0xDB,0xE7,0xEF,0xDF,0x3F,0xFF}  //Y
               {0xC7,0x39,0x39,0x39,0x39,0x39,0x39,0xC7}  //O
               {0x18,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xC3}  //U
             };
/*-------------------------*/
void main(void){
set_tris_b(0);set_tris_c(0);set_tris_d(0);
led1=led2=0;
delay_ms(1000);
enable_interrupts(int_timer2);
setup_timer_2(t2_div_by_4,255,1);
enable_interrupts(global);
kitu=0;
while(true){
delay_ms(200);
++m;
switch(m){
case 1:x=0x01;break;
case 2:x=0x03;break;
case 3:x=0x07;break;
case 4:x=0x0f;break;
case 5:x=0x1f;break;
case 6:x=0x3f;break;
case 7:x=0x7f;break;
case 8:x=0xff;break;}
if(m==8){x=m=0;kitu++;if(kitu>7)kitu=0;}
}
}
/*-------------------------------*/
#int_timer2
void quet_led(void){
static unsigned int8 gt;
gt=(ma_kitu[kitu][dong]<<m)|x;
data=0xff;
led1=led2=1<<dong;
data=(ma_kitu[kitu][dong]<<m)|x;
dong++;
if(dong==8)dong=0;
}
