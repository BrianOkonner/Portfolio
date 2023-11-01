/*Колодко 5 группа */
#include <iostream>
#include <fstream>
#include <string.h>
#include "List.h"
#include "maxString.h"
using namespace std;
struct spis						
	{
		char* slovo;					
		spis*  next;				
	};
	spis *head;

void chtenie(spis* head,char* razd)
{
	char stroka[80];
	char* a;
	ifstream in;
	in.open("Input.txt")
		
			while(in.getline(stroka,80))
			{
			a = strtok(stroka,razd);
            vstavka(a);
			while(a)
			{
                 a = strtok(NULL,razd);
                 vstavka(a);
			}
			}
		
		in.close();
}

void zapis(spis* head)
{
    int kol_max = 0;
	char n_max = NULL;
	int nom_max = 0;
	char*str;
	char slovo1;
	int dlinna1;
	ofstream out;
	out.open("Result1.txt")
		out<<"номер слова"<<setw(4)<<"слово"<<setw(15)<<"длинна"<<setw(4)<<"номер символа"<<endl;
		spis* rab = head;
        i = 1;

while(rab != NULL)
{
	str = rab->slovo;
	rab = rab->next;
 slovo1 = str;
dlinna1 = strlen(slovo1); 
poisk_inf(char* str,int& kol_max, char& n_max,int& nom_max);
out<<i<<setw(14)<< slovo1<<setw(15-dlinna1)<<n_max<<setw(9)<<kol_max<<setw(8)<<nom_max<<endl;
i++;
}
out.close();
}




void main()
{
setlocale(LC_ALL,".1251");
char* razd = ",.-;:!";
InitList()
chtenie(head,razd);
zapis(head);
ud_spis();
}









