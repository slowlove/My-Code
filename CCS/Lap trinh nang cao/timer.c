#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai baìo caìc thiêìt ðãòt cho PIC
#use delay(clock=24000000)                               //khai baìo sýÒ duòng thaòch anh 20Mhz ðêÒ sýÒ duòng haÌm delay cuÒa chýõng triÌnh
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
setup_timer_0(rtcc_internal|rtcc_div_4);   //choòn xung dao ðông nôòi vaÌ hêò sôì chia trýõìc theo tiÒ lêò 1/4
enable_interrupts(global);
while(true);
}
