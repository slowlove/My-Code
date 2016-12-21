#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/*************************************************************************************/
void main(){
unsigned char x;
set_tris_c(0xf9);   //dat 2chan ccp_pwm la output con cac chan con lai la input
output_c(0);
output_b(0);
setup_timer_2(t2_div_by_16,255,16);//t2_div_by_16:bo chia tan cho 16 => moi lan dem se mat thoi gian la (4/f*16)
                                   //tang den 255 thi reset=>timer 2 se tran` sau 255*4/f*16
                                   //sau 16 lan tran timer 2 thi xay ra ngat=>sau 16*255*4/f*16 se xay ra ngat timer 2
                                   //tong cong thoi gian~13ms
setup_ccp1(ccp_pwm);
setup_ccp2(ccp_pwm);
while(true){
while(x!=1023){
x++;
set_pwm1_duty(x);
set_pwm2_duty(x);
delay_us(2500);}
delay_ms(500);
while(x>0){
x--;
set_pwm1_duty(x);
set_pwm2_duty(x);
delay_us(2500);}
}
}
