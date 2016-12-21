#include <P89V51RD2.h>
/*************dinh nghia cac gia tri ban dau*************/
#define thang    0x18
#define ra_ngoai 0x00
/*********************/
#define lechtrai1 0x08
#define lechtrai2 0x0c
#define lechtrai3 0x04
#define lechtrai4 0x06
#define lechtrai5 0x02
#define lechtrai6 0x03
#define lechtrai7 0x01
/*********************/
#define lechphai1 0x10
#define lechphai2 0x30
#define lechphai3 0x20
#define lechphai4 0x60
#define lechphai5 0x40
#define lechphai6 0xc0
#define lechphai7 0x80
/*****DK role de dao chieu dong co*******/ 
sbit dctrai=P1^3;		  //mopde =1 banh xe se quay xuoi va nguoc lai
sbit dcphai=P1^2;
/********Cam bien********/
 sbit led1 = P0^0; 
 sbit led2 = P0^1; 
 sbit led3 = P0^2; 
 sbit led4 = P0^3; 
 sbit led5 = P0^4; 
 sbit led6 = P0^5; 
 sbit led7 = P0^6; 
 sbit led8 = P0^7;
/******DN 2 banh la dau ra cua 2 chan dieu xung PWM********/
void banhtrai(unsigned char duty){
CCAP4H=duty;}
void banhphai(unsigned char duty){
CCAP3H=duty;}
/*****Chuong trinh delay******/
void delay(unsigned int time){
unsigned int a;
for(a=0;a<time;a++);
}
/********van toc rieng cho tung vung*******/
void v_thang(void){
banhtrai(250);
banhphai(255);}
/***************************/
void v_trai1(void){
banhtrai(250);
banhphai(250);}
void v_trai2(void){
banhtrai(250);
banhphai(245);}
void v_trai3(void){
banhtrai(250);
banhphai(240);}
void v_trai4(void){
banhtrai(250);
banhphai(235);}
void v_trai5(void){
banhtrai(250);
banhphai(230);}
void v_trai6(void){
banhtrai(250);
banhphai(225);}
void v_trai7(void){
banhtrai(250);
banhphai(220);}
/*****************************/
void v_phai1(void){
banhtrai(245);
banhphai(255);}
void v_phai2(void){
banhtrai(240);
banhphai(255);}
void v_phai3(void){
banhtrai(235);
banhphai(255);}
void v_phai4(void){
banhtrai(230);
banhphai(255);}
void v_phai5(void){
banhtrai(225);
banhphai(255);}
void v_phai6(void){
banhtrai(220);
banhphai(255);}
void v_phai7(void){
banhtrai(115);
banhphai(255);}
/*********chuong trinh stop************/
void stop(void){
banhtrai(0);
banhphai(0);}
/********Chuong trinh KT qua vach ngang********/
unsigned char sensor(void){
unsigned char total;
total=((led1==1)+(led2==1)+(led3==1)+(led4==1)+(led5==1)+(led6==1)+(led7==1)+(led8==1));	//trong cung 1 rthoi diem ma co 
return(total);}																				//>=5 mat nhan dc vach thi coi nhu qua vach
/********chuong trinh con chay thang*******/
void chaythang(unsigned char vach){
dctrai=dcphai=1;delay(1000);		  //thiet lap chieu cua 2 dong co
while(P0==ra_ngoai)stop();
do{
do{
switch(P0){
case lechtrai1:v_trai1();break;
case lechtrai2:v_trai2();break;
case lechtrai3:v_trai3();break;
case lechtrai4:v_trai4();break;
case lechtrai5:v_trai5();break;
case lechtrai6:v_trai6();break;
case lechtrai7:v_trai7();break;
case lechphai1:v_phai1();break;
case lechphai2:v_phai2();break;
case lechphai3:v_phai3();break;
case lechphai4:v_phai4();break;
case lechphai5:v_phai5();break;
case lechphai6:v_phai6();break;
case lechphai7:v_phai7();break;
default:v_thang();break;}
}
while(sensor()<5);
while(sensor()>=5)v_thang();
--vach;
}
while(vach!=0);
vach=0;
v_thang();delay(60000);delay(30000);
}
/*******Chuong trinh re trai*******/
void retrai(void){
dctrai=0;dcphai=1;delay(1000);
while(P0!=lechphai5)v_trai1();
}
/*******chuong trinh re phai********/
void rephai(void){
dctrai=1;dcphai=0;delay(1000);
while(P0!=lechtrai5)v_thang();
}
/********chuong trinh chinh*********/
void main(void){
unsigned char x;
/**************Setup****************/
CMOD=0;		  //che do 6 chu ky xung nhip=1/2 chu ky may
CR=1;		  //cho phep PCA hoat dong
CCAPM1=0x42;  //Thiet lap chan P1.4 lam chan PWM 8 bit
CCAPM2=0x42;  //```````````````P1.5```````````````````
CCAPM3=0x42;  //```````````````P1.6```````````````````
CCAPM4=0x42;  //```````````````P1.7```````````````````
/*********chuong trinh dieu khien robot*************/
for(x=6;x!=0;x--){
chaythang(x);
retrai();chaythang(1);
retrai();
}
rephai();chaythang(2);
while(1){stop();delay(10000);}
}					   