extern unsigned int8 a,data;
/*----------------------------------------------------------------------------*/
/*----------------------Cac chuong trinh can thuc hien-----------------------*/
/*----------------------------------------------------------------------------*/
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
/*--------------------------------------*/
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
/*--------------------------------------*/
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
/*--------------------------------------*/
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
/*--------------------------------------*/
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
/*------------Chuong trinh con phuc vu viec chon chuong trinh ---------------*/
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
case 40:chuongtrinh40();break;}
}
/*------------The end------------*/
