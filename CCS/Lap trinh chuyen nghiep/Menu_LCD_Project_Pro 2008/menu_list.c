/*-----------------Khai bao bien su dung trong chuong trinh---------------*/
extern unsigned int8 a,b,data;
/*--------------------------------------*/
const unsigned char menu[32][8]={   //ko duoc SD vuot qua 256
      {"Meter 1"} {"(SMS) 2"} {"Timer 3"} {"Calc  4"}
      {"SAG_DON"} {"CDMS  6"} {"OFDM  7"} {"FPGA  8"}
      {"(PCM) 9"} {"(PWM)10"} {"(PAM)11"} {"(POW)12"}
      {"menu 13"} {"menu 14"} {"menu 15"} {"menu 16"}
      {"menu 17"} {"menu 18"} {"menu 19"} {"menu 20"}
      {"menu 21"} {"menu 22"} {"menu 23"} {"menu 24"}
      {"menu 25"} {"menu 26"} {"menu 27"} {"menu 28"}
      {"opt1 29"} {"opt2 30"} {"opASK31"} {"opHOM32"}
};
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
void menu_display(unsigned int8 page){
b=page<<2;
moveto(1,2);for(a=0;menu[b][a]!='\0';++a){data=menu[b][a];display();}
moveto(1,10);for(a=0;menu[b+1][a]!='\0';++a){data=menu[b+1][a];display();}
moveto(2,2);for(a=0;menu[b+2][a]!='\0';++a){data=menu[b+2][a];display();}
moveto(2,10);for(a=0;menu[b+3][a]!='\0';++a){data=menu[b+3][a];display();}
}
/*--------------------The end-------------------*/

