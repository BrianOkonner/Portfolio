//Vizgalova Elena 
//Number 5
#include <iostream>
#include <fstream>
#include"head.h"

using namespace std;

bool razdelitel (char c)
{
	char razd[7]={' ','.',',',':','-',';','!'};
    int i=0;
    bool induk=false;
    while ((i<14)&&(!induk))
    {
        if(c==razd[i])
            induk=true;
        i=i+1;
    }
    return (induk);
}

void main ()
{
	setlocale (LC_ALL, ".1251");

	char razd[7]={' ','.',',',':','-',';','!'},str[1000],str11[15];

	int i,j,k,len,cifr=0,m,N_slova=0,Matr[3][100];
	bool induk;
    i=0;
    j=0;
	
	ifstream izfaila;
    izfaila.open("Input.txt");
	ofstream vfail1;
    vfail1.open("Result1.txt");
	vfail1<<"Nomer Slova    Slovo       Dlina     Nomer simvola"<<"\n";

	ofstream vfail2;
    vfail2.open("Result2.txt");
	vfail2<<"Nomer Slova    Slovo       Dlina     Nomer simvola"<<"\n";
	    while (i<3)
    {
        j=0;
        while (j<100)
        {
            Matr[i][j]=0;
            j=j+1;
        }
        i=i+1;
    }
    

	while (!izfaila.eof())
	{	
		izfaila.getline(str,1000);
        len=strlen(str);
        str[len]=' ';
        str[len+1]='\0';

        i=0;

        while (i<=len)
        {
            j=0;
            while ((j<14)&&(induk))
            {
            if (str[i]!=razd[j])  induk=true;
            else {induk=false; cifr=i-cifr;}
            j=j+1;
            }
            if (!induk)
            {
            k=0;
            m=i-cifr;
            while (k<cifr) 
            {
                str11[k]=str[m];
                k=k+1;
                m=m+1;
            }
            str11[k]='\0';


            cout<<str11<<endl;
			N_slova=N_slova+1;
			
			vfail2<<N_slova<<"             "<<"\n";
			vfail1<<N_slova<<"             "<<str11<<"\n";

            cifr=i+1;

            while (razdelitel(str[cifr]))
                cifr=cifr+1;
            i=cifr;
           }
        induk=true;
        i=i+1;
        }
    }

 izfaila.close();
}