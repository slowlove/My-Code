#include <iostream.h>
#include <conio.h>
unsigned int traudung,traunam,traugia,kq=1;
void main()
{
	cout<<"         ===========================         "<<endl;
	cout<<"         =====Bai toan con trau=====         "<<endl;
	cout<<"         ===========================         "<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++"<<endl<<"+++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	for(traudung=1;traudung<99;traudung++)
	{
		for(traunam=1;traunam<99;traunam++)
		{
			for(traugia=1;traugia<99;traugia++)
			{
				if(((traudung*15+traunam*9+traugia)==300)&&((traudung+traunam+traugia)==100))
				{
					cout<<"     Ket qua "<<kq++<<endl<<"     ---------"<<endl;
					cout<<"  So Trau dung : "<<traudung<<endl;
					cout<<"  So Trau nam  : "<<traunam<<endl;
					cout<<"  So Trau gia  : "<<traugia<<endl;
					cout<<"  ================="<<endl;
				}
			}		
		}
	}
	getch();
}

