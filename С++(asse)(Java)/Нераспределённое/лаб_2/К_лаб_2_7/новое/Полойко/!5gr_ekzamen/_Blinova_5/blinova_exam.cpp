#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void main()
{
	
    ifstream in("input.txt");
	ofstream out("output.txt",ios::app);
	
	char**MA=new char*[1000];
		for (int i=0;i<1000;i++)
			MA[i]=new char[10];
	
	//int n=0;
	char** str=new char*[100];
	for(int i=0;i<100;i++)
		str[i]=new char[100];
    int j=0;
	int k=0;
	int i=0;
	int mass[1000];
	for(int i=0;i<1000;i++)
		mass[i]=0;
		
	while(in.getline(str[j],81))
	{
		
		char *rez;
		rez=strtok(str[j]," -,.;:!");
        goto M2;
	M1: rez=strtok(NULL," -,.;:!");
M2:if(rez)
   {MA[i]=rez;
    //out<<MA[i];
	mass[i]=strlen(rez);
	//out<<endl;
    i++;
	 goto M1;}
	else
		j++;
	goto M3;
M3:;}
	int n=i;      //n--кол-во слов
	int arr[256];
    int arr1[80];
	int y=-1;
	out<<"Номер строки "<<"Слово "<<"Символ "<<"Длина "<<"Номер символа "<<endl;
 
	for(int i=0;i<n;i++)
	{
		for(int p=0;p<256;p++)
		       arr[p]=0;
			for(int p=0;p<80;p++)
		       arr1[p]=0;
		
		for(int j=0;j<mass[i];j++)
		{     
			if(MA[i][j]==MA[i][j+1])
			{
			
			arr1[MA[i][j]]=j;

			for(int k=j;k<mass[i];k++)
			{if(MA[i][k]==MA[i][k+1])
				{arr[MA[i][k]]++;
			j++;}}}}
			int max=arr[0];
			for(int u=0;u<256;u++)
			{
				if(arr[u]>max)
				{max=arr[u];
				y=u;}
			}
			if(y!=-1)
			{out<<(i+1)<<"     "<<MA[i]<<"     "<<char(y)<<"     "<<max+1<<"     "<<arr1[y]+1<<endl;}
	}
    
	

	in.close();
	out.close();

	/*ifstream in1("output.txt");
	ofstream out1("output1.txt");
	char** str1=new char*[n];
	for(int i=0;i<n;i++)
		str1[i]=new char[200];
	int r=0,t=0;
	//int c=5*n;
	char**MA1=new char*[300];
		for (int i=0;i<300;i++)
			MA1[i]=new char[100];
	

	while(in1.getline(str1[r],200))
	{
		
		char *rez1;
		rez1=strtok(str1[r]," ");
        goto M5;
	M4: rez1=strtok(NULL," ");
M5:if(rez1)
   {MA1[t]=rez1;
   cout<<MA1[t];
   cout<<endl;
     t++;
	 goto M4;}
	else
		r++;
	goto M6;
M6:;}
	int n1=t;
	
	
    int s=0;
	for(int i=0;i<n1;i++)
	{
		if(i==(5*s+1))
		{for(int g=i;g<n1-1;g++)
				MA1[g]=MA1[g+1];
		s++;}
		else
		s++;
     }
    int x=0;
	for(int i=0;i<n1;i++)
	
		cout<<MA1[i]<<"       ";*/
		

	
				
}


    

	
	


