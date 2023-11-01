// Богомолов_практика_экзамен.cpp : Defines the entry point for the console application.
//Богомолов Дмитрий 5ая группа.

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "List.h"
using namespace std;

int kolichestvo_vhozhdenii_podstroki (char *str, char *podstr)
{
	int i=0;
	while (strstr(str,podstr)!=NULL)
	{
		i=i+1;
		str=strstr(str,podstr);
		str=str+1;
	}
	return i;
}
//////////////////////////////////////////
char find_max_repeat_char (char* word)
{
	char ch,stat_ch;
	int stat_it=-1,it,big_it,i=0;
	
	for (int i=0;i<(int)strlen(word);i=i+1)
	{
		it=0;
		big_it=0;
		ch=word[i];
		for(int j=i;j<(int)strlen(word);j=j+1)
			if (ch==word[j]) it=it+1;
			else if (big_it<it)
			{
				big_it=it;
				stat_ch=ch;//
				it=0;
			}
	}
	if (it>stat_it)//проверка если слово закончилось
		{
			stat_it=it;
			stat_ch=ch;
		}
	//не рациональный выходи из положения. не считает первую подпоследовательность.
	while ((i<(int)strlen(word))&&((word[1])==word[i]))
	{
		i=i+1;
	}
	if (i>stat_it)
	{
		stat_ch=word[1];
	}
	///
	return stat_ch;
}
//////////////////////////////////////////
int find_position_with_max_lengt(char *word, char c)
{
	int stat_len=-1,pos=0,stat_pos,len=0;
	for (int i=0;i<(int)strlen(word);i=i+1)
	{
		if(word[i]==c)
		{
			if(pos==0)pos=i;
			len=len+1;
			if(stat_len<len)
			{
				stat_pos=pos;
				stat_len=len;
			}
		}
		else 
		{
			pos=0;
			len=0;
		}
	}
	return stat_pos;
}
//////////////////////////////////////////
int find_length_from_position (char *word,char s,int pos)
{
	int len=0;
	int i=pos;
	while ((word[i]==s)&&(i<(int)strlen(word)))
	{
		len=len+1;
		i=i+1;
	}
	////если позиция 1
	if(pos==1)len=len+1;
	return len;
}
//////////////////////////////////////////
bool razdel(char symbol)
{
	bool induk=false;
	char mas[7]={'+','.',',',';',':','!','-'};
	int i=0;
	while(i<7)
	{
		if(symbol==mas[i])induk=true;
		i++;
	}
	return induk;
}

//////////////////////////////////////////
void main()
{
	fstream in,out;
	in.open("Input.txt");
	if (in.fail())cerr<<"\n File not found.";
	else 
	{
		int n=1;
		char bringer[80],str[80],ch;
		/*printf(" Vvedite razmer matrici: ");
		scanf("%d",&n);
		int** matr = new int*[n];
		for (int i=0;i<n;i++)
			matr[i]= new int[n];*/
		init_list();
		int leng,position,length_char;
		out.open("Result1.txt");
		out<<"\t nomer slova "<<"\t slovo"<<"\t\t simvol"<<"\t dlina"<<"\t nomer simvola";
		while (in.good())
		{
			in>>str;
			leng=strlen(str);
			//cout<<leng;
			if (razdel(str[leng-1]))str[leng-1]='\0';
			//тут у нас есть уже слово без знака препинания

			ch=find_max_repeat_char(str);
			position=find_position_with_max_lengt(str,ch);
			length_char=find_length_from_position(str,ch,position);
			printf("\n %s : %c : %d : %d",str,ch,position+1,length_char);
			//
			out<<"\n\t"<<n<<"\t\t\t"<<str<<"\t\t\t\t"<<ch<<"\t\t"<<length_char<<"\t\t"<<position;
			push_in_list(str,&ch,position,length_char);
			n=n+1;
		}


	}
}

