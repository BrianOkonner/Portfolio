// Хаткевич Тимофей, 5 группа

#include <iostream>
#include <fstream>
#include "list.h"
#include "maxstring.h"
using namespace std;

struct words
{
	char word[80];
	char ch;
	int len;
	int number;
	words* next;
};


void input_data ( words* &marker )
{
	char* s=new char[80];
	ifstream in ( "input.txt" );
	while (!in.eof())
	{
		in.getline(s,80);
		cut(s, marker);
	}
	in.close();
	marker->next=NULL;
}





void output1 ( words* head )
{
	ofstream out ( "result1.txt" );
	out<<"N   "<<"word   "<<"character     "<<"length      "<<"number of character"<<endl;
	int i=1;
	while (head->next)
	{
		out<<i<<' ';
		out<<head->word<<' '<<head->ch<<' '<<head->len<<' '<<head->number<<endl;
		head=head->next;
		++i;
	}
	out.close();
}





void main()
{
	int** matr=new int*[80];
	for (int i=0; i<=80; ++i)
		matr[i]=new int[3];
	words* head=new words;
	head->next=NULL;
	words* marker=new words;
	marker=head;
	input_data(marker);
	marker=head;
	find_ch(marker); 
	output1(head);
}