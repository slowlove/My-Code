/********Cac ham chuyen doi ma va ki tu cua Slowlove*********/
/*xay dung 04/06/2008*/
 /* chu y:
   Ta co the them bien toan cuc o moi luc,moi noi khi viet chong trinh duoc chua trinh duoc chua trong
1 tep.Song neu cac ham duoc viet chua trong cac tep rieng re thi van de lai thay doi:khong truy 
cap duoc.
   De gai quyet van de nay ,C chi phep khai bao cac bien toan cuc nay lai 1 lan nua trong tat ca cac 
tep.Tuy nhien chi 1 trong so cac tep nay co cac khai bao nhu binh thuong.Trang cac tep khac chung ta
su dung bien nay thi khai bao co them tu khoa  extern
VD:
   extern int bien_toan_cuc;
tu khoa extern thong bao rang bien_toan_cuc khong phai la bien moi,no da duoc dinh nghia va khia bao o
nhung cho khac va dung(khong) cap bo nho cho bien_toan_cuc o trong tep nay.Chuong trinh ket noi se tim 
ra khai bao bien nay voi dk no duoc khai bao trong 1 va chi 1 trong cac tep duoc ket noi
 */
 /***********Program conver data on port to led 7 seg***********/
 unsigned char toled7seg(unsigned char n)
 {
 const unsigned char ma_so[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   // ma cua so 0-->9 duoi dang hex de hien thi tra led 7 doan
 // {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};   ma led 7 SD dau cham dong
 return ma_so[n];
 }
 /*********Chuyen doi sang ma Led 7 doan su dung con tro************/
 
