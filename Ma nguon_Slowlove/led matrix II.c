#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
#bit ab1=0x07.0   //chan C0
#bit ab2=0x07.1
#bit ab3=0x07.2
#bit ck1=0x07.3
#bit ck2=0x07.4
#bit ck3=0x07.5
#bit rs =0x07.6   //chan C6
/**************************/
#bit x1 =0x08.0   //chan D0
#bit x2 =0x08.1
#bit x3 =0x08.2
#bit d1 =0x08.3
#bit d2 =0x08.4
#bit d3 =0x08.5
#bit chot_x =0x08.6
#bit chot_d =0x08.7  //chan D7
/*********ket thuc phan dinh nghia************/
int32 value;
unsigned char n;
unsigned char const ma_kitu[32][8]=    //neu so luong hang vuot qua 32 se bi tran ram vi khai bao qua so luong mang
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
#int_timer0
void quetcot(void)
   {     
      set_timer0(246);  //timer0 se tran sau 8us
      ++value;
      if(value==100)
      {
      if(n==1)ab1=1;
      else ab1=0;
      ck1=0;
      ck1=1;
      n++;
      if(n==8)n=0;
      value=0;
      }
   }
void main(void){
enable_interrupts(int_timer0);
setup_timer_0(rtcc_internal|rtcc_div_4);
enable_interrupts(global);
set_tris_c(0x80); //C0-C6 la ngo ra,C7 la ngo vao
set_tris_d(0x00); //tat ca port D deu la ngo ra
rs=1;
chot_x=chot_d=1;                                                                 
while(true)
   {                                                                                                                 
   x1=x2=x3=0;
   }
}                                           

