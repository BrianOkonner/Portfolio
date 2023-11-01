#include<iostream>
#include<fstream>
#include<stdio.h>
#include"list.h"

using namespace std;

spisok_slov* add_el(spisok_slov* el,char* slovon,int n)
{
	spisok_slov* new_el,*uk;
				el;
				new_el=new spisok_slov;
				new_el->slovo=new char[n];
				new_el->next=NULL;
				strcpy(new_el->slovo,slovon);
				return (new_el);
}