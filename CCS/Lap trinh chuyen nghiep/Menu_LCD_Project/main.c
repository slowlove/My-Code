#include <16F877A.h>
#device *=16 adc=10
#use delay(clock=20M)
#define lcd_4bit  //Su dung LCD the giao thuc 4bit
#include <lcd_lib.c>
#include <menu_list.c>
#include <program.c>
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT
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
unsigned int1 chon;
unsigned int8 a;   //bien da nang,su dung lam gi cung duoc
unsigned int8 phim,chon_ct,chon_page,backup;
unsigned int8 data;   //bien toan cuc co trong moi file khi link cac file *.c de complier
/*-----------------------------------------------------------------*/
/*----------------------cac chuong trinh con-----------------------*/
/*-----------------------------------------------------------------*/
void muiten(void){data=0x7e;display();}    //bieu tuong con tro (->)
void eraser(void){data=' ';display();}   //ki tu rong(xoa ki tu)
void vach(void){data=0xff;display();}   //vach % qua trinh xu li
/*----------------------*/
void contro(unsigned int8 dong,cot){
moveto(dong,cot);muiten();
delay_ms(20);
moveto(dong,cot);eraser();
delay_ms(20);
}
/*-----Loi Chao------*/
void wellcome(void){
const unsigned char msg1[]={"BAN QUYEN SP CUA"};
const unsigned char msg2[]={"Slowlove-(29/06)"};
for(a=0;msg1[a]!='\0';++a){data=msg1[a];display();}
moveto(2,1);
for(a=0;msg2[a]!='\0';++a){data=msg2[a];display();}
delay_ms(1000);
}
/*------------------*/
void cau_hoi_xac_nhan(void){
const unsigned char msg1[]={"Co muon chay CT?"};
const unsigned char msg2[]={"  YES 1  NO 2  "};
clear();
for(a=0;msg1[a]!='\0';++a){data=msg1[a];display();}
moveto(2,1);
for(a=0;msg2[a]!='\0';++a){data=msg2[a];display();}
}
/*------------------*/
void thong_bao_complete(void){
const unsigned char msg[]={"Complete !"};
clear();moveto(1,4);
for(a=0;msg[a]!='\0';++a){data=msg[a];display();}   //Complete
delay_ms(800);
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
      thong_bao_complete();   //complete
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
