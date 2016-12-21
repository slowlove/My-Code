#include <AT89X51.H>
void tre(int time) 
{ 
 unsigned int n; 
  for(n=0;n<time;n++); 
} 
void main(void) 
{unsigned char b;
for(b=0x03;b>=0x03;b*2){
P1=b;delay(10000);}
}
