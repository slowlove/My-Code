/*-----------------Khai bao bien su dung trong chuong trinh---------------*/
extern unsigned int8 a,data;
/*-------------------------------------------------------------------------------------*/
/*--------Noi dung cua cac Menu duoc to chuc thanh cac chuong trinh con------------*/
/*-------------------------------------------------------------------------------------*/
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
/*----------Chuong trinh con lua chon menu theo bien page-------------------*/
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
/*--------------------The end-------------------*/
