#include <16F877A.h>
#device*=16
#include <lcd_lib.c>
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)  //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
#bit E   = 0x09.0 //chan e0
#bit RW  = 0x09.1 //chan e1
#bit RS  = 0x09.2 //chan e2
#bit BF  = 0x08.7 //chan d7
#byte data = 0x08 //port D
/*******khai bao hang va bien******/
int16 number;
const unsigned char str1[]={"--I_Love_You !--"};
const unsigned char str2[]={"==Slow_in_love=="};
const unsigned char str3[]={"love_You,Forever"};
const unsigned char str4[]={"nhiet do:"};
const unsigned char str5[]={"nhiet do dat toi,MUC NGUY HIEM,DANGER !"};
unsigned char str_n[3];

/********Chuong trinh dem so luong ki tu trong chuoi ki tu*********/
int16 demkitu(void)
{
int16 count=0;
while(str2[count] != '\0')count++;
return count;
}
int16 demkitu2(void)
{
int16 count=0;
while(str3[count] != '\0')count++;
return count;
}
/*****************************************/
void main(void)
{
unsigned char a;
int1 b;
set_tris_e(0x00); //tat ca cac chan tren port E deu la dau ra
set_tris_d(0x00); //tat ca cac chan tren port D deu la dau ra
khoitao(1,1,0);   //che do 8 bit,2 dong,kieu 5x8
cursor(1,1,0);
while(true){
cursor(1,1,0);clear();moveto(1,1);
for(a=0;str2[a]!='\0';a++){
delay_ms(100);
data=str2[a];
display();}
moveto(2,1);
for(a=0;str3[a]!='\0';a++){
delay_ms(100);
data=str3[a];
display();}
moveto(1,17);
for(a=0;a<=demkitu();a++){ //xoa dan cac ki tu
motion(0,0);
data='\0';display();
motion(0,0);
delay_ms(100);}
moveto(1,1);
for(a=0;a<=16;a++){
delay_ms(100);
data=str1[a];
display();}
delay_ms(500);
/*************Ket thuc man chao hoi*****************/
clear();cursor(1,0,0);
for(a=0;a<=9;a++){data=str4[a];display();delay_ms(80);}
moveto(1,13);data=0xdf;display();data='C';display();
for(number=0;number<=999;number++){
str_n[0]=0x30+number/100;
str_n[1]=0x30+(number/10)%10;
str_n[2]=0x30+number%10;
moveto(1,10);
      for(a=0;a<3;a++){
      data=str_n[a];
      display();
      delay_ms(20);}
      }
/*********Thong bao lan cuoi********/
clear();
for(a=0;str5[a]!=',';a++)
   {
      data=str5[a];
      display();
      delay_ms(80);
   }
   moveto(2,3);
for(a=17;str5[a]!=',';a++)
   {
      data=str5[a];
      display();
      delay_ms(80);
   }
   delay_ms(1500);clear();moveto(1,5);
for(a=31;str5[a]!='\0';a++)
   {
      data=str5[a];
      display();
      delay_ms(80);
   }
for(a=0;a<=10;a++){cursor(b=!b,0,0);delay_ms(500);}
}
}
