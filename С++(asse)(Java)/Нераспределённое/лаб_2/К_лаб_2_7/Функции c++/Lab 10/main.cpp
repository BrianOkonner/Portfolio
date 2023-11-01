
//made by ћинец јлександр, 8 группа 2009_10
/*9. «адан текстовый файл Input.txt, состо€щий из слов, и некоторое предложение. 
–азделител€ми между словами €вл€етс€ некоторое множество знаков препинани€. 
Ќайти строки, в которых встречаетс€ данное предложение, 
продублировать первое и последнее слова предложений.   
–езультат записать в новый файл Output.txt. 
”пор€дочить слова  в искомых предложени€х по убыванию длин слов, 
результат сортировки записать в файл Out_sort.txt. 

ћы сортируем строку без добавленных в начало и конец дубликатов слов. ƒубликаты
добавл€ютс€ в начало и конец строки соответственно через пробел.

 оличество слов не должно превышать 255, иначе получим переполнение в сортировке.
ƒлина всех строк (вводимые и преполагаемые к получению) не должна превосходить maxLength.
¬се основные функции дл€ работы со строками были написаны на asm, на C++ же написаны лишь
работа с файлами, ввод-вывод, вызов функций, цикл дл€ заполнени€ массива слов и 
добавление пробелов между словами. ѕоследние два пункта (массив и пробелы) были сделаны
на C++ исключительно во избежание загромождени€ программы лишними ассемблерными вставками
и удобства оформлени€-чтени€.*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
using namespace std;

const int maxLength=1000;

void main()				//made by ћинец јлександр, 8 группа
{
	int i=0,n=0,ind=1;
	char* k=NULL;
	char** mas=new char*[255];
	char *str1=new char[maxLength],*sent=new char[maxLength],*strout=new char[maxLength];
	char *strtmp=NULL;
	FILE *fin,*fout,*fsort;

	setlocale(LC_ALL,".1251");

	fin=fopen("input.txt","r");
	fout=fopen("output.txt","w");
	fsort=fopen("outSort.txt","w");

	sent[0]='\0';
	k=&sent[0];
	while ((*k)=='\0')
	{
		printf("¬ведите строку-ключ\n");
		gets(sent);
		k=findFirstWord(sent,n);
	}

	while (!feof(fin))
	{
		fgets(str1,maxLength,fin);
		delEndl(str1);	//убираем символ переноса строки
		if (ifSent(sent,str1))	//проверка на вхождение предложени€ в строку
		{	//записываем в output.txt
			strout[0]='\0';
			strtmp=findFirstWord(str1,n);
			addWordEnd(strout,strtmp,n);
			addWordEnd(strout," ");		//дублируем первое слово
			addWordEnd(strout,str1);
			strtmp=findLastWord(str1,n);
			addWordEnd(strout," ");
			addWordEnd(strout,strtmp,n);	//дублируем последнее слово
			fprintf(fout,"%s\n",strout);	//записываем результат

			i=0;		//обнул€ем число слов в массиве
			k=detFirstWord(str1);
			while ((*k)!='\0') 
			{
				mas[i]=k;
				i++;
				k=detFirstWord(str1);
			}								//поделили строку на слова
			sortArrWord(mas,i);				//отсортировали массив
			strout[0]='\0';
			for(int j=0;j<i;j++) 
			{
				addWordEnd(strout,mas[j]); 
				if (j!=i-1) addWordEnd(strout," ");
			}								//записываем отсортированный массив в строку
			fprintf(fsort,"%s\n",strout);	//и в файл
			//cout<<strout<<endl;
		}
		printf("—трока %d обработана\n",ind);
		ind++;
	}
	fclose(fin);
	fclose(fout);
	fclose(fsort);
	delete[] mas;
}