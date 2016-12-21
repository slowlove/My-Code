#include <16F877A.h>
#device *=16 adc=10
#include <lcd4b_lib.c>
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT
#use delay(clock=20M)
#priority int_timer2,int_timer0  //thiet dat uu tien ngat
/**************Ket thuc khai bao*****************/
#bit OE = 0x08.7   //chan d7(chot du lieu)
/*----------*/
#bit c0 = 0x07.0
#bit c1 = 0x07.1
#bit c2 = 0x07.2
#bit c3 = 0x07.3
#bit c4 = 0x07.4
#bit c5 = 0x07.5
#bit c6 = 0x07.6
#bit c7 = 0x07.7
/*--------------*/
#byte portC=0x07
#byte portD=0x08
/*---------Dinh nghia Marco------------*/
#define kiemtra (c4+(c5<<1)+(c6<<2)+(c7<<3))
#define start_quetphim enable_interrupts(int_timer2)
#define stop_quetphim disable_interrupts(int_timer2)
/*---------------------------------------------*/
const unsigned char str1[]={"Co muon chay CT?"};
const unsigned char str2[]={"  YES 1  NO 2  "};
const unsigned char str3[]={"Complete !"};
unsigned int8 a;   //bien da nang,su dung lam gi cung duoc
unsigned int8 phim,chon_ct,chon_page,backup;
unsigned int1 chon;
unsigned int8 data;   //bien toan cuc co trong moi file khi link cac file *.c de complier
/*-----------------------------------------------------------------*/
/*----------------------cac chuong trinh con-----------------------*/
/*-----------------------------------------------------------------*/
void menu_page0(void){
const unsigned char menu1[]={"Meter 1"};
const unsigned char menu2[]={"(SMS) 2"};
const unsigned char menu3[]={"Timer 3"};
const unsigned char menu4[]={"Calc  4"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page1(void){
const unsigned char menu1[]={"GPRS  5"};
const unsigned char menu2[]={"CDMA  6"};
const unsigned char menu3[]={"OFDM  7"};
const unsigned char menu4[]={"FPGA  8"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page2(void){
const unsigned char menu1[]={"PCM   9"};
const unsigned char menu2[]={"PWM  10"};
const unsigned char menu3[]={"PAM  11"};
const unsigned char menu4[]={"Menu 12"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page3(void){
const unsigned char menu1[]={"Menu 13"};
const unsigned char menu2[]={"Menu 14"};
const unsigned char menu3[]={"Menu 15"};
const unsigned char menu4[]={"Menu 16"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page4(void){
const unsigned char menu1[]={"Menu 17"};
const unsigned char menu2[]={"Menu 18"};
const unsigned char menu3[]={"Menu 19"};
const unsigned char menu4[]={"Menu 20"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page5(void){
const unsigned char menu1[]={"Menu 21"};
const unsigned char menu2[]={"Menu 22"};
const unsigned char menu3[]={"Menu 23"};
const unsigned char menu4[]={"Menu 24"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page6(void){
const unsigned char menu1[]={"Menu 25"};
const unsigned char menu2[]={"Menu 26"};
const unsigned char menu3[]={"Menu 27"};
const unsigned char menu4[]={"Menu 28"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page7(void){
const unsigned char menu1[]={"Menu 29"};
const unsigned char menu2[]={"Menu 30"};
const unsigned char menu3[]={"Menu 31"};
const unsigned char menu4[]={"Menu 32"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page8(void){
const unsigned char menu1[]={"Menu 33"};
const unsigned char menu2[]={"Menu 34"};
const unsigned char menu3[]={"Menu 35"};
const unsigned char menu4[]={"Menu 36"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
void menu_page9(void){
const unsigned char menu1[]={"Menu 37"};
const unsigned char menu2[]={"Menu 38"};
const unsigned char menu3[]={"Menu 39"};
const unsigned char menu4[]={"Menu 40"};
moveto(1,2);for(a=0;menu1[a]!='\0';++a){data=menu1[a];display();}
moveto(1,10);for(a=0;menu2[a]!='\0';++a){data=menu2[a];display();}
moveto(2,2);for(a=0;menu3[a]!='\0';++a){data=menu3[a];display();}
moveto(2,10);for(a=0;menu4[a]!='\0';++a){data=menu4[a];display();}
}
/*----------------------------*/
void menu_display(unsigned int8 page){
switch(page){
case 0:menu_page0();break;
case 1:menu_page1();break;
case 2:menu_page2();break;
case 3:menu_page3();break;
case 4:menu_page4();break;
case 5:menu_page5();break;
case 6:menu_page6();break;
case 7:menu_page7();break;
case 8:menu_page8();break;
case 9:menu_page9();break;}
}
/*------------------*/
void muiten(void){
data=0x7e;display();}    //bieu tuong con tro (->)
void eraser(void){
data=' ';display();}   //ki tu rong(xoa ki tu)
void vach(void){
data=0xff;display();}   //vach % qua trinh xu li
/*----------------------*/
void contro(unsigned int8 dong,cot){
moveto(dong,cot);muiten();
delay_ms(20);
moveto(dong,cot);eraser();
delay_ms(20);
}
/*-----Loi Chao------*/
void wellcome(void){
const unsigned char msg[]={"BAN QUYEN SP CUA"};
const unsigned char msg2[]={"Slowlove-(29/06)"};
for(a=0;msg[a]!='\0';++a){data=msg[a];display();}
moveto(2,1);
for(a=0;msg2[a]!='\0';++a){data=msg2[a];display();}
delay_ms(1000);
}
/*------------------*/
void cau_hoi_xac_nhan(void){
clear();
for(a=0;str1[a]!='\0';++a){data=str1[a];display();}
moveto(2,1);
for(a=0;str2[a]!='\0';++a){data=str2[a];display();}
}
/*---------Cac chuong trinh can thuc hien----------*/
void chuongtrinh1(void){
const unsigned char msg[]={"Process..."};
clear();   //xoa man hinh de chuan bi hien thi thong tin qua trinh xu li
for(a=0;msg[a]!='\0';++a){data=msg[a];display();}   //Process...
moveto(2,1);
for(a=0;bit_test(a,4)==0;++a){
data=0xff;display();
delay_ms(300);
}
}
/*-------------*/
void chuongtrinh2(void){
const unsigned char msg[]={"Love_You_Forever"};
clear();
for(a=0;msg[a]!='\0';++a){data=msg[a];display();} 
moveto(2,1);
for(a=0;bit_test(a,4)==0;++a){
data=0xff;display();
delay_ms(300);
}
}
/*-------------*/
void chuongtrinh3(void){
const unsigned char msg[]={"Slowlove_Winner!"};
clear();
for(a=0;msg[a]!='\0';++a){data=msg[a];display();} 
moveto(2,1);
for(a=0;bit_test(a,4)==0;++a){
data=0xff;display();
delay_ms(300);
}
}
/*-------------*/
void chuongtrinh4(void){
const unsigned char msg[]={" --29/06/2008--"};
clear();
for(a=0;msg[a]!='\0';++a){data=msg[a];display();} 
moveto(2,1);
for(a=0;bit_test(a,4)==0;++a){
data=0xff;display();
delay_ms(300);
}
}
/*-----------*/
void chuongtrinh5(void){}
void chuongtrinh6(void){}
void chuongtrinh7(void){}
void chuongtrinh8(void){}
void chuongtrinh9(void){}
void chuongtrinh10(void){}
void chuongtrinh11(void){}
void chuongtrinh12(void){}
void chuongtrinh13(void){}
void chuongtrinh14(void){}
void chuongtrinh15(void){}
void chuongtrinh16(void){}
void chuongtrinh17(void){}
void chuongtrinh18(void){}
void chuongtrinh19(void){}
void chuongtrinh20(void){}
void chuongtrinh21(void){}
void chuongtrinh22(void){}
void chuongtrinh23(void){}
void chuongtrinh24(void){}
void chuongtrinh25(void){}
void chuongtrinh26(void){}
void chuongtrinh27(void){}
void chuongtrinh28(void){}
void chuongtrinh29(void){}
void chuongtrinh30(void){}
void chuongtrinh31(void){}
void chuongtrinh32(void){}
void chuongtrinh33(void){}
void chuongtrinh34(void){}
void chuongtrinh35(void){}
void chuongtrinh36(void){}
void chuongtrinh37(void){}
void chuongtrinh38(void){}
void chuongtrinh39(void){}
void chuongtrinh40(void){}
/*---------------*/
void chay_chuongtrinh(unsigned int8 chuongtrinh){
switch(chuongtrinh){
case 1:chuongtrinh1();break;
case 2:chuongtrinh2();break;
case 3:chuongtrinh3();break;
case 4:chuongtrinh4();break;
case 5:chuongtrinh5();break;
case 6:chuongtrinh6();break;
case 7:chuongtrinh7();break;
case 8:chuongtrinh8();break;
case 9:chuongtrinh9();break;
case 10:chuongtrinh10();break;
case 11:chuongtrinh11();break;
case 12:chuongtrinh12();break;
case 13:chuongtrinh13();break;
case 14:chuongtrinh14();break;
case 15:chuongtrinh15();break;
case 16:chuongtrinh16();break;
case 17:chuongtrinh17();break;
case 18:chuongtrinh18();break;
case 19:chuongtrinh19();break;
case 20:chuongtrinh20();break;
case 21:chuongtrinh21();break;
case 22:chuongtrinh22();break;
case 23:chuongtrinh23();break;
case 24:chuongtrinh24();break;
case 25:chuongtrinh25();break;
case 26:chuongtrinh26();break;
case 27:chuongtrinh27();break;
case 28:chuongtrinh28();break;
case 29:chuongtrinh29();break;
case 30:chuongtrinh30();break;
case 31:chuongtrinh31();break;
case 32:chuongtrinh32();break;
case 33:chuongtrinh33();break;
case 34:chuongtrinh34();break;
case 35:chuongtrinh35();break;
case 36:chuongtrinh36();break;
case 37:chuongtrinh37();break;
case 38:chuongtrinh38();break;
case 39:chuongtrinh39();break;
case 40:chuongtrinh40();break;
}
}
/*----------------------------------------------------------------------------*/
/*-----------------------------Chuong trinh chinh-----------------------------*/
/*----------------------------------------------------------------------------*/
void main(void){
setup_timer_0(rtcc_internal|rtcc_div_256);  //thiet dat cac thong so cho timer 0
setup_timer_2(t2_div_by_16,255,8);  //sau khoang 6.5ms(200ns*16*255*8) thi xay ra ngat timer 2
enable_interrupts(int_timer0);
disable_interrupts(int_timer2);
enable_interrupts(global); //cho phep ngat toan cuc hoat dong
/*---------Cac lenh khoi tao ban dau-------*/
setup_adc_ports(no_analogs);  //chu y:doi voi port a thi phai thiet lap analog hay digital
set_tris_a(0);                //RA4 la chan cuc mang ho
set_tris_c(0xf0); // 1/2la dau ra,con lai la dau vao
set_tris_d(0x00); //tat ca la dau ra
portC=portD=0; //tat toan bo ca 2 port
OE=0; //mo chot
/*--------Cac lenh hien thi ban dau--------*/
khoitao(0,1,0);
cursor(1,0,0);
wellcome(); //loi chao dau tien
/*****************phan xu li chinh cua chuong trinh*********************/
while(true){
clear();
chon_page=0;   //trang mac dinh la trang dau
start_quetphim;   //bat dau quet phim
while(true)
   {
      menu_display(chon_page);   //hien thi cac trang menu de lua chon chuong trinh
      while((phim==0)||(phim==1)||(phim==2));   //chong rung phim
      phim=4;   //vi tri mac dinh cua -> la vi tri dau tien cua moi trang
      while(true)
        {
            if((phim==1)||(phim==2))break;   //neu an tang hoac giam page thi thoat va thuc hien + hoac - page
            switch(phim){
            case 0:goto thuc_hien_chuong_trinh; //nhay han ra khoi vong lap kep va thuc hien chuong trinh
            case 4:stop_quetphim,backup=phim,chon_ct=(chon_page<<2)+1,contro(1,1),start_quetphim;break;
            case 5:stop_quetphim,backup=phim,chon_ct=(chon_page<<2)+2,contro(1,9),start_quetphim;break;
            case 6:stop_quetphim,backup=phim,chon_ct=(chon_page<<2)+3,contro(2,1),start_quetphim;break;
            case 8:stop_quetphim,backup=phim,chon_ct=(chon_page<<2)+4,contro(2,9),start_quetphim;break;
            default:stop_quetphim,phim=backup;}
        }
      if(phim==2)++chon_page;   //an phim(=) de chon trang khac
      if((phim==1)&&(chon_page>0))--chon_page;  //nhan phim 0 de lui ve trang truoc do
      if(chon_page==10)chon_page=0;   //den trang cuoi cung thi tro ve trang dau
   }
/*-----------------------------------------------------------------------------*/
thuc_hien_chuong_trinh:
cau_hoi_xac_nhan();   //hien thi cau hoi truoc khi chay chuong trinh
while(phim==0);   //chong rung phim
phim=4;   //vi tri mac dinh cua con tro
while(true)   //hien thi con tro tai vi tri YES cho toi khi nao bam phim OK hoac di chuyen    
   {
      if(phim==0)break;   //neu bam phim OK thi thoat khoi vong lap va chay chuong trinh duoc chi dinh
      switch(phim){
      case 4:stop_quetphim,backup=phim,chon=0,contro(2,2),start_quetphim;break;   //YES
      case 5:stop_quetphim,backup=phim,chon=1,contro(2,9),start_quetphim;break;   //NO
      default:stop_quetphim,phim=backup;}
   }
stop_quetphim; //dung quet phim khi khong can dung den phim bam nua
if(chon==0)   //neu chon NO ,hoac thuc hien xong chuong trinh thi tro ve tu dau
   {
      chay_chuongtrinh(chon_ct);
      clear();moveto(1,4);
      for(a=0;str3[a]!='\0';++a){data=str3[a];display();}   //Complete
      delay_ms(800);
   }
}
}
/*-----------------------------------------------------------------*/
/*------------Cac chuong trinh con phuc vu ngat timer--------------*/
/*-----------------------------------------------------------------*/
#int_ext
void ext(void){}
/*--------------------------*/
#int_timer0
void chose(void){
static unsigned int8 x,value0;
++value0;
if(value0==10){
output_a(3<<x++);
if(bit_test(x,3))x=0;
value0=0;
}
}
/*--------------------------*/
#int_timer1
void timer1(void){}
/*--------------------------*/
#int_timer2
void quet(void){
portC=1;   //mo toan bo hang 1
switch(kiemtra){
case 1:phim=12;break;
case 2:phim=13;break;
case 4:phim=14;break;
case 8:phim=15;break;
default:phim=16;}   //neu khong co phim nao duoc an
portC=2;
switch(kiemtra){
case 1:phim=8;break;
case 2:phim=9;break;
case 4:phim=10;break;
case 8:phim=11;break;}
portC=4;
switch(kiemtra){
case 1:phim=4;break;
case 2:phim=5;break;
case 4:phim=6;break;
case 8:phim=7;break;}
portC=8;
switch(kiemtra){
case 1:phim=0;break;
case 2:phim=1;break;
case 4:phim=2;break;
case 8:phim=3;break;}
portC=0;
}
/*--------------------------*/
