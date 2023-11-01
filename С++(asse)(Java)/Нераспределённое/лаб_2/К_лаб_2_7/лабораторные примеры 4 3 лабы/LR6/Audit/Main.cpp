#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
#include <locale>
using namespace std;

int isNumber(char *word){
int l1;
char *tmp;
l1=strtol(word,&tmp,0);
if(*tmp==0)
	return 1;
double l2;
l2=strtod(word,&tmp);
if(*tmp==0)
	return -1;
return 0;
}

int main(void)
{
    setlocale(LC_ALL, "ru");
    unsigned int clk;
    int k=0,i=0,p=0;
    ifstream in;
    ofstream out;
    in.open("input.txt");
	char tmp[81], *word;
	while(!in.eof())
	{
		in.getline(tmp,80);
		word=strtok(tmp," ");
		while(word)
		{
			if(!(isNumber(word)))
				cout<<word<<" ";
			word=strtok(NULL, " ");
		}
		cout<<endl;
	}
	clk=clock();
    cout << endl << "Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
