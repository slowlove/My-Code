#include <16F877A.h>
#device *=16
#fuses NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT      //khai bao cac thiet dat cho PIC
#use delay(clock=20000000)  //khai bao su dung thach anh 20MHz de su dung ham delay cua chuong trinh
/****************************Ket thuc phan khai bao****************************/
int1 mau=0;  //bien mau dung de dao mau moi khi het 1 anh quet
unsigned char colour;   //bien xac dinh mau sac cua ki tu
unsigned char vitri,kitu,n=0;   //cac bien thuoc tinh cau ki tu
int16 value;   //bien dem trong chuong trinh ngat,co tac dung tranh dung ham
               //delay trong ngat de chuong trinh chinh lam viec khac
/***********Hang ki tu duoc ma hoa duoi dang mang 8x8 toi da duoc 32 ki tu************/
const unsigned char ma_kitu[32][8]=    //neu so luong hang vuot qua 32 se bi                           
             {                         //tran RAM vi mang toi da la 256 byte  
                            {0x00,0x66,0xE7,0xE7,0xE7,0xE7,0x66,0x00}  //I
                            {0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3B,0x03}  //L
                            {0xFF,0x99,0x66,0x7E,0xBD,0xDB,0xE7,0xFF}  //heart
                            {0x3C,0x3C,0x3C,0x3C,0x99,0xC3,0xC3,0xE7}  //V
                            {0x01,0x3D,0x37,0x07,0x07,0x37,0x3D,0x01}  //E
                            {0x18,0xBD,0xDB,0xE7,0xEF,0xDF,0x3F,0xFF}  //Y
                            {0xC7,0x39,0x39,0x39,0x39,0x39,0x39,0xC7}  //O
                            {0x18,0xBD,0xBD,0xBD,0xBD,0xBD,0xBD,0xC3}  //U
             };
/********Chuong trinh con thay doi mau sac  cua chu************/
void set_colour(void)
   {
      switch(n)
         {
         case 0:colour=0;break;
         case 1:colour=0;break;
         case 2:colour=1;break;
         case 3:colour=1;break;
         case 4:colour=1;break;
         case 5:colour=1;break;
         case 6:colour=2;break;
         case 7:colour=2;break;
         }
   }         
/*************chuong trinh phuc vu ngat timer 0***************/
#int_timer0
void quetled(void)
   {
      set_timer0(246);   //sau 8us
      ++value;   
   if(value==10)   //sau 8us*10=80us
      {  
         set_colour();  //xac lap mau cho tung dong
         output_c(0);output_b(0xff);output_d(0xff);   //xoa toan bo nhung gi da hien thi truoc do,cong viec nay rat quan trong nham tranh chong mau khi hien thi
         switch(colour) //chon mau truoc khi dua vao hien thi
         {
         case 0:output_d(ma_kitu[kitu][n]);   //mau xanh               
            break;
         case 1:
            {  
               if(mau==0)output_d(ma_kitu[kitu][n]);
               else output_b(ma_kitu[kitu][n]);
            }
            break;
         case 2:output_b(ma_kitu[kitu][n]);   //mau do              
            break;
         }
         output_c(vitri<<n);  //quet cot
         n++;
         if(n==8)
            {  
               n=0;  //quet lai tu dong dau dong thoi dao mau`
               mau=!mau; //dao? mau`   
            }
         value=0; //khoi tao lai bien dem         
      }
   }
/*********Chuong trinh chinh**************/
void main(void){
output_b(0);output_d(0);output_c(0);   //tat port B&C de tranh Error khi nap chuong trinh
delay_ms(5000);   //doi 5s de cho` tin hieu nap chuong trinh
enable_interrupts(int_timer0);   //cho phep ngat timer 0 hoat dong
setup_timer_0(rtcc_internal|rtcc_div_4);  //thiet dat cac thong so cho timer 0
enable_interrupts(global); //cho phep ngat toan cuc hoat dong
kitu=0;  //bat dau hien thi tu ki tu dau tien trong danh sach mang
while(true)
   {
      vitri=1; //bat quet tu hang tren cung(hang dau tien)
      delay_ms(350);    
      while(vitri!=0)
         {  
            vitri<<=1;  //dich ca chu cho den khi het dong
            delay_ms(70);
         }
      kitu++;  //chuyen sang ki tu tiep theo
      if(kitu==8)kitu=0;   //vong lai tu dau neu gap ki tu thu 8
   }
}
