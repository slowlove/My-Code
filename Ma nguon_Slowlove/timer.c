#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai ba�o ca�c thi��t ���t cho PIC
#use delay(clock=24000000)                               //khai ba�o s�� du�ng tha�ch anh 20Mhz ��� s�� du�ng ha�m delay cu�a ch��ng tri�nh
/*************************************************************************************/
unsigned char a=0x01;
long value;
#int_timer0
void ngat(void){
set_timer0(106);
value++;
if(value==10000){
output_c(a<<=1);
value=0;}
}
void main(void){
enable_interrupts(int_timer0);
setup_timer_0(rtcc_internal|rtcc_div_4);   //cho�n xung dao ��ng n��i va� h�� s�� chia tr���c theo ti� l�� 1/4
enable_interrupts(global);
while(true);
}
