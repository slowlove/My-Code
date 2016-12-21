unsigned int test(char chuoi[])	//ham kiem tra do dai cua chuoi
{
	unsigned int cout=0;	//khoi tao can thiet
	while(chuoi[cout]!='\0')cout++;
	return cout;
}
/*--------------------------------------------------*/
char* daochuoi(char *str)		//dao nguoc 1 chuoi~
{
	unsigned int m,n=0;
	m=n=strlen(str);	//them n de ko anh huong toi m
	char *invert =new char[n];
	for(int b=0;b<=n;b++)invert[b]=*(str+(--m));
	return invert;
}
/*-------------------------------------------------*/
char* std_chuoi(char *begin,char c)	//Ham chuan hoa chuoi~
{
	uint a;
	char *b;
	//Loai bo nhung~ki tu dac biet
	a=0;
	while(*(begin+a)!='\0')
	{
		b=begin+a;
		if((*b<'0'|*b>'9')&(*b<'A'|*b>'Z')&(*b<'a'|*b>'z')& *b!=' ')*b=' ';
		a++;
	}	
	//xoa khoang trang 2 dau
	char *end=begin+strlen(begin);
	while(*begin==' ')begin++;
	while((*end==' ')|(*end=='\0'))end--;
	*(++end)='\0';	//tao null cuoi'chuoi~
	//xoa ki tu trung`(space)
	a=0;
	while(*(begin+a)!='\0')
	{
		b=begin+a;		
		while(*b==c && *(b+1)==c)memmove(b,b+1,strlen(b));
		a++;
	}
	return begin;
}
/*-----------------------------------------------------*/
char* strcpy_std(char *des,char *src)	//sao chep 1 chuoi~=>1 chuoi~#
{
	uint c,d;
	d=strlen(src);
	for(c=0;c<=d;c++)*(des+c)=*(src+c);
	return des;
}