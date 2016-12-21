#include <AT89X51.H>
void delay(int time) 
{ 
 unsigned int n; 
  for(n=0;n<time;n++); 
} 
void main(void) 
{unsigned char a,b;

for(b=0x03;1;b=b*2)
{
P1=b;
delay(10000);}
for(a=0xc0;a<=0xc0;a=a/2)
{P1=a;
delay(10000);
if(a==0x03) break;
}

 }