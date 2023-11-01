//Каминский Денис(5-ая группа)

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out1("Result1.txt");
ofstream out2("Result2.txt");
void perevod(char s[10000],  char **a, int &n)
{
	int i = 0; int l = strlen(s);
	while (i < l)
	{
		while(s[i] == ',' || s[i] == '.' || s[i] == ' ' || s[i]=='!' || s[i]=='-' ||s[i]==';')
		{
			++i;
	
		}
		int tl = 0;
		while (s[i] != ',' && s[i] != '.' && s[i] != ' ' && s[i]!='!' && s[i]!='-' && s[i]!=';' && i < l)
		{
			a[n][tl++] = s[i];
			++i;
		}
		a[n][tl] = '\0';
		++n;
	}
}



void main()
{
	char l[1000];
	int n=0;
	char **a;
	a=new char*[1000];
	for(int i=0;i<1000;++i)
	{
		a[i]=new char[1000];
	}
	while(in.getline(l,1000))
	{
		cout<<l;
		cout<<endl;
		perevod(l,a,n);
	}
	cout<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	out1<<"Number    ";
	out1<<"Word   ";
	out1<<"Symbol   ";
	out1<<"Lenth   ";
	out1<<"Symbol number"<<endl;
	out1<<"1";

	int count=0; //счётчик номера символа
	int m[200];
	for(int i=0;i<200;++i)
	{
		m[i]=0;
	}
	
		for(int j=0;j<strlen(a[j]);++j)
		{
			m[a[0][j]]++;
		}
	int max=m[0];
	out1<<"         "<<a[0];
	int d=strlen(a[0]);
		for(int i=0;i<200;++i)
		{
			
			if(m[i+1]>m[i])
			{
				count++;
				max=m[i+1];
				cout<<(char)i<<" "<<max<<endl;
				out1<<max<<" "<<(char)i;
			}
			
		}
	out1<<"  "<<d;
	out1<<"                  "<<count<<endl;
cout<<count<<endl;
	out1<<"2";
	out1<<"         "<<a[1];

	int mas[200];
	for(int i=0;i<200;++i)
	{
		mas[i]=0;
	}
	
	for(int j=0;j<strlen(a[j]);++j)
		{
			m[a[1][j]]++;
		}
		int maximum=m[0];
		int f=strlen(a[1]);
		int count2=0;
		for(int i=0;i<200;++i)
		{
			if(m[i+1]>m[i])
			{
				count2++;
				maximum=m[i+1];
				cout<<maximum<<" "<<(char)i;
				out1<<maximum<<" "<<(char)i;
			}
		}
		out1<<" "<<f;
		out1<<"                  "<<count2<<endl;
	in.close();
	out1.close();

	ifstream in("Result1.txt");
	char str[1000];
	char **b=new char*[1000];
	for(int i=0;i<1000;++i)
	{
		b[i]=new char[1000];
	}
	int g=0;
	cout<<endl;
	cout<<"_________________________________________________"<<endl;
	cout<<endl;
	int t=0;
while(in.getline(str,10000))
	{
		cout<<str;
		cout << endl;
		perevod(str,b,t);
	}
	for(int i=6;i<t/2+3;++i)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for(int i=t/2+3;i<t;++i)
	{
		cout<<b[i]<<" ";
	}
	if(d>f)
	{
		for(int i=t/2+3;i<t;++i)
		{
			out2<<b[i]<<" ";
		}
		out2<<endl;
		for(int i=6;i<t/2+3;++i)
		{
			out2<<b[i]<<" ";
		}
	}
	else
	{
		for(int i=6;i<t/2+3;++i)
		{
			out2<<b[i]<<" ";
		}
		out2<<endl;
		for(int i=t/2+3;i<t;++i)
		{
			out2<<b[i]<<" ";
		}
	}
	cout<<endl;
	in.close();
	out2.close();
}