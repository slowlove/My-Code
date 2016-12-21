#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT 
#use delay(clock=20000000)                              
unsigned char a,b;
 unsigned char toled7seg(unsigned char n)
 {
 switch(n)   
 {
 case 0x00:n=0x40;break; 
 case 0x01:n=0x79;break;
 case 0x02:n=0x24;break;
 case 0x03:n=0x30;break;
 case 0x04:n=0x19;break;
 case 0x05:n=0x12;break;
 case 0x06:n=0x02;break;
 case 0x07:n=0x78;break;
 case 0x08:n=0x00;break;
 case 0x09:n=0x10;break;  
 }
 return(n);             
 }
 void tachso(unsigned char value)
 {
 b=value%10;  
 a=(value-b)/10;  
 }
 void hienthi(unsigned display)
 {
 unsigned char m;
 tachso(display);             
 for(m=0;m<2;m++)
 {
 output_b(toled7seg(b));
 output_c(0x01);
 delay_ms(50);
 output_b(toled7seg(a));
 output_c(0x02);
 delay_ms(50);
 }
 }
 void main(unsigned char x)
 {
 while(1){
 for(x=0x00;x<=99;x++){
 hienthi(x);}
 }
 }
