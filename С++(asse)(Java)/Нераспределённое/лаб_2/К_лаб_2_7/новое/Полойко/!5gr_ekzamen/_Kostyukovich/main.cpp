//Костюкович. Группа №5

#include <iostream>
#include <stdio.h>
#include "Kostlib.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct spis
{
	int n;
	char wor[80];
	spis *next;
};

bool sitest(char ch)//Проверка символа на разделитель
{
	const char sign[7]={' ','.',',',';',':','!','-'};
	int i=0;
	while (i<7)
	{
		if (ch==sign[i]) return true;
		else i=i+1;
	}
	if (i==7) return false;
}

void main()
{
	setlocale(LC_ALL,".1251");
	ifstream in("input.txt");
	ofstream out ("result.txt");
	char str[80];
	int k = 0;
	int i = 0;
	char signs[] = {' ','.',',',';',':','!','-'};
	spis *words = new spis;
	spis *first = words;
	char chh[80]="";
	int j=0;

	if (!in.is_open()) cout << "File not open!\n";
	else
	{
		while ( in.getline( str, 80 ) )
		{
			int qu=strlen(str);
			i=0;
			while(i!=qu-1)
			{

				if (!(sitest(str[i]))&&(!(sitest(str[i+1])))) 
				{
					chh[j]=str[i];
					j=j+1;
				}
				else
					if (!(sitest(str[i]))&&(sitest(str[i+1])))
					{
						chh[j]=str[i];
						j=0;
						k=k+1;
						spis *temp = new spis;
						temp->n = k;
						strcpy(temp->wor,chh);
						words->next = temp;
						temp->next = NULL;
						words = temp;
					}
				i=i+1;
			
			}
		}

		spis *last;
		last=first->next;
		int len;
		int mmax=0;
		int ind;
		int l=0;
		out << "Номер слова Слово Символ Длина посл. Номер символа\n";
		while (last!=NULL)
		{
			len = strlen(last->wor);
			int mmax=0;
			int ind=0;
			int l=0;
			for(int j=0;j<len;j++)
			{
				if (last->wor[j]==last->wor[j+1]) l=l+1;
				else 
				{
					if (l>mmax) {mmax=l; ind=j;} 
					l=0;
				}
			}
			out << last->n << "     ";
			out << last->wor<< "     ";
			out <<"     "<< last->wor[ind]<< "     ";
			out << mmax <<"     "<< ind << endl;
			last=last->next;
		}

	}
}