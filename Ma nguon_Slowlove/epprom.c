#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)                               //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
void main(void){
unsigned char a;
while(true){
output_d(a=read_eeprom(00));
delay_ms(300);
a++;
write_eeprom(00,a);
}
}
