#include<iostream>
#include<fstream>
#include<stdio.h>
#include"vspom_func.h"

using namespace std;

struct spisok_slov
{
	char* slovo;
	char simvol;
	int dl,pos;
	spisok_slov* next;
};

void add_el(spisok_slov* el,char* slovon,int n)
{	
	spisok_slov* new_el;
	new_el=new spisok_slov;
	strcpy(new_el->slovo,slovon);
	if (el!=NULL)
	{
		while (el->next!=NULL)
			el=el->next;
		el->next=new_el;
	}
	else
		el=new_el;
}