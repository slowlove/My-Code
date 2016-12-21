/*****************************************************************************
**           ----Chuong trinh hien thi nhiet do bang sensor LM35----        **
**           xay dung:23/06/2008                                            **
**           Thong so:                                                      **
**           +dai nhiet do hoat dong 0-99°C                                 **
**           +sai so so voi nhiet do thuc:0.3%                              **
**           +xac suat sai so:33% so lan nhiet do thay doi                  **
**           +hien thi nhiet do ra LCD va led 7 doan-                       **
**           Lap trinh:Slowlove                                             **
**           YM:love_classicalguitar||slow_in_love                          **
**           E-Mail:Guitar.mp3@gmail.com                                    **
*****************************************************************************/
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
#bit OE   = 0x08.7   //chan d7
/*******Cac hang va bien su ducng trong chuong trinh**********/
extern unsigned int8 data; // bien toan cuc data da duoc dinh nghia trong LCD4b_lib
const unsigned char str[]={"Nhiet do:"};
const unsigned char str1[]={"QUA MUC CHO PHEP"};
const unsigned char str2[]={"Sensor [-LM35-]"};
unsigned int8 hangchuc,hangdonvi,thapphan;
unsigned int8 a;  //bien dem so ki tu trong chuoi ki tu
unsigned int16 x;
float nhietdo;
/*****Chuong trinh doi gia tri ADC tra ve ra °C*******/
float temp(float value){
float t;
t=(value/1023)*500;  //doi ra °C su dung ADC 10 bit,Vref=5V,ung voi thay doi 10mV/1°C
t=((unsigned int16)(t*10))/10.0;   //chinh xac toi 1 chu so sau dau phay,SD 10.0 kieu float de tu chuyen doi kieu phep tinh
return t;
}
/*-----hien thi thong tin chuan bi tren LCD---------*/
void hien_thi_ban_dau(void){
for(a=0;str[a]!='\0';a++){data=str[a];display();}
moveto(1,12);data='.';display();
moveto(1,14);data=0xdf;display();data='C';display();
moveto(2,1);
for(a=0;str2[a]!='\0';a++){data=str2[a];display();}
}
/*------Doc gia tri ADC va chuyen doi thanh nhiet do------*/
void readADC(void){
read_adc(adc_start_only);  //bat dau qua trinh ADC
while(!adc_done());  //doi cho den khi qua trinh chuyen doi ADC hoan tat
nhietdo=temp(read_adc(adc_read_only));  //doc gia tri nhiet do tu sensor
}
/*****Chuong trinh ngat Timer0 phuc vu viec quet Led*********/
#int_timer0
void quetled(void){
set_timer0(140);  //sau 6ms voi bo chia timer0 cho 256
OE=0;
}
/*******Chuong trinh chinh*********/
void main(void){
/******thiet lap ngat*******/
enable_interrupts(int_timer0);   //cho phep ngat timer 0 hoat dong
setup_timer_0(rtcc_internal|rtcc_div_256);  //thiet dat cac thong so cho timer 0
enable_interrupts(global); //cho phep ngat toan cuc hoat dong
/******thiet lap cac che do ADC******/
setup_adc(adc_clock_internal);
setup_adc_ports(an0);
set_adc_channel(0);
delay_us(10);  //delay 10us sau moi lan chon kenh doc gia tri ADC de ket qua adc chinh xac hon
/******thiet lap in/out cho cac port*********/
set_tris_a(0x01); //chan a0 la ngo vao
set_tris_d(0x00); //tat ca port d deu la ngo ra
/*---khoi tao hien thi tren LCD---*/
khoitao(0,1,0);   //che do 4 bit,2 dong,5x8
cursor(1,0,0);
hien_thi_ban_dau();
/*------vong lap chuong trinh-----*/
while (true){
readADC();  //doc va chuyen doi gia tri ADC ra nhiet do(°C)
/*---tach so--*/
x=nhietdo*10;  //bo dau cham dong phan cach phan thap phan,x la 1 so 16bit boi nhiet do la float
hangchuc=x/100;
hangdonvi=(x/10)%10;
thapphan=x%10;
/*---------hien thi nhiet do tren LCD-------------*/
moveto(1,10);
data=0x30+hangchuc;display();
data=0x30+hangdonvi;display();
moveto(1,13);
data=0x30+thapphan;display();
if(nhietdo>=100)  //neu nhiet do >=100°C thi hien canh bao
   {
      clear();moveto(1,5);
      for(a=0;str[a]!=':';a++){data=str[a];display();}
      moveto(2,1);
      for(a=0;str1[a]!='\0';a++){data=str1[a];display();}
      while(nhietdo>=100)readADC();  //khong lam gi cho toi khi nhiet do xuong duoi 100°C
      clear(); //xoa toan bo hien thi
      hien_thi_ban_dau();  //tra lai trang thai hien thi ban dau cho LCD
   }
}
}

