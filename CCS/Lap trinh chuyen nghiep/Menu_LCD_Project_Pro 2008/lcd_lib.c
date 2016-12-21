/*********Thu vien cac ham dung cho LCD cua Slowlove**********/
/* xay dung:04/06/2008*/
/*Luu y:truoc khi dung thu vien nay phai dong bo cac bien va cac gia tri khai bao trong chuong trinh*/
/*===========================================================================================*/
#ifdef lcd_8bit   //Neu tu dau chuong trinh dinh nghia la lcd_8bit thi bien dich doan ma sau:
/******Dinh nghia cac chan su dung trong chuomg trinh******/
#bit E   = 0x09.0 //chan e0
#bit RW  = 0x09.1 //chan e1
#bit RS  = 0x09.2 //chan e2
#bit BF  = 0x08.7 //chan d7
#byte data = 0x08 //port D
/*========================================================================*/
/*******cac trang thai tin hieu dieu khien*********/
unsigned int8 read(void)
{
unsigned int8 read;
RW=1;RS=0;
E=0;E=1;
delay_us(1);
read=data;
RW=0;
return read;
}
void command(void)
{
/*chon thanh ghi va chon che do read/write*/
E=1;
RS=0; //chon thanh ghi:RS=0:chon IR;RS=1:chon thanh ghi DR
RW=0; //chon che do:RW=0:chon che do ghi;RW=1:chon che do doc
E=0; //1 xung E 1=>0 dung de kich hoat lenh
delay_us(50);   //doi 50us de thuc hien xong lenh
}
void display(void)
{
E=1;
RS=1;
RW=0;
E=0; //1 xung E 1=>0
delay_us(50);   //doi 50us de thuc hien xong lenh
}
/********khoi tao,khai bao cac thong so hoat dong cho LCD**********/
void khoitao(int1 giao_thuc,int1 so_dong,int1 do_phan_giai)
{
/*giao_thuc =1 hoac 0:che do 8 hoac 4 bit;
  so_dong =1 hoac 0:che do hien thi 2 hoac 1 dong
  do_phangiai =1 hoac 0:hien thi 5x10 hoac 5x8 diem anh
Chu y:trong che do hient hi 2 hang thi khong the hien thi che do 5x10 diem anh*/
delay_ms(40);   //doi 40ms de cho LCD dat toi 4.5V
data=0x20+(giao_thuc<<4)+(so_dong<<3)+(do_phan_giai<<2);   //data phai duoc dinh nghia truoc trong chuong trinh chinh
command();
}
/*****Xoa man hinh tro ve dau dong*****/
void clear(void)
{
data=0x01;
command();
}
/******di chuyen con tro ve dau dong*******/
void return_home(void)
{
data=0x02;
command();
}
/*******Hien thi con tro********/
void cursor(int1 manhinh,int1 contro,int1 kieu_contro)
{
/*manhinh = 1 hoac bang 0:hien thi man hinh hoac khong hien thi man hinh
  contro  = 1 hoac bang 0:hien thi con tro hoac khong hien thi con tro
  kieu_contro =1 hoac bang 0:2 che do hien thi con tro*/
data=0x08+(manhinh<<2)+(contro<<1)+(kieu_contro);
command();
}
/******Dua con tro toi 1 toa do cho truoc*******/
void moveto(unsigned char dong,unsigned char vitri)
{
/*nguoi dung se nhap toa do cua vi tri can hien thi tren LCD,cu the la dong 1
hay dong 2,vi tri cua con tro can hien thi 1 to 16*/
if(dong==1)data=0x80+(vitri-1);  //dong 1 co dia chi bat dau tu 0x80
else data=0xC0+(vitri-1);        //dog 2 co dia chi bat dau tu 0x0C
command();
}
/********Di chuyen con tro va ki tu********/
void motion(int1 contents,int1 trend)
{
/* contents = 0 hoac 1:chon con tro hoac ca con tro & van ban
   trend = 0 hoac 1: chon huong sang trai hoac sang phai voi con tro,van ban theo
   chieu nguoc lai 0 hoac 1 sang phai hoac sang trai
   Chu y: neu o che do hien thi 2 hang thi khi het dong dong dau tien thi se
   tu dong chuyen xuong duong thu 2,du lieu hang dau va hang 2 cung dich 1 luc*/ 
data=0x10+(contents<<3)+(trend<<2);
command();
}
/******thiet lap thong so hien thi******/
void modeset(int1 trend,int1 mode)
{
/* trend = 0 hoac 1 :dich sang phai hoac trai
   mode  = 0 hoac 1 :khong dich hoac dich hien thi*/
data=0x04+(trend<<1)+mode;
command();
}
#endif
/*================================================================*/
/*===========================The End==============================*/
/*================================================================*/
#ifdef lcd_4bit   //Neu tu dau chuong trinh dinh nghia la lcd_4bit thi bien dich doan ma sau:
/******Dinh nghia cac chan su dung trong chuomg trinh******/
#bit RS = 0x08.0
#bit RW = 0x08.1
#bit E  = 0x08.2
#bit d0 = 0x08.3   //|
#bit d1 = 0x08.4   //|cac duong data(d0-d3)
#bit d2 = 0x08.5   //|cua LCD
#bit d3 = 0x08.6   //|
/*--------------------------------------------------------------------*/
extern unsigned int8 data;
unsigned int8 read(void)
{
unsigned int8 read1,read2;
Set_tris_d(0x78);  //3 chan dau+chan cuoi la chan ra con lai la chan vao
RW=1;RS=0;
E=0;E=1;
delay_cycles(1);
read1=(d3<<7)|(d2<<6)|(d1<<5)|(d0<<4);
E=0;E=1;
delay_us(1);
read2=(d3<<3)|(d2<<2)|(d1<<1)|d0;
RW=0;
set_tris_d(0);
return (read1|read2);
}
/*----------------------------*/
void command(void)
{
/*chon thanh ghi va chon che do read/write*/
while(bit_test(read(),7));
d0=bit_test(data,4);
d1=bit_test(data,5);
d2=bit_test(data,6);
d3=bit_test(data,7);
delay_cycles(1);
E=1;E=0;
d0=bit_test(data,0);
d1=bit_test(data,1);
d2=bit_test(data,2);
d3=bit_test(data,3);
E=1;E=0;
}
void display(void)
{
while(bit_test(read(),7));
RS=1;
d0=bit_test(data,4);
d1=bit_test(data,5);
d2=bit_test(data,6);
d3=bit_test(data,7);
delay_cycles(1);
E=1;E=0;
d0=bit_test(data,0);
d1=bit_test(data,1);
d2=bit_test(data,2);
d3=bit_test(data,3);
delay_cycles(1);
E=1;E=0;
}
/********khoi tao,khai bao cac thong so hoat dong cho LCD**********/
void khoitao(int1 so_dong,int1 do_phan_giai)
{
/*so_dong =1 hoac 0:che do hien thi 2 hoac 1 dong
  do_phangiai =1 hoac 0:hien thi 5x10 hoac 5x8 diem anh
Chu y:trong che do hient hi 2 hang thi khong the hien thi che do 5x10 diem anh
va ban dau luc cap nguon cho LCD mac dinh se hoat dong o che do 8 bit nen
khong the thuc hien cac lenh dat giao thuc cho LCD bang giao thuc 4 bit nen 
phai send 4 bit cao truoc de chuyen bi giao thuc 4 bit roi moi thuc hien nhung
thiet dat tiep theo va cac lenh tiep theo se duoc thuc hien theo giao thuc 4 bit*/
delay_ms(40);   //doi 40ms de cho LCD dat toi 4.5V
RS=0; //chon thanh ghi:RS=0:chon IR;RS=1:chon thanh ghi DR
RW=0; //chon che do:RW=0:chon che do ghi;RW=1:chon che do doc
d3=0;d2=0;d1=1;d0=0;
E=1;E=0; //1 xung E 1=>0 dung de kich hoat lenh
data=0x20|(so_dong<<3)|(do_phan_giai<<2);
command();
}
/*****Xoa man hinh tro ve dau dong*****/
void clear(void)
{
data=0x01;
command();
}
/******di chuyen con tro ve dau dong*******/
void return_home(void)
{
data=0x02;
command();
}
/*******Hien thi con tro********/
void cursor(int1 manhinh,int1 contro,int1 kieu_contro)
{
/*manhinh = 1 hoac bang 0:hien thi man hinh hoac khong hien thi man hinh
  contro  = 1 hoac bang 0:hien thi con tro hoac khong hien thi con tro
  kieu_contro =1 hoac bang 0:2 che do hien thi con tro*/
data=0x08|(manhinh<<2)|(contro<<1)|(kieu_contro);
command();
}
/******Dua con tro toi 1 toa do cho truoc*******/
void moveto(unsigned char dong,unsigned char vitri)
{
/*nguoi dung se nhap toa do cua vi tri can hien thi tren LCD,cu the la dong 1
hay dong 2,vi tri cua con tro can hien thi 1 to 16*/
if(dong==1)data=0x80|(vitri-1);  //dong 1 co dia chi bat dau tu 0x80
else data=0xC0|(vitri-1);        //dog 2 co dia chi bat dau tu 0x0C
command();
}
/******Set CGRAM address********/
void cgramadd(unsigned int8 vitri,unsigned int8 add)
{
data=0x40|data|vitri<<3;
command();
}
/********Di chuyen con tro va ki tu********/
void motion(int1 contents,int1 trend)
{
/* contents = 0 hoac 1:chon con tro hoac ca con tro & van ban
   trend = 0 hoac 1: chon huong sang trai hoac sang phai voi con tro,van ban theo
   chieu nguoc lai 0 hoac 1 sang phai hoac sang trai
   Chu y: neu o che do hien thi 2 hang thi khi het dong dong dau tien thi se
   tu dong chuyen xuong duong thu 2,du lieu hang dau va hang 2 cung dich 1 luc*/ 
data=0x10|(contents<<3)|(trend<<2);
command();
}
/******thiet lap thong so hien thi******/
void modeset(int1 trend,int1 mode)
{
/* trend = 0 hoac 1 :dich sang phai hoac trai
   mode  = 0 hoac 1 :khong dich hoac dich hien thi*/
data=0x04|(trend<<1)|mode;
command();
}
#endif
/*================================================================*/
/*===========================The End==============================*/
/*================================================================*/
