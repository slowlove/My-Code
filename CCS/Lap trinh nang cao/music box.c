#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=24000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/*************************************************************************************/
void a(unsigned int ring){
unsigned int a;
for(a=0;a<ring;a++){
output_bit(pin_c0,1);
delay_us(1136);
output_bit(pin_c0,0);
delay_us(1136);
}
}
/********************************/
void main(){
output_low(pin_c3);
while(1){
a(50);delay_ms(10);
a(0);delay_ms(50);
a(50);delay_ms(10);
a(0);delay_ms(50);
a(50);delay_ms(10);
a(0);delay_ms(50);
a(50);delay_ms(200);
a(0);delay_ms(300);
}
}

