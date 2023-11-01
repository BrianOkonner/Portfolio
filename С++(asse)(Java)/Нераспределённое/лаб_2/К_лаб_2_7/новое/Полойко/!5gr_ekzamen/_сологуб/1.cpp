//сологуб анастасия 5 группа


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void main()
{
	int j=0; //подсчет слов
	char** matr=new char*[80];
	for(int i=0; i<80; i++)
		matr[i]=new char[80];
	char* word;
	char* str=new char[80];
	ifstream in("input.txt");
	while(in.getline(str, 80))
	{
		word=strtok(str, " -,.;:!");
		while(word)
		{
			strcpy(matr[j], word);
			j++;
			word=strtok(NULL, " -,.;:!");
		}
	}
	in.close();

	ofstream out("result1.txt");
	unsigned int k=0, max, nmax, l;
	char sym;
	out<<"number "<<"word "<<"symbol "<<"lenth "<<"number"<<endl;
	for(int i=0; i<j; i++)
	{
		l=1;
		k=0;
		sym=matr[i][0];
		nmax=0;
		max=1;
		while(k<strlen(matr[i]))
		{
			while(matr[i][k]==matr[i][k+1])
			{
				l++;
				k++;
			}
			if(l>max)
			{
				max=l;
				nmax=k-l+1;
			}
			l=1;
			k++;
		}
		out<<i+1<<"   "<<matr[i]<<"   "<<matr[i][nmax]<<"   "<<max<<"   "<<nmax+1<<endl;
	}
	out.close();

	ifstream in1("result1.txt");
	
	int** matr1=new int*[j];
	for(int m=0; m<j; m++)
		matr1[m]=new int[10];

	in1.getline(str, 80);
	
	for(int m=0; m<j; m++)
	{
		in1.getline(str, 80);
		matr1[m][0]=atoi(strtok(str, " "));
		word=strtok(NULL, " ");
		word=strtok(NULL, " ");
		matr1[m][1]=atoi(strtok(NULL, " "));
		matr1[m][2]=atoi(strtok(NULL, " "));
	}

	in1.close();

	ofstream out1("result2.txt");
	out1<<"number"<<" lenth"<<" number"<<endl;

	for(int m=0; m<j; m++)
	{
		for(int r=0; r<3; r++)
			out1<<matr1[m][r]<<" ";
		out1<<endl;
	}
	out1.close();

	
	/*ifstream in("result1.txt");
	while(in.getline(str, 100))
	{
		word=strtok(str, " -,.;:!");
		while(word)
		{
			push(word, );
			word=strtok(NULL, " -,.;:!");
		}
	}*/

}