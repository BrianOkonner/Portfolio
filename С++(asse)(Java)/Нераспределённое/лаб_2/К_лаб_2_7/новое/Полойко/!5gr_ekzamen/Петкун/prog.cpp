//Петкун_5_группа
#include "List.h"
#include "maxstr.h"
#include <iostream>
#include <fstream>
using namespace std;
void main()
{
	int len,num;
	char sym;
	int pos=0;
	//setlocale(LC_ALL,".1251");
	char seps[]=" -,.;:!";
	ifstream in;
	in.open("Input.txt");
	ofstream out;
	out.open("Result1.txt");
	out<<"Номер слова   "<<"Слово   "<<"Символ   "<<"Длина    "<<"Номер символа"<<endl;
	char* token;
	char* s;
	s=new char[90];
	int** Matr;
	Matr=new int*[100];
	for (int i=0; i<100; i++)	Matr[i]=new int [5];
	init_list();
	while (in.getline(s,90))
	{
		char* str;
		token=strtok(s,seps);
		while (token!=NULL)
		{
			//cout<<token<<endl;
			str=new char[80];
			strcpy(str,token);
			insert(str,pos);
			maxstr(token,sym,len,num);
			pos++;
			out<<pos<<"            "<<token<<"       "<<sym<<"          "<<len<<"          "<<num<<endl;
			token=strtok(NULL,seps);
		}
	}
}