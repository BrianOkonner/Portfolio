#include <iostream>
#include "fun_h.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>  
using namespace std;
void main()
{
	setlocale(LC_ALL,".1251");
	int h,m,n,i,*w,j=0,**q=0;
	ifstream in("Input.txt"), d("Data.txt");
	char *sepr=" .,;:+",*s,s1[]="0123456789",*s2,t=0;
	s=new char[100];
	w=new int [100];
	s2=new char[100];
	//for(i=-127;i<=127;i++)
	//	if(i!='0'||i!='1'||i!='2'||i!='3'||i!='4'||i!='5'||i!='6'||i!='7'||i!='8'||i!='9')
	//		s1[127+i]=i;
	while(!in.eof())
	{
		in.getline(s2,100,'\n');
		s=strtok(s2,sepr);
		while (s!=NULL)
		{
			for(i=0,t=0;s[i]!='\0';i++)
				if (strchr(s1,s[i])==0)
					t=1;
			if(t==0)
				{
					w[j]=atoi(s);
					j++;
				}
		s=strtok(0,sepr);
		}
	}
	bubble_srt(w,j);
	for(i=0;i<j;i++)
		cout<<w[i]<<"  ";
	d>>n>>h;
	matr2_dclr(q,n,h);
		for(j=0;j<n;j++)
		for(i=0;i<h;i++)
			d>>q[j][i];
	vivodmatr2(q,n,h);
	system("pause");
}